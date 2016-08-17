#include "QQJsonEncoder.h"

int main(void)
{
    std::string str("test.json");
    auto encoder = QQJsonEncoder::fromFile(str);
    auto json = encoder->encode();
    std::cout << json->toString() << std::endl;
    return 0;
}
