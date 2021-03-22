/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallizz <mgallizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:51:08 by mgallizz          #+#    #+#             */
/*   Updated: 2021/03/22 10:09:37 by mgallizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFTPRINTF_H__
# define __LIBFTPRINTF_H__

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# define HEXA_LOWER "0123456789abcdef"
# define HEXA_UPPER "0123456789ABCDEF"
# define TYPE "scdiuxXp"

typedef void (*ft)(void *, ...);

typedef struct s_data
{
        int len;
        int mod;
        int int_min;
        int typ;
        int zero;
        int conv;
        int minus;
        int neg;
        int zero_w;
        int zero_p;
        int width;
        int precision;
        int precision_nb;
        int wildcard_w;
        int wildcard_p;
        int width_minus;
        char *arg_s;
        unsigned long long ptr;
        int arg_i;
        unsigned int arg_u;
} t_data;

typedef struct s_buf
{
        int len;
        char buf[1024];
        int mod;
        int count;
        void *ptr;
} t_buf;


int     ft_printf(char *str, ...);

// find GET DATA
void        *ft_get_type(char *str_after_mod, t_data *data, t_buf *buf);
void        ft_find_mod(char *str, va_list args_ptr, t_buf *buf);
void        ft_get_flags(char *str_after_mod, t_data *data, t_buf *buf);
void	*ft_check_n_store_digit(char *str_after_mod, int *width_or_prec);
void    *ft_check_mod(char *str, t_buf *buf);

//init
t_buf   ft_init_buf(char *list);
t_data  ft_data_init(void);

// treat flags
void        ft_treat_wildcard(t_data *data, va_list args_ptr);
void        ft_treat_width(t_data *data);
void        ft_width(t_data *data);
void        ft_treat_minus(t_data *data);
void        ft_treat_prec(t_data *data);
void        ft_treat_neg(t_data * data);
void        ft_treat_arg_zero(t_data *data);
void    ft_treat_zero_p(t_data *data, t_buf *buf);
void    ft_width_notprec_nb(t_data *data);
void        ft_treat_flag(t_data *data);
void ft_wildcard_p(t_data *data, va_list args_ptr);
void ft_wildcard_w(t_data *data, va_list args_ptr);

//treat types
void        ft_treat_u_i(t_data *data, t_buf *buf);
void        ft_treat_c(va_list args_ptr, t_data *data, t_buf *buf);
void        ft_treat_s(t_data *data, t_buf *buf);
void        ft_treat_prec_s(t_data *data);
void        ft_treat_x(t_data *data, t_buf *buf);

//convert arg && print 
void        ft_convert_putnbr_base(long long unsigned int nbr, t_data *data, t_buf *buf);
void        ft_print_width(int width, t_buf *buf);
void        ft_print_zero(int zero_nb, t_buf *buf);
void        ft_putnbr(long long int n,t_data *data, t_buf *buf);
void	ft_putchar(int c, int *count);
void        ft_treat_p(t_data *data,  t_buf *buf);
void        ft_ptr_len(long long unsigned nbr, int *len);
//void      *ft_double_mod(char *str, t_buf *buf);

//get arg PARSER
void        ft_notype(va_list args_ptr, t_data *data, t_buf *buf);
void        ft_get_arg_s(va_list args_ptr, t_data *data, t_buf *buf);
void        ft_get_arg_p(va_list args_ptr, t_data *data, t_buf *buf);
void        ft_get_arg_i_d(va_list args_ptr, t_data *data, t_buf *buf);
void        ft_get_arg_x_u(va_list args_ptr, t_data *data, t_buf *buf);
void        ft_parser(va_list args_ptr, t_data *data, t_buf *buf);

//utils
void	ft_putstrl(char *str, int len, t_buf *buf);
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c, int *minus);
size_t	ft_intlen(unsigned int nb, char typ);
void	ft_strcpy(char *dest, char *src);
int		ft_isflag(int c);
int		ft_isdigit(int c);

# endif
