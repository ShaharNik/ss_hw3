//
// Created by shaharnik on 09/12/2019.
//

#include "text_search.h"
#include <stdio.h>
#include <string.h>


int getlines(char s[])
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
    int i=0,j=0;
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
                //printf("\nSubstring found at index : %d\n",i);
                return 1;
            }
        }
        p1++;
    }
    return 0; // Substring Not Founded
}
void print_lines(char* str)
{
    char line[LINE];
    while(getlines(line))
    {
        if (substring(line, str))
            puts(line);
    }
}
int similar(char *s, char *t, int n)
{ //t is longer then s

    if (strlen(t) - strlen(s) > n)
        return 0;

    int i;
    while (*s != '\0')
    {
        while (*(t + i) != *s) // while different characters
        {
            i = 0;
            if (!(*(t+i)))
                return 0;
            i++;
        }
        n = n-i;
        s++;
        t += i + 1;
    }

    return (n==strlen(t));
}
int similar2(char *s, char *t, int n)
{ //t is longer then s
    int i = 0, j = 0;

    if (strlen(t) - strlen(s) > n)
        return 0;

    while (*(t + i) != '\0' || *(s + j) != '\0')
    {
        if ((*(s + j) == *(t + i))) // if same characters
        {
            j++;
        }
        if (i > j + n) // if the number of checks is bigger then possible and what we checked return 0;
        {
            return 0;
        }
        i++;
    }

    return 1;
}