#include "util.hpp"

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

std::vector<int> *criaVector() {
    size_t n;
    std::cout << "Digite quantos termos seu vetor vai ter\n";
    std::cin >> n;

    return new std::vector<int>(n);
}

void leVector(std::vector<int> &v) {
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << "Digite o " << i + 1 << "o termo:\n";
        std::cin >> v[i];
    }
}

void ordenaVector(std::vector<int> &v) { std::sort(v.begin(), v.end()); }

void printVector(const std::vector<int> &v) {
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

void liberaVector(std::vector<int> *v) { delete v; }

double raizQuadrada(double n) { return std::sqrt(n); }