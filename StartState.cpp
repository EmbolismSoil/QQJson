#include "StartState.h"

class QQJsonKey;
class QQJsonObject; 
class ExpectKeyState;

AbstractContext::ErrorCode_Type
    handle(AbstractContext *context, QQJsonDocument *doc)
{
    auto Token = doc->peekNextToken();
    switch(Token){
        case QQJsonDocument::TOKEN_BEGIN_OBECT :{
            doc->readAToken();
            auto Key = std::make_shared<QQJsonKey>("root");
            context->getStack().push(std::dynamic_pointer_cast<QQJsonX>(Key));
            auto Obj = std::make_shared<QQJsonObject>();
            context->getStack().push(std::dynamic_pointer_cast<QQJsonX>(Obj));
            auto nextState = std::make_shared<ExpectKeyState>();
            context->setCurState(std::dynamic_pointer_cast<AbstractState>(nextState));
            break;
        }
        default:
            return -1;    
    }
   return 0;
}
