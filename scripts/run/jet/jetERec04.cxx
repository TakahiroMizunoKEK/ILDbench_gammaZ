double jetERec0(double Ecm,double mj1,double mj2,
			      double jet1thetaAnl,   double jet1phiAnl, 
		  	      double jet2thetaAnl,   double jet2phiAnl, 
			      double photonthetaAnl, double photonphiAnl, int i)
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
        TMatrixD v1=v1o;
        
        double v2e[3]={500*sa,0.,-ca};
        v2o.SetMatrixArray(v2e);
        TMatrixD v2=v2o;
 
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
	double qec[5];
	qec[4]=4.*pow(a2,2)*pow(a3+1.,2)-pow((-pow(a1,2)+pow(a2,2)+pow(a3,2)-2.*a3+1.),2); //coefficient of EISR^4

	qec[3]=4.*(2.*pow(a2,2)*(a3+1.)*(b3-500.)+2.*a2*b2*pow((a3+1.),2))-2.*(-pow(a1,2)+pow(a2,2)+pow(a3,2)-2.*a3+1.)*(-2.*a1*b1+2.*a2*b2-2*(500.-b3)*(a3-1.));

	qec[2]=4.*((pow(b2,2)+pow(mj2,2))*pow((a3+1.),2)+4.*a2*b2*(a3+1.)*(b3-500.)+pow(a2*(b3-500.),2))-pow((-2.*a1*b1+2.*a2*b2-2.*(500.-b3)*(a3-1.)),2)+2.*(-pow(a1,2)+pow(a2,2)+pow(a3,2)-2.*a3+1.)*(-pow(b1,2)+pow(mj1,2)+pow(b2,2)+pow(mj2,2)+pow((500.-b3),2));

	qec[1]=4.*(2*a2*b2*(pow((b3-500.),2)+2*pow(mj2,2))*pow((a3+1.),2)+4.*a2*b2*(a3+1.)*(b3-500.)+pow(a2*(b3-500.),2))-pow((-2.*a1*b1+2.*a2*b2-2.*(500.-b3)*(a3-1.)),2)+2.*(-pow(a1,2)+pow(a2,2)+pow(a3,2)-2.*a3+1.)*(-pow(b1,2)+pow(mj1,2)+pow(b2,2)+pow(mj2,2)+pow((500.-b3),2));





	//photon
	if (i == 0){
	return v2(2,0);
	}

	//jet1
        if (i == 1){
	return v2(0,0);
	}	

	//jet2
        if (i == 2){
	return v2(1,0);
	}
/*
	//ISR		
        if (i == 3){
	return Ecm-(B2/A2 + B2*fAmum/A2 + B2*fAmup/A2);
	}*/
}
