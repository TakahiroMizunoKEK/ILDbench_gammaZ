
#include "/home/ilc/mizunot/bin/root_macros/style.C"
#include "photonERec6.cxx"
#include "CalibFactor.C"

void GammaCalibp0_68() {

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

	Int_t nbinx   = 200;	
	Double_t xmin = -.2; 
	Double_t xmax = .2; 	

	//Int_t nbiny   = 520;	
	//Double_t ymin = -10.; 
	//Double_t ymax = 510.; 	

        TCanvas *c1 = new TCanvas("c1","",0,0,600,600);
        //TCanvas *c1 = new TCanvas("c1","",0,0,250,250);
        c1->SetRightMargin(.05);
        c1->SetLeftMargin(.2);


        TH1D *h08 = new TH1D("h08","",200.,xmin,xmax);
        TH1D *h09 = new TH1D("h09","",200.,xmin,xmax);
        TH1D *h10 = new TH1D("h10","",200.,xmin,xmax);

        TH1D *h08l = new TH1D("h08l","",200.,xmin,xmax);
        TH1D *h09l = new TH1D("h09l","",200.,xmin,xmax);
        TH1D *h10l = new TH1D("h10l","",200.,xmin,xmax);
        TH1D *h08r = new TH1D("h08r","",200.,xmin,xmax);
        TH1D *h09r = new TH1D("h09r","",200.,xmin,xmax);
        TH1D *h10r = new TH1D("h10r","",200.,xmin,xmax);


	TCut cut1 = "pdg0==13 && abs(mzgen-91.2)<10";
	TCut cut3 = "coneen > -0.5";
	TCut cut4 = "abs(sin(photonphiAnl))>=.1";
	TCut cut6 = "abs(cos(photonthetaAnl))<=.95";
	TCut cut2 = cut3+cut4+cut6;



        hAnll->Draw("(photonEAnl-photonEMC)/photonEMC>>h08l",cut1+cut2);
        hAnlr->Draw("(photonEAnl-photonEMC)/photonEMC>>h08r",cut1+cut2);
	*h08= (*h08l) * wl + (*h08r) * wr;
        h08->SetLineColor(kAzure+10);
        h08->SetMarkerColor(kAzure+10);
        gPad->Update();
        TPaveStats *st4 = (TPaveStats*)h08->GetListOfFunctions()->FindObject("stats");


        hAnll->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h09l",cut1+cut2);
        hAnlr->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h09r",cut1+cut2);
	*h09= (*h09l) * wl + (*h09r) * wr;
        //h09->SetTitle("(E-E_{MC})/E_{MC} of Photon");
        //h09->SetXTitle("Energy Resolution of Photon");
	h09->GetYaxis()->SetTitleOffset(1.5);
        h09->SetYTitle("Events");
        h09->SetXTitle("(E_{#gamma}-E_{#gamma}^{MC})/E_{#gamma}^{MC}");
        h09->GetYaxis()->SetLabelSize(0.05);
        h09->GetXaxis()->SetLabelSize(0.05);
        h09->SetMarkerColor(kAzure);
        h09->SetLineColor(kAzure);

        gPad->Update();
        TPaveStats *st6 = (TPaveStats*)h09->GetListOfFunctions()->FindObject("stats");

        hAnll->Draw("(photonEAnl*CalibFactor(abs(cos(photonthetaAnl)))-photonEMC)/photonEMC>>h10l",cut1+cut2);
        hAnlr->Draw("(photonEAnl*CalibFactor(abs(cos(photonthetaAnl)))-photonEMC)/photonEMC>>h10r",cut1+cut2);
        *h10= (*h10l) * wl + (*h10r) * wr;
        h10->SetLineColor(kGreen-3);
        h10->SetMarkerColor(kGreen-3);
        gPad->Update();
        TPaveStats *st10 = (TPaveStats*)h10->GetListOfFunctions()->FindObject("stats");

        h09->Draw("");
        h08->Draw("same");
        //h10->Draw("same");

        TLegend *legend = new TLegend( 0.63, 0.66, 0.81, 0.90) ;
        legend->AddEntry( h09, "Angular Method" , "p") ;
        legend->AddEntry( h08, "PFO" , "p") ;
	legend->AddEntry((TObject*)0,"IDR-L model","");
        //legend->AddEntry( h10, "Calibrated PFO" , "p") ;
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
