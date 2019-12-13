//
// Created by Niknazar on 12/13/2019.
//

#include <stdio.h>
#include "String_functions.h"
#include <string.h>
#define LINE 256
#define WORD 30

int getline(char s[])
{
    int c, i;
    int j = 0;
    for (int i = 0; (c = getchar()) != EOF && c != '\n' ; ++i)
    {
        if (i < LINE)
            s[j++] = c;
    }
    s[j] = '\0';
    return i;
}
int getword(char w[])
{
    int c, i;
    int j = 0;
    for (int i = 0; (c = getchar()) != EOF && c != '\n' && c != '\t' && c != ' '; ++i)
    {
        if (i < WORD)
            w[j++] = c;
        else
            break;
    }
    w[j] = '\0';
    return i;
}
int substring(char *str1, char *str2)
{
    // Check if str2 is a substring of str

    if (!*str2) // empty string
        return 1;

    char *p1, *p2, *p3;
    int i=0,j=0,flag=0;
    p1 = str1;
    p2 = str2;

    for(i = 0; i < strlen(str1); i++)
    {
        if(*p1 == *p2)
        {
            p3 = p1;
            for(j = 0;j < strlen(str2);j++)
            {
                if(*p3 == *p2)
                {
                    p3++;p2++;
                }
                else
                    break;
            }
            p2 = str2; // return to index 0 of str2
            if(j == strlen(str2))
            {
                flag = 1;
                //printf("\nSubstring found at index : %d\n",i);
                return 1;
            }
        }
        p1++;
    }
    return 0; // Substring Not Founded
}

