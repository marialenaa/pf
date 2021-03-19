#include "../libftprintf.h"

void	ft_putchar(int c, int *count)
{
   
        //printf("c%c", c); 
        //printf("d%d", c);
    write(1, &c,1);
    *count += 1;
}

void	ft_putstrl(char *str, int len, t_buf *buf)
{
	int i;

	i = 0;
    while (str[i] != '\0' && len > 0)
    {
        if (buf->mod && str[i] == '%')
        {
            i++;
            buf->mod = 0;
        }
        ft_putchar(str[i], &buf->count);
            i++;
        len--;
    }
}

void    ft_print_zero(int zero_nb, t_buf *buf)
{
    while (zero_nb > 0)
    {
        ft_putchar('0', &buf->count);
        zero_nb--;
    }
}

void    ft_print_width(int width,t_buf *buf)
{
    while (width > 0)
        {
            ft_putchar(' ', &buf->count);
            width--;
        }
}
