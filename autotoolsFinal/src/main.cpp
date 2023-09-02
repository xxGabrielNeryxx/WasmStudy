#include "util.hpp"
#include "util1.hpp"

int main() {
    int n_ezimo_termo;
    std::cout << "Digite o qual termo da sequencia de fibbonaci quer saber:\n";
    std::cin >> n_ezimo_termo;
    std::cout << fibonacci(n_ezimo_termo) << "\n";

    std::vector<int> *v = criaVector();
    leVector(*v);
    ordenaVector(*v);
    printVector(*v);
    std::cout << (*v)[0] <<"\n";
    liberaVector(v);

    int numero_raiz;
    std::cout << "Digite o numero que quer calcular a raiz:\n";
    std::cin >> numero_raiz;
    std::cout << raizQuadrada(numero_raiz) << "\n";

    printHello();

    return 0;
}