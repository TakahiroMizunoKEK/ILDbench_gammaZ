double jetERec0(double Ecm,double mj1,double mj2,
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

        double alpha = 0.007;
        double sa = sin(alpha);
        double ca = cos(alpha);
        double ta = tan(alpha);


	//Derive ai and bi
	//Pj1=a1*EISR+b1
	//Pj2=a2*EISR+b2
	//Epho=a3*EISR+b3

        TMatrixD mat(3,3), inv(3,3);
        double   a[9] = {stj1*cpj1,stj2*cpj2,stp*cpp,stj1*spj1,stj2*spj2,stp*spp,ctj1,ctj2,ctp};    // input matrix data
        mat.SetMatrixArray(a);
        inv=mat.Invert();
        
        TMatrixD v1o(3,1),v1(3,1);
        TMatrixD v2o(3,1),v2(3,1);

//signISR=+
        double v1e[3]={-sa,0.,-ca};
        v1o.SetMatrixArray(v1e);
        v1=v1o;
        
        double v2e[3]={500*sa,0.,-ca};
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


        //Solve the quartic equation
	double c[10],d[5];
	c[1]=pow(a2,2);
	c[2]=2.*a2*b2;
	c[3]=pow(b2,2)+pow(mj2,2);
	c[4]=pow((a3+1.),2);
	c[5]=(a3+1.)*(b3-500.);
	c[6]=pow((b3-500.),2);
	c[7]=-pow(a1,2)+pow(a2,2)+pow(a3,2)-2.*a3+1.;
	c[8]=-2.*a1*b1+2.*a2*b2-2.*(500.-b3)*(a3-1.);
	c[9]=-pow(b1,2)-pow(mj1,2)+pow(b2,2)+pow(mj2,2)+pow((500.-b3),2);

	d[4]=4*c[1]*c[4]-pow(c[7],2);
	d[3]=4*(c[1]*c[5]+c[2]*c[4])-2*c[7]*c[8];
	d[2]=4*(c[1]*c[6]+c[2]*c[5]+c[3]*c[4])-2*c[7]*c[9]-pow(c[8],2);
	d[1]=4*(c[2]*c[6]+c[3]*c[5])-2*c[8]*c[9];
	d[0]=4*c[3]*c[6]-pow(c[9],2);


        ROOT::Math::Polynomial pol(d[4],d[3],d[2],d[1],d[0]);

        std::vector< double > solv = pol.FindRealRoots();
        int nsol = solv.size();
        cout<<"nsol= "<<nsol<<endl;

        cout << "solv=";
        for (int i=0; i<nsol; i++) {
                cout << " " << solv[i];
        }
        cout << endl;












	//photon
	if (part == 0){
	return v2(2,0);
	}

	//jet1
        if (part == 1){
	return v2(0,0);
	}	

	//jet2
        if (part == 2){
	return v2(1,0);
	}
/*
	//ISR		
        if (part == 3){
	return Ecm-(B2/A2 + B2*fAmum/A2 + B2*fAmup/A2);
	}*/

	return -9999.;
}
