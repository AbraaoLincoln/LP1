#include <iostream>
std::string next_flight(std::string flights[], std::string start, int size);
int erase(std::string x[], std::string v, int size);

int main(void)
{
	std::string flights[]{"A", "B", "A", "C", "B", "C", "C", "A"}, flights_end[8];
	std::string start{"A"};
	int count{1}, size{sizeof(flights)/sizeof(*flights)};
	
	flights_end[0] = start;

	for(int i{0}; i < size/2; i++)
	{
		flights_end[count] = next_flight(flights, start, size);
		flights[erase(flights, start, size)] = '\0';
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
std::string next_flight(std::string flights[], std::string start, int size){
	std::string next{"N"};

	for(int i{0}; i < size; i += 2)
	{
		if(flights[i] == start)
		{
			next = flights[i + 1];
			break;
		}
	}

	for(int i{0}; i < size; i += 2)
	{
		if(flights[i] == start)
		{
			if(flights[i + 1] < next)
			{
				next = flights[i + 1];
			}
		}
	}
	return next;
}
//Retorna o indice do voo de origem a ser apagado no vetor flights, para que nao atrapalhe na proxima busca.
int erase(std::string flights[], std::string start, int size)
{
	std::string next{"N"};
	int index{0};

	for(int i{0}; i < size; i += 2)
	{
		if(flights[i] == start)
		{
			next = flights[i + 1];
			break;
		}
	}

	for(int i{0}; i < size; i += 2)
	{
		if(flights[i] == start)
		{
			if(flights[i + 1] <= next)
			{
				next = flights[i + 1];
				index = i;
			}
		}
	}
	return index;
}
