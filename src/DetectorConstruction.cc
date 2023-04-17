#include "DetectorConstruction.hh"

namespace G4Miraclue
{
    namespace WorldLength
    {
        constexpr G4double x = 10.0 * m;
        constexpr G4double y = 10.0 * m;
        constexpr G4double z = 10.0 * m;
    }

    namespace CopyNumber
    {
        constexpr G4int world = 0;
    }

    DetectorConstruction::DetectorConstruction(G4NistManager *nMan)
    {
        this->nistManager = nMan;
    }
    DetectorConstruction::~DetectorConstruction() {}

    G4VPhysicalVolume *DetectorConstruction::Construct()
    {
        auto world = new G4PVPlacement(G4Transform3D(),
                                       "worldPhysical",
                                       this->constructLogicalWorld(),
                                       0,
                                       false,
                                       CopyNumber::world,
                                       true);
        return world;
    }

    G4LogicalVolume *DetectorConstruction::constructLogicalWorld()
    {
        auto material = this->nistManager->FindOrBuildMaterial("G4_AIR");
        auto box = new G4Box("worldBox",
                             WorldLength::x / 2.,
                             WorldLength::y / 2.,
                             WorldLength::z / 2.);
        auto logicalVolume = new G4LogicalVolume(box, material, "worldLogical");
        logicalVolume->SetVisAttributes(G4VisAttributes::GetInvisible());
        return logicalVolume;
    }

}