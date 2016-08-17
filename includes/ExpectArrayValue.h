#ifndef __EXPECTARRAYVALUE_H__
#define __EXPECTARRAYVALUE_H__
#include "AbstractState.h"

class ExpectArrayValueState : public AbstractState{
public:
    virtual QQJson::StateCode_Type handle(AbstractContext*, QQJsonDocument *) override;
};

#endif
