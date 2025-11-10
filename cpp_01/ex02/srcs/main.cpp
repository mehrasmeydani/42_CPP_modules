#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	/********************************************************************************************************/
	/*	a reference cannot be reasigned and should be assigned when being declared (similar to constants)	*/
	/*	reference is also used when returning an object alloceted on the stack this is because if you do not*/
	/*	use the reference a copy of that object will be created instead of the original object				*/
	/*	example:																							*/
	/*	std::string& myClass::get_name();																	*/
	/*	std::string myClass::get_name(); will create a copy of the the string which the function should		*/
	/*	returns a copy of the object insted of the original. This is important for manuplating the values	*/
	/********************************************************************************************************/

	std::cout << &str << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << str << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}