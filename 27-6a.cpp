
#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream fileA("27-17a.txt");
    std::ifstream fileB("27-17b.txt");

    int N;
    fileA >> N;

    std::vector<int> data(N);
    for (int i = 0; i < N; ++i) {
        fileA >> data[i];
    }
    
    int countA = 0, countB = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 5; j < N; ++j) {
            if ((data[i] + data[j]) % 2 != 0 && (data[i] * data[j]) % 13 == 0) {
                countA++;
            }
        }
    }

    fileB >> N;
    data.resize(N);
    for (int i = 0; i < N; ++i) {
        fileB >> data[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i + 5; j < N; ++j) {
            if ((data[i] + data[j]) % 2 != 0 && (data[i] * data[j]) % 13 == 0) {
                countB++;
            }
        }
    }

    std::cout << countA << " " << countB;

    fileA.close();
    fileB.close();

    return 0;
}
