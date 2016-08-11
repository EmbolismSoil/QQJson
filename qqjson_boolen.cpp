#include "qqjson_boolen.h"

QQJsonX::QQJsonXType QQJsonBoolen::whichType()
{
    return QQJsonX::QQJSON_BOOLEN;
}

const std::string QQJsonBoolen::toString()
{
    return _Boolen;
}
