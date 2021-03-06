using namespace std;
#include "skimTree_Dzero.h"

void skimTree_Dzero(TString ifname="root://eoscms//eos/cms//store/group/phys_heavyions/wangj/DntupleData/ntD_EvtBase_20160425_HighPtJet80_DfinderData_pp_20160329_dPt0tkPt0p5_D0Dstar/ntuple_69.root",
                    TString ofname="test.root",
                    Bool_t skimbranch=true)
{
  cout<<endl;
  cout<<" -- Checking if input and output files are same"<<endl;
  if(ifname==ofname)
    {
      cout<<"    Error: Input file will be overwritten."<<endl;
      return;
    }
  TFile* inf = TFile::Open(ifname);
  TTree* ntDkpi = (TTree*)inf->Get("ntDkpi");
  TTree* ntGen = (TTree*)inf->Get("ntGen");
  TTree* ntHlt = (TTree*)inf->Get("ntHlt");
  TTree* ntHi = (TTree*)inf->Get("ntHi");
  TTree* ntSkim = (TTree*)inf->Get("ntSkim");

  if(skimbranch)
    {
      SelectRecoBranches(ntDkpi);
      SelectGenBranches(ntGen);
      SelectHiBranches(ntHi);
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
      return;
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
      
      ntDkpi_new->Fill();
      ntGen_new->Fill();
      ntHlt_new->Fill(); 
      ntHi_new->Fill(); 
      ntSkim_new->Fill(); 
    } 
  outf->Write();
  cout<<" -- Writing new trees done"<<endl;
  outf->Close();

}
