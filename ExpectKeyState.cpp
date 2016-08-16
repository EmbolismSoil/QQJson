#include "ExpectKeyState.h"
#include "AbstractContext.h"
#include "qqjsondocument.h"
#include "qqjsonkey.h" 

//class ExpectColonState;
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
            context->setCurState(AbstractState::Expect_ColonState);
            break;
        }

        default:{
            return AbstractState::FORMAT_ERROR; 
        }
    } 

    return AbstractState::SUCCESS; 
}
