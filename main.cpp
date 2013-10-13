//////////////////////////////////////////////////////////
//	Authors:											//
//	Kim Wahlman			kim.wahlman@gmail.com			//
//	Johannes Sinander	johannes.sinander@gmail.com		//
//	Jacob Fogelberg										//
//////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <cmath>

std::vector<__int64> setVector( std::vector<int>, std::vector<int>, int );

int main()
{
	std::vector<int> coefficients, initialValues;
	int n = 0, value = 0;

	//Read n
	std::cout << "Enter number of values (n): ";
	while(n == 0)
	{
		std::cin >> n;
		if( std::cin.fail() )
		{
			std::cout << "STOP WRITING NON-NUMBERS BAKA!\n";
			std::cin.clear();
			std::cin.ignore();
			n = 0;

		}
	}

	//Read coefficients
	std::cout << "Enter " << n << " cofficients: ";
	for( int i = 0; i < n; ++i )
	{
		std::cin >> value;
		if( std::cin.fail() )
		{
			std::cout << "STOP WRITING NON-NUMBERS BAKA!\n";
			std::cin.clear();
			std::cin.ignore();
			i--;
		}
		else
		{
			coefficients.push_back( value );
		}
	}

	//Read 2 initial values
	std::cout << "Enter " << 2 << " initial values: ";
	for( int i = 0; i < 2; ++i )
	{
		std::cin >> value;
		if( std::cin.fail() )
		{
			std::cout << "STOP WRITING NON-NUMBERS BAKA!\n";
			std::cin.clear();
			std::cin.ignore();
			i--;
		}
		else
		{
			initialValues.push_back( value );
		}
	}

	setVector( coefficients, initialValues, n );

	std::cout << "Press enter to exit..";
	std::cin.get();
	std::cin.get();

	return 0;
}

//////////////////
//	FUNCTIONS	//
//////////////////
std::vector<__int64> setVector( std::vector<int> coefficients, std::vector<int> initialValues, int n )
{
	std::vector<__int64> returnValues;
	for (std::vector<int>::iterator it = initialValues.begin(); it != initialValues.end(); it++)
	{
		returnValues.push_back( (*it) );
	}
	
	__int64 an;
	for (int i = returnValues.size(); i < n; i++)
	{
		an = 0;
		for (int j = 0; j < 2; j++)
		{
			an += coefficients[i - returnValues.size() + j] * returnValues[ returnValues.size() - (j + 1) ];
		}
		returnValues.push_back( an );
	}
	
	std::cout << "Result: ";
	for ( std::vector<__int64>::iterator it = returnValues.begin(); it != returnValues.end(); it++ )
	{
		std::cout << (*it) << " ";
	}
	std::cout << "\n";

	return returnValues;
}