#include "Geant4/G4UserSteppingAction.hh"
#include "Geant4/G4Step.hh"

namespace G4Miraclue
{
    class SteppingAction : public G4UserSteppingAction
    {
    public:
        static SteppingAction *Instance();
        SteppingAction();
        ~SteppingAction();
        virtual void UserSteppingAction(const G4Step *);
        void Reset();
        G4double GetEnergyDeposit() { return this->eDep; }

    private:
        static SteppingAction *instancePointer;
        G4double eDep;
    };
}