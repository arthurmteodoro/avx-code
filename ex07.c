/**
 * Escreva um programa que suporte a entrada de três vetores A, B e C e realize a multiplicação e
 * soma de seus elementos usando a instrução SIMD do AVX (_mm256_fmadd_). A entrada deve
 * ser selecionada de acordo com o tipo de dados dos vetores double (4 x 64bits), float (8 x 32bits) ou
 * integer (8 x 32 bits). Apresente o resultado convenientemente na tela.
 * 
 * Como compilar: gcc -mfma -o ex1.o ex01.c
 * É necessário que o processador suporte AVX2
*/

#include <immintrin.h>
#include <stdio.h>

int main() {
    // Cria o primeiro vetor
    __m256 vec1 = _mm256_setr_ps(0.0, 2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0);
    // Cria o segundo vetor
    __m256 vec2 = _mm256_setr_ps(1.0, 3.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0);

    // Imprime o primeiro vetor
    printf("VEC1:");
    for(int i = 0; i < 8; i++) {
        printf("%0.2f ", vec1[i]);
    }
    printf("\n");

    // Imprime o segundo vetor
    printf("VEC2:");
    for(int i = 0; i < 8; i++) {
        printf("%0.2f ", vec2[i]);
    }
    printf("\n");

    // Imprime o valor utilizado para o shuffle
    printf("Valor utilizado para o shuffle:\n");
    printf("Em binário: 01110100\n");
    printf("Em hexadecimal: 74\n");
    printf("Em decimal: %d\n\n", 0b01110100);

    // Aplica o shuffle nos vetores 1 e 2 com o decimal 116 e armazena no 
    // terceiro vetor
    __m256 vec3 = _mm256_shuffle_ps(vec1, vec2, 0b01110100);


    // Imprime o resultado do shuffle
    printf("SHUFFLE:");
    for(int i = 0; i < 8; i++) {
        printf("%0.2f ", vec3[i]);
    }
    printf("\n");



    return 0;
}