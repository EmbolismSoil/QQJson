#ifndef __QQJSONCOMMON_H__
#define __QQJSONCOMMON_H__
#include <memory>
#include "qqjsonx.h"

namespace QQJson{
    typedef enum{FORMAT_ERROR, FINISHED, 
                    UNKONE_ERROR, SUCCESS} StateCode_Type;

    typedef enum{ Expect_KeyState, Expect_ValueState, 
                  Expect_ArrayValueState,Expect_CommaOrEndState, 
                  Expect_ColonState, Start_State,
                 }State_Type;    
    
    using jsonPtr = std::shared_ptr<QQJsonX>;

    template<class T, class Raw>
        T& ptr2obj(Raw ptr){
            return *(std::dynamic_pointer_cast<T>(ptr));
        }

}
#endif
