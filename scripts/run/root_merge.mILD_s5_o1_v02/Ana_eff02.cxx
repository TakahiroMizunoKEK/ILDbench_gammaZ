{

	TCanvas *c1 = new TCanvas("c1");

	TFile *f = new TFile("2f_z_l.eL.pR.mILD_s5_o1_v02.root");
	
	TNtuple *hGen = f->Get("hGen");
	TNtuple *hAnl = f->Get("hAnl");
	
	Int_t nbin=100;
	Double_t xmin = -1.0; 
	Double_t xmax = 1.0; 	

	TH1D *h1 = new TH1D("h1","",nbin,xmin,xmax);
	TH1D *h2 = new TH1D("h2","",nbin,xmin,xmax);
        TH1D *h3 = new TH1D("h3","",nbin,xmin,xmax);
        TH2D *h4 = new TH2D("h4","",500,xmin,xmax,500,xmin,xmax);
        TH1D *h5 = new TH1D("h5","",nbin,xmin,xmax);

	h1->SetFillColor(kTeal);
	hGen->Draw("coslep1>>h1","pdg0==13 && abs(mz-91.2)<10");
	gStyle->SetStatX(0.6);
        gStyle->SetStatY(0.9);
	h2->SetFillColor(kViolet);
	hAnl->Draw("coslep1mc>>h2","pdg0==13 && abs(mzgen-91.2)<10","sames");
	h2->Draw("sames");

        //h1->SetTitle("M(\mu^{+}\mu^{-}) distribution");
        h1->SetXTitle("cos(#mu-)");
        h1->SetYTitle("Entries/bin");
        h1->GetYaxis()->SetTitleOffset(1.5);

        TCanvas *c2 = new TCanvas("c2");
	hAnl->Draw("coslep1mc>>h3","pdg0==13 && abs(mzgen-91.2)<10");
	h3->Divide(h1);
	h3->SetLineColor(kRed);
	h3->Draw();
	h3->SetStats(0);
	h3->GetYaxis()->SetRangeUser(0,1.1);

        //h3->SetTitle("M(\mu^{+}\mu^{-}) distribution");
        h3->SetXTitle("cos(#mu-)");
        h3->SetYTitle("Efficiency");
	h3->GetYaxis()->SetTitleOffset(1);

        TCanvas *c3 = new TCanvas("c3");
	hAnl->Draw("coslep2mc:coslep1mc>>h4","pdg0==13 && abs(mzgen-91.2)<10");
	h4->Draw("colz");
	h4->SetXTitle("cos(#mu-)");
        h4->SetYTitle("cos(#mu+)");

        TCanvas *c4 = new TCanvas("c4");
        hAnl->Draw("coslep1mc>>h5","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep2mc)<0.2");
        h5->SetXTitle("cos(#mu-)");
        h5->SetYTitle("Entries");
	h5->SetFillColor(kSpring);
	

}
