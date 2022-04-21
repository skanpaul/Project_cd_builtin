/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:59:47 by ski               #+#    #+#             */
/*   Updated: 2022/04/21 15:40:56 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
#define		NAME_A		"AAA"
#define		CONTENT_A	"_________________________________________________________"

#define		NAME_PWD	"PWD"
#define		CONTENT_PWD	"/Users/ski/Documents/8_Experimentation/Project_cd_builtin"

#define		NAME_B		"BBB"
#define		CONTENT_B	"_________________________________________________________"

#define		NAME_OLDPWD		"OLDPWD"
#define		CONTENT_OLDPWD	"/Users/ski/Documents/8_Experimentation"
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
	t_env *ptr_head;
	t_env maillon_a;
	t_env maillon_pwd;
	t_env maillon_b;
	t_env maillon_oldpwd;	
	// ---------------------------- lier les maillons
	ptr_head = &maillon_a;	
	maillon_a.next = &maillon_pwd;
	maillon_pwd.next = &maillon_b;
	maillon_b.next = &maillon_oldpwd;
	maillon_oldpwd.next = NULL;
	// -------------------------- remplir les maillon
	maillon_a.name = strdup(NAME_A);
	maillon_a.data = strdup(CONTENT_A);
	
	maillon_pwd.name =  strdup(NAME_PWD);
	maillon_pwd.data =  strdup(CONTENT_PWD);
	
	maillon_b.name =  strdup(NAME_B);
	maillon_b.data =  strdup(CONTENT_B);
	
	maillon_oldpwd.name =  strdup(NAME_OLDPWD);
	maillon_oldpwd.data =  strdup(CONTENT_OLDPWD);
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