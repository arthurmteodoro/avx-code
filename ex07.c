/**
 * A função intrínseca _shuffle_ seleciona elementos de entrada para um ou dois 
 * vetores de 256 bitse os colocam no vetor de saída de acordo com um terceiro 
 * elemento de 8 bits, que determinaquais elementos devem ser colocados no 
 * vetor de saída.  Encontre o valor do terceiro elementoe implemente um 
 * programa que realize o embaralhamento mostrado na figura abaixo, usando 
 * ainstrução _mm256_shuffle_ps (vec1, vec2, 0bxxxxxxxx).
 * 
 * Alunos: Arthur Alexsander Martins Teodoro
 *         Arthur Henrique Sousa Cruz
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

    /* Dado um inteiro para o controle do shuffle, cujo binário é composto pela concatenação dos pares de bits w, x, y e z, tem-se que cada par de bits representa as seguintes atribuições para as posições no vetor resultado:
    w: a posição 3 do novo vetor recebe o valor de vec2[int(w)]
       a posição 7 do novo vetor recebe o valor de vec2[int(w)+4]
    x: a posição 2 do novo vetor recebe o valor de vec2[int(w)]
       a posição 6 do novo vetor recebe o valor de vec2[int(w)+4]
    y: a posição 1 do novo vetor recebe o valor de vec1[int(w)]
       a posição 5 do novo vetor recebe o valor de vec1[int(w)+4]
    z: a posição 0 do novo vetor recebe o valor de vec1[int(w)]
       a posição 4 do novo vetor recebe o valor de vec1[int(w)+4]

    */

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