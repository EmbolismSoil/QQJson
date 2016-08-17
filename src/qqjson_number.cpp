#include "qqjson_number.h"

QQJsonNumber::QQJsonNumber()
{

}

QQJsonX::QQJsonXType QQJsonNumber::whichType()
{
     return QQJsonX::QQJSON_NUMBER;
}

const std::string QQJsonNumber::toString()
{
    return _number;
}
