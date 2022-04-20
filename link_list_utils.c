/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:35:13 by ski               #+#    #+#             */
/*   Updated: 2022/04/20 14:38:55 by ski              ###   ########.fr       */
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
}

/* ************************************************************************** */