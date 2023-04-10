/*
    문제 설명
    비내림차순으로 정렬된 수열이 주어질 때, 다음 조건을 만족하는 부분 수열을 찾으려고 합니다.

    기존 수열에서 임의의 두 인덱스의 원소와 그 사이의 원소를 모두 포함하는 부분 수열이어야 합니다.
    부분 수열의 합은 k입니다.
    합이 k인 부분 수열이 여러 개인 경우 길이가 짧은 수열을 찾습니다.
    길이가 짧은 수열이 여러 개인 경우 앞쪽(시작 인덱스가 작은)에 나오는 수열을 찾습니다.
    수열을 나타내는 정수 배열 sequence와 부분 수열의 합을 나타내는 정수 k가 매개변수로 주어질 때, 위 조건을 만족하는 부분 수열의 시작 인덱스와 마지막 인덱스를 배열에 담아 return 하는 solution 함수를 완성해주세요. 이때 수열의 인덱스는 0부터 시작합니다.

    제한사항
    5 ≤ sequence의 길이 ≤ 1,000,000
    1 ≤ sequence의 원소 ≤ 1,000
    sequence는 비내림차순으로 정렬되어 있습니다.
    5 ≤ k ≤ 1,000,000,000
    k는 항상 sequence의 부분 수열로 만들 수 있는 값입니다.

*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// vector안의 pair 값의 차가 작은 순서대로 정렬하기 위한 비교함수

bool cmp(const pair<int, int>& a, const pair<int, int>& b) { 
    return a.second - a.first < b.second - b.first;
}

vector<int> solution(vector<int> sequence, int k) {

    int sum = sequence.at(0);

    vector<pair<int, int>> tmp; // 부분 수열의 start point와 end point를 저장하기 위한 임시 벡터 

    int leftidx = 0;
    int rightidx = 0;

    while (1) {

        if (sum == k) tmp.push_back({ leftidx,rightidx }); // sum k인 부분 수열의 시작점과 끝지점을 임시 벡터에 저장

        if (rightidx == sequence.size() && leftidx == sequence.size()) break; // 부분 수열을 가리키는 Index가 모두 sequence 함수의 마지막 부분을 가리킬 때 종료

        if (sum <= k && rightidx < sequence.size()) { // sum이 k보다 작을 때 right idx를 하나 올림  
            rightidx++;

            if (rightidx < sequence.size()) {
                sum += sequence.at(rightidx); //right idx를 올릴 때는 부분 수열을 더해줌
            }

        }

        else {

            if (leftidx < sequence.size()) {
                sum -= sequence.at(leftidx); // 이외의 경우는 left idx가 가리키는 원소 값을 뺴주고 left idx를 한칸 위로 올려서 다음 부분 수열부터 계산
            }

            leftidx++;
        }
        // 더블 포인터를 이용하여 시간복잡도 O(N)
    }

    stable_sort(tmp.begin(), tmp.end(), cmp); // 부분 수열의 시작점과 끝점의 차 (거리)가 가장 작은 pair가 처음으로 올 수 있도록 sorting,
    //이 때 거리가 동일할 때 먼저 입력 받은 부분의 pair가 뒤로 정렬되지 않도록 stable sorting

    return { tmp[0].first,tmp[0].second };
}


int main(void) {

    vector<int> answer;

    answer = solution({ 2,2,2,2,2 }, 6);

    for (auto i : answer) {
        cout << i << ' ';
    }
}