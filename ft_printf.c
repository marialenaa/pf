#include "libftprintf.h"

void ft_find_mod(char *str, va_list args_ptr, t_buf *buf)
{
    t_data data;

    data = ft_data_init();
    while (*str)
    {
        if ((*str == '%' && *(str + 1)) && (*(str + 1) != '%'))
        {
            str++;
            buf->ptr = ft_get_type(str, &data);
            ft_get_flags(str, &data, buf);
            ft_parser(args_ptr, &data, buf);
            str = buf->ptr;
        }
        else
        {
            if (*str == '%' && (*(str + 1) == '%'))
                str++;
            ft_putchar(*str, &buf->count);
        }
        str++;
    }
}

int ft_printf(char *str, ...)
{
    va_list args_ptr;
    t_buf buf;
    va_start(args_ptr, str);
    int i;

    i = 0;
    buf = ft_init_buf(str);
    ft_find_mod(str ,args_ptr, &buf);
    va_end(args_ptr);
    return (buf.count);
}
