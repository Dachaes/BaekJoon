#include <iostream>
#include <map>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력 1 (테스트 케이스 개수)
    int n_pokemons = 0, n_questions = 0;
    cin >> n_pokemons >> n_questions;

    map<int, string> pokemons_encyclopedia1;
    map<string, int> pokemons_encyclopedia2;
    for (int i = 0; i < n_pokemons; ++i) {
        string pokemon;
        cin >> pokemon;

        pokemons_encyclopedia1[i + 1] = pokemon;
        pokemons_encyclopedia2[pokemon] = i + 1;
    }
    for (int i = 0; i < n_questions; ++i) {
        string query;
        cin >> query;

        if (isdigit(query[0]))
            cout << pokemons_encyclopedia1[stoi(query)] << '\n';
        else
            cout << pokemons_encyclopedia2[query] << '\n';
    }

    return 0;
}