// BOJ_2448 : 별 찍기 11
#include <iostream>
using namespace std;
// N: 입력 받은 3x(2^k) 값 (3, 6, 12, 24, 48, ... ,1536 ,3072)
//    또한 matrix의 행의 크기 = 아랫변의 중간값
// matrix_col=N: 아랫변의 중간값이자 matrix의 행의 크기
// matrix_row: 큰 삼각형의 아랫변의 길이, 즉 matrix의 열의 크기
int N, matrix_col, matrix_row, start_x, start_y;
char star[3075][6145];

void in(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    matrix_col = N;
    matrix_row = N * 2 - 1;
    int row1 = N;
    int row2 = N;           
    // start_x, start_y 값  // N = 3, 6, 12, 24
    start_x = N / 2;        // x = 1, 3, 6, 12
    start_y = N - 1;        // y = 2, 5, 11, 23
    for(int i = 0; i < matrix_col; i++){
        for(int j = 0; j <= matrix_row; j++){
            if(j >= row1 - 1 && j <= row2 - 1)
                star[i][j] = '*';
            else
                star[i][j] = ' ';
        }
        row1--;     row2++;
    }
}

void star11(int x, int y, int size){
    int next_x[3] = {x, x, x};
    int next_y[3] = {y, y, y};
    int line;           if(size == 2)  line = 1;
                        else        line = size;
// Base case
    bool flag = 0;
    if(size == 2)
        flag = 1;

// Exceptional case     -> none
// Recursive case
    for(int i = 0; i < x; i++){
        for(int j = 0; j < line; j++){
            star[x + i][y - (line / 2) + j] = ' ';
        }
        line -= 2;
    }

    if(flag == 0){
        if(size != 5)
            next_x[0] = next_x[0] - ((size + 1) / 2 / 2);
        else    next_x[0] = next_x[0] - 2;
        next_x[1] = next_x[1] + ((size + 1) / 2 / 2);
        next_x[2] = next_x[1];
        next_y[1] = next_y[1] - ((size + 1) / 2);
        next_y[2] = next_y[2] + ((size + 1) / 2);
        size = (size + 1) / 2 - 1;

        star11(next_x[0], next_y[0], size);
        star11(next_x[1], next_y[1], size);
        star11(next_x[2], next_y[2], size);
    }
    else    return;

}

void out(){
    //int print_row = N;
    for(int i = 0; i < matrix_col; i++){      
        for(int j = 0; j < matrix_row; j++){    
            cout << star[i][j];
        }
        //print_row++;
        cout << endl;
    }
}

int main() {
    in();
    star11(start_x, start_y, N - 1);
    out();
    return 0;
}