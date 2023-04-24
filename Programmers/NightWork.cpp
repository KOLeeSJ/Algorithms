/*
    문제 설명
    회사원 Demi는 가끔은 야근을 하는데요, 야근을 하면 야근 피로도가 쌓입니다. 
    야근 피로도는 야근을 시작한 시점에서 남은 일의 작업량을 제곱하여 더한 값입니다. 
    Demi는 N시간 동안 야근 피로도를 최소화하도록 일할 겁니다.Demi가 1시간 동안 작업량 1만큼을 처리할 수 있다고 할 때, 
    퇴근까지 남은 N 시간과 각 일에 대한 작업량 works에 대해 야근 피로도를 최소화한 값을 리턴하는 함수 solution을 완성해주세요.

    제한 사항
    works는 길이 1 이상, 20,000 이하인 배열입니다.
    works의 원소는 50000 이하인 자연수입니다.
    n은 1,000,000 이하인 자연수입니다.

    입출력 예
    works	n	result
    [4, 3, 3]	4	12
    [2, 1, 2]	1	6
    [1,1]	3	0
*/


#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) { // 해당 문제는 벡터안의 값들의 차가 적으면 적을수록 결과 값이 작음.
    long long answer = 0;
    priority_queue<long long> pq(works.begin(),works.end()); // 우선순위 큐를 이용하여 문제를 해결하기 위해 선언
    
    long long tmp = 0;

    while (n > 0) { // 내림차순으로 정렬된 우선순위 큐의 top 값을 -1 씩 감소시키며 큐 안의 값들의 차를 줄임.
        tmp = pq.top();
        pq.pop();

        tmp -= 1;
        pq.push(tmp);
        
        n -= 1;
    }

    while(!pq.empty()) { // 큐 안의 값들을 제곱하여 결과로 반환
        tmp = pq.top();
        answer = tmp * tmp;
        pq.pop();
    }

    return answer;
}

int main() {

    solution(4, { 4,3,3 });

    return 0;
}