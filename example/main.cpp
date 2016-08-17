#include "QQJsonEncoder.h"

int main(void)
{
    std::string str("test.json");
    auto encoder = QQJsonEncoder::fromFile(str);
    std::cout << "raw  : " << encoder->getDoc()->getRawDoc() << std::endl;
    auto json = encoder->encode();
    std::cout << json->toString() << std::endl;
    return 0;
}
