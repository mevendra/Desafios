#include <assert.h>
#include <stdio.h> 
#include <utility> 
#include <list>

int fibonacci_recursiva(int numero) {
    assert(numero >= 0);
    if (numero == 0) {
        return 0;
    } else if (numero == 1) {
        return 1;
    } else {
        return fibonacci_recursiva(numero - 1) + fibonacci_recursiva(numero - 2);
    }
}

std::pair<int, int> recursao(std::pair<int, int> par, int it) {
    it--;
    std::pair<int, int> novo_par = std::make_pair(par.second, par.first + par.second);
    if (it == 0) {
        return novo_par;
    } else {
        return recursao(novo_par, it);
    }
}

int fibonacci_recursiva_melhor(int numero) {
    assert(numero >= 0);
    if (numero == 0) {
        return 0;
    } else if (numero == 1) {
        return 1;
    } else {
        std::pair<int, int> par= recursao(std::make_pair(0, 1), numero - 1);

        return par.second;
    }
}

int fibonacci_linear(int numero) {
    assert(numero >= 0);
    if (numero == 0) {
        return 0;
    } else if (numero == 1) {
        return 1;
    } else {
        int menos_um = 1;
        int menos_dois = 0;
        int soma = menos_um + menos_dois;
        for (int i = 2; i < numero; i++) {
            menos_dois = menos_um;
            menos_um = soma;

            soma = menos_um + menos_dois;
        }
        return soma;
    }
}

std::list<int> primos_recursiva(int numero) {
    assert(numero > 1);
    if (numero == 2) {
        std::list<int> lista;
        lista.push_back(2);
        return lista;
    }

    std::list<int> lista = primos_recursiva(numero - 1);
    bool eh_primo = true;
    for (int i: lista) {
        if (numero % i == 0) {
            eh_primo = false;
            break;
        }
    }
    if (eh_primo) {
        lista.push_back(numero);
    }

    return lista;
}

std::list<int> primos_linear(int numero) {
    assert(numero > 1);
    std::list<int> lista;
    lista.push_back(2);
    for(int i = 3; i <= numero; i+=2) {
        bool adicionar = true;
        for (int j: lista) {
            if (i % j == 0) {
                adicionar = false;
                break;
            }
        }
        if (adicionar) {
            lista.push_back(i);
        }
    }
    return lista;
}

int main() {
    //Teste Fibonacci
    for (int i = 0; i <= 20; i++) {
        //int resultado_recursivo = fibonacci_recursiva(i);
        int resultado_linear = fibonacci_linear(i);
        int resultado_recursivo_melhor = fibonacci_recursiva_melhor(i);
        printf("Fibonacci(%d) = %d\n", i, resultado_recursivo_melhor);

        assert(resultado_linear == resultado_recursivo_melhor);
    }

    //Teste Primos
    int teste_primos = 20;
    std::list<int> resultado_recursivo = primos_recursiva(teste_primos);
    std::list<int> resultado_linear = primos_linear(teste_primos);
    assert(resultado_recursivo.size() == resultado_linear.size());

    printf("Primos até %d: ", teste_primos);
    for (int j: resultado_linear)
        printf("%d ", j);
    printf("\n");
    
    return 0;
}