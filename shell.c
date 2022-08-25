#include "main.h"

/**
 * main - func with infinite loop
 * @ac: NULL
 * @av: NULL
 * Return: loop.
 **/

int main(int ac, char **av)
{
	(void)av;
	(void)ac;

	signal(SIGINT, controlC);
	prompt();
	return (0);
}
