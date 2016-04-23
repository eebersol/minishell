/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 18:56:04 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/18 18:56:07 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void		ft_match_node(t_list *cur, t_list **list, char **cmd, int j)
{
	t_env	*env;
	int		i;

	i = 0;
	while (cur)
	{
		env = cur->content;
		if (ft_strcmp(env->var, cmd[j]) == 0)
			ft_lstdel_at(list, i, &ft_free_node);
		cur = cur->next;
		i++;
	}
}

void			ft_env_unset(t_list **list, char **cmd)
{
	t_list	*cur;
	t_list	*tmp;
	int		j;

	j = 1;
	if ((ft_error_set_unset_env(cmd, "unsetenv")) == 0)
	{
		cur = *list;
		while (cmd[j])
		{
			tmp = NULL;
			ft_match_node(cur, list, cmd, j);
			cur = *list;
			if (cmd[j + 1] == NULL)
				break ;
			j++;
		}
	}
}
