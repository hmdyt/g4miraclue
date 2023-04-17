#include "PrimaryGeneragor.hh"

namespace G4Miraclue
{
    PrimaryGenerator::PrimaryGenerator()
    {
        this->particleGun = new G4ParticleGun();
    }

    PrimaryGenerator::~PrimaryGenerator()
    {
        delete this->particleGun;
    }

    void PrimaryGenerator::GeneratePrimaries(G4Event *event)
    {
        this->particleGun->GeneratePrimaryVertex(event);
    }
}