#include "libftprintf.h"

int main(void)
{
    int *ptr;
    int ret;
    int ret2;

    ptr = &ret;
   //  printf("p\n");
    ret = printf("%--12.38x%-116.%%--51.178i" ,1756825080u,-1476384935);
    printf("p\n");
     //printf("\n");
    ret2 = ft_printf("%--12.38x%-116.%%--51.178i" ,1756825080u,-1476384935);
    printf("p\n");
    printf("ret=%d ret-%d\n", ret, ret2);
    return (0);
}
