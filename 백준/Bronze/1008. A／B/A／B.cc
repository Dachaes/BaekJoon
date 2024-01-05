#include <iostream>
using namespace std;

int main(){
    cout << fixed;
    cout.precision(11);

    int a, b;
    
    cin >> a >> b;
    long double c = double(a) / b;
    cout << c << endl;
    return 0;
}