
#include "/home/ilc/mizunot/bin/root_macros/style.C"


void Ereso03_t2() {

        stringstream filest;
        filest << "../root_merge.mILD_l5_o1_v02/"
               << "2f_z_l.eL.pR.mILD_l5_o1_v02.root" << ends;

        TFile *f = new TFile(filest.str().data());
	setILDStyle();
	//gStyle->SetPadLeftMargin(0.2);

	TCanvas *c1 = new TCanvas("c1");

	//TFile *f = new TFile("2f_z_l.eL.pR.mILD_o1_v05.root");
	
	TNtuple *hGen = f->Get("hGen");
	TNtuple *hAnl = f->Get("hAnl");
	
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


	Double_t cos[10],cose[10],sigma[10],sigmae[10];

	hAnl->Draw("-(lep1EMC-lep1EAnl)/lep1EMC>>h1","pdg0==13 && abs(mzgen-91.2)<10 && lep1EMC > 100 && abs(coslep1) > 0.0 && abs(coslep1) < 0.1");
	h1->SetXTitle("(E^{Rec}_{#mu}-E^{MC})/E^{MC}");
        h1->SetYTitle("Entries");
        h1->Draw();
        h1->Fit("gaus");
	cos[0] = 0.05;
        cose[0] = 0.0;
        sigma[0] = gaus->GetParameter(2);//get sigma
        sigmae[0] = gaus->GetParError(2);


	TCanvas *c2 = new TCanvas("c2");
	hAnl->Draw("-(lep1EMC-lep1EAnl)/lep1EMC>>h2","pdg0==13 && abs(mzgen-91.2)<10 && lep1EMC > 100 && abs(coslep1) > 0.1 && abs(coslep1) < 0.2");
        h2->SetXTitle("(E^{Rec}_{#mu}-E^{MC})/E^{MC}");
        h2->SetYTitle("Entries");
        h2->Draw(); 
        h2->Fit("gaus");
        cos[1] = 0.15;
        cose[1] = 0.0;
        sigma[1] = gaus->GetParameter(2);//get sigma
        sigmae[1] = gaus->GetParError(2);


	TCanvas *c3 = new TCanvas("c3");
	hAnl->Draw("-(lep1EMC-lep1EAnl)/lep1EMC>>h3","pdg0==13 && abs(mzgen-91.2)<10 && lep1EMC > 100 && abs(coslep1) > 0.2 && abs(coslep1) < 0.3");
        h3->SetXTitle("(E^{Rec}_{#mu}-E^{MC})/E^{MC}");
        h3->SetYTitle("Entries");
        h3->Draw(); 
        h3->Fit("gaus");
        cos[2] = 0.25;
        cose[2] = 0.0;
        sigma[2] = gaus->GetParameter(2);//get sigma
        sigmae[2] = gaus->GetParError(2);


	TCanvas *c4 = new TCanvas("c4");
	hAnl->Draw("-(lep1EMC-lep1EAnl)/lep1EMC>>h4","pdg0==13 && abs(mzgen-91.2)<10 && lep1EMC > 100 && abs(coslep1) > 0.3 && abs(coslep1) < 0.4");
        h4->SetXTitle("(E^{Rec}_{#mu}-E^{MC})/E^{MC}");
        h4->SetYTitle("Entries");
        h4->Draw(); 
        h4->Fit("gaus");
        cos[3] = 0.35;
        cose[3] = 0.0;
        sigma[3] = gaus->GetParameter(2);//get sigma
        sigmae[3] = gaus->GetParError(2);


	TCanvas *c5 = new TCanvas("c5");
	hAnl->Draw("-(lep1EMC-lep1EAnl)/lep1EMC>>h5","pdg0==13 && abs(mzgen-91.2)<10 && lep1EMC > 100 && abs(coslep1) > 0.4 && abs(coslep1) < 0.5");
        h5->SetXTitle("(E^{Rec}_{#mu}-E^{MC})/E^{MC}");
        h5->SetYTitle("Entries");
        h5->Draw(); 
        h5->Fit("gaus");
        cos[4] = 0.45;
        cose[4] = 0.0;
        sigma[4] = gaus->GetParameter(2);//get sigma
        sigmae[4] = gaus->GetParError(2);


	TCanvas *c6 = new TCanvas("c6");
	hAnl->Draw("-(lep1EMC-lep1EAnl)/lep1EMC>>h6","pdg0==13 && abs(mzgen-91.2)<10 && lep1EMC > 100 && abs(coslep1) > 0.5 && abs(coslep1) < 0.6");
        h6->SetXTitle("(E^{Rec}_{#mu}-E^{MC})/E^{MC}");
        h6->SetYTitle("Entries");
        h6->Draw(); 
        h6->Fit("gaus");
        cos[5] = 0.55;
        cose[5] = 0.0;
        sigma[5] = gaus->GetParameter(2);//get sigma
        sigmae[5] = gaus->GetParError(2);


	TCanvas *c7 = new TCanvas("c7");
	hAnl->Draw("-(lep1EMC-lep1EAnl)/lep1EMC>>h7","pdg0==13 && abs(mzgen-91.2)<10 && lep1EMC > 100 && abs(coslep1) > 0.6 && abs(coslep1) < 0.7");
        h7->SetXTitle("(E^{Rec}_{#mu}-E^{MC})/E^{MC}");
        h7->SetYTitle("Entries");
        h7->Draw(); 
        h7->Fit("gaus");
        cos[6] = 0.65;
        cose[6] = 0.0;
        sigma[6] = gaus->GetParameter(2);//get sigma
        sigmae[6] = gaus->GetParError(2);


	TCanvas *c8 = new TCanvas("c8");
	hAnl->Draw("-(lep1EMC-lep1EAnl)/lep1EMC>>h8","pdg0==13 && abs(mzgen-91.2)<10 && lep1EMC > 100 && abs(coslep1) > 0.7 && abs(coslep1) < 0.8");
        h8->SetXTitle("(E^{Rec}_{#mu}-E^{MC})/E^{MC}");
        h8->SetYTitle("Entries");
        h8->Draw(); 
        h8->Fit("gaus");
        cos[7] = 0.75;
        cose[7] = 0.0;
        sigma[7] = gaus->GetParameter(2);//get sigma
        sigmae[7] = gaus->GetParError(2);


	TCanvas *c9 = new TCanvas("c9");
	hAnl->Draw("-(lep1EMC-lep1EAnl)/lep1EMC>>h9","pdg0==13 && abs(mzgen-91.2)<10 && lep1EMC > 100 && abs(coslep1) > 0.8 && abs(coslep1) < 0.9");
        h9->SetXTitle("(E^{Rec}_{#mu}-E^{MC})/E^{MC}");
        h9->SetYTitle("Entries");
        h9->Draw(); 
        h9->Fit("gaus");
        cos[8] = 0.85;
        cose[8] = 0.0;
        sigma[8] = gaus->GetParameter(2);//get sigma
        sigmae[8] = gaus->GetParError(2);


	TCanvas *c10 = new TCanvas("c10");
	hAnl->Draw("-(lep1EMC-lep1EAnl)/lep1EMC>>h10","pdg0==13 && abs(mzgen-91.2)<10 && lep1EMC > 100 && abs(coslep1) > 0.9 && abs(coslep1) < 1.0");
        h10->SetXTitle("(E^{Rec}_{#mu}-E^{MC})/E^{MC}");
        h10->SetYTitle("Entries");
        h10->Draw(); 
        h10->Fit("gaus");
        cos[9] = 0.95;
        cose[9] = 0.0;
        sigma[9] = gaus->GetParameter(2);//get sigma
        sigmae[9] = gaus->GetParError(2);


        TCanvas *c11 = new TCanvas("c11");
        TGraphErrors *g1 = new TGraphErrors(10,cos,sigma,cose,sigmae);
        g1->SetMaximum(0.015);
        g1->SetMinimum(0.0);
        g1->GetXaxis()->SetLimits(0.,1.);
        g1->SetTitle(" ;abs(cos(#mu-));Sigma");        
	g1->Draw("AP");


       
}
