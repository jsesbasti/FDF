/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:06:39 by jsebasti          #+#    #+#             */
/*   Updated: 2022/10/09 22:06:34 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(char const *s, ...);
int		ft_print_char(char const c, int count);
int		ft_print_str(char const *s, int count);
int		ft_print_digits(int n, int count);
int		ft_print_pointers(void *ptr, int count);
int		ft_print_unsigned(unsigned int n, int count);
int		ft_print_hexa_low(unsigned int hx, int count);
int		ft_print_hexa_up(unsigned int hx, int count);

#endif