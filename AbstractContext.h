#ifndef __ABSTRACTCONTEXT_H__
#define __ABSTRACTCONTEXT_H__

#include <memory>
#include <stack>
#include "qqjsonx.h"
#include "AbstractState.h"

class QQJsonDocument;
class AbstractContext{
public:
    //定义使用的类型
//    using ErrorCode_Type = int;

    virtual AbstractState::ErrorCode_Type request(QQJsonDocument *doc) = 0; 

    virtual void setCurState(AbstractState::State_Type state) = 0;
    
    std::stack<AbstractState::jsonPtr> &getStack(void){
        return _stack;
    }
    
private:
    std::stack<AbstractState::jsonPtr> _stack;
};
#endif
