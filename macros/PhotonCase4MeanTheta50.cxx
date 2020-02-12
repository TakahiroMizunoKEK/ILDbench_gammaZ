
//#include "/home/ilc/mizunot/bin/root_macros/style.C"

std::vector<double> PhotonCase4MeanTheta50(int a){ 
//void PhotonCase4SigmaTheta(){ 

        stringstream filest;
        filest << "../root_merge.mILD_l5_o1_v02/"
               << "2f_z_l.eL.pR.mILD_l5_o1_v02.root" << ends;

        TFile *f = new TFile(filest.str().data());
	
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
        TCut cut2 = cut3;
        TCut cut6 = "abs(sin(photonphiMC))<=1.";

        const int kNhist = 6;
        TCut cutv[kNhist];

        cutv[0] = "abs(cos(photonthetaMC))<0.2";
        cutv[1] = "abs(cos(photonthetaMC))>=0.2 && abs(cos(photonthetaMC))<0.4";
        cutv[2] = "abs(cos(photonthetaMC))>=0.4 && abs(cos(photonthetaMC))<0.6";
        cutv[3] = "abs(cos(photonthetaMC))>=0.6 && abs(cos(photonthetaMC))<0.8";
        cutv[4] = "abs(cos(photonthetaMC))>=0.8 && abs(cos(photonthetaMC))<0.9";
        cutv[5] = "abs(cos(photonthetaMC))>=0.9";

/*        cutv[6] = "abs(sin(photonphiMC))<0.1";
        cutv[7] = "abs(sin(photonphiMC))>=0.1 && abs(sin(photonphiMC))<0.2";
        cutv[8] = "abs(sin(photonphiMC))>=0.2 && abs(sin(photonphiMC))<0.4";
        cutv[9] = "abs(sin(photonphiMC))>=0.4 && abs(sin(photonphiMC))<0.6";
        cutv[10] = "abs(sin(photonphiMC))>=0.6 && abs(sin(photonphiMC))<0.8";
        cutv[11] = "abs(sin(photonphiMC))>=0.8";*/


        const double kXmin = -.01;
        const double kXmax = .01;

        const int histNo1st = 51;

/*        double ange[12],sig[12],sige[12],ste[12],stee[12],numt[12];
        double ang[] = {.1,.3,.5,.7,.85,.95,.05,.15,.3,.5,.7,.9};
*/
        double ange[6],sig[6],sige[6],ste[6],stee[6],numt[6];
        double ang[] = {.1,.3,.5,.7,.85,.95};
	

	for (int i=0;i<kNhist;i++){
	        stringstream hname;	
		hname<<"h"<<i+histNo1st<<ends;
        	TH1D *hp = new TH1D(hname.str().data(),"",400.,-.2,.2);

		//stringstream cname;
		//cname<<"c"<<i+histNo1st<<ends;
	        //TCanvas *cp = new TCanvas(cname.str().data(),cname.str().data());
		
		stringstream item;
        	item << "(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>"<< hname.str().data() << ends;
	        hAnl->Draw(item.str().data(),cut1+cut2+cutv[i]);
		hp->SetTitle("Energy Resolution of Photon");
	        hp->SetXTitle("Energy Resolution of Photon");
	        hp->SetYTitle("");
//       	hp->Draw("");


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
 	        sig [i] = fp->GetParameter(1);
 	        sige[i] = fp->GetParError(1);
 	        ste [i] = sig[i]/sqrt(numt[i]);
 	        stee[i] = sige[i]/sqrt(numt[i]);

	}




        //std::vector<double> *vecC4{sig[0],sig[1],sig[2],sig[3],sig[4],sig[5]};
        //std::vector<double> *vecC4E{sige[0],sige[1],sige[2],sige[3],sige[4],sige[5]};
	std::vector<double> vecC4;
        std::vector<double> vecC4E;

        for (int u=0;u<6;u++){
                vecC4.push_back(sig[u]);
                vecC4E.push_back(sige[u]);
        }

        if (a == 0){
                return vecC4;
        } else if(a == 1){
                return vecC4E;
        }

        return vecC4;


}
