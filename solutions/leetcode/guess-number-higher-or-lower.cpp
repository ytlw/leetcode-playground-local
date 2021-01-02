// Created by Minghang Yang on 2021/1/3.

#include <helper.h>
#include <treenode_int.h>
#include <listnode_int.h>
#include "subroutine_relative.h"

using namespace std;

class Solution {
private:
    int secret;
private:
    int guess(int n) {
        if (n == secret) {
            return 0;
        }
        if (n > secret) {
            return -1;
        }
        return 1;
    }
public:
    void setSecret(int sec) {
        this->secret = sec;
    }
public:
    int guessNumber(int n) {
        if (n == 1) {
            return 1;
        }
        int left = 1, right = n;
        int cnt = 0;
        do {
            int mid = left + ((right - left) >> 1);
            int t = guess(mid);
            if (t == 0) {
                return mid;
            } else if (t == 1) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } while (true);
    }
};

int sub() {
    string s;
    Solution solution;
    while (getline(cin, s)) {
        int n = atoi(s.c_str());
        getline(cin, s);
        int sec = atoi(s.c_str());
        solution.setSecret(sec);
        cout << solution.guessNumber(n) << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub, subroutineRelative);
}
