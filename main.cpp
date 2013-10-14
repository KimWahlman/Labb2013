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
	int n, k, d, value;

	while ( true )
	{
		n = 0;
		k = 0;
		value = 0;

		//Read n
		std::cout << "Enter the number of values (n): ";
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
		std::cout << "Enter " << n - 1 << " cofficients: ";
		for( int i = 0; i < n - 1; ++i )
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
	
		//Read k
		std::cout << "Enter the number of initial values (k): ";
		while(k == 0)
		{
			std::cin >> k;
			if( std::cin.fail() )
			{
				std::cout << "STOP WRITING NON-NUMBERS BAKA!\n";
				std::cin.clear();
				std::cin.ignore();
				k = 0;

			}
		}

		//Read 2 initial values
		std::cout << "Enter " << k << " initial values: ";
		for( int i = 0; i < k; ++i )
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

		std::cout << "\n\n\n";
		/*std::cin.get();
		std::cin.get();*/
	}

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
		/*for (int j = 0; j < 2; j++)
		{
			
			an += coefficients[i + j - initialValues.size()] * returnValues[ returnValues.size() - (j + 1) ];
			std::cout << coefficients[i + j - initialValues.size()] << " * " << returnValues[ returnValues.size() - (j + 1) ] << " = " << coefficients[i - returnValues.size() + j] * returnValues[ returnValues.size() - (j + 1) ] << " Total: " << an << "\n";
		}*/
		for (int j = 0; j < returnValues.size(); j++)
		{
			
			an += coefficients[j] * returnValues[ returnValues.size() - (j + 1) ];
			std::cout << "\n" << coefficients[j] << " * " << returnValues[ returnValues.size() - (j + 1) ] << " = " << coefficients[i - returnValues.size() + j] * returnValues[ returnValues.size() - (j + 1) ] << " Total: " << an;
		}
		std::cout << "\n\n";
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
