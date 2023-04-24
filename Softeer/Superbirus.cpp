/*
    수퍼바이러스가 숙주의 몸속에서 0.1초당 P배씩 증가한다.



    처음에 수퍼바이러스 K마리가 있었다면 N초 후에는 총 몇 마리의 수퍼바이러스로 불어날까?

    N초 동안 죽는 수퍼바이러스는 없다고 가정한다.



    수퍼바이러스는 일반 바이러스에 비해서 훨씬 오래 생존할 수 있기 때문에 N이 매우 클 수 있다.
*/

#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long fast_pow(long long base, long long exp) { // 거듭제곱의 값을 구하기 위한 함수
    long long result = 1;

    while (exp > 0) { // 연산량을 줄이기 위해 지수 표현식을 이용
        if (exp % 2 == 1) { // exp 가 홀 수 일때마다 지수를 더해줌
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD; // exp가 짝 수 일 경우 지수를 곱해줌
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