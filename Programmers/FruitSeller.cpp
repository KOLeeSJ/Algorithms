/*
    ���� ����� ��� ���ڸ� �����ϰ� �ֽ��ϴ�. 
    ����� ���¿� ���� 1������ k�������� ������ �з��ϸ�, k���� �ֻ�ǰ�� ����̰� 1���� ����ǰ�� ����Դϴ�. 
    ��� �� ������ ������ ������ ���� �����˴ϴ�.

    �� ���ڿ� ����� m���� ��� �����մϴ�.
    ���ڿ� ��� ��� �� ���� ���� ������ p (1 �� p �� k)���� ���, ��� �� ������ ������ p * m �Դϴ�.
    ���� ����� ������ ���� ����� �Ⱦ��� ��, ���� �� �ִ� �ִ� ������ ����ϰ��� �մϴ�.
    (����� ���� �����θ� �Ǹ��ϸ�, ���� ����� �����ϴ�)

    ���� ���, k = 3, m = 4, ��� 7���� ������ [1, 2, 3, 1, 2, 3, 1]�̶��, ������ ���� [2, 3, 2, 3]���� ������ ��� ���� 1���� ����� �Ǹ��Ͽ� �ִ� ������ ���� �� �ֽ��ϴ�.

    (���� ��� ����) x (�� ���ڿ� ��� ��� ����) x (������ ����) = 2 x 4 x 1 = 8
    ����� �ִ� ���� k, �� ���ڿ� ���� ����� �� m, ������� ���� score�� �־����� ��, ���� ����� ���� �� �ִ� �ִ� ������ return�ϴ� solution �Լ��� �ϼ����ּ���.

    ���ѻ���
    3 �� k �� 9
    3 �� m �� 10
    7 �� score�� ���� �� 1,000,000
    1 �� score[i] �� k
    ������ �߻����� �ʴ� ��쿡�� 0�� return ���ּ���.

    ����� ��
    k	m	score	                                result
    3	4	[1, 2, 3, 1, 2, 3, 1]	                8
    4	3	[4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2]	33

*/


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;

    if (score.size() < m) return 0; // �� ����� ������ �� ���ڿ� ä�����ϴ� �������� ���� ��� ������ �߻����� ����

    vector<vector<int>> boxes;
    vector<int> tmp;

    sort(score.begin(), score.end(), greater<>()); // ���� �ȿ� ���� ���� ������ ���� ����� ������ �ݿ��Ǳ� ������ ���� ū ������ ������� ���������� ��� ���� �������� Sorting

    for (int i = 0; i <= score.size() - m; i += m) { // tmp�� ����� m���� �й��ؼ� ������� �ݺ��� ���� (�̶� ������ ���ڿ� ���� ������ m�� ���� ���� ��� ���ǿ� ���� Ż��)

        tmp.clear();

        for (int j = i; j < i + m; j++) { // tmp�� ����� m���� �й�
            tmp.push_back(score.at(j));
        }

        boxes.push_back(tmp);
    }

    for (auto i : boxes) { // Range based for ���� ����Ͽ� ��� ������ ���� ���� ������ ������ answer�� ������
        answer += i.at(i.size() - 1) * m;
    }

    return answer;
}