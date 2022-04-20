/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:00:42 by ski               #+#    #+#             */
/*   Updated: 2022/04/20 20:15:11 by ski              ###   ########.fr       */
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
/* ************************************************************************** */
typedef struct s_maillon t_maillon;
/* ************************************************************************** */
typedef struct s_maillon
{
	char		*var_env;
	t_maillon	*prev;
	t_maillon	*next;
}	t_maillon;
/* ************************************************************************** */
typedef struct s_data
{
	
}	t_data;
/* ************************************************************************** */
int		pwd_builtin(void);
int		cd_builtin(char *pathname, t_maillon **ptr_head);

/* ************************************************************************** */
void	print_maillon(t_maillon **ptr_head);
void	replace_env_pwd(t_maillon **ptr_env, char *new_path);
void	replace_env_oldpwd(t_maillon **ptr_env, char *new_path);
/* ************************************************************************** */
void	envp_print(char **envp);
int		envp_get_size(char **envp);
char	**envp_copy(char **envp);
/* ************************************************************************** */
bool	is_parent(pid_t fk_pid);
/* ************************************************************************** */
#endif