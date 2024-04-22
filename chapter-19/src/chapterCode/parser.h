
#ifndef _parser_h
#define _parser_h

#include "exp.h"
#include "tokenscanner.h"
#include "error.h"

Expression * parseExp(TokenScanner &scanner);

Expression *readE(TokenScanner &scanner, int prec);

Expression *readT(TokenScanner &scanner);

int precedence(std::string);


#endif // _parser_h
