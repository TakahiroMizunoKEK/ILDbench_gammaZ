
#include "/home/ilc/mizunot/bin/root_macros/style.C"
#include "PhotonCase4SigmaTheta.cxx"
#include "PhotonCase4SigmaPhi.cxx"


void GammaCalibp0_06() {

        stringstream filest;
        filest << "../root_merge.mILD_l5_o1_v02/"
               << "2f_z_l.eL.pR.mILD_l5_o1_v02.root" << ends;

        TFile *f = new TFile(filest.str().data());
	
	setILDStyle();
	//gStyle->SetPadRightMargin(1.0);
	//gStyle->SetPadRightMargin(1.0);
	gStyle->SetOptStat(1000001110);
        gStyle->SetStatH(0.15);
        gStyle->SetStatW(0.15);
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


	TCut cut1 = "pdg0==13 && abs(mzgen-91.2)<10";
	TCut cut3 = "coneen > -0.5";
	TCut cut4 = "abs(coslep1)<0.75 && abs(coslep2)<0.75";
        //TCut cut2 = cut3+cut4;
        TCut cut2 = cut3;
        TCut cut6 = "abs(sin(photonphiMC))<=1.";

	const int kNhist = 14;
	TCut cutv[kNhist];

	cutv[0] = "abs(cos(photonthetaMC))<0.2";
	cutv[1] = "abs(cos(photonthetaMC))>=0.2 && abs(cos(photonthetaMC))<0.4";
	cutv[2] = "abs(cos(photonthetaMC))>=0.4 && abs(cos(photonthetaMC))<0.6";
	cutv[3] = "abs(cos(photonthetaMC))>=0.6 && abs(cos(photonthetaMC))<0.8";
	cutv[4] = "abs(cos(photonthetaMC))>=0.8 && abs(cos(photonthetaMC))<0.9";
	cutv[5] = "abs(cos(photonthetaMC))>=0.9 && abs(cos(photonthetaMC))<0.95";
	cutv[6] = "abs(cos(photonthetaMC))>=0.95";

        cutv[7] = "abs(sin(photonphiMC))<0.04";
        cutv[8] = "abs(sin(photonphiMC))>=0.04  && abs(sin(photonphiMC))<0.08";
        cutv[9] = "abs(sin(photonphiMC))>=0.08 && abs(sin(photonphiMC))<0.12";
        cutv[10] = "abs(sin(photonphiMC))>=0.12 && abs(sin(photonphiMC))<0.4";
        cutv[11] = "abs(sin(photonphiMC))>=0.4 && abs(sin(photonphiMC))<0.6";
        cutv[12] = "abs(sin(photonphiMC))>=0.6 && abs(sin(photonphiMC))<0.8";
        cutv[13] = "abs(sin(photonphiMC))>=0.8";

	const double kXmin = -.01;
	const double kXmax = .04;

	const int histNo1st = 11;

	double ange[14],sig[14],sige[14],ste[14],stee[14],numt[14];
	double ang[] = {.1,.3,.5,.7,.85,.925,.975,0.02,0.06,.1,.26,.5,.7,.9};
	

	for (int i=0;i<kNhist;i++){
	        stringstream hname;	
		hname<<"h"<<i+histNo1st<<ends;
        	TH1D *hp = new TH1D(hname.str().data(),"",400.,-.2,.2);

		stringstream cname;
		cname<<"c"<<i+histNo1st<<ends;
	        TCanvas *cp = new TCanvas(cname.str().data(),cname.str().data());

		stringstream item;
		item << "(-photonEMC+photonEAnl)/photonEMC>>" << hname.str().data() << ends;
	        hAnl->Draw(item.str().data(),cut1+cut2+cutv[i]);
		
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
		double xmin  = mean-2*sigma;
		double xmax  = mean+2*sigma;
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
	TGraphErrors *f38 = new TGraphErrors(7,ang,sig,ange,sige);
        //f68->SetTitle("Energy Resolution of Photon");
        //f68->SetXTitle("Energy Resolution of Photon");
        //f68->SetYTitle("");
        f38->SetMinimum(.0);
	f38->Draw("AP");
        f38->SetLineColor(kAzure+10);
 	TGraphErrors *g38 = PhotonCase4SigmaTheta(0);
	c38->cd();
	f38->Draw("AP");
        g38->Draw("P same");
        g38->SetLineColor(kAzure);


        TCanvas *c39 = new TCanvas("c39","c39");
	TGraph *f39 = new TGraphErrors(7,ang,ste,ange,stee);
        //f68->SetTitle("Energy Resolution of Photon");
        //f68->SetXTitle("Energy Resolution of Photon");
        //f68->SetYTitle("");
        f39->SetMinimum(.0);
	f39->Draw("AP");
        f39->SetLineColor(kAzure+10);
        TGraphErrors *g39 = PhotonCase4SigmaTheta(1);
        c39->cd();
        f39->Draw("AP");
        g39->Draw("P same");
        g39->SetLineColor(kAzure);


        TCanvas *c48 = new TCanvas("c48","c48");
        TGraph *f48 = new TGraphErrors(7,&ang[7],&sig[7],&ange[7],&sige[7]);
	f48->SetMinimum(.0);
        f48->Draw("AP");
        f48->SetLineColor(kAzure+10);
	TGraphErrors *g48 = PhotonCase4SigmaPhi(0);
        c48->cd();
        f48->Draw("AP");
        g48->Draw("P same");
        g48->SetLineColor(kAzure);


        TCanvas *c49 = new TCanvas("c49","c49");
        TGraph *f49 = new TGraphErrors(7,&ang[7],&ste[7],&ange[7],&stee[7]);
	f49->SetMinimum(.0);
        f49->Draw("AP");
        f49->SetLineColor(kAzure+10);
        TGraphErrors *g49 = PhotonCase4SigmaPhi(1);
        c49->cd();
        g49->Draw("AP");
        f49->Draw("P same");
        g49->SetLineColor(kAzure);


}


