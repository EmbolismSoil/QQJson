#ifndef __EXPECTCOMMAORENDSTATE_H__
#define __EXPECTCOMMAORENDSTATE_H__
#include "AbstractState.h"

class ExpectCommaOrEndState : public AbstractState{
public:
    StateCode_Type handle(AbstractContext *, QQJsonDocument *) override;
};
#endif
