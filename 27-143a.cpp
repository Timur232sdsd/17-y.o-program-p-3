
#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream fileB("27-143b.txt");

    int N, K;

    std::vector<int> dataA(N);
    for (int i = 0; i < N; ++i) {
        fileB >> dataA[i];
    }

    fileB >> N >> K;

    std::vector<int> dataB(N);
    for (int i = 0; i < N; ++i) {
        fileB >> dataB[i];
    }

    int maxSumA = 0, maxSumB = 0;

    for (int i = 0; i < N - K + 1; ++i) {
        int sum = 0;
        for (int j = i; j < i + K; ++j) {
            sum += dataA[j];
        }
        if (sum % 68 == 0 && sum > maxSumA) {
            maxSumA = sum;
        }
    }

    for (int i = 0; i < N - K + 1; ++i) {
        int sum = 0;
        for (int j = i; j < i + K; ++j) {
            sum += dataB[j];
        }
        if (sum % 68 == 0 && sum > maxSumB) {
            maxSumB = sum;
        }
    }

    std::cout << maxSumA << " " << maxSumB << std::endl;

    fileB.close();

    return 0;
}
