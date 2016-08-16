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
#include "QQJsonContext.h"

int main(void)
{
    std::string str("{}");
    QQJsonContext context;
    QQJsonDocument doc(str);
    context.request(&doc);
    return 0; 
}
