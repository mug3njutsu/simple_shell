#include "main.h"

/**
 * sig_handler - Ctrl+C handler
 * @sig_num: int
 */

void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		_puts("\nl33tsh3ll$ ");
	}
}

/**
* _EOF - handles EOF
* @len: return value of getline func
* @buff: buf
 */

void _EOF(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buff);
		}
		exit(0);
	}
}

/**
  * _isatty - verify if terminal
  */

void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("l33tsh3ll$ ");
}

/**
 * main - Shell
 * Return: Always 0 -> (Success)
 */

int main(void)
{
	ssize_t len = 0;
	char *buff = NULL, *value, *pathname, **arv;
	size_t size = 0;
	list_path *head = '\0';
	void (*f)(char **);

	signal(SIGINT, sig_handler);
	while (len != EOF)
	{
		_isatty();
		len = getline(&buff, &size, stdin);
		_EOF(len, buff);
		arv = splitstring(buff, " \n");
		if (!arv || !arv[0])
			execute(arv);
		else
		{
			value = _getenv("PATH");
			head = linkpath(value);
			pathname = _which(arv[0], head);
			f = checkbuild(arv);
			if (f)
			{
				free(buff);
				f(arv);
			}
			else if (!pathname)
				execute(arv);
			else if (pathname)
			{
				free(arv[0]);
				arv[0] = pathname;
				execute(arv);
			}
		}
	}
	free_list(head);
	freearv(arv);
	free(buff);
	return (0);
}