#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			base_size(int size)
{
	int		tier;
	int		row_len;
	int		tier_jump;

	tier = 1;
	base_len = 1;
	tier_jump = 4;
	while (tier <= size)
	{
		base_len += 2 * (2 + tier);
		if (tier % 2 && tier < size)
			tier_jump += 2;
		tier++;
	}
	return (base_len);
}

void		ft_putspaces(int space) 
{
	int		col_nbr;
	
	col_nbr = 0;
	while (col_nbr < space)
	{
		ft_putchar(' ');
		col_nbr++;
	}
}

void		create_pyramid(int size, int tier /*floor*/,  int row_len /*width*/, int row_nbr /*step*/)
{
	int		door;
	int		col_nbr;

	col_nbr = 0;
	while (col_nbr < row_len)
	{
		if (col_nbr == 0)
			ft_putchar('/');
		else if (col_nbr == row_len - 1)
			ft_putchar('\\');
		else
		{
		/*	if (tier == size && col_nbr >= (row_len - door) / 2
					&& col_nbr < (row_len + door) / 2 && 2 + tier - row_nbr <= door)
			{	
				if (door >= 5 && row_len == 2 + tier - door / 2 - 1
						&& col_nbr == (row_len + door) / 2 - 2)
					ft_putchar('$');
				else
					ft_putchar('|');
			}
			else */
				ft_putchar('*');
		}
		col_nbr++;
	}
}
	// the two outermost chars are '/' and '\' respectivly
		// find the longest row based on the size
			// subtract the amount in that row
				// divide new number, spaces, by two
					// put that many spaces before and after '/' and '\'
	
 // EACH TIER IS JUST A SQUARE INCLUDING THE SPACES
				// first tier is 3 * 7
				// add 10 to 3 and add 12 to 7
					// increase each by two each time
						// every other increases by 2 more
							// total of 4
				// the two outermost chars are '/' and '\' respectivly
					// find the longest row based on the size
						// subtract the amount in that row
						// divide new number, spaces, by two
						// put that many spaces before and after '/' and '\'

void		sastantua(int size)
{
	int		tier;
	int		rows_per_tier;
	int		row_nbr;
	int		row_len;

	if (size < 1)
		return (0);
	tier = 1;
	row_len = 1;
	while (tier <= size)
	{
		rows_per_tier = 2 + tier;
		row_nbr = 0;
		while (row_nbr < rows_per_tier)
		{
			row_len += 2;
			ft_putspaces((base_size(size) - row_len) / 2);
			create_pyramid(size, tier, row_len, row_nbr);
			ft_putchar('\n');
			row_nbr++;
		}
		tier++;
		row_len += 4 + 2 * ((tier - 2) / 2);
	}

	// what am I trying to do?
		// print out pyrimid
		// size givn as argv[1]
		// after the first, and after the second, tier add 6 '*'
			// every 2 tiers add 2 more '*'
		//center of the bottom most row is '|'
		// door is perfect square
			// the diminsions == size
			// key '$' isn't printed before the 3rd tier
		// each row add 2 '*'
		// incorporate spaces before and after '/' and '\'
	
}

int			main(int argc, char **argv)
{	
	if (argc != 2)
		return (0);
	if (argv[1] == 0)
		return (0);
	sastantua(argv[1]);
	return (0);
}