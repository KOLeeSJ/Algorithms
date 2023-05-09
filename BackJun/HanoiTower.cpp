#include <iostream>

using namespace std;

void hanoi(int n, int start, int mid, int end) {

    if (n == 1) {
        cout << start << " " << end << "\n"; // ���� ���� ���ǿ��� ���� ����, 
    }
    else {
        hanoi(n - 1, start, end, mid); // n-1���� ������ ���������� �߰����� �ű�
        cout << start << " " << end << "\n"; // ���� ū ������ ������ ������ �ű�
        hanoi(n - 1, mid, start, end); // �Ű��� n-1���� ������ ������ �������� �ű�
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
    n = 3 �� ��
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