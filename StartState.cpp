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
            auto Obj = std::make_shared<QQJsonObject>();
            auto nextState = std::make_shared<ExpectKeyState>();

            context->getStack().push(std::dynamic_pointer_cast<QQJsonX>(Key));
            context->getStack().push(std::dynamic_pointer_cast<QQJsonX>(Obj));

            context->setCurState(std::dynamic_pointer_cast<AbstractState>(nextState));
            break;
        }
        default:
            return AbstractContext::FORMAT_ERROR;    
    }
   return AbstractContext::SUCCESS;
}
