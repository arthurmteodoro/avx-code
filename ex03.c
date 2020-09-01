/**
 * Ao adicionar ou subtrair vetores inteiros, é importante verificar a diferença entre as funções _add_
 * e _sub_ e as funções _adds_ _subs_. O s extra significa saturação, que é produzida quando o
 * resultado requer mais memória do que o o vetor pode armazenar. Crie um programa que exem-
 * plifique esta situação ao somarmos dois vetores A e B, no qual seus elementos são definidos como
 * _mm256_add_epi8 e _mm256_subs_epi16. Apresente o resultado convenientemente na tela.
 * 
 * Alunos: Arthur Alexsander Martins Teodoro
 *         Arthur Henrique Sousa Cruz
*/

#include <immintrin.h>
#include <stdio.h>

int main() {

    int i;

    // Inicializa os vetores com inteiros sinalizados de 16 bits
    __m256i a = _mm256_set1_epi16(32760);
    __m256i b = _mm256_set1_epi16(10);

    // realiza a soma dos inteiros com saturacao e sem saturacao
    __m256i c = _mm256_add_epi16(a, b);
    __m256i d = _mm256_adds_epi16(a, b);

    // converte os veetores para vetores de short
    short* vet1 = (short*)&a;
    short* vet2 = (short*)&b;

    short* res_add = (short*)&c;
    short* res_add_saturado = (short*)&d;

    // imprime os resultados na tela
    printf("Vetor 1: \n");
    for(i = 0; i < 16; i++)
        printf("%hi ", vet1[i]);
    printf("\n");

    printf("\nVetor 2: \n");
    for(i = 0; i < 16; i++)
        printf("%hi ", vet2[i]);
    printf("\n");

    printf("\nSoma dos vetores sem saturacao: \n");
    for(i = 0; i < 16; i++)
        printf("%hi ", res_add[i]);
    printf("\n");

    printf("\nSoma dos vetores com saturacao: \n");
    for(i = 0; i < 16; i++)
        printf("%hi ", res_add_saturado[i]);
    printf("\n");

    return 0;
}
