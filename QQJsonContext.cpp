#include "QQJsonContext.h"

QQJsonContext::ErrorCode_Type 
   QQJsonContext::request(QQJsonDocument *doc)
{
    return getCurState()->handle(this, doc);
}
