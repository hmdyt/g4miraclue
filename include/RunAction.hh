#include "Geant4/G4UserRunAction.hh"

namespace G4Miraclue
{
    class RunAction : public G4UserRunAction
    {
    public:
        RunAction();
        ~RunAction();
        void BeginOfRunAction(const G4Run *);
        void EndOfRunAction(const G4Run *);
    };
}