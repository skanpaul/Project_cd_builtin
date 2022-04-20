/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:04:25 by ski               #+#    #+#             */
/*   Updated: 2022/04/20 10:26:16 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
void envp_print(char **envp)
{
	int i;

	i = 0;
	while (envp[i] != NULL)
	{
		// printf("%s\n", envp[i]);
		write(1, envp[i], strlen(envp[i]));
		write(1, "\n", 1);
		i++;
	}
}

/* ************************************************************************** */
int envp_get_size(char **envp)
{
	int i;

	i = 0;
	while (envp[i] != NULL)
	{
		i++;
	}
	return (i);
}

/* ************************************************************************** */
char **envp_copy(char **envp)
{
	int i;
	int envp_size;
	char *var_mirror;
	char **mirror;

	mirror = NULL;
	var_mirror = NULL;

	envp_size = envp_get_size(envp);
	mirror = malloc(envp_size + 1 * sizeof(char *));
	if (mirror == NULL)
		return (NULL);
	mirror[envp_size] = NULL; 
	
	i = 0;
	while (envp[i] != NULL)
	{
		var_mirror = strdup(envp[i]);
		mirror[i] = var_mirror;
		i++;
	}
	
	return (mirror);
}

/* ************************************************************************** */