#ifndef __EXPECTCOLONSTATE_H__
#define __EXPECTCOLONSTATE_H__
#include "AbstractState.h"

class ExpectColonState : public AbstractState{
public:
    QQJson::StateCode_Type handle(AbstractContext*, QQJsonDocument *) override;
};

#endif
