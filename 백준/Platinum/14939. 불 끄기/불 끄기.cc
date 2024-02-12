#include <iostream>
using namespace std;

int num = 1000;                 // 정답 넣어줄 변수, 이상치는 1000 으로 설정
bool state[10][10];             // 매번 검사해줄 용도의 배열
bool fixedState[10][10];        // 처음 입력받을 값들 고정 저장될 배열

void click(int row, int col) {    // 해당 위치를 클릭했을 때 전구들의 상태를 바꿔줌
    state[row][col] = !state[row][col];
    if (row - 1 >= 0) state[row - 1][col] = !state[row - 1][col];
    if (row + 1 < 10) state[row + 1][col] = !state[row + 1][col];
    if (col - 1 >= 0) state[row][col - 1] = !state[row][col - 1];
    if (col + 1 < 10) state[row][col + 1] = !state[row][col + 1];
}
 
int check() {  // state 배열이 유효한지, 유효하다면 클릭 수는 몇회인지 반환

    int temp = 0;

    for (int r = 1; r < 10; r++) {                           // 첫 줄은 메인에서 처리됐으므로 두번째 줄부터 시작
        for (int c = 0; c < 10; c++){
            if (state[r - 1][c]){                            // 바로 윗 줄의 같은 칸의 전구가 켜져있는 상태면 무조건 눌러야 함
                click(r, c);
                temp++;
            }
        }
    }
    for (int r = 0; r < 10; r++) {                           // 쭉 검사했는데 켜져있는 전구가 있으면
        for (int c = 0; c < 10; c++) {
            if (state[r][c] == true) return 1000;            // 불가능함, 1000 반환
        }  
    }

    return temp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    char temp;

    for (int r = 0; r < 10; r++){
        for (int c = 0; c < 10; c++) {
            cin >> temp;
            if (temp == 'O') fixedState[r][c] = true;        // 처음에 정보 입력 받음
        }
    }
    for (int p = 0; p < 1024; p++) {                         // 첫 줄 10개를 각각 킬지/끌지 에 대해서 모든 경우의 수 탐색                                                  //  (2의 10승)
        for (int r = 0; r < 10; r++){
            for (int c = 0; c < 10; c++){                    // 해당 반복문을 수행하기 위해 state 배열을 초기화
                state[r][c] = fixedState[r][c];
            }
        }
        int ret = 0;
        for (int i = 0; i < 10; i++) {                       // 비트마스킹을 통해 첫 줄 10개의 전구를 누를지 말지 판단
            if (p & (1 << i)) {                              // 해당 전구를 눌러야 하는 위치라면
                ret++;                                       // 누름 처리
                click(0, i);
            }
        }
        ret += check();                                      // state 에 1024번 중 현재 반복(첫 줄 전구)의 상태 담겨있음
        if (ret < num) num = ret;                            // 최솟값 갱신
    }

    cout << (num == 1000 ? -1 : num) << '\n';                // 모든 경우의 수가 이상치 반환할 경우 불가능 -1 출력

    return 0;
}
