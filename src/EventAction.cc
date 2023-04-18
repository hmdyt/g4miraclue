#include "EventAction.hh"
#include "SteppingAction.hh"

namespace G4Miraclue
{
    EventAction::EventAction() {}
    EventAction::~EventAction() {}

    void EventAction::BeginOfEventAction(const G4Event *event)
    {
        spdlog::debug("Event #{:05d} started", event->GetEventID());
        SteppingAction::Instance()->Reset();
    }

    void EventAction::EndOfEventAction(const G4Event *event)
    {
        spdlog::debug("{} MeV", SteppingAction::Instance()->GetEnergyDeposit() / MeV);
        spdlog::debug("Event #{:05d} finished", event->GetEventID());
    }

}