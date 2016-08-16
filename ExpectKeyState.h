#include "AbstractState.h"
#include "AbstractContext.h"

class QQJsonDocument;
class ExpectKeyState: public AbstractState{
public:
    StateCode_Type handle(AbstractContext *, 
                                QQJsonDocument *) override;
};
