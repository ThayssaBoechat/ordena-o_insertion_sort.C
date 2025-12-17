#include <stdio.h>
#include <string.h>
#include <ctype.h>

void insertionSort(int array[], int tamanho) {
    int i, chave, j;
    for (i = 1; i < tamanho; i++) {
        chave = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > chave) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = chave;
    }
}

void imprimirArray(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    char entrada[20];
    int numeros[10];
    int tamanho = 0;

    // Mensagem solicitando entrada
    printf("Digite uma sequencia de numeros (max 10 digitos): ");
    scanf("%s", entrada);

    int len = strlen(entrada);

    if (len > 10) {
        printf("Erro: limite de 10 digitos excedido.\n");
        return 1;
    }

    for (int i = 0; i < len; i++) {
        if (isdigit(entrada[i])) {
            numeros[tamanho++] = entrada[i] - '0';
        } else {
            printf("Erro: apenas digitos de 0 a 9 sao permitidos.\n");
            return 1;
        }
    }

    insertionSort(numeros, tamanho);
    imprimirArray(numeros, tamanho);

    return 0;
}
