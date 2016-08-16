#ifndef __ABSTRACTSTATE_H__
#define __ABSTRACTSTATE_H__

#include "qqjsondocument.h"
#include <memory>
#include "qqjson_object.h"

class AbstractContext;
class QQJsonDocument;
class AbstractState{
public:
    typedef enum{FORMAT_ERROR, FINISHED, UNKONE_ERROR, SUCCESS} ErrorCode_Type;
    typedef enum{
                    Expect_KeyState, Expect_ValueState, Expect_ArrayValueState,
                    Expect_CommaOrEndState, Expect_ColonState, Start_State,
                }State_Type;    
    
    using statePtr = std::shared_ptr<AbstractState>;
    using jsonPtr = std::shared_ptr<QQJsonX>;

    using StateCode_Type = ErrorCode_Type;
    typedef enum{Start, Expect_Key, Expect_Value,
                    Expect_Colon, Expect_ArrayValue,
                   Expect_CommaOrEnd, Stack_Top_Check}STATE;

    virtual StateCode_Type 
			handle(AbstractContext* context ,QQJsonDocument *doc) = 0;

    static StateCode_Type doExpectValue(AbstractContext* context, jsonPtr ptr);
    
    static StateCode_Type doExpectArrayValue(AbstractContext*, jsonPtr);
};

#endif
