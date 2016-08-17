#include "qqjson_null.h"

QQJsonNull::QQJsonNull()
{

}

QQJsonX::QQJsonXType QQJsonNull::whichType()
{
    return QQJsonX::QQJSON_NULL;
}

const std::string QQJsonNull::toString()
{
    return std::string("Null");
}
