#include "libftprintf.h"

int main(void)
{
    int *ptr;
    int ret;
    int ret2;

    ptr = &ret;
    ret = printf("%0.1u", 4294967161);
    printf("p\n");
    ret2 = ft_printf("%0.1u", 4294967161);
    printf("p\n");
    printf("ret=%d ret:%d\n", ret, ret2);
    return (0);
}
