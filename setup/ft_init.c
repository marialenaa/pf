#include "../libftprintf.h"

void	ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

t_buf ft_init_buf(char *list)
{
    t_buf buf;

    ft_strcpy(buf.buf, list);
    buf.len = ft_strlen(list);
    buf.mod = 0;
    buf.count = 0;
    return (buf);
}

t_data ft_data_init()
{
    t_data data;

    data.len = 0;
    data.mod = 0;
    data.conv = 0;
    data.zero = 0;
    data.size_max = 0;
    data.typ = 0;
    data.minus = 0;
    data.neg = 0;
    data.zero_w = 0;
    data.zero_p = 0;
    data.width = 0;
    data.precision = 0;
    data.precision_nb = 0;
    data.wildcard_w = 0;
    data.wildcard_p = 0;
    data.int_min = 0;
    data.width_minus = 0;
    return (data);
}
