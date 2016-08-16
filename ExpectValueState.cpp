#include "ExpectValueState.h"
#include "qqjson_number.h"
#include "qqjson_object.h"
#include "qqjson_null.h"
#include "qqjsonstring.h"
#include "qqjson_boolen.h"

using jsonPtr = AbstractContext::jsonPtr;
class ExpectCommaOrEndState;

ExpectValueState::StateCode_Type
    handle(AbstractContext *context, QQJsonDocument *doc)
{
    auto token = doc->peekNextToken();
    ExpectValueState::StateCode_Type ret;
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
            return AbstractContext::FORMAT_ERROR;
    }
    
    auto nextState = std::make_shared<ExpectCommaOrEndState>(); 
    context->setCurState(std::dynamic_pointer_cast<AbstractState>(nextState));
    return ret;
}

ExpectValueState::StateCode_Type
  ExpectValueState::doExpectValue(AbstractContext*context, 
                   AbstractContext::jsonPtr ptr)
{
    auto Stack = context->getStack();   
    auto Key = Stack.top();
    Stack.pop();
    if (Key->whichType() != QQJsonX::QQJSON_KEY)
        return AbstractContext::FORMAT_ERROR;
    auto Object = Stack.top();
    Stack.pop();
    if (Object->whichType() != QQJsonX::QQJSON_OBJECT)
        return AbstractContext::FORMAT_ERROR;

    auto Obj = std::dynamic_pointer_cast<QQJsonObject>(Object);

    Obj->addVaule(Key->toString(), ptr);
    Stack.push(Object);
    return AbstractContext::SUCCESS;
}
