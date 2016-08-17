#ifndef QQJSONNUMBER_H
#define QQJSONNUMBER_H
#include "qqjsonx.h"

class QQJsonNumber : public QQJsonX
{
public:
    QQJsonNumber();
    QQJsonNumber(std::string const&  str) : _number(str){}
    virtual QQJsonX::QQJsonXType whichType() override;
    virtual const std::string  toString() override;
private:
    std::string _number;
};

#endif // QQJSONNUMBER_H
