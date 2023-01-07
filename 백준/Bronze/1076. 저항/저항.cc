#include <iostream>
#include <string>

using namespace std;
string resistance_color1, resistance_color2, resistance_color3;

void add_value(string, string, string);
long long int resistance_value(string, int);

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    getline(cin, resistance_color1);
    getline(cin, resistance_color2);
    getline(cin, resistance_color3);

    add_value(resistance_color1,resistance_color2,resistance_color3);
    
    return 0;
}

void add_value(string color1, string color2, string color3){
    int color1_value = (int)resistance_value(color1,1);
    int color2_value = (int)resistance_value(color2,2);
    long long int color3_value = resistance_value(color3,3);

    cout << (color1_value*10 + color2_value) * color3_value << endl;
}

long long int resistance_value(string color, int sequence){
    long long int value;
    if (sequence == 1 || sequence == 2){
        if (color == "black")
            value = 0;
        else if (color == "brown")
            value = 1;
        else if (color == "red")
            value = 2;
        else if (color == "orange")
            value = 3;
        else if (color == "yellow")
            value = 4;
        else if (color == "green")
            value = 5;
        else if (color == "blue")
            value = 6;
        else if (color == "violet")
            value = 7;
        else if (color == "grey")
            value = 8;
        else if (color == "white")
            value = 9;
    }

    else {
        if (color == "black")
            value = 1;
        else if (color == "brown")
            value = 10;
        else if (color == "red")
            value = 100;
        else if (color == "orange")
            value = 1000;
        else if (color == "yellow")
            value = 10000;
        else if (color == "green")
            value = 100000;
        else if (color == "blue")
            value = 1000000;
        else if (color == "violet")
            value = 10000000;
        else if (color == "grey")
            value = 100000000;
        else if (color == "white")
            value = 1000000000;
    }
    return value;
}