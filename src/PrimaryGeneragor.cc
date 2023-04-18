#include "PrimaryGeneragor.hh"

namespace G4Miraclue
{
    PrimaryGenerator::PrimaryGenerator()
    {
        this->particleGun = new G4ParticleGun(1);
        auto particle = G4ParticleTable::GetParticleTable()->FindParticle("gamma");
        this->particleGun->SetParticleDefinition(particle);
        this->particleGun->SetParticlePosition(G4ThreeVector(0, 0, 50 * cm));
        this->particleGun->SetParticleMomentumDirection(G4ThreeVector(0, 0, -1));
        this->particleGun->SetParticleEnergy(1 * GeV);
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