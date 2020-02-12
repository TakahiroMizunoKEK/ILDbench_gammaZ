
/*#include "TMath.h"
#include "streamlog/streamlog.h"
#include "marlin/Global.h"
#include <GeometryUtil.h>
#include "algebraImplementation.h"*/

//mureso(int par){
double  resocalc2(double lep1thetaAnl,   double lep1phiAnl,  double lep2thetaAnl,   double lep2phiAnl,
                  double photonthetaAnl, double photonphiAnl, double Egamma,  double lep1dPAnl, double lep2dPAnl){

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


	double mumcoe;
	double mupcoe;
	double resocon = 2. * pow (10.,-5.);

	double sig,sig2;
	mumcoe = pow ((stmum * spmum/stgamma/spgamma/Egamma),2.);
	mupcoe = pow ((stmup * spmup/stgamma/spgamma/Egamma),2.);
	sig2 = mumcoe * pow(lep1dPAnl,2.) + mupcoe * pow(lep2dPAnl,2.);
	sig2 = sqrt(sig2);

	return sig2;



}

