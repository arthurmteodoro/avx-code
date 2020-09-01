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
    __m256 vec1 = _mm256_setr_ps(0.0, 2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0);
    // __m256 vec1 = _mm256_setr_ps(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
    __m256 vec2 = _mm256_setr_ps(1.0, 3.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0);
    // __m256 vec2 = _mm256_setr_ps(9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);

    printf("VEC1: ");
    for(int i = 0; i < 8; i++) {
        printf("%f ", vec1[i]);
    }
    printf("\n");

    printf("VEC2: ");
    for(int i = 0; i < 8; i++) {
        printf("%f ", vec2[i]);
    }
    printf("\n");

    __m256 vec3 = _mm256_shuffle_ps(vec1, vec2, 0x29);

    printf("SHUFFLE: ");
    for(int i = 0; i < 8; i++) {
        printf("%f ", vec3[i]);
    }
    printf("\n");



    return 0;
}