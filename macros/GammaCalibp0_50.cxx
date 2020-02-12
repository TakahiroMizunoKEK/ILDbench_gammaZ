
#include "/home/ilc/mizunot/bin/root_macros/style.C"
#include "PhotonCase4SigmaTheta20.cxx"
#include "PhotonCase4SigmaPhi40.cxx"
#include "PhotonCase4SigmaTheta20s.cxx"
#include "PhotonCase4SigmaPhi40s.cxx"



void GammaCalibp0_50() {

        stringstream filestll;
        stringstream filestlr;
        stringstream filestsl;
        stringstream filestsr;

        filestll << "../root_merge.mILD_l5_o1_v02/"
               << "2f_z_l.eL.pR.mILD_l5_o1_v02.root" << ends;

        filestlr << "../root_merge.mILD_l5_o1_v02/"
               << "2f_z_l.eR.pL.mILD_l5_o1_v02.root" << ends;

        filestsl << "../root_merge.mILD_s5_o1_v02/"
               << "2f_z_l.eL.pR.mILD_s5_o1_v02.root" << ends;

        filestsr << "../root_merge.mILD_s5_o1_v02/"
               << "2f_z_l.eR.pL.mILD_s5_o1_v02.root" << ends;

        TFile *fll = new TFile(filestll.str().data());
        TFile *flr = new TFile(filestlr.str().data());
        TFile *fsl = new TFile(filestsl.str().data());
        TFile *fsr = new TFile(filestsr.str().data());
	
	
	setILDStyle();
	//gStyle->SetPadRightMargin(1.0);
	//gStyle->SetPadRightMargin(1.0);
	gStyle->SetOptStat(1000001110);
        gStyle->SetStatH(0.15);
        gStyle->SetStatW(0.15);
        gStyle->SetStatX(0.9);
        gStyle->SetStatY(0.9);
	gStyle->SetOptFit();

        TNtuple *hGenll = static_cast<TNtuple *>(fll->Get("hGen"));
        TNtuple *hAnlll = static_cast<TNtuple *>(fll->Get("hAnl"));
        TNtuple *hGenlr = static_cast<TNtuple *>(flr->Get("hGen"));
        TNtuple *hAnllr = static_cast<TNtuple *>(flr->Get("hAnl"));
        TNtuple *hGensl = static_cast<TNtuple *>(fsl->Get("hGen"));
        TNtuple *hAnlsl = static_cast<TNtuple *>(fsl->Get("hAnl"));
        TNtuple *hGensr = static_cast<TNtuple *>(fsr->Get("hGen"));
        TNtuple *hAnlsr = static_cast<TNtuple *>(fsr->Get("hAnl"));
	

        double expl=5547.58 * 0.62 * 1600.;
        double expr=4344.86 * 0.62 * 1600.;
	double genll=hGenll->GetEntries();
	double genlr=hGenlr->GetEntries();
	double gensl=hGensl->GetEntries();
	double gensr=hGensr->GetEntries();
        double wll=expl/genll;  
        double wlr=expr/genlr;
        double wsl=expl/gensl;  
        double wsr=expr/gensr;
        double nexp=expl+expr;

	
	double Ecm = 500.;

	Int_t nbinx   = 520;	
	Double_t xmin = -10.; 
	Double_t xmax = 510.; 	

	Int_t nbiny   = 520;	
	Double_t ymin = -10.; 
	Double_t ymax = 510.; 	


	TCut cut1 = "pdg0==13 && abs(mzgen-91.2)<10";
	TCut cut3 = "coneen > -0.5";
	TCut cut4 = "abs(coslep1)<0.75 && abs(coslep2)<0.75";
        //TCut cut2 = cut3+cut4;
        TCut cut2 = cut3;
        TCut cut6 = "abs(sin(photonphiMC))<=1.";

	        cout << "02" << endl;
	const int kNhist = 15;
	TCut cutv[kNhist];

	cutv[0] = "abs(cos(photonthetaMC))<0.2";
	cutv[1] = "abs(cos(photonthetaMC))>=0.2 && abs(cos(photonthetaMC))<0.4";
	cutv[2] = "abs(cos(photonthetaMC))>=0.4 && abs(cos(photonthetaMC))<0.6";
	cutv[3] = "abs(cos(photonthetaMC))>=0.6 && abs(cos(photonthetaMC))<0.8";
	cutv[4] = "abs(cos(photonthetaMC))>=0.8 && abs(cos(photonthetaMC))<0.9";
	cutv[5] = "abs(cos(photonthetaMC))>=0.9";

        /*cutv[6]  = "photonphiMC<3.14*(-5.)/7.";
        cutv[7]  = "photonphiMC>=3.14*(-5.)/7. && photonphiMC<3.14*(-3.)/7.";
        cutv[8]  = "photonphiMC>=3.14*(-3.)/7. && photonphiMC<3.14*(-1.)/7.";
        cutv[9]  = "photonphiMC>=3.14*(-1.)/7. && photonphiMC<3.14*(1.)/7.";
        cutv[10] = "photonphiMC>=3.14*(1.)/7. && photonphiMC<3.14*(3.)/7.";
        cutv[11] = "photonphiMC>=3.14*(3.)/7. && photonphiMC<3.14*(5.)/7.";
        cutv[12] = "photonphiMC>=3.14*(5.)/7.";
*/
        cutv[6]  = "photonphiMC<-2.";
        cutv[7]  = "photonphiMC>=-2. && photonphiMC<-1.";
        cutv[8]  = "photonphiMC>=-1. && photonphiMC<-.3";
        cutv[9]  = "photonphiMC>=-.3 && photonphiMC<-.1";
        cutv[10] = "photonphiMC>=-.1 && photonphiMC<.1";
        cutv[11] = "photonphiMC>=.1 && photonphiMC<.3";
        cutv[12] = "photonphiMC>=.3 && photonphiMC<1.";
        cutv[13] = "photonphiMC>=1. && photonphiMC<2.";
        cutv[14] = "photonphiMC>=2";

	const double kXmin = -.01;
	const double kXmax = .04;

	const int histNo1st = 11;

	double ange[kNhist],sig[kNhist],sige[kNhist],ste[kNhist],stee[kNhist],numtl[kNhist];
	//double ang[] = {.1,.3,.5,.7,.85,.95,3.14*(-6.)/7.,3.14*(-4.)/7.,3.14*(-2.)/7.,0.,3.14*(2.)/7.,3.14*(4.)/7.,3.14*(6.)/7.};
	double ang[] = {.1,.3,.5,.7,.85,.95,-2.57,-1.5,-0.65,-0.2,0.,0.2,0.65,1.5,2.57};
	

	for (int i=0;i<kNhist;i++){
	        stringstream hnamel;	
	        stringstream hnamell;	
	        stringstream hnamelr;	
		hnamel<<"hl"<<i+histNo1st<<ends;
		hnamell<<"hll"<<i+histNo1st<<ends;
		hnamelr<<"hlr"<<i+histNo1st<<ends;
        	TH1D *hpl = new TH1D(hnamel.str().data(),"",50.,-.2,.2);
        	TH1D *hpll = new TH1D(hnamell.str().data(),"",50.,-.2,.2);
        	TH1D *hplr = new TH1D(hnamelr.str().data(),"",50.,-.2,.2);
	        stringstream hnames;	
	        stringstream hnamesl;	
	        stringstream hnamesr;	
		hnames<<"hs"<<i+histNo1st<<ends;
		hnamesl<<"hsl"<<i+histNo1st<<ends;
		hnamesr<<"hsr"<<i+histNo1st<<ends;
        	TH1D *hps = new TH1D(hnames.str().data(),"",50.,-.2,.2);
        	TH1D *hpsl = new TH1D(hnamesl.str().data(),"",50.,-.2,.2);
        	TH1D *hpsr = new TH1D(hnamesr.str().data(),"",50.,-.2,.2);

		stringstream cnamel;
		cnamel<<"cl"<<i+histNo1st<<ends;
	        TCanvas *cpl = new TCanvas(cnamel.str().data(),cnamel.str().data());

		stringstream iteml,itemll,itemlr;
		//item << "(-photonEMC+photonEAnl)/photonEMC>>" << hname.str().data() << ends;
		itemll << "(-photonEMC+photonEAnl)/photonEMC>>" << hnamell.str().data() << ends;
		itemlr << "(-photonEMC+photonEAnl)/photonEMC>>" << hnamelr.str().data() << ends;
	        hAnlll->Draw(itemll.str().data(),cut1+cut2+cutv[i]);
	        hAnllr->Draw(itemlr.str().data(),cut1+cut2+cutv[i]);
		*hpl= (*hpll) * wll + (*hplr) * wlr;
		
		hpl->SetTitle("Energy Resolution of Photon");
        	hpl->SetXTitle("Energy Resolution of Photon");
        	hpl->SetYTitle("");
        	hpl->Draw("");

#if 0
		stringstream cname;
		cname<<"c"<<i+histNo1st<<ends;
	        TCanvas *cp = new TCanvas(cname.str().data(),cname.str().data());

		stringstream item,iteml,itemr;
		//item << "(-photonEMC+photonEAnl)/photonEMC>>" << hname.str().data() << ends;
		iteml << "(-photonEMC+photonEAnl)/photonEMC>>" << hnamel.str().data() << ends;
		itemr << "(-photonEMC+photonEAnl)/photonEMC>>" << hnamer.str().data() << ends;
	        hAnll->Draw(iteml.str().data(),cut1+cut2+cutv[i]);
	        hAnlr->Draw(itemr.str().data(),cut1+cut2+cutv[i]);
		*hp= (*hpl) * wl + (*hpr) * wr;
		
		hp->SetTitle("Energy Resolution of Photon");
        	hp->SetXTitle("Energy Resolution of Photon");
        	hp->SetYTitle("");
        	hp->Draw("");

#endif			

                stringstream fnamel;
                fnamel<<"fl"<<i+histNo1st<<ends;
	        TF1 *fpl = new TF1(fnamel.str().data(),"gaus");
	        fpl->SetLineColor(kRed);
	        hpl->Fit(fnamel.str().data(),"Q","",kXmin,kXmax);
		double mean  = hpl->GetFunction(fnamel.str().data())->GetParameter(1);
		double sigma = hpl->GetFunction(fnamel.str().data())->GetParameter(2);
		double xmin  = mean-2*sigma;
		double xmax  = mean+2*sigma;
		hpl->Fit(fnamel.str().data(),"Q","",xmin,xmax);

	        double numil = hpl->Integral(hpl->FindFixBin(xmin),hpl->FindFixBin(xmax));
		numtl[i]=numil;
	        cout << "PFOS_num" << i+ histNo1st << "= " << numtl[i] << endl;
		ange[i] = 0.;
 	        sig [i] = fpl->GetParameter(2);
 	        sige[i] = fpl->GetParError(2);
 	        ste [i] = sig[i]/sqrt(numtl[i]);
 	        stee[i] = sige[i]/sqrt(numtl[i]);


}


  /*      TCanvas *c31 = new TCanvas("c31");
        hAnl->Draw("(-photonEMC+photonEAnl)/photonEMC>>h31",cut1+cut2);
        h31->SetTitle("Energy Resolution of Photon");
        h31->SetXTitle("Energy Resolution of Photon");
        h31->SetYTitle("");        
	h31->Draw("");
	TF1 *f31 = new TF1("f31","gaus",-.012,.042);
        f31->SetLineColor(kRed);
	h31->Fit("f31","","",-.01,.04);
	double mean31 = h31->GetFunction("f31")->GetParameter(1);
	double sigma31 = h31->GetFunction("f31")->GetParameter(2);
	h31->Fit("f31","","",mean31-2*sigma31,mean31+2*sigma31);
	
	double num31,sig31,se31;
	int numi31 = h31->Integral(h31->FindFixBin(-.01),h31->FindFixBin(.04));
	num31 = numi31;
	cout<<"num31 = "<<num31<<endl;	
	sig31= f31->GetParameter(2);	
	cout<<"sig31 = "<<sig31<<endl;
	se31= sig31/num31;
	cout<<"se31 = "<<se31<<endl;
*/


        TCanvas *c138 = new TCanvas("c138","c138");
	TGraphErrors *f138 = new TGraphErrors(6,ang,sig,ange,sige);
        //f68->SetTitle("Energy Resolution of Photon");
        //f68->SetXTitle("Energy Resolution of Photon");
        //f68->SetYTitle("");
        f138->SetMinimum(.0);
	f138->Draw("AP");
        f138->SetMarkerStyle(3);
	f138->SetMarkerColor(kAzure+10);
	f138->SetLineColor(kAzure+10);
 	TGraphErrors *g138 = PhotonCase4SigmaTheta20(0);
 	TGraphErrors *s138 = PhotonCase4SigmaTheta20s(0);
	c138->cd();
	f138->Draw("AP");
        g138->Draw("P same");
        s138->Draw("P same");
        g138->SetMarkerStyle(3);
	g138->SetMarkerColor(kBlue);
        g138->SetLineColor(kBlue);
        s138->SetMarkerStyle(3);
	s138->SetMarkerColor(kRed);
        s138->SetLineColor(kRed);


        TCanvas *c139 = new TCanvas("c139","c139");
	TGraph *f139 = new TGraphErrors(6,ang,ste,ange,stee);
        //f68->SetTitle("Energy Resolution of Photon");
        //f68->SetXTitle("Energy Resolution of Photon");
        //f68->SetYTitle("");
	f139->SetMarkerStyle(3);
        f139->SetMarkerColor(kAzure+10);
        f139->SetLineColor(kAzure+10);
        TGraphErrors *g139 = PhotonCase4SigmaTheta20(1);
        TGraphErrors *s139 = PhotonCase4SigmaTheta20s(1);
        c139->cd();
        f139->SetMinimum(.0);
        f139->SetMaximum(.000125);
	f139->Draw("AP");
        g139->Draw("P same");
        s139->Draw("P same");
        g139->SetLineColor(kBlue);
        g139->SetMarkerStyle(3);
        g139->SetMarkerColor(kBlue);
        s139->SetLineColor(kRed);
        s139->SetMarkerStyle(3);
        s139->SetMarkerColor(kRed);


        TCanvas *c148 = new TCanvas("c148","c148");
        TGraph *f148 = new TGraphErrors(9,&ang[6],&sig[6],&ange[6],&sige[6]);
	f148->SetMinimum(.0);
        f148->SetMarkerStyle(3);
	f148->SetMarkerColor(kAzure+10);
        f148->SetLineColor(kAzure+10);
        f148->SetLineColor(kAzure+10);
	TGraphErrors *g148 = PhotonCase4SigmaPhi40(0);
	TGraphErrors *s148 = PhotonCase4SigmaPhi40s(0);
        c148->cd();
        f148->Draw("AP");
        g148->Draw("P same");
        s148->Draw("P same");
        g148->SetLineColor(4);
        g148->SetMarkerStyle(3);
        g148->SetMarkerColor(4);
        s148->SetLineColor(2);
        s148->SetMarkerStyle(3);
        s148->SetMarkerColor(2);


        TCanvas *c149 = new TCanvas("c149","c149");
        TGraph *f149 = new TGraphErrors(9,&ang[6],&ste[6],&ange[6],&stee[6]);
        f149->Draw("AP");
	f149->SetMarkerStyle(3);
        f149->SetMarkerColor(kAzure+10);
        f149->SetLineColor(kAzure+10);
        TGraphErrors *g149 = PhotonCase4SigmaPhi40(1);
        TGraphErrors *s149 = PhotonCase4SigmaPhi40s(1);
        c149->cd();
        f149->SetMinimum(.0);
        f149->SetMaximum(.0002); 
        f149->Draw("AP");
        g149->Draw("P same");
        s149->Draw("P same");
        g149->SetLineColor(4);
        g149->SetMarkerStyle(3);
        g149->SetMarkerColor(4);
        s149->SetLineColor(2);
        s149->SetMarkerStyle(3);
        s149->SetMarkerColor(2);

}


