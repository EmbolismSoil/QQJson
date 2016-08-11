#include "qqjsonkey.h"

QQJsonKey::QQJsonKey(const std::string key):
    _key(key)
{

}

QQJsonX::QQJsonXType QQJsonKey::whichType()
{
     return QQJsonX::QQJSON_KEY;
}

const std::string QQJsonKey::toString()
{
     return _key;
}
