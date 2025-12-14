#include <iostream>

int main(int ac, char **av)
{
	int a = 1;
	int b = 0;
	if (ac == 1)
	{
		std :: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std :: endl;
		return (0);	
	}
	while (a < ac)
	{
		while (av[a][b])
		{
			char c = toupper(av[a][b]);
			std :: cout << c;
			b++;
		}
		a++;
		b = 0;
	}
	std :: cout << std :: endl;
}