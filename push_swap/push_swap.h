/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:29:25 by pgorner           #+#    #+#             */
/*   Updated: 2022/12/12 19:17:28 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//				██╗  ██╗███████╗ █████╗ ██████╗ ███████╗██████╗
//				██║  ██║██╔════╝██╔══██╗██╔══██╗██╔════╝██╔══██╗
//				███████║█████╗  ███████║██║  ██║█████╗  ██████╔╝
//				██╔══██║██╔══╝  ██╔══██║██║  ██║██╔══╝  ██╔══██╗
//				██║  ██║███████╗██║  ██║██████╔╝███████╗██║  ██║
//				╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═════╝ ╚══════╝╚═╝  ╚═╝
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
//==============================================================================
//-------------------------------DEFINED_VALUES---------------------------------
//==============================================================================
//-----------------------------------FLAGS--------------------------------------
# define AB 0
# define A 1
# define B 2
# define S 4
# define P 5
# define R 6
# define RR 7
//----------------------------------RETURNS-------------------------------------
# define YES 0
# define NO 1
# define SUCESS 0
# define ERR_INVAL 1
# define SPACE ' '
//==============================================================================
//----------------------------------STRUCTS-------------------------------------
//==============================================================================
typedef struct stacks
{
	char	**a;
	char	**b;
	char	*str;
	char	**tmp;
	int		speed;
	int		prevspeed;
	int		ispeed;
	int		num;
}	t_s;

/* typedef struct info
{
	int		start;
	int		flip;
}	t_s; */
// for start: top = 0 bottom = 1
//==============================================================================
//----------------------------------PUSH_SWAP-----------------------------------
//==============================================================================
//	starts the whole program
int		main(int argc, char *argv[]);
//==============================================================================
//---------------------------------READ_INPUT-----------------------------------
//==============================================================================
//	calls the check functions
int		check_valid(int argc, char *argv[]);
//	calls the functions to take input into stack.a and allocates stack tmp and b
int		read_input(int argc, char *argv[], t_s *stacks);
//==============================================================================
//-----------------------------------VALID--------------------------------------
//==============================================================================
//	checks wether there are doubles
int		check_double(t_s *stacks);
//	checks if its a digit
int		is_digit(char check);
//	applies is_digit
int		check_digit(int argc, char *argv[]);
//	checks for all space or the case if empty
int		space_check(int argc, char *argv[]);
//	checks for negative or positive number with sign
int		negpos_check(int argc, char *argv[]);
//==============================================================================
//---------------------------------UTILS_A--------------------------------------
//==============================================================================
//	SA
void	sa(t_s *stacks);
//	PA
void	pa(t_s *stacks);
//	RA
void	ra(t_s *stacks);
//	RRA
void	rra(t_s *stacks);
//==============================================================================
//---------------------------------UTILS_B--------------------------------------
//==============================================================================
//	SB
void	sb(t_s *stacks);
//	PB
void	pb(t_s *stacks);
//	RB
void	rb(t_s *stacks);
//	RRB
void	rrb(t_s *stacks);
//==============================================================================
//---------------------------------UTILS_F--------------------------------------
//==============================================================================
//	calls sa/sb/ss
void	let_s(t_s *stacks, int flag);
//	calls ra/rb/rr
void	let_r(t_s *stacks, int flag);
//	calls rra/rrb/rrr
void	let_rr(t_s *stacks, int flag);
//	calls pa/pb
void	let_p(t_s *stacks, int flag);
//	calls the appropriate flag function
void	flags(t_s *stacks, int let, int flag);
//==============================================================================
//----------------------------------UTILS---------------------------------------
//==============================================================================
//	checks if it is a number
int		is_num(char check);
//	returns the size of the stack put in
int		size(char **count);
//	prints error message and returns error
int		ft_error(int i);
//	calls strjoin with a space to join the string
char	*join_inpt(int argc, char *argv[]);
//==============================================================================
//------------------------------CHECK_SORTED------------------------------------
//==============================================================================
//	checks if a small stack.a(size<3) is sorted or not
int		sorted(t_s *stacks);
//==============================================================================
//----------------------------------NEXTHILO------------------------------------
//==============================================================================
int	nextlowernumber(t_s *stacks, int i);
int	nexthighernumber(t_s *stacks, int i);
void	position(t_s *stacks, int i);
int	actionhilow(t_s *stacks, int i);
int	actionhilowb(t_s *stacks, int i);
//==============================================================================
//----------------------------------SORTNEW-------------------------------------
//==============================================================================
//	calls sorting by size (smaller or larger than 5)
void	sort(t_s *stacks);
void	sort_small(t_s *stacks);
//counts the number of operatiosn to get the next num
void	operations(t_s *stacks);
/* // finds out if upper or lower number closer
void	maxormin(t_s *stacks, int i); */
// finds out how many rotations to get it ot the top
void	place(t_s *stacks, int i);
int	placereturn(t_s *stacks, int i);
//==============================================================================
//----------------------------------SORT_UTILS----------------------------------
//==============================================================================
void	placeb(t_s *stacks, int i);
void	placea(t_s *stacks, int i);
int	actionreturnb(t_s *stacks, int i);
void	operationsb(t_s *stacks);
void	sortitb(t_s *stacks);
void	sortb(t_s *stacks);

int	nextlowernumberb(t_s *stacks, int i);
int	nexthighernumberb(t_s *stacks, int i);
void	positionb(t_s *stacks, int i);
int	actionhilowb(t_s *stacks, int i);

void	rotatea(t_s *stacks);

#endif
