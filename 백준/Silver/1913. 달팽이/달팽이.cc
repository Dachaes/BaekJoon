// BOJ_1913 : 달팽이
#include <iostream>
using namespace std;
int N, M, x, y;
int arr[1000][1000];
// 아래->위, 왼쪽->오른쪽, 위->아래, 오른쪽->왼쪽
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
// type =========>  0       1       2       3
int type;   // dir type 저장

void in(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M;
    x = (N - 1) / 2;
    y = (N - 1) / 2;
    arr[x][y] = 1;
}

void snail(){
    int len = 1;    // 데이터 저장 시, 어떤 한 방향으로 저장되는 갯수
    bool temp = 0;
    int num = 2;
    // i의 반복 횟수 -> 3-5, 5-9, 7-13
    //i < 5 + 4 * ((N - 1) / 2 - 1)
    // len <= N
    for(int i = 0; len <= N; i++){
        for(int j = 0; j < len; j++){
            x += dir[type][0];  y += dir[type][1];
            arr[x][y] = num;
            num++;
        }
        if(type == 3)       type = 0;
        else                type++;
        
        if(temp == 0)       temp = 1;
        else                {temp = 0;   len++;}

        // 마지막 한 줄 저장
        if (len == N){
            for(int j = 0; j < (len - 1); j++){
                x += dir[type][0];  y += dir[type][1];
                arr[x][y] = num;
                num++;
            }
            len++;
        }
    }
}
void snail_search(int data){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(data == arr[i][j])
                cout << i + 1 << " " << j + 1 << endl;
        }
    }
}

void snail_print(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << arr[i][j];
            if (j < N - 1)
                cout << " ";
        }
        cout << endl;
    }
}

int main() {
    in();
    snail();
    snail_print();
    snail_search(M);
    return 0;
}