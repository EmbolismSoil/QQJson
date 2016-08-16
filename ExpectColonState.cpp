#include "ExpectColonState.h"

class ExpectValueState;

ExpectColonState::StateCode_Type
    handle(AbstractContext* context, QQJsonDocument *doc)
{
    auto token = doc->peekNextToken();
    switch(token){
        case QQJsonDocument::TOKEN_COLON:{
            doc->readAToken();
            auto nextState = std::make_shared<ExpectColonState>();
            context->setCurState(
                std::dynamic_pointer_cast<AbstractState>(nextState)
            );
            break;
        }

        default:
            return AbstractContext::FORMAT_ERROR;
    }
    return AbstractContext::SUCCESS;
}
