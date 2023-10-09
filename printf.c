#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr(char *str)
{
    int len = 0;
    if (!str)
    {
        write(1, "(null)", 6);
        return (6);
    }
    while (str[len] != 0)
    {
        ft_putchar(str[len]);
        len++;
    }
    return (len);
}
int count_len(unsigned int num, int divisor)
{
    int len = 0;
    while (num > 0)
    {
        num = num / divisor;
        len++;
    }
    return (len);
}

int ft_print_hex(unsigned int nbr)
{
    if (nbr == 0)
    {
        write(1, "0", 1);
        return (1);
    }
    int i = 1;
    char *base = "0123456789abcdef";
    int len = count_len(nbr, 16);
    char *hex_str;
    hex_str = (char *)malloc(sizeof(char) * (len + 1));
    hex_str[len] = '\0';
    while (nbr > 0)
    {
        hex_str[len - i] = base[nbr % 16];
        nbr = nbr / 16;
        i++;
    }
    ft_putstr(hex_str);
    free(hex_str);
    return (len);
}

int ft_putnbr(long long int nbr)
{
    long long int num = nbr;
    int len = 0;
    // if (nbr < -2147483647)
    // {
    //     write(1, "-2147483648", 11);
    //     return (11);
    // }
    if (num == 0)
        len = 1;
    if (nbr < 0)
    {
        num = -nbr;
        len++;
        ft_putchar('-');
    }
    len += count_len(num, 10);
    if (num > 9)
        ft_putnbr(num / 10);
    ft_putchar((num % 10) + 48);
    return(len);
}

int ft_printf(const char *str, ...)
{
    va_list args;
    int len = 0;
    int i = 0;
    va_start(args, str);
    while (str[i] != 0)
    {
        if (str[i] == '%' && str[i + 1] == 's')
        {
            len += ft_putstr(va_arg(args, char *));
            i++;
        } 
        else if (str[i] == '%' && str[i + 1] == 'd')
        {
            len += ft_putnbr(va_arg(args, int));
            i++;
        }  
        else if (str[i] == '%' && str[i + 1] == 'x')
        {
            len += ft_print_hex(va_arg(args, unsigned int));
            i++;
        }
        else
            len += ft_putchar(str[i]);
        i++;
    }
    va_end(args);
    return (len);
}


int main(void)
{
    // int num = 1347345;
    char *str = "abc";
    int result = 0;
    int result_printf = 0;
    // int test = 0;
    printf("String results:\n");
    result = ft_printf("my string: %s\n", str);
    ft_printf("result: %d\n", result);
    printf("-------------------\n");
    result_printf = printf("my string: %s\n", str);
    printf("result: %d\n\n", result_printf);

    // printf("Percent results:\n");
    // result = ft_printf("%%\n");
    // ft_printf("result: %d\n", result);
    // printf("-------------------\n");
    // result_printf = printf("%%\n");
    // printf("result: %d\n\n", result_printf);

    printf("Decimal results:\n");
    result = ft_printf("%d\n", 0);
    printf("result: %d\n", result);
    printf("-------------------\n");
    result_printf = printf("%d\n", 0);
    printf("result: %d\n\n", result_printf);

    printf("Decimal negative results:\n");
    result = ft_printf("%d\n", -35647);
    printf("result: %d\n", result);
    printf("-------------------\n");
    result_printf = printf("%d\n", -35647);
    printf("result: %d\n\n", result_printf);

    printf("Decimal results (max int):\n");
    result = ft_printf("%d\n", INT_MAX);
    printf("result: %d\n", result);
    printf("-------------------\n");
    result_printf = printf("%d\n", INT_MAX);
    printf("result: %d\n\n", result_printf);

    printf("Decimal results (min_int):\n");
    result = ft_printf("%d\n", INT_MIN);
    printf("result: %d\n", result);
    printf("-------------------\n");
    result_printf = printf("%d\n", INT_MIN);
    printf("result: %d\n\n", result_printf);

    // test = count_len(8888881);
    // printf("test value: %d\n", test);
    printf("Hex results:\n");
    result = ft_printf("%x\n", UINT_MAX);
    ft_printf("result: %d\n", result);
    printf("-------------------\n");
    result_printf = printf("%x\n", UINT_MAX);
    printf("result: %d\n\n", result_printf);

    printf("Hex results (0):\n");
    result = ft_printf("%x\n", 0);
    ft_printf("result: %d\n", result);
    printf("-------------------\n");
    result_printf = printf("%x\n", 0);
    printf("result: %d\n\n", result_printf);
    return (0);
}