#include "QQJsonEncoder.h"
#include "qqjson_array.h"

using QQJson::to;

int main(void)
{
    std::string str("test.json");
    auto encoder = QQJsonEncoder::fromFile(str);
    auto json = encoder->encode();
    auto obj = to<QQJsonObject>(json); 
    auto sonList = to<QQJsonArray>(obj["song_list"]);
    std::cout << sonList[2]->toString() << std::endl;
    return 0;
}
