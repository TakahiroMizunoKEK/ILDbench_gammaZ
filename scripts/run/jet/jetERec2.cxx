double jetERec2(double Ecm, double Egamma, double mj1,double mj2,
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
        TMatrixD vorig(3,1),v(3,1);

	double bestsol = -9999.;
        double besta[3];
        double a1[2],a2[2],a3[2];
	double diff[2];


	//signISR
	for (int isrdir = 0;isrdir < 2; isrdir++){
		double a8 = -ca * (2.*isrdir-1.);
	        double a[9] = {stj1*cpj1,stj2*cpj2,sa,stj1*spj1,stj2*spj2,0.,ctj1,ctj2,a8};    // input matrix data

	        mat.SetMatrixArray(a);
	        inv=mat.Invert();
        
	        double ve[3]={Ecm*sa-Egamma*stp*cpp,-Egamma*stp*spp,-Egamma*ctp};
	        vorig.SetMatrixArray(ve);
	        v = vorig;
	        v = inv * v;

		//double a1,a2,a3;
		a1[isrdir]=v(0,0);
		a2[isrdir]=v(1,0);
		a3[isrdir]=v(2,0);

                diff[isrdir] = sqrt(pow(a1[isrdir],2)+pow(mj1,2))+sqrt(pow(a2[isrdir],2)+pow(mj2,2))+abs(a3[isrdir])+Egamma-Ecm;
		}


	cout << "diff[+]= "<<diff[0]<<endl;
	cout << "diff[-]= "<<diff[1]<<endl;
	
	 //choose the best answer;
	if(abs(diff[0])<abs(diff[1])) {
		besta[0] = a1[0];
		besta[1] = a2[0];
		besta[2] = a3[0];
	} else {
		besta[0] = a1[1];
		besta[1] = a2[1];
		besta[2] = a3[1];
	}
	

	//cout << "Best PISR= "<<bestsol<<endl;

	//part= 0->jet1
	//	1->jet2
	//	2->photon

	return besta[part];



	/*if (part ==0){
		return a1[0];
	} else if (part ==1){
		return a2[0];
	} else {
		return a3[0];
		}*/








}
