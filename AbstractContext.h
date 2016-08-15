#include <memory>
#include <stack>
#include "qqjsonx.h"

class QQJsonDocument;
class AbstractState;

class AbstractContext{
public:
    //定义使用的类型
    using ErrorCode_Type = int;
    using statePtr = std::shared_ptr<AbstractState>;
    using jsonPtr = std::shared_ptr<QQJsonX>;

    virtual ErrorCode_Type request(QQJsonDocument *doc) = 0; 

    statePtr getCurState(void){
    	return _curState;
    }

    void setCurState(statePtr state){
 	    _curState = state;
    }
    
    std::stack<jsonPtr> &getStack(void){
        return _stack;
    }
    
private:
    statePtr _curState;    
    std::stack<jsonPtr> _stack;
};
