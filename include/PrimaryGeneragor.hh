#include "Geant4/G4VUserPrimaryGeneratorAction.hh"
#include "Geant4/G4ParticleGun.hh"

namespace G4Miraclue
{
    class PrimaryGenerator : public G4VUserPrimaryGeneratorAction
    {
    public:
        PrimaryGenerator();
        ~PrimaryGenerator();
        void GeneratePrimaries(G4Event *);

    private:
        G4ParticleGun *particleGun;
    };
}