{

	TCanvas *c1 = new TCanvas("c1");

	TFile *f = new TFile("2f_z_l.eL.pR.mILD_l5_o1_v02.root");
	
	TNtuple *hGen = f->Get("hGen");
	TNtuple *hAnl = f->Get("hAnl");
	
	Int_t nbin=200;
	Double_t xmin = -1.0; 
	Double_t xmax = 1.0; 	

	TH1D *h1 = new TH1D("h1","",nbin,xmin,xmax);
	TH1D *h2 = new TH1D("h2","",nbin,xmin,xmax);

	hGen->Draw("coslep1>>h1","pdg0==13 && mz>400");
	gStyle->SetStatX(0.6);
        gStyle->SetStatY(0.9);

	TCanvas *c2 = new TCanvas("c2");
	hAnl->Draw("coslep1mc>>h2","pdg0==13 && mzgen>400");
	h2->Divide(h1);
	h2->Draw();
	h2->SetStats(0);

}
