#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    int i, a;
    char x;
    char *p;

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == 'c')
            {
                x = va_arg(args, int);
                printChar(x, &count);
                i++;
            }
            else if (format[i + 1] == 's')
            {
                p = va_arg(args, char*);
                printStr(p, &count);
                i++;
            }
            
            else if (format[i + 1] == 'd' || format[i + 1] == 'i')
	    {
		    int q = va_arg(args, int);
		    print_number(q, &count);
		    i++;
	    }

            else if (format[i + 1] == 'b')
            {
                unsigned int num = va_arg(args, unsigned int);
                printBinary(num, &count);
                i++;
            }

	    else if (format[i + 1] == 'u')
            {
                unsigned int u = va_arg(args, unsigned int);
                print_unsigned(u, &count);
                i++;
            }

            else if (format[i + 1] == 'o')
            {
                unsigned int num = va_arg(args, unsigned int);
                int digits = 0;
                unsigned int temp = num;
                while (temp != 0)
                {
                    digits++;
                    temp /= 8;
                }
                for (a = 0; a < digits; a++)
                {
                    putchar('0' + ((num >> (3 * (digits - 1 - a))) & 7));
                    count++;
                }
                i++;
            }
            else if (format[i + 1] == 'x' || format[i + 1] == 'X')
            {
                unsigned int num = va_arg(args, unsigned int);
                int digits = 0;
                unsigned int temp = num;
		char hex_digits[] = "0123456789abcdef";
                while (temp != 0)
                {
                    digits++;
                    temp /= 16;
                }
                
                if (format[i + 1] == 'X')
                    hex_digits[10] = 'A';
                for (a = 0; a < digits; a++)
                {
                    putchar(hex_digits[(num >> (4 * (digits - 1 - a))) & 0xF]);
                    count++;
                }
                i++;
            }

	    else if (format[i + 1] == 'p')
            {
                void *ptr = va_arg(args, void *);
                unsigned long ptrValue = (unsigned long)ptr;
                int numDigits = 0;
                unsigned long temp = ptrValue;

                
                while (temp != 0)
                {
                    numDigits++;
                    temp /= 16;
                }

                
                putchar('0');
                putchar('x');
                count += 2;

               
                for (a = 0; a < numDigits; a++)
                {
                    int digit = (int)((ptrValue >> (4 * (numDigits - 1 - a))) & 0xF);
                    putchar("0123456789abcdef"[digit]);
                    count++;
                }
	                i++;
	    }


            else if (format[i + 1] == '%')
            {
                putchar('%');
                i++;
                count++;
            }
            else
            {
                putchar(format[i]);
                count++;
                
            }
        }
        else
        {
            putchar(format[i]);
            count++;
        }
    }

    va_end(args);

    return count;
}

