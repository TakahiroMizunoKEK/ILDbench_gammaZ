// *****************************************************
// e+e- ------> ZH ------> ll + X
// Processor for Analysis
//                        ----Junping
// *****************************************************
#include "ZHllXAnalysisProcessor.h"
#include <iostream>
#include <sstream>
#include <iomanip>

#include <EVENT/LCCollection.h>
#include <EVENT/MCParticle.h>
#include <IMPL/LCCollectionVec.h>
#include <EVENT/ReconstructedParticle.h>
#include <IMPL/ReconstructedParticleImpl.h>
#include <EVENT/Cluster.h>
#include <UTIL/LCTypedVector.h>
#include <EVENT/Track.h>
#include <UTIL/LCRelationNavigator.h>
#include <EVENT/ParticleID.h>
#include <marlin/Exceptions.h>
#include "UTIL/PIDHandler.h"

// ----- include for verbosity dependend logging ---------
#include "marlin/VerbosityLevels.h"

#include "TROOT.h"
#include "TFile.h"
#include "TH1D.h"
#include "TNtupleD.h"
#include "TVector3.h"
#include "TMath.h"
#include "TLorentzVector.h"


#include "Utilities.h"

using namespace lcio ;
using namespace marlin ;
using namespace std;

using namespace mylib;

ZHllXAnalysisProcessor aZHllXAnalysisProcessor ;


ZHllXAnalysisProcessor::ZHllXAnalysisProcessor() : Processor("ZHllXAnalysisProcessor") {
  
  // modify processor description
  _description = "ZHllXAnalysisProcessor does whatever it does ..." ;
  

  // register steering parameters: name, description, class-variable, default value

  registerInputCollection( LCIO::MCPARTICLE,
			   "InputMCParticlesCollection" , 
			   "Name of the MCParticle collection"  ,
			   _colMCP ,
			   std::string("MCParticlesSkimmed") ) ;

  registerInputCollection( LCIO::LCRELATION,
			   "InputMCTruthLinkCollection" , 
			   "Name of the MCTruthLink collection"  ,
			   _colMCTL ,
			   std::string("RecoMCTruthLink") ) ;

  registerInputCollection( LCIO::RECONSTRUCTEDPARTICLE,
			   "InputPandoraPFOsCollection" , 
			   "Name of the PandoraPFOs collection"  ,
			   _colPFOs ,
			   std::string("PandoraPFOs") ) ;

  registerOutputCollection( LCIO::RECONSTRUCTEDPARTICLE, 
			    "InputNewPFOsCollection",
			    "Name of the new PFOs collection after some pre-cuts",
			    _colNewPFOs,
			    std::string("newPandoraPFOs") );

  registerOutputCollection( LCIO::RECONSTRUCTEDPARTICLE, 
			    "InputPhotonsCollection",
			    "Name of collection with the selected photons",
			    _colPhotons,
			    std::string("photons") );

  registerInputCollection( LCIO::RECONSTRUCTEDPARTICLE, 
			   "InputJetsCollection",
			   "Name of the jets collection",
			   _colJets,
			   std::string("Refined_2Jet") );

  registerOutputCollection( LCIO::RECONSTRUCTEDPARTICLE, 
			    "InputLeptonsCollection",
			    "Name of collection with the selected leptons",
			    _colLeptons,
			    std::string("leptons") );

  registerOutputCollection( LCIO::RECONSTRUCTEDPARTICLE, 
			    "InputLeptonsOrigCollection",
			    "Name of collection with the selected leptons w/o FSR and BS recovery",
			    _colLeptonsOrig,
			    std::string("leptonsOrig") );
}

void ZHllXAnalysisProcessor::init() { 

  streamlog_out(DEBUG) << "   init called  " 
		       << std::endl ;
  
  
  // usually a good idea to
  printParameters() ;

  _nRun = 0 ;
  _nEvt = 0 ;

  hStatAnl = 0;

}

void ZHllXAnalysisProcessor::processRunHeader( LCRunHeader* run) { 

  _nRun++ ;
} 

