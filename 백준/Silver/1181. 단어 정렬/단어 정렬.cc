#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const string&, const string&);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n = 0;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i)
        cin >> words[i];

    sort(words.begin(), words.end(), compare);
    words.erase(unique(words.begin(), words.end()), words.end());

    for (const string& word : words)
        cout << word << endl;
}


bool compare(const string& a, const string& b)
{
    if (a.length() == b.length())
        return a < b;
    else
        return a.size() < b.size();
}