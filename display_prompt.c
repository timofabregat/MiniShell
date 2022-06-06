#include "minish.h"

void	ft_putstr_fd(char const *s, int fd)
{
	write(fd, s, strlen(s));
}

void	ft_putstr(char const *s)
{
	ft_putstr_fd(s, 1);
}

void	display_prompt_msg(void)
{
	char	*cwd;
	char	buff[4096 + 1];
	char	*parsed_cwd;

	/*cwd = getcwd(buff, 4096);
	parsed_cwd = parse_home_path(cwd, 0);
	ft_putstr(parsed_cwd);
	free(parsed_cwd);*/
	ft_putstr(" \033[31m︻\033[0m\033[32m┳\033[0m\033[33mデ");
	ft_putstr("\033[0m\033[34m═\033[0m\033[35m—\033[0m$ ");
}

