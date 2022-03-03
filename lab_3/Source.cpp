#include"RingBuffer.h"
#include<string>
#include<vector>
#include"Algorithms.h"
#include<iostream>


bool predicate(int element)
{
	if (element > 0)
		return true;
	else
		return false;
}

int main()
{

	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	std::vector<int>::iterator it_1 = vec.begin();
	std::vector<int>::iterator it_2 = vec.end() - 1;


	std::cout << algo_space::all_of(it_1, it_2, predicate) << std::endl;



	/*setlocale(LC_ALL, "Russian");

	int m = 5;
	RingBuffer<std::string> r(m);
	r.add_front("Привет ");
	r.add_back("меня ");
	r.add_back("зовут ");
	r.add_back("Вадим ");
	r.add_back("! ");


	for (int i = 0; i < m; i++)
	{
		std::cout << r[i].data;
	}
	std::cout << std::endl;


	r.resize(m - 2);
	r.add_back("Ура ");

	for (int i = 0; i < m - 2; i++)
	{
		std::cout << r[i].data;
	}
	std::cout << std::endl;


	iterator <BufferElement<std::string>> it;
	it = &r[2];
	std::cout << (*it).data;

	r.remove_front();*/

	return 0;
}