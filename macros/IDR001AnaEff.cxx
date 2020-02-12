
#include "/home/ilc/mizunot/bin/root_macros/style.C"


void IDR001AnaEff() {

        stringstream filest;
        filest << "2f_z_l.eL.pR.mILD_l5_o1_v02.root" << ends;

        TFile *f = new TFile(filest.str().data());
	
	setILDStyle();
	//gStyle->SetPadLeftMargin(0.15);

        TCanvas *c1 = new TCanvas("c1","",0,0,600,600);	
        c1->SetRightMargin(.05);
        c1->SetLeftMargin(.25);

	//TFile *f = new TFile("2f_z_l.eL.pR.mILD_o1_v05.root");

        TNtuple *hGen = static_cast<TNtuple *>(f->Get("hGen"));
        TNtuple *hAnl = static_cast<TNtuple *>(f->Get("hAnl"));	
	/*Int_t nbinx=100;	
	Double_t xmin = -1.; 
	Double_t xmax = 1.; 	

	Int_t nbiny=100;	
	Double_t ymin = -0.05; 
	Double_t ymax = 0.05;*/ 	

	TH1D *h1 = new TH1D("h1","",200,0,500);
	h1->SetFillColor(kTeal);
	hGen->Draw("mz>>h1","");

	h1->SetTitle("M(#mu^{+}#mu^{-}) distribution");
	h1->SetXTitle("M(#mu^{+}#mu^{-}) (GeV)");
        h1->SetYTitle("Entries/2.5 GeV");
	h1->GetYaxis()->SetTitleOffset(1.8); 

	TH1D *h2 = new TH1D("h2","",200,0,500);
        h2->SetFillColor(kViolet);
        hAnl->Draw("mzgen>>h2","","sames");

	TLatex *   tex = new TLatex(250,65000,"ILD preliminary");
	tex->SetTextFont(62);
	tex->Draw();


        TLegend *legend = new TLegend( 0.60, 0.66, 0.78, 0.81) ;
        legend->AddEntry( h1, "Generated" , "f") ;
        legend->AddEntry( h2, "Selected" , "f") ;
        legend->SetFillColor(0);
        legend->SetTextSize(0.04);
	legend->Draw() ;

	/*gStyle->SetOptStat();
        TPaveStats *st1 = (TPaveStats*)h1->GetListOfFunctions()->FindObject("stats");
        st1->SetX1NDC(0.50);
        st1->SetX2NDC(0.70);
        st1->SetY1NDC(0.70);
        st1->SetY2NDC(0.90);
	TPaveStats *st2 = (TPaveStats*)h2->FindObject("stats");
        st2->SetX1NDC(0.70);
        st2->SetX2NDC(0.90);
        st2->SetY1NDC(0.70);
        st2->SetY2NDC(0.90);

	c1->Modified();*/

}
