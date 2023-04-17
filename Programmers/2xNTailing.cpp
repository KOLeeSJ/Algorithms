/*
    문제 설명
    가로 길이가 2이고 세로의 길이가 1인 직사각형모양의 타일이 있습니다. 
    이 직사각형 타일을 이용하여 세로의 길이가 2이고 가로의 길이가 n인 바닥을 가득 채우려고 합니다. 
    타일을 채울 때는 다음과 같이 2가지 방법이 있습니다.

    타일을 가로로 배치 하는 경우
    타일을 세로로 배치 하는 경우

    직사각형의 가로의 길이 n이 매개변수로 주어질 때, 이 직사각형을 채우는 방법의 수를 return 하는 solution 함수를 완성해주세요.

    제한사항
    가로의 길이 n은 60,000이하의 자연수 입니다.
    경우의 수가 많아 질 수 있으므로, 경우의 수를 1,000,000,007으로 나눈 나머지를 return해주세요.
*/


#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long dp[60001] = { 0 }; // 이전에 만들었던 결과를 중복으로 계산하지 않기위한 배열 선언

long long squre(long long num) {

    if (num <= 3) return num; // n이 3이하 일 떄의 경우의 수는 n과 같음

    if (dp[num - 1] != -1) return dp[num - 1]; // dp 배열이 한번 계산 되었을 경우 배열안의 값을 반환

    dp[num - 1] = (squre(num - 1) + squre(num - 2)) % 1000000007; // 새로운 계산이 될 때마다 배열에 값을 저장

    return (squre(num - 1) + squre(num - 2)) % 1000000007; // 재귀함수 호출 위의 문제의 경우 num번째 경우의 수는 num-1, num-2 번째의 경우의 수의 합과 같음
}

int solution(int n) {

    for (int i = 0; i < 60001; i++) { // 전역변수로 선언한 배열을 -1로 초기화
        dp[i] = -1;
    }

    long long answer = squre(n);

    return answer;
}
