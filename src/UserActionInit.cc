#include "UserActionInit.hh"
#include "RunAction.hh"

namespace G4Miraclue
{
    UserActionInit::UserActionInit(G4VUserPrimaryGeneratorAction *pg,
                                   G4UserRunAction *ra,
                                   G4UserEventAction *ea,
                                   G4UserSteppingAction *sa)
    {
        this->primaryGenerator = pg;
        this->runAction = ra;
        this->eventAction = ea;
        this->steppingAction = sa;
    }

    UserActionInit::~UserActionInit()
    {
    }

    void UserActionInit::Build() const
    {
        this->SetUserAction(this->primaryGenerator);
        this->SetUserAction(this->runAction);
        this->SetUserAction(this->eventAction);
        this->SetUserAction(this->steppingAction);
    }
}