#ifndef __LANGUAGE__
#define __LANGUAGE__

#include "commons.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

enum token_class
{
    NONE,    
};

struct token
{
    enum token_class type;
   
    wchar_t *wtok;
    
};


int split_wtokens(wchar_t ***buffer, wchar_t *delim, wchar_t *inp);



#endif 
