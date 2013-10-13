#include <iostream>
#include <vector>
#include <cmath>

/**********************************************
	Developers
	Kim Wahlman			kim.wahlman@gmail.com
	Johannes Sinander	johannes.sinander@gmail.com
	Jacob Fogelberg
***********************************************/

// ce = coefficents, iv = initial value, n = # of numbers
std::vector<long long unsigned int> setVector(std::vector<long long unsigned int> ce, std::vector<long long unsigned int> iv, int n)
{
	std::vector<long long unsigned int> returnValues;
	returnValues = iv;

	long long unsigned int an = 0;
	for (int i = returnValues.size(); i < n; i++)
	{
		an = 0;
		//std::cout << "returnValue.size = " << returnValues.size() << std::endl;
		for(int j = 0; j < 2; j++)
		{
			an += ce[i - returnValues.size() + j] * returnValues[ returnValues.size() - (j + 1) ];
		}
		returnValues.push_back(an);
		// a3 = c1a(n-1)
		//an = ce[i] * iv[i];
	}
	std::cout << std::endl;
	for(std::vector<long long unsigned int>::iterator it = returnValues.begin(); it != returnValues.end(); it++)
	{
		std::cout << (*it) << std::endl;
	}
	std::cin >> an;
	return returnValues;
}

int main()
{
	std::vector<long long unsigned int> ce, iv;
	int n = 0, value = 0;

	std::cout << "Enter amount of values to do stuff with: ";
	while(n == 0)
	{
		std::cin >> n;
		if(std::cin.fail())
		{
			std::cout << "STOP WRITING NON-NUMBERS BAKA!\n";
			std::cin.clear();
			std::cin.ignore();
			n = 0;
		}
	}
	
	std::cout << "Enter " << n << " cofficient: ";
	for(int i = 0; i < n; ++i)
	{
		
		std::cin >> value;
		if(std::cin.fail())
		{
			std::cout << "STOP WRITING NON-NUMBERS BAKA!\n";
			std::cin.clear();
			std::cin.ignore();
			i--;
		}
		else
			ce.push_back(value);
	}
	
	std::cout << "Enter two initial values: ";
	for(int i = 0; i < 2; ++i)
	{
		
		std::cin >> value;
		if(std::cin.fail())
		{
			std::cout << "STOP WRITING NON-NUMBERS BAKA!\n";
			std::cin.clear();
			std::cin.ignore();
			i--;
		}
		else
			iv.push_back(value);
	}

	setVector(ce, iv, 100);

	return 0;
}
