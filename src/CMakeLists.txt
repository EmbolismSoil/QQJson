SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(
SRC_LIST 
AbstractState.cpp
ExpectArrayValue.cpp
ExpectColonState.cpp
ExpectCommaOrEndState.cpp
ExpectKeyState.cpp
ExpectValueState.cpp
qqjson_array.cpp
qqjson_boolen.cpp
QQJsonContext.cpp
qqjson.cpp
qqjsondocument.cpp
QQJsonEncoder.cpp
qqjsonkey.cpp
qqjson_null.cpp
qqjson_number.cpp
qqjson_object.cpp
qqjsonstring.cpp
qqjsonx.cpp
StartState.cpp
)
INCLUDE_DIRECTORIES(../includes)
ADD_LIBRARY(qqjson SHARED ${SRC_LIST})
