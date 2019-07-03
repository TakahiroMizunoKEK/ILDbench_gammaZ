
#include "/home/ilc/mizunot/bin/root_macros/style.C"

double photonERec(double lep1thetaAnl,double lep1phiAnl, double lep2thetaAnl,
double lep2phiAnl, double photonthetaAnl, double photonphiAnl)
{
return 500.*sin(lep1thetaAnl)*sin(lep2thetaAnl)*(cos(lep1phiAnl)*sin(lep2phiAnl)-sin(lep1phiAnl)*cos(lep2phiAnl))/(sin(lep1thetaAnl)*sin(lep2thetaAnl)*(cos(lep1phiAnl)*sin(lep2phiAnl)-sin(lep1phiAnl)*cos(lep2thetaAnl))+sin(lep2thetaAnl)*sin(photonthetaAnl)*(cos(lep2phiAnl)*sin(photonphiAnl)-sin(lep2phiAnl)*cos(photonphiAnl))+sin(lep1thetaAnl)*sin(photonthetaAnl)*(sin(lep1phiAnl)*cos(photonphiAnl)-sin(photonphiAnl)*cos(lep1phiAnl)));
}

void GammaCalib02_02photonP() {

        stringstream filest;
        filest << "../root_merge.mILD_l5_o1_v02/"
               << "2f_z_l.eL.pR.mILD_l5_o1_v02.root" << ends;

        TFile *f = new TFile(filest.str().data());
	
	setILDStyle();
	gStyle->SetPadRightMargin(1.0);
	gStyle->SetOptFit(111);

        TNtuple *hGen = static_cast<TNtuple *>(f->Get("hGen"));
        TNtuple *hAnl = static_cast<TNtuple *>(f->Get("hAnl"));
	
	Int_t nbinx=1200;	
	Double_t xmin = 0.; 
	Double_t xmax = 600.; 	

	Int_t nbiny=300;	
	Double_t ymin = 0.; 
	Double_t ymax = 600.; 	

	TH1D *h1 = new TH1D("h1","",nbinx,-600.,600.);
	TH1D *h2 = new TH1D("h2","",nbinx,-600.,600.);
        TH2D *h3 = new TH2D("h3","",1200,-600,xmax,1200,-600,ymax);

	TH1D *h4 = new TH1D("h4","",nbinx,-600.,600.);
	TH1D *h5 = new TH1D("h5","",nbinx,-600.,600.);
        TH2D *h6 = new TH2D("h6","",nbinx,xmin,xmax,nbiny,ymin,ymax);

	TH1D *h7 = new TH1D("h7","",nbinx,-600.,600.);
	TH1D *h8 = new TH1D("h8","",nbinx,-600.,600.);
        TH2D *h9 = new TH2D("h9","",nbinx,xmin,xmax,nbiny,ymin,ymax);

	TH1D *h10 = new TH1D("h10","",nbinx,-600.,600.);
	TH1D *h11 = new TH1D("h11","",nbinx,-600.,600.);
        TH2D *h12 = new TH2D("h12","",nbinx,-600,xmax,nbiny,-600,ymax);

	TH1D *h13 = new TH1D("h13","",nbinx,-600.,600.);
	TH1D *h14 = new TH1D("h14","",nbinx,-600.,600.);
        TH2D *h15 = new TH2D("h15","",nbinx,xmin,xmax,nbiny,ymin,ymax);

	TH1D *h16 = new TH1D("h16","",nbinx,-600.,600.);
	TH1D *h17 = new TH1D("h17","",nbinx,-600.,600.);
        TH2D *h18 = new TH2D("h18","",nbinx,xmin,xmax,nbiny,ymin,ymax);

        TCanvas *c1 = new TCanvas("c1");
        c1->Divide(2,2);
        c1->cd(1);

	hAnl->Draw("photonEAnl>>h1","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.75 && abs(coslep2)>0.0 && abs(coslep2)<0.75");
        h1->Draw("");
        h1->SetTitle("Energy of Photon (Anl)");
        h1->SetXTitle("Energy of Photon (Anl)");

	//TCanvas *c2 = new TCanvas("c2");
	c1->cd(2);
	
	hAnl->Draw("(photonERec(lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))>>h2","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.75 && abs(coslep2)>0.0 && abs(coslep2)<0.75");
	h2->Draw("");
        h2->SetTitle("Energy of Photon (Reconstructed)");
        h2->SetXTitle("Energy of Photon (Reconstructed)");

        //TCanvas *c3 = new TCanvas("c3");
	c1->cd(3);
	hAnl->Draw("photonEAnl:(photonERec(lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))>>h3","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.75 && abs(coslep2)>0.0 && abs(coslep2)<0.75");
        h3->Draw("colz");

        h3->SetTitle("Energy of Photon (Anl:Reconstructed)");
        h3->SetXTitle("Energy of Photon (Reconstructed)");
        h3->SetYTitle("Energy of Photon (Anl)");



	TCanvas *c4 = new TCanvas("c4");
	c4->Divide(2,2);
        c4->cd(1);
	hAnl->Draw("lep1EAnl>>h4","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.75 && abs(coslep2)>0.0 && abs(coslep2)<0.75");
        h4->Draw("");
        h4->SetTitle("Energy of Mu^{-} (Anl)");
        h4->SetXTitle("Energy of Mu^{-} (Anl)");

	//TCanvas *c5 = new TCanvas("c5");
	c4->cd(2);
	hAnl->Draw("500.*sin(photonthetaAnl)*sin(lep2thetaAnl)*(cos(lep2phiAnl)*sin(photonphiAnl)-sin(lep2phiAnl)*cos(photonphiAnl))/(sin(lep2thetaAnl)*sin(photonthetaAnl)*(cos(lep2phiAnl)*sin(photonphiAnl)-sin(lep2phiAnl)*cos(photonthetaAnl))+sin(lep1thetaAnl)*sin(photonthetaAnl)*(cos(photonphiAnl)*sin(lep1phiAnl)-sin(photonphiAnl)*cos(lep1phiAnl))+sin(lep1thetaAnl)*sin(lep2thetaAnl)*(sin(lep2phiAnl)*cos(lep1phiAnl)-sin(lep1phiAnl)*cos(lep2phiAnl)))>>h5","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.75 && abs(coslep2)>0.0 && abs(coslep2)<0.75");
	h5->Draw("");
        h5->SetTitle("Energy of Mu^{-} (Reconstructed)");
        h5->SetXTitle("Energy of Mu^{-} (Reconstructed)");

        //TCanvas *c6 = new TCanvas("c6");
        c4->cd(3);
	hAnl->Draw("lep1EAnl:500.*sin(photonthetaAnl)*sin(lep2thetaAnl)*(cos(lep2phiAnl)*sin(photonphiAnl)-sin(lep2phiAnl)*cos(photonphiAnl))/(sin(lep2thetaAnl)*sin(photonthetaAnl)*(cos(lep2phiAnl)*sin(photonphiAnl)-sin(lep2phiAnl)*cos(photonthetaAnl))+sin(lep1thetaAnl)*sin(photonthetaAnl)*(cos(photonphiAnl)*sin(lep1phiAnl)-sin(photonphiAnl)*cos(lep1phiAnl))+sin(lep1thetaAnl)*sin(lep2thetaAnl)*(sin(lep2phiAnl)*cos(lep1phiAnl)-sin(lep1phiAnl)*cos(lep2phiAnl)))>>h6","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.75 && abs(coslep2)>0.0 && abs(coslep2)<0.75");
        h6->Draw("colz");

        h6->SetTitle("Energy of Mu^{-} (Anl:Reconstructed)");
        h6->SetXTitle("Energy of Mu^{-} (Reconstructed)");
        h6->SetYTitle("Energy of Mu^{-} (Anl)");
	
	TCanvas *c7 = new TCanvas("c7");
	c7->Divide(2,2);
        c7->cd(1);
	hAnl->Draw("lep2EAnl>>h7","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.75 && abs(coslep2)>0.0 && abs(coslep2)<0.75");
        h7->Draw("");
        h7->SetTitle("Energy of Mu^{+} (Anl)");
        h7->SetXTitle("Energy of Mu^{+} (Anl)");

	//TCanvas *c8 = new TCanvas("c8");
	c7->cd(2);
	hAnl->Draw("500.*sin(photonthetaAnl)*sin(lep1thetaAnl)*(cos(lep1phiAnl)*sin(photonphiAnl)-sin(lep1phiAnl)*cos(photonphiAnl))/(sin(lep1thetaAnl)*sin(photonthetaAnl)*(cos(lep1phiAnl)*sin(photonphiAnl)-sin(lep1phiAnl)*cos(photonthetaAnl))+sin(lep2thetaAnl)*sin(photonthetaAnl)*(cos(photonphiAnl)*sin(lep2phiAnl)-sin(photonphiAnl)*cos(lep2phiAnl))+sin(lep1thetaAnl)*sin(lep2thetaAnl)*(sin(lep1phiAnl)*cos(lep2phiAnl)-sin(lep2phiAnl)*cos(lep1phiAnl)))>>h8","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.75 && abs(coslep2)>0.0 && abs(coslep2)<0.75");
	h8->Draw("");
        h8->SetTitle("Energy of Mu^{+} (Reconsructed)");
        h8->SetXTitle("Energy of Mu^{+} (Reconstructed)");

        //TCanvas *c9 = new TCanvas("c9");
	c7->cd(3);
	hAnl->Draw("lep2EAnl:500.*sin(photonthetaAnl)*sin(lep1thetaAnl)*(cos(lep1phiAnl)*sin(photonphiAnl)-sin(lep1phiAnl)*cos(photonphiAnl))/(sin(lep1thetaAnl)*sin(photonthetaAnl)*(cos(lep1phiAnl)*sin(photonphiAnl)-sin(lep1phiAnl)*cos(photonthetaAnl))+sin(lep2thetaAnl)*sin(photonthetaAnl)*(cos(photonphiAnl)*sin(lep2phiAnl)-sin(photonphiAnl)*cos(lep2phiAnl))+sin(lep1thetaAnl)*sin(lep2thetaAnl)*(sin(lep1phiAnl)*cos(lep2phiAnl)-sin(lep2phiAnl)*cos(lep1phiAnl)))>>h9","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.75 && abs(coslep2)>0.0 && abs(coslep2)<0.75");
        h9->Draw("colz");

        h9->SetTitle("Energy of Mu^{+} (Anl:Reconstructed)");
        h9->SetXTitle("Energy of Mu^{+} (Reconstructed)");
        h9->SetYTitle("Energy of Mu^{+} (Anl)");



        TCanvas *c10 = new TCanvas("c10");
        c10->Divide(2,2);
        c10->cd(1);

	hAnl->Draw("photonEMC>>h10","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.75 && abs(coslep2)>0.0 && abs(coslep2)<0.75");
        h10->Draw("");
        h10->SetTitle("Energy of Photon (MC)");
        h10->SetXTitle("Energy of Photon (MC)");

	//TCanvas *c11 = new TCanvas("c11");
	c10->cd(2);
	hAnl->Draw("500.*sin(lep1thetaAnl)*sin(lep2thetaAnl)*(cos(lep1phiAnl)*sin(lep2phiAnl)-sin(lep1phiAnl)*cos(lep2phiAnl))/(sin(lep1thetaAnl)*sin(lep2thetaAnl)*(cos(lep1phiAnl)*sin(lep2phiAnl)-sin(lep1phiAnl)*cos(lep2thetaAnl))+sin(lep2thetaAnl)*sin(photonthetaAnl)*(cos(lep2phiAnl)*sin(photonphiAnl)-sin(lep2phiAnl)*cos(photonphiAnl))+sin(lep1thetaAnl)*sin(photonthetaAnl)*(sin(lep1phiAnl)*cos(photonphiAnl)-sin(photonphiAnl)*cos(lep1phiAnl)))>>h11","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.75 && abs(coslep2)>0.0 && abs(coslep2)<0.75");
	h11->Draw("");
        h11->SetTitle("Energy of Photon (Reconstructed)");
        h11->SetXTitle("Energy of Photon (Reconstructed)");

        //TCanvas *c12 = new TCanvas("c12");
	c10->cd(3);
	hAnl->Draw("photonEMC:500.*sin(lep1thetaAnl)*sin(lep2thetaAnl)*(cos(lep1phiAnl)*sin(lep2phiAnl)-sin(lep1phiAnl)*cos(lep2phiAnl))/(sin(lep1thetaAnl)*sin(lep2thetaAnl)*(cos(lep1phiAnl)*sin(lep2phiAnl)-sin(lep1phiAnl)*cos(lep2thetaAnl))+sin(lep2thetaAnl)*sin(photonthetaAnl)*(cos(lep2phiAnl)*sin(photonphiAnl)-sin(lep2phiAnl)*cos(photonphiAnl))+sin(lep1thetaAnl)*sin(photonthetaAnl)*(sin(lep1phiAnl)*cos(photonphiAnl)-sin(photonphiAnl)*cos(lep1phiAnl)))>>h12","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.75 && abs(coslep2)>0.0 && abs(coslep2)<0.75");
        h12->Draw("colz");

        h12->SetTitle("Energy of Photon (MC:Reconstructed)");
        h12->SetXTitle("Energy of Photon (Reconstructed)");
        h12->SetYTitle("Energy of Photon (MC)");


	TCanvas *c13 = new TCanvas("c13");
	c13->Divide(2,2);
        c13->cd(1);
	hAnl->Draw("lep1EMC>>h13","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.75 && abs(coslep2)>0.0 && abs(coslep2)<0.75");
        h13->Draw("");
        h13->SetTitle("Energy of Mu^{-} (MC)");
        h13->SetXTitle("Energy of Mu^{-} (MC)");

	//TCanvas *c14 = new TCanvas("c14");
	c13->cd(2);
	hAnl->Draw("500.*sin(photonthetaAnl)*sin(lep2thetaAnl)*(cos(lep2phiAnl)*sin(photonphiAnl)-sin(lep2phiAnl)*cos(photonphiAnl))/(sin(lep2thetaAnl)*sin(photonthetaAnl)*(cos(lep2phiAnl)*sin(photonphiAnl)-sin(lep2phiAnl)*cos(photonthetaAnl))+sin(lep1thetaAnl)*sin(photonthetaAnl)*(cos(photonphiAnl)*sin(lep1phiAnl)-sin(photonphiAnl)*cos(lep1phiAnl))+sin(lep1thetaAnl)*sin(lep2thetaAnl)*(sin(lep2phiAnl)*cos(lep1phiAnl)-sin(lep1phiAnl)*cos(lep2phiAnl)))>>h14","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.75 && abs(coslep2)>0.0 && abs(coslep2)<0.75");
	h14->Draw("");
        h14->SetTitle("Energy of Mu^{-} (Reconstructed)");
        h14->SetXTitle("Energy of Mu^{-} (Reconstructed)");

        //TCanvas *c15 = new TCanvas("c15");
        c13->cd(3);
	hAnl->Draw("lep1EMC:500.*sin(photonthetaAnl)*sin(lep2thetaAnl)*(cos(lep2phiAnl)*sin(photonphiAnl)-sin(lep2phiAnl)*cos(photonphiAnl))/(sin(lep2thetaAnl)*sin(photonthetaAnl)*(cos(lep2phiAnl)*sin(photonphiAnl)-sin(lep2phiAnl)*cos(photonthetaAnl))+sin(lep1thetaAnl)*sin(photonthetaAnl)*(cos(photonphiAnl)*sin(lep1phiAnl)-sin(photonphiAnl)*cos(lep1phiAnl))+sin(lep1thetaAnl)*sin(lep2thetaAnl)*(sin(lep2phiAnl)*cos(lep1phiAnl)-sin(lep1phiAnl)*cos(lep2phiAnl)))>>h15","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.75 && abs(coslep2)>0.0 && abs(coslep2)<0.75");
        h15->Draw("colz");

        h15->SetTitle("Energy of Mu^{-} (MC:Reconstructed)");
        h15->SetXTitle("Energy of Mu^{-} (Reconstructed)");
        h15->SetYTitle("Energy of Mu^{-} (MC)");
	
	TCanvas *c16 = new TCanvas("c16");
	c16->Divide(2,2);
        c16->cd(1);
	hAnl->Draw("lep2EMC>>h16","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.75 && abs(coslep2)>0.0 && abs(coslep2)<0.75");
        h16->Draw("");
        h16->SetTitle("Energy of Mu^{+} (MC)");
        h16->SetXTitle("Energy of Mu^{+} (MC)");

	//TCanvas *c8 = new TCanvas("c8");
	c16->cd(2);
	hAnl->Draw("500.*sin(photonthetaAnl)*sin(lep1thetaAnl)*(cos(lep1phiAnl)*sin(photonphiAnl)-sin(lep1phiAnl)*cos(photonphiAnl))/(sin(lep1thetaAnl)*sin(photonthetaAnl)*(cos(lep1phiAnl)*sin(photonphiAnl)-sin(lep1phiAnl)*cos(photonthetaAnl))+sin(lep2thetaAnl)*sin(photonthetaAnl)*(cos(photonphiAnl)*sin(lep2phiAnl)-sin(photonphiAnl)*cos(lep2phiAnl))+sin(lep1thetaAnl)*sin(lep2thetaAnl)*(sin(lep1phiAnl)*cos(lep2phiAnl)-sin(lep2phiAnl)*cos(lep1phiAnl)))>>h17","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.75 && abs(coslep2)>0.0 && abs(coslep2)<0.75");
	h17->Draw("");
        h17->SetTitle("Energy of Mu^{+} (Reconstructed)");
        h17->SetXTitle("Energy of Mu^{+} (Reconstructed)");

        //TCanvas *c9 = new TCanvas("c9");
	c16->cd(3);
	hAnl->Draw("lep2EMC:500.*sin(photonthetaAnl)*sin(lep1thetaAnl)*(cos(lep1phiAnl)*sin(photonphiAnl)-sin(lep1phiAnl)*cos(photonphiAnl))/(sin(lep1thetaAnl)*sin(photonthetaAnl)*(cos(lep1phiAnl)*sin(photonphiAnl)-sin(lep1phiAnl)*cos(photonthetaAnl))+sin(lep2thetaAnl)*sin(photonthetaAnl)*(cos(photonphiAnl)*sin(lep2phiAnl)-sin(photonphiAnl)*cos(lep2phiAnl))+sin(lep1thetaAnl)*sin(lep2thetaAnl)*(sin(lep1phiAnl)*cos(lep2phiAnl)-sin(lep2phiAnl)*cos(lep1phiAnl)))>>h18","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.75 && abs(coslep2)>0.0 && abs(coslep2)<0.75");
	//h3->SetYTitle("(P_t^{Rec}_{#mu}-P_t^{MC})/(P_t^{MC})^{2}");
	//h3->SetXTitle("P_t^{MC}");
        h18->Draw("colz");

        h18->SetTitle("Energy of Mu^{+} (MC:Reconstructed)");
        h18->SetXTitle("Energy of Mu^{+} (Reconstructed)");
        h18->SetYTitle("Energy of Mu^{+} (MC)");


	}
