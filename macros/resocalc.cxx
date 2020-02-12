
/*#include "TMath.h"
#include "streamlog/streamlog.h"
#include "marlin/Global.h"
#include <GeometryUtil.h>
#include "algebraImplementation.h"*/

//mureso(int par){
double  resocalc(double Ecm, double Emum, double Emup,  double lep1thetaAnl,   double lep1phiAnl,
                              double lep2thetaAnl,   double lep2phiAnl,
                              double photonthetaAnl, double photonphiAnl){

        double stgamma  = sin(photonthetaAnl);
        double stmum    = sin(lep1thetaAnl);
        double stmup    = sin(lep2thetaAnl);
        double ctgamma  = cos(photonthetaAnl);
        double ctmum    = cos(lep1thetaAnl);
        double ctmup    = cos(lep2thetaAnl);

        double spgamma  = sin(photonphiAnl);
        double spmum    = sin(lep1phiAnl);
        double spmup    = sin(lep2phiAnl);
        double cpgamma  = cos(photonphiAnl);
        double cpmum    = cos(lep1phiAnl);
        double cpmup    = cos(lep2phiAnl);


	double mumco;
	double mupco;
	double resocon = 2. * pow (10.,-5.);

	double sig,sig2;
	mumco = pow ((1./stgamma/spgamma),2.)*pow ((stmum * spmum),2.);
	mupco = pow ((1./stgamma/spgamma),2.)*pow ((stmup * spmup),2.);
	sig2 = mumco * resocon + mupco * resocon;

	//return sig2;	

	sig = resocon/(Emum * stmum *spmum + Emup * stmup *spmup);
	sig = sig * sqrt(pow((Emum * stmum),4.) *pow(spmum,2.) + pow((Emup * stmup),4.) *pow(spmup,2.));

	return sig;




}

