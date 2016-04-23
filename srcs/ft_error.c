/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 17:09:09 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/17 17:09:10 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		ft_error_env(char **cmd)
{
	if ((ft_strcmp(cmd[0], "env") == 0) && !cmd[1])
		return (0);
	else if (cmd[1] && cmd[1][0] != '-')
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(cmd[1], 2);
		ft_putendl_fd(" : No such file or directory", 2);
		return (-1);
	}
	else if (cmd[1] && ((ft_strcmp(cmd[1], "-v") != 0)
		|| (ft_strcmp(cmd[1], "-P") != 0) || (ft_strcmp(cmd[1], "-S") != 0)
		|| (ft_strcmp(cmd[1], "-u") != 0) || (ft_strcmp(cmd[1], "--") != 0)
		|| (ft_strcmp(cmd[1], "--") != 0)))
	{
		ft_putstr_fd("env: illegal option -- ", 2);
		ft_putchar_fd((ft_seek_wrong_opt(cmd[1])), 2);
		ft_putchar('\n');
		ft_putstr_fd("usage: env [-iv] [-P utilpath][-S string] [-u name]", 2);
		ft_putendl_fd("[-S string] [-u name]", 2);
		ft_putstr_fd("           ", 2);
		ft_putendl_fd("[name=value ...] [utility [argument ...]]", 2);
		return (-1);
	}
	return (0);
}

void	ft_error_no_directory(char **cmd)
{
	struct stat my_stat;

	stat(cmd[1], &my_stat);
	ft_putstr_fd("cd: ", 2);
	if ((access(cmd[1], F_OK)) == -1)
		ft_putstr_fd("no such file or directory: ", 2);
	else if (!(S_ISDIR(my_stat.st_mode)))
		ft_putstr_fd("not directory: ", 2);
	else
		ft_putstr_fd("permission denied: ", 2);
	ft_putendl_fd(cmd[1], 2);
}

int		ft_error_set_unset_env(char **cmd, char *name)
{
	if ((ft_tab_len(cmd)) <= 1)
	{
		ft_putstr_fd(name, 2);
		ft_putendl_fd(": You must provide a variable", 2);
		return (-1);
	}
	else if ((ft_tab_len(cmd)) > 3 && ft_strcmp(name, "setenv") == 0)
	{
		ft_putstr_fd(name, 2);
		ft_putendl_fd(": Two many arguments", 2);
		return (-1);
	}
	else if ((ft_isalphanumeric(cmd[1]) == 1)
		&& ((ft_strcmp(name, "setenv")) == 0))
	{
		ft_putstr_fd("setenv: Variable name must", 2);
		ft_putendl_fd(" contain alphanumeric characters.", 2);
		return (-1);
	}
	return (0);
}

int		ft_error_exit(char **cmd, char *name)
{
	(void)name;
	if (cmd && cmd[1] && cmd[2])
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(cmd[1], 2);
		ft_putendl_fd(": unique numeric argument required", 2);
		return (-1);
	}
	else
		return (0);
}

int		ft_error_cd(char **cmd)
{
	if ((access(cmd[1], F_OK)) == -1 && !cmd[2] && (ft_strcmp(cmd[1], "~") != 0)
		&& (ft_strcmp(cmd[1], "-") != 0))
		ft_error_no_directory(cmd);
	else if (cmd[0] && cmd[1] && cmd[2] && cmd[3])
		ft_putendl_fd("cd: too many arguments", 2);
	else if ((cmd[1]) && cmd[2])
	{
		ft_putstr_fd("cd: string not in pwd: ", 2);
		ft_putendl_fd(cmd[1], 2);
	}
	else
		return (0);
	return (1);
}
