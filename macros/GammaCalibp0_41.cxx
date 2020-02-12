
#include "/home/ilc/mizunot/bin/root_macros/style.C"
#include "PhotonCase4SigmaTheta20.cxx"
#include "PhotonCase4SigmaPhi40.cxx"


void GammaCalibp0_41() {

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
	TCut cut4 = "abs(coslep1)<0.75 && abs(coslep2)<0.75";
        //TCut cut2 = cut3+cut4;
        TCut cut2 = cut3;
        TCut cut6 = "abs(sin(photonphiMC))<=1.";

	        cout << "02" << endl;
	std::vector<TCut> cutv; 
	/*cutv.push_back(TCut("abs(cos(photonthetaMC))<0.2"));
	cutv.push_back(TCut("abs(cos(photonthetaMC))>=0.2 && abs(cos(photonthetaMC))<0.4"));
	cutv.push_back(TCut("abs(cos(photonthetaMC))>=0.4 && abs(cos(photonthetaMC))<0.6"));
	cutv.push_back(TCut("abs(cos(photonthetaMC))>=0.6 && abs(cos(photonthetaMC))<0.8"));
	cutv.push_back(TCut("abs(cos(photonthetaMC))>=0.8 && abs(cos(photonthetaMC))<0.9"));
	cutv.push_back(TCut("abs(cos(photonthetaMC))>=0.9"));
	*/
	//TCut cutv[kNhist];

	/*cutv[0] = "abs(cos(photonthetaMC))<0.2";
	cutv[1] = "abs(cos(photonthetaMC))>=0.2 && abs(cos(photonthetaMC))<0.4";
	cutv[2] = "abs(cos(photonthetaMC))>=0.4 && abs(cos(photonthetaMC))<0.6";
	cutv[3] = "abs(cos(photonthetaMC))>=0.6 && abs(cos(photonthetaMC))<0.8";
	cutv[4] = "abs(cos(photonthetaMC))>=0.8 && abs(cos(photonthetaMC))<0.9";
	cutv[5] = "abs(cos(photonthetaMC))>=0.9";
*/
        /*cutv[6]  = "photonphiMC<3.14*(-5.)/7.";
        cutv[7]  = "photonphiMC>=3.14*(-5.)/7. && photonphiMC<3.14*(-3.)/7.";
        cutv[8]  = "photonphiMC>=3.14*(-3.)/7. && photonphiMC<3.14*(-1.)/7.";
        cutv[9]  = "photonphiMC>=3.14*(-1.)/7. && photonphiMC<3.14*(1.)/7.";
        cutv[10] = "photonphiMC>=3.14*(1.)/7. && photonphiMC<3.14*(3.)/7.";
        cutv[11] = "photonphiMC>=3.14*(3.)/7. && photonphiMC<3.14*(5.)/7.";
        cutv[12] = "photonphiMC>=3.14*(5.)/7.";
*/
        /*cutv[6]  = "photonphiMC<-2.";
        cutv[7]  = "photonphiMC>=-2. && photonphiMC<-1.";
        cutv[8]  = "photonphiMC>=-1. && photonphiMC<-.3";
        cutv[9]  = "photonphiMC>=-.3 && photonphiMC<-.1";
        cutv[10] = "photonphiMC>=-.1 && photonphiMC<.1";
        cutv[11] = "photonphiMC>=.1 && photonphiMC<.3";
        cutv[12] = "photonphiMC>=.3 && photonphiMC<1.";
        cutv[13] = "photonphiMC>=1. && photonphiMC<2.";
        cutv[14] = "photonphiMC>=2";*/
		
	
	const int kNthetabins = 20;
	const int kNphibins = 31;
	double    ang[kNphibins+kNthetabins];

	double dcs = 1./kNthetabins;
        for (int j=0;j<kNthetabins;j++){
                double csmin =  j * dcs;
                double csmax = csmin + dcs;

                stringstream cutstr;
                cutstr << "abs(cos(photonthetaMC))>" << csmin << " && "
                       << "abs(cos(photonthetaMC))<" << csmax << ends;
                cutv.push_back(TCut(cutstr.str().data()));
                ang[j] = (csmin + csmax)/2.;
        }


/*	ang[0] = .1;
	ang[1] = .3;
	ang[2] = .5;
	ang[3] = .7;
	ang[4] = .85;
	ang[5] = .95;*/

	double kPi   = TMath::Pi();
	double dphi  = 2*kPi/kNphibins;

	for (int j=0;j<kNphibins;j++){
		double phimin = -kPi + j * dphi;
		double phimax = phimin + dphi;
			
		stringstream cutstr;
		cutstr << "photonphiMC>" << phimin << " && "
 		       << "photonphiMC<" << phimax << ends;
		cutv.push_back(TCut(cutstr.str().data()));
		ang[j+kNthetabins] = (phimin + phimax)/2.; 
	}

	const double kXmin = -.01;
	const double kXmax = .04;

	const int kNhist = cutv.size();
	cerr<<"cutvsize= " <<kNhist<<endl;
	const int histNo1st = 11;

	double ange[kNhist],sig[kNhist],sige[kNhist],ste[kNhist],stee[kNhist],numt[kNhist];
	//double ang[] = {.1,.3,.5,.7,.85,.95,3.14*(-6.)/7.,3.14*(-4.)/7.,3.14*(-2.)/7.,0.,3.14*(2.)/7.,3.14*(4.)/7.,3.14*(6.)/7.};
	//double ang[] = {.1,.3,.5,.7,.85,.95,-2.57,-1.5,-0.65,-0.2,0.,0.2,0.65,1.5,2.57};
	

	for (int i=0;i<kNhist;i++){
	        stringstream hname;	
	        stringstream hnamel;	
	        stringstream hnamer;	
		hname<<"h"<<i+histNo1st<<ends;
		hnamel<<"hl"<<i+histNo1st<<ends;
		hnamer<<"hr"<<i+histNo1st<<ends;
        	TH1D *hp = new TH1D(hname.str().data(),"",50.,-.2,.2);
        	TH1D *hpl = new TH1D(hnamel.str().data(),"",50.,-.2,.2);
        	TH1D *hpr = new TH1D(hnamer.str().data(),"",50.,-.2,.2);

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
	        hp->Fit(fname.str().data(),"Q","",kXmin,kXmax);
		double mean  = hp->GetFunction(fname.str().data())->GetParameter(1);
		double sigma = hp->GetFunction(fname.str().data())->GetParameter(2);
		double xmin  = mean-2*sigma;
		double xmax  = mean+2*sigma;
		hp->Fit(fname.str().data(),"Q","",xmin,xmax);

	        double numi = hp->Integral(hp->FindFixBin(xmin),hp->FindFixBin(xmax));
		numt[i]=numi;
	        cout << "PFOS_num" << i+ histNo1st << "= " << numt[i] << endl;
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


        TCanvas *c138 = new TCanvas("c138","c138");
	TGraphErrors *f138 = new TGraphErrors(kNthetabins,ang,sig,ange,sige);
	f138->GetHistogram()->SetAxisRange(-kPi,kPi,"x");
        //f68->SetTitle("Energy Resolution of Photon");
        //f68->SetXTitle("Energy Resolution of Photon");
        //f68->SetYTitle("");
        f138->SetMinimum(.0);
	f138->Draw("AP");
        f138->SetMarkerStyle(3);
	f138->SetMarkerColor(kAzure+10);
	f138->SetLineColor(kAzure+10);
 	TGraphErrors *g138 = PhotonCase4SigmaTheta20(0,cutv,kNthetabins,ang);
	c138->cd();
	f138->Draw("AP");
        g138->Draw("P same");
        g138->SetMarkerStyle(3);
	g138->SetMarkerColor(kAzure);
        g138->SetLineColor(kAzure);


        TCanvas *c139 = new TCanvas("c139","c139");
	TGraphErrors *f139 = new TGraphErrors(kNthetabins,ang,ste,ange,stee);
        //f68->SetTitle("Energy Resolution of Photon");
        //f68->SetXTitle("Energy Resolution of Photon");
        //f68->SetYTitle("");
	f139->SetMarkerStyle(3);
        f139->SetMarkerColor(kAzure+10);
        f139->SetLineColor(kAzure+10);
        TGraphErrors *g139 = PhotonCase4SigmaTheta20(1,cutv,kNthetabins,ang);
        c139->cd();
        f139->SetMinimum(.0);
        f139->GetHistogram()->SetMaximum(.000225);
	f139->Draw("AP");
	f139->GetHistogram()->SetAxisRange(-1.,1.,"x");
        g139->Draw("P same");
        g139->SetLineColor(kAzure);
        g139->SetMarkerStyle(3);
        g139->SetMarkerColor(kAzure);


        TCanvas *c148 = new TCanvas("c148","c148");
        TGraphErrors *f148 = new TGraphErrors(kNphibins,&ang[kNthetabins],&sig[kNthetabins],&ange[kNthetabins],&sige[kNthetabins]);
	f148->SetMinimum(.0);
        f148->SetMarkerStyle(3);
	f148->SetMarkerColor(kAzure+10);
        f148->SetLineColor(kAzure+10);
        f148->SetLineColor(kAzure+10);
	TGraphErrors *g148 = PhotonCase4SigmaPhi40(0,cutv,kNthetabins,kNphibins,ang);
        c148->cd();
        f148->Draw("AP");
	f148->GetHistogram()->SetAxisRange(-kPi,kPi,"x");
        g148->Draw("P same");
        g148->SetLineColor(kAzure);
        g148->SetMarkerStyle(3);
        g148->SetMarkerColor(kAzure);


        TCanvas *c149 = new TCanvas("c149","c149");
        TGraphErrors *f149 = new TGraphErrors(kNphibins,&ang[kNthetabins],&ste[kNthetabins],&ange[kNthetabins],&stee[kNthetabins]);
        f149->Draw("AP");
	f149->SetMarkerStyle(3);
        f149->SetMarkerColor(kAzure+10);
        f149->SetLineColor(kAzure+10);
        TGraphErrors *g149 = PhotonCase4SigmaPhi40(1,cutv,kNthetabins,kNphibins,ang);
        c149->cd();
        f149->SetMinimum(.0);
        f149->GetHistogram()->SetMaximum(.000275); 
        f149->Draw("AP");
	//f149->GetHistogram()->SetAxisRange(-kPi,kPi,"x");
	f149->GetHistogram()->SetAxisRange(-kPi,kPi,"x");
        g149->Draw("P same");
        g149->SetLineColor(kAzure);
        g149->SetMarkerStyle(3);
        g149->SetMarkerColor(kAzure);
        g149->SetLineColor(kAzure);

}


