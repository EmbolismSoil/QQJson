#include "StartState.h"
#include "qqjsonkey.h"
#include "AbstractContext.h"
#include "qqjson_object.h"
#include "QQJsonCommon.h"

using namespace QQJson;
QQJson::StateCode_Type
    StartState::handle(AbstractContext *context, QQJsonDocument *doc)
{
    auto Token = doc->peekNextToken();
    switch(Token){
        case QQJsonDocument::TOKEN_BEGIN_OBECT :{
            doc->readAToken();

            auto Key = std::make_shared<QQJsonKey>("root");
            auto Obj = std::make_shared<QQJsonObject>();

            context->getStack().push(std::dynamic_pointer_cast<QQJsonX>(Key));
            context->getStack().push(std::dynamic_pointer_cast<QQJsonX>(Obj));

            context->setCurState(Expect_KeyState);
            break;
        }
        default:
            return QQJson::FORMAT_ERROR;    
    }
   return SUCCESS;
}
