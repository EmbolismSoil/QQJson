#ifndef QQJSON_ARRAY_H
#define QQJSON_ARRAY_H

#include <memory>
#include <qqjsonx.h>
#include <string>
#include <vector>

class QQJsonArray : public QQJsonX
{
public:
    QQJsonArray();
    virtual QQJsonX::QQJsonXType whichType() override;
    virtual const std::string  toString() override;
    virtual void addValue(std::shared_ptr<QQJsonX> ptr);
private:
    std::string _ArrayName;
    std::vector<std::shared_ptr<QQJsonX> >  _ArrayVector;
};

#endif // QQJSON_ARRAY_H
