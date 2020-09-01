/**
 * Usando a instrução _mm256_hadd_pd realize a soma horizontal de dois vetores conforme mostrado
 * na figura abaixo. Apresente o resultado convenientemente na tela.
 * 
 * Como compilar: gcc -mavx -o ex4.o ex04.c
 * É necessário que o processador suporte AVX
 * 
 * Alunos: Arthur Alexsander Martins Teodoro
 *         Arthur Henrique Sousa Cruz
*/

#include <immintrin.h>
#include <stdio.h>

int main() {

    __m256d a = _mm256_setr_pd(0.1, 0.2, 0.3, 0.4);
    __m256d b = _mm256_setr_pd(0.5, 0.6, 0.7, 0.8);

    __m256d c = _mm256_hadd_pd(a, b);

    double* a_double = (double*)&a;
    double* b_double = (double*)&b;
    double* c_double = (double*)&c;

    printf("\nValores de A: \n");
    printf("%lf %lf %lf %lf\n", a_double[0], a_double[1], a_double[2], a_double[3]);

    printf("\nValores de B: \n");
    printf("%lf %lf %lf %lf\n", b_double[0], b_double[1], b_double[2], b_double[3]);

    printf("\nResultado da soma horizontal entre A e B: \n");
    printf("%lf %lf %lf %lf\n", c_double[0], c_double[1], c_double[2], c_double[3]);

    return 0;
}
