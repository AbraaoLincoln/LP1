#include <iostream>

int pascal_triangle(int n, int k)
{
	if(n == 0)
	{
		return 1;
	}else
	{
		if(k == 0 or n == k)
		{
			return 1;
		}else
		{
			return pascal_triangle(n-1, k-1) + pascal_triangle(n-1,k);
		}
	}

	return -1;
}

void show_row(int n, int k)
{
	if(k == 0)
	{
		std::cout << 1 << " ";

		if(n == 0)
		{
			std::cout << "\n";
		}

	}else
	{
		if(n == k)
		{
			show_row(n, k-1);
			std::cout << 1 << std::endl;
		}else
		{	
			show_row(n, k-1);
			std::cout << pascal_triangle(n-1, k-1) + pascal_triangle(n-1,k) << " ";
		}
	}
}

void show_triangle(int n)
{
	if(n == 0)
	{
		show_row(n,n);
	}else
	{
		show_triangle(n-1);
		show_row(n,n);
	}
}

int main(void)
{
	int n{7};
	show_triangle(n);
}