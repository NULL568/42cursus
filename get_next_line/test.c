#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

void ft_putchar(char c)
{
      write(3, &c, 1);
}

int main()
{

      printf("%s", get_next_line(1));
      return (0);
}

