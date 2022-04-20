/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:35:13 by ski               #+#    #+#             */
/*   Updated: 2022/04/20 17:35:19 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/* ************************************************************************** */
void print_maillon(t_maillon **ptr_head)
{
	t_maillon *temp;

	temp = *ptr_head;

	while(temp != NULL)
	{
		printf("%s\n", temp->var_env);
		temp = temp->next;		
	}
	printf("\n");
}

/* ************************************************************************** */
void replace_pwd(t_maillon **ptr_env, char *new_pwd_path)
{
	t_maillon **env_pwd;

	env_pwd = get_env_var_ptr(ptr_env, "PWD=");
	if (*env_pwd == NULL)
	{
		printf("[ PWD= ] n'existe pas\n");	
	}
	else
	{
		free((*env_pwd)->var_env);
		(*env_pwd)->var_env = ft_strdup("SALUT XXXXXXX");
	}
	
	
}

/* ************************************************************************** */
t_maillon **get_env_var_ptr(t_maillon **ptr_env, char *wished_var)
{
	t_maillon **temp;

	temp = ptr_env;

	while (*temp != NULL)
	{
		if(ft_strncmp((*temp)->var_env, wished_var, ft_strlen(wished_var)) == 0)
		{
			return (temp);
		}
		temp = &(*temp)->next;
	}
	
	return (NULL);
}

/* ************************************************************************** */