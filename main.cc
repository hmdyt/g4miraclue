#include "TTree.h"
#include "G4ios.hh"

int main()
{
    auto tree = new TTree("tree", "tree");

    int a;
    tree->Branch("a", &a);

    for (int i = 0; i < 10; ++i)
    {
        a = i;
        tree->Fill();
    }

    tree->Print();

    G4cout << "hello, world from ROOT and Geant4!" << G4endl;

    return 0;
}