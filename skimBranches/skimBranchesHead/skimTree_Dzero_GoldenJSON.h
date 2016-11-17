#include "uti.h"

void SelectRecoBranches(TTree* nt)
{
  nt->SetBranchStatus("PVxE",0);
  nt->SetBranchStatus("PVyE",0);
  nt->SetBranchStatus("PVzE",0);
  nt->SetBranchStatus("BSxErr",0);
  nt->SetBranchStatus("BSyErr",0);
  nt->SetBranchStatus("BSzErr",0);
  nt->SetBranchStatus("BSdxdz",0);
  nt->SetBranchStatus("BSdydz",0);
  nt->SetBranchStatus("BSdxdzErr",0);
  nt->SetBranchStatus("BSdydzErr",0);
  nt->SetBranchStatus("BSWidth*",0);
  nt->SetBranchStatus("Dmax*",0);
  nt->SetBranchStatus("Dtrk1Idx",0);
  nt->SetBranchStatus("Dtrk2Idx",0);
  nt->SetBranchStatus("Dtrk1EtaErr",0);
  nt->SetBranchStatus("Dtrk2EtaErr",0);
  nt->SetBranchStatus("Dtrk1PhiErr",0);
  nt->SetBranchStatus("Dtrk2PhiErr",0);
  nt->SetBranchStatus("Dtrk1Y",0);
  nt->SetBranchStatus("Dtrk2Y",0);
  nt->SetBranchStatus("Dtrk1D0Err",0);
  nt->SetBranchStatus("Dtrk2D0Err",0);
  nt->SetBranchStatus("Dtrk1MVAVal",0);
  nt->SetBranchStatus("Dtrk2MVAVal",0);
  nt->SetBranchStatus("Dtrk1Quality",0);
  nt->SetBranchStatus("Dtrk2Quality",0);
}
void SelectGenBranches(TTree* nt)
{
  nt->SetBranchStatus("GpdgId",0);
}
void SelectHiBranches(TTree* nt) 
{
}

void SelectHltBranches(TTree* nthlt)
{
  nthlt->SetBranchStatus("*",0);
  nthlt->SetBranchStatus("HLT_HIL1MinimumBiasHF2AND*",1);
}

