// BOJ_10798 : 세로읽기
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string word1,word2,word3,word4,word5;
string word_res = "";

void getline_5(string&, string&, string&, string&, string&);
void vertical_reading(string, string, string, string, string);

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    getline_5(word1, word2, word3, word4, word5); 
    vertical_reading(word1, word2, word3, word4, word5);

    return 0;
}

void getline_5(string& A, string& B, string& C, string& D, string& E){
    getline(cin, A);
    getline(cin, B);
    getline(cin, C);
    getline(cin, D);
    getline(cin, E);
}

void vertical_reading(string A, string B, string C, string D, string E){
    int A_len = A.length(); int B_len = B.length();
    int C_len = C.length(); int D_len = D.length(); int E_len = E.length();
    int max_length = max(A_len, B_len);
    max_length = max(max_length, C_len);
    max_length = max(max_length, D_len);
    max_length = max(max_length, E_len);

    for(int i = 0; i<max_length; i++){
        if(i < A.length())
            word_res.push_back(A[i]);
        if(i < B.length())
            word_res.push_back(B[i]);
        if(i < C.length())
            word_res.push_back(C[i]);
        if(i < D.length())
            word_res.push_back(D[i]); 
        if(i < E.length())
            word_res.push_back(E[i]);    
    }
    cout << word_res << endl;
}