#include "QQJsonContext.h"
#include "ExpectCommaOrEndState.h"
#include "ExpectArrayValue.h"
#include "StartState.h"
#include "ExpectKeyState.cpp"
#include "ExpectColonState.h"
#include "ExpectValueState.h"


AbstractState::ErrorCode_Type 
   QQJsonContext::request(QQJsonDocument *doc)
{
    return getCurState()->handle(this, doc);
}

void QQJsonContext::setCurState(AbstractState::State_Type state)
{
    switch(state){
        case AbstractState::Expect_KeyState:{
            _curState = std::make_shared<ExpectKeyState>();
            break;
        }

        case AbstractState::Expect_CommaOrEndState:{
            _curState = std::make_shared<ExpectCommaOrEndState>();
            break;
        }

        case AbstractState::Expect_ColonState:{
            _curState = std::make_shared<ExpectColonState>();
            break;
        }

        case AbstractState::Expect_ValueState:{
            _curState = std::make_shared<ExpectValueState>();
            break;
        }

        case AbstractState::Expect_ArrayValueState:{
            _curState = std::make_shared<ExpectArrayValueState>();
            break;
        }

        case AbstractState::Start_State:{
            _curState = std::make_shared<StartState>();
            break;
        }
    }
}
