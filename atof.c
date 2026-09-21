#include <ctype.h>
#include <stdio.h>

/* atof: convert string s to double */
double atof(char s[])
{
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		i++;

	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}

    if (s[i] != 'e' && s[i] != 'E')
    {
        return sign * val / power;
    }
 
    int scientific_notation_sign = 1;
    if (s[++i] == '-')
    {
        scientific_notation_sign = -1;
        i++; 
    }

    int scientific_num = 0;
    for (; isdigit(s[i]); i++)
    {
        scientific_num = 10 * scientific_num + (s[i] - '0');
    }

    double n = 1;
    if (scientific_notation_sign == 1)
    {
        while (scientific_num > 0)
        {
            n *= 10;
            scientific_num--;
        }
        return (sign * val / power) * n;
    }

    while (scientific_num > 0)
    {
        n = n / 10;
        scientific_num--;
    }

    return (sign * val / power) * n;
}

int main(void)
{
    double result = atof("123.45e-6");
    printf("%.17f", result);
}