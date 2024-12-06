#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

const char& getCharAt(const std::vector<std::string>& A, int rowNum, int colNum)
{
	return A[rowNum].at(colNum);
}

int numXMAS(const std::vector<std::string>& A)
{
	int numXMAS = 0;
	for (int i = 1; i < A.size()-1; i++) // row num
	{
		const std::string& line = A[i];
		for (int j = 1; j < line.size()-1; j++) // col num
		{
			const char& c = line.at(j);
			if (c == 'A')
			{
				/* M   S
				 *   A
				 * M   S  
				*/
				//check L-R/T-B & L-R/B-T
				if (A[i-1].at(j-1) == 'M' &&
				    A[i+1].at(j+1) == 'S' &&
				    A[i+1].at(j-1) == 'M' &&
				    A[i-1].at(j+1) == 'S')
				{
					std::cout << "found an X case 1 at row " << i << " col " << j << std::endl;
					numXMAS++;
				}
				/* M   M
				 *   A 
				 * S   S 
				*/
				//check L-R/T-B & R-L/T-B
				if (A[i-1].at(j-1) == 'M' &&
				    A[i+1].at(j+1) == 'S' &&
				    A[i+1].at(j-1) == 'S' &&
				    A[i-1].at(j+1) == 'M')
				{
					std::cout << "found an X case 2 at row " << i << " col " << j << std::endl;
					numXMAS++;
				}
				/* S   M
				 *   A  
				 * S   M
				*/
				if (A[i-1].at(j-1) == 'S' &&
				    A[i+1].at(j+1) == 'M' &&
				    A[i+1].at(j-1) == 'S' &&
				    A[i-1].at(j+1) == 'M')
				{
					std::cout << "found an X case 3 at row " << i << " col " << j << std::endl;
					numXMAS++;
				}
				/* S   S
				 *   A  
				 * M   M
				*/
				if (A[i-1].at(j-1) == 'S' &&
				    A[i+1].at(j+1) == 'M' &&
				    A[i+1].at(j-1) == 'M' &&
				    A[i-1].at(j+1) == 'S')
				{
					std::cout << "found an X case 4 at row " << i << " col " << j << std::endl;
					numXMAS++;
				}
			}
		}
	}
	return numXMAS;
}

int main(int argc, char** argv)
{
	if (argc == 2)
	{
		std::ifstream ifs(argv[1]);
		std::string line;
		std::vector<std::string> A; // matrix :)
		while (std::getline(ifs, line))
		{
			A.push_back(line);
		}
		int num_XMAS = numXMAS(A);
		std::cout << "num xmas " << num_XMAS << std::endl;
	}
	return 0;
}
