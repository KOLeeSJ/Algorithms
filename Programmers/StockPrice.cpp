/*

    ���� ����
    �� ������ ��ϵ� �ֽİ����� ��� �迭 prices�� �Ű������� �־��� ��, 
    ������ �������� ���� �Ⱓ�� �� �������� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

    ���ѻ���
    prices�� �� ������ 1 �̻� 10,000 ������ �ڿ����Դϴ�.
    prices�� ���̴� 2 �̻� 100,000 �����Դϴ�.

    ����� ��
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

        tmp = 1; // ���������� ����ϴ� �������� 1�� ���� ������ ������ �������� tmp�� ���� 1���� ����, �� �ݺ����� �ʱ�ȭ

        for (int j = i + 1; j < prices.size() - 1; j++) { 
            if (prices.at(i) <= prices.at(j)) { // �ֽ��� ������ �������� �ʴ� ��� �Ϸ� �� ����
                tmp++;
            }

            else { // �ֽ��� ������ ������ ��� �ݺ����� ���� ��Ŵ
                break;
            }
        }

        answer.push_back(tmp); // ���ڸ� ���Ϳ� ����
    }

    answer.push_back(0); // �ش� ������ ������ ��ȯ ���� �ݵ�� 0

    return answer;
}