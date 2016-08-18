#ifndef __ABSTRACTSTATE_H__
#define __ABSTRACTSTATE_H__

#include "qqjsondocument.h"
#include <memory>
#include "qqjson_object.h"
#include "QQJsonCommon.h"

class AbstractContext;
class QQJsonDocument;
class AbstractState{
public:
    virtual QQJson::StateCode_Type 
			handle(AbstractContext* context ,QQJsonDocument *doc) = 0;

    static QQJson::StateCode_Type doExpectValue(AbstractContext* context, QQJson::jsonPtr ptr);
    
    static QQJson::StateCode_Type doExpectArrayValue(AbstractContext*, QQJson::jsonPtr);
    AbstractState() = default;
    AbstractState(AbstractState const &) = delete;
    AbstractState const & operator=(AbstractState const &) = delete;
};

#endif
