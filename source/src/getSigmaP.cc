#include <iostream>
#include "TMath.h"
#include "streamlog/streamlog.h"
#include "marlin/Global.h"
#include <GeometryUtil.h>
#include "lcio.h"
#include <EVENT/ReconstructedParticle.h>

using namespace lcio;
using namespace marlin;


// ====================================================================
double  getSigmaP(ReconstructedParticle const *par)
// Obtain covariance matrix on (px,py,pz,E) from the
// covariance matrix on helix parameters.
//
// I define the jacobian as the 3x4 matrix:
// (W = omega)
//
//
//       Dpx/DtanL     Dpy/DtanL      Dpz/DtanL     DE/DtanL
//
// J =   Dpx/DW        Dpy/DW         Dpz/DW        DE/DW
//
//       Dpx/DPhi      Dpy/DPhi       Dpz/DPhi      DE/DPhi
//
//
//
//         0           0         PT        Pz*Pz / E / tanL
//
// J =    -Px/W       -Py/W      -Pz/W     -P*P / E / W
//
//        -Py          Px         0        0
//
//
// Order in the covariance matrix on helix parameters:
//
//            tanL tanL         tanL omega        tanL phi
//
// Cov =      omega tanL        omega omega       omega phi
//
//            phi tanL          phi omega         phi phi
//
//
//
{
  TrackVec tracks = par->getTracks();
  if ( tracks.size() == 0) {
      streamlog_out(ERROR) << " Warning: this pfo has no associated tracks. \n";
      std::cerr << " Warning: this pfo has no associated tracks. \n";
      return -999.;
  }

  Track* mytrack = tracks[0];
  double charge  = par->getCharge();
  if ( TMath::Abs(charge) < 0.5 ) {
    streamlog_out(ERROR) << " Warning: null charge particle!"
                         << " This case is not supported." << std::endl;
    std::cerr << " Warning: null charge particle!"
                         << " This case is not supported." << std::endl;
      return -9999.;
  }

  double bField       = MarlinUtil::getBzAtOrigin();
  const double CT     = 2.99792458E-4;

  double track_omega  = mytrack->getOmega();
  double track_tanL   = mytrack->getTanLambda();
  double track_phi    = mytrack->getPhi();
  double track_pt     = (CT*bField) / fabs(track_omega);
  double track_pz     = (track_pt*track_tanL);
  double track_p      = sqrt( (track_pt * track_pt)+(track_pz * track_pz) );
  double track_domega = sqrt((Double_t) mytrack->getCovMatrix()[5]);
  double sigma_p      = track_p/fabs(track_omega) * track_domega;
#if 0
  std::cerr << " track_p= " << track_p 
       << " track_omega= " << track_omega  
       << " track_domega= " << track_domega 
       << " bField= " << bField 
       << std::endl; 
#endif


  return sigma_p;
}
