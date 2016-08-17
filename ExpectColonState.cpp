#include "ExpectColonState.h"
#include "AbstractContext.h"

QQJson::StateCode_Type
    ExpectColonState::handle(AbstractContext* context, QQJsonDocument *doc)
{
    auto token = doc->peekNextToken();
    switch(token){
        case QQJsonDocument::TOKEN_COLON:{
            doc->readAToken();
            auto nextState = std::make_shared<ExpectColonState>();
            context->setCurState(QQJson::Expect_ValueState);
            break;
        }

        default:
            return QQJson::FORMAT_ERROR;
    }
    return QQJson::SUCCESS;
}
