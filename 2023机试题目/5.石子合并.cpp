#include <stdio.h>
#include <limits.h>

// ��̬�滮���������غϲ�ʯ�ӵ���С����
int minCostToMergeStones(int stones[], int n, int k) {
    // Ԥ��������ǰ׺��
    int prefixSum[n + 1];
    prefixSum[0] = 0;
    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + stones[i];
    }

    // ������ά�������ڴ洢�м���
    int dp[n][n];

    // ��ʼ����ά����
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    // ��̬�滮����
    for (int len = k; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int m = i; m < j; m += k - 1) {
                dp[i][j] = (dp[i][j] < dp[i][m] + dp[m + 1][j]) ? dp[i][j] : (dp[i][m] + dp[m + 1][j]);
            }

            if ((j - i) % (k - 1) == 0) {
                dp[i][j] += prefixSum[j + 1] - prefixSum[i];
            }
        }
    }

    // �������ս��
    return dp[0][n - 1];
}

int main() {
    int stones[] = {3, 2, 4, 1, 5};
    int n = sizeof(stones) / sizeof(stones[0]);
    int k = 2;

    int result = minCostToMergeStones(stones, n, k);

    printf("Minimum cost to merge stones: %d\n", result);

    return 0;
}

