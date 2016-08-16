#include "ExpectCommaOrEndState.h"
#include "AbstractContext.h"

ExpectCommaOrEndState::StateCode_Type
    handle(AbstractContext *context, QQJsonDocument *doc)
{
    ExpectCommaOrEndState::StateCode_Type 
                    ret = AbstractState::SUCCESS;

    auto Token = doc->peekNextToken();
    switch(Token){
        case QQJsonDocument::TOKEN_COMMA:{
            doc->readAToken();
            context->setCurState(AbstractState::Expect_KeyState);
            break;
        }

        case QQJsonDocument::TOKEN_END_ARRAY:
        case QQJsonDocument::TOKEN_END_OBJECT:{
            doc->readAToken();
            auto obj = context->getStack().top();
            if (obj->whichType() != QQJsonX::QQJSON_OBJECT &&
                       obj->whichType() != QQJsonX::QQJSON_ARRAY){
                return AbstractState::FORMAT_ERROR;
            }

            if (context->getStack().size() == 1){
                return AbstractState::FINISHED;
            }
            
            context->getStack().pop();
            auto ptr = context->getStack().top();
            if (ptr->whichType() == QQJsonX::QQJSON_KEY){
                ret = AbstractState::doExpectValue(context, ptr);
                context->setCurState(AbstractState::Expect_CommaOrEndState);
               break;
            }else if (ptr->whichType() == QQJsonX::QQJSON_ARRAY){
               AbstractState::doExpectArrayValue(context, obj);
               context->setCurState(AbstractState::Expect_ArrayValueState);
               break;
                // break;
            }else{
                return AbstractState::FORMAT_ERROR;
            }
        }    
    
        default:
            return AbstractState::FORMAT_ERROR;
    }
    
    return ret; 
}
