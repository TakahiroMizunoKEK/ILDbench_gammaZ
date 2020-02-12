
#include "/home/ilc/mizunot/bin/root_macros/style.C"
#include "photonERec.cxx"
#include "photonERec3.cxx"
#include "photonERec4.cxx"
#include "photonERec4B.cxx"
#include "photonERec5.cxx"
#include "photonERec50.cxx"
#include "photonERec6.cxx"
#include "CalibFactor.C"

//method comparison method 1~4' for four different conditions

void GammaCalibp0_64() {

        stringstream filestl;
        stringstream filestr;
        
        filestl << "../root_merge.mILD_l5_o1_v02/"
               << "2f_z_l.eL.pR.mILD_l5_o1_v02.root" << ends;

        filestr << "../root_merge.mILD_l5_o1_v02/"
               << "2f_z_l.eR.pL.mILD_l5_o1_v02.root" << ends;

        TFile *fl = new TFile(filestl.str().data());
        TFile *fr = new TFile(filestr.str().data());

	setILDStyle();
	//
	//gStyle->SetPadRightMargin(2.0);
	//gStyle->SetPadRightMargin(1.0);
	/*gStyle->SetOptStat(1000001110);
        gStyle->SetStatH(0.15);
        gStyle->SetStatX(0.9);
        gStyle->SetStatY(0.9);
	gStyle->SetOptFit();
*/
        TNtuple *hGenl = static_cast<TNtuple *>(fl->Get("hGen"));
        TNtuple *hAnll = static_cast<TNtuple *>(fl->Get("hAnl"));
        TNtuple *hGenr = static_cast<TNtuple *>(fr->Get("hGen"));
        TNtuple *hAnlr = static_cast<TNtuple *>(fr->Get("hAnl"));
	
        double expl=5547.58 * 0.62 * 1600.;
        double expr=4344.86 * 0.62 * 1600.;
	double genl=hGenl->GetEntries();
	double genr=hGenr->GetEntries();
        double wl=expl/genl;  
        double wr=expr/genr;
        double nexp=expl+expr;

	double Ecm = 500.;
/*
	Int_t nbinx   = 200;	
	Double_t xmin = -.2; 
	Double_t xmax = .2; 	
*/
	Int_t nbinx   = 60;	
	Double_t xmin = -.06; 
	Double_t xmax = .06; 	

	//Int_t nbiny   = 520;	
	//Double_t ymin = -10.; 
	//Double_t ymax = 510.; 	

        TCanvas *c1 = new TCanvas("c1","",0,0,600,600);
        //TCanvas *c1 = new TCanvas("c1","",0,0,250,250);
        c1->SetRightMargin(.05);
        c1->SetLeftMargin(.2);


        TH1D *h08 = new TH1D("h08","",nbinx,xmin,xmax);
        TH1D *h09 = new TH1D("h09","",nbinx,xmin,xmax);
        TH1D *h10 = new TH1D("h10","",nbinx,xmin,xmax);
        TH1D *h001 = new TH1D("h001","",nbinx,xmin,xmax);
        TH1D *h002 = new TH1D("h002","",nbinx,xmin,xmax);
        TH1D *h003 = new TH1D("h003","",nbinx,xmin,xmax);
        TH1D *h032 = new TH1D("h032","",nbinx,xmin,xmax);
        TH1D *h041 = new TH1D("h041","",nbinx,xmin,xmax);
        TH1D *h042 = new TH1D("h042","",nbinx,xmin,xmax);

        TH1D *h08l = new TH1D("h08l","",nbinx,xmin,xmax);
        TH1D *h09l = new TH1D("h09l","",nbinx,xmin,xmax);
        TH1D *h10l = new TH1D("h10l","",nbinx,xmin,xmax);
        TH1D *h08r = new TH1D("h08r","",nbinx,xmin,xmax);
        TH1D *h09r = new TH1D("h09r","",nbinx,xmin,xmax);
        TH1D *h10r = new TH1D("h10r","",nbinx,xmin,xmax);
        TH1D *h001l = new TH1D("h001l","",nbinx,xmin,xmax);
        TH1D *h002l = new TH1D("h002l","",nbinx,xmin,xmax);
        TH1D *h003l = new TH1D("h003l","",nbinx,xmin,xmax);
        TH1D *h032l = new TH1D("h032l","",nbinx,xmin,xmax);
        TH1D *h041l = new TH1D("h041l","",nbinx,xmin,xmax);
        TH1D *h042l = new TH1D("h042l","",nbinx,xmin,xmax);
        TH1D *h001r = new TH1D("h001r","",nbinx,xmin,xmax);
        TH1D *h002r = new TH1D("h002r","",nbinx,xmin,xmax);
        TH1D *h003r = new TH1D("h003r","",nbinx,xmin,xmax);
        TH1D *h032r = new TH1D("h032r","",nbinx,xmin,xmax);
        TH1D *h041r = new TH1D("h041r","",nbinx,xmin,xmax);
        TH1D *h042r = new TH1D("h042r","",nbinx,xmin,xmax);


	TCut cut1 = "pdg0==13 && abs(mzgen-91.2)<10";
	TCut cut3 = "coneen > -0.5";
	TCut cut4 = "abs(sin(photonphiAnl))>=.1";
	TCut cut6 = "abs(cos(photonthetaAnl))<=.95";
	//TCut cut2 = cut3+cut4+cut6;
	TCut cut2 = cut3;



        /*hAnll->Draw("(photonEAnl-photonEMC)/photonEMC>>h08l",cut1+cut2);
        hAnlr->Draw("(photonEAnl-photonEMC)/photonEMC>>h08r",cut1+cut2);
	*h08= (*h08l) * wl + (*h08r) * wr;
        h08->SetLineColor(kAzure+10);
        h08->SetMarkerColor(kAzure+10);
        gPad->Update();
        TPaveStats *st4 = (TPaveStats*)h08->GetListOfFunctions()->FindObject("stats");
*/


        hAnll->Draw("(-photonEMC+photonERec(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))/photonEMC>>h001l",cut1+cut2);
        hAnlr->Draw("(-photonEMC+photonERec(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))/photonEMC>>h001r",cut1+cut2);
	*h001= (*h001l) * wl + (*h001r) * wr;
	h001->GetYaxis()->SetTitleOffset(1.5);
        h001->SetYTitle("Events");
        h001->SetXTitle("(E_{#gamma}-E_{#gamma}^{MC})/E_{#gamma}^{MC}");
        h001->GetYaxis()->SetLabelSize(0.05);
        h001->GetXaxis()->SetLabelSize(0.05);
        h001->SetMarkerColor(kGray+1);
        h001->SetLineColor(kGray+1);

        hAnll->Draw("(-photonEMC+photonERec3(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))/photonEMC>>h002l",cut1+cut2);
        hAnlr->Draw("(-photonEMC+photonERec3(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))/photonEMC>>h002r",cut1+cut2);
	*h002= (*h002l) * wl + (*h002r) * wr;
	h002->GetYaxis()->SetTitleOffset(1.5);
        h002->SetYTitle("Events");
        h002->SetXTitle("(E_{#gamma}-E_{#gamma}^{MC})/E_{#gamma}^{MC}");
        h002->GetYaxis()->SetLabelSize(0.05);
        h002->GetXaxis()->SetLabelSize(0.05);
        h002->SetMarkerColor(kViolet);
        h002->SetLineColor(kViolet);

        hAnll->Draw("(-photonEMC+photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))/photonEMC>>h003l",cut1+cut2);
        hAnlr->Draw("(-photonEMC+photonERec4(500.,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,0))/photonEMC>>h003r",cut1+cut2);
	*h003= (*h003l) * wl + (*h003r) * wr;
	h003->GetYaxis()->SetTitleOffset(1.5);
        h003->SetYTitle("Events");
        h003->SetXTitle("(E_{#gamma}-E_{#gamma}^{MC})/E_{#gamma}^{MC}");
        h003->GetYaxis()->SetLabelSize(0.05);
        h003->GetXaxis()->SetLabelSize(0.05);
        h003->SetMarkerColor(kAzure-3);
        h003->SetLineColor(kAzure-3);

        hAnll->Draw("(-photonEMC+photonERec4B(lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,lep1EAnl,lep2EAnl,photonEAnl))/photonEMC>>h032l",cut1+cut2);
        hAnlr->Draw("(-photonEMC+photonERec4B(lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,lep1EAnl,lep2EAnl,photonEAnl))/photonEMC>>h032r",cut1+cut2);
	*h032= (*h032l) * wl + (*h032r) * wr;
	h032->GetYaxis()->SetTitleOffset(1.5);
        h032->SetYTitle("Events");
        h032->SetXTitle("(E_{#gamma}-E_{#gamma}^{MC})/E_{#gamma}^{MC}");
        h032->GetYaxis()->SetLabelSize(0.05);
        h032->GetXaxis()->SetLabelSize(0.05);
        h032->SetMarkerColor(kOrange-3);
        h032->SetLineColor(kOrange-3);


        hAnll->Draw("(-photonEMC+photonERec50(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h041l",cut1+cut2);
        hAnlr->Draw("(-photonEMC+photonERec50(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h041r",cut1+cut2);
	*h041= (*h041l) * wl + (*h041r) * wr;
	h041->GetYaxis()->SetTitleOffset(1.5);
        h041->SetYTitle("Events");
        h041->SetXTitle("(E_{#gamma}-E_{#gamma}^{MC})/E_{#gamma}^{MC}");
        h041->GetYaxis()->SetLabelSize(0.05);
        h041->GetXaxis()->SetLabelSize(0.05);
        h041->SetMarkerColor(kGreen+1);
        h041->SetLineColor(kGreen+1);

        hAnll->Draw("(-photonEMC+photonERec5(lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,photonEAnl))/photonEMC>>h042l",cut1+cut2);
        hAnlr->Draw("(-photonEMC+photonERec5(lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,photonEAnl))/photonEMC>>h042r",cut1+cut2);
	*h042= (*h042l) * wl + (*h042r) * wr;
	h042->GetYaxis()->SetTitleOffset(1.5);
        h042->SetYTitle("Events");
        h042->SetXTitle("(E_{#gamma}-E_{#gamma}^{MC})/E_{#gamma}^{MC}");
        h042->GetYaxis()->SetLabelSize(0.05);
        h042->GetXaxis()->SetLabelSize(0.05);
        h042->SetMarkerColor(kYellow+1);
        h042->SetLineColor(kYellow+1);



        hAnll->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h09l",cut1+cut2);
        hAnlr->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h09r",cut1+cut2);
	*h09= (*h09l) * wl + (*h09r) * wr;
	h09->GetYaxis()->SetTitleOffset(1.5);
        h09->SetYTitle("Events");
        h09->SetXTitle("(E_{#gamma}-E_{#gamma}^{MC})/E_{#gamma}^{MC}");
        h09->GetYaxis()->SetLabelSize(0.05);
        h09->GetXaxis()->SetLabelSize(0.05);
        //h09->SetMarkerColor(kOrange+8);
        h09->SetMarkerColor(kRed);
        //h09->SetLineColor(kOrange+8);
        h09->SetLineColor(kRed);
        //h09->SetMarkerColor(kGreen+1);
        //h09->SetLineColor(kGreen+1);

        gPad->Update();
        TPaveStats *st6 = (TPaveStats*)h09->GetListOfFunctions()->FindObject("stats");









        hAnll->Draw("(photonEAnl*CalibFactor(abs(cos(photonthetaAnl)))-photonEMC)/photonEMC>>h10l",cut1+cut2);
        hAnlr->Draw("(photonEAnl*CalibFactor(abs(cos(photonthetaAnl)))-photonEMC)/photonEMC>>h10r",cut1+cut2);
        *h10= (*h10l) * wl + (*h10r) * wr;
        h10->SetLineColor(kGreen-3);
        h10->SetMarkerColor(kGreen-3);
        gPad->Update();
        TPaveStats *st10 = (TPaveStats*)h10->GetListOfFunctions()->FindObject("stats");

        h042->Draw("");
        h09->Draw("same");
        //h09->Draw("");
        //h08->Draw("same");
        //h10->Draw("same");
        h001->Draw("same");
        h002->Draw("same");
        h003->Draw("same");
        h032->Draw("same");
        h041->Draw("same");
        //h042->Draw("same");
        h09->Draw("same");

        TLegend *legend = new TLegend( 0.63, 0.66, 0.81, 0.90) ;
        //legend->AddEntry( h08, "PFO" , "p") ;
        //legend->AddEntry( h10, "Calibrated PFO" , "p") ;
        legend->AddEntry( h001, "Method 1" , "p") ;
        legend->AddEntry( h002, "Method 2" , "p") ;
        legend->AddEntry( h003, "Method 3" , "p") ;
        legend->AddEntry( h032, "Method 3B" , "p") ;
        legend->AddEntry( h041, "Method 4" , "p") ;
        legend->AddEntry( h042, "Method 4B" , "p") ;
        legend->AddEntry( h09, "Method 4'" , "p") ;
        legend->SetFillColor(0);
        legend->SetTextSize(0.04);
	legend->Draw() ;


TLatex *   tex = new TLatex(-0.19,26000,"ILD preliminary");
tex->SetTextFont(62);
tex->Draw();
//TLatex * tex2 = new TLatex(-0.15,26000,"preliminary");
//tex2->SetTextFont(62);
//tex2->Draw();
//tex->SetTextSize(0.07);
//tex->SetLineWidth(2);



	}
