#ifndef QQJSON_ARRAY_H
#define QQJSON_ARRAY_H

#include <map>
#include <memory>
#include <qqjsonx.h>
#include <string>
#include <vector>
#include <stdint.h>
#include "qqjson_null.h"

class QQJsonArray : public QQJsonX
{
public:
    QQJsonArray();
    virtual QQJsonX::QQJsonXType whichType() override;
    virtual const std::string  toString() override;
    virtual void addValue(std::shared_ptr<QQJsonX> ptr);
    std::shared_ptr<QQJsonX> const& operator[](const uint32_t index) const
    {
        return _ArrayVector[index];
    }

    std::shared_ptr<QQJsonX> &operator[](uint32_t const index)
    {
        return _ArrayVector[index];
    }

    void push_back(std::shared_ptr<QQJsonX> ptr)
    {
        _ArrayVector.push_back(ptr);
    }

private:
    std::string _ArrayName;
    std::vector<std::shared_ptr<QQJsonX> >  _ArrayVector;
};

#endif // QQJSON_ARRAY_H
