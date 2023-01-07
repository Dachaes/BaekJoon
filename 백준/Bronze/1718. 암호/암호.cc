#include <iostream>
#include <string>

using namespace std;
string key, sentence;          // key : 암호키, sentence : 암호화하려는 문장

void in(string &);
void out(string);
void vigenere_cipher(string, string);
    
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    getline(cin, sentence); 
    getline(cin, key); 
    vigenere_cipher(key, sentence);
   
    return 0;
}

void in(string &a){
    cin >> a;
}

void out(string a){
    cout << a << endl;
}

// a = 암호화키, b = 평문
void vigenere_cipher(string str_a, string str_b){
    int a_length = str_a.length();
    int arr_a[a_length];
    int b_length = str_b.length();
    int arr_b[b_length];

    int arr_res[b_length];
        
// String A를 각 문자마다 정수값(ASCII)으로 Array A에 저장
// String B를 각 문자마다 정수값(ASCII)으로 Array B에 저장
    for(int i=0; i<a_length; i++)
        arr_a[i] = str_a[i];

    for(int i=0; i<b_length; i++)
        arr_b[i] = str_b[i];

// Array Result에 둘의 합을 계산
    int j = 0;
    for(int i=0; i<b_length; i++){
        if(j >= a_length)                     // 암호화 키가 짧을 경우
            j -= a_length;
                                         
        if(arr_b[i] == ' ')                      // 평문이 공란일 경우
            arr_res[i] = ' '; 
        else                                    // 평문에 문자가 있을 경우
            arr_res[i] = arr_b[i] - arr_a[j] + 'a' - 1;
        
        j++;

        // Array Result 결과를 String에 저장
        if(arr_res[i] < 'a' && arr_res[i] != ' ')
            arr_res[i] += 26;                  // 소문자 a를 아래로 갈 경우   

        cout << (char)arr_res[i];
    }
}