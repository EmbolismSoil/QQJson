#include "ExpectValueState.h"
#include "AbstractContext.h"
#include "qqjson_number.h"
#include "qqjson_object.h"
#include "qqjson_array.h"
#include "qqjson_null.h"
#include "qqjsonstring.h"
#include "qqjson_boolen.h"

//class ExpectCommaOrEndState;

QQJson::StateCode_Type
    ExpectValueState::handle(AbstractContext *context, QQJsonDocument *doc)
{
    auto token = doc->peekNextToken();
    QQJson::StateCode_Type ret;
    switch(token){
        case QQJsonDocument::TOKEN_NULL:{
           doc->readNull();
           auto nullObj = std::make_shared<QQJsonNull>();
           ret = ExpectValueState::doExpectValue(context,nullObj); 
           context->setCurState(QQJson::Expect_CommaOrEndState);
           break;
        }

        case QQJsonDocument::TOKEN_STRING:{
            auto str = doc->readString();
            auto obj = std::make_shared<QQJsonString>(str);  
            ret = ExpectValueState::doExpectValue(context, obj);
            context->setCurState(QQJson::Expect_CommaOrEndState);
            break;
        }
    
        case QQJsonDocument::TOKEN_BOOLEN:{
            auto boolStr = doc->readBoolen();
            auto boolenObj = std::make_shared<QQJsonBoolen>(boolStr); 
            ret = ExpectValueState::doExpectValue(context, boolenObj);
            context->setCurState(QQJson::Expect_CommaOrEndState);
            break;
        }

        case QQJsonDocument::TOKEN_NUMER:{
            auto number = doc->readNumber();
            auto numberObj = std::make_shared<QQJsonNumber>(number);
            ret = ExpectValueState::doExpectValue(context, numberObj);
            context->setCurState(QQJson::Expect_CommaOrEndState);
            break;
        }

        case QQJsonDocument::TOKEN_BEGIN_ARRAY:{
            doc->readAToken();
            auto array = std::make_shared<QQJsonArray>();
            context->getStack().push(array);
            context->setCurState(QQJson::Expect_ArrayValueState);
            break;
        }

        case QQJsonDocument::TOKEN_BEGIN_OBECT:{
            doc->readAToken();
            auto obj = std::make_shared<QQJsonObject>();
            context->getStack().push(obj);
            context->setCurState(QQJson::Expect_KeyState);
            break;
        }
        default:
            return QQJson::FORMAT_ERROR;
    }
    
    return ret;
}

