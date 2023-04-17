#include "UserActionInit.hh"

namespace G4Miraclue
{
    UserActionInit::UserActionInit(PrimaryGenerator *gen)
    {
        this->primaryGenerator = gen;
    }

    UserActionInit::~UserActionInit()
    {
        delete this->primaryGenerator;
    }

    void UserActionInit::Build() const
    {
        this->SetUserAction(this->primaryGenerator);
    }
}