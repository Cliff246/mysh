#include <stdio.h>
#include "language.h"
#include <curses.h>
#include <wchar.h>
#include <locale.h>

int main()
{
    //WINDOW *initscr();
    wchar_t **data;
	const wchar_t *test= L"the little duck walks ";
	//wprintf(L"%ls", test);
    split_wtokens(&data, L"a ", L"hello a world");

}
