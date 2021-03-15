#include "libftprintf.h"

int main(void)
{
    int *ptr;
    int ret;
    int ret2;

    ptr = &ret;
   //  printf("p\n");
    ret = printf("%%-d 42 == %-d", -2147483648);
    printf("p\n");
     //printf("\n");
    ret2 = ft_printf("%%-d 42 == %-d", -2147483648);
    printf("p\n");
   printf("ret=%d ret-%d\n", ret, ret2);
    return (0);
}
