double photonERec5(double lep1EAnl,    double lep2EAnl, 
			      double lep1thetaAnl,   double lep1phiAnl, 
		  	      double lep2thetaAnl,   double lep2phiAnl, 
			      double photonthetaAnl, double photonphiAnl, double photonEAnl)
			      //double photonthetaAnl, double photonphiAnl, int i)
{
	double Ecm=500.;
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
	//signISR =  (Ecm/A * stgamma + Ecm*fAmum/A * stmum + Ecm*fAmup/A * stmup);
	signISR =  -(lep1EAnl* ctmum + lep2EAnl * ctmup + photonEAnl * ctgamma);
	//

	double alpha = 0.007;
	double ta = tan(alpha);
	double ca = cos(alpha);
	double sa = sin(alpha);
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
	

	// (signISR >= 0)
	double	A21 = 1. - ctgamma/ca;
	double	B21 = 500. - lep2EAnl * (1. - ctmup/ca) - lep1EAnl * (1. - ctmum/ca);
	// else
	double	A22 = 1. + ctgamma/ca;
        double	B22 = 500. - lep2EAnl * (1. + ctmup/ca) - lep1EAnl * (1. + ctmum/ca);
	
	double Egp =B21/A21;
	double Egm =B22/A22;

	double EISRp = 500. -  Egp - lep1EAnl  - lep2EAnl;
	double EISRm = 500. -  Egm - lep1EAnl  - lep2EAnl;

	double Eg,EISR;
	if(EISRp < 0){
		Eg=Egm;
		EISR=EISRm;
		if(EISRm < 0){
        		Eg=-9999.;
        		EISR=-9999.;
        	}	 
	}else if(EISRm < 0){
	        Eg=Egp;
	        EISR=EISRp;
        }else{
		double chi2p = pow((500.*sa-lep1EAnl*stmum*cpmum-lep2EAnl*stmup*cpmup-Egp*stgamma*cpgamma-EISRp*sa),2)+pow((lep1EAnl*stmum*spmum+lep2EAnl*stmup*spmup+Egp*stgamma*spgamma),2);
		//double chi2p = abs(500.*sa-lep1EAnl*stmum*cpmum-lep2EAnl*stmup*cpmup-Egp*stgamma*cpgamma-EISRp*sa)+abs(lep1EAnl*stmum*spmum+lep2EAnl*stmup*spmup+Egp*stgamma*spgamma);
		double chi2m = pow((500.*sa-lep1EAnl*stmum*cpmum-lep2EAnl*stmup*cpmup-Egm*stgamma*cpgamma-EISRm*sa),2)+pow((lep1EAnl*stmum*spmum+lep2EAnl*stmup*spmup+Egm*stgamma*spgamma),2);
		//double chi2m = abs(500.*sa-lep1EAnl*stmum*cpmum-lep2EAnl*stmup*cpmup-Egm*stgamma*cpgamma-EISRm*sa)+abs(lep1EAnl*stmum*spmum+lep2EAnl*stmup*spmup+Egm*stgamma*spgamma);

		if(chi2p < chi2m){
			Eg=Egp;
                	EISR=EISRp;
		}else{
			Eg=Egm;
                	EISR=EISRm;
		}
	}

	int i =0;

	if (i == 0){
		return Eg;
	}

	if (i == 3){
		return EISR;        
	}

	return -9999.9999;
		
}

