/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fullgreen <fullgreen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:32:43 by fullgreen         #+#    #+#             */
/*   Updated: 2024/08/06 14:28:39 by fullgreen        ###   ########.fr       */
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
	char			**map;
	int				nb_lines;
	int				nb_cols;
}					t_map_data;

typedef struct s_result_pos
{
	int		start[2];
	int		end[2];
}					t_result_pos;

char			**process_map(char *map);
char			*ft_strjoin(char **map);
char			*file_to_string(const char *file_path);
char			**ft_split(char *str, char *charset);
char			*ft_strcat(char *dest, char *src);
int				ft_strlen(char *str);
int				overwrite_file_with_string(const char *file_path,
					char *file_content);
int				nb_word(char *str, char *charset);
int				ft_atoi(const char *str);
int				min(int a, int b, int c);
t_args_data		string_args(char *strn, t_args_data data);

#endif