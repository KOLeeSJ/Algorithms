/*
    ���۹��̷����� ������ ���ӿ��� 0.1�ʴ� P�辿 �����Ѵ�.



    ó���� ���۹��̷��� K������ �־��ٸ� N�� �Ŀ��� �� �� ������ ���۹��̷����� �Ҿ��?

    N�� ���� �״� ���۹��̷����� ���ٰ� �����Ѵ�.



    ���۹��̷����� �Ϲ� ���̷����� ���ؼ� �ξ� ���� ������ �� �ֱ� ������ N�� �ſ� Ŭ �� �ִ�.
*/

#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long fast_pow(long long base, long long exp) { // �ŵ������� ���� ���ϱ� ���� �Լ�
    long long result = 1;

    while (exp > 0) { // ���귮�� ���̱� ���� ���� ǥ������ �̿�
        if (exp % 2 == 1) { // exp �� Ȧ �� �϶����� ������ ������
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD; // exp�� ¦ �� �� ��� ������ ������
        exp /= 2;
    }

    return result;
}

int main() {
    long long K, P, N, answer;
   
    cin >> K >> P >> N;

    answer = (K * fast_pow(P, N * 10)) % MOD;

    cout << answer << endl;

    return 0;
}