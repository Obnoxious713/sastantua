#include <unistd.h>

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

int            row_size(int size)
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
    row_nbr = 1;
    rows_per_tier = tier + 2;
    while (row_nbr < rows_per_tier)
    {
        if (row_nbr == rows_per_tier)
        {
            if (tier % 3 == 0)
                tier_jump += 2;
            if (tier != size)
               row_len += tier_jump;
        }
            row_len += 2;
            row_nbr++;
            tier++;
    }
    return (row_len);
}

void            ft_putspaces(int space)
{
        int             col_nbr;

        col_nbr = 0;
        while (col_nbr < space)
        {
                ft_putchar(' ');
                col_nbr++;
        }
}

void            ft_putrow(int size, int tier,  int row_len, int row_nbr)
{
        int             col_nbr;

        col_nbr = 0;
        while (col_nbr < row_len)
        {
                if (col_nbr == 0)
                        ft_putchar('/');
                else if (col_nbr == row_len - 1)
                        ft_putchar('\\');
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
        int             row_s;

        tier = 1;
        row_len = 1;
        rows_per_tier = 0;
        while (tier <= size)
        {
                row_nbr = 1;
                rows_per_tier = tier + 2;
                row_s = row_size(tier);
                if (row_nbr == rows_per_tier)
                {
                     row_len += 2;
                      ft_putspaces((base_size(tier) - row_len) / 2);
                      ft_putrow(size, tier, row_len, row_nbr);
                      ft_putchar('\n'); 
                }
                if (row_nbr < rows_per_tier)
                {
                        row_len += 2;
                        ft_putspaces((row_s - row_len) / 2);
                        ft_putrow(size, tier, row_len, row_nbr);
                        ft_putchar('\n');
                }
                row_nbr++;
                tier++;
        }
}

int     main()
{
  sastantua(2);
  return (0);
}