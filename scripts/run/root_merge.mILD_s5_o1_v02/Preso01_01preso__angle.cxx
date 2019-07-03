
#include "/home/ilc/mizunot/bin/root_macros/style.C"


void Preso01_01preso__angle() {

        stringstream filest;
        filest << "../root_merge.mILD_s5_o1_v02/"
	<< "2f_z_l.eL.pR.mILD_s5_o1_v02.root" << ends;

        TFile *f = new TFile(filest.str().data());
	
	setILDStyle();
	gStyle->SetPadRightMargin(0.15);

	TCanvas *c1 = new TCanvas("c1");

	//TFile *f = new TFile("2f_z_l.eL.pR.mILD_o1_v05.root");
	
	TNtuple *hGen = static_cast<TNtuple *>(f->Get("hGen"));
	TNtuple *hAnl = static_cast<TNtuple *>(f->Get("hAnl"));
	
	Int_t nbinx=100;	
	Double_t xmin = -1.; 
	Double_t xmax = 1.; 	

	Int_t nbiny=100;	
	Double_t ymin = -0.05; 
	Double_t ymax = 0.05; 	

	TH2D *h1 = new TH2D("h1","",nbinx,xmin,xmax,nbiny,ymin,ymax);

	hAnl->Draw("-(lep1PMC-lep1PAnl)/lep1PMC:coslep1>>h1","pdg0==13 && abs(mzgen-91.2)<10");

	h1->SetYTitle("(P^{Rec}_{#mu}-P^{MC})/P^{MC}");
	h1->SetXTitle("cos(#mu-)");

	h1->Draw("colz");

}
