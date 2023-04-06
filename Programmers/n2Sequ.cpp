/*
    정수 n, left, right가 주어집니다. 다음 과정을 거쳐서 1차원 배열을 만들고자 합니다.

    n행 n열 크기의 비어있는 2차원 배열을 만듭니다.
    i = 1, 2, 3, ..., n에 대해서, 다음 과정을 반복합니다.
    1행 1열부터 i행 i열까지의 영역 내의 모든 빈 칸을 숫자 i로 채웁니다.
    1행, 2행, ..., n행을 잘라내어 모두 이어붙인 새로운 1차원 배열을 만듭니다.
    새로운 1차원 배열을 arr이라 할 때, arr[left], arr[left+1], ..., arr[right]만 남기고 나머지는 지웁니다.
    정수 n, left, right가 매개변수로 주어집니다. 주어진 과정대로 만들어진 1차원 배열을 return 하도록 solution 함수를 완성해주세요.


*/


#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 1 2 3 4 5 2 2 3 4 5 3 3 3 4 5 4 4 4 4 5 5 5 5 5 5
// n^2의 숫자 배열을 1열로 나열하면 위와 같음
// 규칙성 행의 시작부터 행 숫자에 해당하는 열까지 모두 행의 숫자로 동일
// 위와 같은 조건에 의해서 알고리즘을 구현

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    long long tmp = left;

    while (1) {

        if (answer.size() == right - left + 1) break; // 배열의 크기가 Right - Left이면 반복문을 종료

        if (tmp % n + 1 < tmp / n + 1) {
            answer.push_back(tmp / n + 1); 
        }

        else {
            answer.push_back(tmp % n + 1);
        }

        tmp++;

    }

    return answer;
}