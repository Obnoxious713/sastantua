#include <unistd.h>
#include <stdlib.h>

void            ft_putchar(char c)
{
        write(1, &c, 1);
}

int            base_size(int size)
{
    int        tier;
    int        row_len;
    int        base_len;
    int        rows_per_tier;
    int        row_nbr;
    int        tier_jump;

    tier = 1;
    row_len = 3;
    base_len = 0;
    rows_per_tier = 0;
    tier_jump = 6;
    while (tier <= size)
    {
        row_nbr = 1;
        rows_per_tier = tier + 2;
        while (row_nbr < rows_per_tier)
        {
            row_len += 2;
            row_nbr++;
        }
        if (row_nbr == rows_per_tier)
        {
            if (tier % 3 == 0)
                tier_jump += 2;
            if (tier != size)
               row_len += tier_jump;
        }
        tier++;
    }
    base_len = row_len;
    return (base_len);
}

void           ft_putspaces(int space)
{
        int             col_nbr;

        col_nbr = 0;
        while (col_nbr < space)
        {
                ft_putchar(' ');
                col_nbr++;
        }
}

void            ft_putrow(int size, int tier, int row_len, int row_nbr)
{
        int             col_nbr;
        int             door;
        int             key;

        col_nbr = 0;
        door = 0;
        while (col_nbr < row_len)
        {
                if (col_nbr == 0)
                        ft_putchar('/');
                else if (col_nbr == row_len - 1)
                        ft_putchar('\\');
                else if ((tier == size) && (row_nbr >= 2) && col_nbr == ((row_len / 2) - (size / 2)))
                {
                        while (door < size)
                        {
                                if ((tier >= 3 && door == size - 2) && row_nbr == (size +  3) / 2)
                                        ft_putchar('$');
                                else
                                        ft_putchar('|');
                                col_nbr += 1;
                                door++;
                        }
                        col_nbr -= 1;
                }
                else
                        ft_putchar('*');
                col_nbr++;
        }
}

void            sastantua(int size)
{
        int             tier;
        int             row_nbr;
        int             row_len;
        int             rows_per_tier;
        int             row_bases;
        int             tier_jump;

        tier = 1;
        row_len = 1;
        rows_per_tier = 0;
        tier_jump = 4;
        row_bases = base_size(size);
        while (tier <= size)
        {
                if (tier == 1)
                        row_len = 3;
                row_nbr = 0;
                rows_per_tier = tier + 2;
                while (row_nbr < rows_per_tier)
                {
                        ft_putspaces((row_bases - row_len) / 2);
                        ft_putrow(size, tier, row_len, row_nbr);
                        ft_putchar('\n');
                        row_len += 2;
                        row_nbr++;
                }
                if (row_nbr == rows_per_tier)
                {
                    if (tier % 3 == 0)
                        tier_jump += 2;
                    if (tier != size)
                       row_len += tier_jump;
                }
            tier++;
        }
}

int                     main(int argc, char **argv)
{
        int     av;

        av = atoi(argv[1]);
        if (argc != 2)
                return (0);
        if (argv[1] == 0)
                return (0);
        sastantua(av);
        return (0);
}