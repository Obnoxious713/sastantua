#include <stdio.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(str);
		str++;
	}
}

void		findsquare(int size)
{
	int		x;
	int		y;
	int		tier_count;
	int		*tier_rnbr;
	int		spaces;
	char	*row;

	x = 0;
	y = 0;
	tier_count = 1;
	tier_rnbr[1] = 3;
	spaces = 0;
	// the two outermost chars are '/' and '\' respectivly
		// find the longest row based on the size
			// subtract the amount in that row
				// divide new number, spaces, by two
					// put that many spaces before and after '/' and '\'
	while (tier_count <= size)
	{
		while (*row != '\0')
		{
			if (tier_count == 1)
			{
				x = 7;
				y = 3;
				spaces = (x - y) / 2;
				if (*row <= spaces || *row >= x - spaces)
					ft_putchar(' ');
				else if (*row == spaces + 1)
					ft_putchar('/');
				else if (*row == x - (spaces - 1))
					ft_putchar('\\');
				else
					ft_putchar('*');
			}
			row++;
		}
		tier_count++;
	}
}
/*
void		printrow(int size)
{
	char	*row;
	int		row_nbr;
	int		spaces;
	int		*nbr_char;
	int		lines;
	int		tier;
	int		tier_rnbr;

	spaces = 4;
	nbr_char[0] = 3;
	row_nbr = 0;
	tier = 1; // EACH TIER IS JUST A SQUARE INCLUDING THE SPACES
				// first tier is 3 * 7
				// add 10 to 3 and add 12 to 7
					// increase each by two each time
						// every other increases by 2 more
							// total of 4
	tier_rnbr = 3;
	while (tier < size)
	{
		while (row[r] != '\0')
		{
			while (row_nbr > tier_rnbr)
			{
				if (lines == ('\0' - 1))
				{
					
					spaces = (nbr_char[row_nbr] / 2) - nbr_char[0];
					if (nbr_char[])
						ft_putchar('\\');
					if (row[r] == row[0])
						ft_putchar('/');
					else
						ft_putchar('*');
					nbr_char + 2;
				}
				if (row_nbr == tier_rnbr)
				{
					nbr_char + 4;
					tier_rnbr++;
				}
				// the two outermost chars are '/' and '\' respectivly
					// find the longest row based on the size
						// subtract the amount in that row
						// divide new number, spaces, by two
						// put that many spaces before and after '/' and '\'
				
				row_nbr++;
			}
			r++;
		}
		tier++;
	}
	
}
*/

void		sastantua(int size)
{
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
	findsquare(size);
}

int			main(int argc, char **argv)
{	
	if (argc != 2)
		return (0);
	if (argv[1] == 0)
		return (0);
	ft_putstr(sastantua(argv[1]));
	return (0);
}