void ZHllXAnalysisProcessor::processEvent( LCEvent * evt ) { 

    
  // this gets called for every event 
  // usually the working horse ...
  _nEvt++;

  Double_t kMassZ = 91.187;     // Z mass
  Double_t kMassH = 125.;       // Higgs mass
  Double_t fMassZCut = 40.;     // mass cut for lepton pair from Z
  Double_t fEpsilon = 1.E-10;

  static const Double_t fEnergyCut = 0.05; // minimum energy of each pfo

  Double_t fCosConeCut = 0.998;   // the angle of cone around the direction of photon for merging
  Double_t fCosSmallCone = 0.98;   // the angle of small cone around photon for isolation
  Double_t fCosLargeCone = 0.95;   // the angle of large cone around photon for isolation  
  // cut table
  if (!hStatAnl) hStatAnl = new TH1D("hStatAnl", "Cut Table", 20, 0, 20);
  Double_t selid = -0.5;
  hStatAnl->Fill(++selid);
  gCutName[(Int_t)selid] << "No Cuts" << ends;

  TDirectory *last = gDirectory;
  gFile->cd("/");

  cerr << endl << "Hello, e+e- --> ZH -> llX Analysis! Event No. " << _nEvt << endl;

  static TNtupleD *hAnl = 0;
  if (!hAnl) {
    stringstream tupstr_anl;
    tupstr_anl << "mz:pz:cosz:phiz:mx:px:"  //00->05
	       << "cosx:phix:leptype:mvalep1:mvalep2:"  //10
	       << "coslep1:coslep2:mzgen:pdg0:coslep1mc:" //15
	       << "coslep2mc:cosphoton:coneen:coneec:coslarge:" //20
	       << "eratiolarge:sinlep1:sinlep2:sinlep1mc:sinlep2mc:" //25
	       << "sinphoton:ISR1EMC:ISR2EMC:lep1EAnl:lep1PAnl:" //30 
	       << "lep1thetaAnl:lep1phiAnl:lep2EAnl:lep2PAnl:lep2thetaAnl:" //35
	       << "lep2phiAnl:photonEAnl:photonPAnl:photonthetaAnl:photonphiAnl:" //40
	       << "lep1EMC:lep1PMC:lep1thetaMC:lep1phiMC:lep2EMC:" //45
	       << "lep2PMC:lep2thetaMC:lep2phiMC:photonEMC:photonPMC:" //50
	       << "photonthetaMC:photonphiMC:ISRphotonEMC:ISRphotonPMC:nPhoton:" //55
	       << "photonOrigEAnl:photonOrigPAnl:photonOrigthetaAnl:photonOrigphiAnl:" //60
	       << "photonHCalEnergy:photonECalEnergy" //
	       << ends;
    hAnl = new TNtupleD("hAnl","",tupstr_anl.str().data());
  }

  // ------------------------------------------------
  // -- read out the MCParticles information
  // ------------------------------------------------
  LCCollection *colMC = evt->getCollection(_colMCP);
  if (!colMC) {
    std::cerr << "No MC Collection Found!" << std::endl;
    throw marlin::SkipEventException(this);
  }
  // get the truth information
  Int_t nMCP = colMC->getNumberOfElements();
  TLorentzVector lortzLep1MC,lortzLep2MC,lortzZMC,lortzHMC,lortzISRMC;
  TLorentzVector lortzISR1MC, lortzISR2MC;
  TLorentzVector lortzJ1MC, lortzJ2MC;  
  int pdg0;
    for (Int_t i=6;i<8;i++) {
    MCParticle *mcPart = dynamic_cast<MCParticle*>(colMC->getElementAt(i));
    Int_t pdg = mcPart->getPDG();
    Int_t nparents = mcPart->getParents().size();
    Int_t motherpdg = 0;
	if (i ==6){
	pdg0=pdg;
	}   
 if (nparents > 0) {
      MCParticle *mother = mcPart->getParents()[0];
      motherpdg = mother->getPDG();
    }
    Double_t energy = mcPart->getEnergy();
    TVector3 pv = TVector3(mcPart->getMomentum());
    Int_t ndaughters = mcPart->getDaughters().size();
    Int_t daughterpdg = 0;
    if (ndaughters > 0) {
      MCParticle *daughter = mcPart->getDaughters()[0];
      daughterpdg = daughter->getPDG();
    }
    TLorentzVector lortz = TLorentzVector(pv,energy);
    Int_t ioverlay = mcPart->isOverlay()? 1 : 0;
    //if ((pdg == 13 || pdg == 11) && motherpdg == 0 && ioverlay == 0) {
    if ((pdg == 13 || pdg == 15) && ioverlay == 0) {
      lortzLep1MC = lortz;
      lortzZMC += lortz;
    }
    //if ((pdg == -13 || pdg == -11) && motherpdg == 0 && ioverlay == 0) {
    if ((pdg == -13 || pdg == -15) && ioverlay == 0) {
      lortzLep2MC = lortz;
      lortzZMC += lortz;
    }
    if (pdg == 25 && motherpdg == 0 && ioverlay == 0) {
      lortzHMC = lortz;
    }
    if (pdg > 0 && motherpdg == 25 && ioverlay == 0) {
      lortzJ1MC = lortz;
    }
    if (pdg < 0 && motherpdg == 25 && ioverlay == 0) {
      lortzJ2MC = lortz;
    }
	}
    /*for (Int_t i=4;i<6;i++) {
    MCParticle *mcPart2 = dynamic_cast<MCParticle*>(colMC->getElementAt(i));    
    Double_t energy2 = mcPart2->getEnergy();
    TVector3 pv2 = TVector3(mcPart2->getMomentum());
    TLorentzVector lortz2 = TLorentzVector(pv2,energy2);

    if (i == 4) {
      lortzISR1MC = lortz2;
    }
    if (i == 5) {
      lortzISR2MC = lortz2;
    }
   } */ 

  // get Higgs decay modes
  std::vector<Int_t> nHDecay;
  nHDecay = getHiggsDecayModes(colMC);
  Double_t nHbb = nHDecay[0]; // H---> b b
  Double_t nHWW = nHDecay[1]; // H---> W W
  Double_t nHgg = nHDecay[2]; // H---> g g
  Double_t nHtt = nHDecay[3]; // H---> tau tau
  Double_t nHcc = nHDecay[4]; // H---> c c
  Double_t nHZZ = nHDecay[5]; // H---> Z Z
  Double_t nHaa = nHDecay[6]; // H---> gam gam
  Double_t nHmm = nHDecay[7]; // H---> mu mu

  // ------------------------------------------------
  // -- read out the Thrust information
  // ------------------------------------------------
#if 0
  LCCollection *colSelRecPart = evt->getCollection("SelectedReconstructedParticle");
  Double_t principleThrust = colSelRecPart->parameters().getFloatVal("principleThrustValue");
  Double_t majorThrust = colSelRecPart->parameters().getFloatVal("majorThrustValue");
  Double_t minorThrust = colSelRecPart->parameters().getFloatVal("minorThrustValue");
  FloatVec tAxis;
  FloatVec thrustAxis = colSelRecPart->parameters().getFloatVals("principleThrustAxis",tAxis);
  TVector3 principleAxis = TVector3(thrustAxis[0],thrustAxis[1],thrustAxis[2]);
  Double_t cosThrustAxis = principleAxis.CosTheta();
#endif

  // ------------------------------------------------
  // -- read out the NewPFOs information
  // ------------------------------------------------
  LCCollection *colPFO = evt->getCollection(_colPFOs);
  LCCollection *colNewPFO = evt->getCollection(_colNewPFOs);
  if (!colNewPFO) {
    cerr << "No NewPFOs Collection Found!" << endl;
    throw marlin::SkipEventException(this);
  }
  hStatAnl->Fill(++selid);
  gCutName[(Int_t)selid] << "NewPFOs Collection Found" << ends;
  // get the visible energy
  Int_t nPFOs = colNewPFO->getNumberOfElements();
  TLorentzVector lortzVis = TLorentzVector(0.,0.,0.,0.);
  Int_t nParticles = 0, nParticlesC = 0, nParticlesPt500 = 0;
  for (Int_t i=0;i<nPFOs;i++) {
    ReconstructedParticle *pfo = dynamic_cast<ReconstructedParticle*>(colNewPFO->getElementAt(i));
    TLorentzVector lortz = getLorentzVector(pfo);
    lortzVis += lortz;
    if (pfo->getEnergy() >= fEnergyCut) nParticles++;
    if (pfo->getEnergy() >= fEnergyCut && pfo->getCharge() != 0) nParticlesC++;
    if (lortz.Pt() > 0.5) nParticlesPt500++;
  }

  // ------------------------------------------------
  // -- read out the MCTruthLink information
  // ------------------------------------------------
  LCCollection *colMCTL = evt->getCollection(_colMCTL);

  // ------------------------------------------------
  // -- read out the Leptons information
  // ------------------------------------------------
  LCCollection *colLep = evt->getCollection(_colLeptons);
  Int_t nLeps = colLep? colLep->getNumberOfElements() : 0;
  if (!colLep || nLeps != 2) {
    cerr << "No Leptons Collection Found or nLeptons != 2 !" << endl;
    throw marlin::SkipEventException(this);
  }
  hStatAnl->Fill(++selid);
  gCutName[(Int_t)selid] << "Leptons Collection Found" << ends;
  ReconstructedParticle *leptonMinus = dynamic_cast<ReconstructedParticle*>(colLep->getElementAt(0));
  ReconstructedParticle *leptonPlus  = dynamic_cast<ReconstructedParticle*>(colLep->getElementAt(1));
  ReconstructedParticle *lep_tmp = 0;
  if (leptonMinus->getCharge() > leptonPlus->getCharge()) {
    lep_tmp = leptonMinus;
    leptonMinus = leptonPlus;
    leptonPlus  = lep_tmp;
  }
  Double_t _mva_lep_minus = colLep->getParameters().getFloatVal("MVALepMinus");
  Double_t _mva_lep_plus  = colLep->getParameters().getFloatVal("MVALepPlus");
  Double_t _lep_type = colLep->getParameters().getIntVal("ISOLepType");
  Double_t nPhotonsRecovered = colLep->getParameters().getIntVal("NPhotons");

#if 1
  // ------------------------------------------------
  // -- read out the Photons information
  // ------------------------------------------------
  LCCollection *colPho = evt->getCollection(_colPhotons);
  TLorentzVector lortzPhoton(0.,0.,0.,0.);
  Double_t coneEN=-1,coneEC=-1,cosThetaWithLargeCone=-2,energyRatioWithLargeCone=-2;
  TLorentzVector lortzPhotonOrig(0.,0.,0.,0.);
  int nPhoton = 0;
        float ECalEnergy,HCalEnergy;
        ECalEnergy =0;
        HCalEnergy =0;

  if (colPho && colPho->getNumberOfElements() > 0) {
    nPhoton=colPho->getNumberOfElements();
    ReconstructedParticle *recoPhoton = dynamic_cast<ReconstructedParticle*>(colPho->getElementAt(0));
    lortzPhoton = getLorentzVector(recoPhoton);
    std::vector<lcio::ReconstructedParticle*> photons = recoPhoton->getParticles();
    ReconstructedParticle *thePhoton = photons.at(0);

	ClusterVec clv= thePhoton -> getClusters();
	for (int i=0;i<clv.size();i++){
		Cluster* cl = clv[i];
		FloatVec flv = 	cl -> getSubdetectorEnergies();
		HCalEnergy+=flv[1];		
		ECalEnergy+=flv[0];		
	}

    //TLorentzVector lortzPhotonOrig = getLorentzVector(thePhoton);
    lortzPhotonOrig = getLorentzVector(thePhoton);
    // get photon cone energies
    Bool_t woFSR = kFALSE;
    Double_t coneEnergy0[3] = {0.,0.,0.};
    Double_t pFSR[4] = {0.,0.,0.,0.};
    Double_t pLargeCone[4]  = {0.,0.,0.,0.};
    Int_t nConePhoton = 0;
    getConeEnergy(thePhoton,colPFO,fCosSmallCone,woFSR,coneEnergy0,pFSR,fCosLargeCone,pLargeCone,nConePhoton);


    coneEN     = coneEnergy0[1];
    coneEC     = coneEnergy0[2];
    TLorentzVector lortzLargeCone = TLorentzVector(pLargeCone[0],pLargeCone[1],pLargeCone[2],pLargeCone[3]);
    cosThetaWithLargeCone = getCosTheta(lortzPhotonOrig,lortzLargeCone);
    energyRatioWithLargeCone = lortzPhotonOrig.E()/(lortzPhotonOrig.E()+lortzLargeCone.E());
 
 
	//*added20181122
    for (Int_t i=4;i<6;i++) {
    MCParticle *mcPart2 = dynamic_cast<MCParticle*>(colMC->getElementAt(i));
    Double_t energy2 = mcPart2->getEnergy();
    TVector3 pv2 = TVector3(mcPart2->getMomentum());
    TLorentzVector lortz2 = TLorentzVector(pv2,energy2);

    if (i == 4) {
      lortzISR1MC = lortz2;
    }
    if (i == 5) {
      lortzISR2MC = lortz2;
    }
   }
	//end*	


}
#endif  

#if 0
  // ------------------------------------------------
  // -- read out the Jets information
  // ------------------------------------------------
  LCCollection *colJet = evt->getCollection(_colJets);
  if (!colJet) {
    cerr << "No Refined_2Jet Collection Found!" << endl;
    throw marlin::SkipEventException(this);
  }
  hStatAnl->Fill(++selid);
  gCutName[(Int_t)selid] << "Refined_2Jet Collection Found" << ends;
  Int_t nJets = colJet->getNumberOfElements();
  if (nJets != 2) {
    cerr << "Number of Jets is not 2" << endl;
    throw marlin::SkipEventException(this);
  }
  hStatAnl->Fill(++selid);
  gCutName[(Int_t)selid] << "2 Jets Found" << ends;

  ReconstructedParticle *jets[2];
  // flavor tagging information
  PIDHandler pidh (colJet);
  Int_t algo = pidh.getAlgorithmID("lcfiplus");
  Double_t FLV[2][11];
  Int_t nPFOsCJ1 = 0, nPFOsCJ2 = 0;
  for (Int_t i=0;i<nJets;i++) {
    jets[i] = dynamic_cast<ReconstructedParticle*>(colJet->getElementAt(i));
    const ParticleID & jetID = pidh.getParticleID(jets[i], algo);
    FloatVec params = jetID.getParameters();
    FLV[i][0] = params[pidh.getParameterIndex(algo, "BTag")];
    FLV[i][1] = params[pidh.getParameterIndex(algo, "CTag")];
    FLV[i][2] = params[pidh.getParameterIndex(algo, "BCTag")];
    std::vector<lcio::ReconstructedParticle*> partVec = jets[i]->getParticles();
    for (std::vector<lcio::ReconstructedParticle*>::const_iterator iPart=partVec.begin();iPart!=partVec.end();++iPart) {
      TVector3 momPart = TVector3((*iPart)->getMomentum());
      Double_t pTPart = momPart.Pt();
      if ((*iPart)->getCharge() != 0 && pTPart > 0.5 && i == 0) nPFOsCJ1++;
      if ((*iPart)->getCharge() != 0 && pTPart > 0.5 && i == 1) nPFOsCJ2++;
    }
  }
  Int_t algo_y = pidh.getAlgorithmID("yth");
  const ParticleID & ythID = pidh.getParticleID(jets[0], algo_y);
  FloatVec params_y = ythID.getParameters();
  Double_t yMinus = params_y[pidh.getParameterIndex(algo_y, "y12")];
  Double_t yPlus  = params_y[pidh.getParameterIndex(algo_y, "y23")];
  Double_t yMinus4= params_y[pidh.getParameterIndex(algo_y, "y34")];
  Double_t yPlus4 = params_y[pidh.getParameterIndex(algo_y, "y45")];
#endif  

  // ------------------------------------------------
  // -- get the useful physical quantities and save them to ntuple
  // ------------------------------------------------
  TLorentzVector lortzLep1 = getLorentzVector(leptonMinus);
  TLorentzVector lortzLep2 = getLorentzVector(leptonPlus);
  TLorentzVector lortzZ = lortzLep1 + lortzLep2;

  const Double_t fEcm = 500.;
  TLorentzVector lortzEcm = getLorentzEcm(fEcm);
  TLorentzVector lortzMis = lortzEcm-lortzZ-lortzVis-lortzPhoton;
  TLorentzVector lortzRecoil = lortzEcm-lortzZ;
  TLorentzVector lortzRecoilMC = lortzEcm-lortzZMC;
 
  double v22,v23,v24,v25,v26,photonEMC,photonPMC,photonthetaMC,photonphiMC;
  TLorentzVector lortzphotonmc;
  TLorentzVector ISRphotonmc;
  v22 = sqrt(1.-pow(lortzLep1.CosTheta(),2));
  v23 = sqrt(1.-pow(lortzLep2.CosTheta(),2));
  v24 = sqrt(1.-pow(lortzLep1MC.CosTheta(),2));
  v25 = sqrt(1.-pow(lortzLep2MC.CosTheta(),2));
  v26 = sqrt(1.-pow(lortzPhoton.CosTheta(),2));
 
  if(lortzISR1MC.E()>lortzISR2MC.E()){
	lortzphotonmc=lortzISR1MC;
	ISRphotonmc=lortzISR2MC;
	}else{
	lortzphotonmc=lortzISR2MC;
	ISRphotonmc=lortzISR1MC;
	}
  photonEMC=lortzphotonmc.E();
  photonPMC=lortzphotonmc.P();
  photonthetaMC=lortzphotonmc.Theta();
  photonphiMC=lortzphotonmc.Phi();


  Double_t data_anl[100];
  data_anl[ 0] = lortzZ.M();
  data_anl[ 1] = lortzZ.P();
  data_anl[ 2] = lortzZ.CosTheta();
  data_anl[ 3] = lortzZ.Phi();
  data_anl[ 4] = lortzRecoil.M();
  data_anl[ 5] = lortzRecoil.P();
  data_anl[ 6] = lortzRecoil.CosTheta();
  data_anl[ 7] = lortzRecoil.Phi();
  data_anl[ 8] = _lep_type;
  data_anl[ 9] = _mva_lep_minus;
  data_anl[10] = _mva_lep_plus;
  data_anl[11] = lortzLep1.CosTheta();
  data_anl[12] = lortzLep2.CosTheta();
  data_anl[13] = lortzZMC.M();
  data_anl[14] = pdg0; 
  data_anl[15] = lortzLep1MC.CosTheta();
  data_anl[16] = lortzLep2MC.CosTheta();
  data_anl[17] = lortzPhoton.CosTheta();
  data_anl[18] = coneEN;
  data_anl[19] = coneEC;
  data_anl[20] = cosThetaWithLargeCone;
  data_anl[21] = energyRatioWithLargeCone;
  data_anl[22] = v22;
  data_anl[23] = v23;
  data_anl[24] = v24;
  data_anl[25] = v25;
  data_anl[26] = v26;
  data_anl[27] = lortzISR1MC.P();
  data_anl[28] = lortzISR2MC.P();
  data_anl[29] = lortzLep1.E();
  data_anl[30] = lortzLep1.P();
  data_anl[31] = lortzLep1.Theta();
  data_anl[32] = lortzLep1.Phi();
  data_anl[33] = lortzLep2.E();
  data_anl[34] = lortzLep2.P();
  data_anl[35] = lortzLep2.Theta();
  data_anl[36] = lortzLep2.Phi();
  data_anl[37] = lortzPhoton.E();
  data_anl[38] = lortzPhoton.P();
  data_anl[39] = lortzPhoton.Theta();
  data_anl[40] = lortzPhoton.Phi();

  data_anl[41] = lortzLep1MC.E();
  data_anl[42] = lortzLep1MC.P();
  data_anl[43] = lortzLep1MC.Theta();
  data_anl[44] = lortzLep1MC.Phi();
  data_anl[45] = lortzLep2MC.E();
  data_anl[46] = lortzLep2MC.P();
  data_anl[47] = lortzLep2MC.Theta();
  data_anl[48] = lortzLep2MC.Phi();
  data_anl[49] = photonEMC;
  data_anl[50] = photonPMC;
  data_anl[51] = photonthetaMC;
  data_anl[52] = photonphiMC;  
  data_anl[53] = ISRphotonmc.E();
  data_anl[54] = ISRphotonmc.P();
  
  data_anl[55] = nPhoton;
  data_anl[56] = lortzPhotonOrig.E();
  data_anl[57] = lortzPhotonOrig.P();
  data_anl[58] = lortzPhotonOrig.Theta();
  data_anl[59] = lortzPhotonOrig.Phi();

  data_anl[60] = HCalEnergy;		
  data_anl[61] = ECalEnergy;		

 hAnl->Fill(data_anl);
  
  //-- note: this will not be printed if compiled w/o MARLINDEBUG=1 !

  streamlog_out(DEBUG) << "   processing event: " << evt->getEventNumber() 
  		       << "   in run:  " << evt->getRunNumber() 
  		       << std::endl ;

  //  _nEvt ++ ;

  last->cd();
}



void ZHllXAnalysisProcessor::check( LCEvent * evt ) { 
  // nothing to check here - could be used to fill checkplots in reconstruction processor
}


void ZHllXAnalysisProcessor::end(){ 

  cerr << "ZHllXAnalysisProcessor::end()  " << name() 
       << " processed " << _nEvt << " events in " << _nRun << " runs "
       << endl ;
  //  cerr << endl;
  cerr << "  =============" << endl;
  cerr << "   Cut Summary " << endl;
  cerr << "  =============" << endl;
  cerr << "   ll+4 Jet    " << endl;
  cerr << "  =============" << endl;
  cerr << endl
       << "  -----------------------------------------------------------" << endl
       << "   ID   No.Events    Cut Description                         " << endl
       << "  -----------------------------------------------------------" << endl;
  for (int id=0; id<20 && gCutName[id].str().data()[0]; id++) {
    cerr << "  " << setw( 3) << id
         << "  " << setw(10) << static_cast<int>(hStatAnl->GetBinContent(id+1))
         << "  : " << gCutName[id].str().data() << endl;
  }
  cerr << "  -----------------------------------------------------------" << endl;
  
}
