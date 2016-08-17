#ifndef QQJSONDOCUMENT_H
#define QQJSONDOCUMENT_H

#include <string>
class QQJsonDocument
{
public:
    typedef enum{
        /*TOKEN_DOC_END, */TOKEN_BEGIN_OBECT,
        TOKEN_END_OBJECT, TOKEN_BEGIN_ARRAY,
        TOKEN_END_ARRAY, TOKEN_COLON, TOKEN_COMMA,
        TOKEN_STRING, TOKEN_BOOLEN, TOKEN_NUMER,
        TOKEN_NULL, TOKEN_ERROR,
    }Token;

    QQJsonDocument(const std::string &);
    QQJsonDocument(std::string &&);
    Token peekNextToken();
    //Token nextToken();
    std::string getRawDoc(){return _Document;}
    void popToken();
    std::string readBoolen();
    std::string readString();
    std::string readNull();
    std::string readNumber();
    std::string readComma();
    std::string readColon();
private:
   std::string _Document;
   std::string::iterator _WorkerIter;
   std::string::iterator _EndDocumentIter;
   std::string::iterator _BeginDocumentIter;
public:
   std::string readAToken();
};

#endif // QQJSONDOCUMENT_H
