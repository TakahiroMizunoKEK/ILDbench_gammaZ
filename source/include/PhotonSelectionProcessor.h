#ifndef PhotonSelectionProcessor_h
#define PhotonSelectionProcessor_h 1

#include "marlin/Processor.h"
#include "lcio.h"
#include <string>
#include "TH1D.h"

#include "TMVA/Reader.h"


/**  processor for selecting the two isolated leptons from Z decay, with BS and FSR recovered.
 * @version $Id: PhotonSelectionProcessor.h,v 1.0 2013-10-31 12:57:39 Junping Exp $ 
 */

class PhotonSelectionProcessor : public marlin::Processor {
  
 public:
  
  virtual Processor*  newProcessor() { return new PhotonSelectionProcessor ; }
  
  
  PhotonSelectionProcessor() ;
  
  /** Called at the begin of the job before anything is read.
   * Use to initialize the processor, e.g. book histograms.
   */
  virtual void init() ;
  
  /** Called for every run.
   */
  virtual void processRunHeader( LCRunHeader* run ) ;
  
  /** Called for every event - the working horse.
   */
  virtual void processEvent( LCEvent * evt ) ; 
  
  
  virtual void check( LCEvent * evt ) ; 
  
  
  /** Called after data processing for clean up.
   */
  virtual void end() ;
  
  
 protected:

  /** Input collection name.
   */
  std::string _colPFOs ;
  std::string _colNewPFOs ;
  std::string _colPhotons ;

  int _nRun ;
  int _nEvt ;

  TH1D *hStatA;
  std::stringstream gCutName[20];

} ;

#endif



