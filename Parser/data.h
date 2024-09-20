#pragma once
#ifndef extern_
#    define extern_ extern
#endif   // !extern_
#include <stdio.h>


// Make these variables global.
extern_ int   Line;
extern_ int   Putback;
extern_ FILE *Infile;
extern_ struct token Token;
