/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:36:27 by mjabri            #+#    #+#             */
/*   Updated: 2026/01/15 18:16:17 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	int				index;
	int				content;
	struct s_list	*next;
}					t_list;

void				indexing(t_list *stack_a);
int					pos(t_list *stack_b);
int					algo(t_list **stack_a);
void				list_free(t_list *list);
int					list_count(t_list *stack);
int					set_valid_2(char c);
ssize_t				ft_len(char const *str);
void				ft_exit(void);
char				**ft_free(char **s);
char				*fill_up(char const *s);
int					ra(t_list **stack_a);
int					pa(t_list **stack_a, t_list **stack_b);
int					sa(t_list **stack_a);
int					rra(t_list **stack_a);
int					sb(t_list **stack_b);
int					pb(t_list **stack_b, t_list **stack_a);
int					rb(t_list **stack_b);
int					rrb(t_list **stack_b);
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
void				*ft_calloc(size_t nmemb);
size_t				ft_strnlen(char *str);
size_t				new_line_search(char *str);
char				*ft_strnjoin(char *src1, char *src2);
char				*ft_line(char *str);
char				*get_next_line(int fd);
void				ko(void);
void				ok(void);
int					instructions(t_list **stack_a, t_list **stack_b, char *str);
int					apply_a(t_list **stack_a, t_list **stack_b, char *str);
int					ft_strcmp(char *str1, char *str2);
int					apply_b(t_list **stack_a, t_list **stack_b, char *str);
int					aorb(char *str);

#endif
