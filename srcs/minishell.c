/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/09 17:23:20 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_exec_fonc( char **cmd, char **env)
{
	pid_t 	pid;
	int 	statue;
	int		ret;

	ret = 0;
	wait(&statue);
	if ((pid = fork()) == 0)
	{
		if ((execve(cmd[0], cmd, env)) != -1)
			ret = 1;
		else
			perror("minishell ");
	}
	return (ret);
}

char	*ft_get_env(char **env, char *elem)
{
	char 	*path;
	int 	i;

	i = 0;
	path = ft_strdup(env[i]);
	path = ft_strsub(env[i], 5, (ft_strlen(env[i]) - 5));
	return (path);
}

int		main(int ac, char **av, char **env)
{
	char 	*line;
	char 	**cmd;
	int  	ret;
	pid_t 	pid;

	line = NULL;
	cmd = (char **)malloc(sizeof(char **) *ac);
	while(ret == 0)
	{
		ft_putstr("$>");
		get_next_line(0, &line);
		cmd = ft_strsplit(line, ' ');
		cmd[0] = ft_strjoin("/bin/", cmd[0]);
		ft_exec_fonc(cmd, env);
	}
}