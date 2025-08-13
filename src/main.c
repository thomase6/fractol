#include "libft.h"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int res;

        res = ft_isalpha(av[1][0]);
        if (res == 1)
            write(1, "yes", 3);
        else
            write (1, "no", 2);
        return (0);
    }
}