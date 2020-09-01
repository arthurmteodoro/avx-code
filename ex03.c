/**
 * Ao adicionar ou subtrair vetores inteiros, é importante verificar a diferença entre as funções _add_
 * e _sub_ e as funções _adds_ _subs_. O s extra significa saturação, que é produzida quando o
 * resultado requer mais memória do que o o vetor pode armazenar. Crie um programa que exem-
 * plifique esta situação ao somarmos dois vetores A e B, no qual seus elementos são definidos como
 * _mm256_add_epi8 e _mm256_subs_epi16. Apresente o resultado convenientemente na tela.
*/

#include <immintrin.h>
#include <stdio.h>

int main() {

    __m256i a = _mm256_set1_epi16(32760);
    __m256i b = _mm256_set1_epi16(32768);

    __m256i c = _mm256_subs_epi16(a, b);

    short* res = (short*)&c;
    printf("\nResultado de A*B + C: \n");
    printf("%hi %hi %hi %hi %hi %hi %hi %hi\n", res[0], res[1], res[2], res[3], res[4], res[5], res[6], res[7]);

    return 0;
}
