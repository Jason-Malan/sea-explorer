/*
Write  a  function  htoi(s),  which  converts  a  string  of  hexadecimal  digits  
(including  an  optional  0x  or  0X)  into  its  equivalent  integer  value.  The  allowable  digits  are  0 
through 9, a through f, and A through F. 
*/

#include <stdio.h>

int htoi(char s[10]);

int main() 
{
    int result = htoi("10A");

    printf("%d, hi", result);

    return 0;
}

int htoi(char s[10])
{
    int result = 0, i = 0;

    int c;
    while(i < 10 && (c = s[i]) != '\0') 
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            result = result * 16 + (s[i] - '0');
            i++;
            continue;
        } 
        
        if (s[i] >= 'a' && s[i] <= 'f')
        {
            result = result * 16 + (s[i] - 'a' + 10);
            i++;
            continue;
        } 

        if (s[i] >= 'A' && s[i] <= 'F')
        {
            result = result * 16 + (s[i] - 'A' + 10);
            i++;
            continue;
        }
    }

    return result;
}