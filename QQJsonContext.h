#ifndef __QQJSONCONTEXT_H__
#define __QQJSONCONTEXT_H__

#include "AbstractContext.h"
#include "AbstractState.h"
#include "AbstractState.h"
#include "qqjsondocument.h"
#include <vector>
#include <map>

class QQJsonContext: public AbstractContext{
public:
    AbstractState::ErrorCode_Type request(QQJsonDocument *doc) override;
    void setCurState(AbstractState::State_Type state) override;

    std::shared_ptr<AbstractState> getCurState(void)
    {
        return _curState;
    }

private:
    std::shared_ptr<AbstractState> _curState;
};
#endif
