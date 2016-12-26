// 13909-MERT TOKA HW4

#include "MPQ.h"
#include "strutils.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

const char* FILENAME = "input.txt";

// Struct to keep only one x and y, whether or not it is left of the building and label.
struct SkylineInfo
{
	int x;
	int y;
	bool left;
	int label;

	SkylineInfo()	{}
	SkylineInfo(int _x, int _y, bool _left, int _label)
		:x(_x), y(_y), left(_left), label(_label)	{}
};

// Merge sort functions
template <class Comparable>
void merge( vector<Comparable> & a, vector<Comparable> & tmpArray,
	int leftPos, int rightPos, int rightEnd )
{
	int leftEnd = rightPos - 1;
	int tmpPos = leftPos;
	int numElements = rightEnd - leftPos + 1;
	while( leftPos <= leftEnd && rightPos <= rightEnd )
		if( a[ leftPos ].x <= a[ rightPos ].x )
			tmpArray[ tmpPos++ ] = a[ leftPos++ ];
		else
			tmpArray[ tmpPos++ ] = a[ rightPos++ ];

	while( leftPos <= leftEnd )    // Copy rest of first half
		tmpArray[ tmpPos++ ] = a[ leftPos++ ];

	while( rightPos <= rightEnd )  // Copy rest of right half
		tmpArray[ tmpPos++ ] = a[ rightPos++ ];

	// Copy tmpArray back
	for( int i = 0; i < numElements; i++, rightEnd-- )
		a[ rightEnd ] = tmpArray[ rightEnd ];
}
template <class Comparable>
void mergeSort( vector<Comparable> & a, vector<Comparable> & tmpArray, int left, int right )
{
	if( left < right )
	{
		int center = ( left + right ) / 2;
		mergeSort( a, tmpArray, left, center );
		mergeSort( a, tmpArray, center + 1, right );
		merge( a, tmpArray, left, center + 1, right );
	}
}
template <class Comparable>
void mergeSort( vector<Comparable> & a )
{
	vector<Comparable> tmpArray( a.size( ) );

	mergeSort( a, tmpArray, 1, a.size( ) - 1 );
}

int main()
{
	// Opening of the file.
	ifstream inp;
	inp.open(FILENAME);

	if(inp.fail())
	{
		cout << "Could not open" << endl;
		return 0;
	}

	// Reading first line to get Builing Number.
	string BuildingNumber;
	getline(inp, BuildingNumber);

	// Creation of MPQ object and other vector to keep x's seperately.
	MPQ<int> skyline(atoi(BuildingNumber)+1);
	vector<SkylineInfo> seq(1);

	
	int i = 1;
	string line;
	while(getline(inp, line))
	{
		// Interpreting the data
		int x1, y, x2;
		istringstream iss(line);
		iss >> x1 >> y >> x2;

		// Adding to MPQ object
		Value<int> Coordinates(x1, x2, y);
		skyline.insert(Coordinates, i);

		// Adding to other vector seperately
		seq.push_back(SkylineInfo(x1, y, true,  i));
		seq.push_back(SkylineInfo(x2, y, false, i));
		i++;
	}

	// Sorting the list according to their x's
	mergeSort(seq);

	// Printing the Skyline
	int prevPrinted = 0;
	if(seq[1].x != 0)
		cout << 0 << " " << 0 << endl;

	for(unsigned int k = 1; k <= seq.size() -1; k++)
	{
		int print = skyline.GetMax(seq[k].x);
		if(print != prevPrinted)
		{
			cout << seq[k].x << " " << print << endl;			
			prevPrinted = print;				
		}
	}
	system("pause");
	return 0;
}