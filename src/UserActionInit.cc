#include "UserActionInit.hh"
#include "RunAction.hh"

namespace G4Miraclue
{
    UserActionInit::UserActionInit(G4VUserPrimaryGeneratorAction *pg,
                                   G4UserRunAction *ra,
                                   G4UserEventAction *ea)
    {
        this->primaryGenerator = pg;
        this->runAction = ra;
        this->eventAction = ea;
    }

    UserActionInit::~UserActionInit()
    {
    }

    void UserActionInit::Build() const
    {
        this->SetUserAction(this->primaryGenerator);
        this->SetUserAction(this->runAction);
        this->SetUserAction(this->eventAction);
    }
}