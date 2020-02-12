
#include "/home/ilc/mizunot/bin/root_macros/style.C"
#include "photonERec6.cxx"
#include "photonERec63.cxx"
#include "CalibFactor.C"
#include "PhotonCase4MeanE0.cxx"
#include "PhotonCase4MeanE0s.cxx"
//#include "PhotonCase4MeanMCE0.cxx"


void GammaCalibp0_58() {

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

        //double ange[kNhist],sig[kNhist],sige[kNhist],ste[kNhist],stee[kNhist],numt[kNhist];
        double sig[kNhist],sige[kNhist],ste[kNhist],stee[kNhist],numt[kNhist];
        double angec[kNhist],sigc[kNhist],sigec[kNhist],stec[kNhist],steec[kNhist],numtc[kNhist];
        double angecomp[kNhist],sigcomp[kNhist],sigecomp[kNhist],stecomp[kNhist],steecomp[kNhist],numtcomp[kNhist];
        double ang[] = {85.,140.,170.,190.,210.,230.,250.};
        double angc[] = {83.,138.,168.,188.,208.,228.,248.};
        double ange[] = {35.,20.,10.,10.,10.,10.,10.};	


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
		iteml << "(-photonEMC+photonEAnl)/photonEMC>>" << hnamel.str().data() << ends;
		itemr << "(-photonEMC+photonEAnl)/photonEMC>>" << hnamer.str().data() << ends;
	        hAnll->Draw(iteml.str().data(),cut1+cut2+cutv[i]);
	        hAnlr->Draw(itemr.str().data(),cut1+cut2+cutv[i]);
		*hp= (*hpl) * wl + (*hpr) * wr;
		
		hp->SetTitle("Energy Resolution of Photon");
        	hp->SetXTitle("Energy Resolution of Photon");
        	hp->SetYTitle("");
        	
		if (i == 0) hp->Rebin(4);
		hp->Draw("");

                stringstream fname;
                fname<<"f"<<i+histNo1st<<ends;
	        TF1 *fp = new TF1(fname.str().data(),"gaus");
	        fp->SetLineColor(kRed);

                if (i == 0) hp->Fit(fname.str().data(),"","",-.1,.1);
		else        hp->Fit(fname.str().data(),"","",kXmin,kXmax);

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
		//ange[i] = 0.;
 	        sig [i] = fp->GetParameter(1);
 	        sige[i] = fp->GetParError(1);
 	        ste [i] = sig[i]/sqrt(numt[i]);
 	        stee[i] = sige[i]/sqrt(numt[i]);



                stringstream cnametr;
                cnametr<<"ctr"<<i+histNo1st<<ends;
                TCanvas *ctr = new TCanvas(cnametr.str().data(),cnametr.str().data());

                stringstream hnamec;
                stringstream hnamelc;
                stringstream hnamerc;
                hnamec<<"hc"<<i+histNo1st<<ends;
                hnamelc<<"hlc"<<i+histNo1st<<ends;
                hnamerc<<"hrc"<<i+histNo1st<<ends;
                TH1D *hpc = new TH1D(hnamec.str().data(),"",100.,-.2,.2);
                TH1D *hplc = new TH1D(hnamelc.str().data(),"",100.,-.2,.2);
                TH1D *hprc = new TH1D(hnamerc.str().data(),"",100.,-.2,.2);

                stringstream itemc,itemlc,itemrc;
                itemlc << "(-photonEMC+photonEAnl*CalibFactor(abs(cos(photonthetaAnl))))/photonEMC>>" << hnamelc.str().data() << ends;
                itemrc << "(-photonEMC+photonEAnl*CalibFactor(abs(cos(photonthetaAnl))))/photonEMC>>" << hnamerc.str().data() << ends;
                hAnll->Draw(itemlc.str().data(),cut1+cut2+cutv[i]);
                hAnlr->Draw(itemrc.str().data(),cut1+cut2+cutv[i]);
                *hpc= (*hplc) * wl + (*hprc) * wr;

                hpc->SetTitle("Energy Resolution of Photon");
                hpc->SetXTitle("Energy Resolution of Photon");
                hpc->SetYTitle("");
                if (i == 0) hpc->Rebin(4);
                hpc->Draw("");

                stringstream fnamec;
                fnamec<<"fc"<<i+histNo1st+400<<ends;
                TF1 *fpc = new TF1(fnamec.str().data(),"gaus");
                fpc->SetLineColor(kRed);
                if (i == 0)	hpc->Fit(fnamec.str().data(),"","",-.1,.1);
                else 		hpc->Fit(fnamec.str().data(),"","",kXmin,kXmax);
                double meanc  = hpc->GetFunction(fnamec.str().data())->GetParameter(1);
                double sigmac = hpc->GetFunction(fnamec.str().data())->GetParameter(2);
                double xminc  = meanc-2.5*sigmac;
                double xmaxc  = meanc+2.5*sigmac;
                hpc->Fit(fnamec.str().data(),"","",xminc,xmaxc);
                meanc  = hpc->GetFunction(fnamec.str().data())->GetParameter(1);
                sigmac = hpc->GetFunction(fnamec.str().data())->GetParameter(2);
                xminc  = meanc-2.5*sigmac;
                xmaxc  = meanc+2.5*sigmac;
                hpc->Fit(fnamec.str().data(),"","",xminc,xmaxc);

                int numic = hpc->Integral(hpc->FindFixBin(xminc),hp->FindFixBin(xmaxc));
                numtc[i] = numic;
                cout << "numc" << i+ histNo1st << "= " << numtc[i] << endl;
                angec[i] = 0.;
                sigc [i] = fpc->GetParameter(1);
                sigec[i] = fpc->GetParError(1);
                stec [i] = sigc[i]/sqrt(numtc[i]);
                steec[i] = sigec[i]/sqrt(numtc[i]);


/*		stringstream hnamecomp;
                stringstream hnamelcomp;
                stringstream hnamercomp;
                hnamecomp<<"hcomp"<<i+histNo1st<<ends;
                hnamelcomp<<"hlcomp"<<i+histNo1st<<ends;
                hnamercomp<<"hrcomp"<<i+histNo1st<<ends;
                TH1D *hpcomp = new TH1D(hnamecomp.str().data(),"",100.,-.2,.2);
                TH1D *hplcomp = new TH1D(hnamelcomp.str().data(),"",100.,-.2,.2);
                TH1D *hprcomp = new TH1D(hnamercomp.str().data(),"",100.,-.2,.2);

               stringstream itemcomp,itemlcomp,itemrcomp;
                itemlcomp << "(-photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl)+photonEAnl)/photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl)>>" << hnamelcomp.str().data() << ends;
                itemrcomp << "(-photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl)+photonEAnl)/photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl)>>" << hnamercomp.str().data() << ends;
                hAnll->Draw(itemlcomp.str().data(),cut1+cut2+cutv[i]);
                hAnlr->Draw(itemrcomp.str().data(),cut1+cut2+cutv[i]);
                *hpcomp= (*hplcomp) * wl + (*hprcomp) * wr;

                hpcomp->SetTitle("Energy Resolution of Photon");
                hpcomp->SetXTitle("Energy Resolution of Photon");
                hpcomp->SetYTitle("");
                hpcomp->Draw("");

                stringstream fnamecomp;
                fnamecomp<<"fcomp"<<i+histNo1st+500<<ends;
                TF1 *fpcomp = new TF1(fnamecomp.str().data(),"gaus");
                fpcomp->SetLineColor(kRed);
                hpcomp->Fit(fnamecomp.str().data(),"","",kXmin,kXmax);
                double meancomp  = hpcomp->GetFunction(fnamecomp.str().data())->GetParameter(1);
                double sigmacomp = hpcomp->GetFunction(fnamecomp.str().data())->GetParameter(2);
                double xmincomp  = meancomp-2.5*sigmacomp;
                double xmaxcomp  = meancomp+2.5*sigmacomp;
                hpcomp->Fit(fnamecomp.str().data(),"","",xmincomp,xmaxcomp);
                meancomp  = hpcomp->GetFunction(fnamecomp.str().data())->GetParameter(1);
                sigmacomp = hpcomp->GetFunction(fnamecomp.str().data())->GetParameter(2);
                xmincomp  = meancomp-2.5*sigmacomp;
                xmaxcomp  = meancomp+2.5*sigmacomp;
                hpcomp->Fit(fnamecomp.str().data(),"","",xmincomp,xmaxcomp);
        
	        int numicomp = hpcomp->Integral(hpcomp->FindFixBin(xmincomp),hpcomp->FindFixBin(xmaxcomp));
                numtcomp[i] = numicomp;
                cout << "numcomp" << i+ histNo1st << "= " << numtcomp[i] << endl;
                angecomp[i] = 0.;
                sigcomp [i] = fpcomp->GetParameter(1);
                sigecomp[i] = fpcomp->GetParError(1);
                stecomp [i] = sigcomp[i]/sqrt(numtcomp[i]);
                steecomp[i] = sigecomp[i]/sqrt(numtcomp[i]);
*/



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


        TCanvas *c38 = new TCanvas("c38","c38",0,0,600,600);
        c38->SetRightMargin(.05);
        c38->SetLeftMargin(.25);

        //c38->SetLogy();
	TGraphErrors *f38 = new TGraphErrors(kNhist,ang,sig,ange,sige);
        f38->SetTitle("");
        f38->GetXaxis()->SetTitle("E_{#gamma} [GeV]");
        f38->GetYaxis()->SetTitle("Mean of (E_{#gamma}-E_{#gamma}^{MC})/E_{#gamma}^{MC}");        
	f38->GetYaxis()->SetTitleOffset(1.5);
        //f68->SetTitle("Energy Resolution of Photon");
        //f68->SetXTitle("Energy Resolution of Photon");
        //f68->SetYTitle("");
	f38->SetMaximum(.07);
        f38->SetMinimum(-.02);
	f38->GetHistogram()->SetAxisRange(40.,270.,"x");
	f38->Draw("AP");
        f38->SetMarkerStyle(21);
        f38->SetMarkerSize(0.7);
	f38->SetMarkerColor(kAzure+10);
	f38->SetLineColor(kAzure+10);

        TGraphErrors *fc38 = new TGraphErrors(kNhist,angc,sigc,ange,sigec);
        TGraphErrors *fcomp38 = new TGraphErrors(kNhist,ang,sigcomp,angecomp,sigecomp);

 	TGraphErrors *g38 = PhotonCase4MeanE0(0);
 	//TGraphErrors *s38 = PhotonCase4MeanE0s(0);
 	//TGraphErrors *g38 = PhotonCase4MeanMCE0(0);
	c38->cd();
	f38->SetMaximum(.07);
        f38->SetMinimum(-.02);
	//g38->SetMaximum(.001);
        //g38->SetMinimum(-.001);
	f38->Draw("AP");
        fc38->Draw("P same");
        g38->Draw("P same");
        //s38->Draw("P same");
        //fcomp38->Draw("P same");
        //g38->Draw("AP");
        fc38->SetMarkerStyle(21);
        fc38->SetMarkerSize(0.7);
	fc38->SetMarkerColor(kGreen-3);
        fc38->SetLineColor(kGreen-3);
        g38->SetMarkerStyle(22);
        g38->SetMarkerSize(0.9);
	g38->SetMarkerColor(4);
        g38->SetLineColor(4);
        /*s38->SetMarkerStyle(3);
	s38->SetMarkerColor(2);
        s38->SetLineColor(2);*/
        //fcomp38->SetMarkerStyle(3);
	//fcomp38->SetMarkerColor(6);
        //fcomp38->SetLineColor(6);

        TLegend *legend = new TLegend( 0.6, 0.65, 0.93, 0.85) ; 
        legend->SetTextSize(0.03787879) ; 
 //       legend->SetMarkerSize(0.03787879) ; 
        legend->AddEntry( g38, "Angular Method" , "p") ; 
        legend->AddEntry( f38, "PFO" , "p") ; 
        //legend->AddEntry( fcomp38, "PFO Compared with CaseB" , "p") ; 
        //legend->AddEntry( s38, "Resolved IDR-S" , "p") ; 
        legend->AddEntry( fc38, "Calibrated PFO" , "p") ; 
        legend->AddEntry((TObject*)0,"IDR-L model","");
        legend->SetFillColor(0);
        legend->Draw() ;

	TLatex *   tex = new TLatex(50,0.062,"ILD preliminary");
	tex->SetTextFont(62);
	tex->Draw();


/*
        TLegend *legend = new TLegend( 0.66, 0.66, 0.90, 0.90) ;
        legend->AddEntry( f38, "PFO" , "p") ;
        legend->AddEntry( g38, "IDR-L" , "p") ;
        legend->AddEntry( s38, "IDR-S" , "p") ;
        legend->SetFillColor(0);
        legend->SetTextSize(0.04);
        legend->Draw() ;


TLatex *   tex = new TLatex(80,0.02,"ILD");
tex->SetTextFont(62);
tex->Draw();
TLatex * tex2 = new TLatex(100,0.02,"preliminary");
tex2->SetTextFont(62);
tex2->Draw();
*/




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


