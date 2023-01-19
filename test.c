#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
# include <readline/readline.h>
# include <readline/history.h> 

void	handler(int sig)
{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
}

int main()
{
	char *s;

	signal(SIGINT, handler);
	while (1)
	{
		s = readline(">");
		printf("%s\n",s);
	}
}
