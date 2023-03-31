/*
    문제 설명

    햄버거 가게에서 일을 하는 상수는 햄버거를 포장하는 일을 합니다. 
    함께 일을 하는 다른 직원들이 햄버거에 들어갈 재료를 조리해 주면 조리된 순서대로 상수의 앞에 아래서부터 위로 쌓이게 되고, 
    상수는 순서에 맞게 쌓여서 완성된 햄버거를 따로 옮겨 포장을 하게 됩니다. 
    상수가 일하는 가게는 정해진 순서(아래서부터, 빵 – 야채 – 고기 - 빵)로 쌓인 햄버거만 포장을 합니다. 
    상수는 손이 굉장히 빠르기 때문에 상수가 포장하는 동안 속 재료가 추가적으로 들어오는 일은 없으며, 
    재료의 높이는 무시하여 재료가 높이 쌓여서 일이 힘들어지는 경우는 없습니다.

    예를 들어, 상수의 앞에 쌓이는 재료의 순서가 [야채, 빵, 빵, 야채, 고기, 빵, 야채, 고기, 빵]일 때, 상수는 여섯 번째 재료가 쌓였을 때, 
    세 번째 재료부터 여섯 번째 재료를 이용하여 햄버거를 포장하고, 아홉 번째 재료가 쌓였을 때, 
    두 번째 재료와 일곱 번째 재료부터 아홉 번째 재료를 이용하여 햄버거를 포장합니다. 
    즉, 2개의 햄버거를 포장하게 됩니다.

    상수에게 전해지는 재료의 정보를 나타내는 정수 배열 ingredient가 주어졌을 때, 
    상수가 포장하는 햄버거의 개수를 return 하도록 solution 함수를 완성하시오.

    제한사항

    1 ≤ ingredient의 길이 ≤ 1,000,000
    ingredient의 원소는 1, 2, 3 중 하나의 값이며, 순서대로 빵, 야채, 고기를 의미합니다.

    입출력 예

    ingredient	                result
    [2, 1, 1, 2, 3, 1, 2, 3, 1]	2
    [1, 3, 2, 1, 2, 1, 3, 1, 2]	0
*/


#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> ingredient) {
    
    int answer = 0;
    string strtmp;
    
    for ( auto i : ingredient ) {
        strtmp.append(to_string(i)); // ingredient vector의 모든 인자를 strtmp 문자열로 저장
    }
    
    int pos = 0;
    
    while (1) {
        
        size_t ret = strtmp.find("1231", pos); // 문자열로 저장된 strtmp에 pos 번째부터 Target 문자열이 존재한다면 string의 길이보다 작은 숫자를 반환
        
        if (ret > strtmp.length()) { // 문자열 내에 해당 조합이 없다면 반복문을 종료
            break;
        }
        
        answer++; // 한번의 검사를 마칠 때마다 하나의 햄버거가 생성됨
        strtmp.erase(ret,4); // ret는 Target 문자열을 find하였을 때 문자열의 시작지점을 반환하기 때문에 시작지점부터 "1231" 4자리의 문자열을 strtmp에서 제거
      
        if (ret > 2) { // 해당 문제의 조건은 100만자 까지 주어지기 때문에 ret를 처음에 발견하였다면 이전 pos에서는 해당 조합이 없다는 것을 의미
            pos = ret - 3; // position을 3칸 당겨 탐색 지점을 초기화 함으로 연산량을 줄임
        }
        
    }
    
    return answer;
}