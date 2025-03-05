#include <stdio.h>

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <wchar.h>
#include "language.h"




int split_wtokens(wchar_t ***buffer, wchar_t *delim, wchar_t *inp)
{
    if(buffer == NULL)
        return -1;
    int length = 1;
	bool last_was_delim = false;
    for(wchar_t *scroll = inp; *scroll != L'\0'; scroll++)
    {
		bool is_delim = false;
        for(wchar_t *delim_scroll = delim; *delim_scroll != L'\0'; delim_scroll++)
        {

            if(*scroll == *delim_scroll && last_was_delim == false)
			{
                length++;
				is_delim = true;
				break;
			}

        }
		last_was_delim = is_delim;
    }

    wchar_t **list = (wchar_t **)malloc(sizeof(wchar_t *) * length);;
	//printf("%d\n", length);
	if(list == NULL)
        return -1;
    int current_size = 0;
    int current_count = 0;
    size_t inp_size = wcslen(inp);
    wchar_t *current_wstr = (wchar_t *)malloc(sizeof(wchar_t) * (inp_size + 1) );
    memset(current_wstr, 0, (sizeof(wchar_t) * (inp_size + 1)));
	//printf("test2 %d\n", inp_size);
	last_was_delim = false;
    for(size_t i = 0; i < inp_size; i++)
    {
		//printf("%d", i);

		//wprintf(L"%lc\n", inp[i]);
        wchar_t *current_ptr = inp + i;
        bool is_delim = false;
        for(wchar_t *delim_scroll = delim; *delim_scroll != L'\0'; delim_scroll++)
        {
			wprintf(L"%ls\n", current_ptr);

            if(inp[i] == *delim_scroll && last_was_delim == false)
			{
               	is_delim = true;
				break;
			}
        }

        if(is_delim == true)
        {
            int bytes = sizeof(wchar_t) * (current_size + 1);
            wchar_t *new_split = (wchar_t *)malloc(bytes);
            memset(new_split, 0, bytes);
            memcpy(new_split, current_wstr, bytes);
			wprintf(L"%ls\n", new_split);
            list[current_count++] = new_split;
            memset(current_wstr, 0, length * sizeof(wchar_t));
			current_size = 0;
        }
        else
        {
        	current_wstr[current_size++] = inp[i];
        }
		last_was_delim = is_delim;
    }
	int bytes = sizeof(wchar_t) * (current_size + 1);
    wchar_t *new_split = (wchar_t *)malloc(bytes);
    memset(new_split, 0, bytes);
    memcpy(new_split, current_wstr, bytes);
    list[current_count++] = new_split;

	free(current_wstr);
	*buffer = list;
	for(int c = 0; c < length; c++)
	{
		wprintf(L"%d %ls\n",c, list[c]);
	}

	return length;
}
