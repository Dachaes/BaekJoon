// BOJ_13241 : 최소공배수
#include <iostream>
using namespace std;
long long int A, B;
long long int A_, B_, LCM;
int Anum = 1; int Bnum = 1;
void in(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> A >> B;
    A_ = A;     B_ = B;
}

void solve(){
    while(LCM == 0){
        if(A_ == B_)
            LCM = A_;
        else if (A_ < B_){
            A_ = A * Anum;
            Anum++;
        }
        else if (A_ > B_){
            B_ = B * Bnum;
            Bnum++;
        }
    }
}

void out(){
    cout << LCM << endl;
}

int main() {
    in();
    solve();
    out();
    return 0;
}