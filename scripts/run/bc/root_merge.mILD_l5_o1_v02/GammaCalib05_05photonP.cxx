
#include "/home/ilc/mizunot/bin/root_macros/style.C"
#include "photonERec5.cxx"
#include "photonERec53.cxx"

void GammaCalib05_05photonP() {

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


	TCut cut1 = "pdg0==13 && abs(mzgen-91.2)<10";
	TCut cut3 = "coneen > -0.5";
	TCut cut4 = "abs(coslep1)<0.75 && abs(coslep2)<0.75";
        TCut cut2 = cut3+cut4;

        TCanvas *c1 = new TCanvas("c1");
        c1->Divide(2,2);
        c1->cd(1);

	hAnl->Draw("photonEAnl>>h1",cut1+cut2);
        h1->Draw("");
        h1->SetTitle("Energy of Photon (Anl)");
        h1->SetXTitle("Energy of Photon (Anl)");

	//TCanvas *c2 = new TCanvas("c2");
	c1->cd(2);

	hAnl->Draw("(photonERec5(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))>>h2",cut1+cut2);
	h2->Draw("");
        h2->SetTitle("Energy of Photon (Reconstructed)");
        h2->SetXTitle("Energy of Photon (Reconstructed)");

        //TCanvas *c3 = new TCanvas("c3");
	c1->cd(3);
	hAnl->Draw("photonEAnl:photonERec5(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl)>>h3",cut1+cut2);
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
	hAnl->Draw("photonERec5(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl)>>h11",cut1+cut2);
	h11->Draw("");
        h11->SetTitle("Energy of Photon (Reconstructed)");
        h11->SetXTitle("Energy of Photon (Reconstructed)");

	c10->cd(3);
	hAnl->Draw("photonEMC:photonERec5(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl)>>h12",cut1+cut2);
        h12->Draw("colz");

        h12->SetTitle("Energy of Photon (MC:Reconstructed)");
        h12->SetXTitle("Energy of Photon (Reconstructed)");
        h12->SetYTitle("Energy of Photon (MC)");

        c10->cd(4);
	hAnl->Draw("(-photonEMC+photonERec5(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h41",cut1+cut2);
        h41->Draw("");

        h41->SetTitle("Energy Resolution of Photon");
        h41->SetXTitle("Energy Resolution of Photon");
        h41->SetYTitle("");


        TCanvas *c30 = new TCanvas("c30");
        c30->Divide(2,2);
        c30->cd(1);

        hAnl->Draw("ISRphotonEMC>>h31",cut1+cut2);
        h31->Draw("");
        h31->SetTitle("Energy of ISR Photon (MC)");
        h31->SetXTitle("Energy of ISR Photon (MC)");

        c30->cd(2);
        hAnl->Draw("photonERec53(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl)>>h32",cut1+cut2);
        h32->Draw("");
        h32->SetTitle("Energy of ISR Photon (Reconstructed)");
        h32->SetXTitle("Energy of ISR Photon (Reconstructed)");

        c30->cd(3);
        hAnl->Draw("ISRphotonEMC:photonERec53(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl)>>h33",cut1+cut2);
        h33->Draw("colz");

        h33->SetTitle("Energy of ISR Photon (MC:Reconstructed)");
        h33->SetXTitle("Energy of ISR Photon (Reconstructed)");
        h33->SetYTitle("Energy of ISR Photon (MC)");

        c30->cd(4);
        hAnl->Draw("(-ISRphotonEMC+photonERec53(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/ISRphotonEMC>>h34",cut1+cut2);
        h34->Draw("");

        h34->SetTitle("Energy Resolution of Photon");
        h34->SetXTitle("Energy Resolution of Photon");
        h34->SetYTitle("");



        TCanvas *c31 = new TCanvas("c31");

        hAnl->Draw("ISRphotonEMC>>h35",cut1+cut2);
        h35->SetLineColor(kBlue);
        gPad->Update();
        TPaveStats *st35 = (TPaveStats*)h35->GetListOfFunctions()->FindObject("stats");

        hAnl->Draw("photonERec53(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl)>>h36",cut1+cut2);
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


        TCanvas *c47 = new TCanvas("c47");
        hAnl->Draw("photonERec5(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl):photonEAnl>>h47",cut1+cut2);
        h47->SetTitle("");
        h47->SetXTitle("PFO Energy of Photon");
        h47->SetYTitle("Reconstructed Energy of Photon");
        h47->Draw("colz");

	}
