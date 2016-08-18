#include "QQJsonContext.h"
#include "ExpectCommaOrEndState.h"
#include "ExpectArrayValue.h"
#include "StartState.h"
#include "ExpectKeyState.h"
#include "ExpectValueState.h"
#include "ExpectColonState.h"
#include "ExpectKeyState.h"

QQJsonContext::QQJsonContext():_curState(std::make_shared<StartState>())
{

}

QQJson::StateCode_Type
   QQJsonContext::request(QQJsonDocument *doc)
{
    return getCurState()->handle(this, doc);
}

void QQJsonContext::setCurState(QQJson::State_Type state)
{

    switch(state){
        case QQJson::Expect_KeyState:{
            _curState = std::make_shared<ExpectKeyState>();
            break;
        }

        case QQJson::Expect_CommaOrEndState:{
            _curState = std::make_shared<ExpectCommaOrEndState>();
            break;
        }

        case QQJson::Expect_ColonState:{
            _curState = std::make_shared<ExpectColonState>();
            break;
        }

        case QQJson::Expect_ValueState:{
            _curState = std::make_shared<ExpectValueState>();
            break;
        }

        case QQJson::Expect_ArrayValueState:{
            _curState = std::make_shared<ExpectArrayValueState>();
            break;
        }

        case QQJson::Start_State:{
            _curState = std::make_shared<StartState>();
            break;
        }
    }

}
