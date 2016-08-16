#ifndef __QQJSONCONTEXT_H__
#define __QQJSONCONTEXT_H__

#include "AbstractContext.h"
#include "AbstractState.h"
#include "qqjsondocument.h"
#include <vector>
#include <map>

class QQJsonContext: public AbstractContext{
public:
    ErrorCode_Type request(QQJsonDocument *doc) override;
};
#endif
