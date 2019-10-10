#include <iostream>
#include <iomanip>
#include <string>
#include <climits>
#include <cstring>
#include <fstream>
#include <sstream>
#include <chrono>
#include <vector>
using std::ostringstream;
using std::ifstream;
using std::ofstream;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


class Timer {
private:
	using hrClock = std::chrono::high_resolution_clock;
	using durationDouble = std::chrono::duration<double>;
	std::chrono::time_point<hrClock> start;
public:
	Timer() : start{ hrClock::now() } {}
	void reset() {
		start = hrClock::now();
	}
	double elapsed() const {
		return durationDouble (hrClock::now() - start).count();
	}
};

void HashAndCompare(const char* input, unsigned int length, string& output)
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
	while (output.length() < 16)
	{
		output.insert(0, "0");
	}
	std::stringstream ss;
	ss << std::hex << hash1 << hash2;
	output = ss.str();
	//cout<<hash<<endl;
}
int compare(string& input1, string& input2, int& collision)
{
	if ( input1 == input2)
	{
		return collision++;
	}
	return collision;
}

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
	unsigned int keys[2];
	int collision = 0;
	if (argc > 1)
	{
		ifstream failas(argv[1]);
		ofstream ofailas("EiluteFailasRez.txt");
		Timer T;
		int k = 0;
		string inputnow = " ";
		string inputlast = "0";
		while (!failas.eof())
		{
			getline(failas, input);
			HashAndCompare(input.c_str(), input.length(), inputnow);
			compare(input, inputlast, collision);
			inputlast = input;
			k++;
		}
		cout << "rasta collision: " << collision << " is " << k - 1 << " palyginimu" << endl;
		ofailas << T.elapsed() << endl;
		cout << T.elapsed() << endl;
	}
	else {
		cout << "Iveskite duomenis: ";
		getline(cin, input);
		string output;
		Hash(input.c_str(), input.length(), output);
		cout << output << endl;

	}
	return 0;
}
