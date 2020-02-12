double photonERec53(double Ecm,double lep1EAnl,    double lep2EAnl, 
			      double lep1thetaAnl,   double lep1phiAnl, 
		  	      double lep2thetaAnl,   double lep2phiAnl, 
			      double photonthetaAnl, double photonphiAnl)
			      //double photonthetaAnl, double photonphiAnl, int i)
{
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

	double fAmup2n = (stgamma*cpgamma-ctgamma*ta)*stmum*spmum-(stmum*cpmum-ctmum*ta)*stgamma*spgamma;
	double fAmup2d = (stmup  *cpmup  -ctmup  *ta)*stmum*spmum-(stmum*cpmum-ctmum*ta)*stmup  *spmup  ;
	double fAmup2 = -fAmup2n/fAmup2d;
	double fAmup3n = ta*stmum*spmum;
	double fAmup3 = -fAmup3n/fAmup2d;
	double fAmum2n = (stgamma*cpgamma-ctgamma*ta)*stmup*spmup-(stmup*cpmup-ctmup*ta)*stgamma*spgamma;
	double fAmum2d = (stmum  *cpmum  -ctmum  *ta)*stmup*spmup-(stmup*cpmup-ctmup*ta)*stmum  *spmum  ;
	double fAmum2 = -fAmum2n/fAmum2d;
	double fAmum3n = ta*stmup*spmup;
	double fAmum3 = -fAmum3n/fAmum2d;
	

	if (signISR >= 0){
		A2 = 1. - ctgamma/ca;
		B2 = 500. - lep2EAnl * (1. - ctmup/ca) - lep1EAnl * (1. - ctmum/ca);
	} else {
		A2 = 1. + ctgamma/ca;
        	B2 = 500. - lep2EAnl * (1. + ctmup/ca) - lep1EAnl * (1. + ctmum/ca);
	}


	int i =3;

	if (i == 0){
		return B2/A2;
	}

	if (i == 3){
        if (signISR >= 0){
                return 500. -  B2/A2 - lep1EAnl  - lep2EAnl;
        } else {
                return -(500. -  B2/A2 - lep1EAnl  - lep2EAnl);
        }
	}

	return -9999.9999;
		
}

