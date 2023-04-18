#include <string>

#include <argparse/argparse.hpp>
#include <spdlog/spdlog.h>

#include "LBE.hh"
#include "G4ios.hh"
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "DetectorConstruction.hh"
#include "UserActionInit.hh"
#include "PrimaryGeneragor.hh"
#include "RunAction.hh"
#include "EventAction.hh"

struct CliArguments
{
    bool isIntaractiveMode;
    std::string macroFile;
    std::string output;
};

CliArguments *parse(int argc, char **argv)
{
    auto p = new argparse::ArgumentParser("g4miraclue");
    auto ret = new CliArguments{};

    p->add_argument("-i", "--interactive")
        .default_value(false)
        .implicit_value(true)
        .help("interactive mode");

    p->add_argument("-m", "--macro")
        .default_value("macro/run.macro")
        .help("macro file path");

    p->add_argument("-o", "--output")
        .default_value("out.root")
        .help("output root file");

    try
    {
        p->parse_args(argc, argv);
    }
    catch (const std::runtime_error &err)
    {
        spdlog::error("Argument parse err: ");
        spdlog::error(err.what());
        spdlog::error(p->help().str());
        std::exit(1);
    }

    ret->isIntaractiveMode = p->get<bool>("--interactive");
    ret->macroFile = p->get<std::string>("--macro");
    ret->output = p->get<std::string>("--output");

    return ret;
}

int main(int argc, char **argv)
{
    spdlog::set_level(spdlog::level::debug);

    CliArguments *args = parse(argc, argv);
    G4cout << "output file: " << args->output << G4endl;

    auto runManager = new G4RunManager();

    // Geometry
    auto nistManager = G4NistManager::Instance();
    auto detectorConstruction = new G4Miraclue::DetectorConstruction(nistManager);
    runManager->SetUserInitialization(detectorConstruction);
    // Physics
    G4VModularPhysicsList *physicsList = new LBE();
    runManager->SetUserInitialization(physicsList);
    // User Action Register
    auto userActionInit = new G4Miraclue::UserActionInit(new G4Miraclue::PrimaryGenerator(),
                                                         new G4Miraclue::RunAction(),
                                                         new G4Miraclue::EventAction());
    runManager->SetUserInitialization(userActionInit);
    // init
    runManager->Initialize();

    auto uiManager = G4UImanager::GetUIpointer();

    if (args->isIntaractiveMode)
    {
        auto *visExec = new G4VisExecutive();
        visExec->Initialize();

        auto *uiExec = new G4UIExecutive(argc, argv);
        uiExec->SessionStart();
    }
    else
    {
        uiManager->ApplyCommand("/control/execute " + args->macroFile);
        // TODO: tell output file path
    }

    return 0;
}