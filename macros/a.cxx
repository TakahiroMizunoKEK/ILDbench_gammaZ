
#include "/home/ilc/mizunot/bin/root_macros/style.C"


void IDR002PhotonMCTrueE() {

        stringstream filest;
        filest << "2f_z_l.eL.pR.mILD_l5_o1_v02.root" << ends;

        TFile *f = new TFile(filest.str().data());
	
	setILDStyle();
	//gStyle->SetPadLeftMargin(0.15);

        TCanvas *c1 = new TCanvas("c1","",0,0,600,600);	
        c1->SetRightMargin(.05);
        c1->SetLeftMargin(.25);

	//TFile *f = new TFile("2f_z_l.eL.pR.mILD_o1_v05.root");

        TNtuple *hGen = static_cast<TNtuple *>(f->Get("hGen"));
        TNtuple *hAnl = static_cast<TNtuple *>(f->Get("hAnl"));	
	/*Int_t nbinx=100;	
	Double_t xmin = -1.; 
	Double_t xmax = 1.; 	

	Int_t nbiny=100;	
	Double_t ymin = -0.05; 
	Double_t ymax = 0.05;*/ 	

	TH1D *h1 = new TH1D("h1","",200,0,500);
        hAnl->Draw("photonEMC>>h1","","sames");

	TLatex *   tex = new TLatex(10,600,"ILD preliminary");
	tex->SetTextFont(62);
	tex->Draw();



}
