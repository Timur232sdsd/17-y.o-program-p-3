#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ifstream input("26-s1.txt");
    int n;
    input >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        input >> prices[i];
    }

    sort(prices.begin(), prices.end());

    int total_discounted_price = 0;
    int max_discounted_price = 0;
    int z = n / 2;

    for (int i = 0; i < z; i++) {
        if (i % 2 == 0 && prices[z + i] > 200) {
            total_discounted_price += prices[z + i] * 0.7;
            max_discounted_price = max(max_discounted_price, prices[z + i]);
        }
    }

    for (int i = z; i < n; i++) {
        total_discounted_price += prices[i];
    }

    total_discounted_price = ceil(total_discounted_price);

    cout << total_discounted_price << " " << max_discounted_price << endl;

    return 0;
}
