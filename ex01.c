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
    int option = -1;  // opcao escolhida
    int i = 0;        // variavel para iterar para a leitura dos valores

    // menu de opcaoes
    printf("Selecione o tipo de entrada\n");
    printf("1. double (4 x 64bit)\n");
    printf("2. float (8 x 32bit)\n");
    printf("3. int (8 x 32bit)\n");
    printf("Digite a opção: ");
    scanf("%d", &option);

    // caso a opcao seja de ler vetores do tipo double
    if (option == 1) {
        // aloca cada um dos 3 vetores de double com 4 elementos
        double* vet_a_double = (double*) malloc(4*sizeof(double));
        double* vet_b_double = (double*) malloc(4*sizeof(double));
        double* vet_c_double = (double*) malloc(4*sizeof(double));

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

        // le os valores do vetor C usando scaf dentro de um loop
        printf("Digite os elementos do vetor C:\n");
        for (i = 0; i < 4; i++) {
            printf("Digite o elemento %d: ", i);
            scanf("%lf", &vet_c_double[i]);
        }

        // carrega o vetor de double para um arranjo do avx usando a funcao _mm256_loadu_pd
        __m256d a = _mm256_loadu_pd(vet_a_double);
        __m256d b = _mm256_loadu_pd(vet_b_double);
        __m256d c = _mm256_loadu_pd(vet_c_double);

        // calcula a * b + c usando a funcao _mm256_fmad_pd
        __m256d result = _mm256_fmadd_pd(a, b, c);

        // converte o resultado para double e mostra na tela
        double* res = (double*)&result;
        printf("\nResultado de A*B + C: \n");
        printf("%lf %lf %lf %lf\n", res[0], res[1], res[2], res[3]);
    }

    // caso a opcao seja de ler vetores do tipo float
    if (option == 2) {
        // aloca cada um dos 3 vetores de float com 8 elementos
        float* vet_a_float = (float*) malloc(8*sizeof(float));
        float* vet_b_float = (float*) malloc(8*sizeof(float));
        float* vet_c_float = (float*) malloc(8*sizeof(float));

        // le os valores do vetor A usando scaf dentro de um loop
        printf("Digite os elementos do vetor A:\n");
        for (i = 0; i < 8; i++) {
            printf("Digite o elemento %d: ", i);
            scanf("%f", &vet_a_float[i]);
        }

        // le os valores do vetor B usando scaf dentro de um loop
        printf("Digite os elementos do vetor B:\n");
        for (i = 0; i < 8; i++) {
            printf("Digite o elemento %d: ", i);
            scanf("%f", &vet_b_float[i]);
        }

        // le os valores do vetor C usando scaf dentro de um loop
        printf("Digite os elementos do vetor C:\n");
        for (i = 0; i < 8; i++) {
            printf("Digite o elemento %d: ", i);
            scanf("%f", &vet_c_float[i]);
        }

        // carrega o vetor de float para um arranjo do avx usando a funcao _mm256_loadu_ps
        __m256 a = _mm256_loadu_ps(vet_a_float);
        __m256 b = _mm256_loadu_ps(vet_b_float);
        __m256 c = _mm256_loadu_ps(vet_c_float);

        // calcula a * b + c usando a funcao _mm256_fmad_ps
        __m256 result = _mm256_fmadd_ps(a, b, c);

        // converte o resultado para float e mostra na tela
        float* res = (float*)&result;
        printf("\nResultado de A*B + C: \n");
        printf("%f %f %f %f %f %f %f %f\n", res[0], res[1], res[2], res[3], res[4], res[5], res[6], res[7]);
    }

    // caso a opcao seja de ler vetores do tipo int
    if (option == 3) {
        // aloca cada um dos 3 vetores de int com 8 elementos
        int* vet_a_int = (int*) malloc(8*sizeof(int));
        int* vet_b_int = (int*) malloc(8*sizeof(int));
        int* vet_c_int = (int*) malloc(8*sizeof(int));

        // le os valores do vetor A usando scaf dentro de um loop
        printf("Digite os elementos do vetor A:\n");
        for (i = 0; i < 8; i++) {
            printf("Digite o elemento %d: ", i);
            scanf("%d", &vet_a_int[i]);
        }

        // le os valores do vetor A usando scaf dentro de um loop
        printf("Digite os elementos do vetor B:\n");
        for (i = 0; i < 8; i++) {
            printf("Digite o elemento %d: ", i);
            scanf("%d", &vet_b_int[i]);
        }

        // le os valores do vetor A usando scaf dentro de um loop
        printf("Digite os elementos do vetor C:\n");
        for (i = 0; i < 8; i++) {
            printf("Digite o elemento %d: ", i);
            scanf("%d", &vet_c_int[i]);
        }

        // carrega o vetor de integers para um arranjo do avx usando a funcao _mm256_loadu_si256
        __m256i a = _mm256_loadu_si256((__m256i*)&vet_a_int[0]);
        __m256i b = _mm256_loadu_si256((__m256i*)&vet_b_int[0]);
        __m256i c = _mm256_loadu_si256((__m256i*)&vet_c_int[0]);

        // converte o vetor de inteiro para float porque as funcoes de fma so operam sobre pontos flutuantes
        __m256 a_float = _mm256_cvtepi32_ps(a);
        __m256 b_float = _mm256_cvtepi32_ps(b);
        __m256 c_float = _mm256_cvtepi32_ps(c);

        // calcula a * b + c usando a funcao _mm256_fmad_ps
        __m256 result_float = _mm256_fmadd_ps(a_float, b_float, c_float);

        // volta o valor calculado para inteiro sem realizar truncamento
        __m256i result = _mm256_cvtps_epi32(result_float);

        // converte o resultado para int e mostra na tela
        int* res = (int*)&result;
        printf("\nResultado de A*B + C: \n");
        printf("%d %d %d %d %d %d %d %d\n", res[0], res[1], res[2], res[3], res[4], res[5], res[6], res[7]);
    }

    return 0;
}