#include <iostream>
#include <stack>
#include <cstring>
using namespace std;


int main() {
	string str;
	cin >> str;
	stack<char>ele;
	stack<int> num;
	int ssum = 0;
	int ret = 0;
	int keep = 1;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			ele.push(str[i]);
			keep *= 2;
		}
		else if (str[i] == '[') {
			ele.push(str[i]);
			keep *= 3;
		}
		else if (str[i] == ')') {
			if (ele.empty()) {
				ret = 0;
				break;
			}

			if (ele.top() == '(') {
				int ntop = ele.top();
				ele.pop();

				ret += ntop;
			}

		}
		else if (str[i] == ']') {
			if (ele.empty()) {
				ret = 0;
				break;
			}
		}
	}
	
	if (!ele.empty())
		ret = 0;
	while (!num.empty()) {
		//cout << "top:" << num.top() << endl;
		ret += num.top();
		num.pop();
	}
	//ret = num.top();
	std::cout << ret << endl;

	return 0;
}
