#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> del;
int wcnt = 0;
bool compare(int i, int j) {
    return i > j;
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
 
    for (int i = 0; i < wcnt; i++) {
        if (cmd[i].size() <=4) {
            if (cmd[i][1] == 'Z') {
                if (!del.empty()) {
                    del.pop_back();
                }
               
            }
            else if (cmd[i] == "C") {
                del.push_back(k);
                if (k + 1 <= n) {
                    k += 1;
                }
                else {
                    k -= 1;
                }
                
            }
        }
        else{
            int move = cmd[i][2] - '0';
            if (cmd[i][0] == 'D') {
                int cnt = 0;
                for (int i = 0; i < del.size(); i++) {
                    if (k < del[i]) {
                        cnt++;
                    }
                }
                k += (move+cnt);
            }
            else if (cmd[i][0] == 'U') {
                int cnt = 0;
                for (int i = 0; i < del.size(); i++) {
                    if (del[i] < k) {
                        cnt++;
                    }
                }
                k -= (move+cnt);
            }

         }
    }
    if (!del.empty()) {
        sort(del.begin(), del.end(),compare);
    }
   
    for (int i = 0; i < n; i++) {
        if (!del.empty()) {
            if (i != del.back()) {
                answer += 'O';
            }
            else {
                answer += 'X';
                del.pop_back();
            }
        }
        else {
            answer += 'O';
        }
      
    }

    return answer;
}

int main() {
    int n;
    int k;
    vector<string> cmd;
    string tt;
    cin >> n >> k;
    cin.ignore();
   
    getline(cin, tt);
    for (int i = 0; i < tt.size(); i++) {
        if (tt[i] == ',') {
            string ww = tt.substr(0, i);
            cmd.push_back(ww);
            wcnt++;
        }
    }
    cout << "cmd:" << cmd.size() << endl;
    /*for (int i = 0; i < cmd.size(); i++) {

    }*/
    string ret = solution(n, k, cmd);
    std::cout << ret << endl;
}