#include <limits.h>

static unsigned int	lfsr113_Bits (void)
{
	static unsigned int z1 = 12345;
	static unsigned int z2 = 12345;
	static unsigned int z3 = 12345;
	static unsigned int z4 = 12345;
	unsigned int b;

	b  = ((z1 << 6) ^ z1) >> 13;
	z1 = ((z1 & 4294967294U) << 18) ^ b;
	b  = ((z2 << 2) ^ z2) >> 27; 
	z2 = ((z2 & 4294967288U) << 2) ^ b;
	b  = ((z3 << 13) ^ z3) >> 21;
	z3 = ((z3 & 4294967280U) << 7) ^ b;
	b  = ((z4 << 3) ^ z4) >> 12;
	z4 = ((z4 & 4294967168U) << 13) ^ b;
	return (z1 ^ z2 ^ z3 ^ z4);
}

unsigned int	uint_random_nbr(void)
{
	return (lfsr113_Bits());
}

double	pseudo_random(void)
{
	return (uint_random_nbr() / UINT_MAX);
}
