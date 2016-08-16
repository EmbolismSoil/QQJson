#include "ExpectKeyState.h"
#include "qqjsondocument.h"
#include "qqjsonkey.h" 

class ExpectColonState;
ExpectKeyState::StateCode_Type
    handle(AbstractContext *context, QQJsonDocument *doc)
{
    auto token = doc->peekNextToken();
    switch(token){
        case QQJsonDocument::TOKEN_STRING:{
            auto str = doc->readString();
            auto jsonStr = std::make_shared<QQJsonKey>(str);
            auto jsonX = std::dynamic_pointer_cast<QQJsonX>(jsonStr);
            context->getStack().push(jsonX);
            auto nextState = std::make_shared<ExpectColonState>();
            context->setCurState(
                    std::dynamic_pointer_cast<AbstractState>(nextState)
            );
            break;
        }

        default:{
            return AbstractContext::FORMAT_ERROR; 
        }
    } 

    return AbstractContext::SUCCESS; 
}
