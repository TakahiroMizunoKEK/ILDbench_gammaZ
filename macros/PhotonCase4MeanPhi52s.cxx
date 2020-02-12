
//#include "/home/ilc/mizunot/bin/root_macros/style.C"
//#include "photonERec6.cxx"
//#include "photonERec63.cxx"

TGraphErrors *PhotonCase4MeanPhi52s(int a, const std::vector<TCut> &cutv, int offset, const int kNhist,
				    const double ang[]){ 
//void PhotonCase4SigmaPhi(){ 

        stringstream filestl;
        stringstream filestr;

        filestl << "../root_merge.mILD_s5_o1_v02/"
               << "2f_z_l.eL.pR.mILD_s5_o1_v02.root" << ends;

        filestr << "../root_merge.mILD_s5_o1_v02/"
               << "2f_z_l.eR.pL.mILD_s5_o1_v02.root" << ends;

        TFile *fl = new TFile(filestl.str().data());
        TFile *fr = new TFile(filestr.str().data());
	
	//setILDStyle();
	//gStyle->SetPadRightMargin(1.0);
/*	/gStyle->SetPadRightMargin(1.0);
	gStyle->SetOptStat(1000001110);
        gStyle->SetStatH(0.15);
        gStyle->SetStatW(0.15);
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

	Int_t nbinx   = 520;	
	Double_t xmin = -10.; 
	Double_t xmax = 510.; 	

	Int_t nbiny   = 520;	
	Double_t ymin = -10.; 
	Double_t ymax = 510.; 	

	TCut cut1 = "pdg0==13 && abs(mzgen-91.2)<10";
	TCut cut3 = "coneen > -0.5";
	//TCut cut4 = "abs(coslep1)<0.75 && abs(coslep2)<0.75";
	TCut cut4 = "abs(cos(photonthetaMC))<0.95";
        TCut cut2 = cut3;
        TCut cut6 = "abs(sin(photonphiMC))>=.1";
        //TCut cut2 = cut3+cut4+cut6;

/*        const int kNhist = 
        TCut cutv[kNhist];
*/
/*        cutv[0] = "abs(cos(photonthetaMC))<0.2";
        cutv[1] = "abs(cos(photonthetaMC))>=0.2 && abs(cos(photonthetaMC))<0.4";
        cutv[2] = "abs(cos(photonthetaMC))>=0.4 && abs(cos(photonthetaMC))<0.6";
        cutv[3] = "abs(cos(photonthetaMC))>=0.6 && abs(cos(photonthetaMC))<0.8";
        cutv[4] = "abs(cos(photonthetaMC))>=0.8 && abs(cos(photonthetaMC))<0.9";
        cutv[5] = "abs(cos(photonthetaMC))>=0.9";*/

        /*cutv[0]  = "photonphiMC<-2.";
        cutv[1]  = "photonphiMC>=-2. && photonphiMC<-1.";
        cutv[2]  = "photonphiMC>=-1. && photonphiMC<-.3";
        cutv[3]  = "photonphiMC>=-.3 && photonphiMC<-.1";
        cutv[4] = "photonphiMC>=-.1 && photonphiMC<.1";
        cutv[5] = "photonphiMC>=.1 && photonphiMC<.3";
        cutv[6] = "photonphiMC>=.3 && photonphiMC<1.";
        cutv[7] = "photonphiMC>=1. && photonphiMC<2.";
        cutv[8] = "photonphiMC>=2";*/



        const double kXmin = -.01;
        const double kXmax = .01;

        const int histNo1st = 201;

/*        double ange[12],sig[12],sige[12],ste[12],stee[12],numt[12];
        double ang[] = {.1,.3,.5,.7,.85,.95,.05,.15,.3,.5,.7,.9};
*/
        double ange[kNhist],sig[kNhist],sige[kNhist],ste[kNhist],stee[kNhist],numt[kNhist];
//        double ang[] = {.1,.3,.5,.7,.85,.95};
//	  double ang[] = {.025,.1,.2,.325,.5,.7,.9};
	//double ang[] = {3.14*(-6.)/7.,3.14*(-4.)/7.,3.14*(-2.)/7.,0.,3.14*(2.)/7.,3.14*(4.)/7.,3.14*(6.)/7.};
	//double ang[] = {-2.57,-1.5,-0.65,-0.2,0.,0.2,0.65,1.5,2.57};

	for (int i=0;i<kNhist;i++){
	        stringstream hname;	
	        stringstream hnamel;	
	        stringstream hnamer;	
		hname<<"h"<<i+histNo1st<<ends;
		hnamel<<"hl"<<i+histNo1st<<ends;
		hnamer<<"hr"<<i+histNo1st<<ends;
        	TH1D *hp = new TH1D(hname.str().data(),"",200.,-.2,.2);
        	TH1D *hpl = new TH1D(hnamel.str().data(),"",200.,-.2,.2);
        	TH1D *hpr = new TH1D(hnamer.str().data(),"",200.,-.2,.2);

		/*stringstream cname;
		cname<<"cs"<<i+histNo1st<<ends;
	        TCanvas *cp = new TCanvas(cname.str().data(),cname.str().data());
		*/
		stringstream item,iteml,itemr;
        	//item << "(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>"<< hname.str().data() << ends;
        	iteml << "(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaMC,photonphiMC))/photonEMC>>"<< hnamel.str().data() << ends;
        	itemr << "(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaMC,photonphiMC))/photonEMC>>"<< hnamer.str().data() << ends;

	        hAnll->Draw(iteml.str().data(),cut1+cut2+cut4+cutv[i+offset]);
	        hAnlr->Draw(itemr.str().data(),cut1+cut2+cut4+cutv[i+offset]);
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
		double mean  = hp->GetFunction(fname.str().data())->GetParameter(1);
		double sigma = hp->GetFunction(fname.str().data())->GetParameter(2);
		double xmin  = mean-2.5*sigma;
		double xmax  = mean+2.5*sigma;
		hp->Fit(fname.str().data(),"Q","",xmin,xmax);

	        double numi = hp->Integral(hp->FindFixBin(xmin),hp->FindFixBin(xmax));
	        numt[i] = numi;
	        cout << "C4SP_num" << i+ histNo1st << "= " << numt[i] << endl;
		ange[i] = 0.;
 	        sig [i] = fp->GetParameter(1);
 	        sige[i] = fp->GetParError(1);
 	        ste [i] = sig[i]/sqrt(numt[i]);
 	        stee[i] = sige[i]/sqrt(numt[i]);

	}




        //TCanvas *c68 = new TCanvas("c68");
	TGraphErrors *f68 = new TGraphErrors(kNhist,&ang[offset],sig,ange,sige);
	//cerr<<"f68= "<<(void*) f68<<endl;
        //f68->SetTitle("Energy Resolution of Photon");
        //f68->SetXTitle("Energy Resolution of Photon");
        //f68->SetYTitle("");
        f68->SetMinimum(.0);
	//f68->Draw("AP");
        f68->SetLineColor(kGreen-3);

        //TCanvas *c69 = new TCanvas("c69");
	TGraphErrors *f69 = new TGraphErrors(kNhist,&ang[offset],ste,ange,stee);
        //f68->SetTitle("Energy Resolution of Photon");
        //f68->SetXTitle("Energy Resolution of Photon");
        //f68->SetYTitle("");
        f69->SetMinimum(.0);
	//f69->Draw("AP");
        f69->SetLineColor(kGreen-3);
	if (a == 0){
		return f68;
	} else if(a == 1){
		return f69;
	}

	return 0;	

}
