#include <iostream>
#include <iomanip>
#include <string>
#include <climits>
#include <cstring>
#include <fstream>
#include <sstream>
using std::ostringstream;
using std::ifstream;
using std::ofstream;
using std::cin;
using std::cout;
using std::endl;
using std::string;
void Hash(const char* input, unsigned int length, unsigned int* keys)
{
	unsigned int hash1;
	unsigned int hash2;
	unsigned int hashxor = 0x003479b9;
	unsigned int z = length - 1;
	for (int i = 0; i < length; i++)
	{
		hash1 += input[i];
		hash2 += input[i];
		hashxor += input[z];
		hashxor = hashxor >> 3;
		hashxor += 0x9e3479b9;
		z--;
		hash1 = hash1 ^ hashxor;
		hash1 += (hash1 >> 1) ^ (hash1 << 3);
		hash1 += (hash1 >> 3) ^ (hash1 << 4);
		hash1 += (hash1 >> 24) ^ (hash1 << 16);
		hash1 += (hash1 >> 28) ^ (hash1 << 10);
		hash2 = hash2 ^ hashxor;
		hash2 += (hash2 >> 17) ^ (hash2 << 11);
		hash2 += (hash2 >> 3) ^ (hash2);
		hash2 += (hash2 >> 5) ^ (hash2 << 9);
		hash2 += (hash2 >> 28) ^ (hash2 << 10);
	}

	while (hash1 < 0x11111111)
	{
		hash1 = hash1 * (hash1 << 1);

	}
	while (hash2 < 0x11111111)
	{
		hash2 = hash2 * (hash1 << 1);
	}
	keys[0] = hash1;
	keys[1] = hash2;
}
int main(int argc, char *argv[])
{
	string input;
	unsigned int keys[2];
	if (argc > 1)
	{
		ifstream failas(argv[1]);
		ostringstream ss;
		ss << failas.rdbuf();
		input = ss.str();
		Hash(input.c_str(), input.length(), keys);
		ofstream ofailas("VisasFailasRez.txt");
		ofailas << std::hex << keys[0] << keys[1] << endl;
	}
	else {
		cout << "Iveskite duomenis: ";
		getline(cin, input);
		Hash(input.c_str(), input.length(), keys);
		cout << std::hex << keys[0] << keys[1] << endl;

	}
	return 0;
}
