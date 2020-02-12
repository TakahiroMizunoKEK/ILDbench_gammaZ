
#include "/home/ilc/mizunot/bin/root_macros/style.C"
#include "photonERec.cxx"
#include "photonERec3.cxx"
#include "photonERec4.cxx"

void GammaCalib07_02photonP() {

        stringstream filest;
        filest << "../root_merge.mILD_l5_o1_v02/"
               << "2f_z_l.eL.pR.mILD_l5_o1_v02.root" << ends;

        TFile *f = new TFile(filest.str().data());
	
	setILDStyle();
	//gStyle->SetPadRightMargin(1.0);
	//gStyle->SetPadRightMargin(1.0);
	gStyle->SetOptStat(1000001110);
        gStyle->SetStatH(0.15);
        gStyle->SetStatX(0.9);
        gStyle->SetStatY(0.9);
	gStyle->SetOptFit();

        TNtuple *hGen = static_cast<TNtuple *>(f->Get("hGen"));
        TNtuple *hAnl = static_cast<TNtuple *>(f->Get("hAnl"));
	
	double Ecm = 500.;

	Int_t nbinx   = 520;	
	Double_t xmin = -10.; 
	Double_t xmax = 510.; 	

	Int_t nbiny   = 520;	
	Double_t ymin = -10.; 
	Double_t ymax = 510.; 	

        TH1D *h20 = new TH1D("h20","",200.,-.6,.6);
        TH1D *h40 = new TH1D("h40","",200.,-.6,.6);
        TH1D *h60 = new TH1D("h60","",200.,-.6,.6);


	TCut cut1 = "pdg0==13 && abs(mzgen-91.2)<10";
	TCut cut3 = "coneen > -0.5";
	TCut cut4 = "abs(coslep1)<0.75 && abs(coslep2)<0.75";
        TCut cut2 = cut3+cut4;


        TCanvas *c10 = new TCanvas("c10");
	hAnl->Draw("(-photonEMC+photonERec(500.,lep1thetaMC, lep1phiMC,lep2thetaMC,lep2phiMC,photonthetaMC,photonphiMC,0))/photonEMC>>h20",cut1+cut2);
        //h20->Draw("");

        //h20->SetTitle("Energy Resolution of Photon");
        //h20->SetXTitle("Energy Resolution of Photon");
        //h20->SetYTitle("");

        hAnl->Draw("(-photonEMC+photonERec3(500.,lep1thetaMC, lep1phiMC,lep2thetaMC,lep2phiMC,photonthetaMC,photonphiMC,0))/photonEMC>>h40",cut1+cut2);
        //h40->Draw("same");
        h40->SetLineColor(kGreen+2);

  hAnl->Draw("(-photonEMC+photonERec4(500.,lep1thetaMC, lep1phiMC,lep2thetaMC,lep2phiMC,photonthetaMC,photonphiMC,0))/photonEMC>>h60",cut1+cut2);
        h60->SetTitle("Energy Resolution of Photon");
        h60->SetXTitle("Energy Resolution of Photon");
        h60->SetYTitle("");
	h60->SetLineColor(kOrange-3);
        
	h60->Draw("");
        h40->Draw("same");
        h20->Draw("same");
	}
