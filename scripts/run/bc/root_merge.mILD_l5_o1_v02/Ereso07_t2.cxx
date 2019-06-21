
#include "/home/ilc/mizunot/bin/root_macros/style.C"


void Ereso07_t2() {

        stringstream filest;
        filest << "../root_merge.mILD_l5_o1_v02/"
               << "2f_z_l.eL.pR.mILD_l5_o1_v02.root" << ends;

        TFile *f = new TFile(filest.str().data());
	
	setILDStyle();
	gStyle->SetPadRightMargin(1.0);
	gStyle->SetOptFit(111);

	TString name;
	name.Form("L5dist_07_02plus.pdf");
	TCanvas *c1 = new TCanvas("c1");

	//TFile *f = new TFile("2f_z_l.eL.pR.mILD_o1_v05.root");
	
	TNtuple *hGen = f->Get("hGen");
	TNtuple *hAnl = f->Get("hAnl");
	
	Int_t nbinx=25;	
	Double_t xmin = 0.; 
	Double_t xmax = 250.; 	

	Int_t nbiny=200;	
	Double_t ymin = -0.0005; 
	Double_t ymax = 0.0005; 	

	TH2D *h1 = new TH2D("h1","",nbinx,xmin,xmax,nbiny,ymin,ymax);
	TH1D *h2 = new TH1D("h2","",nbiny,ymin,ymax);
	TH1D *h3 = new TH1D("h3","",nbiny,ymin,ymax);
	TH1D *h4 = new TH1D("h4","",nbiny,ymin,ymax);
	TH1D *h5 = new TH1D("h5","",nbiny,ymin,ymax);
	TH1D *h6 = new TH1D("h6","",nbiny,ymin,ymax);
	//TH1D *h7 = new TH1D("h7","",nbinx,xmin,xmax,nbiny,ymin,ymax);
	//TH1D *h8 = new TH1D("h8","",nbinx,xmin,xmax,nbiny,ymin,ymax);

	hAnl->Draw("-(lep1EMC-lep1EAnl)/lep1EMC/lep1EMC:lep1EMC>>h1","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.6 && abs(coslep1)<0.8");

	h1->SetYTitle("(E^{Rec}_{#mu}-E^{MC})/(E^{MC})^{2}");
	h1->SetXTitle("E^{MC}");
       
	//TH2D *h1 = static_cast<TH2D *>(gROOT ->FindObject("h1"));
        h1->Draw("colz");
        /*h1->FitSlicesY();
        
	TH1D *h1_1 = static_cast<TH1D *>(gROOT ->FindObject("h1_1"));
        TH1D *h1_2 = static_cast<TH1D *>(gROOT ->FindObject("h1_2"));
        TCanvas *c2 = new TCanvas("c2");
        h1_1->Draw();
        TCanvas *c3 = new TCanvas("c3");
        h1_2->Draw();*/


	Double_t energy[5],energye[5],sigma[5],sigmae[5];

        TCanvas *c2 = new TCanvas("c2");
	hAnl->Draw("-(lep1EMC-lep1EAnl)/lep1EMC/lep1EMC>>h2","pdg0==13 && abs(mzgen-91.2)<10 && lep1EMC>0 && lep1EMC<50 && abs(coslep1)>0.6 && abs(coslep1)<0.8");
	h2->SetXTitle("(E^{Rec}_{#mu}-E^{MC})/(E^{MC})^{2}");
	h2->SetYTitle("Entries/bin");
	h2->Fit("gaus");
	h2->GetFunction("gaus")->SetLineColor(kGreen+2);
	gaus->SetLineColor(kGreen+2);

	energy[0] = 25.0;
	energye[0] = 0.0;
	sigma[0] = gaus->GetParameter(2);//get sigma
	sigmae[0] = gaus->GetParError(2);


        TCanvas *c3 = new TCanvas("c3");
	hAnl->Draw("-(lep1EMC-lep1EAnl)/lep1EMC/lep1EMC>>h3","pdg0==13 && abs(mzgen-91.2)<10 && lep1EMC>50 && lep1EMC<100 && abs(coslep1)>0.6 && abs(coslep1)<0.8");
	h3->SetXTitle("(E^{Rec}_{#mu}-E^{MC})/(E^{MC})^{2}");
	h3->SetYTitle("Entries/bin");
	h3->Fit("gaus");

	energy[1] = 75.0;
	energye[1] = 0.0;
	sigma[1] = gaus->GetParameter(2);//get sigma
	sigmae[1] = gaus->GetParError(2);

        
	TCanvas *c4 = new TCanvas("c4");
	hAnl->Draw("-(lep1EMC-lep1EAnl)/lep1EMC/lep1EMC>>h4","pdg0==13 && abs(mzgen-91.2)<10 && lep1EMC>100 && lep1EMC<150 && abs(coslep1)>0.6 && abs(coslep1)<0.8");
	h4->SetXTitle("(E^{Rec}_{#mu}-E^{MC})/(E^{MC})^{2}");
	h4->SetYTitle("Entries/bin");
	h4->Fit("gaus");

	energy[2] = 125.0;
	energye[2] = 0.0;
	sigma[2] = gaus->GetParameter(2);//get sigma
	sigmae[2] = gaus->GetParError(2);

        
	TCanvas *c5 = new TCanvas("c5");
	hAnl->Draw("-(lep1EMC-lep1EAnl)/lep1EMC/lep1EMC>>h5","pdg0==13 && abs(mzgen-91.2)<10 && lep1EMC>150 && lep1EMC<200 && abs(coslep1)>0.6 && abs(coslep1)<0.8");
	h5->SetXTitle("(E^{Rec}_{#mu}-E^{MC})/(E^{MC})^{2}");
	h5->SetYTitle("Entries/bin");
	h5->Fit("gaus");

	energy[3] = 175.0;
	energye[3] = 0.0;
	sigma[3] = gaus->GetParameter(2);//get sigma
	sigmae[3] = gaus->GetParError(2);

        
	TCanvas *c6 = new TCanvas("c6");
	hAnl->Draw("-(lep1EMC-lep1EAnl)/lep1EMC/lep1EMC>>h6","pdg0==13 && abs(mzgen-91.2)<10 && lep1EMC>200 && lep1EMC<250 && abs(coslep1)>0.6 && abs(coslep1)<0.8");
	h6->SetXTitle("(E^{Rec}_{#mu}-E^{MC})/(E^{MC})^{2}");
	h6->SetYTitle("Entries/bin");
	h6->Fit("gaus");

	energy[4] = 225.0;
	energye[4] = 0.0;
	sigma[4] = gaus->GetParameter(2);//get sigma
	sigmae[4] = gaus->GetParError(2);


	TCanvas *c7 = new TCanvas("c7");
        c7->Print(name + "[","pdf");
	TGraphErrors *g1 = new TGraphErrors(5,energy,sigma,energye,sigmae);
	g1->SetMaximum(0.00015);
	g1->SetMinimum(0.0);
	g1->GetXaxis()->SetLimits(0.,250.);
	g1->SetTitle("Sigma;E^{MC}; ");
	g1->Draw("AP");
	c7->Print(name,"pdf");
        c7->Print(name + "]","pdf");



}
