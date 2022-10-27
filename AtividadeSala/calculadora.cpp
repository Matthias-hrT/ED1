#include <iostream>
#include <cmath>

int main()
{
    int opcao, numero1, numero2;

    std::cout << " --->>>CALCULADORA<<<---" << std::endl;
    std::cout << " 1 <- Adição" << std::endl;
    std::cout << " 2 <- Subtração" << std::endl;
    std::cout << " 3 <- Divição" << std::endl;
    std::cout << " 4 <- Multiplicação" << std::endl;
    std::cout << " 5 <- Raiz" << std::endl;
    std::cout << " 0 <- Sair\n" << std::endl;
    std::cout << " Selecione a operação: ";
    std::cin >> opcao;

    if (opcao != 0)
    {
        if (opcao == 5)
        {
            std::cout << "\n Digite um número: ";
            std::cin >> numero1;
        }
        else
        {
            std::cout << "\n Digite um número: ";
            std::cin >> numero1;

            std::cout << "\n Digite um número: ";
            std::cin >> numero2;
        }
    }

    switch (opcao)
    {
    case 1:
        std::cout << "\n\n A soma é: " << (numero1 + numero2) << "\n" << std::endl;
        break;

    case 2:
        std::cout << "\n\n A subtração é: " << (numero1 - numero2) << "\n" << std::endl;
        break;

    case 3:
        std::cout << "\n\n A divisão é: " << (numero1 / numero2);
        if ((numero1 % numero2) > 0)
            std::cout << "\n O resto da divisão é: " << (numero1 % numero2) << "\n" << std::endl;
        break;

    case 4:
        std::cout << "\n\n A multiplicação é: " << (numero1 * numero2) << "\n" << std::endl;
        break;

    case 5:
        std::cout << "\n\n A raiz de " << numero1 << " é: " << (sqrt(numero1)) << "\n" << std::endl;
        break;

    case 0:
        std::cout << "\n\n !!!Tchauzinho!!!\n" << std::endl;
        break;

    default:
        break;
    }

    return 0;
}