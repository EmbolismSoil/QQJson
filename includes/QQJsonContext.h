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
    QQJson::StateCode_Type request(QQJsonDocument *doc) override;
    QQJsonContext();
    void setCurState(QQJson::State_Type state) override;

    std::shared_ptr<AbstractState> getCurState(void)
    {
        return _curState;
    }

private:
    std::shared_ptr<AbstractState> _curState;
};
#endif
