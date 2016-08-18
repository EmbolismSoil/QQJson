#include "QQJsonEncoder.h"
#include "qqjson_object.h"
#include <fstream>
#include <sstream>

QQJsonEncoder::encoderPtr
    QQJsonEncoder::fromString(std::string const &str)
{
    auto doc = std::make_shared<QQJsonDocument>(str);
    auto context = std::make_shared<QQJsonContext>();    
    auto encoder = new QQJsonEncoder(context, doc);
    return std::shared_ptr<QQJsonEncoder>(encoder);
}

QQJsonEncoder::encoderPtr
    QQJsonEncoder::fromFile(std::string const &path)
{
    //这里会发生异常吗？
    std::ifstream t(path);  
    std::stringstream buffer;  
    buffer << t.rdbuf();
    std::string contents(buffer.str());  
    //std::cout << "raw input : " << std::endl << contents << std::endl;
    return QQJsonEncoder::fromString(contents);
}

QQJsonEncoder::jsonPtr QQJsonEncoder::encode(void)
{
    QQJson::StateCode_Type ret = QQJson::SUCCESS;
    for (;;){
        ret = _context->request(_doc.get());
        if (ret == QQJson::FORMAT_ERROR)
            return std::make_shared<QQJsonObject>();
        else if (ret == QQJson::FINISHED)
            return _context->getStack().top();
    }
}
