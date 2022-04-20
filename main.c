/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:59:47 by ski               #+#    #+#             */
/*   Updated: 2022/04/20 12:01:24 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/* ************************************************************************** */
#define		SAME_STRING		0
/* ************************************************************************** */
/* ************************************************************************** */
int main (int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	char *str_pwd;
	char *str_pwd_old;

	char *cd_path = "/Users/ski/Documents/8_Experimentation";
	
	// str_pwd = getenv("PWD");
	// str_pwd_old = getenv("OLDPWD");	
	// ft_putstr("-- PWD ----- > "); ft_putendl(str_pwd);
	// ft_putstr("-- PWDOLD -- > "); ft_putendl(str_pwd_old);
	// ft_putendl("pwd_buildin: ");
	// pwd_builtin();
	// printf("\n");
	// printf("\n");


	// if(chdir(cd_path) == -1)
	// 	{
	// 		printf("chdir got an ERROR\n");
	// 		return (1);				
	// 	}
	// printf("chdir was executed\n");
	// sleep(1);
	// str_pwd = getenv("PWD");
	// str_pwd_old = getenv("OLDPWD");	
	// printf("-- PWD ----- > %s\n", str_pwd);
	// printf("-- PWDOLD -- > %s\n", str_pwd_old);
	// printf("pwd_buildin: \n");
	// pwd_builtin();
	// printf("\n");
	// printf("\n");
	// envp_print(envp);


	
		
	return (0);
}

/* ************************************************************************** */