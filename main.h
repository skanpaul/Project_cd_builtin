/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:00:42 by ski               #+#    #+#             */
/*   Updated: 2022/04/20 11:21:31 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
/* ************************************************************************** */
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
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
typedef struct s_data
{
	
}	t_data;
/* ************************************************************************** */
bool	is_parent(pid_t fk_pid);
/* ************************************************************************** */
int		pwd_builtin(void);
void	ft_putstr(char *str);
void	ft_putendl(char *str);
void	ft_putstr_fd(char *str, int fd);
/* ************************************************************************** */
void	envp_print(char **envp);
int		envp_get_size(char **envp);
char	**envp_copy(char **envp);
/* ************************************************************************** */
#endif