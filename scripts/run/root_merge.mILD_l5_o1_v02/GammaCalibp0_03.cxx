
#include "/home/ilc/mizunot/bin/root_macros/style.C"
//#include "PhotonCase4SigmaTheta.cxx"


void GammaCalibp0_03() {

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

/*        TH1D *h61 = new TH1D("h61","",400.,-.2,.2);
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
*/

	TCut cut1 = "pdg0==13 && abs(mzgen-91.2)<10";
	TCut cut3 = "coneen > -0.5";
	TCut cut4 = "abs(coslep1)<0.75 && abs(coslep2)<0.75";
        //TCut cut2 = cut3+cut4;
        TCut cut2 = cut3;

	TCut cut51 = "abs(cos(photonthetaMC))<0.2";
	TCut cut52 = "abs(cos(photonthetaMC))>=0.2 && abs(cos(photonthetaMC))<0.4";
	TCut cut53 = "abs(cos(photonthetaMC))>=0.4 && abs(cos(photonthetaMC))<0.6";
	TCut cut54 = "abs(cos(photonthetaMC))>=0.6 && abs(cos(photonthetaMC))<0.8";
	TCut cut55 = "abs(cos(photonthetaMC))>=0.8 && abs(cos(photonthetaMC))<0.9";
	TCut cut56 = "abs(cos(photonthetaMC))>=0.9";

	//TCut cut7 = "abs(cos(photonthetaMC))<0.8";
	TCut cut7 = "abs(cos(photonthetaMC))<1.1";
        TCut cut72 = "abs(sin(photonphiMC))<0.1";
        TCut cut73 = "abs(sin(photonphiMC))>=0.1 && abs(sin(photonphiMC))<0.2";
        TCut cut74 = "abs(sin(photonphiMC))>=0.2 && abs(sin(photonphiMC))<0.4";
        TCut cut75 = "abs(sin(photonphiMC))>=0.4 && abs(sin(photonphiMC))<0.6";
        TCut cut76 = "abs(sin(photonphiMC))>=0.6 && abs(sin(photonphiMC))<0.8";
        TCut cut77 = "abs(sin(photonphiMC))>=0.8";

        TCut cut6 = "abs(sin(photonphiMC))<=1.";



        TCanvas *c31 = new TCanvas("c31");
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


	double ang5[6],ange5[6],sig5[6],sige5[6],ste5[6],stee5[6],numt5[6];


        TCanvas *c32 = new TCanvas("c32");
        hAnl->Draw("(-photonEMC+photonEAnl)/photonEMC>>h32",cut1+cut2+cut51+cut6);
        h32->SetTitle("Energy Resolution of Photon");
        h32->SetXTitle("Energy Resolution of Photon");
        h32->SetYTitle("");
        h32->Draw("");
        TF1 *f32 = new TF1("f32","gaus",-.012,.042);
        f32->SetLineColor(kRed);
        h32->Fit("f32","","",-.01,.04);
	double mean32 = h32->GetFunction("f32")->GetParameter(1);
	double sigma32 = h32->GetFunction("f32")->GetParameter(2);
	h32->Fit("f32","","",mean32-2*sigma32,mean32+2*sigma32);

        double num32,sig32,se32;
        int numi32 = h32->Integral(h32->FindFixBin(-.01),h32->FindFixBin(.04));
        num32 = numi32;
        numt5[0] = numi32;
        cout<<"num32 = "<<num32<<endl;
	ang5[0]=0.1;
	sig5[0]=f32->GetParameter(2);
	sige5[0]=f32->GetParError(2);
        se32= sig32/sqrt(num32);


        TCanvas *c33 = new TCanvas("c33");
        hAnl->Draw("(-photonEMC+photonEAnl)/photonEMC>>h33",cut1+cut2+cut52+cut6);
        h33->SetTitle("Energy Resolution of Photon");
        h33->SetXTitle("Energy Resolution of Photon");
        h33->SetYTitle("");
        h33->Draw("");
        TF1 *f33 = new TF1("f33","gaus",-.012,.042);
        f33->SetLineColor(kOrange);
        h33->Fit("f33","","",-.01,.04);
	double mean33 = h33->GetFunction("f33")->GetParameter(1);
	double sigma33 = h33->GetFunction("f33")->GetParameter(2);
	h33->Fit("f33","","",mean33-2*sigma33,mean33+2*sigma33);

        double num33,sig33,se33;
        int numi33 = h33->Integral(h33->FindFixBin(-.01),h33->FindFixBin(.04));
        num33 = numi33;
        numt5[1] = numi33;
        cout<<"num33 = "<<num33<<endl;
	ang5[1]=0.3;
	sig5[1]=f33->GetParameter(2);
	sige5[1]=f33->GetParError(2);
        se33= sig33/sqrt(num33);


        TCanvas *c34 = new TCanvas("c34");
        hAnl->Draw("(-photonEMC+photonEAnl)/photonEMC>>h34",cut1+cut2+cut53+cut6);
        h34->SetTitle("Energy Resolution of Photon");
        h34->SetXTitle("Energy Resolution of Photon");
        h34->SetYTitle("");
        h34->Draw("");
        TF1 *f34 = new TF1("f34","gaus",-.012,.042);
        f34->SetLineColor(kGreen);
        h34->Fit("f34","","",-.01,.04);
	double mean34 = h34->GetFunction("f34")->GetParameter(1);
	double sigma34 = h34->GetFunction("f34")->GetParameter(2);
	h34->Fit("f34","","",mean34-2*sigma34,mean34+2*sigma34);

        double num34,sig34,se34;
        int numi34 = h34->Integral(h34->FindFixBin(-.01),h34->FindFixBin(.04));
        num34 = numi34;
        numt5[2] = numi34;
        cout<<"num34 = "<<num34<<endl;
	ang5[2]=0.5;
	sig5[2]=f34->GetParameter(2);
	sige5[2]=f34->GetParError(2);
        se34= sig34/sqrt(num34);


        TCanvas *c35 = new TCanvas("c35");
        hAnl->Draw("(-photonEMC+photonEAnl)/photonEMC>>h35",cut1+cut2+cut54+cut6);
        h35->SetTitle("Energy Resolution of Photon");
        h35->SetXTitle("Energy Resolution of Photon");
        h35->SetYTitle("");
        h35->Draw("");
        TF1 *f35 = new TF1("f35","gaus",-.012,.042);
        f35->SetLineColor(kTeal);
        h35->Fit("f35","","",-.01,.04);
	double mean35 = h35->GetFunction("f35")->GetParameter(1);
	double sigma35 = h35->GetFunction("f35")->GetParameter(2);
	h35->Fit("f35","","",mean35-2*sigma35,mean35+2*sigma35);

        double num35,sig35,se35;
        int numi35 = h35->Integral(h35->FindFixBin(-.01),h35->FindFixBin(.04));
        num35 = numi35;
        numt5[3] = numi35;
        cout<<"num35 = "<<num35<<endl;
	ang5[3]=0.7;
	sig5[3]=f35->GetParameter(2);
	sige5[3]=f35->GetParError(2);
        se35= sig35/sqrt(num35);


        TCanvas *c36 = new TCanvas("c36");
        hAnl->Draw("(-photonEMC+photonEAnl)/photonEMC>>h36",cut1+cut2+cut55+cut6);
        h36->SetTitle("Energy Resolution of Photon");
        h36->SetXTitle("Energy Resolution of Photon");
        h36->SetYTitle("");
        h36->Draw("");
        TF1 *f36 = new TF1("f36","gaus",-.012,.042);
        f36->SetLineColor(kBlue);
        h36->Fit("f36","","",-.01,.04);
	double mean36 = h36->GetFunction("f36")->GetParameter(1);
	double sigma36 = h36->GetFunction("f36")->GetParameter(2);
	h36->Fit("f36","","",mean36-2*sigma36,mean36+2*sigma36);

        double num36,sig36,se36;
        int numi36 = h36->Integral(h36->FindFixBin(-.01),h36->FindFixBin(.04));
        num36 = numi36;
        numt5[4] = numi36;
        cout<<"num36 = "<<num36<<endl;
	ang5[4]=0.85;
	sig5[4]=f36->GetParameter(2);
	sige5[4]=f36->GetParError(2);
        se36= sig36/sqrt(num36);


        TCanvas *c37 = new TCanvas("c37");
        hAnl->Draw("(-photonEMC+photonEAnl)/photonEMC>>h37",cut1+cut2+cut56+cut6);
        h37->SetTitle("Energy Resolution of Photon");
        h37->SetXTitle("Energy Resolution of Photon");
        h37->SetYTitle("");
        h37->Draw("");
        TF1 *f37 = new TF1("f37","gaus",-.012,.042);
        f37->SetLineColor(kViolet);
        h37->Fit("f37","","",-.01,.04);
	double mean37 = h37->GetFunction("f37")->GetParameter(1);
	double sigma37 = h37->GetFunction("f37")->GetParameter(2);
	h37->Fit("f37","","",mean37-2*sigma37,mean37+2*sigma37);

        double num37,sig37,se37;
        int numi37 = h37->Integral(h37->FindFixBin(-.01),h37->FindFixBin(.04));
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
	TGraphErrors *f38 = new TGraphErrors(6,ang5,sig5,ange5,sige5);
        //f68->SetTitle("Energy Resolution of Photon");
        //f68->SetXTitle("Energy Resolution of Photon");
        //f68->SetYTitle("");
        f38->SetMinimum(.0);
	f38->Draw("AP");
        f38->SetLineColor(kGreen-3);
 	//TGraphErrors *g38 = PhotonCase4SigmaTheta(0);
        //g38->Draw("P same");
        //g38->SetLineColor(kYellow-3);


        TCanvas *c39 = new TCanvas("c39");
	TGraph *f39 = new TGraphErrors(6,ang5,ste5,ange5,stee5);
        //f68->SetTitle("Energy Resolution of Photon");
        //f68->SetXTitle("Energy Resolution of Photon");
        //f68->SetYTitle("");
        f39->SetMinimum(.0);
	f39->Draw("AP");
        f39->SetLineColor(kGreen-3);


        TCanvas *c41 = new TCanvas("c41");
        hAnl->Draw("(-photonEMC+photonEAnl)/photonEMC>>h41",cut1+cut2+cut7);
        h41->SetTitle("Energy Resolution of Photon");
        h41->SetXTitle("Energy Resolution of Photon");
        h41->SetYTitle("");
        h41->Draw("");
        TF1 *f41 = new TF1("f41","gaus",-.012,.042);
        f41->SetLineColor(kRed);
        h41->Fit("f41","","",-.01,.04);

        double num41,sig41,se41;
        int numi41 = h41->Integral(h41->FindFixBin(-.01),h41->FindFixBin(.04));
        num41 = numi41;
        cout<<"num41 = "<<num41<<endl;
        sig41= f41->GetParameter(2);
        cout<<"sig41 = "<<sig41<<endl;
        se41= sig41/num41;
        cout<<"se41 = "<<se41<<endl;


        double angp5[6],angpe5[6],sigp5[6],sigep5[6],step5[6],steep5[6],nump5[6];


        TCanvas *c42 = new TCanvas("c42");
        hAnl->Draw("(-photonEMC+photonEAnl)/photonEMC>>h42",cut1+cut2+cut7+cut72);
        h42->SetTitle("Energy Resolution of Photon");
        h42->SetXTitle("Energy Resolution of Photon");
        h42->SetYTitle("");
        h42->Draw("");
        TF1 *f42 = new TF1("f42","gaus",-.012,.042);
        f42->SetLineColor(kRed);
        h42->Fit("f42","","",-.01,.04);

        double num42;
        int numi42 = h42->Integral(h42->FindFixBin(-.01),h42->FindFixBin(.04));
        num42 = numi42;
        nump5[0] = numi42;
        cout<<"num42 = "<<num42<<endl;
        angp5[0]=0.05;
        sigp5[0]=f42->GetParameter(2);
        sigep5[0]=f42->GetParError(2);
        //se72= sig72/sqrt(num72);

        TCanvas *c43 = new TCanvas("c43");
        hAnl->Draw("(-photonEMC+photonEAnl)/photonEMC>>h43",cut1+cut2+cut7+cut73);
        h43->SetTitle("Energy Resolution of Photon");
        h43->SetXTitle("Energy Resolution of Photon");
        h43->SetYTitle("");
        h43->Draw("");
        TF1 *f43 = new TF1("f43","gaus",-.012,.042);
        f43->SetLineColor(kOrange);
        h43->Fit("f43","","",-.01,.04);

        double num43;
        int numi43 = h43->Integral(h43->FindFixBin(-.01),h43->FindFixBin(.04));
        num43 = numi43;
        nump5[1] = numi43;
        cout<<"num43 = "<<num43<<endl;
        angp5[1]=0.15;
        sigp5[1]=f43->GetParameter(2);
        sigep5[1]=f43->GetParError(2);
        //se73= sig73/sqrt(num73);

        TCanvas *c44 = new TCanvas("c44");
        hAnl->Draw("(-photonEMC+photonEAnl)/photonEMC>>h44",cut1+cut2+cut7+cut74);
        h44->SetTitle("Energy Resolution of Photon");
        h44->SetXTitle("Energy Resolution of Photon");
        h44->SetYTitle("");
        h44->Draw("");
        TF1 *f44 = new TF1("f44","gaus",-.012,.042);
        f44->SetLineColor(kGreen);
        h44->Fit("f44","","",-.01,.04);

        double num44;
        int numi44 = h44->Integral(h44->FindFixBin(-.01),h44->FindFixBin(.04));
        num44 = numi44;
        nump5[2] = numi44;
        cout<<"num44 = "<<num44<<endl;
        angp5[2]=0.3;
        sigp5[2]=f44->GetParameter(2);
        sigep5[2]=f44->GetParError(2);
      //  se74= sig74/sqrt(num74);

        TCanvas *c45 = new TCanvas("c45");
        hAnl->Draw("(-photonEMC+photonEAnl)/photonEMC>>h45",cut1+cut2+cut7+cut75);
        h45->SetTitle("Energy Resolution of Photon");
        h45->SetXTitle("Energy Resolution of Photon");
        h45->SetYTitle("");
        h45->Draw("");
        TF1 *f45 = new TF1("f45","gaus",-.012,.042);
        f45->SetLineColor(kTeal);
        h45->Fit("f45","","",-.01,.04);

        double num45;
        int numi45 = h45->Integral(h45->FindFixBin(-.01),h45->FindFixBin(.04));
        num45 = numi45;
        nump5[3] = numi45;
        cout<<"num45 = "<<num45<<endl;
        angp5[3]=0.5;
        sigp5[3]=f45->GetParameter(2);
        sigep5[3]=f45->GetParError(2);
    //    se75= sig75/sqrt(num75);

        TCanvas *c46 = new TCanvas("c46");
        hAnl->Draw("(-photonEMC+photonEAnl)/photonEMC>>h46",cut1+cut2+cut7+cut76);
        h46->SetTitle("Energy Resolution of Photon");
        h46->SetXTitle("Energy Resolution of Photon");
        h46->SetYTitle("");
        h46->Draw("");
        TF1 *f46 = new TF1("f46","gaus",-.012,.042);
        f46->SetLineColor(kBlue);
        h46->Fit("f46","","",-.01,.04);

        double num46;
        int numi46 = h46->Integral(h46->FindFixBin(-.01),h46->FindFixBin(.04));
        num46 = numi46;
        nump5[4] = numi46;
        cout<<"num46 = "<<num46<<endl;
        angp5[4]=0.7;
        sigp5[4]=f46->GetParameter(2);
        sigep5[4]=f46->GetParError(2);
  //      se76= sig76/sqrt(num76);

        TCanvas *c47 = new TCanvas("c47");
        hAnl->Draw("(-photonEMC+photonEAnl)/photonEMC>>h47",cut1+cut2+cut7+cut77);
        h47->SetTitle("Energy Resolution of Photon");
        h47->SetXTitle("Energy Resolution of Photon");
        h47->SetYTitle("");
        h47->Draw("");
        TF1 *f47 = new TF1("f47","gaus",-.012,.042);
        f47->SetLineColor(kViolet);
        h47->Fit("f47","","",-.01,.04);

        double num47;
        int numi47 = h47->Integral(h47->FindFixBin(-.01),h47->FindFixBin(.04));
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
        f48->Draw("AP");
        f48->SetLineColor(kOrange+7);

        TCanvas *c49 = new TCanvas("c49");
        TGraph *f49 = new TGraphErrors(6,angp5,step5,angpe5,steep5);
	f49->SetMinimum(.0);
        f49->Draw("AP");
        f49->SetLineColor(kOrange+7);





}


