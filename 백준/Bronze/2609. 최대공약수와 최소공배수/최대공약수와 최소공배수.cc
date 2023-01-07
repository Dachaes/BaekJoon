// BOJ_2609 : 최대공약수와 최소공배수
#include <iostream>
using namespace std;
int A, B;
int A_, B_, LCM;
int Anum = 1; int Bnum = 1;
int A__, B__, GCD;
void in(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> A >> B;
    A_ = A__ = A;     B_ = B__ = B;
}

void solve_LCM(){
    while(LCM == 0){
        if(A_ == B_)
            LCM = A_;
        else if (A_ < B_) {
            A_ = A * Anum;
            Anum++;
        }
        else if (A_ > B_) {
            B_ = B * Bnum;
            Bnum++;
        }
    }
}

void solve_GCD(){
    while(GCD == 0){
        if(A__ > B__)
            A__ -= B__;
        else if(A__ < B__)
            B__ -= A__;
        else
            GCD = A__;
    }
}

void out(){
    cout << GCD << endl;
    cout << LCM << endl;
}

int main() {
    in();
    solve_LCM();
    solve_GCD();
    out();
    return 0;
}