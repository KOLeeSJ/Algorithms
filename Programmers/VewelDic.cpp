/*
    ������ ���ĺ� ���� 'A', 'E', 'I', 'O', 'U'���� ����Ͽ� ���� �� �ִ�, ���� 5 ������ ��� �ܾ ���ϵǾ� �ֽ��ϴ�.
    �������� ù ��° �ܾ�� "A"�̰�, �״����� "AA"�̸�, ������ �ܾ�� "UUUUU"�Դϴ�.

    �ܾ� �ϳ� word�� �Ű������� �־��� ��, �� �ܾ �������� �� ��° �ܾ����� return �ϵ��� solution �Լ��� �ϼ����ּ���.

    ���ѻ���
    word�� ���̴� 1 �̻� 5 �����Դϴ�.
    word�� ���ĺ� �빮�� 'A', 'E', 'I', 'O', 'U'�θ� �̷���� �ֽ��ϴ�.

    ���̰� 1 �� �� 1
    ���̰� 2 �� �� 6
    ���̰� 3 �� �� 39
    ���̰� 4 �� �� 

    ����� ��
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

vector<string> dict; // ��� ����� ���� ������ ���� ����
string temp[5] = { "A", "E", "I", "O", "U" }; // ���� ���� �� ����

void makedict(int maxlen, string s) { // ����Լ��� �̿��Ͽ� ��� ����� ���� dict�� ����
    if (maxlen == s.size()) { // solution �Լ����� maxlen�� 1 ~ 5�� ��츦 ��� ȣ��
        dict.push_back(s);
        return;
    }

    for (int i = 0; i < 5; i++) {
        makedict(maxlen, s + temp[i]); // ����Լ� ex ) 
                                       // maxlen == 1 -> A, E I, O ,U
                                       // maxlen == 2 -> A, AA, AE, AI, AO, AU, E, EA ~~ �� ���� �켱Ž�� ����
    }
}

int solution(string word) {
    int answer = 0;

    for (int i = 1; i <= 5; i++) { // ���̰� 1�� ����� �� ���� 5�� ����� �� ������ ��� ����� ���� �ݺ��� ����
        makedict(i, ""); 
    }

    sort(dict.begin(), dict.end()); // dict�� ������� ����

    for (int i = 0; i < dict.size(); i++) {
        if (dict.at(i) == word) {
            return i + 1;
        }
    }

}