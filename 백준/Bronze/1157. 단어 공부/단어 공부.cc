#include <iostream>
using namespace std;

int main() {
    string words;
    getline(cin, words);

    int ord;
    int alphas[26] = {};    // 사용된 알파벳의 갯수를 저장하는 배열

    // 1. 알파벳에 따라 카운팅하여 alphas 배열에 저장하기
    for (char word : words) {
        ord = word - 'A';
        if (ord >= 26)  alphas[ord - 32]++;
        else            alphas[ord]++;
    }

    // 2. 알파벳 카운팅 배열 (alphas) 를 탐색하며, 많이 사용한 알파벳 찾기
    int maxAlpha = 0;       // 가장 많이 사용된 알파벳
    int countMaxAlpha = 0;  // 가장 많이 사용된 알파벳의 갯수
    int count = 0;          // countMaxAlpha 가 같은 알파벳 갯수

    for (int i = 0; i < 26; i++) {
        if (alphas[i] > 0) {
            if (countMaxAlpha < alphas[i]) {
                countMaxAlpha = alphas[i];
                maxAlpha = i + 'A';
                count = 1;
            }
            else if (countMaxAlpha == alphas[i]) {
                count++;
            }
        }
    }

    // 3. 조건에 따라 출력하기
    if (count > 1)
        cout << '?' << '\n';
    else
        cout << static_cast<char>(maxAlpha) << '\n';

    return 0;
}