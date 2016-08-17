#ifndef QQJSONBOOLEN_H
#define QQJSONBOOLEN_H
#include "qqjsonx.h"

class QQJsonBoolen : public QQJsonX
{
public:
    QQJsonBoolen(std::string const &Boolen) : _Boolen(Boolen){  }
    virtual QQJsonX::QQJsonXType whichType() override;
    virtual const std::string  toString() override;
private:
    std::string _Boolen;
};

#endif // QQJSONBOOLEN_
