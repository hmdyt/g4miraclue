#include "UserActionInit.hh"
#include "RunAction.hh"

namespace G4Miraclue
{
    UserActionInit::UserActionInit(G4VUserPrimaryGeneratorAction *pg,
                                   G4UserRunAction *ra)
    {
        this->primaryGenerator = pg;
        this->runAction = ra;
    }

    UserActionInit::~UserActionInit()
    {
    }

    void UserActionInit::Build() const
    {
        this->SetUserAction(this->primaryGenerator);
        this->SetUserAction(this->runAction);
    }
}