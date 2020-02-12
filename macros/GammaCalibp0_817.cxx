
#include "/home/ilc/mizunot/bin/root_macros/style.C"
#include "resocalc.cxx"

void GammaCalibp0_817() {

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
	int anll=hAnll->GetEntries();
	int anlr=hAnlr->GetEntries();
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


	double lep1EAnl, lep2EAnl,  lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl ,photonthetaMC, photonphiMC;
	double pdg0, mzgen,coneen;

	hAnll->SetBranchAddress("lep1EMC",&lep1EAnl);		
	hAnll->SetBranchAddress("lep2EMC",&lep2EAnl);		
	hAnll->SetBranchAddress("lep1thetaMC",&lep1thetaAnl);		
	hAnll->SetBranchAddress("lep2thetaMC",&lep2thetaAnl);		
	hAnll->SetBranchAddress("lep1phiMC",&lep1phiAnl);		
	hAnll->SetBranchAddress("lep2phiMC",&lep2phiAnl);		
	hAnll->SetBranchAddress("photonthetaMC",&photonthetaMC);		
	hAnll->SetBranchAddress("photonphiMC",&photonphiMC);		
	hAnll->SetBranchAddress("pdg0",&pdg0);		
	hAnll->SetBranchAddress("mzgen",&mzgen);		
	hAnll->SetBranchAddress("coneen",&coneen);		


	TCut cut1 = "pdg0==13 && abs(mzgen-91.2)<10";
	TCut cut3 = "coneen > -0.5";
	TCut cut4 = "abs(cos(photonthetaMC))<0.95";
        TCut cut6 = "abs(sin(photonphiMC))>=.1";
        TCut cut2 = cut3+cut4+cut6;

	std::vector<TCut> cutv; 
		
	
	const int kNthetabins = 20;
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



	double kPi   = TMath::Pi();

	const double kXmin = -.01;
	const double kXmax = .04;

	const int kNhist = cutv.size();
	cerr<<"cutvsize= " <<kNhist<<endl;
	const int histNo1st = 11;

	double ange[kNhist],sig[kNhist],sige[kNhist],ste[kNhist],stee[kNhist],numt[kNhist];


	
	int count=0;

	for(int i=0;i<anll;i++){ 
		hAnll->GetEntry(i);
		if( pdg0==13 && abs(mzgen-91.2)<10. && coneen > -0.5 && abs(sin(photonphiMC))>=.1){
				count++;
			}
		}

	double reso[count];
	double abcosth[count];

	int count2 =0;
	for(int i=0;i<anll;i++){ 
		hAnll->GetEntry(i);
		if( pdg0==13 && abs(mzgen-91.2)<10. && coneen > -0.5 && abs(sin(photonphiMC))>=.1){

		reso[count2] = abs(resocalc(Ecm, lep1EAnl, lep2EAnl,  lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl , photonthetaMC, photonphiMC));
		abcosth[count2]  = abs(cos(photonthetaMC));
		count2++;
		}

	}


	cout<<"count1= "<<count<<endl;
	cout<<"count2= "<<count2<<endl;

	TCanvas *c149 = new TCanvas("c149","c149");
        TGraph *f149 = new TGraph(count,abcosth,reso);
        //f149->GetXaxis()->SetRangeUser(-1.,1.);
        //f149->GetYaxis()->SetRangeUser(-.1,.1);
        //f149->GetXaxis()->SetLabelSize(0.05);
        f149->Draw("AP");
        //f149->GetXaxis()->SetRangeUser(-1.,1.);
        f149->GetXaxis()->SetLimits(-.025,1.025);
        f149->GetYaxis()->SetRangeUser(-.002,.027);
        //                f149->SetMarkerStyle(3);
        f149->SetMarkerSize(0.3);
        f149->SetMarkerColor(kOrange);
        //                                f149->SetLineColor(kAzure+10);



}


