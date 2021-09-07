#include "push_swap.h"

void	ft_puts(char *msg)
{
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
}