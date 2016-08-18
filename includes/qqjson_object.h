#ifndef QQJSON_OBJECT_H
#define QQJSON_OBJECT_H

#include <qqjsonx.h>
#include <map>
#include <string>
#include <memory>
#include "QQJsonCommon.h"

class QQJsonObject : public QQJsonX
{
private:
    std::map<std::string, std::shared_ptr<QQJsonX> > _ObjectMap;

public:
    QQJsonObject();

    virtual QQJsonX::QQJsonXType whichType() override;
    virtual  const std::string toString() override;
    virtual void addVaule(const std::string &key, std::shared_ptr<QQJsonX> value);
    //std::shared_ptr<QQJsonX> operator[](const std::string index);
    QQJson::jsonPtr& operator[](std::string const &index)
    {
        return _ObjectMap[index];
    }    
};

#endif // QQJSON_OBJECT_H
