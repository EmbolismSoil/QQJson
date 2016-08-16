#ifndef __STARTSTATE_H__
#define __STARTSTATE_H__

#include "AbstractState.h"
#include "AbstractContext.h"

class StartState: public AbstractState{
public:
    AbstractContext::ErrorCode_Type 
         handle(AbstractContext *context, QQJsonDocument *doc);
};

#endif
