#ifndef __QQJSONENCODER_H__
#define __QQJSONENCODER_H__
#include "QQJsonContext.h"
#include <memory>
#include <iostream>
#include <string>
#include "qqjsondocument.h"

class QQJsonEncoder{
public:
    using encoderPtr = std::shared_ptr<QQJsonEncoder>;
    using jsonPtr = QQJson::jsonPtr;
    static encoderPtr fromFile(std::string const &path);
    static encoderPtr fromString(std::string const &str);
    jsonPtr encode(void);
    //uncopyable
    QQJsonEncoder(const QQJsonEncoder &) = delete;
    QQJsonEncoder &operator=(const QQJsonEncoder &) = delete;

private:
    using contextPtr = std::shared_ptr<QQJsonContext>;
    using docPtr = std::shared_ptr<QQJsonDocument>;
    QQJsonEncoder(contextPtr context, docPtr doc) :
        _context(context), _doc(doc)
    {

    }

    contextPtr _context;
    docPtr _doc;
};

#endif
