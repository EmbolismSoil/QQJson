#ifndef __EXPECTKEYSTATE_H__
#define __EXPECTKEYSTATE_H__
#include "AbstractState.h"
#include "qqjsonkey.h"
#include "AbstractContext.h"

class QQJsonDocument;
class ExpectKeyState: public AbstractState{
public:
    virtual QQJson::StateCode_Type 
            handle(AbstractContext *, QQJsonDocument *) override;
};

QQJson::StateCode_Type
ExpectKeyState::handle(AbstractContext *context, QQJsonDocument *doc)
{
    auto token = doc->peekNextToken();
    switch(token){
        case QQJsonDocument::TOKEN_STRING:{
            auto str = doc->readString();
            auto jsonStr = std::make_shared<QQJsonKey>(str);
            auto jsonX = std::dynamic_pointer_cast<QQJsonX>(jsonStr);
            context->getStack().push(jsonX);
            context->setCurState(QQJson::Expect_ColonState);
            break;
        }

        default:{
            return QQJson::FORMAT_ERROR; 
        }
    } 

    return QQJson::SUCCESS; 
}

#endif
