#ifndef __EXPECTARRAYVALUE_H__
#define __EXPECTARRAYVALUE_H__
#include "AbstractState.h"


class ExpectArrayValueState : public AbstractState{
public:
    StateCode_Type handle(AbstractContext*, QQJsonDocument *) override;
    static StateCode_Type doExpectArrayValue(AbstractContext*, 
                                                AbstractContext::jsonPtr);
};

#endif
