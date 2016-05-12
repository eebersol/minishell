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

#include <minishell.h>

int		ft_exec(char **cmd, char **env)
{
	pid_t	pid;
	int		status;
	int		flag;

	flag = 0;
	if ((pid = fork()) == 0)
	{
		if ((execve(cmd[0], cmd, env)) != -1)
			flag = -1;
		flag = 1;
	}
	wait(&status);
	return (flag);
}

void	minishell_exec(t_list *env, char **cmd)
{
	char	*varname;
	char	**tab_env;

	varname = cmd[0];
	tab_env = ft_list_to_tab(&env);
	if ((ft_strcmp(cmd[0], "cd")) == 0)
		ft_cd(env, cmd);
	else if ((ft_strcmp(cmd[0], "env")) == 0)
		ft_env_opt(env, cmd);
	else if ((ft_strcmp(cmd[0], "setenv")) == 0)
	{
		if ((ft_error_set_unset_env(cmd, "setenv")) == 0)
			ft_env_set(&env, cmd[1], cmd[2]);
	}
	else if ((ft_strcmp(cmd[0], "unsetenv")) == 0)
		*env = *ft_env_unset(&env, cmd);
	else if ((ft_strcmp(cmd[0], "exit")) == 0)
		ft_exit(cmd, &env);
	else if ((cmd[0][0] == '.' && cmd[0][1] == '/') || cmd[0][0] == '/')
		ft_exec(cmd, tab_env);
	else if (((cmd[0] = ft_get_path(env, cmd[0])) != NULL))
		ft_exec(cmd, tab_env);
	else if (1)
		ft_error_not_found(varname);
}

int		minishell(t_minishell *sh)
{
	t_env	*env;
	char	*line;
	char	**db_tab;
	char	**cmd;
	int		i;

	env = sh->env->content;
	i = 0;
	ft_display_prompt(sh->env);
	ft_check_signal();
	while (get_next_line(0, &line))
	{
		db_tab = ft_strsplit(line, ';');
		while (i < (ft_tab_len(db_tab)))
		{
			cmd = ft_word_to_tab(db_tab[i]);
			if (cmd[0])
				minishell_exec(sh->env, cmd);
			i++;
		}
		ft_display_prompt(sh->env);
		i = 0;
	}
	return (0);
}

int		main(int ac, char **av, char **environ)
{
	t_minishell sh;

	(void)av;
	if (ac > 1)
	{
		ft_putendl_fd("minishell cannot execute commands", 2);
		return (0);
	}
	ft_env_to_list(&(sh.env), environ);
	ft_env_set(&(sh.env), "SHLVL",
		ft_itoa((ft_atoi(ft_env_get(sh.env, "SHLVL")) + 1)));
	return (minishell(&sh));
}
