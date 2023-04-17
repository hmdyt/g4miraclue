#include "Geant4/G4VUserActionInitialization.hh"
#include "PrimaryGeneragor.hh"

namespace G4Miraclue
{
    class UserActionInit : public G4VUserActionInitialization
    {
    public:
        UserActionInit(PrimaryGenerator *gen);
        virtual ~UserActionInit();
        virtual void Build() const;

    private:
        PrimaryGenerator *primaryGenerator;
    };
}
