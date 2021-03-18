#include "libftprintf.h"

void ft_find_mod(char *str, va_list args_ptr, t_buf *buf)
{
    t_data data;

    while (*str)
    {
        // if (*str == '%' && !buf->mod)
        // {
        if (ft_check_mod(str, buf))
        {
            data = ft_data_init();
            str++;
            //ft_check_mod(str, buf, args_ptr);
            buf->ptr = ft_get_type(str, &data, buf);
            //printf("STR%c", *str);
            ft_get_flags(str, &data);
            if (data.typ)
                ft_parser(args_ptr, &data, buf);
            else
                ft_notype(args_ptr, &data, buf);
            str = buf->ptr;
        }
        else
            ft_putchar(*str, &buf->count);
        str++;
    }
}

int ft_check_mod(char *str, t_buf *buf)
{
    if (buf->mod || !(*str + 1 || *str != '%'))
        return (0);
    if (*str == '%')
    {
        if ((*str + 1) == '%')
        {
            //write(1, "9\n", 2);
            buf->mod = 1;
            return (0);
        }
    }
     return (1);
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
