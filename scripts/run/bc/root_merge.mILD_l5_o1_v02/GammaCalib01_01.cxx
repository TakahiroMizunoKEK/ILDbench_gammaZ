
#include "/home/ilc/mizunot/bin/root_macros/style.C"


void GammaCalib01_01() {

        stringstream filest;
        filest << "../root_merge.mILD_l5_o1_v02/"
               << "2f_z_l.eL.pR.mILD_l5_o1_v02.root" << ends;

        TFile *f = new TFile(filest.str().data());
	
	setILDStyle();
	gStyle->SetPadRightMargin(1.0);
	gStyle->SetOptFit(111);

	TCanvas *c1 = new TCanvas("c1");

        TNtuple *hGen = static_cast<TNtuple *>(f->Get("hGen"));
        TNtuple *hAnl = static_cast<TNtuple *>(f->Get("hAnl"));
	
	Int_t nbinx=250;	
	Double_t xmin = 0.; 
	Double_t xmax = 250.; 	

	Int_t nbiny=250;	
	Double_t ymin = 0.; 
	Double_t ymax = 250; 	

	TH1D *h1 = new TH1D("h1","",nbinx,-600.,600.);
	TH1D *h2 = new TH1D("h2","",nbinx,-600.,600.);
        TH2D *h3 = new TH2D("h3","",nbinx,xmin,xmax,nbiny,ymin,ymax);

	hAnl->Draw("lep1EMC>>h1","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.75");
        h1->Draw("");


	TCanvas *c2 = new TCanvas("c2");
	//hAnl->Draw("-500.*cosphoton*(coslep2*sinlep1-sinlep2*coslep1)*(cosphoton*sinlep2-sinphoton*coslep2)/(coslep2*sinlep1-sinlep2*coslep1)/((coslep1-cosphoton)*(cosphoton*sinlep2-sinphoton*coslep2)+(coslep2-cosphoton)*(cosphoton*sinlep1-sinphoton*coslep1))>>h2","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.75");
	hAnl->Draw("500.*cosphoton*(coslep2*sinphoton-sinlep2*cosphoton)/((coslep1-cosphoton)*(cosphoton*sinlep2-sinphoton*coslep2)+(coslep2-cosphoton)*(cosphoton*sinlep1-sinphoton*coslep1))>>h2","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.75");
	h2->Draw("");



        TCanvas *c3 = new TCanvas("c3");
	//hAnl->Draw("lep1EMC:-500.*cosphoton*(coslep2*sinlep1-sinlep2*coslep1)*(cosphoton*sinlep2-sinphoton*coslep2)/(coslep2*sinlep1-sinlep2*coslep1)/((coslep1-cosphoton)*(cosphoton*sinlep2-sinphoton*coslep2)+(coslep2-cosphoton)*(cosphoton*sinlep1-sinphoton*coslep1))>>h3","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.75");
	hAnl->Draw("lep1EMC:500.*cosphoton*(coslep2*sinphoton-sinlep2*cosphoton)/((coslep1-cosphoton)*(cosphoton*sinlep2-sinphoton*coslep2)+(coslep2-cosphoton)*(cosphoton*sinlep1-sinphoton*coslep1))>>h3","pdg0==13 && abs(mzgen-91.2)<10 && abs(coslep1)>0.0 && abs(coslep1)<0.75");
	//h3->SetYTitle("(P_t^{Rec}_{#mu}-P_t^{MC})/(P_t^{MC})^{2}");
	//h3->SetXTitle("P_t^{MC}");
       
	//TH2D *h1 = static_cast<TH2D *>(gROOT ->FindObject("h1"));
        h3->Draw("colz");

}
