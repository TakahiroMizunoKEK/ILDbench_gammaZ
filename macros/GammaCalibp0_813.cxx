
#include "/home/ilc/mizunot/bin/root_macros/style.C"
#include "GammaCalibp0_81s.cxx"
#include "PhotonCase4SigmaTheta20.cxx"
#include "PhotonCase4SigmaPhi40.cxx"
#include "PhotonCase4SigmaTheta51.cxx"
#include "PhotonCase4SigmaPhi51.cxx"
#include "PhotonCase4SigmaTheta20las.cxx"
#include "PhotonCase4SigmaTheta51las.cxx"
#include "PhotonCase4SigmaTheta20tes.cxx"
#include "PhotonCase4SigmaTheta51tes.cxx"


void GammaCalibp0_813() {

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
        TCut cut2 = cut3;
        //TCut cut6 = "abs(sin(photonphiMC))<=1.";
	TCut cut4 = "abs(cos(photonthetaMC))<0.95";
        //TCut cut2 = cut3;
        TCut cut6 = "abs(sin(photonphiMC))>=.1";
        //TCut cut2 = cut3+cut4+cut6;

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
	const int kNphibins = 40;
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
        	TH1D *hp = new TH1D(hname.str().data(),"",100.,-.2,.2);
        	TH1D *hpl = new TH1D(hnamel.str().data(),"",100.,-.2,.2);
        	TH1D *hpr = new TH1D(hnamer.str().data(),"",100.,-.2,.2);

		stringstream cname;
		cname<<"c"<<i+histNo1st<<ends;
	        //TCanvas *cp = new TCanvas(cname.str().data(),cname.str().data());

		stringstream item,iteml,itemr;
		//item << "(-photonEMC+photonEAnl)/photonEMC>>" << hname.str().data() << ends;
		iteml << "(-photonEMC+photonEAnl)/photonEMC>>" << hnamel.str().data() << ends;
		itemr << "(-photonEMC+photonEAnl)/photonEMC>>" << hnamer.str().data() << ends;
	        if (i<kNthetabins){
			hAnll->Draw(iteml.str().data(),cut1+cut2+cut6+cutv[i]);
	 	        hAnlr->Draw(itemr.str().data(),cut1+cut2+cut6+cutv[i]);
		} else {	
        	        hAnll->Draw(iteml.str().data(),cut1+cut2+cut4+cutv[i]);
              		hAnlr->Draw(itemr.str().data(),cut1+cut2+cut4+cutv[i]);

		}
		*hp= (*hpl) * wl + (*hpr) * wr;
		
		hp->SetTitle("Energy Resolution of Photon");
        	hp->SetXTitle("Energy Resolution of Photon");
        	hp->SetYTitle("");
        	//hp->Draw("");

			

                stringstream fname;
                fname<<"f"<<i+histNo1st<<ends;
	        TF1 *fp = new TF1(fname.str().data(),"gaus");
	        fp->SetLineColor(kRed);
	        hp->Fit(fname.str().data(),"Q","",kXmin,kXmax);
	        //cout << "03" << endl;
		double mean  = hp->GetFunction(fname.str().data())->GetParameter(1);
		double sigma = hp->GetFunction(fname.str().data())->GetParameter(2);
		double xmin  = mean-2.5*sigma;
		double xmax  = mean+2.5*sigma;
		hp->Fit(fname.str().data(),"Q","",xmin,xmax);

	        //cout << "04" << endl;
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


        TCanvas *c138 = new TCanvas("c138","c138",0,0,600,600);
        c138->SetRightMargin(.05);
        c138->SetLeftMargin(.25);

	TGraphErrors *f138 = new TGraphErrors(kNthetabins,ang,sig,ange,sige);
	f138->GetHistogram()->SetAxisRange(0.,1.,"x");
        f138->SetTitle("");
        //f138->SetTitle("Energy Resolution of Photon");

        f138->GetXaxis()->SetTitle("|cos#theta_{#gamma}|");
        f138->GetYaxis()->SetTitle("Sigma of (E_{#gamma}-E_{#gamma}^{MC})/E_{#gamma}^{MC}");
	f138->GetYaxis()->SetLabelSize(0.05);
	f138->GetYaxis()->SetTitleOffset(1.6);
        f138->SetMinimum(-.002);
        f138->SetMaximum(.035);
	f138->Draw("AP");
        //f138->SetMarkerStyle(3);
        f138->SetMarkerStyle(21);
        f138->SetMarkerSize(0.7);
	f138->SetMarkerColor(kAzure+10);
	f138->SetLineColor(kAzure+10);
 	TGraphErrors *g138 = PhotonCase4SigmaTheta20(0,cutv,kNthetabins,ang);
 	TGraphErrors *s138 = PhotonCase4SigmaTheta51(0,cutv,kNthetabins,ang);
 	TGraphErrors *sp138 = GammaCalibp0_81s(0);
 	TGraphErrors *l001 = PhotonCase4SigmaTheta20tes(1,0,cutv,kNthetabins,ang);
 	TGraphErrors *l002 = PhotonCase4SigmaTheta20tes(2,0,cutv,kNthetabins,ang);
 	TGraphErrors *l003 = PhotonCase4SigmaTheta20tes(3,0,cutv,kNthetabins,ang);
 	TGraphErrors *s001 = PhotonCase4SigmaTheta51tes(1,0,cutv,kNthetabins,ang);
 	TGraphErrors *s002 = PhotonCase4SigmaTheta51tes(2,0,cutv,kNthetabins,ang);
 	TGraphErrors *s003 = PhotonCase4SigmaTheta51tes(3,0,cutv,kNthetabins,ang);


	c138->cd();
	f138->Draw("AP");
        g138->Draw("P same");
        s138->Draw("P same");
        sp138->Draw("P same");
        l001->Draw("P same");
        l002->Draw("P same");
        //l003->Draw("P same");
        s001->Draw("P same");
        s002->Draw("P same");
        //s003->Draw("P same");
        //sum138->Draw("P same");
        g138->SetMarkerStyle(22);
        g138->SetMarkerSize(0.9);
	g138->SetMarkerColor(4);
        g138->SetLineColor(4);
        s138->SetMarkerStyle(23);
        s138->SetMarkerSize(0.9);
	s138->SetMarkerColor(2);
        s138->SetLineColor(2);
        sp138->SetMarkerStyle(21);
        sp138->SetMarkerSize(0.7);
        sp138->SetMarkerColor(kPink-9);
        sp138->SetLineColor(kPink-9);
        l001->SetMarkerStyle(22); //large
        l001->SetMarkerSize(0.9);
	l001->SetMarkerColor(kTeal-6);
        l001->SetLineColor(kTeal-6);
        l002->SetMarkerStyle(22); //large
        l002->SetMarkerSize(0.9);
	l002->SetMarkerColor(kGreen-3);
        l002->SetLineColor(kGreen-3);
        /*l003->SetMarkerStyle(22); //large
        l003->SetMarkerSize(0.9);
	l003->SetMarkerColor(kTeal+6);
        l003->SetLineColor(kTeal+6);*/
        s001->SetMarkerStyle(23);
        s001->SetMarkerSize(0.9);
	s001->SetMarkerColor(kOrange+9);
        s001->SetLineColor(kOrange+9);
        s002->SetMarkerStyle(23);
        s002->SetMarkerSize(0.9);
	s002->SetMarkerColor(kOrange-3);
        s002->SetLineColor(kOrange-3);
        /*s003->SetMarkerStyle(22);
        s003->SetMarkerSize(0.9);
	s003->SetMarkerColor(kPink+6);
        s003->SetLineColor(kPink+6);*/

        TLegend *legend = new TLegend( 0.55, 0.66, 0.9, 0.9) ;
        //legend->SetFontSize(0.5);
        legend->AddEntry( f138, "PFO IDR-L" , "p") ;
        legend->AddEntry( sp138, "PFO IDR-S" , "p") ;
        legend->AddEntry( g138, "Ang. Method IDR-L" , "p") ;
        legend->AddEntry( s138, "Ang. Method IDR-S" , "p") ;
        legend->AddEntry( l001, "IDR-L 1muE Cheated" , "p") ;
        legend->AddEntry( s001, "IDR-S 1muE Cheated" , "p") ;
        legend->AddEntry( l002, "IDR-L 2muE Cheated" , "p") ;
        legend->AddEntry( s002, "IDR-S 2muE Cheated" , "p") ;
	legend->SetFillColor(0);
	legend->SetTextSize(0.03787879);        
	legend->Draw() ;

TLatex *   tex = new TLatex(0.02,0.032,"ILD preliminary");
tex->SetTextFont(62);
tex->Draw();
/*TLatex * tex2 = new TLatex(0.15,0.0225,"preliminary");
tex2->SetTextFont(62);
tex2->Draw();*/


        TCanvas *c139 = new TCanvas("c139","c139");
	TGraphErrors *f139 = new TGraphErrors(kNthetabins,ang,ste,ange,stee);
	f139->GetHistogram()->SetAxisRange(0.,1.,"x");
        //f68->SetTitle("Energy Resolution of Photon");
        //f68->SetXTitle("Energy Resolution of Photon");
        //f68->SetYTitle("");
	f139->SetMarkerStyle(3);
        f139->SetMarkerColor(kAzure+10);
        f139->SetLineColor(kAzure+10);
        TGraphErrors *g139 = PhotonCase4SigmaTheta20(1,cutv,kNthetabins,ang);
        TGraphErrors *s139 = PhotonCase4SigmaTheta51(1,cutv,kNthetabins,ang);
        TGraphErrors *l13920 = PhotonCase4SigmaTheta20las(1,cutv,kNthetabins,ang);
        TGraphErrors *l13951 = PhotonCase4SigmaTheta51las(1,cutv,kNthetabins,ang);

        double signsum[kNthetabins];
        double signesum[kNthetabins];
        const double *Signrecct  = g139 -> GetY(); 
        const double *Signerecct = g139 -> GetEY();
        for (int j=0; j<kNthetabins;j++){
                signsum[j]  = sqrt(pow(ste[j],2) +pow(Signrecct[j],2));
                signesum[j] = sqrt(pow(stee[j],2)+pow(Signerecct[j],2));
                }
        TGraphErrors *sum139 = new TGraphErrors(kNthetabins,ang,signsum,ange,signesum);


        c139->cd();
        f139->SetMinimum(.0);
        f139->GetHistogram()->SetMaximum(.000325);
	f139->Draw("AP");
	f139->GetHistogram()->SetAxisRange(-1.,1.,"x");
        g139->Draw("P same");
        s139->Draw("P same");
        l13920->Draw("P same");
        l13951->Draw("P same");
        //sum139->Draw("P same");
        g139->SetLineColor(4);
        g139->SetMarkerStyle(3);
        g139->SetMarkerColor(4);
        s139->SetLineColor(2);
        s139->SetMarkerStyle(3);
        s139->SetMarkerColor(2);
        //sum139->SetMarkerStyle(3);
        //sum139->SetMarkerColor(3);
        //sum139->SetLineColor(3);


        TCanvas *c148 = new TCanvas("c148","c148",0,0,600,600);
        c148->SetRightMargin(.05);
        c148->SetLeftMargin(.25);

        TGraphErrors *f148 = new TGraphErrors(kNphibins,&ang[kNthetabins],&sig[kNthetabins],&ange[kNthetabins],&sige[kNthetabins]);
	//f138->GetHistogram()->SetAxisRange(-1.,1.,"x");
//        f148->SetTitle("Energy Resolution of Photon");

        f148->SetTitle("");
        f148->GetXaxis()->SetTitle("#phi_{#gamma}");
        f148->GetYaxis()->SetTitle("Sigma of (E_{#gamma}-E_{#gamma}^{MC})/E_{#gamma}^{MC}");
	f148->GetYaxis()->SetLabelSize(0.05);
	f148->GetYaxis()->SetTitleOffset(1.6);

	f148->SetMinimum(.0);
	f148->SetMaximum(.029);
        f148->SetMarkerStyle(21);
        f148->SetMarkerSize(0.7);
	f148->SetMarkerColor(kAzure+10);
        f148->SetLineColor(kAzure+10);
	TGraphErrors *g148 = PhotonCase4SigmaPhi40(0,cutv,kNthetabins,kNphibins,ang);
	TGraphErrors *s148 = PhotonCase4SigmaPhi51(0,cutv,kNthetabins,kNphibins,ang);
 	TGraphErrors *sp148 = GammaCalibp0_81s(4);


        double sigpsum[kNphibins];
        double sigpesum[kNphibins];
        const double *Sigrecp = g148 -> GetY();
        const double *Sigerecp = g148 -> GetEY();
        for (int j=0; j<kNphibins;j++){
                sigpsum[j]  = sqrt(pow(sig[j+kNthetabins],2) +pow(Sigrecp[j],2));
                sigpesum[j] = sqrt(pow(sige[j+kNthetabins],2)+pow(Sigerecp[j],2));
		}        
        TGraphErrors *sum148 = new TGraphErrors(kNphibins,&ang[kNthetabins],sigpsum,&ange[kNthetabins],sigpesum);


        c148->cd();
        f148->Draw("AP");
	f148->GetHistogram()->SetAxisRange(-kPi,kPi,"x");
        g148->Draw("P same");
        s148->Draw("P same");
        sp148->Draw("P same");
        //sum148->Draw("P same");
        g148->SetLineColor(4);
        g148->SetMarkerStyle(22);
        g148->SetMarkerSize(0.9);
        g148->SetMarkerColor(4);
        s148->SetLineColor(2);
        s148->SetMarkerStyle(22);
        s148->SetMarkerSize(0.9);
        s148->SetMarkerColor(2);
        sp148->SetMarkerStyle(21);
        sp148->SetMarkerSize(0.7);
        sp148->SetMarkerColor(kPink-9);
        sp148->SetLineColor(kPink-9);
        TLegend *legend148 = new TLegend( 0.55, 0.72, 0.94, 0.9) ;
        legend148->AddEntry( f148, "PFO IDR-L" , "p") ;
        legend148->AddEntry( sp148, "PFO IDR-S" , "p") ;
        legend148->AddEntry( g148, "Ang. Method IDR-L" , "p") ;
        legend148->AddEntry( s148, "Ang. Method IDR-S" , "p") ;
        legend148->SetFillColor(0);
	legend148->SetTextSize(0.03787879);        
        legend148->Draw() ;
TLatex *   tex148 = new TLatex(-3.05,0.027,"ILD preliminary");
tex148->SetTextFont(62);
tex148->Draw();
/*TLatex * tex1482 = new TLatex(-2.5,0.0225,"preliminary");
tex1482->SetTextFont(62);
tex1482->Draw();*/


        TCanvas *c149 = new TCanvas("c149","c149");
        TGraphErrors *f149 = new TGraphErrors(kNphibins,&ang[kNthetabins],&ste[kNthetabins],&ange[kNthetabins],&stee[kNthetabins]);
	f149->GetHistogram()->SetAxisRange(-1.,1.,"x");
	//f149->GetXaxis()->SetLabelSize(0.05);
        f149->Draw("AP");
	f149->SetMarkerStyle(3);
        f149->SetMarkerColor(kAzure+10);
        f149->SetLineColor(kAzure+10);
        TGraphErrors *g149 = PhotonCase4SigmaPhi40(1,cutv,kNthetabins,kNphibins,ang);
        TGraphErrors *s149 = PhotonCase4SigmaPhi51(1,cutv,kNthetabins,kNphibins,ang);

        double stepsum[kNphibins];
        double stepesum[kNphibins];
        const double *Sterecp = g149 -> GetY();
        const double *Steerecp = g149 -> GetEY();
        for (int j=0; j<kNphibins;j++){
                stepsum[j]  = sqrt(pow(ste[j+kNthetabins],2) +pow(Sterecp[j],2));
                stepesum[j] = sqrt(pow(stee[j+kNthetabins],2)+pow(Steerecp[j],2));
                }
        TGraphErrors *sum149 = new TGraphErrors(kNphibins,&ang[kNthetabins],stepsum,&ange[kNthetabins],stepesum);


        c149->cd();
        f149->SetMinimum(.0);
        f149->GetHistogram()->SetMaximum(.000275); 
        f149->Draw("AP");
	//f149->GetHistogram()->SetAxisRange(-kPi,kPi,"x");
	f149->GetHistogram()->SetAxisRange(-kPi,kPi,"x");
        g149->Draw("P same");
        s149->Draw("P same");
        //sum149->Draw("P same");
        g149->SetLineColor(4);
        g149->SetMarkerStyle(3);
        g149->SetMarkerColor(4);
        s149->SetLineColor(2);
        s149->SetMarkerStyle(3);
        s149->SetMarkerColor(2);
        //sum149->SetMarkerStyle(3);
        //sum149->SetMarkerColor(3);
        //sum149->SetLineColor(3);

}


