#ifndef __ABSTRACTSTATE_H__
#define __ABSTRACTSTATE_H__

#include "qqjsondocument.h"
#include "AbstractContext.h"

class QQJsonDocument;

class AbstractState{
public:
    using StateCode_Type = AbstractContext::ErrorCode_Type;
    typedef enum{Start, Expect_Key, Expect_Value,
                    Expect_Colon, Expect_ArrayValue,
                   Expect_CommaOrEnd, Stack_Top_Check}STATE;

    virtual StateCode_Type 
			handle(AbstractContext* context ,QQJsonDocument *doc) = 0;
};

#endif
