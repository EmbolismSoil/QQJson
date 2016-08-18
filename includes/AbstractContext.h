#ifndef __ABSTRACTCONTEXT_H__
#define __ABSTRACTCONTEXT_H__

#include <memory>
#include <stack>
#include "qqjsonx.h"
#include "AbstractState.h"

class QQJsonDocument;
class AbstractContext{
public:
    virtual QQJson::StateCode_Type request(QQJsonDocument *doc) = 0; 
    virtual void setCurState(QQJson::State_Type state) = 0;
    std::stack<QQJson::jsonPtr> &getStack(void){
        return _stack;
    }
    
    AbstractContext() = default;
    AbstractContext(AbstractContext const &) = delete;
    AbstractContext const &operator = (AbstractContext const &) = delete;
private:
    std::stack<QQJson::jsonPtr> _stack;
};
#endif
