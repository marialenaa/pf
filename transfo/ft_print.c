#include "../libftprintf.h"

void	ft_putchar(char c, t_buf *buf)
{
    buf->count += write(1, &c, 1);
    // printf("count=%d",buf->count);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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
        ft_putchar(str[i], buf);
            i++;
        len--;
    }
}

void    ft_print_zero(int zero_nb, t_buf *buf)
{
    while (zero_nb > 0)
    {
        ft_putchar('0', buf);
        zero_nb--;
    }
}

void    ft_print_width(int width,t_buf *buf)
{
    while (width > 0)
        {
            ft_putchar(' ', buf);
            width--;
        }
}
