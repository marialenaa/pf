#include "libftprintf.h"

void ft_find_mod(char *str, va_list args_ptr, t_buf *buf)
{
    int i;
    char *after_type;

    i = 0;
    while (str[i] && str[i] != '%')
        i++;
    if (str[i] == '%' && str[i + 1] && !(str[i + 1] == '%'))
    {
            //printf("YpO");
            buf->len = i;
            ft_putstrl(str, buf->len, buf);
            after_type = ft_parser(str + (i + 1), args_ptr, buf);
            ft_find_mod(after_type, args_ptr, buf);
    }
    else if (str[i] == '%' && (str[i + 1] == '%'))
    {
        // printf("cO");
        i++;
        buf->mod = 1;
        buf->len = i;
        ft_putstrl(str, buf->len, buf);
        ft_find_mod(str + (i + 1), args_ptr, buf);
    }
    else 
    {
        if (str[i] == '\0')
            ft_putstrl(str, i, buf);
        // else
        //     ft_find_mod(str + i, args_ptr, buf, store_data);
    }
    //printf("count=%d",buf->count);
}

int ft_printf(char *str, ...)
{
    va_list args_ptr;
   
    //va_copy(args_ptr, args_ptr_cpy);
    //t_data store_data;
    t_buf buf;
   
    va_start(args_ptr, str);
    int i;

    i = 0;
    buf = ft_init_buf(str);
    ft_find_mod(str ,args_ptr, &buf);
    va_end(args_ptr);
    return (buf.count);
}
