/*

    문제 설명
    초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때, 
    가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 solution 함수를 완성하세요.

    제한사항
    prices의 각 가격은 1 이상 10,000 이하인 자연수입니다.
    prices의 길이는 2 이상 100,000 이하입니다.

    입출력 예
    prices	        return
    [1, 2, 3, 2, 3]	[4, 3, 1, 1, 0]

*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    int tmp = 1;

    for (int i = 0; i < prices.size() - 1; i++) {

        tmp = 1; // 다음시점을 고려하는 순간부터 1일 동안 가격을 유지한 개념으로 tmp의 값은 1부터 시작, 매 반복마다 초기화

        for (int j = i + 1; j < prices.size() - 1; j++) { 
            if (prices.at(i) <= prices.at(j)) { // 주식의 가격이 떨어지지 않는 경우 하루 씩 증가
                tmp++;
            }

            else { // 주식의 가격이 떨어진 경우 반복문을 종료 시킴
                break;
            }
        }

        answer.push_back(tmp); // 일자를 벡터에 삽입
    }

    answer.push_back(0); // 해당 문제의 마지막 반환 값은 반드시 0

    return answer;
}