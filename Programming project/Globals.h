#define MIN(a, b) (a<b ? a:b)

#define MAX(a, b) (a>b ? a:b)

#ifndef __FACT__
#define __FACT__
unsigned int Fact(unsigned int value)
{
	if (value > 1){ return (value * Fact(value - 1)); }
	return 1;
}

#endif //__FACT__

#ifndef __SWAP__
#define __SWAP__

template<class TIPUS>
void Swap(TIPUS& a, TIPUS& b)
{
	TIPUS tmp = a;
	a = b;
	b = tmp;
}

#endif //__SWAP__