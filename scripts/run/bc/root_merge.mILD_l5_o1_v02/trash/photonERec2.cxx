double photonERec2(double Ecm, double lep1thetaAnl,   double lep1phiAnl, 
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

	//P(ISR)>0 case
	double Ap = 1.*(1.-cos(photonthetaAnl)) + fAmup*(1.-cos(lep2thetaAnl)) + fAmum*(1.-cos(lep1thetaAnl));
	
	//P(ISR)<0 case
	double Am = 1.*(1.+cos(photonthetaAnl)) + fAmup*(1.+cos(lep2thetaAnl)) + fAmum*(1.+cos(lep1thetaAnl));


	if (i == 10){
	return Ecm/Ap;
	}
	if (i == 20){
	return Ecm/Am;
	}
        if (i == 11){
	return Ecm*fAmum/Ap;
	}	
        if (i == 21){
	return Ecm*fAmum/Am;
	}	
        if (i == 12){
	return Ecm*fAmup/Ap;
	}
        if (i == 22){
	return Ecm*fAmup/Am;
	}
		
}

