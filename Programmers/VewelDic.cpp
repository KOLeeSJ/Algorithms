/*
    사전에 알파벳 모음 'A', 'E', 'I', 'O', 'U'만을 사용하여 만들 수 있는, 길이 5 이하의 모든 단어가 수록되어 있습니다.
    사전에서 첫 번째 단어는 "A"이고, 그다음은 "AA"이며, 마지막 단어는 "UUUUU"입니다.

    단어 하나 word가 매개변수로 주어질 때, 이 단어가 사전에서 몇 번째 단어인지 return 하도록 solution 함수를 완성해주세요.

    제한사항
    word의 길이는 1 이상 5 이하입니다.
    word는 알파벳 대문자 'A', 'E', 'I', 'O', 'U'로만 이루어져 있습니다.

    길이가 1 일 때 1
    길이가 2 일 때 6
    길이가 3 일 때 39
    길이가 4 일 때 

    입출력 예
    word	result
    "AAAAE"	6  
    "AAAE"	10 
    "I"	1563 
    "EIO"	1189
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> dict; // 모든 경우의 수를 저장할 벡터 선언
string temp[5] = { "A", "E", "I", "O", "U" }; // 모음 참조 값 선언

void makedict(int maxlen, string s) { // 재귀함수를 이용하여 모든 경우의 수를 dict에 저장
    if (maxlen == s.size()) { // solution 함수에서 maxlen이 1 ~ 5인 경우를 모두 호출
        dict.push_back(s);
        return;
    }

    for (int i = 0; i < 5; i++) {
        makedict(maxlen, s + temp[i]); // 재귀함수 ex ) 
                                       // maxlen == 1 -> A, E I, O ,U
                                       // maxlen == 2 -> A, AA, AE, AI, AO, AU, E, EA ~~ 로 깊이 우선탐색 수행
    }
}

int solution(string word) {
    int answer = 0;

    for (int i = 1; i <= 5; i++) { // 길이가 1인 경우의 수 부터 5인 경우의 수 까지를 모두 만들기 위한 반복문 선언
        makedict(i, ""); 
    }

    sort(dict.begin(), dict.end()); // dict를 순서대로 정렬

    for (int i = 0; i < dict.size(); i++) {
        if (dict.at(i) == word) {
            return i + 1;
        }
    }

}