/*
 * **********************************************************
 * Virtual class for processing trees of AliReducedEventInfo
 * Authors: Ionut-Cristian Arsene, iarsene@cern.ch, i.c.arsene@fys.uio.no
 *                Jacobus Onderwaater, j.onderwaater@gsi.de, jacobus.onderwaater@cern.ch
 * Creation date: 2015/10/01
 *********************************************************
 */

#include "AliReducedAnalysisTaskSE.h"

ClassImp(AliReducedAnalysisTaskSE);


//___________________________________________________________________________
AliReducedAnalysisTaskSE::AliReducedAnalysisTaskSE() :
  TObject(),
  fName(""),
  fTitle(""),
  fHistosManager(0x0),
  fMixingHandler(0x0),
  fEvent(0x0),
  fEventCuts(),
  fTrackCuts(),
  fPairCuts()
{
  //
  // default constructor
  //
  for(Int_t i=0; i<AliReducedVarManager::kNVars; ++i)
    fValues[i] = 0.0;
  //fEventCuts = new TList(); 
  //fTrackCuts = new TList(); 
  //fPairCuts = new TList(); 
  fEventCuts.SetOwner(kTRUE);
  fTrackCuts.SetOwner(kTRUE);
  fPairCuts.SetOwner(kTRUE);
}


//___________________________________________________________________________
AliReducedAnalysisTaskSE::AliReducedAnalysisTaskSE(const Char_t* name, const Char_t* title) :
  TObject(),
  fName(name),
  fTitle(title),
  fHistosManager(0x0),
  fMixingHandler(0x0),
  fEvent(0x0),
  fEventCuts(),
  fTrackCuts(),
  fPairCuts()
{
  //
  // named constructor
  //
  for(Int_t i=0; i<AliReducedVarManager::kNVars; ++i)
    fValues[i] = 0.0;
  //fEventCuts = new TList();
  //fTrackCuts = new TList();
  //fPairCuts = new TList();
  fEventCuts.SetOwner(kTRUE);
  fTrackCuts.SetOwner(kTRUE);
  fPairCuts.SetOwner(kTRUE);
}


//___________________________________________________________________________
AliReducedAnalysisTaskSE::~AliReducedAnalysisTaskSE() 
{
  //
  // destructor
  //
  /*if(fEventCuts) {fEventCuts->Clear("C"); delete fEventCuts;}
  if(fTrackCuts) {fTrackCuts->Clear("C"); delete fTrackCuts;}
  if(fPairCuts) {fPairCuts->Clear("C"); delete fPairCuts;}*/
  fEventCuts.Clear("C"); fTrackCuts.Clear("C"); fPairCuts.Clear("C");
}

//___________________________________________________________________________
void AliReducedAnalysisTaskSE::Init() {
   //
   // initialization (typically called in AliAnalysisTask::UserCreateOutputObjects())
   //
}

//___________________________________________________________________________
void AliReducedAnalysisTaskSE::Process() {
   //
   // process a given event (typically called in AliAnalysisTask::UserExec())
   //
}

//___________________________________________________________________________
void AliReducedAnalysisTaskSE::Finish() {
   //
   // finish, to be executed after all events were processed
   //
}

//___________________________________________________________________________
Bool_t AliReducedAnalysisTaskSE::IsEventSelected(AliReducedBaseEvent* event) {
   //
   //
   //
}
//___________________________________________________________________________
Bool_t AliReducedAnalysisTaskSE::IsTrackSelected(AliReducedBaseTrack* track) {
   //
   //
   //
}
//___________________________________________________________________________
Bool_t AliReducedAnalysisTaskSE::IsPairSelected(AliReducedBaseTrack* pair) {
   //
   //
   //
}
