#include "QQJsonEncoder.h"

int main(void)
{
    std::string str("{\"str\" : \"hello\"}");
    auto encoder = QQJsonEncoder::fromString(str);
    auto json = encoder->encode();
    std::cout << json->toString() << std::endl;
    return 0;
}
