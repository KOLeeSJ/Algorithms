/*
    문제 설명
    어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.

    예를 들어, 숫자 1924에서 수 두 개를 제거하면 [19, 12, 14, 92, 94, 24] 를 만들 수 있습니다. 이 중 가장 큰 숫자는 94 입니다.

    문자열 형식으로 숫자 number와 제거할 수의 개수 k가 solution 함수의 매개변수로 주어집니다. 
    number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return 하도록 solution 함수를 완성하세요.

    제한 조건
    number는 2자리 이상, 1,000,000자리 이하인 숫자입니다.
    k는 1 이상 number의 자릿수 미만인 자연수입니다.
*/

#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    stack<char> stk;
    string answer = "";
    int len = number.length() - k; // 나와야하는 결과 string 길이
    int cnt = 0;
    int idx = 1;

    stk.push(number[0]); // 반복문에 진입했을 때 가장 처음 조건을 비교하기 위해 문자열의 가장 첫 문자를 스택에 쌓음

    while (true) { // 주어진 문자열에서 앞부분에 가장 큰 수가 남도록 만들어주는 반복문 
        if (cnt == k)  break; // 버린 문자의 개수에 도달하면 반복문을 종료

        if (!stk.empty() && (int)stk.top() < (int)number[idx]) {  // 스택의 가장 top의 숫자와 idx번째의 문자열과 비교하여 idx에 해당하는 문자열보다 작을 경우 버림.
            stk.pop();
            cnt++; 
        }
        else {
            stk.push(number[idx]); // top 문자열이 큰 경우 그래도 스택에 쌓음
            idx++;
        }
    }

    if (stk.size() > len) { // 반복문이 끝났을 때 스택의 크기가 target길이보다 큰 경우 전부 버림  ex) 999991, 4일 경우 99999가 반환됨, idx가 문자열의 길이를 초과한 경우 쓰레기 값들이 비교됨
        while (1) {

            if (stk.size() == len) break;

            stk.pop();
        }
    }

    while (!stk.empty()) { // 스택에 쌓인 구조는 원래의 문자열과 반대로 문자열에 반환되기 떄문에 top부터 하나씩 문자열에 insert 이후 reverse 함수로 반전시킴
        answer.push_back(stk.top());
        stk.pop();
    }

    reverse(answer.begin(), answer.end());

    for (int i = idx; i < number.length(); i++) { // idx가 끝까지 도달하지 못하고 반복문이 종료된 경우 문자열의 마지막까지 결과에 삽입
        if (answer.length() == number.length() - k) break;
        answer.push_back(number[i]);
    }

    return answer;
}
