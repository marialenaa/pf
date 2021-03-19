#include "../libftprintf.h"

void    ft_parser(va_list args_ptr, t_data *data, t_buf *buf)
{
//        printf("\nSTRUCTURE INFOS:\n");
//  	 printf("precision_nb >>>>> %d\n", data->precision_nb);
//     printf("precision >>>>> %d\n", data->precision);
//     printf("zero >>>>> %d\n", data->zero);
//     printf("zerop >>>>> %d\n", data->zero_p);
//    printf("zerow >>>>> %d\n", data->zero_w);
//  printf("mod >>>>> %d\n", data->mod);
//    printf("NEG >>>>> %d\n", data->neg);
//  printf("typ >>>>> %c\n", data->typ);
//     printf("minus >>>>> %d\n", data->minus);
//   //printf("len >>>>> %d\n", data->len);
//    printf("conv >>>>> %d\n", data->conv);
//    printf("wildcardp >>>>> %d\n", data->wildcard_p);
//     //printf("arg_s >>>>> %s\n", data->arg_s);
//   //  printf("hexa >>>>> %llu\n", data->ptr);
//   printf("width >>>>> %d\n", data->width);
// printf("len >>>>> %d\n", data->len);
   // printf("int >>>>> %d\n", data->arg_i);
  
    if (data->wildcard_w || data->wildcard_p)
        ft_treat_wildcard(data, args_ptr);
    if (data->typ == 'c')
         ft_treat_c(args_ptr, data, buf);
    if (data->typ == 's')
        ft_get_arg_s(args_ptr, data, buf);
    else if (data->typ == 'p')
            ft_get_arg_p(args_ptr, data, buf);
    else if (data->typ == 'i' || data->typ == 'd')
        ft_get_arg_i_d(args_ptr, data, buf);
    else if (data->typ == 'x' || data->typ == 'X' || data->typ == 'u')
        ft_get_arg_x_u(args_ptr, data, buf);
}

