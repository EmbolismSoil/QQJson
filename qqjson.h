#ifndef QQJSON_H
#define QQJSON_H

#include <string>
#include <map>
#include <vector>
#include "qqjsondocument.h"
#include <stack>
#include <qqjsonx.h>
#include <memory>

class QQJson
{
public:
    typedef  std::map<std::string ,std::string> Object;
    typedef  std::vector<std::string> Array;

    QQJson(const std::string &str);
    QQJson(const QQJson &) = delete;
    void Parse();
private:
    QQJsonDocument _Document;
    std::stack<std::shared_ptr<QQJsonX> > _ParseStack;
};

#endif // QQJSON_H
