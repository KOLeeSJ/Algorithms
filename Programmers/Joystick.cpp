#include <algorithm>
#include <string>

using namespace std;

// 문제 다시 이해해야됨

int solution(string name) {
    int n = name.size();
    int upDown = 0;
    int leftRight = n - 1;

    for (int i = 0; i < n; i++) {
        upDown += min(name[i] - 'A', 'Z' - name[i] + 1);

        int ii = i + 1;
        while (ii < n && name[ii] == 'A')
            ii++;

        int newLeftRight = i + n - ii + min(n - ii, i);

        leftRight = min(leftRight, newLeftRight);
    }

    return upDown + leftRight;
}