#include <iostream>

using namespace std;

void hanoi(int n, int start, int mid, int end) {

    if (n == 1) {
        cout << start << " " << end << "\n"; // 가장 작은 원판에서 부터 시작, 
    }
    else {
        hanoi(n - 1, start, end, mid); // n-1개의 원판을 시작점에서 중간으로 옮김
        cout << start << " " << end << "\n"; // 가장 큰 원판을 마지막 지점에 옮김
        hanoi(n - 1, mid, start, end); // 옮겨진 n-1개의 원판을 마지막 지점으로 옮김
    }
}

int main() {
    int n;
    cin >> n;

    cout << (1 << n) - 1 << "\n"; // a_n+1 = 2*a_n + 1, a_1 = 1
    hanoi(n, 1, 2, 3);

    return 0;
}

/*
    n = 3 일 때
    3 1 2 3
    2 1 3 2
    1 1 2 3 : 1 3
    2 1 3 2 : 1 2
    1 3 1 2 : 3 2
    3 1 2 3 : 1 3
    2 2 1 3
    1 2 3 1 : 2 1
    2 2 1 3 : 2 3
    1 1 2 3 : 1 3
    
    

*/