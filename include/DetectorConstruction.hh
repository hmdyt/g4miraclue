#include "Geant4/G4VUserDetectorConstruction.hh"
#include "Geant4/G4SystemOfUnits.hh"
#include "Geant4/G4NistManager.hh"
#include "Geant4/G4Box.hh"
#include "Geant4/G4LogicalVolume.hh"
#include "Geant4/G4PVPlacement.hh"
#include "Geant4/G4Transform3D.hh"
#include "Geant4/G4VisAttributes.hh"

namespace G4Miraclue
{
    class DetectorConstruction : public G4VUserDetectorConstruction
    {
    public:
        DetectorConstruction(G4NistManager *nMan);
        ~DetectorConstruction();
        G4VPhysicalVolume *Construct();

    private:
        G4NistManager *nistManager;
        G4LogicalVolume *constructLogicalWorld();
    };
}