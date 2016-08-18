#include "qqjson_object.h"
#include "QQJsonCommon.h"

QQJsonObject::QQJsonObject()
{

}

QQJsonX::QQJsonXType QQJsonObject::whichType()
{
    return    QQJsonX::QQJSON_OBJECT;
}

const std::string QQJsonObject::toString()
{
      std::string str;
      //str.append(_ObjetName);
      str.append("{");
      for (auto &iter : _ObjectMap){

         str.append("\"" + (iter).first + "\"");
         str.append(1, ':');
         auto ptr = (iter).second;
         str.append(ptr->toString());
         str.append(1, ',');
      }
      str.pop_back();
      str.append("}");
      return str;
}

void QQJsonObject::addVaule(const std::string &key, std::shared_ptr<QQJsonX> value)
{
    _ObjectMap[key] = value;
}


