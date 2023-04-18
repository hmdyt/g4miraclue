#include <spdlog/spdlog.h>
#include "Geant4/G4UserEventAction.hh"
#include "Geant4/G4SystemOfUnits.hh"
#include "Geant4/G4Event.hh"

namespace G4Miraclue
{
    class EventAction : public G4UserEventAction
    {
    public:
        EventAction();
        ~EventAction();
        virtual void BeginOfEventAction(const G4Event *event);
        virtual void EndOfEventAction(const G4Event *event);
    };
}