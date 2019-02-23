#include <iostream>
std::string next_flight(std::string *flights, std::string *start);

int main(void)
{
	std::string flights[]{"A", "B", "A", "C", "B", "C", "C", "A"}, flights_end[8];
	std::string start{"A"};
	int count{1};

	flights_end[0] = start;

	for(int i{0}; i < 4; i++)
	{
		flights_end[count] = next_flight( flights, &start);
		start = flights_end[count];
		count++;
	}
	flights_end[count] = "\0";
	count = 0;
	while(flights_end[count] != "\0")
	{
		std::cout << flights_end[count] << ", " ;
		count++;
	}

	std::cout << std::endl;
	return 0;
}
//Retorna o melhor destino de acordo com a origem.
std::string next_flight(std::string *flights, std::string *start){
	std::string next{"N"};
	int index{0};

	for(int i{0}; i < 8; i += 2)
	{
		if(flights[i] == *start)
		{
			next = flights[i + 1];
			break;
		}
	}

	for(int i{0}; i < 8; i += 2)
	{
		if(flights[i] == *start)
		{
			if(flights[i + 1] <= next)
			{
				next = flights[i + 1];
				index = i;
			}
		}
	}

	flights[index] = "\0";
	return next;
}

