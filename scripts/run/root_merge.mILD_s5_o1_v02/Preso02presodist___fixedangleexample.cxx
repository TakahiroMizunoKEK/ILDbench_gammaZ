
#include "/home/ilc/mizunot/bin/root_macros/style.C"


void Preso02presodist___fixedangleexample() {

        stringstream filest;
        filest << "../root_merge.mILD_s5_o1_v02/"
               << "2f_z_l.eL.pR.mILD_s5_o1_v02.root" << ends;

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
	
        TNtuple *hGen = static_cast<TNtuple *>(f->Get("hGen"));
        TNtuple *hAnl = static_cast<TNtuple *>(f->Get("hAnl"));
	
	Int_t nbinx=100;	
	Double_t xmin = -0.05; 
	Double_t xmax = 0.05; 	


	TH1D *h1 = new TH1D("h1","",nbinx,xmin,xmax);

	hAnl->Draw("-(lep1PMC-lep1PAnl)/lep1PMC>>h1","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)<0.2 && lep1PMC > 100");

	h1->SetXTitle("(P^{Rec}_{#mu}-P^{MC})/P^{MC}");
	h1->SetYTitle("Entries");

	h1->Draw();

	h1->Fit("gaus");



}
