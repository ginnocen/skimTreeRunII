using namespace std;
#include "uti.h"
#include "setBranches.h"
#include "skimTree_Cut.h"

int skimTree_Cut(TString ifname="",
                 TString ofname="",
                 Int_t PD=1,
                 Bool_t skimbranch=true)
{
  cout<<endl;
  cout<<" -- Checking if input and output files are same"<<endl;
  if(ifname==ofname)
    {
      cout<<"    Error: Input file will be overwritten."<<endl;
      return 0;
    }
  TFile* inf = TFile::Open(ifname);
  TTree* ntDkpi = (TTree*)inf->Get("ntDkpi");
  TTree* ntGen = (TTree*)inf->Get("ntGen");
  TTree* ntHlt = (TTree*)inf->Get("ntHlt");
  TTree* ntHi = (TTree*)inf->Get("ntHi");
  TTree* ntSkim = (TTree*)inf->Get("ntSkim");

  SetRecoBranches(ntDkpi);
  SetHltBranches(ntHlt);
  SetSkimBranches(ntSkim);
  if(skimbranch)
    {
      SelectHltBranches(ntHlt);
    }
  TFile* outf = TFile::Open(ofname,"recreate");
  TTree* ntDkpi_new = ntDkpi->CloneTree(0);
  TTree* ntGen_new = ntGen->CloneTree(0);
  TTree* ntHlt_new = ntHlt->CloneTree(0);
  TTree* ntHi_new = ntHi->CloneTree(0);
  TTree* ntSkim_new = ntSkim->CloneTree(0);

  cout<<" -- Check evt no. for three trees"<<endl;
  cout<<"    "<<ntDkpi->GetEntries()<<", "<<ntGen->GetEntries()<<", "<<ntHlt->GetEntries()<<", "<<ntHi->GetEntries()<<", "<<ntSkim->GetEntries()<<endl;
  if(ntDkpi->GetEntries()!=ntHlt->GetEntries())
    {
      cout<<"    Error: Event numbers are different in three trees."<<endl;
      return 0;
    }
  Long64_t nentries = ntDkpi->GetEntries();

  cout<<" -- Event reading"<<endl;
  for(Long64_t i=0;i<nentries;i++)
    {
      if(i%1000000==0) cout<<setiosflags(ios::left)<<"    "<<setw(8)<<i<<" / "<<nentries<<endl;
      ntDkpi->GetEntry(i);
      ntGen->GetEntry(i);
      ntHlt->GetEntry(i);
      ntHi->GetEntry(i);
      ntSkim->GetEntry(i);
      if((PD==1&&HLT_HIL1MinimumBiasHF2AND_part7_v1) ||
         (PD==2&&HLT_HIL1MinimumBiasHF2AND_part1_v1) ||
         (PD==3&&HLT_HIL1MinimumBiasHF2AND_part2_v1) ||
         (PD==4&&HLT_HIL1MinimumBiasHF2AND_part3_v1) ||
         (PD==5&&HLT_HIL1MinimumBiasHF2AND_part4_v1) ||
         (PD==6&&HLT_HIL1MinimumBiasHF2AND_part5_v1) ||
         (PD==7&&HLT_HIL1MinimumBiasHF2AND_part6_v1) ||
         (PD==8&&HLT_HIL1MinimumBiasHF2AND_part8_v1) ||
         (PD==9&&HLT_HIL1MinimumBiasHF2AND_part9_v1) ||
         (PD==10&&HLT_HIL1MinimumBiasHF2AND_part10_v1) ||
         (PD==11&&HLT_HIL1MinimumBiasHF2AND_part11_v1) ||
         (PD==0&&(HLT_HIL1MinimumBiasHF2AND_part1_v1||HLT_HIL1MinimumBiasHF2AND_part2_v1||HLT_HIL1MinimumBiasHF2AND_part3_v1)))
        {
          if(passeventsel())
            {
              bool flag = false;
              for(int j=0;j<Dsize;j++)
                {
                  if(passcutsel(j))
                    {
                      flag = true;
                      break;
                    }
                }
              if(flag)
                {
                  ntDkpi_new->Fill();
                  ntGen_new->Fill();
                  ntHlt_new->Fill(); 
                  ntHi_new->Fill(); 
                  ntSkim_new->Fill();
                }
            }
        }
    } 
  outf->Write();
  cout<<" -- Writing new trees done"<<endl;
  outf->Close();

  return 1;  
}
