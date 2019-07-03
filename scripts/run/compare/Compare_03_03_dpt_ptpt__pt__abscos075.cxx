
#include "/home/ilc/mizunot/bin/root_macros/style.C"


//void getGraph(TFile *f, TGraphErrors *g) {
TGraphErrors *getGraph(TFile *f) {


  //	TString name;
  //	name.Form("L5dist_07_06plus.pdf");
	TCanvas *c1 = new TCanvas("c1");

	//TFile *f = new TFile("2f_z_l.eL.pR.mILD_o1_v05.root");
	
        TNtuple *hGen = static_cast<TNtuple *>(f->Get("hGen"));
        TNtuple *hAnl = static_cast<TNtuple *>(f->Get("hAnl"));
	
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


	hAnl->Draw("-(lep1PMC*sinlep1mc-lep1PAnl*sinlep1)/lep1PMC/lep1PMC/sinlep1mc/sinlep1mc:lep1PMC*sinlep1mc>>h1","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.20");

	h1->SetYTitle("(P_t^{Rec}_{#mu}-P^_t{MC})/(P_t^{MC})^{2}");
	h1->SetXTitle("P_t^{MC}");
       
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
	hAnl->Draw("-(lep1PMC*sinlep1mc-lep1PAnl*sinlep1)/lep1PMC/lep1PMC/sinlep1mc/sinlep1mc>>h2","pdg0==13 && abs(mzgen-91.2)<10 && lep1PMC*sinlep1mc>0 && lep1PMC*sinlep1mc<50 && abs(coslep1)>0.0 && abs(coslep1)<0.75");
	h2->SetXTitle("(P_t^{Rec}_{#mu}-P_t^{MC})/(P_t^{MC})^{2}");
	h2->SetYTitle("Entries/bin");
	h2->Fit("gaus0");
	h2->GetFunction("gaus0")->SetLineColor(kGreen+2);
	gaus0->SetLineColor(kGreen+2);

	energy[0] = 25.0;
	energye[0] = 0.0;
	sigma[0] = gaus0->GetParameter(2);//get sigma
	sigmae[0] = gaus0->GetParError(2);


        TCanvas *c3 = new TCanvas("c3");
	hAnl->Draw("-(lep1PMC*sinlep1mc-lep1PAnl*sinlep1)/lep1PMC/lep1PMC/sinlep1mc/sinlep1mc>>h3","pdg0==13 && abs(mzgen-91.2)<10 && lep1PMC*sinlep1mc>50 && lep1PMC*sinlep1mc<100 && abs(coslep1)>0.0 && abs(coslep1)<0.75");
	h3->SetXTitle("(P_t^{Rec}_{#mu}-P_t^{MC})/(P_t^{MC})^{2}");
	h3->SetYTitle("Entries/bin");
	h3->Fit("gaus1");

	energy[1] = 75.0;
	energye[1] = 0.0;
	sigma[1] = gaus1->GetParameter(2);//get sigma
	sigmae[1] = gaus1->GetParError(2);

        
	TCanvas *c4 = new TCanvas("c4");
	hAnl->Draw("-(lep1PMC*sinlep1mc-lep1PAnl*sinlep1)/lep1PMC/lep1PMC/sinlep1mc/sinlep1mc>>h4","pdg0==13 && abs(mzgen-91.2)<10 && lep1PMC*sinlep1mc>100 && lep1PMC*sinlep1mc<150 && abs(coslep1)>0.0 && abs(coslep1)<0.75");
	h4->SetXTitle("(P_t^{Rec}_{#mu}-P_t^{MC})/(P_t^{MC})^{2}");
	h4->SetYTitle("Entries/bin");
	h4->Fit("gaus2");

	energy[2] = 125.0;
	energye[2] = 0.0;
	sigma[2] = gaus2->GetParameter(2);//get sigma
	sigmae[2] = gaus2->GetParError(2);

        
	TCanvas *c5 = new TCanvas("c5");
	hAnl->Draw("-(lep1PMC*sinlep1mc-lep1PAnl*sinlep1)/lep1PMC/lep1PMC/sinlep1mc/sinlep1mc>>h5","pdg0==13 && abs(mzgen-91.2)<10 && lep1PMC*sinlep1mc>150 && lep1PMC*sinlep1mc<200 && abs(coslep1)>0.0 && abs(coslep1)<0.75");
	h5->SetXTitle("(P_t^{Rec}_{#mu}-P_t^{MC})/(P_t^{MC})^{2}");
	h5->SetYTitle("Entries/bin");
	h5->Fit("gaus3");

	energy[3] = 175.0;
	energye[3] = 0.0;
	sigma[3] = gaus3->GetParameter(2);//get sigma
	sigmae[3] = gaus3->GetParError(2);

        
	TCanvas *c6 = new TCanvas("c6");
	hAnl->Draw("-(lep1PMC*sinlep1mc-lep1PAnl*sinlep1)/lep1PMC/lep1PMC/sinlep1mc/sinlep1mc>>h6","pdg0==13 && abs(mzgen-91.2)<10 && lep1PMC*sinlep1mc>200 && lep1PMC*sinlep1mc<250 && abs(coslep1)>0.0 && abs(coslep1)<0.75");
	h6->SetXTitle("(P_t^{Rec}_{#mu}-P_t^{MC})/(P_t^{MC})^{2}");
	h6->SetYTitle("Entries/bin");
	h6->Fit("gaus4","","",-0.0002,0.0002);

	energy[4] = 225.0;
	energye[4] = 0.0;
	sigma[4] = gaus4->GetParameter(2);//get sigma
	sigmae[4] = gaus4->GetParError(2);


	TCanvas *c7 = new TCanvas("c7");
	//        c7->Print(name + "[","pdf");
	TGraphErrors *g1 = new TGraphErrors(5,energy,sigma,energye,sigmae);
	//	g1 = new TGraphErrors(5,energy,sigma,energye,sigmae);	
	//	g->SetMaximum(0.00015);
	//	g->SetMinimum(0.0);
	//	g->GetXaxis()->SetLimits(0.,250.);
	//	g->SetTitle("Sigma;E^{MC}; ");
	//	g->Draw("AP");
	//	c7->Print(name,"pdf");
	//        c7->Print(name + "]","pdf");
	return g1;


}

void Compare_03_03_dpt_ptpt__pt__abscos075() {

  stringstream filest1,filest2;
  filest1 << "../root_merge.mILD_l5_o1_v02/"
	  << "2f_z_l.eL.pR.mILD_l5_o1_v02.root" << ends;
  filest2 << "../root_merge.mILD_s5_o1_v02/"
	  << "2f_z_l.eL.pR.mILD_s5_o1_v02.root" << ends;

  TFile *f1 = new TFile(filest1.str().data());
  TFile *f2 = new TFile(filest2.str().data());
  //  TGraphErrors *g1,*g2;
  //  getGraph(f1,g1);
  //  getGraph(f2,g2);
  TGraphErrors *g1 = getGraph(f1);
  TGraphErrors *g2 = getGraph(f2);
	
  setILDStyle();
  gStyle->SetPadRightMargin(1.0);
  gStyle->SetOptFit(111);

  g1->SetLineColor(kBlue);
  g2->SetLineColor(kRed);
  
  TCanvas *c = new TCanvas("c");
  g1->SetMaximum(0.00008);
  g1->SetMinimum(0.0);
  g1->GetXaxis()->SetLimits(0.,250.);
  g1->SetTitle("Sigma;P_t^{MC}; ");
  g1->Draw("AP");
  g2->Draw("P same");


}
