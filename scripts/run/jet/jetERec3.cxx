double jetERec3(double Ecm, double Egamma, double mj1,double mj2,
			      double jet1thetaAnl,   double jet1phiAnl, 
		  	      double jet2thetaAnl,   double jet2phiAnl, 
			      double photonthetaAnl, double photonphiAnl, int part)
{
	double stp  = sin(photonthetaAnl);
	double ctp  = cos(photonthetaAnl);
	double spp  = sin(photonphiAnl);
	double cpp  = cos(photonphiAnl);
	double stj1  = sin(jet1thetaAnl);
	double ctj1  = cos(jet1thetaAnl);
	double spj1  = sin(jet1phiAnl);
	double cpj1  = cos(jet1phiAnl);
	double stj2  = sin(jet2thetaAnl);
	double ctj2  = cos(jet2thetaAnl);
	double spj2  = sin(jet2phiAnl);
	double cpj2  = cos(jet2phiAnl);

//	double Ecm   = 500.;
        double alpha = 0.007;
        //double alpha = 0.;
        double sa = sin(alpha);
        double ca = cos(alpha);
        double ta = tan(alpha);


	//Derive ai and bi
        TMatrixD mat(3,3), inv(3,3);
        double   a[9] = {stj1*cpj1,stj2*cpj2,stp*cpp,stj1*spj1,stj2*spj2,stp*spp,ctj1,ctj2,ctp};    // input matrix data
        mat.SetMatrixArray(a);
        inv=mat.Invert();
        
        TMatrixD v1o(3,1),v1(3,1);
        TMatrixD v2o(3,1),v2(3,1);


	double bestsol = -9999.;
        double besta[3],bestb[3];
	double diff = 1.e20;


//signISR
	for (int isrdir = 0;isrdir < 2; isrdir++){
	        double v1e[3]={-sa,0.,-ca*(1.-2.*isrdir)};
	        v1o.SetMatrixArray(v1e);
	        v1=v1o;
        
	        double v2e[3]={Ecm*sa,0.,0.};
	        v2o.SetMatrixArray(v2e);
	        v2=v2o;
 
	        v1 = inv * v1;
	        v2 = inv * v2;

		double a1,a2,a3,b1,b2,b3;
		a1=v1(0,0);
		a2=v1(1,0);
		a3=v1(2,0);
		b1=v2(0,0);
		b2=v2(1,0);
		b3=v2(2,0);

	//cout<<"pj1= "<< a1*Eisr+b1<<endl;
	//cout<<"pj2= "<< a2*Eisr+b2<<endl;
	//cout<<"Ega= "<< a3*Eisr+b3<<endl;



	        //Solve the quartic equation
		double c[10],d[5];
		c[1]=pow(a2,2);
		c[2]=2.*a2*b2;
		c[3]=pow(b2,2)+pow(mj2,2);
		c[4]=pow((a3+1.),2);
		c[5]=2.*(a3+1.)*(b3-Ecm);
		c[6]=pow((b3-Ecm),2);
		c[7]=-pow(a1,2)+pow(a2,2)+pow(a3,2)+2.*a3+1.;
		c[8]=-2.*a1*b1+2.*a2*b2-2.*(Ecm-b3)*(a3+1.);
		c[9]=-pow(b1,2)-pow(mj1,2)+pow(b2,2)+pow(mj2,2)+pow((Ecm-b3),2);
	
		d[4]=4.*c[1]*c[4]-pow(c[7],2);
		d[3]=4.*(c[1]*c[5]+c[2]*c[4])-2.*c[7]*c[8];
		d[2]=4.*(c[1]*c[6]+c[2]*c[5]+c[3]*c[4])-2*c[7]*c[9]-pow(c[8],2);
		d[1]=4.*(c[2]*c[6]+c[3]*c[5])-2.*c[8]*c[9];
		d[0]=4.*c[3]*c[6]-pow(c[9],2);
	
	
	        ROOT::Math::Polynomial pol(d[4],d[3],d[2],d[1],d[0]);
	
	        std::vector< double > solv = pol.FindRealRoots();
	        int nsol = solv.size();
	        //cout<<"nsol= "<<nsol<<endl;
		if (debug) {
	        	cerr<<"nsol= "<<nsol<<endl;
			for (int i=0; i<nsol; i++) {
				cerr<<"solv["<< i<< "]= "<< solv[i]<< " ";
			}	
			cerr << endl;			
		}
		

		int    isol = -1;
	
	        //cout << "solv=";
	        for (int i=0; i<nsol; i++) {
	                //cout << " " << solv[i];
			if ((solv[i] < 0.) || (solv[i] > Ecm/2.)) continue;
			double Eg = a3*solv[i]+b3;
			if (fabs(Eg - Egamma) < diff){
				isol = i;
				diff = fabs(Eg - Egamma);
				bestsol = solv[i];
				besta[0] = a1;
				besta[1] = a2;
				besta[2] = a3;
				bestb[0] = b1;
				bestb[1] = b2;
				bestb[2] = b3;
			}
	        }
	        //cout << endl;
	        //cout << "Best: solv["<<isol<<"]="<<solv[isol]<<endl;
	}


	//cout << "Best PISR= "<<bestsol<<endl;



	//part= 0->jet1
	//	1->jet2
	//	2->photon


	return besta[part]*bestsol+bestb[part];
}
