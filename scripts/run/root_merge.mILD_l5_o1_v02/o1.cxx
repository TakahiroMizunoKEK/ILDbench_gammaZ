
#include "/home/ilc/mizunot/bin/root_macros/style.C"
#include "photonERec6.cxx"
#include "photonERec63.cxx"

void GammaCalib05_06photonP() {

        stringstream filest;
        filest << "../root_merge.mILD_l5_o1_v02/"
               << "2f_z_l.eL.pR.mILD_l5_o1_v02.root" << ends;

        TFile *f = new TFile(filest.str().data());
	
	setILDStyle();
	//gStyle->SetPadRightMargin(1.0);
	//gStyle->SetPadRightMargin(1.0);
	gStyle->SetOptStat(1000001110);
        gStyle->SetStatH(0.15);
        gStyle->SetStatW(0.1);
        gStyle->SetStatX(0.9);
        gStyle->SetStatY(0.9);
	gStyle->SetOptFit();

        TNtuple *hGen = static_cast<TNtuple *>(f->Get("hGen"));
        TNtuple *hAnl = static_cast<TNtuple *>(f->Get("hAnl"));
	
	double Ecm = 500.;

	Int_t nbinx   = 520;	
	Double_t xmin = -10.; 
	Double_t xmax = 510.; 	

	Int_t nbiny   = 520;	
	Double_t ymin = -10.; 
	Double_t ymax = 510.; 	

	TH1D *h1 = new TH1D("h1","",nbinx,xmin,xmax);
	TH1D *h2 = new TH1D("h2","",nbinx,xmin,xmax);
        TH2D *h3 = new TH2D("h3","",nbinx,xmin,xmax,nbiny,ymin,ymax);

	TH1D *h10 = new TH1D("h10","",nbinx,xmin,xmax);
	TH1D *h11 = new TH1D("h11","",nbinx,xmin,xmax);
        TH2D *h12 = new TH2D("h12","",nbinx,xmin,xmax,nbiny,ymin,ymax);

        TH1D *h41 = new TH1D("h41","",200.,-.6,.6);

        TH1D *h31 = new TH1D("h31","",nbinx,xmin,xmax);
        TH1D *h32 = new TH1D("h32","",nbinx,xmin,xmax);
        TH2D *h33 = new TH2D("h33","",nbinx,xmin,xmax,nbiny,ymin,ymax);
        TH1D *h34 = new TH1D("h34","",200.,-.6,.6);

        TH1D *h35 = new TH1D("h35","",nbinx,xmin,xmax);
        TH1D *h36 = new TH1D("h36","",nbinx,xmin,xmax);

        TH2D *h39 = new TH2D("h39","",nbinx,xmin,xmax,nbiny,ymin,ymax);
        TH2D *h47 = new TH2D("h47","",nbinx,100.,270.,nbiny,100.,270.);
        TH2D *h48 = new TH2D("h48","",nbinx,0.,500.,nbiny,0.,500.);

        TH1D *h51 = new TH1D("h51","",nbinx,xmin,xmax);
        TH1D *h52 = new TH1D("h52","",nbinx,xmin,xmax);

        TH1D *h61 = new TH1D("h61","",400.,-.2,.2);
        TH1D *h62 = new TH1D("h62","",400.,-.2,.2);
        TH1D *h63 = new TH1D("h63","",400.,-.2,.2);
        TH1D *h64 = new TH1D("h64","",400.,-.2,.2);
        TH1D *h65 = new TH1D("h65","",400.,-.2,.2);
        TH1D *h66 = new TH1D("h66","",400.,-.2,.2);
        TH1D *h67 = new TH1D("h67","",400.,-.2,.2);

        TH1D *h71 = new TH1D("h71","",400.,-.2,.2);
        TH1D *h72 = new TH1D("h72","",400.,-.2,.2);
        TH1D *h73 = new TH1D("h73","",400.,-.2,.2);
        TH1D *h74 = new TH1D("h74","",400.,-.2,.2);
        TH1D *h75 = new TH1D("h75","",400.,-.2,.2);
        TH1D *h76 = new TH1D("h76","",400.,-.2,.2);
        TH1D *h77 = new TH1D("h77","",400.,-.2,.2);



	TCut cut3 = "pdg0==13 && abs(mzgen-91.2)<10";
	TCut cut4 = "coneen > -0.5";
	TCut cut2 = "abs(coslep1)<0.75 && abs(coslep2)<0.75";
        TCut cut1 = cut3+cut4;

	TCut cut31 = "abs(sin(photonphiMC))>0.2";

	TCut cut51 = "abs(cos(photonthetaMC))<0.2";
	TCut cut52 = "abs(cos(photonthetaMC))>=0.2 && abs(cos(photonthetaMC))<0.4";
	TCut cut53 = "abs(cos(photonthetaMC))>=0.4 && abs(cos(photonthetaMC))<0.6";
	TCut cut54 = "abs(cos(photonthetaMC))>=0.6 && abs(cos(photonthetaMC))<0.8";
	TCut cut55 = "abs(cos(photonthetaMC))>=0.8 && abs(cos(photonthetaMC))<0.9";
	TCut cut56 = "abs(cos(photonthetaMC))>=0.9";

	//TCut cut6 = "abs(sin(photonphiMC))>0.5";
	TCut cut6 = "abs(sin(photonphiMC))>0.4 && abs(sin(photonphiMC))<0.8";
	TCut cut62 = "abs(sin(photonphiMC))>0.2";

	TCut cut69 = "abs(cos(photonthetaMC))>=0.2 && abs(cos(photonthetaMC))<0.8";

	TCut cut72 = "abs(cos(photonphiMC))<0.2";
	TCut cut73 = "abs(cos(photonphiMC))>=0.2 && abs(cos(photonphiMC))<0.4";
	TCut cut74 = "abs(cos(photonphiMC))>=0.4 && abs(cos(photonphiMC))<0.6";
	TCut cut75 = "abs(cos(photonphiMC))>=0.6 && abs(cos(photonphiMC))<0.8";
	TCut cut76 = "abs(cos(photonphiMC))>=0.8 && abs(cos(photonphiMC))<0.9";
	TCut cut77 = "abs(cos(photonphiMC))>=0.9";


        TCanvas *c1 = new TCanvas("c1");
        c1->Divide(2,2);
        c1->cd(1);

	hAnl->Draw("photonEAnl>>h1",cut1+cut2);
        h1->Draw("");
        h1->SetTitle("Energy of Photon (Anl)");
        h1->SetXTitle("Energy of Photon (Anl)");

	//TCanvas *c2 = new TCanvas("c2");
	c1->cd(2);

	hAnl->Draw("(photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))>>h2",cut1+cut2);
	h2->Draw("");
        h2->SetTitle("Energy of Photon (Reconstructed)");
        h2->SetXTitle("Energy of Photon (Reconstructed)");

        //TCanvas *c3 = new TCanvas("c3");
	c1->cd(3);
	hAnl->Draw("photonEAnl:photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl)>>h3",cut1+cut2);
        h3->Draw("colz");

        h3->SetTitle("Energy of Photon (Anl:Reconstructed)");
        h3->SetXTitle("Energy of Photon (Reconstructed)");
        h3->SetYTitle("Energy of Photon (Anl)");



        TCanvas *c10 = new TCanvas("c10");
        c10->Divide(2,2);
        c10->cd(1);

	hAnl->Draw("photonEMC>>h10",cut1+cut2);
        h10->Draw("");
        h10->SetTitle("Energy of Photon (MC)");
        h10->SetXTitle("Energy of Photon (MC)");

	c10->cd(2);
	hAnl->Draw("photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl)>>h11",cut1+cut2);
	h11->Draw("");
        h11->SetTitle("Energy of Photon (Reconstructed)");
        h11->SetXTitle("Energy of Photon (Reconstructed)");

	c10->cd(3);
	hAnl->Draw("photonEMC:photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl)>>h12",cut1+cut2);
        h12->Draw("colz");

        h12->SetTitle("Energy of Photon (MC:Reconstructed)");
        h12->SetXTitle("Energy of Photon (Reconstructed)");
        h12->SetYTitle("Energy of Photon (MC)");

        c10->cd(4);
	hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h41",cut1+cut2);
        h41->Draw("");

        h41->SetTitle("Energy Resolution of Photon");
        h41->SetXTitle("Energy Resolution of Photon");
        h41->SetYTitle("");


	TCanvas *c30 = new TCanvas("c30");
        c30->Divide(2,2);
        c30->cd(1);

        //hAnl->Draw("ISRphotonEMC>>h31",cut1+cut2);
        hAnl->Draw("(500.-photonEMC-lep1EMC-lep2EMC)>>h31",cut1+cut2);
        h31->Draw("");
        h31->SetTitle("Energy of ISR Photon (MC)");
        h31->SetXTitle("Energy of ISR Photon (MC)");

        c30->cd(2);
        hAnl->Draw("photonERec63(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl)>>h32",cut1+cut2);
        h32->Draw("");
        h32->SetTitle("Energy of ISR Photon (Reconstructed)");
        h32->SetXTitle("Energy of ISR Photon (Reconstructed)");

        c30->cd(3);
        hAnl->Draw("(500.-photonEMC-lep1EMC-lep2EMC):photonERec63(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl)>>h33",cut1+cut2);
        //hAnl->Draw("ISRphotonEMC:photonERec63(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl)>>h33",cut1+cut2);
        h33->Draw("colz");

        h33->SetTitle("Energy of ISR Photon (MC:Reconstructed)");
        h33->SetXTitle("Energy of ISR Photon (Reconstructed)");
        h33->SetYTitle("Energy of ISR Photon (MC)");

        c30->cd(4);
        hAnl->Draw("(-(500.-photonEMC-lep1EMC-lep2EMC)+photonERec63(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/(500.-photonEMC-lep1EMC-lep2EMC)>>h34",cut1+cut2);
        //hAnl->Draw("(-ISRphotonEMC+photonERec63(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/ISRphotonEMC>>h34",cut1+cut2);
        h34->Draw("");

        h34->SetTitle("Energy Resolution of Photon");
        h34->SetXTitle("Energy Resolution of Photon");
        h34->SetYTitle("");


        TCanvas *c31 = new TCanvas("c31");

        hAnl->Draw("(500.-photonEMC-lep1EMC-lep2EMC)>>h35",cut1+cut2);
        //hAnl->Draw("ISRphotonEMC>>h35",cut1+cut2);
        h35->SetLineColor(kBlue);
        gPad->Update();
        TPaveStats *st35 = (TPaveStats*)h35->GetListOfFunctions()->FindObject("stats");

        hAnl->Draw("photonERec63(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl)>>h36",cut1+cut2);
        h36->SetLineColor(kRed);
        gPad->Update();
        TPaveStats *st36 = (TPaveStats*)h36->GetListOfFunctions()->FindObject("stats");

        st35->SetX1NDC(0.70);
        st35->SetX2NDC(0.90);
        st35->SetY1NDC(0.70);
        st35->SetY2NDC(0.90);
        st35->SetTextColor(kBlue);
        st36->SetX1NDC(0.70);
        st36->SetX2NDC(0.90);
        st36->SetY1NDC(0.50);
        st36->SetY2NDC(0.70);
        st36->SetTextColor(kRed);
        h35->SetTitle("Energy of ISR Photon");
        h35->SetXTitle("Energy of ISR Photon");
        h35->SetYTitle("");
        h35->Draw("");
        h36->Draw("same");

        TCanvas *c39 = new TCanvas("c39");
        hAnl->Draw("photonERec63(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl):(500.-photonEMC-lep1EMC-lep2EMC)>>h39",cut1+cut2+cut31);
        //hAnl->Draw("ISRphotonEMC>>h35",cut1+cut2);
        //        h35->SetLineColor(kBlue);
        //
        h39->Draw("colz");

        TCanvas *c47 = new TCanvas("c47");
        hAnl->Draw("photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl):photonEAnl>>h47",cut1+cut2);
        h47->SetTitle("");
        h47->SetXTitle("PFO Energy of Photon");
        h47->SetYTitle("Reconstructed Energy of Photon");
        h47->Draw("colz");

        TCanvas *c61 = new TCanvas("c61");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h61",cut1);
        h61->SetTitle("Energy Resolution of Photon");
        h61->SetXTitle("Energy Resolution of Photon");
        h61->SetYTitle("");        
	h61->Draw("");
	TF1 *f61 = new TF1("f61","gaus",-.012,.012);
	//f61->SetLineColor(kBlack);
	h61->Fit("f61","","",-.01,.01);
	
	double num61,sig61,se61;
	int numi61 = h61->Integral(h61->GetXaxis()->FindBin(-.01),h61->GetXaxis()->FindBin(.01));
	num61 = numi61;
	cout<<"num61 = "<<num61<<endl;	
	sig61= f61->GetParameter(2);	
	cout<<"sig61 = "<<sig61<<endl;
	se61= sig61/num61;
	cout<<"se61 = "<<se61<<endl;



	double se[6],i[6];

        TCanvas *c62 = new TCanvas("c62");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h62",cut1+cut51+cut6);
        h62->SetTitle("Energy Resolution of Photon");
        h62->SetXTitle("Energy Resolution of Photon");
        h62->SetYTitle("");
        h62->Draw("");
        TF1 *f62 = new TF1("f62","gaus",-.012,.012);
	f62->SetLineColor(kRed);
        h62->Fit("f62","","",-.01,.01);

        double num62,sig62,se62;
	int numi62 = h62->Integral(h62->GetXaxis()->FindBin(-.01),h62->GetXaxis()->FindBin(.01));
        num62 = numi62;
        cout<<"num62 = "<<num62<<endl;
        sig62= f62->GetParameter(2);
        cout<<"sig62 = "<<sig62<<endl;
        se[0]= sig62/sqrt(num62);
        cout<<"se62 = "<<se62<<endl;


        TCanvas *c63 = new TCanvas("c63");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h63",cut1+cut52+cut6);
        h63->SetTitle("Energy Resolution of Photon");
        h63->SetXTitle("Energy Resolution of Photon");
        h63->SetYTitle("");
        h63->Draw("");
        TF1 *f63 = new TF1("f63","gaus",-.012,.012);
	f63->SetLineColor(kOrange);
        h63->Fit("f63","","",-.01,.01);

        double num63,sig63,se63;
	int numi63 = h63->Integral(h63->GetXaxis()->FindBin(-.01),h63->GetXaxis()->FindBin(.01));
        num63 = numi63;
        cout<<"num63 = "<<num63<<endl;
        sig63= f63->GetParameter(2);
        cout<<"sig63 = "<<sig63<<endl;
        se[1]= sig63/sqrt(num63);
        cout<<"se63 = "<<se63<<endl;


        TCanvas *c64 = new TCanvas("c64");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h64",cut1+cut53+cut6);
        h64->SetTitle("Energy Resolution of Photon");
        h64->SetXTitle("Energy Resolution of Photon");
        h64->SetYTitle("");
        h64->Draw("");
        TF1 *f64 = new TF1("f64","gaus",-.012,.012);
	f64->SetLineColor(kGreen);
        h64->Fit("f64","","",-.01,.01);

        double num64,sig64,se64;
	int numi64 = h64->Integral(h64->GetXaxis()->FindBin(-.01),h64->GetXaxis()->FindBin(.01));
        num64 = numi64;
        cout<<"num64 = "<<num64<<endl;
        sig64= f64->GetParameter(2);
        cout<<"sig64 = "<<sig64<<endl;
        se[2]= sig64/sqrt(num64);
        cout<<"se64 = "<<se64<<endl;


        TCanvas *c65 = new TCanvas("c65");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h65",cut1+cut54+cut6);
        h65->SetTitle("Energy Resolution of Photon");
        h65->SetXTitle("Energy Resolution of Photon");
        h65->SetYTitle("");
        h65->Draw("");
        TF1 *f65 = new TF1("f65","gaus",-.012,.012);
	f65->SetLineColor(kTeal);
        h65->Fit("f65","","",-.01,.01);

        double num65,sig65,se65;
	int numi65 = h65->Integral(h65->GetXaxis()->FindBin(-.01),h65->GetXaxis()->FindBin(.01));
        num65 = numi65;
        cout<<"num65 = "<<num65<<endl;
        sig65= f65->GetParameter(2);
        cout<<"sig65 = "<<sig65<<endl;
        se[3]= sig65/sqrt(num65);
        cout<<"se65 = "<<se65<<endl;


        TCanvas *c66 = new TCanvas("c66");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h66",cut1+cut55+cut6);
        h66->SetTitle("Energy Resolution of Photon");
        h66->SetXTitle("Energy Resolution of Photon");
        h66->SetYTitle("");
        h66->Draw("");
        TF1 *f66 = new TF1("f66","gaus",-.012,.012);
	f66->SetLineColor(kBlue);
        h66->Fit("f66","","",-.01,.01);

        double num66,sig66,se66;
	int numi66 = h66->Integral(h66->GetXaxis()->FindBin(-.01),h66->GetXaxis()->FindBin(.01));
        num66 = numi66;
        cout<<"num66 = "<<num66<<endl;
        sig66= f66->GetParameter(2);
        cout<<"sig66 = "<<sig66<<endl;
        se[4]= sig66/sqrt(num66);
        cout<<"se66 = "<<se66<<endl;


        TCanvas *c67 = new TCanvas("c67");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h67",cut1+cut56+cut6);
        h67->SetTitle("Energy Resolution of Photon");
        h67->SetXTitle("Energy Resolution of Photon");
        h67->SetYTitle("");
        h67->Draw("");
        TF1 *f67 = new TF1("f67","gaus",-.012,.012);
	f67->SetLineColor(kViolet);
        h67->Fit("f67","","",-.025,.025);

        double num67,sig67,se67;
	int numi67 = h67->Integral(h67->GetXaxis()->FindBin(-.025),h67->GetXaxis()->FindBin(.025));
        num67 = numi67;
        cout<<"num67 = "<<num67<<endl;
        sig67= f67->GetParameter(2);
        cout<<"sig67 = "<<sig67<<endl;
        se[5]= sig67/sqrt(num67);
        cout<<"se67 = "<<se67<<endl;


        TCanvas *c68 = new TCanvas("c68");

	i[0]=0.1;
	i[1]=0.3;
	i[2]=0.5;
	i[3]=0.7;
	i[4]=0.85;
	i[5]=0.95;

	TGraph *g1 = new TGraph(6,i,se);
	g1->Draw("");


	double sep[6],ip[6];
/*
        TCanvas *c72 = new TCanvas("c72");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h72",cut1+cut69+cut72);
        h72->SetTitle("Energy Resolution of Photon");
        h72->SetXTitle("Energy Resolution of Photon");
        h72->SetYTitle("");
        h72->Draw("");
        TF1 *f72 = new TF1("f72","gaus",-.012,.012);
	f72->SetLineColor(kRed);
        h72->Fit("f72","","",-.01,.01);

        double num72,sig72,se72;
	int numi72 = h72->Integral(h72->GetXaxis()->FindBin(-.01),h72->GetXaxis()->FindBin(.01));
        num72 = numi72;
        cout<<"num72 = "<<num72<<endl;
        sig72= f72->GetParameter(2);
        cout<<"sig72 = "<<sig72<<endl;
        sep[0]= sig72/num72;
        cout<<"sep72 = "<<se62<<endl;


        TCanvas *c73 = new TCanvas("c73");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h73",cut1+cut69+cut73);
        h73->SetTitle("Energy Resolution of Photon");
        h73->SetXTitle("Energy Resolution of Photon");
        h73->SetYTitle("");
        h73->Draw("");
        TF1 *f73 = new TF1("f73","gaus",-.012,.012);
	f73->SetLineColor(kOrange);
        h73->Fit("f73","","",-.01,.01);

        double num73,sig73,se73;
	int numi73 = h73->Integral(h73->GetXaxis()->FindBin(-.01),h73->GetXaxis()->FindBin(.01));
        num73 = numi73;
        cout<<"num73 = "<<num73<<endl;
        sig73= f73->GetParameter(2);
        cout<<"sig73 = "<<sig73<<endl;
        sep[1]= sig73/num73;
        cout<<"se73 = "<<se73<<endl;


        TCanvas *c74 = new TCanvas("c74");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h74",cut1+cut69+cut74);
        h74->SetTitle("Energy Resolution of Photon");
        h74->SetXTitle("Energy Resolution of Photon");
        h74->SetYTitle("");
        h74->Draw("");
        TF1 *f74 = new TF1("f74","gaus",-.012,.012);
	f74->SetLineColor(kGreen);
        h74->Fit("f74","","",-.01,.01);

        double num74,sig74,se74;
	int numi74 = h74->Integral(h74->GetXaxis()->FindBin(-.01),h74->GetXaxis()->FindBin(.01));
        num74 = numi74;
        cout<<"num74 = "<<num74<<endl;
        sig74= f74->GetParameter(2);
        cout<<"sig74 = "<<sig74<<endl;
        sep[2]= sig74/num74;
        cout<<"se74 = "<<se74<<endl;


        TCanvas *c75 = new TCanvas("c75");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h75",cut1+cut69+cut75);
        h75->SetTitle("Energy Resolution of Photon");
        h75->SetXTitle("Energy Resolution of Photon");
        h75->SetYTitle("");
        h75->Draw("");
        TF1 *f75 = new TF1("f75","gaus",-.012,.012);
	f75->SetLineColor(kTeal);
        h75->Fit("f75","","",-.01,.01);

        double num75,sig75,se75;
	int numi75 = h75->Integral(h75->GetXaxis()->FindBin(-.01),h75->GetXaxis()->FindBin(.01));
        num75 = numi75;
        cout<<"num75 = "<<num75<<endl;
        sig75= f75->GetParameter(2);
        cout<<"sig75 = "<<sig75<<endl;
        sep[3]= sig75/num75;
        cout<<"se75 = "<<se75<<endl;


        TCanvas *c76 = new TCanvas("c76");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h76",cut1+cut69+cut76);
        h76->SetTitle("Energy Resolution of Photon");
        h76->SetXTitle("Energy Resolution of Photon");
        h76->SetYTitle("");
        h76->Draw("");
        TF1 *f76 = new TF1("f76","gaus",-.012,.012);
	f76->SetLineColor(kBlue);
        h76->Fit("f76","","",-.025,.025);

        double num76,sig76,se76;
	int numi76 = h76->Integral(h76->GetXaxis()->FindBin(-.01),h76->GetXaxis()->FindBin(.01));
        num76 = numi76;
        cout<<"num76 = "<<num76<<endl;
        sig76= f76->GetParameter(2);
        cout<<"sig76 = "<<sig76<<endl;
        sep[4]= sig76/num76;
        cout<<"se76 = "<<se76<<endl;


        TCanvas *c77 = new TCanvas("c77");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h77",cut1+cut69+cut77);
        h77->SetTitle("Energy Resolution of Photon");
        h77->SetXTitle("Energy Resolution of Photon");
        h77->SetYTitle("");
        h77->Draw("");
        TF1 *f77 = new TF1("f77","gaus",-.012,.012);
	f77->SetLineColor(kViolet);
        h77->Fit("f77","","",-.025,.025);

        double num77,sig77,se77;
	int numi77 = h77->Integral(h77->GetXaxis()->FindBin(-.01),h77->GetXaxis()->FindBin(.01));
        num77 = numi77;
        cout<<"num77 = "<<num77<<endl;
        sig77= f77->GetParameter(2);
        cout<<"sig77 = "<<sig77<<endl;
        sep[5]= sig77/num77;
        cout<<"se77 = "<<se77<<endl;


        TCanvas *c78 = new TCanvas("c78");

	ip[0]=0.1;
	ip[1]=0.3;
	ip[2]=0.5;
	ip[3]=0.7;
	ip[4]=0.85;
	ip[5]=0.95;

	TGraph *g71 = new TGraph(6,ip,sep);
	g71->Draw("");
*/

	}
