#include <spdlog/spdlog.h>
#include "RunAction.hh"

namespace G4Miraclue
{
    RunAction::RunAction() {}
    RunAction::~RunAction() {}

    void RunAction::BeginOfRunAction(const G4Run *)
    {
        spdlog::debug("Run started");
    }

    void RunAction::EndOfRunAction(const G4Run *)
    {
        spdlog::debug("Run finished");
    }
}