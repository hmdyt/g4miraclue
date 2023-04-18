#include "SteppingAction.hh"

namespace G4Miraclue
{
    SteppingAction *SteppingAction::instancePointer = 0;

    SteppingAction *SteppingAction::Instance()
    {
        return SteppingAction::instancePointer;
    }

    SteppingAction::SteppingAction()
    {
        this->eDep = 0;
        SteppingAction::instancePointer = this;
    }

    SteppingAction::~SteppingAction()
    {
        SteppingAction::instancePointer = 0;
    }

    void SteppingAction::UserSteppingAction(const G4Step *step)
    {
        this->eDep += step->GetTotalEnergyDeposit();
    }

    void SteppingAction::Reset()
    {
        this->eDep = 0;
    }
}