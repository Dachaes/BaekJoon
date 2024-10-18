#include <iostream>
#include <map>
#define endl '\n'
using namespace std;


int to_number(string, map<char, int>);
string to_roman(int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    map<char, int> roman_to_num = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
    };
    string a, b;
    cin >> a >> b;
    int num_a = to_number(a, roman_to_num);
    int num_b = to_number(b, roman_to_num);
    
    int num_res = num_a + num_b;
    cout << num_res << endl;

    string res = to_roman(num_res);
    cout << res << endl;

    return 0;
}


int to_number(string str, map<char, int> key) {
    int num = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (key[str[i]] < key[str[i + 1]])
            num -= key[str[i]];
        else
            num += key[str[i]];
    }

    return num;
}


string to_roman(int num) {
    string roman;
    while (num != 0) {
        if (num >= 1000) {
            roman += 'M';
            num -= 1000;
        }
        else if (num >= 900) {
            roman += "CM";
            num -= 900;
        }
        else if (num >= 500) {
            roman += 'D';
            num -= 500;
        }
        else if (num >= 400) {
            roman += "CD";
            num -= 400;
        }
        else if (num >= 100) {
            roman += 'C';
            num -= 100;
        }
        else if (num >= 90) {
            roman += "XC";
            num -= 90;
        }
        else if (num >= 50) {
            roman += 'L';
            num -= 50;
        }
        else if (num >= 40) {
            roman += "XL";
            num -= 40;
        }
        else if (num >= 10) {
            roman += 'X';
            num -= 10;
        }
        else if (num >= 9) {
            roman += "IX";
            num -= 9;
        }
        else if (num >= 5) {
            roman += 'V';
            num -= 5;
        }
        else if (num >= 4) {
            roman += "IV";
            num -= 4;
        }
        else if (num >= 1) {
            roman += 'I';
            num -= 1;
        }
    }

    return roman;
}