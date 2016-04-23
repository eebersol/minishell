/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 18:33:50 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/14 18:33:51 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		ft_env_del(t_list **list)
{
	t_list	*cur;
	t_env	*env;

	cur = *list;
	env = cur->content;
	while (cur)
	{
		env = cur->content;
		ft_strdel(&(env->var));
		ft_strdel(&(env->value));
		free(env);
		cur = cur->next;
	}
	return (0);
}

int		ft_exit(char **cmd, t_list **list)
{
	int i;

	i = 0;
	if ((ft_error_exit(cmd, cmd[1])) == 0)
	{
		i = (cmd && cmd[1] ? ft_atoi(cmd[1]) : 0);
		ft_tab_free(&cmd);
		ft_env_del(list);
		exit(i);
	}
	return (0);
}
