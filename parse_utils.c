#include "minirt.h"

/*return -1 if no digit*/
int	ft_parse_double(char *str, size_t *pos, double *value)
{
	ft_run_is_space(str, pos);
	*value = ft_atof(str + *pos);
	return (ft_run_atof(str, pos));
}

/*TODO max of value 255 if greater truncated or error up to you*/
int	ft_parse_unsigned_char(char *str, size_t *pos, unsigned char *value)
{
	ft_run_is_space(str, pos);
	*value = (unsigned char)ft_atoi(str + *pos);
	return (ft_run_atoi(str, pos));
}

int	ft_parse_comma(char *str, size_t *pos)
{
	ft_run_is_space(str, pos);
	if ((str[*pos] != ','))
		return (-1);
	pos[0]++;
	return (0);
}

int	ft_parse_end(char *str, size_t pos)
{
	ft_run_is_space(str, &pos);
	if (str[pos] != '\0')
		return (-1);
	return (0);
}

int	ft_parse_colour(char *str, size_t *pos, t_colour *colour)
{
	if (ft_parse_unsigned_char(str, pos, &colour->red))
		return (-1);
	if (ft_parse_comma(str, pos))
		return (-1);
	if (ft_parse_unsigned_char(str, pos, &colour->green))
		return (-1);
	if (ft_parse_comma(str, pos))
		return (-1);
	if (ft_parse_unsigned_char(str, pos, &colour->blue))
		return (-1);
	return (0);
}

int	ft_parse_vec3d(char *str, size_t *pos, t_vec3d *vector)
{
	if (ft_parse_double(str, pos, &vector->x))
		return (-1);
	if (ft_parse_comma(str, pos))
		return (-1);
	if (ft_parse_double(str, pos, &vector->y))
		return (-1);
	if (ft_parse_comma(str, pos))
		return (-1);
	if (ft_parse_double(str, pos, &vector->z))
		return (-1);
	return (0);
}
