#include "QQJsonContext.h"
#include "qqjsondocument.h"

int main(void)
{
    std::string str("{}");
    QQJsonContext context;
    QQJsonDocument doc(str);
    context.request(&doc);
    return 0; 
}
