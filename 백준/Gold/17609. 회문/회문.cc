#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;


int check_palindrome(int, int, string&, int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;      cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        string word;        cin >> word;
        words[i] = word;
    }

    // two pointers
    for (string word : words) {
        int result = check_palindrome(0, word.length() - 1, word, 0);
        cout << result << endl;
    }

    return 0;
}


int check_palindrome(int left, int right, string &word, int result) {
    while (left <= right) {
        //  단어가 같으면
        if (word[left] == word[right]) {
            left++;
            right--;
        }
        // 단어가 다르면
        else {
            // 유사회문 조건1
            int left1 = left + 1;
            int right1 = right;
            bool flag1 = true;
            while (left1 <= right1) {
                if (word[left1] == word[right1]) {
                    left1++;
                    right1--;
                }
                else {
                    flag1 = false;
                    break;
                }
            }
            // 유사회문 조건2
            int left2 = left;
            int right2 = right - 1;
            bool flag2 = true;
            while (left2 <= right2) {
                //  단어가 같으면
                if (word[left2] == word[right2]) {
                    left2++;
                    right2--;
                }
                else {
                    flag2 = false;
                    break;
                }
            }

            // 유사회문 조건 확인
            if (flag1 or flag2) {
                return 1;
            }
            else
                return 2;
        }
    }

    return 0;
}