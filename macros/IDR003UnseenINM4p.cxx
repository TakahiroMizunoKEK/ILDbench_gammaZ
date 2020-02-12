
#include "/home/ilc/mizunot/bin/root_macros/style.C"
#include "photonERec6.cxx"
#include "photonERec63.cxx"

void IDR003UnseenINM4p() {

        stringstream filest;
        filest << "../root_merge.mILD_l5_o1_v02/"
               << "2f_z_l.eL.pR.mILD_l5_o1_v02.root" << ends;

        TFile *f = new TFile(filest.str().data());
	
	setILDStyle();
	//gStyle->SetPadRightMargin(1.0);
	//gStyle->SetPadRightMargin(1.0);
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

        TH2D *h47 = new TH2D("h47","",nbinx,100.,270.,nbiny,100.,270.);

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



	TCut cut1 = "pdg0==13 && abs(mzgen-91.2)<10";
	TCut cut3 = "coneen > -0.5";
	TCut cut4 = "abs(coslep1)<0.75 && abs(coslep2)<0.75";
        TCut cut2 = cut3;
        //TCut cut2 = "1. > 0.";

	TCut cut51 = "abs(cos(photonthetaMC))<0.2";
	TCut cut52 = "abs(cos(photonthetaMC))>=0.2 && abs(cos(photonthetaMC))<0.4";
	TCut cut53 = "abs(cos(photonthetaMC))>=0.4 && abs(cos(photonthetaMC))<0.6";
	TCut cut54 = "abs(cos(photonthetaMC))>=0.6 && abs(cos(photonthetaMC))<0.8";
	TCut cut55 = "abs(cos(photonthetaMC))>=0.8 && abs(cos(photonthetaMC))<0.9";
	TCut cut56 = "abs(cos(photonthetaMC))>=0.9";

	TCut cut7 = "abs(cos(photonthetaMC))<0.8";
	//TCut cut7 = "abs(cos(photonthetaMC))<0.75";
        TCut cut72 = "abs(sin(photonphiMC))<0.1";
        TCut cut73 = "abs(sin(photonphiMC))>=0.1 && abs(sin(photonphiMC))<0.2";
        TCut cut74 = "abs(sin(photonphiMC))>=0.2 && abs(sin(photonphiMC))<0.4";
        TCut cut75 = "abs(sin(photonphiMC))>=0.4 && abs(sin(photonphiMC))<0.6";
        TCut cut76 = "abs(sin(photonphiMC))>=0.6 && abs(sin(photonphiMC))<0.8";
        TCut cut77 = "abs(sin(photonphiMC))>=0.8";



	//TCut cut6 = "abs(sin(photonphiMC))>=0.4 && abs(sin(photonphiMC))<0.8";
	TCut cut6 = "abs(sin(photonphiMC))<=1.";
	//TCut cut6 = "abs(sin(photonphiMC))>0.2";
	//TCut cut62 = "abs(sin(photonphiMC))>0.5";



        TCanvas *c47 = new TCanvas("c47");
        hAnl->Draw("photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl):photonEAnl>>h47",cut1+cut2);
        h47->SetTitle("");
        h47->SetXTitle("PFO Energy of Photon");
        h47->SetYTitle("Reconstructed Energy of Photon");
        h47->Draw("colz");


        TH2D *h88 = new TH2D("h88","",520.,-10.,510.,520.,-10.,510.);
        TCanvas *c88 = new TCanvas("c88","",0,0,600,600);
        c88->SetRightMargin(.18);
        c88->SetLeftMargin(.18);

        //hAnl->Draw("(500.-lep1EMC-lep2EMC-photonERec6(500.,lep1EMC,lep2EMC,lep1thetaMC, lep1phiMC,lep2thetaMC,lep2phiMC,photonthetaMC,photonphiMC)):(500.-lep1EMC-lep2EMC-photonEMC)>>h88",cut1+cut2);
        //////hAnl->Draw("(500.-lep1EAnl-lep2EAnl-photonERec6(500.,lep1EMC,lep2EMC,lep1thetaMC, lep1phiMC,lep2thetaMC,lep2phiMC,photonthetaMC,photonphiMC)):(500.-lep1EMC-lep2EMC-photonEMC)>>h88",cut1+cut2);
        hAnl->Draw("(500.-lep1EAnl-lep2EAnl-photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaMC,photonphiMC)):(500.-lep1EMC-lep2EMC-photonEMC)>>h88",cut1+cut2);
        //hAnl->Draw("(500.-lep1EAnl-lep2EAnl-photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl)):(500.-lep1EMC-lep2EMC-photonEMC)>>h88",cut1+cut2);
        //hAnl->Draw("photonERec63(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl):(500.-lep1EMC-lep2EMC-photonEMC)>>h88",cut1+cut2);
        h88->SetXTitle("True ISR Energy (GeV)");
        h88->SetYTitle("Method4' Reconstructed ISR Energy (GeV)");
        h88->GetYaxis()->SetTitleSize(0.045);
        h88->GetXaxis()->SetTitleSize(0.045);
        h88->SetTitle("");
	h88->GetXaxis()->SetTitleOffset(1.65);
	h88->GetYaxis()->SetTitleOffset(1.95);
        h88->Draw("colz");


TLatex *   tex = new TLatex(210,460,"ILD preliminary");
tex->SetTextFont(62);
tex->Draw();



}
