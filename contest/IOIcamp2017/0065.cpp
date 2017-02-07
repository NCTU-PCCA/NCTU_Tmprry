#include <iostream>
constexpr int a[3][4] = {{2, 3, 5, 7}, {11, 13, 17, 19}, {23, 29, 31, 37}};
int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        for(int i = 0; i < n; i++) {
            if(i < 4) std::cout << "0";
            std::cout << (int) a[i/4][i%4] << std::endl;
        }
    }
}

