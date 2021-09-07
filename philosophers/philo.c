#include "philo.h"

int	main(void)
{
	t_status	info;
	int	ac = 6;
	char	*ag[6] = {"", "4", "400", "100", "100", "2"};

	memset(&info, 0, sizeof(t_status));
	if (!(ac >= 5 && ac <= 6))
		printf("Error: Check argument");
	else if (!init(ac, ag, &info))
	{
		run(&info);
		free(info.dp);
		free(info.gen);
	}
}
