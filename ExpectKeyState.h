#ifndef __EXPECTKEYSTATE_H__
#define __EXPECTKEYSTATE_H__

#include "AbstractState.h"
#include "AbstractContext.h"

class QQJsonDocument;
class ExpectKeyState: public AbstractState{
public:
    StateCode_Type handle(AbstractContext *, 
                                QQJsonDocument *) override;
};

#endif
