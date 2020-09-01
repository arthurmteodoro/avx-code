/**
 * Escreva um programa que calcule a soma de dois vetores A e B do tipo double. Os vetores A e B
 * devem ser lidos da memória usando a instrução _mm256_load_pd. O resultado da operação
 * deve ser armazenado na memória usando a instrução _mm256_store_pd.
*/

#include <immintrin.h>
#include <stdio.h>

int main() {
    int i = 0;

    // aloca cada um dos 2 vetores de entrada e o de saida do tipo double com 4 elementos
    double* vet_a_double = (double*) aligned_alloc(32, 4*sizeof(double));
    double* vet_b_double = (double*) aligned_alloc(32, 4*sizeof(double));
    double* resultado = (double*) aligned_alloc(32, 4*sizeof(double));

    // le os valores do vetor A usando scaf dentro de um loop
    printf("Digite os elementos do vetor A:\n");
    for (i = 0; i < 4; i++) {
        printf("Digite o elemento %d: ", i);
        scanf("%lf", &vet_a_double[i]);
    }

    // le os valores do vetor B usando scaf dentro de um loop
    printf("Digite os elementos do vetor B:\n");
    for (i = 0; i < 4; i++) {
        printf("Digite o elemento %d: ", i);
        scanf("%lf", &vet_b_double[i]);
    }

    // carrega o vetor de double para um arranjo do avx usando a funcao _mm256_load_pd
    __m256d a = _mm256_load_pd(vet_a_double);
    __m256d b = _mm256_load_pd(vet_b_double);

    // faz o calculo de a + b usando avx
    __m256d result = _mm256_add_pd(a, b);

    // salva o vetor de 256-bits do avx em uma variavel na memoria
    _mm256_store_pd(resultado, result);

    // imprime o resultado da operacao na tela
    printf("\nResultado de A + B: \n");
    printf("%lf %lf %lf %lf\n", resultado[0], resultado[1], resultado[2], resultado[3]);

    return 0;
}