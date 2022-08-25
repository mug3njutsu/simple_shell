#include "main.h"

/**
  * sigint - reprompts
  * @signal: signal passed
  */

void sigint(int signal __attribute__((unused)))
{
	fflush(STDIN_FILENO);
	write(STDERR_FILENO, "\n$ ", 3);
}
