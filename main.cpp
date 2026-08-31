#include <iostream>
#include <vector>
#include <string>
#include <fstream>

bool checkPrevious(int number, const std::vector<int>& numbers) {
	if (numbers.begin() == numbers.end()) {return true;}
	for (const auto& n : numbers) { if (number == n) { return false; } }
	return true;
}

std::vector<int> calculate(int loops) {
	std::vector<int> numbers;
	int number = 0;
	for (int i = 0; i < loops; i++) {
		if (!(number - i < 0) && checkPrevious(number - i, numbers)) { numbers.push_back(number - i); number -= i; }
		else { numbers.push_back(number + i); number += i; }
	}
	return numbers;
}

int main(int argc, char* argv[]) {
	if(argc < 2) {return 1;}
	bool fileOP; if (argc == 3) {fileOP = true;} else {fileOP = false;}
	std::string fileN; if (fileOP) {fileN = argv[2];}
	int loops = std::stoi(argv[1]);
	std::vector<int> numbers = calculate(loops);
	if (!fileOP) {
		for (const auto& n : numbers) {std::cout << n << ' ';}
		std::cout << '\n';
	}
	else {
		std::ofstream write(fileN);
		for (const auto& n : numbers) { write << n << '\n'; }
	}
	return 0;	
}
