#include "ExpectArrayValue.h"
#include "qqjson_number.h"
#include "qqjson_boolen.h"
#include "qqjson_null.h"
#include "qqjsonstring.h"
#include "qqjson_array.h"
#include "qqjson_object.h"
#include "AbstractContext.h"

using namespace QQJson;
QQJson::StateCode_Type
    ExpectArrayValueState::handle(AbstractContext* context, QQJsonDocument *doc)
{
    auto Token = doc->peekNextToken();
    QQJson::StateCode_Type ret = QQJson::SUCCESS;

    switch(Token){
        case QQJsonDocument::TOKEN_COMMA:{
            doc->readAToken();
            break;
        }
        
        case QQJsonDocument::TOKEN_BEGIN_OBECT:{
            doc->readAToken();
            context->getStack().push(std::make_shared<QQJsonObject>());
            context->setCurState(Expect_KeyState);
            break;
        }

        case QQJsonDocument::TOKEN_STRING:{
            auto str = doc->readString();
            auto jsonX = context->getStack().top();
            if (jsonX->whichType() != QQJsonX::QQJSON_ARRAY){
                ret = FORMAT_ERROR;
                break;
            }

            auto array = std::dynamic_pointer_cast<QQJsonArray>(jsonX); 
            array->addValue(std::make_shared<QQJsonString>(str));
            break;
        }

        case QQJsonDocument::TOKEN_NULL:{
            doc->readAToken();
            auto nullObj = std::make_shared<QQJsonNull>();
            ExpectArrayValueState::doExpectArrayValue(context, nullObj); 
            break;
        }

        case QQJsonDocument::TOKEN_BOOLEN:{
            auto Boolen = doc->readBoolen();
            auto boolObj = std::make_shared<QQJsonBoolen>(Boolen);
            ExpectArrayValueState::doExpectArrayValue(context, boolObj);
            break;
        }            

        case QQJsonDocument::TOKEN_END_ARRAY:
        case QQJsonDocument::TOKEN_END_OBJECT:{
            doc->readAToken();
            auto obj = context->getStack().top();
            if (obj->whichType() != QQJsonX::QQJSON_OBJECT && 
                        obj->whichType() != QQJsonX::QQJSON_ARRAY){
                ret = FORMAT_ERROR;
                break;
            }

            context->getStack().pop();
            auto ptr = context->getStack().top();
            if (ptr->whichType() == QQJsonX::QQJSON_ARRAY){
                ExpectArrayValueState::doExpectArrayValue(context, obj);
                break;
            }else if (ptr->whichType() == QQJsonX::QQJSON_KEY){
                AbstractState::doExpectValue(context, obj);
                context->setCurState(Expect_CommaOrEndState);
                break;
            }else{
                ret = FORMAT_ERROR;
                break;
            }
        }
        
        case QQJsonDocument::TOKEN_NUMER:{
            auto number = doc->readNumber();
            auto numJson = std::make_shared<QQJsonNumber>(number);
            ExpectArrayValueState::doExpectArrayValue(context, numJson);
            break;
        }

        default:
            return FORMAT_ERROR;
    }
    
    return ret;
}

