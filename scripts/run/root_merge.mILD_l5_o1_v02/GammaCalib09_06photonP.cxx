
#include "/home/ilc/mizunot/bin/root_macros/style.C"
#include "photonERec5.cxx"
#include "photonERec6.cxx"
#include "photonERec53.cxx"
#include "photonERec63.cxx"

void GammaCalib09_06photonP() {

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


        TH1D *h31 = new TH1D("h31","",400.,-.2,.2);
        TH1D *h32 = new TH1D("h32","",400.,-.2,.2);
        TH1D *h33 = new TH1D("h33","",400.,-.2,.2);
        TH1D *h34 = new TH1D("h34","",400.,-.2,.2);
        TH1D *h35 = new TH1D("h35","",400.,-.2,.2);
        TH1D *h36 = new TH1D("h36","",400.,-.2,.2);
        TH1D *h37 = new TH1D("h37","",400.,-.2,.2);

        TH1D *h41 = new TH1D("h41","",400.,-.2,.2);
        TH1D *h42 = new TH1D("h42","",400.,-.2,.2);
        TH1D *h43 = new TH1D("h43","",400.,-.2,.2);
        TH1D *h44 = new TH1D("h44","",400.,-.2,.2);
        TH1D *h45 = new TH1D("h45","",400.,-.2,.2);
        TH1D *h46 = new TH1D("h46","",400.,-.2,.2);
        TH1D *h47 = new TH1D("h47","",400.,-.2,.2);

        TH1D *h61 = new TH1D("h61","",400.,-.2,.2);
        TH1D *h62 = new TH1D("h62","",400.,-.2,.2);
        TH1D *h63 = new TH1D("h63","",400.,-.2,.2);
        TH1D *h64 = new TH1D("h64","",400.,-.2,.2);
        TH1D *h65 = new TH1D("h65","",400.,-.2,.2);
        TH1D *h66 = new TH1D("h66","",400.,-.2,.2);
        TH1D *h67 = new TH1D("h67","",400.,-.2,.2);

        TH1D *h71 = new TH1D("h71","",400.,-.2,.2);
        TH1D *h72 = new TH1D("h72","",400.,-.2,.2);
        TH1D *h73 = new TH1D("h73","",400.,-.2,.2);
        TH1D *h74 = new TH1D("h74","",400.,-.2,.2);
        TH1D *h75 = new TH1D("h75","",400.,-.2,.2);
        TH1D *h76 = new TH1D("h76","",400.,-.2,.2);
        TH1D *h77 = new TH1D("h77","",400.,-.2,.2);


	TCut cut1 = "pdg0==13 && abs(mzgen-91.2)<10";
	TCut cut3 = "coneen > -0.5";
	TCut cut4 = "abs(coslep1)<0.75 && abs(coslep2)<0.75";
        //TCut cut2 = cut3+cut4;
        TCut cut2 = cut3;

	TCut cut51 = "abs(sin(photonthetaMC))<0.2";
	TCut cut52 = "abs(sin(photonthetaMC))>=0.2 && abs(sin(photonthetaMC))<0.4";
	TCut cut53 = "abs(sin(photonthetaMC))>=0.4 && abs(sin(photonthetaMC))<0.6";
	TCut cut54 = "abs(sin(photonthetaMC))>=0.6 && abs(sin(photonthetaMC))<0.8";
	TCut cut55 = "abs(sin(photonthetaMC))>=0.8 && abs(sin(photonthetaMC))<0.9";
	TCut cut56 = "abs(sin(photonthetaMC))>=0.9";

	//TCut cut7 = "abs(cos(photonthetaMC))<0.8";
	TCut cut7 = "abs(cos(photonthetaMC))<1.1";
        TCut cut72 = "abs(sin(photonphiMC))<0.1";
        TCut cut73 = "abs(sin(photonphiMC))>=0.1 && abs(sin(photonphiMC))<0.2";
        TCut cut74 = "abs(sin(photonphiMC))>=0.2 && abs(sin(photonphiMC))<0.4";
        TCut cut75 = "abs(sin(photonphiMC))>=0.4 && abs(sin(photonphiMC))<0.6";
        TCut cut76 = "abs(sin(photonphiMC))>=0.6 && abs(sin(photonphiMC))<0.8";
        TCut cut77 = "abs(sin(photonphiMC))>=0.8";

        TCut cut6 = "abs(sin(photonphiMC))<=1.";

/*

        TCanvas *c31 = new TCanvas("c31");
        hAnl->Draw("(-photonEMC+photonERec5(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h31",cut1+cut2);
        h31->SetTitle("Energy Resolution of Photon");
        h31->SetXTitle("Energy Resolution of Photon");
        h31->SetYTitle("");        
	h31->Draw("");
	TF1 *f31 = new TF1("f31","gaus",-.012,.012);
        f31->SetLineColor(kRed);
	h31->Fit("f31","","",-.01,.01);
	
	double num31,sig31,se31;
	int numi31 = h31->Integral(h31->FindFixBin(-.01),h31->FindFixBin(.01));
	num31 = numi31;
	cout<<"num31 = "<<num31<<endl;	
	sig31= f31->GetParameter(2);	
	cout<<"sig31 = "<<sig31<<endl;
	se31= sig31/num31;
	cout<<"se31 = "<<se31<<endl;


	double ang5[6],ange5[6],sig5[6],sige5[6],ste5[6],stee5[6],numt5[6];


        TCanvas *c32 = new TCanvas("c32");
        hAnl->Draw("(-photonEMC+photonERec5(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h32",cut1+cut2+cut51+cut6);
        h32->SetTitle("Energy Resolution of Photon");
        h32->SetXTitle("Energy Resolution of Photon");
        h32->SetYTitle("");
        h32->Draw("");
        TF1 *f32 = new TF1("f32","gaus",-.012,.012);
        f32->SetLineColor(kRed);
        h32->Fit("f32","","",-.01,.01);

        double num32,sig32,se32;
        int numi32 = h32->Integral(h32->FindFixBin(-.01),h32->FindFixBin(.01));
        num32 = numi32;
        numt5[0] = numi32;
        cout<<"num32 = "<<num32<<endl;
	ang5[0]=0.1;
	sig5[0]=f32->GetParameter(2);
	sige5[0]=f32->GetParError(2);
        se32= sig32/sqrt(num32);


        TCanvas *c33 = new TCanvas("c33");
        hAnl->Draw("(-photonEMC+photonERec5(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h33",cut1+cut2+cut52+cut6);
        h33->SetTitle("Energy Resolution of Photon");
        h33->SetXTitle("Energy Resolution of Photon");
        h33->SetYTitle("");
        h33->Draw("");
        TF1 *f33 = new TF1("f33","gaus",-.012,.012);
        f33->SetLineColor(kOrange);
        h33->Fit("f33","","",-.01,.01);

        double num33,sig33,se33;
        int numi33 = h33->Integral(h33->FindFixBin(-.01),h33->FindFixBin(.01));
        num33 = numi33;
        numt5[1] = numi33;
        cout<<"num33 = "<<num33<<endl;
	ang5[1]=0.3;
	sig5[1]=f33->GetParameter(2);
	sige5[1]=f33->GetParError(2);
        se33= sig33/sqrt(num33);


        TCanvas *c34 = new TCanvas("c34");
        hAnl->Draw("(-photonEMC+photonERec5(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h34",cut1+cut2+cut53+cut6);
        h34->SetTitle("Energy Resolution of Photon");
        h34->SetXTitle("Energy Resolution of Photon");
        h34->SetYTitle("");
        h34->Draw("");
        TF1 *f34 = new TF1("f34","gaus",-.012,.012);
        f34->SetLineColor(kGreen);
        h34->Fit("f34","","",-.01,.01);

        double num34,sig34,se34;
        int numi34 = h34->Integral(h34->FindFixBin(-.01),h34->FindFixBin(.01));
        num34 = numi34;
        numt5[2] = numi34;
        cout<<"num34 = "<<num34<<endl;
	ang5[2]=0.5;
	sig5[2]=f34->GetParameter(2);
	sige5[2]=f34->GetParError(2);
        se34= sig34/sqrt(num34);


        TCanvas *c35 = new TCanvas("c35");
        hAnl->Draw("(-photonEMC+photonERec5(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h35",cut1+cut2+cut54+cut6);
        h35->SetTitle("Energy Resolution of Photon");
        h35->SetXTitle("Energy Resolution of Photon");
        h35->SetYTitle("");
        h35->Draw("");
        TF1 *f35 = new TF1("f35","gaus",-.012,.012);
        f35->SetLineColor(kTeal);
        h35->Fit("f35","","",-.01,.01);

        double num35,sig35,se35;
        int numi35 = h35->Integral(h35->FindFixBin(-.01),h35->FindFixBin(.01));
        num35 = numi35;
        numt5[3] = numi35;
        cout<<"num35 = "<<num35<<endl;
	ang5[3]=0.7;
	sig5[3]=f35->GetParameter(2);
	sige5[3]=f35->GetParError(2);
        se35= sig35/sqrt(num35);


        TCanvas *c36 = new TCanvas("c36");
        hAnl->Draw("(-photonEMC+photonERec5(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h36",cut1+cut2+cut55+cut6);
        h36->SetTitle("Energy Resolution of Photon");
        h36->SetXTitle("Energy Resolution of Photon");
        h36->SetYTitle("");
        h36->Draw("");
        TF1 *f36 = new TF1("f36","gaus",-.012,.012);
        f36->SetLineColor(kBlue);
        h36->Fit("f36","","",-.01,.01);

        double num36,sig36,se36;
        int numi36 = h36->Integral(h36->FindFixBin(-.01),h36->FindFixBin(.01));
        num36 = numi36;
        numt5[4] = numi36;
        cout<<"num36 = "<<num36<<endl;
	ang5[4]=0.85;
	sig5[4]=f36->GetParameter(2);
	sige5[4]=f36->GetParError(2);
        se36= sig36/sqrt(num36);


        TCanvas *c37 = new TCanvas("c37");
        hAnl->Draw("(-photonEMC+photonERec5(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h37",cut1+cut2+cut56+cut6);
        h37->SetTitle("Energy Resolution of Photon");
        h37->SetXTitle("Energy Resolution of Photon");
        h37->SetYTitle("");
        h37->Draw("");
        TF1 *f37 = new TF1("f37","gaus",-.012,.012);
        f37->SetLineColor(kViolet);
        h37->Fit("f37","","",-.01,.01);

        double num37,sig37,se37;
        int numi37 = h37->Integral(h37->FindFixBin(-.01),h37->FindFixBin(.01));
        num37 = numi37;
        numt5[5] = numi37;
        cout<<"num37 = "<<num37<<endl;
	ang5[5]=0.95;
	sig5[5]=f37->GetParameter(2);
	sige5[5]=f37->GetParError(2);
        se37= sig37/sqrt(num37);

	for (int ii=0;ii<6;ii++){
		ange5[ii]=0.;
		ste5[ii]=sig5[ii]/sqrt(numt5[ii]);
		stee5[ii]=sige5[ii]/sqrt(numt5[ii]);
	}


        TCanvas *c38 = new TCanvas("c38");
	TGraph *f38 = new TGraphErrors(6,ang5,sig5,ange5,sige5);
        //f68->SetTitle("Energy Resolution of Photon");
        //f68->SetXTitle("Energy Resolution of Photon");
        //f68->SetYTitle("");
        f38->SetMinimum(.0);
	f38->Draw("");
        f38->SetLineColor(kGreen-3);


        TCanvas *c39 = new TCanvas("c39");
	TGraph *f39 = new TGraphErrors(6,ang5,ste5,ange5,stee5);
        //f68->SetTitle("Energy Resolution of Photon");
        //f68->SetXTitle("Energy Resolution of Photon");
        //f68->SetYTitle("");
        f39->SetMinimum(.0);
	f39->Draw("");
        f39->SetLineColor(kGreen-3);




        TCanvas *c41 = new TCanvas("c41");
        hAnl->Draw("(-photonEMC+photonERec5(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h41",cut1+cut2+cut7);
        h41->SetTitle("Energy Resolution of Photon");
        h41->SetXTitle("Energy Resolution of Photon");
        h41->SetYTitle("");
        h41->Draw("");
        TF1 *f41 = new TF1("f41","gaus",-.012,.012);
        f41->SetLineColor(kRed);
        h41->Fit("f41","","",-.01,.01);

        double num41,sig41,se41;
        int numi41 = h41->Integral(h41->FindFixBin(-.01),h41->FindFixBin(.01));
        num41 = numi41;
        cout<<"num41 = "<<num41<<endl;
        sig41= f41->GetParameter(2);
        cout<<"sig41 = "<<sig41<<endl;
        se41= sig41/num41;
        cout<<"se41 = "<<se41<<endl;


        double angp5[6],angpe5[6],sigp5[6],sigep5[6],step5[6],steep5[6],nump5[6];


        TCanvas *c42 = new TCanvas("c42");
        hAnl->Draw("(-photonEMC+photonERec5(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h42",cut1+cut2+cut7+cut72);
        h42->SetTitle("Energy Resolution of Photon");
        h42->SetXTitle("Energy Resolution of Photon");
        h42->SetYTitle("");
        h42->Draw("");
        TF1 *f42 = new TF1("f42","gaus",-.012,.012);
        f42->SetLineColor(kRed);
        h42->Fit("f42","","",-.01,.01);

        double num42;
        int numi42 = h42->Integral(h42->FindFixBin(-.01),h42->FindFixBin(.01));
        num42 = numi42;
        nump5[0] = numi42;
        cout<<"num42 = "<<num42<<endl;
        angp5[0]=0.05;
        sigp5[0]=f42->GetParameter(2);
        sigep5[0]=f42->GetParError(2);
        //se72= sig72/sqrt(num72);

        TCanvas *c43 = new TCanvas("c43");
        hAnl->Draw("(-photonEMC+photonERec5(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h43",cut1+cut2+cut7+cut73);
        h43->SetTitle("Energy Resolution of Photon");
        h43->SetXTitle("Energy Resolution of Photon");
        h43->SetYTitle("");
        h43->Draw("");
        TF1 *f43 = new TF1("f43","gaus",-.012,.012);
        f43->SetLineColor(kOrange);
        h43->Fit("f43","","",-.01,.01);

        double num43;
        int numi43 = h43->Integral(h43->FindFixBin(-.01),h43->FindFixBin(.01));
        num43 = numi43;
        nump5[1] = numi43;
        cout<<"num43 = "<<num43<<endl;
        angp5[1]=0.15;
        sigp5[1]=f43->GetParameter(2);
        sigep5[1]=f43->GetParError(2);
        //se73= sig73/sqrt(num73);

        TCanvas *c44 = new TCanvas("c44");
        hAnl->Draw("(-photonEMC+photonERec5(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h44",cut1+cut2+cut7+cut74);
        h44->SetTitle("Energy Resolution of Photon");
        h44->SetXTitle("Energy Resolution of Photon");
        h44->SetYTitle("");
        h44->Draw("");
        TF1 *f44 = new TF1("f44","gaus",-.012,.012);
        f44->SetLineColor(kGreen);
        h44->Fit("f44","","",-.01,.01);

        double num44;
        int numi44 = h44->Integral(h44->FindFixBin(-.01),h44->FindFixBin(.01));
        num44 = numi44;
        nump5[2] = numi44;
        cout<<"num44 = "<<num44<<endl;
        angp5[2]=0.3;
        sigp5[2]=f44->GetParameter(2);
        sigep5[2]=f44->GetParError(2);
      //  se74= sig74/sqrt(num74);

        TCanvas *c45 = new TCanvas("c45");
        hAnl->Draw("(-photonEMC+photonERec5(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h45",cut1+cut2+cut7+cut75);
        h45->SetTitle("Energy Resolution of Photon");
        h45->SetXTitle("Energy Resolution of Photon");
        h45->SetYTitle("");
        h45->Draw("");
        TF1 *f45 = new TF1("f45","gaus",-.012,.012);
        f45->SetLineColor(kTeal);
        h45->Fit("f45","","",-.01,.01);

        double num45;
        int numi45 = h45->Integral(h45->FindFixBin(-.01),h45->FindFixBin(.01));
        num45 = numi45;
        nump5[3] = numi45;
        cout<<"num45 = "<<num45<<endl;
        angp5[3]=0.5;
        sigp5[3]=f45->GetParameter(2);
        sigep5[3]=f45->GetParError(2);
    //    se75= sig75/sqrt(num75);

        TCanvas *c46 = new TCanvas("c46");
        hAnl->Draw("(-photonEMC+photonERec5(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h46",cut1+cut2+cut7+cut76);
        h46->SetTitle("Energy Resolution of Photon");
        h46->SetXTitle("Energy Resolution of Photon");
        h46->SetYTitle("");
        h46->Draw("");
        TF1 *f46 = new TF1("f46","gaus",-.012,.012);
        f46->SetLineColor(kBlue);
        h46->Fit("f46","","",-.01,.01);

        double num46;
        int numi46 = h46->Integral(h46->FindFixBin(-.01),h46->FindFixBin(.01));
        num46 = numi46;
        nump5[4] = numi46;
        cout<<"num46 = "<<num46<<endl;
        angp5[4]=0.7;
        sigp5[4]=f46->GetParameter(2);
        sigep5[4]=f46->GetParError(2);
  //      se76= sig76/sqrt(num76);

        TCanvas *c47 = new TCanvas("c47");
        hAnl->Draw("(-photonEMC+photonERec5(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h47",cut1+cut2+cut7+cut77);
        h47->SetTitle("Energy Resolution of Photon");
        h47->SetXTitle("Energy Resolution of Photon");
        h47->SetYTitle("");
        h47->Draw("");
        TF1 *f47 = new TF1("f47","gaus",-.012,.012);
        f47->SetLineColor(kViolet);
        h47->Fit("f47","","",-.01,.01);

        double num47;
        int numi47 = h47->Integral(h47->FindFixBin(-.01),h47->FindFixBin(.01));
        num47 = numi47;
        nump5[5] = numi47;
        cout<<"num47 = "<<num47<<endl;
        angp5[5]=0.9;
        sigp5[5]=f47->GetParameter(2);
        sigep5[5]=f47->GetParError(2);
//        se77= sig77/sqrt(num77);

        for (int ii=0;ii<6;ii++){
                angpe5[ii]=0.;
		step5[ii]=sigp5[ii]/sqrt(nump5[ii]);
		steep5[ii]=sigep5[ii]/sqrt(nump5[ii]);
		}

        TCanvas *c48 = new TCanvas("c48");
        TGraph *f48 = new TGraphErrors(6,angp5,sigp5,angpe5,sigep5);
	f48->SetMinimum(.0);
        f48->Draw("");
        f48->SetLineColor(kOrange+7);

        TCanvas *c49 = new TCanvas("c49");
        TGraph *f49 = new TGraphErrors(6,angp5,step5,angpe5,steep5);
	f49->SetMinimum(.0);
        f49->Draw("");
        f49->SetLineColor(kOrange+7);



        TCanvas *c61 = new TCanvas("c61");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h61",cut1+cut2);
        h61->SetTitle("Energy Resolution of Photon");
        h61->SetXTitle("Energy Resolution of Photon");
        h61->SetYTitle("");        
	h61->Draw("");
	TF1 *f61 = new TF1("f61","gaus",-.012,.012);
        f61->SetLineColor(kRed);
	h61->Fit("f61","","",-.01,.01);
	
	double num61,sig61,se61;
	int numi61 = h61->Integral(h61->FindFixBin(-.01),h61->FindFixBin(.01));
	num61 = numi61;
	cout<<"num61 = "<<num61<<endl;	
	sig61= f61->GetParameter(2);	
	cout<<"sig61 = "<<sig61<<endl;
	se61= sig61/num61;
	cout<<"se61 = "<<se61<<endl;


	double ang[6],sig[6],ange[6],sige[6],ste[6],stee[6],numt[6];


        TCanvas *c62 = new TCanvas("c62");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h62",cut1+cut2+cut51+cut6);
        h62->SetTitle("Energy Resolution of Photon");
        h62->SetXTitle("Energy Resolution of Photon");
        h62->SetYTitle("");
        h62->Draw("");
        TF1 *f62 = new TF1("f62","gaus",-.012,.012);
        f62->SetLineColor(kRed);
        h62->Fit("f62","","",-.01,.01);

        double num62,sig62,se62;
        int numi62 = h62->Integral(h62->FindFixBin(-.01),h62->FindFixBin(.01));
        num62 = numi62;
        numt[0] = numi62;
        cout<<"num62 = "<<num62<<endl;
	ang[0]=0.1;
	sig[0]=f62->GetParameter(2);
	sige[0]=f62->GetParError(2);
        se62= sig62/sqrt(num62);


        TCanvas *c63 = new TCanvas("c63");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h63",cut1+cut2+cut52+cut6);
        h63->SetTitle("Energy Resolution of Photon");
        h63->SetXTitle("Energy Resolution of Photon");
        h63->SetYTitle("");
        h63->Draw("");
        TF1 *f63 = new TF1("f63","gaus",-.012,.012);
        f63->SetLineColor(kOrange);
        h63->Fit("f63","","",-.01,.01);

        double num63,sig63,se63;
        int numi63 = h63->Integral(h63->FindFixBin(-.01),h63->FindFixBin(.01));
        num63 = numi63;
        numt[1] = numi63;
        cout<<"num63 = "<<num63<<endl;
	ang[1]=0.3;
	sig[1]=f63->GetParameter(2);
	sige[1]=f63->GetParError(2);
        se63= sig63/sqrt(num63);


        TCanvas *c64 = new TCanvas("c64");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h64",cut1+cut2+cut53+cut6);
        h64->SetTitle("Energy Resolution of Photon");
        h64->SetXTitle("Energy Resolution of Photon");
        h64->SetYTitle("");
        h64->Draw("");
        TF1 *f64 = new TF1("f64","gaus",-.012,.012);
        f64->SetLineColor(kGreen);
        h64->Fit("f64","","",-.01,.01);

        double num64,sig64,se64;
        int numi64 = h64->Integral(h64->FindFixBin(-.01),h64->FindFixBin(.01));
        num64 = numi64;
        numt[2] = numi64;
        cout<<"num64 = "<<num64<<endl;
	ang[2]=0.5;
	sig[2]=f64->GetParameter(2);
	sige[2]=f64->GetParError(2);
        se64= sig64/sqrt(num64);


        TCanvas *c65 = new TCanvas("c65");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h65",cut1+cut2+cut54+cut6);
        h65->SetTitle("Energy Resolution of Photon");
        h65->SetXTitle("Energy Resolution of Photon");
        h65->SetYTitle("");
        h65->Draw("");
        TF1 *f65 = new TF1("f65","gaus",-.012,.012);
        f65->SetLineColor(kTeal);
        h65->Fit("f65","","",-.01,.01);

        double num65,sig65,se65;
        int numi65 = h65->Integral(h65->FindFixBin(-.01),h65->FindFixBin(.01));
        num65 = numi65;
        numt[3] = numi65;
        cout<<"num65 = "<<num65<<endl;
	ang[3]=0.7;
	sig[3]=f65->GetParameter(2);
	sige[3]=f65->GetParError(2);
        se65= sig65/sqrt(num65);


        TCanvas *c66 = new TCanvas("c66");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h66",cut1+cut2+cut55+cut6);
        h66->SetTitle("Energy Resolution of Photon");
        h66->SetXTitle("Energy Resolution of Photon");
        h66->SetYTitle("");
        h66->Draw("");
        TF1 *f66 = new TF1("f66","gaus",-.012,.012);
        f66->SetLineColor(kBlue);
        h66->Fit("f66","","",-.01,.01);

        double num66,sig66,se66;
        int numi66 = h66->Integral(h66->FindFixBin(-.01),h66->FindFixBin(.01));
        num66 = numi66;
        numt[4] = numi66;
        cout<<"num66 = "<<num66<<endl;
	ang[4]=0.85;
	sig[4]=f66->GetParameter(2);
	sige[4]=f66->GetParError(2);
        se66= sig66/sqrt(num66);


        TCanvas *c67 = new TCanvas("c67");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h67",cut1+cut2+cut56+cut6);
        h67->SetTitle("Energy Resolution of Photon");
        h67->SetXTitle("Energy Resolution of Photon");
        h67->SetYTitle("");
        h67->Draw("");
        TF1 *f67 = new TF1("f67","gaus",-.012,.012);
        f67->SetLineColor(kViolet);
        h67->Fit("f67","","",-.01,.01);

        double num67,sig67,se67;
        int numi67 = h67->Integral(h67->FindFixBin(-.01),h67->FindFixBin(.01));
        num67 = numi67;
        numt[5] = numi67;
        cout<<"num67 = "<<num67<<endl;
	ang[5]=0.95;
	sig[5]=f67->GetParameter(2);
	sige[5]=f67->GetParError(2);
        se67= sig67/sqrt(num67);

	for (int ii=0;ii<6;ii++){
		ange[ii]=0.;
		ste[ii]=sig[ii]/sqrt(numt[ii]);
		stee[ii]=sige[ii]/sqrt(numt[ii]);
	}


        TCanvas *c68 = new TCanvas("c68");
	TGraph *f68 = new TGraphErrors(6,ang,sig,ange,sige);
        //f68->SetTitle("Energy Resolution of Photon");
        //f68->SetXTitle("Energy Resolution of Photon");
        //f68->SetYTitle("");
        f68->SetMinimum(.0);
	f68->Draw("");
        f68->SetLineColor(kGreen-3);

        TCanvas *c69 = new TCanvas("c69");
	TGraph *f69 = new TGraphErrors(6,ang,ste,ange,stee);
        //f68->SetTitle("Energy Resolution of Photon");
        //f68->SetXTitle("Energy Resolution of Photon");
        //f68->SetYTitle("");
        f69->SetMinimum(.0);
	f69->Draw("");
        f69->SetLineColor(kGreen-3);

        TCanvas *c71 = new TCanvas("c71");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h71",cut1+cut2+cut7);
        h71->SetTitle("Energy Resolution of Photon");
        h71->SetXTitle("Energy Resolution of Photon");
        h71->SetYTitle("");
        h71->Draw("");
        TF1 *f71 = new TF1("f71","gaus",-.012,.012);
        f71->SetLineColor(kRed);
        h71->Fit("f71","","",-.01,.01);

        double num71,sig71,se71;
        int numi71 = h71->Integral(h71->FindFixBin(-.01),h71->FindFixBin(.01));
        num71 = numi71;
        cout<<"num71 = "<<num71<<endl;
        sig71= f71->GetParameter(2);
        cout<<"sig71 = "<<sig71<<endl;
        se71= sig71/num71;
        cout<<"se71 = "<<se71<<endl;


        double angp[6],angpe[6],sigp[6],sigep[6],step[6],steep[6],nump[6];


        TCanvas *c72 = new TCanvas("c72");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h72",cut1+cut2+cut7+cut72);
        h72->SetTitle("Energy Resolution of Photon");
        h72->SetXTitle("Energy Resolution of Photon");
        h72->SetYTitle("");
        h72->Draw("");
        TF1 *f72 = new TF1("f72","gaus",-.012,.012);
        f72->SetLineColor(kRed);
        h72->Fit("f72","","",-.01,.01);

        double num72;
        int numi72 = h72->Integral(h72->FindFixBin(-.01),h72->FindFixBin(.01));
        num72 = numi72;
        nump[0] = numi72;
        cout<<"num72 = "<<num72<<endl;
        angp[0]=0.05;
        sigp[0]=f72->GetParameter(2);
        sigep[0]=f72->GetParError(2);
        //se72= sig72/sqrt(num72);


        TCanvas *c73 = new TCanvas("c73");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h73",cut1+cut2+cut7+cut73);
        h73->SetTitle("Energy Resolution of Photon");
        h73->SetXTitle("Energy Resolution of Photon");
        h73->SetYTitle("");
        h73->Draw("");
        TF1 *f73 = new TF1("f73","gaus",-.012,.012);
        f73->SetLineColor(kOrange);
        h73->Fit("f73","","",-.01,.01);

        double num73;
        int numi73 = h73->Integral(h73->FindFixBin(-.01),h73->FindFixBin(.01));
        num73 = numi73;
        nump[1] = numi73;
        cout<<"num73 = "<<num73<<endl;
        angp[1]=0.15;
        sigp[1]=f73->GetParameter(2);
        sigep[1]=f73->GetParError(2);
        //se73= sig73/sqrt(num73);

        TCanvas *c74 = new TCanvas("c74");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h74",cut1+cut2+cut7+cut74);
        h74->SetTitle("Energy Resolution of Photon");
        h74->SetXTitle("Energy Resolution of Photon");
        h74->SetYTitle("");
        h74->Draw("");
        TF1 *f74 = new TF1("f74","gaus",-.012,.012);
        f74->SetLineColor(kGreen);
        h74->Fit("f74","","",-.01,.01);

        double num74;
        int numi74 = h74->Integral(h74->FindFixBin(-.01),h74->FindFixBin(.01));
        num74 = numi74;
        nump[2] = numi74;
        cout<<"num74 = "<<num74<<endl;
        angp[2]=0.3;
        sigp[2]=f74->GetParameter(2);
        sigep[2]=f74->GetParError(2);
      //  se74= sig74/sqrt(num74);

        TCanvas *c75 = new TCanvas("c75");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h75",cut1+cut2+cut7+cut75);
        h75->SetTitle("Energy Resolution of Photon");
        h75->SetXTitle("Energy Resolution of Photon");
        h75->SetYTitle("");
        h75->Draw("");
        TF1 *f75 = new TF1("f75","gaus",-.012,.012);
        f75->SetLineColor(kTeal);
        h75->Fit("f75","","",-.01,.01);

        double num75;
        int numi75 = h75->Integral(h75->FindFixBin(-.01),h75->FindFixBin(.01));
        num75 = numi75;
        nump[3] = numi75;
        cout<<"num75 = "<<num75<<endl;
        angp[3]=0.5;
        sigp[3]=f75->GetParameter(2);
        sigep[3]=f75->GetParError(2);
    //    se75= sig75/sqrt(num75);

        TCanvas *c76 = new TCanvas("c76");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h76",cut1+cut2+cut7+cut76);
        h76->SetTitle("Energy Resolution of Photon");
        h76->SetXTitle("Energy Resolution of Photon");
        h76->SetYTitle("");
        h76->Draw("");
        TF1 *f76 = new TF1("f76","gaus",-.012,.012);
        f76->SetLineColor(kBlue);
        h76->Fit("f76","","",-.01,.01);

        double num76;
        int numi76 = h76->Integral(h76->FindFixBin(-.01),h76->FindFixBin(.01));
        num76 = numi76;
        nump[4] = numi76;
        cout<<"num76 = "<<num76<<endl;
        angp[4]=0.7;
        sigp[4]=f76->GetParameter(2);
        sigep[4]=f76->GetParError(2);
  //      se76= sig76/sqrt(num76);

        TCanvas *c77 = new TCanvas("c77");
        hAnl->Draw("(-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC>>h77",cut1+cut2+cut7+cut77);
        h77->SetTitle("Energy Resolution of Photon");
        h77->SetXTitle("Energy Resolution of Photon");
        h77->SetYTitle("");
        h77->Draw("");
        TF1 *f77 = new TF1("f77","gaus",-.012,.012);
        f77->SetLineColor(kViolet);
        h77->Fit("f77","","",-.01,.01);

        double num77;
        int numi77 = h77->Integral(h77->FindFixBin(-.01),h77->FindFixBin(.01));
        num77 = numi77;
        nump[5] = numi77;
        cout<<"num77 = "<<num77<<endl;
        angp[5]=0.9;
        sigp[5]=f77->GetParameter(2);
        sigep[5]=f77->GetParError(2);
//        se77= sig77/sqrt(num77);

        for (int ii=0;ii<6;ii++){
                angpe[ii]=0.;
		step[ii]=sigp[ii]/sqrt(nump[ii]);
		steep[ii]=sigep[ii]/sqrt(nump[ii]);
        }

        TCanvas *c78 = new TCanvas("c78");
        TGraph *f78 = new TGraphErrors(6,angp,sigp,angpe,sigep);
	f78->SetMinimum(.0);
        f78->Draw("");
        f78->SetLineColor(kOrange+7);

        TCanvas *c79 = new TCanvas("c79");
        TGraph *f79 = new TGraphErrors(6,angp,step,angpe,steep);
	f79->SetMinimum(.0);
        f79->Draw("");
        f79->SetLineColor(kOrange+7);

	
        TCanvas *c81 = new TCanvas("c81");
	TGraph *f81 = new TGraphErrors(6,ang5,sig5,ange5,sige5);
        f81->SetMinimum(.0);
        f81->SetMarkerColor(kOrange-3);
        //f81->SetMarkerColor(kMagenta+1);
        f81->SetMarkerStyle(22);
        f81->SetMarkerSize(.8);
	TGraph *f82 = new TGraphErrors(6,ang,sig,ange,sige);
        f82->SetMinimum(.0);
        //f82->SetMarkerColor(kAzure+10);
        f82->SetMarkerColor(kGreen-3);
        f82->SetMarkerStyle(23);
        f82->SetMarkerSize(.8);
	f82->Draw("AP");
        //f82->SetLineColor(kAzure+10);
        f82->SetLineColor(kGreen-3);
        f81->Draw("P");
        f81->SetLineColor(kOrange-3);
        //f81->SetLineColor(kMagenta+1);

        TCanvas *c86 = new TCanvas("c86");
	TGraph *f86 = new TGraphErrors(6,ang5,ste5,ange5,stee5);
        f86->SetMinimum(.0);
        f86->SetMarkerColor(kOrange-3);
        //f86->SetMarkerColor(kMagenta+1);
        f86->SetMarkerStyle(22);
        f86->SetMarkerSize(.8);
	TGraph *f87 = new TGraphErrors(6,ang,ste,ange,stee);
        f87->SetMinimum(.0);
        //f87->SetMarkerColor(kAzure+10);
        f87->SetMarkerColor(kGreen-3);
        f87->SetMarkerStyle(23);
        f87->SetMarkerSize(.8);
        f86->Draw("AP");
        f86->SetLineColor(kOrange-3);
        //f86->SetLineColor(kMagenta+1);
        f87->Draw("P");
        //f87->SetLineColor(kAzure+10);
        f87->SetLineColor(kGreen-3);

        TCanvas *c91 = new TCanvas("c91");
        TGraph *f91 = new TGraphErrors(6,angp5,sigp5,angpe5,sigep5);
	f91->SetMinimum(.0);
        f91->SetMarkerColor(kOrange-3);
        //f91->SetMarkerColor(kMagenta+1);
        f91->SetMarkerStyle(22);
        f91->SetMarkerSize(.8);
        TGraph *f92 = new TGraphErrors(6,angp,sigp,angpe,sigep);
	f92->SetMinimum(.0);
        //f92->SetMarkerColor(kAzure+10);
        f92->SetMarkerColor(kGreen-3);
        f92->SetMarkerStyle(23);
        f92->SetMarkerSize(.8);
        f92->Draw("AP");
        //f92->SetLineColor(kAzure+10);
        f92->SetLineColor(kGreen-3);
        f91->Draw("P");
        f91->SetLineColor(kOrange-3);
        //f91->SetLineColor(kMagenta+1);

        TCanvas *c96 = new TCanvas("c96");
        TGraph *f96 = new TGraphErrors(6,angp5,step5,angpe5,steep5);
        f96->SetMinimum(.0);
        f96->SetMarkerColor(kOrange-3);
        //f96->SetMarkerColor(kMagenta+1);
        f96->SetMarkerStyle(22);  
        f96->SetMarkerSize(.8); 
        TGraph *f97 = new TGraphErrors(6,angp,step,angpe,steep);
	f97->SetMinimum(.0);
	//f97->SetMarkerColor(kAzure+10);
	f97->SetMarkerColor(kGreen-3);
	f97->SetMarkerStyle(23);
	f97->SetMarkerSize(.8); 
        f97->Draw("AP");
        //f97->SetLineColor(kAzure+10);
        f97->SetLineColor(kGreen-3);
        f96->Draw("P");
        f96->SetLineColor(kOrange-3);
        //f96->SetLineColor(kMagenta+1);
*/

        //TH2D *h101 = new TH2D("h101","",200,-1.,1.,200,-100.,100.);
        TH2D *h101 = new TH2D("h101","",200,-2.,2.,200,-500.,500.);
        TH1D *h102 = new TH1D("h102","",200,-1.,1.);
	TCut cut8 = "abs(sin(photonthetaMC))<.3 &&abs(sin(photonthetaMC)) >.01";
	TCut cut9 = "abs(sin(photonphiMC))<.1";
	TCut cut10 = "photonEMC+lep1EMC+lep2EMC>0.";
	//TCut cut11="-(lep1PzMC+lep2PzMC+photonPzMC+ISRphotonPzMC)*ISRphotonPzMC > 0"
	TCut cut11="-(lep1PMC*cos(lep1thetaMC)+lep2PMC*cos(lep2thetaMC)+photonPMC*cos(photonthetaMC)+ISRphotonPzMC)*ISRphotonPzMC > 0.";
	//TCut cut11="1. > 0.";
	//TCut cut12="ISRphotonEMC > 20.";
	//TCut cut12="ISRphotonEMC < 5.";
	//TCut cut12="1. < 5.";
	//TCut cut12="ISRphotonEMC >5. && (ISRphotonPyMC/ISRphotonPMC) >.1 ";
	TCut cut13=" (ISRphotonPyMC/ISRphotonPMC) <.001 ";
	TCut cut14=" ISRphotonPxMC-500*sin(0.007) <.001 ";
	TCut cut15=" ISRphotonPxMC-500*sin(0.007) <.001 ";
	TCut cut12=cut13+cut14;


	 TCanvas *c101 = new TCanvas("c101");
	//hAnl->Draw("500.-lep1EAnl-lep2EAnl-photonEAnl-abs(lep1PzAnl+lep2PzAnl+photonPzAnl):((-photonEMC+photonERec5(lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,photonEMC))/photonEMC)>>h101",cut1+cut2+(cut8 || cut9));
	//hAnl->Draw("mz:((-photonEMC+photonERec5(lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,photonEMC))/photonEMC)>>h101",cut1+cut2+(cut8 || cut9)+cut10);
	//hAnl->Draw("500.-lep1EMC-lep2EMC-photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl):((-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC)>>h101",cut1+cut2+(cut8 || cut9)+cut10);
	//hAnl->Draw("500.-lep1EMC-lep2EMC-photonERec5(lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,photonEMC):((-photonEMC+photonERec5(lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,photonEMC))/photonEMC)>>h101",cut1+cut2+(cut8 || cut9)+cut10);
	hAnl->Draw("500.-lep1EAnl-lep2EAnl-photonERec5(lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,photonEMC):((-photonEMC+photonERec5(lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,photonEMC))/photonEMC)>>h101",cut1+cut2+(cut8 || cut9)+cut10+cut11+cut12);
///	hAnl->Draw("500.-lep1EMC-lep2EMC-photonERec5(lep1EMC,lep2EMC,lep1thetaMC, lep1phiMC,lep2thetaMC,lep2phiMC,photonthetaMC,photonphiMC,photonEMC):((-photonEMC+photonERec5(lep1EMC,lep2EMC,lep1thetaMC, lep1phiMC,lep2thetaMC,lep2phiMC,photonthetaMC,photonphiMC,photonEMC))/photonEMC)>>h101",cut1+cut2+(cut8 || cut9)+cut10+cut11);
//	hAnl->Draw("500.-lep1EMC-lep2EMC-photonEMC-abs(lep1PMC*cos(lep1thetaMC)+lep2PMC*cos(lep2thetaMC)+photonPMC*cos(photonthetaMC)):((-photonEMC+photonERec5(lep1EMC,lep2EMC,lep1thetaMC, lep1phiMC,lep2thetaMC,lep2phiMC,photonthetaMC,photonphiMC,photonEMC))/photonEMC)>>h101",cut1+cut2+(cut8 || cut9)+cut10+cut11);
	//hAnl->Draw("lep1EAnl+lep2EAnl+photonEAnl:((-photonEMC+photonERec5(lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,photonEMC))/photonEMC)>>h101",cut1+cut2+(cut8 || cut9)+cut10);
	//hAnl->Draw("lep1EAnl+lep2EAnl+photonERec5(lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,photonEMC):((-photonEMC+photonERec5(lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,photonEMC))/photonEMC)>>h101",cut1+cut2+(cut8 || cut9));
	//hAnl->Draw("500.-lep1EMC-lep2EMC-photonEMC-abs(lep1PMC*cos(lep1thetaMC)+lep2PMC*cos(lep2thetaMC)+photonPMC*cos(photonthetaMC)):((-photonEMC+photonERec5(lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,photonEMC))/photonEMC)>>h101",cut1+cut2+(cut8 || cut9));
        h101->SetTitle("");
        h101->SetXTitle("");
        h101->SetYTitle("");
        h101->Draw("colz");

         TCanvas *c102 = new TCanvas("c102");
        hAnl->Draw("((-photonEMC+photonERec5(lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl,photonEMC))/photonEMC)>>h102",cut1+cut2+(cut8 || cut9)+cut10+cut11+cut12);
        //hAnl->Draw("((-photonEMC+photonERec6(500.,lep1EAnl,lep2EAnl,lep1thetaAnl, lep1phiAnl,lep2thetaAnl,lep2phiAnl,photonthetaAnl,photonphiAnl))/photonEMC)>>h102",cut1+cut2+(cut8 || cut9)+cut10);
//        hAnl->Draw("((-photonEMC+photonERec6(500.,lep1EMC,lep2EMC,lep1thetaMC, lep1phiMC,lep2thetaMC,lep2phiMC,photonthetaMC,photonphiMC))/photonEMC)>>h102",cut1+cut2+(cut8 || cut9)+cut10);
        h102->SetTitle("");
        h102->SetXTitle("");
        h102->SetYTitle("");
        h102->Draw("");



}


