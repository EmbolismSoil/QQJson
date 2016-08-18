#include "ExpectCommaOrEndState.h"
#include "AbstractContext.h"

QQJson::StateCode_Type
    ExpectCommaOrEndState::handle(AbstractContext *context, QQJsonDocument *doc)
{
    QQJson::StateCode_Type 
                    ret = QQJson::SUCCESS;

    auto Token = doc->peekNextToken();
    switch(Token){
        case QQJsonDocument::TOKEN_COMMA:{
            doc->readAToken();
            context->setCurState(QQJson::Expect_KeyState);
            break;
        }

        case QQJsonDocument::TOKEN_END_ARRAY:
        case QQJsonDocument::TOKEN_END_OBJECT:{
            doc->readAToken();
            auto obj = context->getStack().top();
            if (obj->whichType() != QQJsonX::QQJSON_OBJECT &&
                       obj->whichType() != QQJsonX::QQJSON_ARRAY){
                return QQJson::FORMAT_ERROR;
            }
            context->getStack().pop();
            if (context->getStack().size() == 1){
                context->getStack().push(obj);
                return QQJson::FINISHED;
            }
            
            //context->getStack().pop();
            auto ptr = context->getStack().top();
            if (ptr->whichType() == QQJsonX::QQJSON_KEY){
                ret = AbstractState::doExpectValue(context, obj);
                context->setCurState(QQJson::Expect_CommaOrEndState);
               break;
            }else if (ptr->whichType() == QQJsonX::QQJSON_ARRAY){
               AbstractState::doExpectArrayValue(context, obj);
               context->setCurState(QQJson::Expect_ArrayValueState);
               break;
                // break;
            }else{
                return QQJson::FORMAT_ERROR;
            }
        }    
    
        default:
            return QQJson::FORMAT_ERROR;
    }
    
    return ret; 
}
