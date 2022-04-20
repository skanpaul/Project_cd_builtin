/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:38:31 by ski               #+#    #+#             */
/*   Updated: 2022/04/20 16:27:43 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/* ************************************************************************** */
#define CD_NO_ERROR		0
#define CD_ERROR		-1
#define CD_MSG_ERR_NO_ARG		"cd: need a relative or absolut path"
#define CD_MSG_ERR_WRONG_DIR	"cd: no such file or directory: "
/* ************************************************************************** */
#define CHDIR_NO_ERROR	0
#define CHDIR_ERROR		-1
#define CHDIR_HOME		"/Users/ski"
/* ************************************************************************** */
int cd_builtin(char *pathname, t_maillon **ptr_head)
{
	t_maillon *temp;

	if (pathname == NULL || pathname[0] == '\0')
	{
		write(1, CD_MSG_ERR_NO_ARG, ft_strlen(CD_MSG_ERR_NO_ARG));
		write(1, "\n", 1);
		return (CD_ERROR);
	}
	// si: [cd . ]
	// alors:
	//		1) $OLDPWD = $PWD


	// si: [cd .. ]
	// alors: 
	//		1) $OLDPWD = $PWD
	//		2) $PWD = parent directory
	//		3) cwd = parent directory 

	// si: 
	return (CD_NO_ERROR);
}

/* ************************************************************************** */
// t_maillon *get_maillon(char *var_name)