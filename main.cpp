#include "qqjsondocument.h"
#include <vector>
#include <string>
#include <iostream>

#include <stack>
#include <qqjsonx.h>
#include <memory>
#include <qqjsonkey.h>
#include <qqjson_object.h>
#include <qqjsonstring.h>
#include <qqjson_array.h>
#include <qqjson_null.h>
#include <qqjson_number.h>
#include <qqjson_boolen.h>
#include <fstream>
#include <sstream>


typedef enum{Start, Expect_Key, Expect_Value,
                    Expect_Colon, Expect_ArrayValue,
                   Expect_CommaOrEnd, Stack_Top_Check}STATE;

std::stack<std::shared_ptr<QQJsonX> > Stack;

template <class T>
std::shared_ptr<T> jsonConcrete_cast(std::shared_ptr<QQJsonX> Obj){
    return std::dynamic_pointer_cast<T>(Obj);
}

int doExpectValue(std::shared_ptr<QQJsonX> ptr)
{
    auto Key = Stack.top();
    Stack.pop();
    if (Key->whichType() != QQJsonX::QQJSON_KEY)
        return -1;
    auto Object = Stack.top();
    Stack.pop();
    if (Object->whichType() != QQJsonX::QQJSON_OBJECT)
        return -1;

    auto Obj = jsonConcrete_cast<QQJsonObject>(Object);

    Obj->addVaule(Key->toString(), ptr);
    Stack.push(Object);
    return 0;
}

template<class T>
int doExpectArrayValue(std::shared_ptr<T> ptr)
{
    auto array = Stack.top();
    if (array->whichType() != QQJsonX::QQJSON_ARRAY)
            return -1;
    auto jsonArray = jsonConcrete_cast<QQJsonArray>(array);
    jsonArray->addValue(ptr);
    return 0;
}

