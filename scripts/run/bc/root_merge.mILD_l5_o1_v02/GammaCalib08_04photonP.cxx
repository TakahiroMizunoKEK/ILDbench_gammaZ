
#include "/home/ilc/mizunot/bin/root_macros/style.C"
#include "photonERec4.cxx"

void GammaCalib08_04photonP() {

        stringstream filest;
        filest << "../root_merge.mILD_l5_o1_v02/"
               << "2f_z_l.eL.pR.mILD_l5_o1_v02.root" << ends;

        TFile *f = new TFile(filest.str().data());
	
	setILDStyle();
	//gStyle->SetPadRightMargin(1.0);
	//gStyle->SetPadRightMargin(1.0);
	gStyle->SetOptStat(1000001110);
        gStyle->SetStatH(0.15);
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

	TH1D *h011 = new TH1D("h011","",nbinx,xmin,xmax);
	TH1D *h012 = new TH1D("h012","",nbinx,xmin,xmax);
        TH2D *h013 = new TH2D("h013","",nbinx,xmin,xmax,nbiny,ymin,ymax);
        TH1D *h014 = new TH1D("h014","",200.,-.6,.6);
	TH1D *h015 = new TH1D("h015","",nbinx,xmin,xmax);
	TH1D *h016 = new TH1D("h016","",nbinx,xmin,xmax);
        TH2D *h017 = new TH2D("h017","",nbinx,xmin,xmax,nbiny,ymin,ymax);
        TH1D *h018 = new TH1D("h018","",200.,-.6,.6);

        TH1D *h021 = new TH1D("h021","",nbinx,xmin,xmax);
        TH1D *h022 = new TH1D("h022","",nbinx,xmin,xmax);
        TH2D *h023 = new TH2D("h023","",nbinx,xmin,xmax,nbiny,ymin,ymax);
        TH1D *h024 = new TH1D("h024","",200.,-.6,.6);
        TH1D *h025 = new TH1D("h025","",nbinx,xmin,xmax);
        TH1D *h026 = new TH1D("h026","",nbinx,xmin,xmax);
        TH2D *h027 = new TH2D("h027","",nbinx,xmin,xmax,nbiny,ymin,ymax);
        TH1D *h028 = new TH1D("h028","",200.,-.6,.6);

        TH1D *h031 = new TH1D("h031","",nbinx,xmin,xmax);
        TH1D *h032 = new TH1D("h032","",nbinx,xmin,xmax);
        TH2D *h033 = new TH2D("h033","",nbinx,xmin,xmax,nbiny,ymin,ymax);
        TH1D *h034 = new TH1D("h034","",200.,-.6,.6);
        TH1D *h035 = new TH1D("h035","",nbinx,xmin,xmax);
        TH1D *h036 = new TH1D("h036","",nbinx,xmin,xmax);
        TH2D *h037 = new TH2D("h037","",nbinx,xmin,xmax,nbiny,ymin,ymax);
        TH1D *h038 = new TH1D("h038","",200.,-.6,.6);

        TH1D *h041 = new TH1D("h041","",nbinx,xmin,xmax);
        TH1D *h042 = new TH1D("h042","",nbinx,xmin,xmax);
        TH2D *h043 = new TH2D("h043","",nbinx,xmin,xmax,nbiny,ymin,ymax);
        TH1D *h044 = new TH1D("h044","",200.,-.6,.6);
        TH1D *h045 = new TH1D("h045","",nbinx,xmin,xmax);
        TH1D *h046 = new TH1D("h046","",nbinx,xmin,xmax);
        TH2D *h047 = new TH2D("h047","",nbinx,xmin,xmax,nbiny,ymin,ymax);
        TH1D *h048 = new TH1D("h048","",200.,-.6,.6);

        TH1D *h051 = new TH1D("h051","",nbinx,xmin,xmax);
        TH1D *h052 = new TH1D("h052","",nbinx,xmin,xmax);
        TH2D *h053 = new TH2D("h053","",nbinx,xmin,xmax,nbiny,ymin,ymax);
        TH1D *h054 = new TH1D("h054","",200.,-.6,.6);
        TH1D *h055 = new TH1D("h055","",nbinx,xmin,xmax);
        TH1D *h056 = new TH1D("h056","",nbinx,xmin,xmax);
        TH2D *h057 = new TH2D("h057","",nbinx,xmin,xmax,nbiny,ymin,ymax);
        TH1D *h058 = new TH1D("h058","",200.,-.6,.6);


        TH1D *h061 = new TH1D("h061","",nbinx,xmin,xmax);
        TH1D *h062 = new TH1D("h062","",nbinx,xmin,xmax);
        TH2D *h063 = new TH2D("h063","",nbinx,xmin,xmax,nbiny,ymin,ymax);
        TH1D *h064 = new TH1D("h064","",200.,-.6,.6);
        TH1D *h065 = new TH1D("h065","",nbinx,xmin,xmax);
        TH1D *h066 = new TH1D("h066","",nbinx,xmin,xmax);
        TH2D *h067 = new TH2D("h067","",nbinx,xmin,xmax,nbiny,ymin,ymax);
        TH1D *h068 = new TH1D("h068","",200.,-.6,.6);


        TH1D *h111 = new TH1D("h111","",200.,-.6,.6);
        TH1D *h112 = new TH1D("h112","",200.,-.4,.4);
        TH1D *h121 = new TH1D("h121","",200.,-.6,.6);
        TH1D *h122 = new TH1D("h122","",200.,-.4,.4);
        TH1D *h131 = new TH1D("h131","",200.,-.6,.6);
        TH1D *h132 = new TH1D("h132","",200.,-.4,.4);
        TH1D *h141 = new TH1D("h141","",200.,-.6,.6);
        TH1D *h142 = new TH1D("h142","",200.,-.4,.4);
        TH1D *h151 = new TH1D("h151","",200.,-.6,.6);
        TH1D *h152 = new TH1D("h152","",200.,-.4,.4);
        TH1D *h161 = new TH1D("h161","",200.,-.6,.6);
        TH1D *h162 = new TH1D("h162","",200.,-.4,.4);







	TCut cut1 = "pdg0==13 && abs(mzgen-91.2)<10";
	TCut cut2 = "coneen > -0.5";
	TCut cut31 = "abs(coslep1)<0.2 && abs(coslep2)<0.2";
	TCut cut32 = "abs(coslep1)>=0.2 && abs(coslep1)<0.4 && abs(coslep2)>=0.2 && abs(coslep2)<0.4";
	TCut cut33 = "abs(coslep1)>=0.4 && abs(coslep1)<0.6 && abs(coslep2)>=0.4 && abs(coslep2)<0.6";
	TCut cut34 = "abs(coslep1)>=0.6 && abs(coslep1)<0.8 && abs(coslep2)>=0.6 && abs(coslep2)<0.8";
	TCut cut35 = "abs(coslep1)>=0.8 && abs(coslep1)<0.9 && abs(coslep2)>=0.8 && abs(coslep2)<0.9";
	TCut cut36 = "abs(coslep1)>=0.9 && abs(coslep2)>=0.9";

        TCanvas *c11 = new TCanvas("c11");
        c11->Divide(2,2);
        c11->cd(1);

	hAnl->Draw("photonEAnl>>h011",cut1+cut2+cut31);
        h011->Draw("");
        h011->SetTitle("Energy of Photon (Anl)");
        h011->SetXTitle("Energy of Photon (Anl)");

	//TCanvas *c2 = new TCanvas("c2");
	c11->cd(2);
	
	hAnl->Draw("(photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))>>h012",cut1+cut2+cut31);
	h012->Draw("");
        h012->SetTitle("Energy of Photon (Reconstructed)");
        h012->SetXTitle("Energy of Photon (Reconstructed)");

        //TCanvas *c3 = new TCanvas("c3");
	c11->cd(3);
	hAnl->Draw("photonEAnl:photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h013",cut1+cut2+cut31);
        h013->Draw("colz");

        h013->SetTitle("Energy of Photon (Anl:Reconstructed)");
        h013->SetXTitle("Energy of Photon (Reconstructed)");
        h013->SetYTitle("Energy of Photon (Anl)");


        TCanvas *c12 = new TCanvas("c12");
        c12->Divide(2,2);
        c12->cd(1);

	hAnl->Draw("photonEMC>>h015",cut1+cut2+cut31);
        h015->Draw("");
        h015->SetTitle("Energy of Photon (MC)");
        h015->SetXTitle("Energy of Photon (MC)");

	//TCanvas *c11 = new TCanvas("c11");
	c12->cd(2);
	hAnl->Draw("photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h016",cut1+cut2+cut31);
	h016->Draw("");
        h016->SetTitle("Energy of Photon (Reconstructed)");
        h016->SetXTitle("Energy of Photon (Reconstructed)");

        //TCanvas *c12 = new TCanvas("c12");
	c12->cd(3);
	hAnl->Draw("photonEMC:photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h017",cut1+cut2+cut31);
        h017->Draw("colz");
        h017->SetTitle("Energy of Photon (MC:Reconstructed)");
        h017->SetXTitle("Energy of Photon (Reconstructed)");
        h017->SetYTitle("Energy of Photon (MC)");

        c12->cd(4);
	hAnl->Draw("(-photonEMC+photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))/photonEMC>>h018",cut1+cut2+cut31);
        h018->Draw("");
        h018->SetTitle("Energy Resolution of Photon");
        h018->SetXTitle("Energy Resolution of Photon");
        h018->SetYTitle("");



        TCanvas *c21 = new TCanvas("c21");
        c21->Divide(2,2);
        c21->cd(1);

	hAnl->Draw("photonEAnl>>h021",cut1+cut2+cut32);
        h021->Draw("");
        h021->SetTitle("Energy of Photon (Anl)");
        h021->SetXTitle("Energy of Photon (Anl)");

	//TCanvas *c2 = new TCanvas("c2");
	c21->cd(2);
	
	hAnl->Draw("(photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))>>h022",cut1+cut2+cut32);
	h022->Draw("");
        h022->SetTitle("Energy of Photon (Reconstructed)");
        h022->SetXTitle("Energy of Photon (Reconstructed)");

        //TCanvas *c3 = new TCanvas("c3");
	c21->cd(3);
	hAnl->Draw("photonEAnl:photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h023",cut1+cut2+cut32);
        h023->Draw("colz");

        h023->SetTitle("Energy of Photon (Anl:Reconstructed)");
        h023->SetXTitle("Energy of Photon (Reconstructed)");
        h023->SetYTitle("Energy of Photon (Anl)");


        TCanvas *c22 = new TCanvas("c22");
        c22->Divide(2,2);
        c22->cd(1);

	hAnl->Draw("photonEMC>>h025",cut1+cut2+cut32);
        h025->Draw("");
        h025->SetTitle("Energy of Photon (MC)");
        h025->SetXTitle("Energy of Photon (MC)");

	//TCanvas *c11 = new TCanvas("c11");
	c22->cd(2);
	hAnl->Draw("photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h026",cut1+cut2+cut32);
	h026->Draw("");
        h026->SetTitle("Energy of Photon (Reconstructed)");
        h026->SetXTitle("Energy of Photon (Reconstructed)");

        //TCanvas *c12 = new TCanvas("c12");
	c22->cd(3);
	hAnl->Draw("photonEMC:photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h027",cut1+cut2+cut32);
        h027->Draw("colz");
        h027->SetTitle("Energy of Photon (MC:Reconstructed)");
        h027->SetXTitle("Energy of Photon (Reconstructed)");
        h027->SetYTitle("Energy of Photon (MC)");

        c22->cd(4);
	hAnl->Draw("(-photonEMC+photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))/photonEMC>>h028",cut1+cut2+cut32);
        h028->Draw("");
        h028->SetTitle("Energy Resolution of Photon");
        h028->SetXTitle("Energy Resolution of Photon");
        h028->SetYTitle("");


        TCanvas *c31 = new TCanvas("c31");
        c31->Divide(2,2);
        c31->cd(1);

	hAnl->Draw("photonEAnl>>h031",cut1+cut2+cut33);
        h031->Draw("");
        h031->SetTitle("Energy of Photon (Anl)");
        h031->SetXTitle("Energy of Photon (Anl)");

	//TCanvas *c2 = new TCanvas("c2");
	c31->cd(2);
	
	hAnl->Draw("(photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))>>h032",cut1+cut2+cut33);
	h032->Draw("");
        h032->SetTitle("Energy of Photon (Reconstructed)");
        h032->SetXTitle("Energy of Photon (Reconstructed)");

        //TCanvas *c3 = new TCanvas("c3");
	c31->cd(3);
	hAnl->Draw("photonEAnl:photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h033",cut1+cut2+cut33);
        h033->Draw("colz");

        h033->SetTitle("Energy of Photon (Anl:Reconstructed)");
        h033->SetXTitle("Energy of Photon (Reconstructed)");
        h033->SetYTitle("Energy of Photon (Anl)");


        TCanvas *c32 = new TCanvas("c32");
        c32->Divide(2,2);
        c32->cd(1);

	hAnl->Draw("photonEMC>>h035",cut1+cut2+cut33);
        h035->Draw("");
        h035->SetTitle("Energy of Photon (MC)");
        h035->SetXTitle("Energy of Photon (MC)");

	//TCanvas *c11 = new TCanvas("c11");
	c32->cd(2);
	hAnl->Draw("photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h036",cut1+cut2+cut33);
	h036->Draw("");
        h036->SetTitle("Energy of Photon (Reconstructed)");
        h036->SetXTitle("Energy of Photon (Reconstructed)");

        //TCanvas *c12 = new TCanvas("c12");
	c32->cd(3);
	hAnl->Draw("photonEMC:photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h037",cut1+cut2+cut33);
        h037->Draw("colz");
        h037->SetTitle("Energy of Photon (MC:Reconstructed)");
        h037->SetXTitle("Energy of Photon (Reconstructed)");
        h037->SetYTitle("Energy of Photon (MC)");

        c32->cd(4);
	hAnl->Draw("(-photonEMC+photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))/photonEMC>>h038",cut1+cut2+cut33);
        h038->Draw("");
        h038->SetTitle("Energy Resolution of Photon");
        h038->SetXTitle("Energy Resolution of Photon");
        h038->SetYTitle("");



        TCanvas *c41 = new TCanvas("c41");
        c41->Divide(2,2);
        c41->cd(1);

	hAnl->Draw("photonEAnl>>h041",cut1+cut2+cut34);
        h041->Draw("");
        h041->SetTitle("Energy of Photon (Anl)");
        h041->SetXTitle("Energy of Photon (Anl)");

	//TCanvas *c2 = new TCanvas("c2");
	c41->cd(2);
	
	hAnl->Draw("(photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))>>h042",cut1+cut2+cut34);
	h042->Draw("");
        h042->SetTitle("Energy of Photon (Reconstructed)");
        h042->SetXTitle("Energy of Photon (Reconstructed)");

        //TCanvas *c3 = new TCanvas("c3");
	c41->cd(3);
	hAnl->Draw("photonEAnl:photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h043",cut1+cut2+cut34);
        h043->Draw("colz");

        h043->SetTitle("Energy of Photon (Anl:Reconstructed)");
        h043->SetXTitle("Energy of Photon (Reconstructed)");
        h043->SetYTitle("Energy of Photon (Anl)");


        TCanvas *c42 = new TCanvas("c42");
        c42->Divide(2,2);
        c42->cd(1);

	hAnl->Draw("photonEMC>>h045",cut1+cut2+cut34);
        h045->Draw("");
        h045->SetTitle("Energy of Photon (MC)");
        h045->SetXTitle("Energy of Photon (MC)");

	//TCanvas *c11 = new TCanvas("c11");
	c42->cd(2);
	hAnl->Draw("photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h046",cut1+cut2+cut34);
	h046->Draw("");
        h046->SetTitle("Energy of Photon (Reconstructed)");
        h046->SetXTitle("Energy of Photon (Reconstructed)");

        //TCanvas *c12 = new TCanvas("c12");
	c42->cd(3);
	hAnl->Draw("photonEMC:photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h047",cut1+cut2+cut34);
        h047->Draw("colz");
        h047->SetTitle("Energy of Photon (MC:Reconstructed)");
        h047->SetXTitle("Energy of Photon (Reconstructed)");
        h047->SetYTitle("Energy of Photon (MC)");

        c42->cd(4);
	hAnl->Draw("(-photonEMC+photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))/photonEMC>>h048",cut1+cut2+cut34);
        h048->Draw("");
        h048->SetTitle("Energy Resolution of Photon");
        h048->SetXTitle("Energy Resolution of Photon");
        h048->SetYTitle("");



        TCanvas *c51 = new TCanvas("c51");
        c51->Divide(2,2);
        c51->cd(1);

	hAnl->Draw("photonEAnl>>h051",cut1+cut2+cut35);
        h051->Draw("");
        h051->SetTitle("Energy of Photon (Anl)");
        h051->SetXTitle("Energy of Photon (Anl)");

	//TCanvas *c2 = new TCanvas("c2");
	c51->cd(2);
	
	hAnl->Draw("(photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))>>h052",cut1+cut2+cut35);
	h052->Draw("");
        h052->SetTitle("Energy of Photon (Reconstructed)");
        h052->SetXTitle("Energy of Photon (Reconstructed)");

        //TCanvas *c3 = new TCanvas("c3");
	c51->cd(3);
	hAnl->Draw("photonEAnl:photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h053",cut1+cut2+cut35);
        h053->Draw("colz");

        h053->SetTitle("Energy of Photon (Anl:Reconstructed)");
        h053->SetXTitle("Energy of Photon (Reconstructed)");
        h053->SetYTitle("Energy of Photon (Anl)");


        TCanvas *c52 = new TCanvas("c52");
        c52->Divide(2,2);
        c52->cd(1);

	hAnl->Draw("photonEMC>>h055",cut1+cut2+cut35);
        h055->Draw("");
        h055->SetTitle("Energy of Photon (MC)");
        h055->SetXTitle("Energy of Photon (MC)");

	//TCanvas *c11 = new TCanvas("c11");
	c52->cd(2);
	hAnl->Draw("photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h056",cut1+cut2+cut35);
	h056->Draw("");
        h056->SetTitle("Energy of Photon (Reconstructed)");
        h056->SetXTitle("Energy of Photon (Reconstructed)");

        //TCanvas *c12 = new TCanvas("c12");
	c52->cd(3);
	hAnl->Draw("photonEMC:photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h057",cut1+cut2+cut35);
        h057->Draw("colz");
        h057->SetTitle("Energy of Photon (MC:Reconstructed)");
        h057->SetXTitle("Energy of Photon (Reconstructed)");
        h057->SetYTitle("Energy of Photon (MC)");

        c52->cd(4);
	hAnl->Draw("(-photonEMC+photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))/photonEMC>>h058",cut1+cut2+cut35);
        h058->Draw("");
        h058->SetTitle("Energy Resolution of Photon");
        h058->SetXTitle("Energy Resolution of Photon");
        h058->SetYTitle("");



        TCanvas *c61 = new TCanvas("c61");
        c61->Divide(2,2);
        c61->cd(1);

	hAnl->Draw("photonEAnl>>h061",cut1+cut2+cut36);
        h061->Draw("");
        h061->SetTitle("Energy of Photon (Anl)");
        h061->SetXTitle("Energy of Photon (Anl)");

	//TCanvas *c2 = new TCanvas("c2");
	c61->cd(2);
	
	hAnl->Draw("(photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))>>h062",cut1+cut2+cut36);
	h062->Draw("");
        h062->SetTitle("Energy of Photon (Reconstructed)");
        h062->SetXTitle("Energy of Photon (Reconstructed)");

        //TCanvas *c3 = new TCanvas("c3");
	c61->cd(3);
	hAnl->Draw("photonEAnl:photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h063",cut1+cut2+cut36);
        h063->Draw("colz");

        h063->SetTitle("Energy of Photon (Anl:Reconstructed)");
        h063->SetXTitle("Energy of Photon (Reconstructed)");
        h063->SetYTitle("Energy of Photon (Anl)");


        TCanvas *c62 = new TCanvas("c62");
        c62->Divide(2,2);
        c62->cd(1);

	hAnl->Draw("photonEMC>>h065",cut1+cut2+cut36);
        h065->Draw("");
        h065->SetTitle("Energy of Photon (MC)");
        h065->SetXTitle("Energy of Photon (MC)");

	//TCanvas *c11 = new TCanvas("c11");
	c62->cd(2);
	hAnl->Draw("photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h066",cut1+cut2+cut36);
	h066->Draw("");
        h066->SetTitle("Energy of Photon (Reconstructed)");
        h066->SetXTitle("Energy of Photon (Reconstructed)");

        //TCanvas *c12 = new TCanvas("c12");
	c62->cd(3);
	hAnl->Draw("photonEMC:photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h067",cut1+cut2+cut36);
        h067->Draw("colz");
        h067->SetTitle("Energy of Photon (MC:Reconstructed)");
        h067->SetXTitle("Energy of Photon (Reconstructed)");
        h067->SetYTitle("Energy of Photon (MC)");

        c62->cd(4);
	hAnl->Draw("(-photonEMC+photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))/photonEMC>>h068",cut1+cut2+cut36);
        h068->Draw("");
        h068->SetTitle("Energy Resolution of Photon");
        h068->SetXTitle("Energy Resolution of Photon");
        h068->SetYTitle("");





        TCanvas *c101 = new TCanvas("c101");
	hAnl->Draw("(photonEAnl-photonEMC)/photonEMC>>h111",cut1+cut2+cut31);
        h111->SetLineColor(kRed);
        gPad->Update();
	TPaveStats *st111 = (TPaveStats*)h111->GetListOfFunctions()->FindObject("stats");

	hAnl->Draw("(photonEAnl-photonEMC)/photonEMC>>h121",cut1+cut2+cut32);
        h121->SetLineColor(kOrange);
        gPad->Update();
	TPaveStats *st121 = (TPaveStats*)h121->GetListOfFunctions()->FindObject("stats");

	hAnl->Draw("(photonEAnl-photonEMC)/photonEMC>>h131",cut1+cut2+cut33);
        h131->SetLineColor(kYellow);
        gPad->Update();
	TPaveStats *st131 = (TPaveStats*)h131->GetListOfFunctions()->FindObject("stats");

	hAnl->Draw("(photonEAnl-photonEMC)/photonEMC>>h141",cut1+cut2+cut34);
        h141->SetLineColor(kGreen+2);
        gPad->Update();
	TPaveStats *st141 = (TPaveStats*)h141->GetListOfFunctions()->FindObject("stats");

	hAnl->Draw("(photonEAnl-photonEMC)/photonEMC>>h151",cut1+cut2+cut35);
        h151->SetLineColor(kBlue);
        gPad->Update();
	TPaveStats *st151 = (TPaveStats*)h151->GetListOfFunctions()->FindObject("stats");

	hAnl->Draw("(photonEAnl-photonEMC)/photonEMC>>h161",cut1+cut2+cut36);
        h161->SetLineColor(kViolet);
        gPad->Update();
	TPaveStats *st161 = (TPaveStats*)h161->GetListOfFunctions()->FindObject("stats");


        h111->SetXTitle("PFO Energy Resolution of Photon");
        h111->SetYTitle("");
	h111->SetMaximum(50);
        h111->Draw("");
        //h121->Draw("same");
        //h131->Draw("same");
        //h141->Draw("same");
        h151->Draw("same");
        h161->Draw("same");

        TCanvas *c102 = new TCanvas("c102");

        hAnl->Draw("(-photonEMC+photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))/photonEMC>>h112",cut1+cut2+cut31);
        h112->SetLineColor(kRed);
        gPad->Update();
        TPaveStats *st112 = (TPaveStats*)h112->GetListOfFunctions()->FindObject("stats");

        hAnl->Draw("(-photonEMC+photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))/photonEMC>>h122",cut1+cut2+cut32);
        h122->SetLineColor(kOrange);
        gPad->Update();
        TPaveStats *st122 = (TPaveStats*)h122->GetListOfFunctions()->FindObject("stats");

        hAnl->Draw("(-photonEMC+photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))/photonEMC>>h132",cut1+cut2+cut33);
        h132->SetLineColor(kYellow);
        gPad->Update();
        TPaveStats *st132 = (TPaveStats*)h132->GetListOfFunctions()->FindObject("stats");

        hAnl->Draw("(-photonEMC+photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))/photonEMC>>h142",cut1+cut2+cut34);
        h142->SetLineColor(kGreen+2);
        gPad->Update();
        TPaveStats *st142 = (TPaveStats*)h142->GetListOfFunctions()->FindObject("stats");

        hAnl->Draw("(-photonEMC+photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))/photonEMC>>h152",cut1+cut2+cut35);
        h152->SetLineColor(kBlue);
        gPad->Update();
        TPaveStats *st152 = (TPaveStats*)h152->GetListOfFunctions()->FindObject("stats");

        hAnl->Draw("(-photonEMC+photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))/photonEMC>>h162",cut1+cut2+cut36);
        h162->SetLineColor(kViolet);
        gPad->Update();
        TPaveStats *st162 = (TPaveStats*)h162->GetListOfFunctions()->FindObject("stats");

	h122->Scale(h112->GetEntries() / h122->GetEntries());
	h132->Scale(h112->GetEntries() / h132->GetEntries());
	h142->Scale(h112->GetEntries() / h142->GetEntries());
	h152->Scale(h112->GetEntries() / h152->GetEntries());
	h162->Scale(h112->GetEntries() / h162->GetEntries());

/*
        h112->Scale(1 / h112->GetEntries());
        h122->Scale(1 / h122->GetEntries());
        h132->Scale(1 / h132->GetEntries());
        h142->Scale(1 / h142->GetEntries());
        h152->Scale(1 / h152->GetEntries());
        h162->Scale(1 / h162->GetEntries());*/


        h112->SetXTitle("Rerconstructed Energy Resolution of Photon");
        h112->SetYTitle("");
//	h112->SetMaximum(1.);
        h112->Draw("");
        //h122->Draw("same");
        //h132->Draw("same");
        //h142->Draw("same");
        h152->Draw("same");
        h162->Draw("same");



	}
