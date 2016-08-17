#ifndef QQJSON_OBJECT_H
#define QQJSON_OBJECT_H

#include <qqjsonx.h>
#include <map>
#include <string>
#include <memory>

class QQJsonObject : public QQJsonX
{
private:
    std::map<std::string, std::shared_ptr<QQJsonX> > _ObjectMap;

public:
    QQJsonObject();

    virtual QQJsonX::QQJsonXType whichType() override;
    virtual  const std::string toString() override;
    virtual void addVaule(const std::string &key, std::shared_ptr<QQJsonX> value);
    std::shared_ptr<QQJsonX> operator[](const std::string index)
    {
        return _ObjectMap[index];
    }

//    std::string _ObjetName;
};

#endif // QQJSON_OBJECT_H