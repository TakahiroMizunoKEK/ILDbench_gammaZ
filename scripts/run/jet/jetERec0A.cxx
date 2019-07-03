double jetERec0(double Ecm, double jet1thetaAnl,   double jet1phiAnl, 
		  	      double jet2thetaAnl,   double jet2phiAnl, 
			      double photonthetaAnl, double photonphiAnl, int i)
{
	double sinthetagamma  = sin(photonthetaAnl);
	double sinthetaj1     = sin(jet1thetaAnl);
	double sinthetaj2     = sin(jet2thetaAnl);
	double sinphij1j2     = sin(jet1phiAnl-jet2phiAnl);
	double sinphij1gamma  = sin(jet1phiAnl-photonphiAnl);
	double sinphij2gamma  = sin(jet2phiAnl-photonphiAnl);

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

	//photon
	if (i == 0){
	return B2/A2;
	}

	//jet1
        if (i == 1){
	return B2*fAmum/A2;
	}	

	//jet2
        if (i == 2){
	return B2*fAmup/A2;
	}

	//ISR		
        if (i == 3){
	return Ecm-(B2/A2 + B2*fAmum/A2 + B2*fAmup/A2);
	}
}
