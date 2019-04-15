#include "018_4Sum.h"
#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char *argv[]) 
{ 
	Solution a;
	vector<int> temp = { -2, 0, 0, 3, 3, -1 };
	a.fourSum(temp, 5);
	cin.get();
	return 0;
}