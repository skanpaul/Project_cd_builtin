/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:38:31 by ski               #+#    #+#             */
/*   Updated: 2022/04/20 19:30:54 by ski              ###   ########.fr       */
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
static int manage_error(void);
static void imprime_avant(char *pathname, t_maillon **ptr_env);
static void imprime_apres(char *pathname, t_maillon **ptr_env);

/* ************************************************************************** */
int cd_builtin(char *pathname, t_maillon **ptr_env)
{
	t_maillon *temp;
	char cwd[4096];
	char oldcwd[4096];
	
	printf("====================== AVANT ============================\n");
	print_maillon(ptr_env);
	printf("\n");
	// cd [vide] --------------------------------------------------
	if (pathname == NULL || pathname[0] == '\0')
	{
		write(1, CD_MSG_ERR_NO_ARG, ft_strlen(CD_MSG_ERR_NO_ARG));
		write(1, "\n", 1);
		write(1, "\n", 1);
		return (CD_ERROR);
	}
	// ---------------------------------------------------------------
	// cd [.] (avec SIMPLE point)  -----------------------------------
	//		1)$OLDPWD = $PWD	
	// ---------------------------------------------------------------
	else if (ft_strncmp(pathname, ".", 2)  == 0)
	{
		if (chdir(pathname) == CHDIR_ERROR)
			return (manage_error());
			
		if(getcwd(cwd, 4096) == NULL)
			return(manage_error());
		replace_env_oldpwd(ptr_env, cwd);
	}

	// ---------------------------------------------------------------
	// cd [..] (avec DOUBLE point) -----------------------------------
	//		1) $OLDPWD = $PWD
	//		2) $PWD = parent directory
	//		3) cwd = parent directory 
	// ---------------------------------------------------------------
	// else if (ft_strncmp(pathname, "..", 3)  == 0)
	else
	{
		if(getcwd(oldcwd, 4096) == NULL)
			return(manage_error());
			
		if (chdir(pathname) == CHDIR_ERROR)
			return (manage_error());
			
		if(getcwd(cwd, 4096) == NULL)
			return(manage_error());
		
		replace_env_oldpwd(ptr_env, oldcwd);
		replace_env_pwd(ptr_env, cwd);
	}

	// ---------------------------------------------------------------
	printf("======================= APRES ===========================\n");
	print_maillon(ptr_env);
	printf("\n");
	// ---------------------------------------------------------------
	return (CD_NO_ERROR);
}

/* ************************************************************************** */
static int manage_error(void)
{
	perror(NULL);
	printf("\n");
	return (CD_ERROR);
}

/* ************************************************************************** */
static void imprime_avant(char *pathname, t_maillon **ptr_env)
{
	char *str_pwd;
	char *str_pwd_old;
	
	printf("====================== AVANT ============================\n");
	printf("Le path désiré: \n\t\t[ %s ]\n", pathname);
	printf("\n");
	printf("=========================================================\n");
	printf("CWD:\n");
	printf("\n");
	pwd_builtin();
	printf("\n");
	
	printf("=========================================================\n");
	str_pwd = getenv("PWD");
	str_pwd_old = getenv("OLDPWD");	
	printf("PWD   : [ %s ]\n", str_pwd);
	printf("OLDPWD: [ %s ]\n", str_pwd_old);
	printf("\n");
	printf("\n");
	
}
/* ************************************************************************** */
static void imprime_apres(char *pathname, t_maillon **ptr_env)
{
	char *str_pwd;
	char *str_pwd_old;
	
	printf("======================= APRES ===========================\n");
	printf("chdir was executed\n");
	if(chdir(pathname) == -1)
		{
			printf("chdir got an ERROR\n");
			perror(NULL);
			printf("chdir got an ERROR\n");
			return;				
		}
	printf("\n");
	printf("CWD:\n");
	printf("\n");
	pwd_builtin();
	printf("\n");
	printf("=========================================================\n");
	str_pwd = getenv("PWD");
	str_pwd_old = getenv("OLDPWD");	
	printf("PWD   : [ %s ]\n", str_pwd);
	printf("OLDPWD: [ %s ]\n", str_pwd_old);
	printf("\n");
	printf("=========================================================\n");
	printf("\n");
	printf("\n");
	printf("\n");
	
}
/* ************************************************************************** */