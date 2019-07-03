double jetERec1(double Ecm, double Egamma, double mj1,double mj2,
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
        
	        double v2e[3]={Ecm*sa,0.,0.};
	        v2o.SetMatrixArray(v2e);
	        v2=v2o;
 
	        v2 = inv * v2;

		double a1,a2,a3,b1,b2,b3;
		b1=v2(0,0);
		b2=v2(1,0);
		b3=v2(2,0);

	//cout<<"pj1= "<< a1*Eisr+b1<<endl;
	//cout<<"pj2= "<< a2*Eisr+b2<<endl;
	//cout<<"Ega= "<< a3*Eisr+b3<<endl;


		besta[0]=b1;
		besta[1]=b2;
		besta[2]=b3;



	}


	//cout << "Best PISR= "<<bestsol<<endl;
	cout << "photonERec= "<<besta[2]<<endl;



	//part= 0->jet1
	//	1->jet2
	//	2->photon


	return besta[part];
}
