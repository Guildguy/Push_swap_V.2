/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleite-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:20:49 by fleite-j          #+#    #+#             */
/*   Updated: 2025/02/13 17:20:52 by fleite-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_node
{
	int				n;
	int				pos;
	int				cost;
	bool			shortest;
	bool			upper_part;
	struct s_node	*target;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

//libft
long	ft_atol(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

//printf
////utils_print
int		ft_islower(int c);
int		ft_int_len(int n);
char	*ft_itoa(int n);
int		ft_uns_int_len(unsigned int n);
char	*ft_uns_itoa(unsigned int n);
////num_print
int		print_int(int n);
int		print_uns_int(unsigned int n);
int		hex_len(unsigned int n);
void	hex_write(unsigned int n, char format);
int		print_hex(unsigned int n, char format);
////char_print
int		print_chr(char c);
int		print_str(char *str);
int		ptr_len(uintptr_t ptr);
void	ptr_write(uintptr_t ptr);
int		print_ptr(void *pointer);
////printf
int		format_specifier(va_list arg, const char format);
int		ft_printf(const char *str, ...);

//moves
////moves_utils
void	set_top_a(t_node **stack, t_node *top);
void	set_top_b(t_node **stack, t_node *top);
void	rotate_a_b(t_node **stack_a, t_node **stack_b, t_node *shortest);
void	reverse_a_b(t_node **stack_a, t_node **stack_b, t_node *shortest);
////push
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_b, t_node **stack_a);
////reverse
void	rra(t_node **stack);
void	rrb(t_node **stack);
void	rrr(t_node **stack_a, t_node **stack_b);
////rotate
void	ra(t_node **stack);
void	rb(t_node **stack);
void	rr(t_node **stack_a, t_node **stack_b);
////swap
void	sa(t_node **stack);
void	sb(t_node **stack);
void	ss(t_node **stack_a, t_node **stack_b);

//sorter
////prep_a
void	set_position(t_node *stack);
void	prepare_a(t_node *stack_a, t_node *stack_b);
////prep_b
void	prepare_b(t_node *stack_a, t_node *stack_b);
////small_sort
void	small_sort(t_node **stack);
////full_sort
void	full_sort(t_node **stack_a, t_node **stack_b);

//main
////ft_lstlast
t_node	*ft_lstlast(t_node *lst);
////ft_lstsize
int		ft_lstsize(t_node *lst);
////p_split
void	free_matrix(char *av[]);
char	**push_split(const char *str, char separator);
////push_utils
void	deallocate_node(t_node **root);
bool	stack_done(t_node *stack);
t_node	*find_smallest(t_node *stack);
t_node	*find_largest(t_node *stack);
t_node	*get_shortest(t_node *stack);

//populate stack
void	populate_stack(t_node **stack, char **ptr, bool array);

#endif
