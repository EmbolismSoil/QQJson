#include "AbstractState.h"
#include "AbstractContext.h"

class StartState: public AbstractState{
public:
    AbstractContext::ErrorCode_Type 
         handle(AbstractContext *context, QQJsonDocument *doc);
};
