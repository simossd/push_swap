/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:36:27 by mjabri            #+#    #+#             */
/*   Updated: 2026/01/10 16:42:37 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				index;
	int				content;
	struct s_list	*next;
}					t_list;

void				indexing(t_list *stack_a);
int					pos(t_list *stack_b);
void				algo_b(t_list **stack_a, t_list **stack_b);
void				algo_a(t_list **stack_a, int chank_n);
void				algo(t_list **stack_a);
void				list_free(t_list *list);
int					list_count(t_list *stack);
int					set_valid_2(char c);
ssize_t				ft_len(char const *str);
void				ft_exit(void);
char				**ft_free(char **s);
char				*fill_up(char const *s);
void				ra(t_list **stack_a);
void				pa(t_list **stack_a, t_list **stack_b);
void				sa(t_list **stack_a);
void				rra(t_list **stack_a);
void				sb(t_list **stack_b);
void				pb(t_list **stack_b, t_list **stack_a);
void				rb(t_list **stack_b);
void				rrb(t_list **stack_b);
int					set_check(char c);
int					set_valid(char c);
int					invalid(char const *str);
int					check_count_words(char const *str);
int					dupcheck(t_list *numbers);
t_list				*new_node(int num);
void				add_back(t_list **node_add, t_list *node_add_2, char **str);
long				ft_atoi(char *str);
char				**ft_hp(int nb);
char				**ft_split(char *s);
int					pusher(t_list *stack_a);
int					list_sort(t_list *stack_a);
void				algo_2(t_list **stack_a, int stack_count);
void				algo_trio(t_list **stack_a);
void				cuatro_algo(t_list **stack_a, t_list **stack_b);
void				algo_cinco(t_list **stack_a, t_list **stack_b);

#endif
