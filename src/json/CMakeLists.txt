SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET (SRC_LIST qqjson_array.cpp
qqjson_boolen.cpp
qqjson.cpp
qqjsondocument.cpp
qqjsonkey.cpp
qqjson_null.cpp
qqjson_number.cpp
qqjson_object.cpp
qqjsonstring.cpp
qqjsonx.cpp
)

INCLUDE_DIRECTORIES(../../includes)
ADD_LIBRARY(json ${SRC_LIST})
