#include "ModifiedPriorityQueue.h"
#include "strutils.h"
#include <string>
#include <fstream>
#include <sstream>

#include <iostream>
using namespace std;


template <class Comparable> 
void sorting(vector<Comparable> & mainD, vector<Comparable> & cloneMe, int left, int right)
{//used modified merge sort
	int abc = 0;
	if (left < right)
	{
		sorting(mainD, cloneMe, left, (left + right) / 2); //recursive hell
		sorting(mainD, cloneMe, ((left + right) / 2) + 1, right); // still buggy?
		//
		int center = ((left + right) / 2) + 1;
		int corner = (left + right) / 2; //leftmost
		int ptr = left;
		int total = right - left + 1;
		//
		while (left <= corner && center <= right)
		{
			if (mainD[left].west <= mainD[center].west)
			{
				cloneMe[ptr++] = mainD[left++];
			}
			else
			{
				cloneMe[ptr++] = mainD[center++];
			}
		};
		//below starts to calculate left  side
		while (left <= corner)    
		{ 
			cloneMe[ptr++] = mainD[left++];
		};
		//below starts to calculate right  side
		while (center <= right) 
		{ 
			cloneMe[ptr++] = mainD[center++];
		}
		// Re-wrting clone
		while (abc < total)
		{
			mainD[right] = cloneMe[right];
			abc++;
			right--;
		}
	}
}

int main()
{
	ifstream inp; //file data
	string IDs, line; //ids are used for tagging buildings
	int west, height, east, boolMe = 1;
	int xyz = 0; //for printing
	unsigned int test = 1;
	inp.open("input.txt");
	getline(inp, IDs);
	// Creation of ModifiedPriorityQueue object and other vector to keep west's seperately.
	ModifiedPriorityQueue<int> cityView(atoi(IDs) + 1);
	vector<SkyLine> step(1);
	while (getline(inp, line))
	{
		istringstream readMe(line);// input started to read
		readMe >> west >> height >> east;
		ValMe<int> Posit(west, east, height);
		cityView.insert(Posit, boolMe);
		//coordinates are managed
		step.push_back(SkyLine(west, height, true, boolMe));
		step.push_back(SkyLine(east, height, false, boolMe));
		boolMe++;
	};
	vector<SkyLine> cloneMe(step.size());
	sorting(step, cloneMe, 1, step.size() - 1);
	if (step[1].west != 0) { cout << "0 0" << endl; };
	while (test <= step.size() - 1)
	{
		int boolMe = cityView.GetMax(step[test].west);
		if (boolMe != xyz)
		{
			cout << step[test].west << " " << boolMe << endl;
			xyz = boolMe;
		}
		test++;
	}


	cin.get();
	cin.ignore();
	return 0;
}