
#include "/home/ilc/mizunot/bin/root_macros/style.C"


void Ereso02() {

        stringstream filest;
        filest << "../root_merge.mILD_l5_o1_v02/"
               << "2f_z_l.eL.pR.mILD_l5_o1_v02.root" << ends;

        TFile *f = new TFile(filest.str().data());
	
	setILDStyle();
//	gStyle->SetPadRightMargin(0.15);
	gStyle->SetPadLeftMargin(0.13);
	gStyle->SetOptStat(1);
	gStyle->SetOptFit(1);

	gStyle->SetTitleOffset(1.1,"x");
	gStyle->SetTitleOffset(0.9,"y");
	

	TCanvas *c1 = new TCanvas("c1");

	//TFile *f = new TFile("2f_z_l.eL.pR.mILD_o1_v05.root");
	
	TNtuple *hGen = f->Get("hGen");
	TNtuple *hAnl = f->Get("hAnl");
	
	Int_t nbinx=100;	
	Double_t xmin = -0.05; 
	Double_t xmax = 0.05; 	


	TH1D *h1 = new TH1D("h1","",nbinx,xmin,xmax);

	hAnl->Draw("-(lep1EMC-lep1EAnl)/lep1EMC>>h1","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)<0.2 && lep1EMC > 100");

	h1->SetXTitle("(E^{Rec}_{#mu}-E^{MC})/E^{MC}");
	h1->SetYTitle("Entries");

	h1->Draw();

	h1->Fit("gaus");



}
