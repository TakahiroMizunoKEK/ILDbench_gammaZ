
#include "/home/ilc/mizunot/bin/root_macros/style.C"


void IDR002PhotonMCTrueE() {

        stringstream filest;
        filest << "2f_z_l.eL.pR.mILD_l5_o1_v02.root" << ends;

        TFile *f = new TFile(filest.str().data());
	
	setILDStyle();
	//gStyle->SetPadLeftMargin(0.15);

	TCut cut1 = "pdg0==13 && abs(mzgen-91.2)<10";
	TCut cut3 = "coneen > -0.5";
        TCut cut2 = cut3+cut1;

        TCanvas *c1 = new TCanvas("c1","",0,0,600,600);	
        c1->SetRightMargin(.05);
        c1->SetLeftMargin(.21);

	//TFile *f = new TFile("2f_z_l.eL.pR.mILD_o1_v05.root");

        TNtuple *hGen = static_cast<TNtuple *>(f->Get("hGen"));
        TNtuple *hAnl = static_cast<TNtuple *>(f->Get("hAnl"));	
	/*Int_t nbinx=100;	
	Double_t xmin = -1.; 
	Double_t xmax = 1.; 	

	Int_t nbiny=100;	
	Double_t ymin = -0.05; 
	Double_t ymax = 0.05;*/ 	

	TH1D *h1 = new TH1D("h1","",200,60,260);
	h1->SetFillColor(kSpring-8);
        hAnl->Draw("photonEMC>>h1",cut2);
	h1->SetXTitle("E_{#gamma}^{MC} (GeV)");
        h1->SetYTitle("Entries/GeV");
	h1->GetYaxis()->SetTitleOffset(1.5); 

	TLatex *   tex = new TLatex(70,2300,"ILD preliminary");
	tex->SetTextFont(62);
	tex->Draw();



}
