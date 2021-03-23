#include "libftprintf.h"

int main(void)
{
    int *ptr;
    int ret;
    int ret2;

    ptr = &ret;
   //  printf("p\n");
    ret = printf("%0*.u" ,76,450647582u);
    printf("p\n");
     //printf("\n");
    ret2 = ft_printf("%0*.u" ,76,450647582u);
    printf("p\n");
    printf("ret=%d ret:%d\n", ret, ret2);
    return (0);
}
