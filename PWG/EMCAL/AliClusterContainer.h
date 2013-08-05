#ifndef AliClusterContainer_H
#define AliClusterContainer_H

//
// container with name, TClonesArray and cuts for particles
//

class TLorentzVector;

class AliVEvent;
class AliVCluster;

#include "AliEmcalContainer.h"

class AliClusterContainer : public AliEmcalContainer {
 public:
  AliClusterContainer();
  AliClusterContainer(const char *name); 
  virtual ~AliClusterContainer(){;}

  void SetClusterArray(AliVEvent *event);

  void SetClusPtCut(Double_t cut)                  { fClusPtCut      = cut ; }
  void SetClusTimeCut(Double_t min, Double_t max)  { fClusTimeCutLow = min ; fClusTimeCutUp = max ; }
  void SetClusterBitMap(UInt_t m)                  { fClusterBitMap     = m ; }
  void SetMCClusterBitMap(UInt_t m)                { fMCClusterBitMap   = m ; }
  void SetMinMCLabel(Int_t s)                      { fMinMCLabel        = s ; }

  AliVCluster                *GetLeadingCluster(const char* opt="")  const;
  AliVCluster                *GetCluster(Int_t i)                    const;
  AliVCluster                *GetAcceptCluster(Int_t i)              const;
  AliVCluster                *GetNextAcceptCluster(Int_t i=-1)       const;
  void                        GetMomentum(TLorentzVector &mom, Int_t i) const;
  Bool_t                      AcceptCluster(AliVCluster         *vp) const;
  Int_t                       GetNClusters()                         const   {return GetNEntries();}

 protected:
  Double_t                    fClusPtCut;                  // cut on cluster pt
  Double_t                    fClusTimeCutLow;             // low time cut for clusters
  Double_t                    fClusTimeCutUp;              // up time cut for clusters
  UInt_t                      fClusterBitMap;              // bit map of accepted clusters (non MC)
  UInt_t                      fMCClusterBitMap;            // bit map of accepted MC clusters
  Int_t                       fMinMCLabel;                 // minimum MC label value for the tracks/clusters being considered MC particles

 private:
  AliClusterContainer(const AliClusterContainer& obj); // copy constructor
  AliClusterContainer& operator=(const AliClusterContainer& other); // assignment

  ClassDef(AliClusterContainer,1);

};

#endif

