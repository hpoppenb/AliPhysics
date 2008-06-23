/**************************************************************************
 * Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               *
 **************************************************************************/

//
// ==== Class AliRsnReader ========
//
// This object reads a 'standard' event and converts it into the internal
// format used for resonance analysis (AliRsnEvent).
// 'Standard' event means ESD, standard AOD and MC event.
//
// The input-2-AliRsnEvent conversion is done through a class which reads
// from AliAnalysisTaskSE, which is the standard analysis object. 
// This class creates the AliRsnEvent's before the input event is read, 
// so this class has not to 'create' a new outpu event, but instead it has 
// to 'fill' one which has already been created elsewhere.
// Then, the methods provided here accept an AliRsnEvent as argument passed
// by reference, and they 'fill' this object using the data from the inputs
// passed to them.
// 
// author: A. Pulvirenti
// email : alberto.pulvirenti@ct.infn.it
//

#ifndef ALIRSNREADER_H
#define ALIRSNREADER_H

class AliVEvent;
class AliESDEvent;
class AliAODEvent;
class AliMCEvent;
class AliRsnEvent;
class AliRsnPIDWeightsMgr;

class AliRsnReader : public TObject
{
public:

    enum ESource {
        kESD = 0,
        kESDTPC,
        kAOD,
        kMC,
        kSources
    };

    AliRsnReader(ESource source = kESD, AliRsnPIDWeightsMgr *mgr = 0x0);
    AliRsnReader(const AliRsnReader& copy);
    AliRsnReader& operator=(const AliRsnReader& copy);
    virtual ~AliRsnReader() {}
    
    void    SetWeightsMgr(AliRsnPIDWeightsMgr *mgr) {fWeightsMgr = mgr;}
    void    SetCheckSplit(Bool_t doit = kTRUE) {fCheckSplit = doit;}
    void    SetRejectFakes(Bool_t doit = kTRUE) {fRejectFakes = doit;}
    
    Bool_t  Fill(AliRsnEvent *rsn, AliVEvent *event, AliMCEvent *refMC = 0);
    
protected:

    Bool_t  FillFromESD(AliRsnEvent *rsn, AliESDEvent *event, AliMCEvent *refMC = 0, Bool_t useTPCOnly = kFALSE);
    Bool_t  FillFromAOD(AliRsnEvent *rsn, AliAODEvent *event, AliMCEvent *refMC = 0);
    Bool_t  FillFromMC(AliRsnEvent *rsn, AliMCEvent *mc);

    ESource              fSource;        // flag to choose what kind of data to be read
    Bool_t               fCheckSplit;    // flag to check and remove split tracks
    Bool_t               fRejectFakes;   // flag to reject fake tracks (negative label)
    AliRsnPIDWeightsMgr *fWeightsMgr;    // manager for alternative PID weights

private:
    
    ClassDef(AliRsnReader, 1);
};

#endif
