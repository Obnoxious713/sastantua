void        ft_putchar(char c)
{
    write(1, &c, 1);
}

void        ft_putstr(char *str)
{
    while (*str != '\0')
    {
        ft_putchar(str);
        str++;
    }
}

void		sastantua(int size)
{
	int		i;
	int		space;
	int		rows;
	int		k;

	i = 1;
	space = 1;
	rows = 0;
	k = 0;
	while (i <= rows)
	{
		while (space <= (rows - i))
		{
			ft_putchar(' ');
			space++;
		}
		while (k != (2 * i - 1))
		{
			ft_putstr("* ");
			k++;
		}
		k = 0;
		ft_putchar('\n');
		i++;
	}
}

int			main(int argc, char **argv)
{
	if (argc > 1)
		return (0);
	if (argv[1] == 0)
		return (0);
	sastantua(argv[1]);
	return (0);
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