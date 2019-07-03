
bool debug = false;
double recp = -9999.;

#include "jetERec1.cxx"
#include "jetERec2.cxx"
#include "jetERec3.cxx"

double betaBar(double x1, double x2)
{
	double bb = sqrt(1.-2.*(x1+x2)+pow(x1-x2,2));
	return bb;
}
 

void testjcomp()
{
	int recomethod = 1;
	
        TCanvas *c1 = new TCanvas("c1");
        TH2D *h1 = new TH2D("h1","h1",520,-10.,510.,520,-10.,510.);
        TH1D *h2 = new TH1D("h2","h2",520,-10.,510.);
        TH1D *h3 = new TH1D("h3","h3",520,-10.,510.);
        TH2D *h4 = new TH2D("h4","h4",520,-10.,510.,520,-10.,510.);

        TH1D *h51 = new TH1D("h51","h51",500,-.2,.2);
        TH1D *h52 = new TH1D("h52","h52",500,-.2,.2);
        TH1D *h53 = new TH1D("h53","h53",500,-.2,.2);

	double Mz  = 91.2;

	double Ebnom  = 250.;
	double Ecmnom = 2.*Ebnom;

	double alpha = 0.007;

	int nevt = 10000;

        double eptrue[nevt];
        double eprec1[nevt];
        double j1true[nevt];
        double j1rec1[nevt];
        double j2true[nevt];
        double j2rec1[nevt];

        double eprec2[nevt];
        double j1rec2[nevt];
        double j2rec2[nevt];

        double eprec3[nevt];
        double j1rec3[nevt];
        double j2rec3[nevt];



//******************* Making ISR *****************************

	for (int ievt=0; ievt<nevt; ievt++) {
		double fEcmIP = Ecmnom;
		//making ISR
		static const double kM_e = 0.511e-3;
		static const double kAlpha0 = 1./137.;
		static const double kFisr = 2. * kAlpha0 / TMath::Pi();
		double beta_isr = kFisr * (2.*(TMath::Log(fEcmIP/kM_e) - 1.));
	 	double xisr    = TMath::Power(gRandom->Uniform(),1./beta_isr); // Ephoton / Ebeam 
		//ISR energy threshold: xisr=0.5
        	if (xisr < 0.) xisr = 0.;
        	if (xisr > .5) xisr = 0.5;
	   	double Ecm = Ecmnom * TMath::Sqrt(1. - xisr);                // reduced Ecm
           	double eplus  = Ebnom;
           	double eminus = Ebnom;

   		if (gRandom->Uniform() > .5) {
   		 	  eplus  = eplus * (1. - xisr);
 		} else {
     			  eminus = eminus * (1. - xisr);
  		}	

//		cerr << "Ecm="<<Ecm << endl;
//******************* e+e- collsionn  *****************************

		double fZBoost = eminus - eplus; // P_Z of the cm system after ISR and beamstrahlung

		double Eb  = Ecm/2.;


		double x1 = pow(Mz/Ecm,2);
		double x2 = 0.;

		double P = Eb * betaBar(x1,x2);

		double Mj1=10.;
		double Mj2=15.;

		//double Mj1=0.;
		//double Mj2=0.;


		double Pj1 = (Mz/2.) * betaBar(pow((Mj1/Mz),2),
					pow((Mj2/Mz),2));
	
		double Ez = Ecm - P;
		double Ej1 = sqrt(Pj1 * Pj1 + Mj1 * Mj1);
		double Ej2 = sqrt(Pj1 * Pj1 + Mj2 * Mj2);

//		cerr <<"Pj1="<<Pj1<<" Ej1="<<Ej1<< endl;

		double costh = -1. + 2. * gRandom->Uniform();
		double phi   = 2. * TMath::Pi() * gRandom->Uniform();
		double pz    = P* costh;
		double sinth = sqrt((1.-costh)*(1.+costh));
		double px    = P* sinth * cos(phi);
		double py    = P* sinth * sin(phi);

		double cosj1 = -1. + 2. * gRandom->Uniform();
		double phij1 = 2. * TMath::Pi() * gRandom->Uniform();
		double pzj1  = Pj1* cosj1;
		double sinj1 = sqrt((1.-cosj1)*(1.+cosj1));
		double pxj1  = Pj1* sinj1 * cos(phij1);
		double pyj1  = Pj1* sinj1 * sin(phij1);

		TLorentzVector qphoton(-px,-py,-pz,P);
		TLorentzVector qZ(px,py,pz,Ez); 
		TLorentzVector qj1(pxj1,pyj1,pzj1,Ej1);
		TLorentzVector qj2(-pxj1,-pyj1,-pzj1,Ej2);
		TVector3 b = qZ.BoostVector();
		qj1.Boost(b);
		qj2.Boost(b);

  		Double_t elab = TMath::Sqrt(Ecm*Ecm + fZBoost*fZBoost);
		TVector3 boostv(0.,0.,fZBoost/elab);
                qj1.Boost(boostv);
                qj2.Boost(boostv);
                qphoton.Boost(boostv);
                qZ.Boost(boostv);
		//for (Int_t i=0; i<fNparton; i++) pv[i].Boost(boostv);  
 

		TLorentzVector qcm (0.,0.,0.,Ecmnom);
		TLorentzVector qISR = qcm - (qj1+qj2+qphoton);

		TVector3 boostx(sin(alpha),0.,0.);
                qj1.Boost(boostx);
                qj2.Boost(boostx);
                qphoton.Boost(boostx);
                qZ.Boost(boostx);
                qISR.Boost(boostx);
                qcm.Boost(boostx);
		//Crossing angle;


		//cerr<<"j1=("<<pxj1<<" "<<pyj1<<" "<<pzj1<<" "<<Ej1<<")"<<endl;
#if 0
		cerr<<"j1=("<<qj1.X()<<" "<<qj1.Y()<<" "<<qj1.Z()<<" "<<qj1.T()<<")"<<endl;
		cerr<<"j2=("<<qj2.X()<<" "<<qj2.Y()<<" "<<qj2.Z()<<" "<<qj2.T()<<")"<<endl;
		cerr<<"jsum=("<<(qj1+qj2).X()<<" "<<(qj1+qj2).Y()<<" "<<(qj1+qj2).Z()
		<<" "<<(qj1+qj2).T()<<")"<<endl;
		cerr<<"Z=("<<qZ.X()<<" "<<qZ.Y()<<" "<<qZ.Z()<<" "<<qZ.T()<<")"<<endl;

		cerr<<"sum=("<<(qj1+qj2+qphoton).X()<<" "<<(qj1+qj2+qphoton).Y()<<" "<<(qj1+qj2+qphoton).Z()
		<<" "<<(qj1+qj2+qphoton).T()<<")"<<endl;
#endif
		
		TLorentzVector qj1j2 = qj1 + qj2;
		TLorentzVector qdiff = qZ - qj1j2;
//		cerr << qdiff.X() <<" "<< qdiff.Y() <<" "<< qdiff.Z() <<" "<< qdiff.T() << endl;
		
		double jet1thetaAnl   = qj1.Theta();
		double jet1phiAnl     = qj1.Phi();
		double jet2thetaAnl   = qj2.Theta();
		double jet2phiAnl     = qj2.Phi();
		double photonthetaAnl = qphoton.Theta();
		double photonphiAnl   = qphoton.Phi();

		double EISR = qISR.E();
		double photonE   = qphoton.E();
		double j1E       = qj1.E();
		double j2E       = qj2.E();
		double photonEresol = 0.15;
//		double photonEresol = 0.;
		double photonEsme   = photonE + photonEresol * sqrt(photonE) * gRandom->Gaus(0.,1.);


                double EphotonRec[4];
                double Ej1Rec[4];
                double Ej2Rec[4];

		double recp1,recp2,recp3;

		
		for (recomethod =1;recomethod <=3; recomethod++){

			stringstream ss0;
			stringstream ss1;
			stringstream ss2;
			ss0<<"recp = jetERec"<<recomethod<<"(qcm.E(),photonEsme,Mj1,Mj2,jet1thetaAnl,jet1phiAnl,jet2thetaAnl,jet2phiAnl,photonthetaAnl,photonphiAnl,0);"<<ends;
			ss1<<"jetERec"<<recomethod<<"(qcm.E(),photonEsme,Mj1,Mj2,jet1thetaAnl,jet1phiAnl,jet2thetaAnl,jet2phiAnl,photonthetaAnl,photonphiAnl,1);"<<ends;
			ss2<<"jetERec"<<recomethod<<"(qcm.E(),photonEsme,Mj1,Mj2,jet1thetaAnl,jet1phiAnl,jet2thetaAnl,jet2phiAnl,photonthetaAnl,photonphiAnl,2);"<<ends;

			double recp1 = 0.;
			double recp2 = 0.;
			gROOT -> ProcessLine(ss0.str().data());
			double recp0 = recp;
			cerr<<"recp= "<<recp<<endl;


			if (recomethod ==1 || recomethod ==3){
                		//EphotonRec[recomethod] = ss2.str().data();
                		EphotonRec[recomethod] = recp2;
			} else if (recomethod ==2){
				EphotonRec[recomethod] = photonEsme;
			}	
                	//Ej1Rec[recomethod] = sqrt(pow(ss0.str().data(),2.)+pow(Mj1,2.));
                	//Ej2Rec[recomethod] = sqrt(pow(ss1.str().data(),2.)+pow(Mj2,2.));

                	Ej1Rec[recomethod] = sqrt(pow(recp0,2.)+pow(Mj1,2.));
                	Ej2Rec[recomethod] = sqrt(pow(recp1,2.)+pow(Mj2,2.));

		}

		//part0=jet1,part1=jet2,part2=photon		

		//part0=jet1,part1=jet2,part2=photon		

		//double EphotonRec = photonERec(Ecm,lep1thetaAnl,lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0);
		//cerr << "photonE="<<photonE << endl;
		//cerr << "EphotonRec="<<EphotonRec << endl;
		double diff = EphotonRec[1]-photonE;	
		TLorentzVector qsum = qj1 + qj2 + qphoton;
		double Esum = qsum.E() + EISR ;
		double pZsum = qsum.Z() + (eplus > eminus ? EISR : -EISR) ;

		//cerr << "EISRmc  = "<< EISR << endl;

		/*cerr << "P1Jmc   = "<< qj1.P() << endl;
		cerr << "P2Jmc   = "<< qj2.P() << endl;
		cerr << "Pgammamc= "<< qphoton.P() << endl;
*/
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
              //double x=Ej1;
              //double x=Pj1;
              double x=Pj1;
              //h2->Fill(x);  
//              

              eptrue[ievt]=photonE;
              j1true[ievt]=j1E;
              j2true[ievt]=j2E;

              eprec1[ievt]=EphotonRec[1];
              j1rec1[ievt]=Ej1Rec[1];
              j2rec1[ievt]=Ej2Rec[1];
              eprec2[ievt]=EphotonRec[2];
              j1rec2[ievt]=Ej1Rec[2];
              j2rec2[ievt]=Ej2Rec[2];
              eprec3[ievt]=EphotonRec[3];
              j1rec3[ievt]=Ej1Rec[3];
              j2rec3[ievt]=Ej2Rec[3];
//              cout<<"recE=  "<<eprec[ievt]<<endl;
//              cout<<"trueE= "<<eptrue[ievt]<<endl;;
              //h3->Fill();  
              //h3->Fill(ep);  
              //h4->Fill(EphotonRec,photonE);  
//             
		h51->Fill((j1rec1[ievt]-j1true[ievt])/j1true[ievt]);
		h52->Fill((j1rec2[ievt]-j1true[ievt])/j1true[ievt]);
		h53->Fill((j1rec3[ievt]-j1true[ievt])/j1true[ievt]);
 
//		double x=photonE;
//		double y=EphotonRec;
//	        h1->Fill(x,y); 	
	        //if (eplus < eminus) h1->Fill(x,y); 	
//		cerr << "------"<< endl;
		}


	//h1->Draw("colz");
	//h2->Draw("");
	//h3->Draw("");
	//f4->Draw("");


/*	TGraph *f1 = new TGraph(nevt,eptrue,eprec);
	f1->GetXaxis()->SetRangeUser(-10.,510.);
	f1->GetYaxis()->SetRangeUser(-10.,510.);
	f1->Draw("ap");
*/
	TGraph *f2 = new TGraph(nevt,j1true,j1rec1);
	f2->GetXaxis()->SetRangeUser(-10.,510.);
	f2->GetYaxis()->SetRangeUser(-10.,510.);
	f2->Draw("ap");

	int inc1 = 0;
	for (int l=0;l<nevt;l++){
//		if (abs(eprec[l]-eptrue[l])>0.1){
		if (abs((j1rec1[l]-j1true[l])/j1true[l])>.1){
			inc1++;
		}
	}
	//cout<<inc1<<endl;
	double irrate1= inc1;
	irrate1= inc1/(double)nevt;
	cout<<"incorect rec rate Case1= "<<irrate1<<endl;

	int inc2 = 0;
	for (int l=0;l<nevt;l++){
//		if (abs(eprec[l]-eptrue[l])>0.1){
		if (abs((j1rec2[l]-j1true[l])/j1true[l])>.1){
			inc2++;
		}
	}
	//cout<<inc1<<endl;
	double irrate2= inc2;
	irrate1= inc2/(double)nevt;
	cout<<"incorect rec rate Case2= "<<irrate2<<endl;
	int inc3 = 0;
	for (int l=0;l<nevt;l++){
//		if (abs(eprec[l]-eptrue[l])>0.1){
		if (abs((j1rec3[l]-j1true[l])/j1true[l])>.1){
			inc3++;
		}
	}
	//cout<<inc1<<endl;
	double irrate3= inc3;
	irrate1= inc3/(double)nevt;
	cout<<"incorect rec rate Case3= "<<irrate3<<endl;


        TCanvas *c2 = new TCanvas("c2");
	h51->SetLineColor(3);
	h51->Draw();
	h52->SetLineColor(5);
	h52->Draw("same");
	h53->SetLineColor(7);
	h53->Draw("same");


}

