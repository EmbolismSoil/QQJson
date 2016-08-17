#include "qqjson_array.h"

QQJsonArray::QQJsonArray()
{

}

QQJsonX::QQJsonXType QQJsonArray::whichType()
{
    return QQJsonX::QQJSON_ARRAY;
}

const std::string QQJsonArray::toString()
{
    std::string str;
    str.append(_ArrayName);
    str.append("[ ");
    for (auto &iter : _ArrayVector){
         str.append((iter)->toString());
         str.append(1, ',');
    }
    str.pop_back();
    str.append("]");
    return str;
}

void QQJsonArray::addValue(std::shared_ptr<QQJsonX> ptr)
{
     _ArrayVector.push_back(ptr);
}

