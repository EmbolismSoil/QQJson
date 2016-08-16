#include "ExpectColonState.h"
#include "AbstractContext.h"

ExpectColonState::StateCode_Type
    handle(AbstractContext* context, QQJsonDocument *doc)
{
    auto token = doc->peekNextToken();
    switch(token){
        case QQJsonDocument::TOKEN_COLON:{
            doc->readAToken();
            auto nextState = std::make_shared<ExpectColonState>();
            context->setCurState(AbstractState::Expect_ValueState);
            break;
        }

        default:
            return AbstractState::FORMAT_ERROR;
    }
    return AbstractState::SUCCESS;
}
