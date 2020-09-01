/**
 * Os valores dos vetores A, B e C são do tipo double e devem ser carregado na memória via terminal.
 * Desenvolva um programa que dado que os vetores A, B e C foram carregados, e usando uma
 * instrução FMA (Fused Multiply and Add ) realize a operação:
 * 
 * Como compilar: gcc -mfma -o ex5.o ex05.c
 * É necessário que o processador suporte AVX2
 * Alunos: Arthur Alexsander Martins Teodoro
 *         Arthur Henrique Sousa Cruz
*/

#include <immintrin.h>
#include <stdio.h>

int main() {
    int i = 0;

    // aloca cada um dos 3 vetores de entrada do tipo double com 4 elementos
    double* vet_a_double = (double*) aligned_alloc(32, 4*sizeof(double));
    double* vet_b_double = (double*) aligned_alloc(32, 4*sizeof(double));
    double* vet_c_double = (double*) aligned_alloc(32, 4*sizeof(double));

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

    // le os valores do vetor B usando scaf dentro de um loop
    printf("Digite os elementos do vetor C:\n");
    for (i = 0; i < 4; i++) {
        printf("Digite o elemento %d: ", i);
        scanf("%lf", &vet_c_double[i]);
    }

    // carrega o vetor de double para um arranjo do avx usando a funcao _mm256_load_pd
    __m256d a = _mm256_load_pd(vet_a_double);
    __m256d b = _mm256_load_pd(vet_b_double);
    __m256d c = _mm256_load_pd(vet_c_double);

    // faz o operacao a a * b + c
    __m256d res = _mm256_fmadd_pd(a, b, c);

    // converte o resultado para double e mostra na tela
    double* resultado = (double*)&res;
    printf("\nResultado de A + B: \n");
    printf("%lf %lf %lf %lf\n", resultado[0], resultado[1], resultado[2], resultado[3]);

    return 0;
}