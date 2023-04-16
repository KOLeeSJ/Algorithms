/*
    ���� ����
    � ���ڿ��� k���� ���� �������� �� ���� �� �ִ� ���� ū ���ڸ� ���Ϸ� �մϴ�.

    ���� ���, ���� 1924���� �� �� ���� �����ϸ� [19, 12, 14, 92, 94, 24] �� ���� �� �ֽ��ϴ�. �� �� ���� ū ���ڴ� 94 �Դϴ�.

    ���ڿ� �������� ���� number�� ������ ���� ���� k�� solution �Լ��� �Ű������� �־����ϴ�. 
    number���� k ���� ���� �������� �� ���� �� �ִ� �� �� ���� ū ���ڸ� ���ڿ� ���·� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

    ���� ����
    number�� 2�ڸ� �̻�, 1,000,000�ڸ� ������ �����Դϴ�.
    k�� 1 �̻� number�� �ڸ��� �̸��� �ڿ����Դϴ�.
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
    int len = number.length() - k; // ���;��ϴ� ��� string ����
    int cnt = 0;
    int idx = 1;

    stk.push(number[0]); // �ݺ����� �������� �� ���� ó�� ������ ���ϱ� ���� ���ڿ��� ���� ù ���ڸ� ���ÿ� ����

    while (true) { // �־��� ���ڿ����� �պκп� ���� ū ���� ������ ������ִ� �ݺ��� 
        if (cnt == k)  break; // ���� ������ ������ �����ϸ� �ݺ����� ����

        if (!stk.empty() && (int)stk.top() < (int)number[idx]) {  // ������ ���� top�� ���ڿ� idx��°�� ���ڿ��� ���Ͽ� idx�� �ش��ϴ� ���ڿ����� ���� ��� ����.
            stk.pop();
            cnt++; 
        }
        else {
            stk.push(number[idx]); // top ���ڿ��� ū ��� �׷��� ���ÿ� ����
            idx++;
        }
    }

    if (stk.size() > len) { // �ݺ����� ������ �� ������ ũ�Ⱑ target���̺��� ū ��� ���� ����  ex) 999991, 4�� ��� 99999�� ��ȯ��, idx�� ���ڿ��� ���̸� �ʰ��� ��� ������ ������ �񱳵�
        while (1) {

            if (stk.size() == len) break;

            stk.pop();
        }
    }

    while (!stk.empty()) { // ���ÿ� ���� ������ ������ ���ڿ��� �ݴ�� ���ڿ��� ��ȯ�Ǳ� ������ top���� �ϳ��� ���ڿ��� insert ���� reverse �Լ��� ������Ŵ
        answer.push_back(stk.top());
        stk.pop();
    }

    reverse(answer.begin(), answer.end());

    for (int i = idx; i < number.length(); i++) { // idx�� ������ �������� ���ϰ� �ݺ����� ����� ��� ���ڿ��� ���������� ����� ����
        if (answer.length() == number.length() - k) break;
        answer.push_back(number[i]);
    }

    return answer;
}
