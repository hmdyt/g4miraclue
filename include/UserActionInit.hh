#include "Geant4/G4VUserActionInitialization.hh"

namespace G4Miraclue
{
    class UserActionInit : public G4VUserActionInitialization
    {
    public:
        UserActionInit(G4VUserPrimaryGeneratorAction *pg,
                       G4UserRunAction *ra,
                       G4UserEventAction *ea);
        virtual ~UserActionInit();
        virtual void Build() const;

    private:
        G4VUserPrimaryGeneratorAction *primaryGenerator;
        G4UserRunAction *runAction;
        G4UserEventAction *eventAction;
    };
}
