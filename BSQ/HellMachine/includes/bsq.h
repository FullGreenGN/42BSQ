/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:32:43 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/07 21:58:42 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define BUFFSIZE 4096

typedef struct s_rgs_data
{
	char			empty;
	char			obstacle;
	char			filler;
	int				nb_lines;
	int				nb_lines_size;
}					t_args_data;

typedef struct s_map_data
{
	int				max_size;
	int				max_i;
	int				max_j;
}					t_map_data;

char			**process_map(char *str, t_args_data data);
char			*file_to_string(const char *file_path);
char			**ft_split(char *str, char *charset);
char			*ft_strcat(char *dest, char *src);
char			*stdin_to_string(void);
int				ft_strlen(char *str);
void			ft_putstr(char *str);
void			ft_putchar(char c);
void			fill_dp(int **dp, char **lines, t_args_data data,
					t_map_data *map);
void			fill_lines(char **lines, t_args_data data, t_map_data *map);
int				ft_contain(char *str, char c);
int				nb_word(char *str, char *charset);
int				ft_atoi(const char *str, int n);
int				min(int a, int b, int c);
t_args_data		string_args(char *strn, t_args_data data);
void			clean_all(char *b_str, char **tab);
void			clean_dp(int **dp, int cols);
int				ft_check_map(char *str, t_args_data data);

#endif