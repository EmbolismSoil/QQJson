#include "qqjsondocument.h"
#include "AbstractContext.h"

class QQJsonDocument;

class AbstractState{
public:
typedef enum{Start, Expect_Key, Expect_Value,
                    Expect_Colon, Expect_ArrayValue,
                   Expect_CommaOrEnd, Stack_Top_Check}STATE;

virtual AbstractContext::ErrorCode_Type 
			handle(AbstractContext* context ,QQJsonDocument *doc) = 0;
};
