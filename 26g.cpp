#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Item {
    char type;
    int price;
    int quantity;
};

int main() {
    std::ifstream file("26-42.txt");
    if (!file.is_open()) {
        std::cout << "File not found." << std::endl;
        return 1;
    }

    int n, money;
    file >> n >> money;

    std::vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        file >> items[i].type >> items[i].price >> items[i].quantity;
    }

    std::vector<Item> typeA, typeZ;
    for (const auto& item : items) {
        if (item.type == 'A') {
            typeA.push_back(item);
        } else if (item.type == 'Z') {
            typeZ.push_back(item);
        }
    }

    std::sort(typeZ.begin(), typeZ.end(), [](const Item& a, const Item& b) {
        return a.price < b.price;
    });

    int usedMoney = 0, typeZQuantity = 0;
    for (const auto& item : typeZ) {
        int canBuy = std::min(money / item.price, item.quantity);
        typeZQuantity += canBuy;
        money -= canBuy * item.price;
        usedMoney += canBuy * item.price;
    }

    int typeAQuantity = 0;
    for (const auto& item : typeA) {
        int canBuy = std::min(money / item.price, item.quantity);
        typeAQuantity += canBuy;
        money -= canBuy * item.price;
        usedMoney += canBuy * item.price;
    }

    std::cout << typeAQuantity << " " << money << std::endl;

    return 0;
}