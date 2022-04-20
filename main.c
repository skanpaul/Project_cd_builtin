/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:59:47 by ski               #+#    #+#             */
/*   Updated: 2022/04/20 19:48:51 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/* ************************************************************************** */
#define		SAME_STRING		0
/* ************************************************************************** */
#define		MSG_A		"AAA=_________________________________________________________"
#define		MSG_PWD		"PWD=/Users/ski/Documents/8_Experimentation/Project_cd_builtin"
#define		MSG_B		"BBB=_________________________________________________________"
#define		MSG_OLDPWD	"OLDPWD=/Users/ski/Documents/8_Experimentation"
/* ************************************************************************** */
int main (int argc, char **argv, char **envp)
{
	// --------------------------------------------- 
	(void)argc;
	(void)argv;
	// --------------------------------------------- 
	char *str_pwd;
	char *str_pwd_old;	
	// // -------------------------- creation maillon	
	t_maillon *ptr_head;
	t_maillon maillon_a;
	t_maillon maillon_pwd;
	t_maillon maillon_b;
	t_maillon maillon_oldpwd;	
	// ---------------------------- lier les maillons
	ptr_head = &maillon_a;	
	maillon_a.prev = NULL;
	maillon_a.next = &maillon_pwd;
	maillon_pwd.prev = &maillon_a;
	maillon_pwd.next = &maillon_b;
	maillon_b.prev = &maillon_pwd;
	maillon_b.next = &maillon_oldpwd;	
	maillon_oldpwd.prev = &maillon_b;
	maillon_oldpwd.next = NULL;
	// -------------------------- remplir les maillon
	maillon_a.var_env = strdup(MSG_A);
	maillon_pwd.var_env =  strdup(MSG_PWD);
	maillon_b.var_env =  strdup(MSG_B);
	maillon_oldpwd.var_env =  strdup(MSG_OLDPWD);
	// ------------------------------------------------------- 

	printf("====================== AVANT ============================\n");
	print_maillon(&ptr_head);
	printf("\n");

	char *pathname;
	pathname = argv[1];
	cd_builtin(pathname, &ptr_head);
	
	printf("======================= APRES ===========================\n");
	print_maillon(&ptr_head);
	printf("\n");
	
	// replace_env_pwd(&ptr_head, "ZOMBIE");
	// replace_env_oldpwd(&ptr_head, "BANANE");
	// print_maillon(&ptr_head);
	// printf("\n");
	// printf("\n");		
	// ---------------------------------------------
	return (0);
}

/* ************************************************************************** */