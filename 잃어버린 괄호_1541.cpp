#include <iostream>
#include <string>
#include <vector>
using namespace std;

string word;
vector<string> splitWord;
vector<string> number;
int main() {

	cin >> word;

	bool flag = false;
	int i = 0;

	int startPosition = 0;
	int going = 0;

	//-·Î split
	for (int i = 1; i < word.size(); i++) {
		if (word[i] == '-') {
			splitWord.push_back(word.substr(startPosition, i - startPosition));
			startPosition = i + 1;
		}
	}
	splitWord.push_back(word.substr(startPosition, word.size() - startPosition));

	
	//+·Î split 
	vector<string> firstString;
	for (int i = 0; i < splitWord.size(); i++) {
		int nstartPosition = 0;
		for (int j = 0; j < splitWord[i].size(); j++) {
			if (i == 0) {
				if (splitWord[0][j] == '+') {
					firstString.push_back(splitWord[i].substr(nstartPosition, j - nstartPosition));
					nstartPosition = j + 1;
				}
			}
			else {
				if (splitWord[i][j] == '+') {
					number.push_back(splitWord[i].substr(nstartPosition, j - nstartPosition));
					nstartPosition = j + 1;
				}
			}
		}
		if (i == 0)
			firstString.push_back(splitWord[0].substr(nstartPosition, splitWord[i].size() - nstartPosition));
		else
			number.push_back(splitWord[i].substr(nstartPosition, splitWord[i].size() - nstartPosition));
	}


	int PositiveSum = 0;
	for (int i = 0; i < firstString.size(); i++) {
		int nn = stoi(firstString[i]);
		PositiveSum += nn;
	}

	int NegativeSum = 0;
	for (int i = 0; i < number.size(); i++) {
		int nn = stoi(number[i]);
		NegativeSum += nn;
	}

	
	cout << PositiveSum - NegativeSum << endl;
	
}