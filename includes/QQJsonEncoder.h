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
    using contextPtr = std::shared_ptr<QQJsonContext>;
    using docPtr = std::shared_ptr<QQJsonDocument>;
    
    static encoderPtr fromFile(std::string const &path);
    static encoderPtr fromString(std::string const &str);
    jsonPtr encode(void);
    //uncopyable
    QQJsonEncoder(const QQJsonEncoder &) = delete;
    QQJsonEncoder &operator=(const QQJsonEncoder &) = delete;
    contextPtr getContext(void){return _context;}
    docPtr getDoc(void){return _doc;}

private:
    QQJsonEncoder(contextPtr context, docPtr doc) :
        _context(context), _doc(doc)
    {

    }

    contextPtr _context;
    docPtr _doc;
};

#endif
