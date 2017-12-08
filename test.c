#include <stdio.h>

Hi Mike. I was just in one of these with another agent before the site crashed. I am having internet connection issues. After logging into my account it says that the internet status is connected but even hard wired to the modem I still get no access.I have restarted both modem and router easily 20 times in the past 4 days that we have been without internet.
I can start with reprovisiong your modem 
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

void        findsquare(int size)
{
    int        x;
    int        y;
    int        tier_count;
    int        tier_rnbr;
    int        spaces;
    int        tier_start;
    int         col;
    int         rows;

    x = 0;
    y = 0;
    tier_start = 1;
    tier_count = 1;
    tier_rnbr = 1;
    // the two outermost chars are '/' and '\' respectivly
        // find the longest row based on the size
            // subtract the amount in that row
                // divide new number, spaces, by two
                    // put that many spaces before and after '/' and '\'
    while (tier_count <= size)
    {
        if (tier_count == 1)
        {
            x = 7;
            y = 3;
        }
        
        while (tier_rnbr <= y)
        {
            col = 0;
            while (col <= x)
            {
              
                spaces = (x - y) / 2;
                if (col < spaces)
                    ft_putchar(' ');
                else if (col == spaces + 1)
                    ft_putchar('/');
                else if ((col > spaces) && (col < x - spaces))
					//if (tier_rnbr > 1)
                  ft_putchar('*');
                else if (col == x - spaces)
                    ft_putchar('\\');
                else if (col > x - spaces)
                    ft_putchar(' ');
            
              if (col == x + 1)
                {
                  x = x + 12;
                  y = y + 10;
                  if (tier_count == tier_start + 1)
                  {
                      x + 2;
                      y + 2;
                      if (tier_count == tier_start + 2)
                      {
                          x + 2;
                          x + 2;
                      }
                  }
                  tier_start = tier_count;
                 }
              col++;
            }
          ft_putchar('\n');
          tier_rnbr++;
		  if (tier_rnbr > 1)
            {
              x + 2;
            }
        }
        tier_count++;
    }
}

int   main()
{
    findsquare(1);
    return (0);
}