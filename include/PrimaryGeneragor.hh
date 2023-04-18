#include "Geant4/G4SystemOfUnits.hh"
#include "Geant4/G4VUserPrimaryGeneratorAction.hh"
#include "Geant4/G4ParticleGun.hh"
#include "Geant4/G4ParticleTable.hh"

namespace G4Miraclue
{
    class PrimaryGenerator : public G4VUserPrimaryGeneratorAction
    {
    public:
        PrimaryGenerator();
        ~PrimaryGenerator();
        virtual void GeneratePrimaries(G4Event *);

    private:
        G4ParticleGun *particleGun;
    };
}