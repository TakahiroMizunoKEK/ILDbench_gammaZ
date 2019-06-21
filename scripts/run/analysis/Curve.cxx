
#include "/home/ilc/mizunot/bin/root_macros/style.C"


TGraph* Curve() {
	
	const int kN=100;
	double dcos =2./kN;
	double x[kN+1],y[kN+1],costhstar[kN+1];

	double mz= 91.18;
	double roots= 500.;
	double pz= (roots/2)*(1+mz/roots)*(1-mz/roots) ;
	double Ez= roots-pz;
	double betaz= pz/Ez;
	double gammaz= Ez/mz;
	double pstar= mz/2.;

	for (int i=0;i<=kN;i++){
		double cs = -1+i*dcos;
		double pL = gammaz*(cs+betaz);
		double pT = sqrt((1+cs)*(1-cs));
		costhstar[i]=cs;
		//x[i]=1/sqrt(1+(1+cs)*(1-cs)/((pow(gammaz*(cs+betaz),2))));
		x[i]=cos(atan2(pT,pL));
		y[i]=pstar*sqrt(pow(gammaz*(cs+betaz),2)+(1+cs)*(1-cs));
	cerr<<" "<<cs<<" "<<x[i]<<" "<<y[i]<<endl;	
	}		


	TGraph *g = new TGraph(kN,x,y);
	g->SetLineColor(kRed);
	return g;
}

