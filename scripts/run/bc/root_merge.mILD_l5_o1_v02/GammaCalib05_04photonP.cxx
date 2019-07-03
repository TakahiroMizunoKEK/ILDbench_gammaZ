
#include "/home/ilc/mizunot/bin/root_macros/style.C"
#include "photonERec4.cxx"

void GammaCalib05_04photonP() {

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

	TH1D *h01 = new TH1D("h01","",nbinx,xmin,xmax);
	TH1D *h02 = new TH1D("h02","",nbinx,xmin,xmax);
        TH2D *h03 = new TH2D("h03","",nbinx,xmin,xmax,nbiny,ymin,ymax);
        TH1D *h04 = new TH1D("h04","",200.,-.6,.6);

	TH1D *h11 = new TH1D("h11","",nbinx,xmin,xmax);
	TH1D *h12 = new TH1D("h12","",nbinx,xmin,xmax);
        TH2D *h13 = new TH2D("h13","",nbinx,xmin,xmax,nbiny,ymin,ymax);
        TH1D *h14 = new TH1D("h14","",200.,-.6,.6);

	TH1D *h21 = new TH1D("h21","",nbinx,xmin,xmax);
	TH1D *h22 = new TH1D("h22","",nbinx,xmin,xmax);
        TH2D *h23 = new TH2D("h23","",nbinx,xmin,xmax,nbiny,ymin,ymax);
        TH1D *h24 = new TH1D("h24","",200.,-.6,.6);

	TH1D *h05 = new TH1D("h05","",nbinx,xmin,xmax);
	TH1D *h06 = new TH1D("h06","",nbinx,xmin,xmax);
        TH2D *h07 = new TH2D("h07","",nbinx,xmin,xmax,nbiny,ymin,ymax);
        TH1D *h08 = new TH1D("h08","",200.,-.6,.6);

	TH1D *h15 = new TH1D("h15","",nbinx,xmin,xmax);
	TH1D *h16 = new TH1D("h16","",nbinx,xmin,xmax);
        TH2D *h17 = new TH2D("h17","",nbinx,xmin,xmax,nbiny,ymin,ymax);
        TH1D *h18 = new TH1D("h18","",200.,-.6,.6);

	TH1D *h25 = new TH1D("h25","",nbinx,xmin,xmax);
	TH1D *h26 = new TH1D("h26","",nbinx,xmin,xmax);
        TH2D *h27 = new TH2D("h27","",nbinx,xmin,xmax,nbiny,ymin,ymax);
        TH1D *h28 = new TH1D("h28","",200.,-.6,.6);

        TH1D *h31 = new TH1D("h31","",nbinx,xmin,xmax);
        TH1D *h32 = new TH1D("h32","",nbinx,xmin,xmax);

        TH1D *h41 = new TH1D("h41","",200.,-.6,.6);
        TH1D *h42 = new TH1D("h42","",200.,-.6,.6);
        TH1D *h43 = new TH1D("h43","",200.,-.6,.6);
        TH1D *h44 = new TH1D("h44","",200.,-.6,.6);
        TH1D *h45 = new TH1D("h45","",200.,-.6,.6);
        TH1D *h46 = new TH1D("h46","",200.,-.6,.6);

        //TH2D *h47 = new TH2D("h47","",200.,-.6,.6,200,-.6,.6);
        //TH2D *h47 = new TH2D("h47","",nbinx,xmin,xmax,nbiny,ymin,ymax);
        TH2D *h47 = new TH2D("h47","",nbinx,100.,270.,nbiny,100.,270.);

	TH1D *h51 = new TH1D("h51","",nbinx,xmin,xmax);
	TH1D *h52 = new TH1D("h52","",nbinx,xmin,xmax);
        TH2D *h53 = new TH2D("h53","",nbinx,xmin,xmax,nbiny,ymin,ymax);
	

	TCut cut1 = "pdg0==13 && abs(mzgen-91.2)<10";
	TCut cut3 = "coneen > -0.5";
	TCut cut4 = "abs(coslep1)<0.75 && abs(coslep2)<0.75";
        TCut cut2 = cut3+cut4;

        TCanvas *c01 = new TCanvas("c1");
        c01->Divide(2,2);
        c01->cd(1);

	hAnl->Draw("photonEAnl>>h01",cut1+cut2);
        h01->Draw("");
        h01->SetTitle("Energy of Photon (Anl)");
        h01->SetXTitle("Energy of Photon (Anl)");

	//TCanvas *c2 = new TCanvas("c2");
	c01->cd(2);
	
	hAnl->Draw("(photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))>>h02",cut1+cut2);
	h02->Draw("");
        h02->SetTitle("Energy of Photon (Reconstructed)");
        h02->SetXTitle("Energy of Photon (Reconstructed)");

        //TCanvas *c3 = new TCanvas("c3");
	c01->cd(3);
	hAnl->Draw("photonEAnl:photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h03",cut1+cut2);
        h03->Draw("colz");

        h03->SetTitle("Energy of Photon (Anl:Reconstructed)");
        h03->SetXTitle("Energy of Photon (Reconstructed)");
        h03->SetYTitle("Energy of Photon (Anl)");



	TCanvas *c11 = new TCanvas("c11");
	c11->Divide(2,2);
        c11->cd(1);
	hAnl->Draw("lep1EAnl>>h11",cut1+cut2);
        h11->Draw("");
        h11->SetTitle("Energy of Mu^{-} (Anl)");
        h11->SetXTitle("Energy of Mu^{-} (Anl)");

	//TCanvas *c5 = new TCanvas("c5");
	c11->cd(2);
	hAnl->Draw("(photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,1))>>h12",cut1+cut2);
	h12->Draw("");
        h12->SetTitle("Energy of Mu^{-} (Reconstructed)");
        h12->SetXTitle("Energy of Mu^{-} (Reconstructed)");

        //TCanvas *c6 = new TCanvas("c6");
        c11->cd(3);
	hAnl->Draw("lep1EAnl:photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,1)>>h13",cut1+cut2);
        h13->Draw("colz");
        h13->SetTitle("Energy of Mu^{-} (Anl:Reconstructed)");
        h13->SetXTitle("Energy of Mu^{-} (Reconstructed)");
        h13->SetYTitle("Energy of Mu^{-} (Anl)");


	
	TCanvas *c21 = new TCanvas("c21");
	c21->Divide(2,2);
        c21->cd(1);
	hAnl->Draw("lep2EAnl>>h21",cut1+cut2);
        h21->Draw("");
        h21->SetTitle("Energy of Mu^{+} (Anl)");
        h21->SetXTitle("Energy of Mu^{+} (Anl)");

	//TCanvas *c8 = new TCanvas("c8");
	c21->cd(2);
	hAnl->Draw("photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,2)>>h22",cut1+cut2);
	h22->Draw("");
        h22->SetTitle("Energy of Mu^{+} (Reconsructed)");
        h22->SetXTitle("Energy of Mu^{+} (Reconstructed)");

        //TCanvas *c9 = new TCanvas("c9");
	c21->cd(3);
	hAnl->Draw("lep2EAnl:photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,2)>>h23",cut1+cut2);
        h23->Draw("colz");
        h23->SetTitle("Energy of Mu^{+} (Anl:Reconstructed)");
        h23->SetXTitle("Energy of Mu^{+} (Reconstructed)");
        h23->SetYTitle("Energy of Mu^{+} (Anl)");



        TCanvas *c02 = new TCanvas("c02");
        c02->Divide(2,2);
        c02->cd(1);

	hAnl->Draw("photonEMC>>h05",cut1+cut2);
        h05->Draw("");
        h05->SetTitle("Energy of Photon (MC)");
        h05->SetXTitle("Energy of Photon (MC)");

	//TCanvas *c11 = new TCanvas("c11");
	c02->cd(2);
	hAnl->Draw("photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h06",cut1+cut2);
	h06->Draw("");
        h06->SetTitle("Energy of Photon (Reconstructed)");
        h06->SetXTitle("Energy of Photon (Reconstructed)");

        //TCanvas *c12 = new TCanvas("c12");
	c02->cd(3);
	hAnl->Draw("photonEMC:photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h07",cut1+cut2);
        h07->Draw("colz");
        h07->SetTitle("Energy of Photon (MC:Reconstructed)");
        h07->SetXTitle("Energy of Photon (Reconstructed)");
        h07->SetYTitle("Energy of Photon (MC)");

        c02->cd(4);
	hAnl->Draw("(-photonEMC+photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))/photonEMC>>h08",cut1+cut2);
        h08->Draw("");
        h08->SetTitle("Energy Resolution of Photon");
        h08->SetXTitle("Energy Resolution of Photon");
        h08->SetYTitle("");


	TCanvas *c12 = new TCanvas("c12");
	c12->Divide(2,2);
        c12->cd(1);
	hAnl->Draw("lep1EMC>>h15",cut1+cut2);
        h15->Draw("");
        h15->SetTitle("Energy of Mu^{-} (MC)");
        h15->SetXTitle("Energy of Mu^{-} (MC)");

	//TCanvas *c14 = new TCanvas("c14");
	c12->cd(2);
	hAnl->Draw("photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,1)>>h16",cut1+cut2);
	h16->Draw("");
        h16->SetTitle("Energy of Mu^{-} (Reconstructed)");
        h16->SetXTitle("Energy of Mu^{-} (Reconstructed)");

        //TCanvas *c15 = new TCanvas("c15");
        c12->cd(3);
	hAnl->Draw("lep1EMC:photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,1)>>h17",cut1+cut2);
        h17->Draw("colz");
        h17->SetTitle("Energy of Mu^{-} (MC:Reconstructed)");
        h17->SetXTitle("Energy of Mu^{-} (Reconstructed)");
        h17->SetYTitle("Energy of Mu^{-} (MC)");

        c12->cd(4);
        hAnl->Draw("(-lep1EMC+photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,1))/lep1EMC>>h18",cut1+cut2);
        h18->Draw("");
        h18->SetTitle("Energy Resolution of Mu^{-}");
        h18->SetXTitle("Energy Resolution of Mu^{-}");
        h18->SetYTitle("");

	
	TCanvas *c22 = new TCanvas("c22");
	c22->Divide(2,2);
        c22->cd(1);
	hAnl->Draw("lep2EMC>>h25",cut1+cut2);
        h25->Draw("");
        h25->SetTitle("Energy of Mu^{+} (MC)");
        h25->SetXTitle("Energy of Mu^{+} (MC)");

	//TCanvas *c8 = new TCanvas("c8");
	c22->cd(2);
	hAnl->Draw("photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,2)>>h26",cut1+cut2);
	h26->Draw("");
        h26->SetTitle("Energy of Mu^{+} (Reconstructed)");
        h26->SetXTitle("Energy of Mu^{+} (Reconstructed)");

        //TCanvas *c9 = new TCanvas("c9");
	c22->cd(3);
	hAnl->Draw("lep2EMC:photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,2)>>h27",cut1+cut2);
        h27->Draw("colz");
        h27->SetTitle("Energy of Mu^{+} (MC:Reconstructed)");
        h27->SetXTitle("Energy of Mu^{+} (Reconstructed)");
        h27->SetYTitle("Energy of Mu^{+} (MC)");

        c22->cd(4);
        hAnl->Draw("(-lep2EMC+photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,2))/lep2EMC>>h28",cut1+cut2);
        h28->Draw("");
        h28->SetTitle("Energy Resolution of Mu^{+}");
        h28->SetXTitle("Energy Resolution of Mu^{+}");
        h28->SetYTitle("");



        TCanvas *c31 = new TCanvas("c31");

        hAnl->Draw("ISRphotonEMC>>h31",cut1+cut2);
        h31->SetLineColor(kBlue);
        gPad->Update();
        TPaveStats *st3 = (TPaveStats*)h31->GetListOfFunctions()->FindObject("stats");

        hAnl->Draw("photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,3)>>h32",cut1+cut2);
        h32->SetLineColor(kRed);
        gPad->Update();
        TPaveStats *st4 = (TPaveStats*)h32->GetListOfFunctions()->FindObject("stats");

        st3->SetX1NDC(0.70);
        st3->SetX2NDC(0.90);
        st3->SetY1NDC(0.70);
        st3->SetY2NDC(0.90);
        st3->SetTextColor(kBlue);
        st4->SetX1NDC(0.70);
        st4->SetX2NDC(0.90);
        st4->SetY1NDC(0.50);
        st4->SetY2NDC(0.70);
        st4->SetTextColor(kRed);
        h31->SetTitle("Energy of ISR Photon");
        h31->SetXTitle("Energy of ISR Photon");
        h31->SetYTitle("");
        h31->Draw("");
        h32->Draw("same");



        TCanvas *c03 = new TCanvas("c03");
	hAnl->Draw("(photonEAnl-photonEMC)/photonEMC>>h41",cut1+cut2);
        h41->SetLineColor(kGreen+2);
        gPad->Update();
	TPaveStats *st1 = (TPaveStats*)h41->GetListOfFunctions()->FindObject("stats");

	hAnl->Draw("(-photonEMC+photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))/photonEMC>>h42",cut1+cut2);
        h42->SetLineColor(kRed);
	gPad->Update();
        TPaveStats *st2 = (TPaveStats*)h42->GetListOfFunctions()->FindObject("stats");
        
        st1->SetX1NDC(0.70);
        st1->SetX2NDC(0.90);
        st1->SetY1NDC(0.70);
        st1->SetY2NDC(0.90);
        st1->SetTextColor(kGreen+2);
	st2->SetX1NDC(0.70);
        st2->SetX2NDC(0.90);
        st2->SetY1NDC(0.50);
        st2->SetY2NDC(0.70);
        st2->SetTextColor(kRed);

	h41->SetTitle("Energy Resolution of Photon");
        h41->SetXTitle("Energy Resolution of Photon");
        h41->SetYTitle("");
        h41->Draw("");
        h42->Draw("same");


        TCanvas *c04 = new TCanvas("c04");
        
        hAnl->Draw("photonEMC>>h05",cut1+cut2);
        h05->SetLineColor(kBlue+2);
        gPad->Update();
        h05->SetTitle("Energy of Photon (MC)");
        h05->SetXTitle("Energy of Photon (MC)");
        TPaveStats *st5 = (TPaveStats*)h05->GetListOfFunctions()->FindObject("stats");


	hAnl->Draw("photonEAnl>>h01",cut1+cut2);
        h01->SetLineColor(kGreen+2);
        gPad->Update();
        TPaveStats *st6 = (TPaveStats*)h01->GetListOfFunctions()->FindObject("stats");

        hAnl->Draw("photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h06",cut1+cut2);
	h06->SetLineColor(kRed);
        gPad->Update();
        TPaveStats *st7 = (TPaveStats*)h06->GetListOfFunctions()->FindObject("stats");

        st5->SetX1NDC(0.20);
        st5->SetX2NDC(0.40);
        st5->SetY1NDC(0.70);
        st5->SetY2NDC(0.90);
        st5->SetTextColor(kBlue+2);
        st6->SetX1NDC(0.20);
        st6->SetX2NDC(0.40);
        st6->SetY1NDC(0.50);
        st6->SetY2NDC(0.70);
        st6->SetTextColor(kGreen+2);
        st7->SetX1NDC(0.20);
        st7->SetX2NDC(0.40);
        st7->SetY1NDC(0.30);
        st7->SetY2NDC(0.50);
        st7->SetTextColor(kRed);


        h05->SetTitle("Energy of Photon");
        h05->SetXTitle("Energy of Photon");

        h05->Draw("");
        h01->Draw("same");
        h06->Draw("same");
	

	TCanvas *c13 = new TCanvas("c13");
        hAnl->Draw("(lep1EAnl-lep1EMC)/lep1EMC>>h43",cut1+cut2);
        h43->SetLineColor(kGreen+2);
        gPad->Update();
        TPaveStats *st11 = (TPaveStats*)h43->GetListOfFunctions()->FindObject("stats");

        hAnl->Draw("(-lep1EMC+photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,1))/lep1EMC>>h44",cut1+cut2);
        h44->SetLineColor(kRed);
        gPad->Update();
        TPaveStats *st12 = (TPaveStats*)h44->GetListOfFunctions()->FindObject("stats");

        st11->SetX1NDC(0.70);
        st11->SetX2NDC(0.90);
        st11->SetY1NDC(0.70);
        st11->SetY2NDC(0.90);
        st11->SetTextColor(kGreen+2);
        st12->SetX1NDC(0.70);
        st12->SetX2NDC(0.90);
        st12->SetY1NDC(0.50);
        st12->SetY2NDC(0.70);
        st12->SetTextColor(kRed);

        h43->SetTitle("Energy Resolution of Mu^{-}");
        h43->SetXTitle("Energy Resolution of Mu^{-}");
        h43->SetYTitle("");
        h43->Draw("");
        h44->Draw("same");


        TCanvas *c14 = new TCanvas("c14");

        hAnl->Draw("lep1EMC>>h15",cut1+cut2);
        h15->SetLineColor(kBlue+2);
        gPad->Update();
        h15->SetTitle("Energy of Mu^{-} (MC)");
        h15->SetXTitle("Energy of Mu^{-} (MC)");
        TPaveStats *st15 = (TPaveStats*)h15->GetListOfFunctions()->FindObject("stats");


        hAnl->Draw("lep1EAnl>>h11",cut1+cut2);
        h11->SetLineColor(kGreen+2);
        gPad->Update();
        TPaveStats *st16 = (TPaveStats*)h11->GetListOfFunctions()->FindObject("stats");

        hAnl->Draw("photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,1)>>h16",cut1+cut2);
        h16->SetLineColor(kRed);
        gPad->Update();
        TPaveStats *st17 = (TPaveStats*)h16->GetListOfFunctions()->FindObject("stats");

        st15->SetX1NDC(0.20);
        st15->SetX2NDC(0.40);
        st15->SetY1NDC(0.70);
        st15->SetY2NDC(0.90);
        st15->SetTextColor(kBlue+2);
        st16->SetX1NDC(0.20);
        st16->SetX2NDC(0.40);
        st16->SetY1NDC(0.50);
        st16->SetY2NDC(0.70);
        st16->SetTextColor(kGreen+2);
        st17->SetX1NDC(0.20);
        st17->SetX2NDC(0.40);
        st17->SetY1NDC(0.30);
        st17->SetY2NDC(0.50);
        st17->SetTextColor(kRed);

        h15->SetTitle("Energy of Mu^{-}");
        h15->SetXTitle("Energy of Mu^{-}");

        h15->Draw("");
        h11->Draw("same");
        h16->Draw("same");



        TCanvas *c23 = new TCanvas("c23");
        hAnl->Draw("(lep2EAnl-lep2EMC)/lep2EMC>>h45",cut1+cut2);
        h45->SetLineColor(kGreen+2);
        gPad->Update();
        TPaveStats *st21 = (TPaveStats*)h45->GetListOfFunctions()->FindObject("stats");

        hAnl->Draw("(-lep2EMC+photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,2))/lep2EMC>>h46",cut1+cut2);
        h46->SetLineColor(kRed);
        gPad->Update();
        TPaveStats *st22 = (TPaveStats*)h46->GetListOfFunctions()->FindObject("stats");

        st21->SetX1NDC(0.70);
        st21->SetX2NDC(0.90);
        st21->SetY1NDC(0.70);
        st21->SetY2NDC(0.90);
        st21->SetTextColor(kGreen+2);
        st22->SetX1NDC(0.70);
        st22->SetX2NDC(0.90);
        st22->SetY1NDC(0.50);
        st22->SetY2NDC(0.70);
        st22->SetTextColor(kRed);

        h45->SetTitle("Energy Resolution of Mu^{+}");
        h45->SetXTitle("Energy Resolution of Mu^{+}");
        h45->SetYTitle("");
        h45->Draw("");
        h46->Draw("same");

        TCanvas *c24 = new TCanvas("c24");

        hAnl->Draw("lep2EMC>>h25",cut1+cut2);
        h25->SetLineColor(kBlue+2);
        gPad->Update();
        h25->SetTitle("Energy of Mu^{+} (MC)");
        h25->SetXTitle("Energy of Mu^{+} (MC)");
        TPaveStats *st25 = (TPaveStats*)h25->GetListOfFunctions()->FindObject("stats");


        hAnl->Draw("lep2EAnl>>h21",cut1+cut2);
        h21->SetLineColor(kGreen+2);
        gPad->Update();
        TPaveStats *st26 = (TPaveStats*)h21->GetListOfFunctions()->FindObject("stats");

        hAnl->Draw("photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,2)>>h26",cut1+cut2);
        h26->SetLineColor(kRed);
        gPad->Update();
        TPaveStats *st27 = (TPaveStats*)h26->GetListOfFunctions()->FindObject("stats");

        st25->SetX1NDC(0.20);
        st25->SetX2NDC(0.40);
        st25->SetY1NDC(0.70);
        st25->SetY2NDC(0.90);
        st25->SetTextColor(kBlue+2);
        st26->SetX1NDC(0.20);
        st26->SetX2NDC(0.40);
        st26->SetY1NDC(0.50);
        st26->SetY2NDC(0.70);
        st26->SetTextColor(kGreen+2);
        st27->SetX1NDC(0.20);
        st27->SetX2NDC(0.40);
        st27->SetY1NDC(0.30);
        st27->SetY2NDC(0.50);
        st27->SetTextColor(kRed);


        h25->SetTitle("Energy of Mu^{+}");
        h25->SetXTitle("Energy of Mu^{+}");

        h25->Draw("");
        h21->Draw("same");
        h26->Draw("same");

	TCanvas *c47 = new TCanvas("c47");
        hAnl->Draw("photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0):photonEAnl>>h47",cut1+cut2);
	h47->SetTitle("");
        h47->SetXTitle("PFO Energy of Photon");
        h47->SetYTitle("Reconstructed Energy of Photon");
	h47->Draw("colz");

        TCanvas *c51 = new TCanvas("c51");

/*        hAnl->Draw("photonEAnl:photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h03",cut1+cut2);
        h03->Draw("colz");

        h03->SetTitle("Energy of Photon (Anl:Reconstructed)");
        h03->SetXTitle("Energy of Photon (Reconstructed)");
        h03->SetYTitle("Energy of Photon (Anl)");
*/
        hAnl->Draw("photonEAnl>>h51",cut1+cut2);
        h51->SetLineColor(kGreen);
        gPad->Update();
        TPaveStats *st51 = (TPaveStats*)h51->GetListOfFunctions()->FindObject("stats");

        hAnl->Draw("photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0)>>h52",cut1+cut2);
        h52->SetLineColor(kRed);
        gPad->Update();
        TPaveStats *st52 = (TPaveStats*)h52->GetListOfFunctions()->FindObject("stats");

        st51->SetX1NDC(0.70);
        st51->SetX2NDC(0.90);
        st51->SetY1NDC(0.70);
        st51->SetY2NDC(0.90);
        st51->SetTextColor(kBlue);
        st52->SetX1NDC(0.70);
        st52->SetX2NDC(0.90);
        st52->SetY1NDC(0.50);
        st52->SetY2NDC(0.70);
        st52->SetTextColor(kRed);
        h51->SetTitle("");
        h51->SetXTitle("Energy of Photon");
        h51->SetYTitle("");
        h51->Draw("");
        h52->Draw("same");


	}
