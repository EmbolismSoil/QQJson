#include "AbstractState.h"
#include "qqjson_array.h"
#include "qqjson_object.h"
#include "AbstractContext.h"

AbstractState::StateCode_Type
         AbstractState::doExpectArrayValue(AbstractContext *context, 
                            jsonPtr json)
{
    auto Stack = context->getStack();
    auto array = Stack.top();

    if (array->whichType() != QQJsonX::QQJSON_ARRAY)
            return FORMAT_ERROR;

    auto jsonArray = std::dynamic_pointer_cast<QQJsonArray>(array);
    jsonArray->addValue(json);

    return SUCCESS;
}

AbstractState::StateCode_Type
  AbstractState::doExpectValue(AbstractContext*context, jsonPtr ptr)
{
    auto Stack = context->getStack();   
    auto Key = Stack.top();
    Stack.pop();
    if (Key->whichType() != QQJsonX::QQJSON_KEY)
        return FORMAT_ERROR;
    auto Object = Stack.top();
    Stack.pop();
    if (Object->whichType() != QQJsonX::QQJSON_OBJECT)
        return FORMAT_ERROR;

    auto Obj = std::dynamic_pointer_cast<QQJsonObject>(Object);

    Obj->addVaule(Key->toString(), ptr);
    Stack.push(Object);
    return SUCCESS;
}
