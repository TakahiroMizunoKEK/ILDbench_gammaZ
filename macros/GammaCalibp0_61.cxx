
#include "/home/ilc/mizunot/bin/root_macros/style.C"
#include "photonERec6.cxx"
#include "photonERec63.cxx"


void GammaCalibp0_61() {

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
        //TCut cut2 = cut3;
	TCut cut4 = "abs(cos(photonthetaMC))<0.95";
        TCut cut6 = "abs(sin(photonphiMC))>=.1";
        TCut cut2 = cut3+cut6;
        //TCut cut7 = "abs((photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl,lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl)-photonEMC)/photonEMC)<=.05";
        //TCut cut2 = cut3+cut7;

	        cout << "02" << endl;
	std::vector<TCut> cutv; 
	
	const int kNthetabins = 20;
	const int kNhist = 20;
	double    ang[kNthetabins];

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
	double meanCB[kNthetabins];
	double rmsCB[kNthetabins];
	double meanPFO[kNthetabins];
	double rmsPFO[kNthetabins];
	double meanMC[kNthetabins];
	double rmsMC[kNthetabins];
	double f[kNthetabins];
	double fe[kNthetabins];
	double fMC[kNthetabins];
	double fMCe[kNthetabins];
	double fMCCB[kNthetabins];
	double fMCCBe[kNthetabins];


	const int histNo1st = 11;

	double ange[kNhist],sig[kNhist],sige[kNhist],ste[kNhist],stee[kNhist],numt[kNhist];

	for (int i=0;i<kNhist;i++){
	        stringstream hname;	
	        stringstream hnamel;	
	        stringstream hnamer;	
	        stringstream hnamemc;	
	        stringstream hnamelmc;	
	        stringstream hnamermc;	

		hname<<"h"<<i+histNo1st<<ends;
		hnamel<<"hl"<<i+histNo1st<<ends;
		hnamer<<"hr"<<i+histNo1st<<ends;
		hnamemc<<"hmc"<<i+histNo1st<<ends;
		hnamelmc<<"hlmc"<<i+histNo1st<<ends;
		hnamermc<<"hrmc"<<i+histNo1st<<ends;

        	TH1D *hp = new TH1D(hname.str().data(),"",400.,ymin,ymax);
        	TH1D *hpl = new TH1D(hnamel.str().data(),"",400.,ymin,ymax);
        	TH1D *hpr = new TH1D(hnamer.str().data(),"",400.,ymin,ymax);
        	TH1D *hpmc = new TH1D(hnamemc.str().data(),"",400.,ymin,ymax);
        	TH1D *hplmc = new TH1D(hnamelmc.str().data(),"",400.,ymin,ymax);
        	TH1D *hprmc = new TH1D(hnamermc.str().data(),"",400.,ymin,ymax);

		/*stringstream cname;
		cname<<"c"<<i+histNo1st<<ends;
	        TCanvas *cp = new TCanvas(cname.str().data(),cname.str().data());
*/
		stringstream item,iteml,itemr;
		//item << "(-photonEMC+photonEAnl)/photonEMC>>" << hname.str().data() << ends;
		iteml << "photonEAnl>>" << hnamel.str().data() << ends;
		itemr << "photonEAnl>>" << hnamer.str().data() << ends;
		hAnll->Draw(iteml.str().data(),cut1+cut2+cut6+cutv[i]);
	 	hAnlr->Draw(itemr.str().data(),cut1+cut2+cut6+cutv[i]);
		*hp= (*hpl) * wl + (*hpr) * wr;
        	//hp->Draw("");

		stringstream itemmc,itemlmc,itemrmc;
		//item << "(-photonEMC+photonEAnl)/photonEMC>>" << hname.str().data() << ends;
		itemlmc << "photonEMC>>" << hnamelmc.str().data() << ends;
		itemrmc << "photonEMC>>" << hnamermc.str().data() << ends;
		hAnll->Draw(itemlmc.str().data(),cut1+cut2+cut6+cutv[i]);
	 	hAnlr->Draw(itemrmc.str().data(),cut1+cut2+cut6+cutv[i]);
		*hpmc= (*hplmc) * wl + (*hprmc) * wr;
        	//hpmc->Draw("");
		double mean0 = hp->GetMean();
		double sigma0= hp->GetRMS();
		//hp->Fit("Gaus",);
		meanPFO[i]=hp->GetMean();			
		rmsPFO[i]=hp->GetRMS();			

		meanMC[i]=hpmc->GetMean();			
		rmsMC[i]=hpmc->GetRMS();			


		}


	for (int i=0;i<kNhist;i++){
	        stringstream hnamec;	
	        stringstream hnamelc;	
	        stringstream hnamerc;	
		hnamec<<"hc"<<i+histNo1st<<ends;
		hnamelc<<"hlc"<<i+histNo1st<<ends;
		hnamerc<<"hrc"<<i+histNo1st<<ends;
        	TH1D *hpc = new TH1D(hnamec.str().data(),"",400.,ymin,ymax);
        	TH1D *hplc = new TH1D(hnamelc.str().data(),"",400.,ymin,ymax);
        	TH1D *hprc = new TH1D(hnamerc.str().data(),"",400.,ymin,ymax);

		/*stringstream cname;
		cname<<"c"<<i+histNo1st<<ends;
	        TCanvas *cp = new TCanvas(cname.str().data(),cname.str().data());
*/
		stringstream itemc,itemlc,itemrc;
		//item << "(-photonEMC+photonEAnl)/photonEMC>>" << hname.str().data() << ends;
		itemlc << "photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl)>>"<< hnamelc.str().data() << ends;
                itemrc << "photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl)>>"<< hnamerc.str().data() << ends;	

			hAnll->Draw(itemlc.str().data(),cut1+cut2+cut6+cutv[i]);
	 	        hAnlr->Draw(itemrc.str().data(),cut1+cut2+cut6+cutv[i]);

		*hpc= (*hplc) * wl + (*hprc) * wr;
		

		meanCB[i]=hpc->GetMean();			
		rmsCB[i]=hpc->GetRMS();			

		f[i]=meanCB[i]/meanPFO[i];
		cerr<<"f="<<f[i]<<endl;
		fMC[i]=meanMC[i]/meanPFO[i];
		cerr<<"fMC="<<fMC[i]<<endl;
		fMCCB[i]=meanCB[i]/meanMC[i];
		
		}



        TCanvas *c138 = new TCanvas("c138","c138");
	//TGraphErrors *f138 = new TGraphErrors(kNthetabins,ang,sig,ange,sige);
	TGraph *f138 = new TGraph(kNthetabins,ang,f);
	//f138->GetHistogram()->SetAxisRange(-kPi,kPi,"x");
        //f138->SetTitle("EmeanCaseB/EmeanPFO");
        //f68->SetXTitle("Energy Resolution of Photon");
        //f68->SetYTitle("");
        //f138->SetMinimum(.0);
	f138->Draw("AP");
	//f138->Draw("AP");
        f138->SetMarkerStyle(3);
	f138->SetMarkerColor(kAzure);
	f138->SetLineColor(kAzure);
 	//TGraphErrors *g138 = PhotonCase4SigmaTheta20(0,cutv,kNthetabins,ang);
 	//TGraphErrors *s138 = PhotonCase4SigmaTheta51(0,cutv,kNthetabins,ang);

	TGraph *f139 = new TGraph(kNthetabins,ang,fMC);
	//f138->GetHistogram()->SetAxisRange(-kPi,kPi,"x");
        //f139->SetTitle("EmeanMC/EmeanPFO");
        //f68->SetXTitle("Energy Resolution of Photon");
        //f68->SetYTitle("");
        //f138->SetMinimum(.0);
	f139->Draw("same P");
	//f138->Draw("AP");
        f139->SetMarkerStyle(3);
        f139->SetMarkerColor(3);
        f139->SetLineColor(3);

	TGraph *f140 = new TGraph(kNthetabins,ang,fMCCB);
	//f138->GetHistogram()->SetAxisRange(-kPi,kPi,"x");
        //f139->SetTitle("EmeanMC/EmeanPFO");
        //f68->SetXTitle("Energy Resolution of Photon");
        //f68->SetYTitle("");
        //f138->SetMinimum(.0);
	f140->Draw("same P");
	//f138->Draw("AP");
        f140->SetMarkerStyle(3);
        f140->SetMarkerColor(2);
        f140->SetLineColor(2);


	/*TLegend *legend = new TLegend( 0.15, 0.75, 0.45, 0.9) ; //（）の中は位置の指定（左下の x , y 、右上の x , y ）
	legend->AddEntry( f138, "EmeanCB/EmeanPFO" , "p") ; // AddEntry( pointer , "interpretation" , "option" )
	legend->AddEntry( f139, "EmeanMC/EmeanPFO" , "p") ; // option は　"f"=box, "l"="L"=line, "p"=marker
	legend->AddEntry( f140, "EmeanCB/EmeanMC" , "p") ; // option は　"f"=box, "l"="L"=line, "p"=marker
	legend->SetFillColor(0);
	legend->Draw() ;*/


	TLegend *legend = new TLegend( 0.15, 0.75, 0.45, 0.9) ; 
	legend->AddEntry( f138, "EmeanCB/EmeanPFO" , "p") ; 
	legend->AddEntry( f139, "EmeanMC/EmeanPFO" , "p") ; 
	legend->AddEntry( f140, "EmeanCB/EmeanMC" , "p") ; 
	legend->SetFillColor(0);
	legend->Draw() ;



}


