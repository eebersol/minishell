/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>
# include "../libft/includes/libft.h"
# include <signal.h>

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define BLUE	"\033[1;34m"
# define CYAN	"\033[1;36m"
# define WHITE	"\033[37m"

typedef struct	s_env
{
	char		*var;
	char		*value;
}				t_env;

typedef struct	s_minishell
{
	t_list		*env;
}				t_minishell;

void			ft_cd(t_list *list, char **cmd);
void			ft_env_set(t_list **list, char *var, char *value);
t_list			*ft_env_unset(t_list **list, char **cmd);
void			ft_env_to_list(t_list **list, char **environ);
char			*ft_env_get(t_list *list, char *var);
void			ft_env_show(t_list *list);
int				ft_error_set_unset_env(char **cmd, char *name);
int				ft_error_exit(char **cmd);
int				ft_error_cd(char **cmd);
int				ft_error_env(char **cmd);
void			ft_error_not_found(char *varname);
int				ft_exit(char **cmd, t_list **list);
int				ft_env_del(t_list **list);
void			ft_free_node(void *content, size_t size);
char			*ft_join_path(char *path, char *str);
char			*ft_get_path(t_list *env, char *cmd);
int				ft_cut_title(char *str);
char			ft_seek_wrong_opt(char *cmd);
void			ft_check_signal(void);
void			ft_env_opt(t_list *list, char **cmd);
void			ft_error_no_directory(char **cmd);
char			**ft_list_to_tab(t_list **list);
int				ft_lstlen(t_list *list);
void			minishell_exec(t_list *env, char **cmd);
void			ft_env_copy(t_list **new, t_list *list);
int				ft_create_new_list(t_list *mew_list, char **cmd, int i, int j);
void			ft_display_prompt(t_list *env);

#endif
