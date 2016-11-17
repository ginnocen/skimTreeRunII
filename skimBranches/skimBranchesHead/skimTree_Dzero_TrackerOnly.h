#include "uti.h"

void SelectRecoBranches(TTree* nt)
{
  nt->SetBranchStatus("DgenBAncestorpdgId",0);
  nt->SetBranchStatus("DgenBAncestorpt",0);
  nt->SetBranchStatus("DgencollisionId",0);  
}
void SelectGenBranches(TTree* nt)
{
  nt->SetBranchStatus("GBAncestorpdgId",0);
  nt->SetBranchStatus("GBAncestorpt",0);
  nt->SetBranchStatus("GcollisionId",0);

  nt->SetBranchStatus("GpdgId",0);
}
void SelectHiBranches(TTree* nt) 
{
  nt->SetBranchStatus("hiNevtPlane",0);
  nt->SetBranchStatus("hiEvtPlanes",0);
  nt->SetBranchStatus("hiEvtPlanesmult",0);
  nt->SetBranchStatus("hiEvtPlanesqx",0);
  nt->SetBranchStatus("hiEvtPlanesqy",0);
}

void SelectHltBranches(TTree* nthlt)
{
  nthlt->SetBranchStatus("*",0);
  nthlt->SetBranchStatus("HLT_HIL1MinimumBiasHF2AND*",1);
}

