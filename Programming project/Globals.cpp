#define MIN (a,b) ((a) < (b) ? (a):(b))

#define MAX (a,b) ((a) < (b) ? (a):(b))

template<class TIPUS>
void Swap(TIPUS& a, TIPUS& b)
{
	TIPUS tmp;
	tmp = a;
	a = b;
	b = tmp;
}