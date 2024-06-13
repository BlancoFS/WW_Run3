#ifndef DelaPhiMET
#define DelaPhiMET

#include <TMath.h>
#include <algorithm>
#include <TLorentzVector.h>
#include <iostream>

#include <TMinuit.h>
#include <vector>

#include "ROOT/RVec.hxx"

using namespace ROOT;
using namespace ROOT::VecOps;

RVecF getVariables(RVecF lepton_pt, RVecF lepton_phi, RVecF lepton_eta, float MET_pt, float MET_phi, float tkMET_pt, float tkMET_phi){

  TLorentzVector L1;
  TLorentzVector L2;
  TLorentzVector MET;
  TLorentzVector TkMET;

  L1.SetPtEtaPhiM(lepton_pt[0], lepton_eta[0], lepton_phi[0], 0.0);
  L2.SetPtEtaPhiM(lepton_pt[1], lepton_eta[1], lepton_phi[1], 0.0);
  MET.SetPtEtaPhiM(MET_pt, 0.0, MET_phi, 0.0);
  TkMET.SetPtEtaPhiM(tkMET_pt, 0.0, tkMET_phi, 0.0);

  float dphiltkmet = -99.9;
  float dphilmet = -99.9;

  /// dphiltkmet
  
  float d1 = fabs((L1).DeltaPhi(TkMET));
  float d2 = fabs((L2).DeltaPhi(TkMET));
  if (d1<d2) dphiltkmet = d1;
  else       dphiltkmet = d2;

  /// dphilmet
  
  d1 = fabs((L1).DeltaPhi(MET));
  d2 = fabs((L2).DeltaPhi(MET));
  if (d1<d2) dphilmet = d1;
  else       dphilmet = d2;

  float projtkmet = -99.9;
  float projpfmet = -99.9;

  /// mpmet
  
  if (dphilmet < TMath::Pi() / 2.)
    projpfmet = sin(dphilmet) * MET.Pt();
  else
    projpfmet = MET.Pt();
  
  if (dphiltkmet < TMath::Pi() / 2.)
    projtkmet = sin(dphiltkmet) * TkMET.Pt();
  else
    projtkmet = TkMET.Pt();

  float mpmet = min(projtkmet,projpfmet);

  // others

  float detall = fabs(L1.Eta() - L2.Eta());
  float dphill = fabs(L1.DeltaPhi(L2));
  float ptll = (L1+L2).Pt();
  float drll = L1.DeltaR(L2);
  float mll = (L1+L2).M();
  float dphilmet1 = fabs((L1).DeltaPhi(MET));
  float	dphilmet2 = fabs((L2).DeltaPhi(MET));
  float mtw1 = -9999.0;
  float	mtw2 = -9999.0;
  if ( L1.Pt() > 0 && MET.E() > 0 ) {
    mtw1 = sqrt(2 * L1.Pt() * MET.Pt() * (1 - cos( dphilmet1 )));
  }
  if ( L2.Pt() > 0 && MET.E() > 0 ) {  
    mtw2 = sqrt(2 * L2.Pt() * MET.Pt() * (1 - cos( dphilmet2 )));
  }
  float dphillmet = fabs( (L1+L2).DeltaPhi(MET) );
  float mth = -9999.0;
  if ((2. * ptll * MET.Pt() * ( 1. - cos (dphillmet) )) > 0){
    mth = sqrt( 2. * ptll * MET.Pt() * ( 1. - cos (dphillmet) ));
  }

  RVecF results = {dphilmet,dphiltkmet,projpfmet,projtkmet,mpmet,detall,dphill,ptll,drll,mll,mth,mtw1,mtw2};
  return results;
}

#endif
