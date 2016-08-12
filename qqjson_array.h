#ifndef QQJSON_ARRAY_H
#define QQJSON_ARRAY_H

#include <memory>
#include <qqjsonx.h>
#include <string>
#include <vector>
#include <stdint.h>

class QQJsonArray : public QQJsonX
{
public:
    QQJsonArray();
    virtual QQJsonX::QQJsonXType whichType() override;
    virtual const std::string  toString() override;
    virtual void addValue(std::shared_ptr<QQJsonX> ptr);
    std::shared_ptr<QQJsonX> operator[](const uint32_t index)
    {
        return _ArrayVector[index];
    }
private:
    std::string _ArrayName;
    std::vector<std::shared_ptr<QQJsonX> >  _ArrayVector;
};

#endif // QQJSON_ARRAY_H
