#ifndef __EXPECTCOMMAORENDSTATE_H__
#define __EXPECTCOMMAORENDSTATE_H__
#include "AbstractState.h"

class ExpectCommaOrEndState : public AbstractState{
public:
    virtual QQJson::StateCode_Type handle(AbstractContext *, QQJsonDocument *) override;
};
#endif
