#define MIN(a, b) (a<b ? a:b)

#define MAX(a, b) (a>b ? a:b)

#ifndef __SWAP__
#define __SWAP__

template<class TIPUS>
void Swap(TIPUS& a, TIPUS& b)
{
	TIPUS tmp = a;
	a = b;
	b = tmp;
}

#endif