int	is_plane_point(t_vec4d *p, t_element *plane)
{
	t_vec4d	pminusq;

	pminusq = p - plane->coords;
	return (plane->orientation_vector * pminusq == 0);
}
