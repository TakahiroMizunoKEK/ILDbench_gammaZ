double photonERec7(double Ecm,double lep1EAnl,    double lep2EAnl, 
			      double lep1thetaAnl,   double lep1phiAnl, 
		  	      double lep2thetaAnl,   double lep2phiAnl, 
			      double photonthetaAnl, double photonphiAnl)
			      //double photonthetaAnl, double photonphiAnl, int i)
{
	//This is "Case 5" Using Pt conservation
	double stgamma  = sin(photonthetaAnl);
	double stmum    = sin(lep1thetaAnl);
	double stmup    = sin(lep2thetaAnl);
	double ctgamma  = cos(photonthetaAnl);
	double ctmum    = cos(lep1thetaAnl);
	double ctmup    = cos(lep2thetaAnl);
	
	double spgamma  = sin(photonphiAnl);
	double spmum    = sin(lep1phiAnl);
	double spmup    = sin(lep2phiAnl);
	double cpgamma  = cos(photonphiAnl);
	double cpmum    = cos(lep1phiAnl);
	double cpmup    = cos(lep2phiAnl);

	double sinphimp       = sin(lep1phiAnl-lep2phiAnl);
	double sinphimumgamma = sin(lep1phiAnl-photonphiAnl);
	double sinphimupgamma = sin(lep2phiAnl-photonphiAnl);

	// determination of ISR direction
	double fAmup = -stgamma*sinphimumgamma/(stmup*sinphimp);
	double fAmum = +stgamma*sinphimupgamma/(stmum*sinphimp);
        double A = 1. + fAmup + fAmum;
	double signISR;
	signISR =  (Ecm/A * stgamma + Ecm*fAmum/A * stmum + Ecm*fAmup/A * stmup);
	//

	double alpha = 0.007;
	double ta = tan(alpha);
	double ca = cos(alpha);
	double A2,B2;

	double sa = sin(alpha);
	double p1x=lep1EAnl*stmum*cpmum;
	double p2x=lep2EAnl*stmup*cpmup;
	double p1y=lep1EAnl*stmum*spmum;
	double p2y=lep2EAnl*stmup*spmup;

	double Egamma0=1./abs(stgamma)*sqrt(pow((p1x+p2x-500.*sa),2)+pow((p1y+p2y),2));

	int i =0;

	if (i == 0){
		return Egamma0;
	}

	return -9999.9999;
		
}

