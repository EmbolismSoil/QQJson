#ifndef QQJSONNULL_H
#define QQJSONNULL_H
#include "qqjsonx.h"

class QQJsonNull : public QQJsonX
{
public:
    QQJsonNull();
    virtual QQJsonX::QQJsonXType whichType() override;
    virtual const std::string  toString() override;
};

#endif // QQJSONNULL_H
