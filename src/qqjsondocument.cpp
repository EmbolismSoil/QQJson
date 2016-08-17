#include "qqjsondocument.h"
#include <string>

QQJsonDocument::QQJsonDocument(const std::string &str):
    _Document(str),
    _WorkerIter(_Document.begin()),
    _EndDocumentIter(_Document.end()),
    _BeginDocumentIter(_Document.begin())
{

}

QQJsonDocument::QQJsonDocument(std::string &&str):
    _Document(std::move(str)),
    _WorkerIter(_Document.begin()),
    _EndDocumentIter(_Document.end()),
    _BeginDocumentIter(_Document.begin())
{

}

QQJsonDocument::Token QQJsonDocument::peekNextToken()
{
    if (_WorkerIter == _EndDocumentIter)
        return TOKEN_ERROR;

    for(; _WorkerIter != _EndDocumentIter; ++_WorkerIter)
        if(!isspace(*_WorkerIter))
            break;

    if (_WorkerIter == _EndDocumentIter)
        return TOKEN_ERROR;

    if (*_WorkerIter == '{')
        return TOKEN_BEGIN_OBECT;
    else if (*_WorkerIter == ':')
        return TOKEN_COLON;
    else if (*_WorkerIter == ',')
        return TOKEN_COMMA;
    else if (*_WorkerIter == '[')
        return TOKEN_BEGIN_ARRAY;
    else if (*_WorkerIter == 't' || *_WorkerIter == 'f')
        return TOKEN_BOOLEN;
    else if (*_WorkerIter == '"')
        return TOKEN_STRING;
    else if (*_WorkerIter >= '0' && *_WorkerIter <= '9')
        return TOKEN_NUMER;
    else if (*_WorkerIter == 'n')
        return TOKEN_NULL;
    else if (*_WorkerIter == '}')
        return TOKEN_END_OBJECT;
    else if (*_WorkerIter == ']')
        return TOKEN_END_ARRAY;
    else
        return TOKEN_ERROR;
}

std::string QQJsonDocument::readBoolen()
{
    if (*_WorkerIter == 't'){
        std::string True("true");
        std::string tmp(_WorkerIter, _WorkerIter + True.length());
        _WorkerIter += True.length();
        return tmp;
    }

    std::string False("false");
    std::string tmp(_WorkerIter, _WorkerIter + False.length());
    _WorkerIter += False.length();
    return tmp;
}

std::string QQJsonDocument::readString()
{
    std::string::iterator tmpIter = _WorkerIter+1;
    if (*tmpIter != '"'){
        ++tmpIter;
    }else{
        _WorkerIter = tmpIter + 1;
        return std::string("");
    }
    for ( ; *tmpIter != '"' || *(tmpIter - 1) == '\\' ; ++tmpIter);

    std::string str(_WorkerIter+1, tmpIter);
    _WorkerIter = tmpIter + 1;

    return str;
}

std::string QQJsonDocument::readNull()
{
    std::string Null("null");
    std::string str(_WorkerIter, _WorkerIter + Null.length());
    _WorkerIter += Null.length();
    return str;
}

std::string QQJsonDocument::readNumber()
{
    std::string::iterator tmpIter = _WorkerIter;
    for (; tmpIter != _Document.end() && (*tmpIter >= '0' && *tmpIter <= '9'); ++tmpIter);
    std::string number(_WorkerIter, tmpIter);
    _WorkerIter += number.length();
    return number;
}

std::string QQJsonDocument::readComma()
{
    return readAToken();
}

std::string QQJsonDocument::readColon()
{
    return readAToken();
}

std::string QQJsonDocument::readAToken()
{
    std::string str(_WorkerIter, _WorkerIter+1);
    ++_WorkerIter;
    return str;
}
