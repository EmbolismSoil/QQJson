#ifndef QQJSONSTRING_H
#define QQJSONSTRING_H
#include <qqjsonx.h>

class QQJsonString : public QQJsonX
{
public:
    QQJsonString(const std::string &str):_String(str){}
    virtual QQJsonXType whichType() override{
        return QQJsonX::QQJSON_STRING;
    }
    virtual const std::string toString() override{
        return "\"" + _String + "\"";
    }
private:
    std::string _String;
};

#endif // QQJSONSTRING_H
