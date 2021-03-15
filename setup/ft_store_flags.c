#include "../libftprintf.h"

char	*ft_strchr(char *s, int c, int *flag)
{
	if (*s == (char)c)
	{
		*flag = 1;
		return (s + 1);
	}
	return (s);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	*ft_check_n_store_digit(char *str_after_mod, int *width_or_prec)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	if (ft_isdigit(*str_after_mod))
	{
		while (ft_isdigit(*str_after_mod))
		{
			res = res * 10 + (*str_after_mod - '0');
            str_after_mod++;
		}
		*width_or_prec = res;
	}
    return (str_after_mod);
}

void		*ft_check_n_data(char *str_after_mod, t_data *data)
{
	str_after_mod = ft_strchr(str_after_mod, '0', &data->zero_w);
    str_after_mod = ft_strchr(str_after_mod, '-', &data->minus);
    str_after_mod = ft_strchr(str_after_mod, '0', &data->zero_w);
	str_after_mod = ft_check_n_store_digit(str_after_mod, &data->width);
	str_after_mod = ft_strchr(str_after_mod, '%', &data->mod);
	str_after_mod = ft_strchr(str_after_mod, '*', &data->wildcard_w);
	str_after_mod = ft_strchr(str_after_mod, '.', &data->precision);
	str_after_mod = ft_strchr(str_after_mod, '0', &data->zero_p);
	str_after_mod = ft_strchr(str_after_mod, '*', &data->wildcard_p);
	if (data->precision)
		str_after_mod = ft_check_n_store_digit(str_after_mod, &data->precision_nb);
	return (str_after_mod);
}
