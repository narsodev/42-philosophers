/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:35:52 by ngonzale          #+#    #+#             */
/*   Updated: 2023/03/05 13:54:33 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_data {
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_required;
	pthread_mutex_t	mutex_write;
	pthread_mutex_t	mutex_eaten;
	int				eaten;
	pthread_mutex_t	mutex_dead;
	int				dead;
	int				start_time;
	t_list			*philos;
}			t_data;

typedef struct s_philo {
	pthread_t			thread;
	int					last_meal;
	int					meals_eaten;
	int					n;
	pthread_mutex_t		fork;
	pthread_mutex_t		mutex_meals;
	t_data				*data;
}			t_philo;

// Create
t_data	*ft_create_data(int argc, char *argv[]);

// Free
void	ft_free_philo(void *content);
void	ft_free_data(t_data *data);

// Routine
void	*routine(void *arg);

// Routine Utils
void	ft_print_action(t_philo *philo, char *str);

// Checks
int		ft_check_meals(t_data *data);
int		ft_check_dead(t_data *data);

// Start
int		ft_start_philos(t_data *data);

// Utils
int		ft_get_time(void);
void	ft_sleep(int milliseconds);
void	ft_lstiter(t_list *lst, void (*f)(void *));
int		ft_printf(const char *str, ...);
void	*ft_calloc(size_t count, size_t size);
void	ft_putstr_fd(char *s, int fd);
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstcreate(int n, void *(*f)(int), void (*del)(void *));
int		ft_atoic(const char *str, int *error);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
void	ft_putchar_fd(char c, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_c_to_str(char c);
char	*ft_uitoa_base(unsigned int n, char *base);
char	*ft_ulltoa_base(unsigned long long n, char *base);

// Printf
typedef struct s_flags {
	int	plus;
	int	space;
	int	hash;
	int	dot;
	int	precision;
	int	minus;
	int	zero;
	int	width;
}			t_flags;

char	*ft_flag_plus(char *str);
char	*ft_flag_space(char *str);
char	*ft_flag_hash(char *str, char type);
char	*ft_flag_width(char *str, t_flags flags);
char	*ft_flag_precision(char *str, char type, int precision);
char	ft_find_type(char c);
char	*ft_switch_types(char type, va_list ap);

#endif
