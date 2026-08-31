#include <iostream>
#include <string>
#include <vector>

bool checkPrevious(int number, const std::vector<int>& numbers) {
	if (numbers.begin() == numbers.end()) {return true;}
	for (const auto& n : numbers) { if (number == n) { return false; } }
	return true;
}

int findNumber(int number) {
	bool foundNumber = false;
	int N = 0;
	int Number = 0;
	std::vector<int> numbers;
	while (!foundNumber) {
		if (!(Number - N < 0) && checkPrevious(Number - N, numbers)) { numbers.push_back(Number - N); Number -= N; }
		else { numbers.push_back(Number + N); Number += N; }
		if(Number == number) {foundNumber = true; break;}
		N++;

	}
	return N+1;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {std::cout << "To few arguments"; return 1;}
	int number = std::stoi(argv[1]);

	int N = findNumber(number);
	std::cout << number << " is " << N << '\n';
	return 0;
}
