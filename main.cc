#include <string>

#include <argparse/argparse.hpp>
#include <spdlog/spdlog.h>

#include "FTFP_BERT.hh"
#include "G4ios.hh"
#include "G4RunManager.hh"

#include "DetectorConstruction.hh"

struct CliArguments
{
    std::string output;
};

CliArguments *parse(int argc, char **argv)
{
    auto p = new argparse::ArgumentParser("g4miraclue");
    auto ret = new CliArguments{};

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

    ret->output = p->get<std::string>("--output");

    return ret;
}

int main(int argc, char **argv)
{
    CliArguments *args = parse(argc, argv);
    G4cout << "output file: " << args->output << G4endl;

    auto nistManager = G4NistManager::Instance();
    auto detectorConstruction = new G4Miraclue::DetectorConstruction(nistManager);

    auto runManager = new G4RunManager();
    runManager->SetUserInitialization(new FTFP_BERT());
    runManager->SetUserInitialization(detectorConstruction);
    runManager->Initialize();

    return 0;
}