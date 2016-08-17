#include "AbstractState.h"
#include "qqjson_array.h"
#include "qqjson_object.h"
#include "AbstractContext.h"

QQJson::StateCode_Type
         AbstractState::doExpectArrayValue(AbstractContext *context, 
                            QQJson::jsonPtr json)
{
    std::stack<QQJson::jsonPtr> & Stack = context->getStack();
    auto array = Stack.top();

    if (array->whichType() != QQJsonX::QQJSON_ARRAY)
            return QQJson::FORMAT_ERROR;

    auto jsonArray = std::dynamic_pointer_cast<QQJsonArray>(array);
    jsonArray->addValue(json);

    return QQJson::SUCCESS;
}

QQJson::StateCode_Type
  AbstractState::doExpectValue(AbstractContext*context, QQJson::jsonPtr ptr)
{
    std::stack<QQJson::jsonPtr> & Stack = context->getStack();
    auto Key = Stack.top();
    Stack.pop();
    if (Key->whichType() != QQJsonX::QQJSON_KEY)
        return QQJson::FORMAT_ERROR;
    auto Object = Stack.top();
    Stack.pop();
    if (Object->whichType() != QQJsonX::QQJSON_OBJECT)
        return QQJson::FORMAT_ERROR;

    auto Obj = std::dynamic_pointer_cast<QQJsonObject>(Object);

    Obj->addVaule(Key->toString(), ptr);
    Stack.push(Object);
    return QQJson::SUCCESS;
}