int main(int argc, char *argv[])
{
    //QQJsonDocument doc(std::string("{\"bool\":true, \"Object\" : {\"bool\": false, \"array\" : [1]}}"));
    if (argc != 2)
        return 0;
    std::ifstream t(argv[1]);
    std::stringstream buffer;
    buffer << t.rdbuf();
    std::string contents(buffer.str());
    QQJsonDocument doc(contents);
    std::shared_ptr<QQJsonX> ret;
//    std::vector<QQJsonDocument::Token> tokens;

    QQJsonDocument::Token Token;    
    STATE state = Start;
    for (;;){
        Token = doc.peekNextToken();
        switch(Token){
            case QQJsonDocument::TOKEN_BEGIN_OBECT:
            {
                doc.readAToken();
               if (state == Start){
                   auto Key = std::make_shared<QQJsonKey>("root");
                   Stack.push(Key);
                   auto Obj = std::make_shared<QQJsonObject>();
                   Stack.push(Obj);
                   state = Expect_Key;
               }else if (state == Expect_ArrayValue){
                   auto Obj = std::make_shared<QQJsonObject>();
                   Stack.push(Obj);
                   state = Expect_Key;
               }else if (state == Expect_Value){
                   auto Obj = std::make_shared<QQJsonObject>();
                   Stack.push(Obj);
                   state = Expect_Key;
               }else return -1;
               continue;
            }
            case QQJsonDocument::TOKEN_STRING:
            {
                std::string str(doc.readString());
                if (state == Expect_Key){
                    auto jsonStr = std::make_shared<QQJsonKey>(str);
                    Stack.push(jsonStr);
                    state = Expect_Colon;
                }else if (state == Expect_Value){
                    auto Key = Stack.top();
                    Stack.pop();
                    if (Key->whichType() != QQJsonX::QQJSON_KEY)
                        return -1;
                    auto Object = Stack.top();
                    Stack.pop();
                    if (Object->whichType() != QQJsonX::QQJSON_OBJECT)
                        return -1;
                    //auto Obj = static_cast<std::shared_ptr<QQJsonObject>>(Object);
                    auto Obj =  jsonConcrete_cast<QQJsonObject>(Object);
                    auto jsonStr = std::make_shared<QQJsonString>(str);
                    Obj->addVaule(Key->toString(), jsonStr);
                    Stack.push(Object);
                    state = Expect_CommaOrEnd;
                }else if (state == Expect_ArrayValue){
                    auto array = Stack.top();
                    if (array->whichType() != QQJsonX::QQJSON_ARRAY)
                            return -1;
                    auto jsonArray = jsonConcrete_cast<QQJsonArray>(array);
                    auto jsonStr = std::make_shared<QQJsonString>(str);
                    jsonArray->addValue(jsonStr);
                    state = Expect_ArrayValue;
                }else return -1;
                continue;
            }
            case QQJsonDocument::TOKEN_COLON:
            {
                doc.readAToken();
                if (state == Expect_Colon)
                    state = Expect_Value;
                else return -1;
                continue;
            }
            case QQJsonDocument::TOKEN_NULL:
            {
                doc.readNull();
                if (state == Expect_Value){
                   if(doExpectValue(std::make_shared<QQJsonNull>()) < 0)
                        return -1;
                   state =  Expect_CommaOrEnd;
                }else if (state == Expect_ArrayValue){
                    if (doExpectArrayValue(std::make_shared<QQJsonNull>()) < 0)
                            return -1;
                      state = Expect_ArrayValue;
                }else return -1;
                continue;
            }
            case QQJsonDocument::TOKEN_NUMER :
            {
                auto number = doc.readNumber();
                if (state == Expect_ArrayValue){
                    if (doExpectArrayValue(std::make_shared<QQJsonNumber>(number)) < 0)
                        return -1;
                    state = Expect_ArrayValue;
                }else if (state == Expect_Value){
                    if (doExpectValue(std::make_shared<QQJsonNumber>(number)) < 0)
                            return -1;
                    state = Expect_CommaOrEnd;
                }else return -1;
                continue;
            }

            case QQJsonDocument::TOKEN_BOOLEN:
            {
                auto Boolen = doc.readBoolen();
                if (state == Expect_ArrayValue){
                    if (doExpectValue(std::make_shared<QQJsonBoolen>(Boolen)) < 0)
                        return -1;
                      state = Expect_ArrayValue;
                }else if (state == Expect_Value){
                    if (doExpectValue(std::make_shared<QQJsonBoolen>(Boolen)) < 0)
                        return -1;
                    state = Expect_CommaOrEnd;
                }else return -1;
                continue;
            }

           case QQJsonDocument::TOKEN_COMMA:
            {
                doc.readAToken();
                if (state == Expect_CommaOrEnd){
                    state = Expect_Key;
                }else if (state == Expect_ArrayValue){
                    state = Expect_ArrayValue;
                }else return -1;
                continue;
            }

            case QQJsonDocument::TOKEN_END_ARRAY:
            case QQJsonDocument::TOKEN_END_OBJECT:
            {
                doc.readAToken();
                if (state == Expect_CommaOrEnd || state == Expect_ArrayValue){
                    auto obj = Stack.top();
                    if (obj->whichType() !=QQJsonX::QQJSON_OBJECT && obj->whichType() !=QQJsonX::QQJSON_ARRAY)
                        return -1;
                    Stack.pop();
                    if (Stack.size() == 1){
                        ret = obj;
                        goto FINISHED;
                    }
                    auto ptr = Stack.top();
                    if (ptr->whichType() == QQJsonX::QQJSON_KEY){
                        doExpectValue(obj);
                        state = Expect_CommaOrEnd;
                    }else if (ptr->whichType() ==  QQJsonX::QQJSON_ARRAY){
                        doExpectArrayValue(obj);
                        state = Expect_ArrayValue;
                    }else return -1;
                }else return -1;
                continue;
            }

            case QQJsonDocument::TOKEN_BEGIN_ARRAY:
            {
               doc.readAToken();
                if (state == Expect_Value){
                    Stack.push(std::make_shared<QQJsonArray>());
                    //if (doExpectValue() < 0)
                       // return -1;
                    state = Expect_ArrayValue;
                }else if (state == Expect_ArrayValue){
                    if (doExpectArrayValue(std::make_shared<QQJsonArray>()) < 0)
                        return -1;
                    state = Expect_ArrayValue;
                }else return -1;
                continue;
            }

            case QQJsonDocument::TOKEN_ERROR:
            {
                return -1;
            }
        }
    }
FINISHED:
    auto obj =  std::dynamic_pointer_cast<QQJsonObject>(ret);
    std::cout << obj->toString() << std::endl;
    return 0;
}
