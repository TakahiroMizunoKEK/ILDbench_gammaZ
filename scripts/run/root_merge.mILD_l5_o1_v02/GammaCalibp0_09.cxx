
#include "/home/ilc/mizunot/bin/root_macros/style.C"
//#include "PhotonCase4MeanE0.cxx"
#include "PhotonCase4SigmaE0.cxx"
//#include "PhotonCase4MeanMCE0.cxx"


void GammaCalibp0_09() {

        stringstream filestl;
        stringstream filestr;

        filestl << "../root_merge.mILD_l5_o1_v02/"
               << "2f_z_l.eL.pR.mILD_l5_o1_v02.root" << ends;

        filestr << "../root_merge.mILD_l5_o1_v02/"
               << "2f_z_l.eR.pL.mILD_l5_o1_v02.root" << ends;

        TFile *fl = new TFile(filestl.str().data());
        TFile *fr = new TFile(filestr.str().data());
	
	setILDStyle();
	//gStyle->SetPadRightMargin(1.0);
	//gStyle->SetPadRightMargin(1.0);
	gStyle->SetOptStat(1000001110);
        gStyle->SetStatH(0.15);
        gStyle->SetStatW(0.15);
        gStyle->SetStatX(0.9);
        gStyle->SetStatY(0.9);
	gStyle->SetOptFit();

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

	Int_t nbinx   = 520;	
	Double_t xmin = -10.; 
	Double_t xmax = 510.; 	

	Int_t nbiny   = 520;	
	Double_t ymin = -10.; 
	Double_t ymax = 510.; 	


	TCut cut1 = "pdg0==13 && abs(mzgen-91.2)<10";
	TCut cut3 = "coneen > -0.5";
	//TCut cut4 = "abs(coslep1)<0.75 && abs(coslep2)<0.75";
        //TCut cut2 = cut3+cut4;
        //TCut cut2 = cut3;
        TCut cut4 = "abs(sin(photonphiAnl))>=.1";
        TCut cut6 = "abs(cos(photonthetaAnl))<=.95";
        TCut cut2 = cut3+cut4+cut6;

	const int kNhist = 7;
	TCut cutv[kNhist];

        cutv[0] = "photonEMC<120.";
        cutv[1] = "photonEMC>=120. && photonEMC<160.";
        cutv[2] = "photonEMC>=160. && photonEMC<180.";
        cutv[3] = "photonEMC>=180. && photonEMC<200.";
        cutv[4] = "photonEMC>=200. && photonEMC<220.";
        cutv[5] = "photonEMC>=220. && photonEMC<240.";
        cutv[6] = "photonEMC>=240. && photonEMC<260.";	


	const double kXmin = -.01;
	const double kXmax = .04;

	const int histNo1st = 11;

        double ange[kNhist],sig[kNhist],sige[kNhist],ste[kNhist],stee[kNhist],numt[kNhist];
        double ang[] = {85.,140.,170.,190.,210.,230.,250.};
	

	for (int i=0;i<kNhist;i++){
	        stringstream hname;	
	        stringstream hnamel;	
	        stringstream hnamer;	
		hname<<"h"<<i+histNo1st<<ends;
		hnamel<<"hl"<<i+histNo1st<<ends;
		hnamer<<"hr"<<i+histNo1st<<ends;
        	TH1D *hp = new TH1D(hname.str().data(),"",100.,-.2,.2);
        	TH1D *hpl = new TH1D(hnamel.str().data(),"",100.,-.2,.2);
        	TH1D *hpr = new TH1D(hnamer.str().data(),"",100.,-.2,.2);

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

			

                stringstream fname;
                fname<<"f"<<i+histNo1st<<ends;
	        TF1 *fp = new TF1(fname.str().data(),"gaus");
	        fp->SetLineColor(kRed);
	        hp->Fit(fname.str().data(),"","",kXmin,kXmax);
		double mean  = hp->GetFunction(fname.str().data())->GetParameter(1);
		double sigma = hp->GetFunction(fname.str().data())->GetParameter(2);
		double xmin  = mean-2.5*sigma;
		double xmax  = mean+2.5*sigma;
		hp->Fit(fname.str().data(),"","",xmin,xmax);
		mean  = hp->GetFunction(fname.str().data())->GetParameter(1);
		sigma = hp->GetFunction(fname.str().data())->GetParameter(2);
		xmin  = mean-2.5*sigma;
		xmax  = mean+2.5*sigma;
		hp->Fit(fname.str().data(),"","",xmin,xmax);

	        int numi = hp->Integral(hp->FindFixBin(xmin),hp->FindFixBin(xmax));
	        numt[i] = numi;
	        cout << "num" << i+ histNo1st << "= " << numt[i] << endl;
		ange[i] = 0.;
 	        sig [i] = fp->GetParameter(2);
 	        sige[i] = fp->GetParError(2);
 	        ste [i] = sig[i]/sqrt(numt[i]);
 	        stee[i] = sige[i]/sqrt(numt[i]);


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


        TCanvas *c38 = new TCanvas("c38","c38");
        //c38->SetLogy();
	TGraphErrors *f38 = new TGraphErrors(7,ang,sig,ange,sige);
        //f68->SetTitle("Energy Resolution of Photon");
        //f68->SetXTitle("Energy Resolution of Photon");
        //f68->SetYTitle("");
	f38->SetMaximum(.03);
        f38->SetMinimum(-.01);
	f38->Draw("AP");
        f38->SetMarkerStyle(3);
	f38->SetMarkerColor(kAzure+10);
	f38->SetLineColor(kAzure+10);
 	TGraphErrors *g38 = PhotonCase4SigmaE0(0);
 	//TGraphErrors *g38 = PhotonCase4MeanMCE0(0);
	c38->cd();
	f38->SetMaximum(.03);
        f38->SetMinimum(-.01);
	//g38->SetMaximum(.001);
        //g38->SetMinimum(-.001);
	f38->Draw("AP");
        g38->Draw("P same");
        //g38->Draw("AP");
        g38->SetMarkerStyle(3);
	g38->SetMarkerColor(kAzure);
        g38->SetLineColor(kAzure);


/*        TCanvas *c39 = new TCanvas("c39","c39");
	TGraph *f39 = new TGraphErrors(6,ang,ste,ange,stee);
        //f68->SetTitle("Energy Resolution of Photon");
        //f68->SetXTitle("Energy Resolution of Photon");
        //f68->SetYTitle("");
        f39->SetMinimum(.0);
	f39->Draw("AP");
        f39->SetLineColor(kAzure+10);
        TGraphErrors *g39 = PhotonCase4SigmaTheta0(1);
        c39->cd();
        f39->Draw("AP");
        g39->Draw("P same");
        g39->SetLineColor(kAzure);*/


/*        TCanvas *c48 = new TCanvas("c48","c48");
        c48->SetLogy();
	TGraph *f48 = new TGraphErrors(6,&ang[6],&sig[6],&ange[6],&sige[6]);
	f48->SetMaximum(.03);
	f48->SetMinimum(.0);
        f48->Draw("AP");
        f48->SetLineColor(kAzure+10);
	TGraphErrors *g48 = PhotonCase4MeanE0(0);
        c48->cd();
        f48->Draw("AP");
        g48->Draw("P same");
        g48->SetLineColor(kAzure);
*/

/*        TCanvas *c49 = new TCanvas("c49","c49");
        TGraph *f49 = new TGraphErrors(6,&ang[6],&ste[6],&ange[6],&stee[6]);
	f49->SetMinimum(.0);
        f49->Draw("AP");
        f49->SetLineColor(kAzure+10);
        TGraphErrors *g49 = PhotonCase4SigmaPhi0(1);
        c49->cd();
        g49->Draw("AP");
        f49->Draw("P same");
        g49->SetLineColor(kAzure);*/


/*        TCanvas *c301 = new TCanvas("c301","c301");
	TGraph f301=(*f38)/(*g38);
	f301->Draw("AP");
        f301->SetLineColor(kAzure);*/


}


