#ifndef __STARTSTATE_H__
#define __STARTSTATE_H__

#include "AbstractState.h"

class AbstractContext;
class StartState: public AbstractState{
public:
    AbstractState::ErrorCode_Type 
         handle(AbstractContext *context, QQJsonDocument *doc);
};

#endif
