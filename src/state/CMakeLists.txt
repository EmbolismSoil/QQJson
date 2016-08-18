SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET (SRC_LIST AbstractState.cpp
ExpectArrayValue.cpp
ExpectColonState.cpp
ExpectCommaOrEndState.cpp
ExpectKeyState.cpp
ExpectValueState.cpp
QQJsonEncoder.cpp
StartState.cpp
QQJsonContext.cpp
)

INCLUDE_DIRECTORIES(../../includes)
ADD_LIBRARY(qqjson ${SRC_LIST})
TARGET_LINK_LIBRARIES(qqjson json)
