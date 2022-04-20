/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:59:47 by ski               #+#    #+#             */
/*   Updated: 2022/04/20 14:41:15 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/* ************************************************************************** */
#define		SAME_STRING		0
/* ************************************************************************** */
#define		MSG_A		"AAA=salut biscuit"
#define		MSG_PWD		"PWD=/Users/ski/Documents/8_Experimentation/Project_cd_builtin"
#define		MSG_B		"BBB=il faut beau aujourd'hui"
#define		MSG_OLDPWD	"OLDPWD=/Users/ski/Documents/8_Experimentation/Project_cd_builtin"
/* ************************************************************************** */
int main (int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	char *str_pwd;
	char *str_pwd_old;
	
	t_maillon *ptr_head;
	t_maillon maillon_a;
	t_maillon maillon_pwd;
	t_maillon maillon_b;
	t_maillon maillon_oldpwd;
	
	// ------------------------
	ptr_head = &maillon_a;
	
	maillon_a.prev = NULL;
	maillon_a.next = &maillon_pwd;

	maillon_pwd.prev = &maillon_a;
	maillon_pwd.next = &maillon_b;

	maillon_b.prev = &maillon_pwd;
	maillon_b.next = &maillon_oldpwd;
	
	maillon_oldpwd.prev = &maillon_b;
	maillon_oldpwd.next = NULL;
	// ------------------------

	maillon_a.var_env = strdup(MSG_A);
	maillon_pwd.var_env =  strdup(MSG_PWD);
	maillon_b.var_env =  strdup(MSG_B);
	maillon_oldpwd.var_env =  strdup(MSG_OLDPWD);

	print_maillon(&ptr_head);

	

	

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