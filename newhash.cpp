#include <iostream>
#include <iomanip>
#include <string>
#include <climits>
#include <cstring>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
void Hash(const char* input, unsigned int length, string & output)
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
	std::stringstream ss;
	ss << std::hex << hash1 << hash2;
	output = ss.str();
	while (output.length() < 16)
	{
		output.insert(0, "0");
	}
}
int main(int argc, char *argv[])
{
	string input;
	if (argc > 1)
	{
		input = argv[1];
	}
	else {
		cout << "Iveskite duomenis: ";
		getline(cin, input);
	}
	string output;
	Hash(input.c_str(), input.length(), output);
	cout << output << endl;
	return 0;
}