/*
 * Dado o exemplo de código para multiplicação de elementos complexos na 
 * página 14 do tutorial [3],seção 7. Implemente um código em que as entradas 
 * são inseridas via terminal, realize a operaçãosolicitada e mostre o 
 * resultado na tela. Explique como são realizados os cálculos.
 * Alunos: Arthur Alexsander Martins Teodoro
 *         Arthur Henrique Sousa Cruz
 * 
 * Código baseado em: https://www.codeproject.com/Articles/874396/Crunching-Numbers-with-AVX-and-AVX
*/

#include <immintrin.h>
#include <stdio.h>

int main() {
    /* Considere que quer-se calcular:
            (a + bi) * (c + di)             (1)
            (w + xi) * (y + zi)             (2)
        
        Os 4 primeiros valores lido serão de (1) e os proximos serão de (2)

        O resultado esperado para as multiplicações é:
            (a*c - b*d)+(a*d + b*c)i        (3)
            (w*y - x*z)+(w*z + x*y)i        (4)
        
        O vetor final apresentará o resultado no seguinte formato:
            [(a*c - b*d), (a*d + b*c), (w*y - x*z), (w*z + x*y)]
        
    */

    // aloca cada um dos 2 vetores de double com 4 elementos
    double* vet_1_double = (double*) malloc(4*sizeof(double));
    double* vet_2_double = (double*) malloc(4*sizeof(double));

    printf("Digite os elementos da primeira equacao:\n");
    for (int i = 0; i < 4; i++) {
        printf("Digite o elemento %d da equacao 1: ", i+1);
        // Aloca no primeiro vetor o primeiro par de elementos da equacao 1
        // posições utilizadas: [0,1]
        if (i < 2) {
            scanf("%lf", &vet_1_double[i]);
        }
        // Aloca no segundo vetor o segundo par de elementos da equacao 1
        // posições utilizadas: [0,1]
        else {
            scanf("%lf", &vet_2_double[i-2]);
        }
    }

    printf("Digite os elementos da segunda equacao:\n");
    for (int i = 0; i < 4; i++) {
        printf("Digite o elemento %d da equacao 2: ", i+1);
        // Aloca no segundo vetor o primeiro par de elementos da equacao 2
        // posições utilizadas: [2,3]
        if (i < 2) {
            scanf("%lf", &vet_1_double[i+2]);
        }
        // Aloca no segundo vetor o segundo par de elementos da equacao 2
        // posições utilizadas: [2,3]
        else {
            scanf("%lf", &vet_2_double[i]);
        }
    }

    // carrega o vetor de double para um arranjo do avx
    __m256d vetor_1 = _mm256_loadu_pd(vet_1_double);
    __m256d vetor_2 = _mm256_loadu_pd(vet_2_double);

    // Ao fim das leituras e alocações temos:
    // vetor 1: a, b, w, x
    // vetor 2: c, d, y, z

    // printf("vetor_1: ");
    // for (int i = 0; i < 4; i++) {
    //     printf("%0.2f ", vetor_1[i]);
    // }
    // printf("\n");

    // printf("vetor_2: ");
    // for (int i = 0; i < 4; i++) {
    //     printf("%0.2f ", vetor_2[i]);
    // }
    // printf("\n");

    // Baseado no exemplo apresentado, propoe-se o algoritmo abaixo para 
    // multiplicar dois numeros imaginarios



    // multiplica-se o vetor_1 pelo vetor_3
    // assim tem-se:
    // a*c, b*d, w*y, x*z
    __m256d vec3 = _mm256_mul_pd(vetor_1, vetor_2);


    // No passo seguinte, calcula-se o oposto dos valores reais, fazendo com 
    // que as variáveis assumam os valores: 
    // vetor_1 =  a, b,  w, x
    // vetor_2 = -c, d, -y, z
    // vetor_3 =  a*c, b*d, w*y, x*z
    __m256d oposto = _mm256_setr_pd(-1.0, 1.0, -1.0, 1.0);
    vetor_2 = _mm256_mul_pd(vetor_2, oposto);  
    
    // Após isso, permuta-se o vetor 2 de forma que ele fique no seguinte 
    // formato:
    // vetor_2 = d, -c, z, -y
    vetor_2 = _mm256_permute_pd(vetor_2, 0b00000101);

    // Armazenamos em vetor 4 a multiplicação do vetor 1 pelo vetor 2 
    // modificado, fazendo com que tenhamos:
    // vetor_1 =  a, b,  w, x
    // vetor_2 =  d, -c, z, -y
    // vetor_3 =  a*c, b*d, w*y, x*z
    // vetor_4 =  a*d, -b*c, w*z, -x*y
    __m256d vec4 = _mm256_mul_pd(vetor_1, vetor_2);

    // Por fim, fazemos a subtração horizontal dos vetores, o que nos dá:
    // vetor_resultado = ac-bd, ad+bc, wy-xz, wz+xy
    __m256d vetor_resultado = _mm256_hsub_pd(vec3, vec4);


    // Imprime o resultado
    printf("Resultado eq 1: ");
    printf("%0.2f + (", vetor_resultado[0]);
    printf("%0.2f)i\n", vetor_resultado[1]);
    printf("Resultado eq 2: ");
    printf("%0.2f + (", vetor_resultado[2]);
    printf("%0.2f)i\n", vetor_resultado[3]);

    return 0;
}