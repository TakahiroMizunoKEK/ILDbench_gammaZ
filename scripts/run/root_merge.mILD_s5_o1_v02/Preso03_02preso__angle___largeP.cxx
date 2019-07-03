
#include "/home/ilc/mizunot/bin/root_macros/style.C"


void Preso03_02preso__angle___largeP() {

        stringstream filest;
        filest << "../root_merge.mILD_s5_o1_v02/"
               << "2f_z_l.eL.pR.mILD_s5_o1_v02.root" << ends;

        TFile *f = new TFile(filest.str().data());
	setILDStyle();
	//gStyle->SetPadLeftMargin(0.2);

	TCanvas *c1 = new TCanvas("c1");

	//TFile *f = new TFile("2f_z_l.eL.pR.mILD_o1_v05.root");
	
        TNtuple *hGen = static_cast<TNtuple *>(f->Get("hGen"));
        TNtuple *hAnl = static_cast<TNtuple *>(f->Get("hAnl"));
	
	Int_t nbinx=10;	
	Double_t xmin = -1.; 
	Double_t xmax = 1.; 	

	Int_t nbiny=100;	
	Double_t ymin = -0.05; 
	Double_t ymax = 0.05; 	

	TH1D *h1 = new TH1D("h1","",nbiny,ymin,ymax);
	TH1D *h2 = new TH1D("h2","",nbiny,ymin,ymax);
	TH1D *h3 = new TH1D("h3","",nbiny,ymin,ymax);
	TH1D *h4 = new TH1D("h4","",nbiny,ymin,ymax);
	TH1D *h5 = new TH1D("h5","",nbiny,ymin,ymax);
	TH1D *h6 = new TH1D("h6","",nbiny,ymin,ymax);
	TH1D *h7 = new TH1D("h7","",nbiny,ymin,ymax);
	TH1D *h8 = new TH1D("h8","",nbiny,ymin,ymax);
	TH1D *h9 = new TH1D("h9","",nbiny,ymin,ymax);
	TH1D *h10 = new TH1D("h10","",nbiny,ymin,ymax);
	TH1D *h11 = new TH1D("h11","",nbiny,ymin,ymax);
	TH1D *h12 = new TH1D("h12","",nbiny,ymin,ymax);

        TF1 *gaus0 = new TF1( "gaus0", "gaus");
        TF1 *gaus1 = new TF1( "gaus1", "gaus");
        TF1 *gaus2 = new TF1( "gaus2", "gaus");
        TF1 *gaus3 = new TF1( "gaus3", "gaus");
        TF1 *gaus4 = new TF1( "gaus4", "gaus");
        TF1 *gaus5 = new TF1( "gaus5", "gaus");
        TF1 *gaus6 = new TF1( "gaus6", "gaus");
        TF1 *gaus7 = new TF1( "gaus7", "gaus");
        TF1 *gaus8 = new TF1( "gaus8", "gaus");
        TF1 *gaus9 = new TF1( "gaus9", "gaus");
        TF1 *gaus10 = new TF1( "gaus10", "gaus");
        TF1 *gaus11 = new TF1( "gaus11", "gaus");
        TF1 *gaus12 = new TF1( "gaus12", "gaus");

	Double_t cos[12],cose[12],sigma[12],sigmae[12];

	hAnl->Draw("-(lep1PMC-lep1PAnl)/lep1PMC>>h1","pdg0==13 && abs(mzgen-91.2)<10 && lep1PMC > 100 && abs(coslep1) > 0.0 && abs(coslep1) < 0.1");
	h1->SetXTitle("(P^{Rec}_{#mu}-P^{MC})/P^{MC}");
        h1->SetYTitle("Entries");
        h1->Draw();
        h1->Fit("gaus0");
	cos[0] = 0.05;
        cose[0] = 0.0;
        sigma[0] = gaus0->GetParameter(2);//get sigma
        sigmae[0] = gaus0->GetParError(2);


	TCanvas *c2 = new TCanvas("c2");
	hAnl->Draw("-(lep1PMC-lep1EAnl)/lep1PMC>>h2","pdg0==13 && abs(mzgen-91.2)<10 && lep1PMC > 100 && abs(coslep1) > 0.1 && abs(coslep1) < 0.2");
        h2->SetXTitle("(P^{Rec}_{#mu}-P^{MC})/P^{MC}");
        h2->SetYTitle("Entries");
        h2->Draw(); 
        h2->Fit("gaus1");
        cos[1] = 0.15;
        cose[1] = 0.0;
        sigma[1] = gaus1->GetParameter(2);//get sigma
        sigmae[1] = gaus1->GetParError(2);


	TCanvas *c3 = new TCanvas("c3");
	hAnl->Draw("-(lep1PMC-lep1PAnl)/lep1PMC>>h3","pdg0==13 && abs(mzgen-91.2)<10 && lep1PMC > 100 && abs(coslep1) > 0.2 && abs(coslep1) < 0.3");
        h3->SetXTitle("(P^{Rec}_{#mu}-P^{MC})/P^{MC}");
        h3->SetYTitle("Entries");
        h3->Draw(); 
        h3->Fit("gaus2");
        cos[2] = 0.25;
        cose[2] = 0.0;
        sigma[2] = gaus2->GetParameter(2);//get sigma
        sigmae[2] = gaus2->GetParError(2);


	TCanvas *c4 = new TCanvas("c4");
	hAnl->Draw("-(lep1PMC-lep1PAnl)/lep1PMC>>h4","pdg0==13 && abs(mzgen-91.2)<10 && lep1PMC > 100 && abs(coslep1) > 0.3 && abs(coslep1) < 0.4");
        h4->SetXTitle("(P^{Rec}_{#mu}-P^{MC})/P^{MC}");
        h4->SetYTitle("Entries");
        h4->Draw(); 
        h4->Fit("gaus3");
        cos[3] = 0.35;
        cose[3] = 0.0;
        sigma[3] = gaus3->GetParameter(2);//get sigma
        sigmae[3] = gaus3->GetParError(2);


	TCanvas *c5 = new TCanvas("c5");
	hAnl->Draw("-(lep1PMC-lep1PAnl)/lep1PMC>>h5","pdg0==13 && abs(mzgen-91.2)<10 && lep1PMC > 100 && abs(coslep1) > 0.4 && abs(coslep1) < 0.5");
        h5->SetXTitle("(P^{Rec}_{#mu}-P^{MC})/P^{MC}");
        h5->SetYTitle("Entries");
        h5->Draw(); 
        h5->Fit("gaus4");
        cos[4] = 0.45;
        cose[4] = 0.0;
        sigma[4] = gaus4->GetParameter(2);//get sigma
        sigmae[4] = gaus4->GetParError(2);


	TCanvas *c6 = new TCanvas("c6");
	hAnl->Draw("-(lep1PMC-lep1PAnl)/lep1PMC>>h6","pdg0==13 && abs(mzgen-91.2)<10 && lep1PMC > 100 && abs(coslep1) > 0.5 && abs(coslep1) < 0.6");
        h6->SetXTitle("(P^{Rec}_{#mu}-P^{MC})/P^{MC}");
        h6->SetYTitle("Entries");
        h6->Draw(); 
        h6->Fit("gaus5");
        cos[5] = 0.55;
        cose[5] = 0.0;
        sigma[5] = gaus5->GetParameter(2);//get sigma
        sigmae[5] = gaus5->GetParError(2);


	TCanvas *c7 = new TCanvas("c7");
	hAnl->Draw("-(lep1PMC-lep1PAnl)/lep1PMC>>h7","pdg0==13 && abs(mzgen-91.2)<10 && lep1PMC > 100 && abs(coslep1) > 0.6 && abs(coslep1) < 0.7");
        h7->SetXTitle("(P^{Rec}_{#mu}-P^{MC})/P^{MC}");
        h7->SetYTitle("Entries");
        h7->Draw(); 
        h7->Fit("gaus6");
        cos[6] = 0.65;
        cose[6] = 0.0;
        sigma[6] = gaus6->GetParameter(2);//get sigma
        sigmae[6] = gaus6->GetParError(2);


	TCanvas *c8 = new TCanvas("c8");
	hAnl->Draw("-(lep1PMC-lep1PAnl)/lep1PMC>>h8","pdg0==13 && abs(mzgen-91.2)<10 && lep1PMC > 100 && abs(coslep1) > 0.7 && abs(coslep1) < 0.8");
        h8->SetXTitle("(P^{Rec}_{#mu}-P^{MC})/P^{MC}");
        h8->SetYTitle("Entries");
        h8->Draw(); 
        h8->Fit("gaus7");
        cos[7] = 0.75;
        cose[7] = 0.0;
        sigma[7] = gaus7->GetParameter(2);//get sigma
        sigmae[7] = gaus7->GetParError(2);


	TCanvas *c9 = new TCanvas("c9");
	hAnl->Draw("-(lep1PMC-lep1PAnl)/lep1PMC>>h9","pdg0==13 && abs(mzgen-91.2)<10 && lep1PMC > 100 && abs(coslep1) > 0.8 && abs(coslep1) < 0.85");
        h9->SetXTitle("(P^{Rec}_{#mu}-P^{MC})/P^{MC}");
        h9->SetYTitle("Entries");
        h9->Draw(); 
        h9->Fit("gaus8");
        cos[8] = 0.825;
        cose[8] = 0.0;
        sigma[8] = gaus8->GetParameter(2);//get sigma
        sigmae[8] = gaus8->GetParError(2);


	TCanvas *c10 = new TCanvas("c10");
	hAnl->Draw("-(lep1PMC-lep1PAnl)/lep1PMC>>h10","pdg0==13 && abs(mzgen-91.2)<10 && lep1PMC > 100 && abs(coslep1) > 0.85 && abs(coslep1) < 0.9");
        h10->SetXTitle("(P^{Rec}_{#mu}-P^{MC})/P^{MC}");
        h10->SetYTitle("Entries");
        h10->Draw(); 
        h10->Fit("gaus9");
        cos[9] = 0.875;
        cose[9] = 0.0;
        sigma[9] = gaus9->GetParameter(2);//get sigma
        sigmae[9] = gaus9->GetParError(2);

        TCanvas *c11 = new TCanvas("c11");
        hAnl->Draw("-(lep1PMC-lep1PAnl)/lep1PMC>>h11","pdg0==13 && abs(mzgen-91.2)<10 && lep1PMC > 100 && abs(coslep1) > 0.9 && abs(coslep1) < 0.95");
        h11->SetXTitle("(P^{Rec}_{#mu}-P^{MC})/P^{MC}");
        h11->SetYTitle("Entries");
        h11->Draw();
        h11->Fit("gaus10");
        cos[10] = 0.925;
        cose[10] = 0.0;
        sigma[10] = gaus10->GetParameter(2);//get sigma
        sigmae[10] = gaus10->GetParError(2);

        TCanvas *c12 = new TCanvas("c12");
        hAnl->Draw("-(lep1PMC-lep1PAnl)/lep1PMC>>h12","pdg0==13 && abs(mzgen-91.2)<10 && lep1PMC > 100 && abs(coslep1) > 0.95 && abs(coslep1) < 1.0");
        h12->SetXTitle("(P^{Rec}_{#mu}-P^{MC})/P^{MC}");
        h12->SetYTitle("Entries");
        h12->Draw();
        h12->Fit("gaus11");
        cos[11] = 0.975;
        cose[11] = 0.0;
        sigma[11] = gaus11->GetParameter(2);//get sigma
        sigmae[11] = gaus11->GetParError(2);

        TCanvas *c13 = new TCanvas("c13");
        TGraphErrors *g1 = new TGraphErrors(12,cos,sigma,cose,sigmae);
        g1->SetMaximum(0.020);
        g1->SetMinimum(0.0);
        g1->GetXaxis()->SetLimits(0.,1.);
        g1->SetTitle(" ;abs(cos(#mu-));Sigma");        
	g1->Draw("AP");


       
}
