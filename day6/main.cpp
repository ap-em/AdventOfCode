#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Author: ap-em 1/1/22
using namespace std;

int main()
{
	std::vector<uint64_t> fish;
	ifstream file;
	file.open("day6.txt");

	if (!file.is_open())
	{
		cout << "Error opening file\n";
		return 0;
	} 

	uint64_t num;
	int j = 0;
	
	for (int i = 0; i < 9; i++)
	{
		fish.push_back(0);
	}

	while (file >> num)
	{
		file.ignore();
		fish[num]++;
		cout << "Line " << j++ << ": " << num << endl;
	}
	cout << endl;

	uint64_t size, val;
	size = fish[0] + fish[1] + fish[2] + fish[3] + fish[4] + fish[5] + fish.at(6) + fish[7];
	for (int day = 0; day < 256; day++)
	{

		cout << "Day " << day << ": " << size << ", " << endl;
		cout << "fish0: " << fish[0] << " fish1: " << fish[1] << " fish2: " << fish[2] << " fish3: " << fish[3] << " fish4: " << fish[4] << " fish5: " << fish[5];
		cout << " fish6: " << fish.at(6) << " fish7: " << fish[7] <<  " fish8: " << fish[8] << "\n" ;
		val = fish[0]; 
		rotate(fish.begin(), fish.begin() + 1, fish.end()); // Rotates vector

		fish[6] = fish.at(6) + val;
		size = fish[0] + fish[1] + fish[2] + fish[3] + fish[4] + fish[5] + fish.at(6) + fish[7] + fish[8];
		
	}
	cout << "Final size: " << size << endl;
	file.close();
	return 0;
}
