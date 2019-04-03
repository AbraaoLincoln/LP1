#include<iostream>
#include<cstring>

using byte = unsigned char;

void rev(void *first, void *last, size_t sz)
{
	byte *pf = (byte *)first;
	byte *pl = (byte *)last;
	byte aux[sz];
	int n_f{0}, n_l{(pl - pf)/sz};
	n_l--;
	pl = pf;

	while(n_f < n_l)
	{
		std::memcpy(aux, pl+(n_l*sz), sz);
		std::memcpy(pl+(n_l*sz), pf+(n_f*sz), sz);
		std::memcpy(pf+(n_f*sz), aux, sz);
		n_f++;
		n_l--;
	}
}

int main(void)
{	/*
	int A[]{1,2,3,4,5};
	rev(&A[0], &A[4], sizeof(int));
	/*
	float A[]{1.3,2.5,3.7,4.9,5.3};
	rev(&A[0], &A[4], sizeof(float));
	*/
	char A[]{'a','b','c','d','e'};
	rev(std::begin(A), std::end(A), sizeof(char));
	for(auto c : A)
	{
		std::cout << c << " ";
	}
	std::cout << std::endl;
	return 0;
}