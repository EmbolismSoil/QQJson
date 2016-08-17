#include "ExpectValueState.h"
#include "AbstractContext.h"
#include "qqjson_number.h"
#include "qqjson_object.h"
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
        }

        case QQJsonDocument::TOKEN_STRING:{
            auto str = doc->readString();
            auto obj = std::make_shared<QQJsonString>(str);  
            ret = ExpectValueState::doExpectValue(context, obj);
        }
    
        case QQJsonDocument::TOKEN_BOOLEN:{
            auto boolStr = doc->readBoolen();
            auto boolenObj = std::make_shared<QQJsonBoolen>(boolStr); 
            ret = ExpectValueState::doExpectValue(context, boolenObj);
        }

        case QQJsonDocument::TOKEN_NUMER:{
            auto number = doc->readNumber();
            auto numberObj = std::make_shared<QQJsonNumber>(number);
            ret = ExpectValueState::doExpectValue(context, numberObj);
        }
        default:
            return QQJson::FORMAT_ERROR;
    }
    
    context->setCurState(QQJson::Expect_CommaOrEndState);
    return ret;
}

