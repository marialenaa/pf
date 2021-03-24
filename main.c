#include "libftprintf.h"

int main(void)
{
    int *ptr;
    int ret;
    int ret2;

    ptr = &ret;
   //  printf("p\n");
    ret = printf("%04.*i", -2, 0);
    printf("p\n");
     //printf("\n");
    ret2 = ft_printf("%04.*i", -2, 0);
    printf("p\n");
    printf("ret=%d ret:%d\n", ret, ret2);
    return (0);
}
