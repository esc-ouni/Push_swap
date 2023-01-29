#include <stdio.h>
#include "LIBFT/libft.h"

int main()
{
    char    **s = ft_split("   45  ", ' ');
    printf("%s\n", s[0]);
    printf("%s\n", s[1]);
    printf("%s\n", s[2]);
}