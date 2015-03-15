template<class TIPUS>
void Swap(TIPUS& a, TIPUS& b)
{
	TIPUS tmp;
	tmp = a;
	a = b;
	b = tmp;
}