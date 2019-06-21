#include "photonERec4.cxx"


double betaBar(double x1, double x2)
{
	double bb = sqrt(1.-2.*(x1+x2)+pow(x1-x2,2));
	return bb;
}
 

void test4()
{
        TCanvas *c1 = new TCanvas("c1");
        TH2D *h1 = new TH2D("h1","h1",520,-10.,510.,520,-10.,510.);

	double Mz  = 91.2;
	double Mmu = 0.106;

	double Ebnom  = 250.;
	double Ecmnom = 2.*Ebnom;


	int nevt = 10000;

	for (int ievt=0; ievt<nevt; ievt++) {
	

		double fEcmIP = Ecmnom;
		static const double kM_e = 0.511e-3;
		static const double kAlpha0 = 1./137.;
		static const double kFisr = 2. * kAlpha0 / TMath::Pi();
		double beta_isr = kFisr * (2.*(TMath::Log(fEcmIP/kM_e) - 1.));
	 	double xisr    = TMath::Power(gRandom->Uniform(),1./beta_isr); // Ephoton / Ebeam 
        	if (xisr < 0.) xisr = 0.;
        	if (xisr > .5) xisr = 0.5;
	   	double Ecm = Ecmnom * TMath::Sqrt(1. - xisr);                // reduced Ecm
           	double eplus  = Ebnom;
           	double eminus = Ebnom;

   		if (gRandom->Uniform() > 0.5) {
   		 	  eplus  = eplus * (1. - xisr);
 		} else {
     			  eminus = eminus * (1. - xisr);
  		}	
		double fZBoost = eminus - eplus; // P_z of the cm system after ISR and beamstrahlung


		double Eb  = Ecm/2.;

		double x1 = pow(Mz/Ecm,2);
		double x2 = 0.;

		double P = Eb * betaBar(x1,x2);
		double Pmum = (Mz/2.) * betaBar(pow((Mmu/Mz),2),
					pow((Mmu/Mz),2));
	
		double Ez = Ecm - P;
		double Emum = sqrt(Pmum * Pmum + Mmu * Mmu);

		double costh = -1. + 2. * gRandom->Uniform();
		double phi   = 2. * TMath::Pi() * gRandom->Uniform();
		double pz    = P* costh;
		double sinth = sqrt((1.-costh)*(1.+costh));
		double px    = P* sinth * cos(phi);
		double py    = P* sinth * sin(phi);

		double cosmum = -1. + 2. * gRandom->Uniform();
		double phimum = 2. * TMath::Pi() * gRandom->Uniform();
		double pzmum  = Pmum* cosmum;
		double sinmum = sqrt((1.-cosmum)*(1.+cosmum));
		double pxmum  = Pmum* sinmum * cos(phimum);
		double pymum  = Pmum* sinmum * sin(phimum);

		TLorentzVector qphoton(-px,-py,-pz,P);
		TLorentzVector qZ(px,py,pz,Ez); 
		TLorentzVector qmum(pxmum,pymum,pzmum,Emum);
		TLorentzVector qmup(-pxmum,-pymum,-pzmum,Emum);
		TVector3 b = qZ.BoostVector();
		qmum.Boost(b);
		qmup.Boost(b);

  		Double_t elab = TMath::Sqrt(Ecm*Ecm + fZBoost*fZBoost);
		TVector3 boostv(0.,0.,fZBoost/elab);
                qmum.Boost(boostv);
                qmup.Boost(boostv);
                qphoton.Boost(boostv);
                qZ.Boost(boostv);
		//for (Int_t i=0; i<fNparton; i++) pv[i].Boost(boostv);  
 

		
		TLorentzVector qmummup = qmum + qmup;
		TLorentzVector qdiff = qZ - qmummup;
		//cerr << qdiff.X() <<" "<< qdiff.Y() <<" "<< qdiff.Z() <<" "
		//     << qdiff.T() << endl;
		
		double lep1thetaAnl   = qmum.Theta();
		double lep1phiAnl     = qmum.Phi();
		double lep2thetaAnl   = qmup.Theta();
		double lep2phiAnl     = qmup.Phi();
		double photonthetaAnl = qphoton.Theta();
		double photonphiAnl   = qphoton.Phi();

		double photonE   = qphoton.E();
		double EphotonRec = photonERec4(Ecmnom,lep1thetaAnl,lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0);
		double diff = EphotonRec-photonE;	
		TLorentzVector qsum = qmum + qmup + qphoton;
		double EISR = Ebnom  *xisr;
		double Esum = qsum.E() + EISR ;
		double pZsum = qsum.Z() + (eplus > eminus ? EISR : -EISR) ;


#if 0
	cerr<<"photonErec4 = "<< EphotonRec <<endl;
	cerr<<"photonE = "<< photonE <<endl;
	cerr<<"diff = "<< diff <<endl;
	cerr<<"boostv = "<< boostv.Z() <<endl;
	cerr<<"beta_isr = "<< beta_isr <<endl;
	cerr<<"xisr = "<< xisr <<endl;
	cerr<<"Esum = "<< Esum <<endl;
	cerr<<"pZsum = "<< pZsum <<endl;
	cerr<<"pXsum = "<< qsum.X() <<endl;
	cerr<<"pYsum = "<< qsum.Y() <<endl;
	//cerr<<"qdiff = "<< qdiff <<endl;
	cerr<<"EphotonRec - photonE = "<< EphotonRec-photonE <<endl;
	cerr<<"  "<<endl;
#endif


		double x=photonE;
		double y=EphotonRec;
	        //if (eplus < eminus) h1->Fill(x,y); 	
	        h1->Fill(x,y); 	
}


	h1->Draw("colz");
}

