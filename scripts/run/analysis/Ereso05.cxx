
#include "/home/ilc/mizunot/bin/root_macros/style.C"


void Ereso05() {

        stringstream filest;
        filest << "../root_merge.mILD_l5_o1_v02/"
               << "2f_z_l.eL.pR.mILD_l5_o1_v02.root" << ends;

        TFile *f = new TFile(filest.str().data());
	
	setILDStyle();
	gStyle->SetPadRightMargin(0.10);

	TCanvas *c1 = new TCanvas("c1");

	//TFile *f = new TFile("2f_z_l.eL.pR.mILD_o1_v05.root");
	
	TNtuple *hGen = f->Get("hGen");
	TNtuple *hAnl = f->Get("hAnl");
	
	Int_t nbinx=20;	
	Double_t xmin = 0.; 
	Double_t xmax = 250.; 	

	Int_t nbiny=200;	
	Double_t ymin = -0.05; 
	Double_t ymax = 0.05; 	

	TH2D *h1 = new TH2D("h1","",nbinx,xmin,xmax,nbiny,ymin,ymax);

	hAnl->Draw("-(lep1EMC-lep1EAnl)/lep1EMC:lep1EMC>>h1","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)<0.1");

	h1->SetYTitle("(E^{Rec}_{#mu}-E^{MC})/E^{MC}");
	h1->SetXTitle("E^{MC}");
       
	TH2D *h1 = static_cast<TH2D *>(gROOT ->FindObject("h1"));
        h1->Draw("colz");
        h1->FitSlicesY();
        
	TH1D *h1_1 = static_cast<TH1D *>(gROOT ->FindObject("h1_1"));
        TH1D *h1_2 = static_cast<TH1D *>(gROOT ->FindObject("h1_2"));
        TCanvas *c2 = new TCanvas("c2");
        h1_1->Draw();
        TCanvas *c3 = new TCanvas("c3");
        h1_2->Draw();
}
