
#include "/home/ilc/mizunot/bin/root_macros/style.C"


void Numbers() {

        stringstream filest;
        filest <<"../root_merge.mILD_l5_o1_v02/"<< "2f_z_l.eL.pR.mILD_l5_o1_v02.root" << ends;

        TFile *f = new TFile(filest.str().data());
//	TCanvas *c1 = new TCanvas("c1");

	TNtuple *hGen = f->Get("hGen");
	TNtuple *hAnl = f->Get("hAnl");
	

	double generated,preselected,mz912,cos0002,cos0204,cos0406,cos0608,cos0809,cos0910;
	
	generated= hGen->GetEntries();
	preselected= hAnl->GetEntries();
	mz912= hAnl->GetEntries("pdg0==13 && abs(mz-10)<91.2");
	cos0002= hAnl->GetEntries("pdg0==13 && abs(mz-10)<91.2 && abs(coslep1)>0.0 && abs(coslep1)<0.2");
	cos0204= hAnl->GetEntries("pdg0==13 && abs(mz-10)<91.2 && abs(coslep1)>0.2 && abs(coslep1)<0.4");
	cos0406= hAnl->GetEntries("pdg0==13 && abs(mz-10)<91.2 && abs(coslep1)>0.4 && abs(coslep1)<0.6");
	cos0608= hAnl->GetEntries("pdg0==13 && abs(mz-10)<91.2 && abs(coslep1)>0.6 && abs(coslep1)<0.8");
	cos0809= hAnl->GetEntries("pdg0==13 && abs(mz-10)<91.2 && abs(coslep1)>0.8 && abs(coslep1)<0.9");
	cos0910= hAnl->GetEntries("pdg0==13 && abs(mz-10)<91.2 && abs(coslep1)>0.9 && abs(coslep1)<1.0");


	cerr<<"generated= "<<generated<<endl;
	cerr<<"preselected= "<<preselected<<endl;
	cerr<<"mz912= "<<mz912<<endl;
	cerr<<"cos0002= "<<cos0002<<endl;
	cerr<<"cos0204= "<<cos0204<<endl;
	cerr<<"cos0406= "<<cos0406<<endl;
	cerr<<"cos0608= "<<cos0608<<endl;
	cerr<<"cos0809= "<<cos0809<<endl;
	cerr<<"cos0910= "<<cos0910<<endl;


        stringstream filest2;
        filest2 <<"../root_merge.mILD_s5_o1_v02/"<< "2f_z_l.eL.pR.mILD_s5_o1_v02.root" << ends;

        TFile *f2 = new TFile(filest2.str().data());
//	TCanvas *c1 = new TCanvas("c1");

	TNtuple *hGenS = f2->Get("hGen");
	TNtuple *hAnlS = f2->Get("hAnl");
	

	double Sgenerated,Spreselected,Smz912,Scos0002,Scos0204,Scos0406,Scos0608,Scos0809,Scos0910;
	
	Sgenerated= hGenS->GetEntries();
	Spreselected= hAnlS->GetEntries();
	Smz912= hAnlS->GetEntries("pdg0==13 && abs(mz-10)<91.2");
	Scos0002= hAnlS->GetEntries("pdg0==13 && abs(mz-10)<91.2 && abs(coslep1)>0.0 && abs(coslep1)<0.2");
	Scos0204= hAnlS->GetEntries("pdg0==13 && abs(mz-10)<91.2 && abs(coslep1)>0.2 && abs(coslep1)<0.4");
	Scos0406= hAnlS->GetEntries("pdg0==13 && abs(mz-10)<91.2 && abs(coslep1)>0.4 && abs(coslep1)<0.6");
	Scos0608= hAnlS->GetEntries("pdg0==13 && abs(mz-10)<91.2 && abs(coslep1)>0.6 && abs(coslep1)<0.8");
	Scos0809= hAnlS->GetEntries("pdg0==13 && abs(mz-10)<91.2 && abs(coslep1)>0.8 && abs(coslep1)<0.9");
	Scos0910= hAnlS->GetEntries("pdg0==13 && abs(mz-10)<91.2 && abs(coslep1)>0.9 && abs(coslep1)<1.0");


	cerr<<"Sgenerated= "<<Sgenerated<<endl;
	cerr<<"Spreselected= "<<Spreselected<<endl;
	cerr<<"Smz912= "<<Smz912<<endl;
	cerr<<"Scos0002= "<<Scos0002<<endl;
	cerr<<"Scos0204= "<<Scos0204<<endl;
	cerr<<"Scos0406= "<<Scos0406<<endl;
	cerr<<"Scos0608= "<<Scos0608<<endl;
	cerr<<"Scos0809= "<<Scos0809<<endl;
	cerr<<"Scos0910= "<<Scos0910<<endl;


	generated= generated+Sgenerated;
	preselected= preselected+Spreselected;
	mz912= mz912+Smz912;
	cos0002= cos0002+Scos0002;
	cos0204= cos0204+Scos0204;
	cos0406= cos0406+Scos0406;
	cos0608= cos0608+Scos0608;
	cos0809= cos0809+Scos0809;
	cos0910= cos0910+Scos0910;;

        cerr<<"generated= "<<generated<<endl;
        cerr<<"preselected= "<<preselected<<endl;
        cerr<<"mz912= "<<mz912<<endl;
        cerr<<"cos0002= "<<cos0002<<endl;
        cerr<<"cos0204= "<<cos0204<<endl;
        cerr<<"cos0406= "<<cos0406<<endl;
        cerr<<"cos0608= "<<cos0608<<endl;
        cerr<<"cos0809= "<<cos0809<<endl;
        cerr<<"cos0910= "<<cos0910<<endl;


	double Ntot,Nmz912,Ncos0002,Ncos0204,Ncos0406,Ncos0608,Ncos0809,Ncos0910;
	Ntot=12417.415920*900.;
        Nmz912= mz912/generated*Ntot;
        Ncos0002= cos0002/generated*Ntot;
        Ncos0204= cos0204/generated*Ntot;
        Ncos0406= cos0406/generated*Ntot;
        Ncos0608= cos0608/generated*Ntot;
        Ncos0809= cos0809/generated*Ntot;
        Ncos0910= cos0910/generated*Ntot;

        cerr<<"Nmz912= "<<Nmz912<<endl;
        cerr<<"Ncos0002= "<<Ncos0002<<endl;
        cerr<<"Ncos0204= "<<Ncos0204<<endl;
        cerr<<"Ncos0406= "<<Ncos0406<<endl;
        cerr<<"Ncos0608= "<<Ncos0608<<endl;
        cerr<<"Ncos0809= "<<Ncos0809<<endl;
        cerr<<"Ncos0910= "<<Ncos0910<<endl;

	double lsigma,ssigma,lcc,scc;
	lsigma=2.2*pow(10,-5);
	ssigma=2.4*pow(10,-5);
	lcc=lsigma*91.2/sqrt(Nmz912);
	scc=ssigma*91.2/sqrt(Nmz912);

	cerr<<"lcc= "<<lcc<<endl;
	cerr<<"scc= "<<scc<<endl;


	return;

}
