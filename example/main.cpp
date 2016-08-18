#include "QQJsonEncoder.h"
#include "qqjson_array.h"
#include "qqjsonstring.h"

using QQJson::ptr2obj;

int main(void)
{
    std::string str("test.json");
    auto encoder = QQJsonEncoder::fromFile(str);
    auto json = encoder->encode();
    auto obj = ptr2obj<QQJsonObject>(json); 
    auto sonList = ptr2obj<QQJsonArray>(obj["song_list"]); 
    std::cout << sonList[2]->toString() << std::endl;
    QQJsonArray array;
    auto object = std::make_shared<QQJsonObject>();    
    (*object)["key"] = std::make_shared<QQJsonString>("value");
    array.push_back(std::make_shared<QQJsonString>("hello world"));
    array.push_back(object);
    std::cout << array.toString() << std::endl;
    return 0;
}
