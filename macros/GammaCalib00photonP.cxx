
#include "/home/ilc/mizunot/bin/root_macros/style.C"
#include "photonERec4.cxx"

void GammaCalib00photonP() {

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

	TH1D *h1 = new TH1D("h1","",nbinx,xmin,xmax);
	TH1D *h2 = new TH1D("h2","",nbinx,xmin,xmax);
        TH2D *h3 = new TH2D("h3","",nbinx,xmin,xmax,nbiny,ymin,ymax);

	TCut cut1 = "pdg0==13 && abs(mzgen-91.2)<10";
	TCut cut3 = "coneen > -0.5";
	TCut cut4 = "abs(coslep1)<0.75 && abs(coslep2)<0.75";
        TCut cut2 = cut3+cut4;
       // TCut cut5 = "(ISR1EMC > ISR2EMC ? ISR2EMC<.1 : ISR1EMC<.1 )";
        TCut cut5 = "1>0";

        TCanvas *c1 = new TCanvas("c1");
        c1->Divide(2,2);
        c1->cd(1);

	hAnl->Draw("photonEMC>>h1",cut1+cut2+cut5);
        h1->Draw("");
        h1->SetTitle("Energy of Photon (MC)");
        h1->SetXTitle("Energy of Photon (MC)");

	//TCanvas *c2 = new TCanvas("c2");
	c1->cd(2);
	
	hAnl->Draw("photonEAnl>>h2",cut1+cut2+cut5);
	h2->Draw("");
        h2->SetTitle("Energy of Photon (PFO)");
        h2->SetXTitle("Energy of Photon (PFO)");

        //TCanvas *c3 = new TCanvas("c3");
	c1->cd(3);
	hAnl->Draw("photonEMC:photonEAnl>>h3",cut1+cut2+cut5);
        h3->Draw("colz");

        h3->SetTitle("Energy of Photon (MC:PFO)");
        h3->SetXTitle("Energy of Photon (PFO)");
        h3->SetYTitle("Energy of Photon (MC)");



        TCanvas *c20 = new TCanvas("c20");
        h3->Draw("colz");



	}
