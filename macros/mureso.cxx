
#include "TMath.h"
#include "streamlog/streamlog.h"
#include "marlin/Global.h"
#include <GeometryUtil.h>
#include "algebraImplementation.h"

//mureso(int par){
double  mureso(ReconstructedParticle const *par, TMatrixD &covMatrixMomenta){

//Based on
//cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/MarlinReco/v01-25/Analysis/FourMomentumCovMat/src
//or
//$ILCSOFT/MarlinReco/v01-25/Analysis/FourMomentumCovMat/src
 

  double bField       = MarlinUtil::getBzAtOrigin();
  const double CT     = 2.99792458E-4;

  double track_omega  = mytrack->getOmega();
  double track_tanL   = mytrack->getTanLambda();
  double track_phi    = mytrack->getPhi();
  double track_pt     = (CT*bField) / fabs(track_omega);
  double track_pz     = (track_pt*track_tanL);
  double track_p      = sqrt( (track_pt * track_pt)+(track_pz * track_pz) );
//  double track_px     = track_pt * TMath::Cos(track_phi);
//  double track_py     = track_pt * TMath::Sin(track_phi);
//  double energy       = par->getEnergy();

  Double_t cov22 = (Double_t) mytrack->getCovMatrix()[5];


return track_pz;



}

