/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fullgreen <fullgreen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:32:43 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/07 08:34:30 by fullgreen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define BUFFSIZE 4096

typedef struct s_rgs_data
{
	char			empty; // .
	char			obstacle; // O
	char			filler; // x
	int				nb_lines; // 10
	int				nb_lines_size; // 2
}					t_args_data;

typedef struct s_map_data
{
	int				max_size;
	int				max_i;
	int				max_j;
}					t_map_data;

typedef struct s_result_pos
{
	int		start[2];
	int		end[2];
}					t_result_pos;

typedef struct s_bsq
{
	int		i;
	int		count;
	int		tmp;
	int		tmpwidth;
	int		tmplenght;
	int		len;
	int		wid;
	int		posx;
	int		posy;
}				t_bsq;

char			**process_map(char *str, t_args_data data);
char			*ft_strjoin(char **map);
char			*file_to_string(const char *file_path);
char			**ft_split(char *str, char *charset);
char			*ft_strcat(char *dest, char *src);
char			*stdin_to_string(void);
void			ft_bufftotab(char *buff, char **tab, int a, int b);
void			ft_create_tab(char *buff);
void			ft_test_argv(int argc);
void			ft_find_file(int fd);
void			ft_test_file(char *tab);
void			ft_test_char(char c);
void			ft_empty_file(char c);
void			ft_test_read(int read);
void			ft_zero(char *buff, int size);
void			ft_putstr(char *str);
void			ft_putchar(char c);
int				ft_contain(char *str, char c);
int				nb_word(char *str, char *charset);
int				ft_atoi(const char *str);
int				min(int a, int b, int c);
int				ft_strlen(char *str);
int				ft_strlenbn(char *str);
int				ft_strnbline(char *str);
void			redirect(char **tab, int lenght, int width);

t_args_data		string_args(char *strn, t_args_data data);

#endif