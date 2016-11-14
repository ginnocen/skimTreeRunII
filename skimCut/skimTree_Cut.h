#include "uti.h"
#include "setBranches.h"

void SelectRecoBranches(TTree* nt)
{
  nt->SetBranchStatus("DtktkRes*",0);
  nt->SetBranchStatus("Dtrk3*",0);
  nt->SetBranchStatus("Dtrk4*",0);
  nt->SetBranchStatus("DRestrk*",0);
}

void SelectHltBranches(TTree* nthlt)
{
  nthlt->SetBranchStatus("*",0);
  nthlt->SetBranchStatus("HLT_HIL1MinimumBiasHF2AND*",1);
}

bool passeventsel()
{
  Bool_t returnval = false;
  if(//pcollisionEventSelection &&
     pprimaryVertexFilter &&
     phfCoincFilter3 &&
     pclusterCompatibilityFilter &&
     TMath::Abs(PVz) < 15.0)
    {
      returnval = true;
    }
  return returnval;
}

bool passcutsel(Int_t j)
{
  Bool_t returnval = false;
  if(Dtrk1highPurity[j] && Dtrk1highPurity[j] &&
     TMath::Abs(Dtrk1Eta[j]) < 1.5 && TMath::Abs(Dtrk2Eta[j]) < 1.5 &&
     Dtrk1Pt[j] > 1. && Dtrk2Pt[j] > 1. && //0.7
     TMath::Abs(Dtrk1PtErr[j]/Dtrk1Pt[j]) < 0.3 && TMath::Abs(Dtrk2PtErr[j]/Dtrk2Pt[j]) < 0.3 )
     //(Dtrk1PixelHit[j]+Dtrk1StripHit[j]) >= 10.5 && (Dtrk2PixelHit[j]+Dtrk2StripHit[j]) >= 10 && //
     //(Dtrk1Chi2ndf[j]/(Dtrk1nStripLayer[j]+Dtrk1nPixelLayer[j])) < 0.15 && (Dtrk2Chi2ndf[j]/(Dtrk2nStripLayer[j]+Dtrk2nPixelLayer[j])) < 0.15 )
    {
      if(TMath::Abs(Dy[j]) < 1. &&
         (DlxyBS[j]/DlxyBSErr[j]) > 2.5)
        {
          if(Dalpha[j] < 0.12)
            {
              if((Dpt[j]>1 && Dpt[j]<2   && (DsvpvDistance[j]/DsvpvDisErr[j])>6.00 && Dchi2cl[j]>0.250) ||
                 (Dpt[j]>2 && Dpt[j]<4   && (DsvpvDistance[j]/DsvpvDisErr[j])>5.86 && Dchi2cl[j]>0.224) ||
                 (Dpt[j]>4 && Dpt[j]<5   && (DsvpvDistance[j]/DsvpvDisErr[j])>5.46 && Dchi2cl[j]>0.196) ||
                 (Dpt[j]>5 && Dpt[j]<6   && (DsvpvDistance[j]/DsvpvDisErr[j])>4.86 && Dchi2cl[j]>0.170) ||
                 (Dpt[j]>6 && Dpt[j]<8   && (DsvpvDistance[j]/DsvpvDisErr[j])>4.54 && Dchi2cl[j]>0.125) ||
                 (Dpt[j]>8 && Dpt[j]<10  && (DsvpvDistance[j]/DsvpvDisErr[j])>4.42 && Dchi2cl[j]>0.091) ||
                 (Dpt[j]>10 && Dpt[j]<15 && (DsvpvDistance[j]/DsvpvDisErr[j])>4.06 && Dchi2cl[j]>0.069) ||
                 (Dpt[j]>15 && Dpt[j]<20 && (DsvpvDistance[j]/DsvpvDisErr[j])>3.71 && Dchi2cl[j]>0.056) ||
                 (Dpt[j]>20 && Dpt[j]<25 && (DsvpvDistance[j]/DsvpvDisErr[j])>3.25 && Dchi2cl[j]>0.054) ||
                 (Dpt[j]>25 && (DsvpvDistance[j]/DsvpvDisErr[j])>2.97 && Dchi2cl[j]>0.050))
                {
                  returnval = true;
                }
            }
        }
    }
  return returnval;
}
