/*
    문제 설명
    자연수 n 개로 이루어진 중복 집합(multi set, 편의상 이후에는 "집합"으로 통칭) 중에 다음 두 조건을 만족하는 집합을 최고의 집합이라고 합니다.

    각 원소의 합이 S가 되는 수의 집합
    위 조건을 만족하면서 각 원소의 곱 이 최대가 되는 집합
    예를 들어서 자연수 2개로 이루어진 집합 중 합이 9가 되는 집합은 다음과 같이 4개가 있습니다.
    { 1, 8 }, { 2, 7 }, { 3, 6 }, { 4, 5 }
    그중 각 원소의 곱이 최대인 { 4, 5 }가 최고의 집합입니다.

    집합의 원소의 개수 n과 모든 원소들의 합 s가 매개변수로 주어질 때, 최고의 집합을 return 하는 solution 함수를 완성해주세요.

    제한사항
    최고의 집합은 오름차순으로 정렬된 1차원 배열(list, vector) 로 return 해주세요.
    만약 최고의 집합이 존재하지 않는 경우에 크기가 1인 1차원 배열(list, vector) 에 -1 을 채워서 return 해주세요.
    자연수의 개수 n은 1 이상 10,000 이하의 자연수입니다.
    모든 원소들의 합 s는 1 이상, 100,000,000 이하의 자연수입니다.
    */


#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, int s) { // 합이 s인 n개의 자연수 중 곱이 가장 큰 값이 되기 위한 값의 Vector를 반환하는 함수
    vector<int> answer;
    int i = 0;
    int target = n;

    if (s / n == 0) return { -1 }; // s < n 인 경우 n개의 자연수로 s를 만들지 못함

    while (1) {

        if (answer.size() == target) break; // answer의 갯수가 n개가 되면 반복문을 종료시킴

        answer.push_back((s / n)); 

        s -= s / n;
        n--;

        // 곱이 값이 가장 크기 위해서는 자연수의 분포가 작아야하기 때문에 s/n을 나눈 값부터 n을 감소시키며 answer에 삽입
    }

    return answer;
}

int main(void) {

    vector<int> answer = solution(2, 9);

    for (auto i : answer) {
        cout << i << ' ';
    }

    return 0;

}