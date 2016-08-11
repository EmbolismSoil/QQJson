#ifndef QQJSONKEY_H
#define QQJSONKEY_H
#include <qqjsonx.h>

class QQJsonKey : public QQJsonX
{
public:
    QQJsonKey(const std::string key);
    virtual QQJsonXType whichType() override;
    virtual const std::string toString() override;
    const std::string &getKey(){return _key;}
private:
    std::string _key;
};

#endif // QQJSONKEY_H
