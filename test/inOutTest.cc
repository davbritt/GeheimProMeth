#include <fstream>
using namespace std;

ifstream input("../README.md", ios::in);
ofstream output("yourOutputFile.txt", ios::out);


char letter;

int main(){
	letter = input.get();
	output.put(letter);
	output << "David Britt";

	input.close();
	output.close();
	return 0;
}