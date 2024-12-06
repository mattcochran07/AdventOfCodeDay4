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
	for (int i = 0; i < A.size(); i++) // row num
	{
		const std::string& line = A[i];
		for (int j = 0; j < line.size(); j++) // col num
		{
			const char& c = line.at(j);
			if (c == 'X')
			{
				//check LEFT TO RIGHT HORIZONTAL
				if (j < (line.size() - 3) &&
				    A[i].at(j+1) == 'M' && 
				    A[i].at(j+2) == 'A' &&
				    A[i].at(j+3) == 'S')
				{
					std::cout << "found a left to right horizonatal xmas at line " << i << std::endl;
					numXMAS++;
				}
				//check RIGHT TO LEFT HORIZONTAL
				if (j >= 3 && 
				    A[i].at(j-1) == 'M' &&
				    A[i].at(j-2) == 'A' && 
				    A[i].at(j-3) == 'S')
				{
					std::cout << "found a right to left horizonatal xmas at line " << i << std::endl;
					numXMAS++;
				}
				// check TOP TO BOTTOM VERTICAL
				if (i < (A.size() - 3) &&
				    A[i+1].at(j) == 'M' &&
				    A[i+2].at(j) == 'A' &&
				    A[i+3].at(j) == 'S')
				{
					std::cout << "found a top to bottom vertical xmas at col " << j << std::endl;
					numXMAS++;
				}
				//check BOTTOM TO TOP VERTICAL
				if (i >= 3 &&
				    A[i-1].at(j) == 'M' &&
				    A[i-2].at(j) == 'A' &&
				    A[i-3].at(j) == 'S')
				{
					std::cout << "found a bottom to top vertical xmas at col " << j << std::endl;
					numXMAS++;
				}
				//check LEFT TO RIGHT BOTTOM TO TOP DIAGONAL
				if (j < (line.size() - 3) && i >= 3 &&
				    A[i-1].at(j+1) == 'M' &&
				    A[i-2].at(j+2) == 'A' &&
				    A[i-3].at(j+3) == 'S')
				{
					std::cout << "found a left to right bottom to top diagonal xmas at row " << i << " col " << j << std::endl;
					numXMAS++;
				}
				//check LEFT TO RIGHT TOP TO BOTTOM DIAGONAL
				if (j < (line.size() - 3) && 
				    i < (A.size() - 3) &&
				    A[i+1].at(j+1) == 'M' &&
				    A[i+2].at(j+2) == 'A' && 
				    A[i+3].at(j+3) == 'S')
				{
					std::cout << "found a left to right top to bottom diagonal xmas at row " << i << " col " << j << std::endl;
					numXMAS++;
				}
				//check RIGHT TO LEFT BOTTOM TO TOP DIAGONAL
				if (j >= 3 && i >= 3 &&
				    A[i-1].at(j-1) == 'M' &&
				    A[i-2].at(j-2) == 'A' &&
				    A[i-3].at(j-3) == 'S')
				{
					std::cout << "found a right to left bottom to top diagonal xmas at row " << i << " col " << j << std::endl;
					numXMAS++;
				}
				// check RIGHT TO LEFT TOP TO BOTTOM DIAGONAL
				if (j >= 3 && 
				    i < (A.size() - 3) &&
				    A[i+1].at(j-1) == 'M' &&
				    A[i+2].at(j-2) == 'A' &&
				    A[i+3].at(j-3) == 'S')
				{
					std::cout << "found a right to left top to bottom diagonal xmas at row " << i << " col " << j << std::endl;
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
