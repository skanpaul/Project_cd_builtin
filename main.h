/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:00:42 by ski               #+#    #+#             */
/*   Updated: 2022/04/21 15:44:10 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
/* ************************************************************************** */
# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <string.h>
/* ************************************************************************** */
# include <signal.h>
# include <readline/history.h>
# include <readline/readline.h>
/* ************************************************************************** */
# define NO_ERROR		0
# define ERROR			1
/* ************************************************************************** */
# define FORK_CHILD		0
# define FORK_ERROR		-1

#define CD_NO_ERROR		0
#define CD_ERROR		-1
#define CD_MSG_ERR_NO_ARG		"cd: need a relative or absolut path"
/* ************************************************************************** */
#define CHDIR_NO_ERROR	0
#define CHDIR_ERROR		-1
/* ************************************************************************** */
#define MSG_ERR_GETCWD	"getcwd() "

#define CWD_BUF_SIZE	4096

/* ************************************************************************** */
typedef struct	s_env
{
	char			*name;
	char			*data;
	struct s_env	*next;
}	t_env;
/* ************************************************************************** */
typedef struct s_data
{
	
}	t_data;
/* ************************************************************************** */
int		pwd_builtin(void);
int		cd_builtin(char *pathname, t_env **ptr_head);

/* ************************************************************************** */
void	print_maillon(t_env **ptr_head);
void	replace_env_pwd(t_env **ptr_env, char *new_path);
void	replace_env_oldpwd(t_env **ptr_env, char *new_path);
/* ************************************************************************** */
void	envp_print(char **envp);
int		envp_get_size(char **envp);
char	**envp_copy(char **envp);
/* ************************************************************************** */
bool	is_parent(pid_t fk_pid);
/* ************************************************************************** */
#endif