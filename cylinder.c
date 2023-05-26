int	cylinder_point(t_vec4d *p, t_element *cylinder)
{
	return (p.x * p.x + py * py == (cylinder->diameter / 2) * (cylinder->diameter / 2))
}
