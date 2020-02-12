double photonERec3(double Ecm, double lep1thetaAnl,   double lep1phiAnl, 
		  	      double lep2thetaAnl,   double lep2phiAnl, 
			      double photonthetaAnl, double photonphiAnl, int i)
{
	double sinthetagamma  = sin(photonthetaAnl);
	double sinthetamum    = sin(lep1thetaAnl);
	double sinthetamup    = sin(lep2thetaAnl);
	double sinphimp       = sin(lep1phiAnl-lep2phiAnl);
	double sinphimumgamma = sin(lep1phiAnl-photonphiAnl);
	double sinphimupgamma = sin(lep2phiAnl-photonphiAnl);

	double fAmup = -sinthetagamma*sinphimumgamma/(sinthetamup*sinphimp);
	double fAmum = +sinthetagamma*sinphimupgamma/(sinthetamum*sinphimp);

        double A = 1. + fAmup + fAmum;

	double PISRz;
	PISRz = - (Ecm/A * cos(photonthetaAnl) + Ecm*fAmum/A * cos(lep1thetaAnl) + Ecm*fAmup/A * cos(lep2thetaAnl));

	double A2,B2;

        //A2 = 1.-cos(photonthetaAnl) + fAmup*(1.-cos(lep2thetaAnl)) + fAmum*(1.-cos(lep1thetaAnl));
	//A2 = 1.+cos(photonthetaAnl) + fAmup*(1.+cos(lep2thetaAnl)) + fAmum*(1.+cos(lep1thetaAnl));
	if (PISRz >= 0.){
	A2 = 1.-cos(photonthetaAnl) + fAmup*(1.-cos(lep2thetaAnl)) + fAmum*(1.-cos(lep1thetaAnl));
	B2 = Ecm;
	}else{
	A2 = 1.+cos(photonthetaAnl) + fAmup*(1.+cos(lep2thetaAnl)) + fAmum*(1.+cos(lep1thetaAnl));
	B2 = Ecm;
	}

	if (i == 0){
	return B2/A2;
	}

        if (i == 1){
	return B2*fAmum/A2;
	}	

        if (i == 2){
	return B2*fAmup/A2;
	}
		
        if (i == 3){
	return Ecm-(B2/A2 + B2*fAmum/A2 + B2*fAmup/A2);
	}
}
