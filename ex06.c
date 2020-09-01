/**
 * Os intrínsecos _permute_ aceitam dois argumentos: um vetor de entrada e um valor de controle de
 * 8 bits. Os bits do valor de controle determinam qual dos elementos do vetor de entrada é inserido
 * na saída. Usando a instrução intrínseca _mm256_permute_ps encontre o valor de controle de oito
 * bits e realize a permuta conforme a figura abaixo. Apresente na tela o vetor de entrada, o valor do
 * controle e o vetor de resultado.
 * 
 * Como compilar: gcc -mavx2 -o ex6.o ex06.c
 * É necessário que o processador suporte AVX2
 * Alunos: Arthur Alexsander Martins Teodoro
 *         Arthur Henrique Sousa Cruz
*/

#include <immintrin.h>
#include <stdio.h>

int main() {

    // inicializa o vetor de entrada e o de indice de acordo com a imagem
    __m256 a = _mm256_setr_ps(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
    __m256i control = _mm256_setr_epi32(2, 0, 1, 3, 4, 6, 5, 5);

    /** 
     * Realiza a permutacao
     * No caso dessa funcao, a permutacao ocorre da seguinte maneira: Alem do vetor a ser
     * permutado, e enviado a funcao um vetor de inteiros com a sequencia de indices
     * que deve ser consultado no vetor de origem para criar o vetor de destino. Por
     * exemplo, caso a primeira posicao do vetor de indices seja 4, o valor que esta
     * na quinta posicao do vetor de origem eh colocado na primeira posicao do vetor destino
    */
    __m256 result = _mm256_permutevar8x32_ps(a, control);

    // converte o resultado para float e mostra na tela
    float* res = (float*)&result;
    float* input_vector = (float*)&a;
    int* control_vector = (int*)&control;

    printf("Vetor de entrada: \n");
    printf("%f %f %f %f %f %f %f %f\n", input_vector[0], input_vector[1], input_vector[2], input_vector[3], input_vector[4], input_vector[5], input_vector[6], input_vector[7]);

    printf("\nVetor de controle (indices): ");
    printf("%d %d %d %d %d %d %d %d\n", control_vector[0], control_vector[1], control_vector[2], control_vector[3], control_vector[4], control_vector[5], control_vector[6], control_vector[7]);

    printf("\nResultado da permutacao: \n");
    printf("%f %f %f %f %f %f %f %f\n", res[0], res[1], res[2], res[3], res[4], res[5], res[6], res[7]);

    return 0;
}