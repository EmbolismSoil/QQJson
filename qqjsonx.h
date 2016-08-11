#ifndef QQJSONX_H
#define QQJSONX_H
#include <string>

class QQJsonX
{
public:
    typedef enum{
        QQJSON_ARRAY, QQJSON_OBJECT, QQJSON_VALUE,
        QQJSON_KEY,QQJSON_STRING, QQJSON_BOOLEN,
        QQJSON_NULL,QQJSON_NUMBER
    }QQJsonXType;

    virtual QQJsonXType whichType() = 0;
    virtual const std::string toString() = 0;
};

#endif // QQJSONX_H
