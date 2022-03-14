// Using names.txt (right click and 'Save Link/Target As...'), a 46K text file
// containing over five-thousand first names, begin by sorting it into
// alphabetical order. Then working out the alphabetical value for each name,
// multiply this value by its alphabetical position in the list to obtain
// a name score.
// For example, when the list is sorted into alphabetical order,
// COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name
// in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
// What is the total of all the name scores in the file?

#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include <iostream>

int main ()
{
	std::vector<std::string> listOfAllNames;
	std::ifstream stream;
	stream.open("../../0022/names.txt");
	std::string s;
	while (!stream.eof())
	{
		std::getline(stream, s, ',');
		s.erase(std::remove(s.begin(), s.end(), '\"'), s.end());
		listOfAllNames.emplace_back(s);
	}
	stream.close();
	
	std::sort(listOfAllNames.begin(), listOfAllNames.end(),
		   [](const std::string &a, const std::string &b){return a < b;});
	
	std::vector<int> valueArray(listOfAllNames.size());
	for (size_t i = 0; i < listOfAllNames.size(); i++)
		for (size_t j = 0; j < listOfAllNames[i].size(); j++)
			valueArray[i] += listOfAllNames[i][j] - 'A' + 1;
	
	size_t answer = 0;
	for (size_t i = 0; i < valueArray.size(); i++)
		answer += (i + 1) * valueArray[i];
	
	std::cout << "Answer is: " << answer << "\n";
	
	return 0;
}
