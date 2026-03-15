#include "../header/PmergeMe.hpp"

#include <cstdlib>
#include <vector>

int main(int argc, char ** argv)
{

	PmergeMe	me;
	std::vector<unsigned int>	vec;
	if (argc < 2)
		return 1;
	for (int i = 1; i < argc; i++)
	{
		vec.push_back(strtod(argv[i], NULL));
	}
	me.merge_insert_sort(vec, 1);
	//for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it ++) {
	//	std::cout << *it << " ";
	//}
	//std::cout << std::endl;
}