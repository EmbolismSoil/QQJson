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

bool isObject(const std::string& str )
{
    if (*(str.begin()) != '{')
        return false;

    std::stack<char> S;
    for (auto &c : str){
        if (c == '}') {
            while(!S.empty()){
                if(S.top() == '{')
                    break;
                S.pop();
            }
            if (S.empty()){
                return false;
            }else{
                S.pop();
                continue;
            }
        }else{
            S.push(c);
        }
    }

    if (S.empty())
        return true;
    else return false;
}

bool isArray(const std::string& str )
{
    if (*(str.begin()) != '[')
        return false;

    std::stack<char> S;
    for (auto &c : str){
        if (c == ']') {
            while(!S.empty()){
                if(S.top() == '[')
                    break;
                S.pop();
            }
            if (S.empty()){
                return false;
            }else{
                S.pop();
                continue;
            }
        }else{
            S.push(c);
        }
    }

    if (S.empty())
        return true;
    else return false;
}


typedef enum{Start, Expect_Key, Expect_Value,
                    Expect_Colon, Expect_ArrayValue,
                   Expect_CommaOrEnd, Stack_Top_Check}STATE;

int main(void)
{
    QQJsonDocument doc(std::string("\"bool\":true \"NULL\": null"));
//    std::vector<QQJsonDocument::Token> tokens;

    QQJsonDocument::Token Token;
    STATE state = Start;
    std::stack<std::shared_ptr<QQJsonX> > Stack;
    for (;;){
        Token = doc.peekNextToken();
        switch(Token){
        case QQJsonDocument::TOKEN_BEGIN_OBECT:
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
            }
        }else return -1;
            continue;
        case QQJsonDocument::TOKEN_STRING:
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
                auto Obj = static_cast<std::shared_ptr<QQJsonObject>>(Object);
                auto jsonStr = std::make_shared<QQJsonString>(str);
                Obj->addVaule(Key->toString(), jsonStr);
                Stack.push(Obj);
                state = Expect_CommaOrEnd;
            }else if (state == Expect_ArrayValue){
                auto array = Stack.top();
                if (array->whichType() != QQJsonX::QQJSON_ARRAY)
                        return -1;
                auto jsonArray = static_cast<std::shared_ptr<QQJsonArray>>(array);
                auto jsonStr = std::make_shared<QQJsonString>(str);
                jsonArray->addValue(jsonStr);
                state = Expect_ArrayValue;
            }else return -1;
            continue;
        case QQJsonDocument::TOKEN_COLON:

    }

}
