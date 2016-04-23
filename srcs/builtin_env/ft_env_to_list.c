/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 18:56:15 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/18 18:56:16 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**ft_list_to_tab(t_list **list)
{
	t_env	*env;
	t_list	*cur;
	char	**tab_env;
	int		i;

	cur = *list;
	i = 0;
	tab_env = (char**)malloc(sizeof(char*) * ft_lstlen(*list) + 1);
	while (cur)
	{
		env = cur->content;
		if (env->var)
			tab_env[i] = ft_strdup((ft_strjoin(env->var, "=")));
		if (env->value)
			tab_env[i] = ft_strdup((ft_strjoin(tab_env[i], env->value)));
		i++;
		cur = cur->next;
	}
	tab_env[i] = NULL;
	return (tab_env);
}

void	ft_env_to_list(t_list **list, char **environ)
{
	t_env	env;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (environ[i])
	{
		j = ft_cut_title(environ[i]);
		env.var = ft_strnew(j + 1);
		ft_strncpy(env.var, environ[i], j);
		env.var[j] = 0;
		env.value = ft_strsub(environ[i], j + 1,
			ft_strlen(ft_strchr(environ[i], '=')));
		ft_lstadd_back(list, ft_lstnew(&env, sizeof(t_env)));
		i++;
	}
}
