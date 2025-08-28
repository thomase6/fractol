#include "libft.h"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int res = 0;
        char c = av[1][0];
        res = ft_is_space(c);
        if (res == 1)
        {
            write(1, "yes", 3);
        }
        else
        {
            write(1, "no", 3);
        }
    }
    return (0);
}