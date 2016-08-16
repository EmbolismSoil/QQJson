#include "ExpectCommaOrEndState.h"
#include "ExpectArrayValue.h"
#include "ExpectKeyState.h"
#include "ExpectValueState.h"

ExpectCommaOrEndState::StateCode_Type
    handle(AbstractContext *context, QQJsonDocument *doc)
{
    ExpectCommaOrEndState::StateCode_Type 
                    ret = AbstractContext::SUCCESS;

    auto Token = doc->peekNextToken();
    switch(Token){
        case QQJsonDocument::TOKEN_COMMA:{
            doc->readAToken();
            context->setCurState(std::make_shared<ExpectKeyState>());
            break;
        }

        case QQJsonDocument::TOKEN_END_ARRAY:
        case QQJsonDocument::TOKEN_END_OBJECT:{
            doc->readAToken();
            auto obj = context->getStack().top();
            if (obj->whichType() != QQJsonX::QQJSON_OBJECT &&
                       obj->whichType() != QQJsonX::QQJSON_ARRAY){
                return AbstractContext::FORMAT_ERROR;
            }

            if (context->getStack().size() == 1){
                return AbstractContext::FINISHED;
            }
            
            context->getStack().pop();
            auto ptr = context->getStack().top();
            if (ptr->whichType() == QQJsonX::QQJSON_KEY){
                ret = ExpectValueState::doExpectValue(context, ptr);
                context->setCurState(std::make_shared<ExpectCommaOrEndState>());
               break;
            }else if (ptr->whichType() == QQJsonX::QQJSON_ARRAY){
               ExpectArrayValueState::doExpectArrayValue(context, obj);
               auto nextState = std::make_shared<ExpectArrayValueState>();
               context->setCurState(nextState);
               break;
                // break;
            }else{
                return AbstractContext::FORMAT_ERROR;
            }
        }    
    
        default:
            return AbstractContext::FORMAT_ERROR;
    }
    
    return AbstractContext::SUCCESS;
}
