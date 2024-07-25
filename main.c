#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int vetor_teste[10][2];

void selecao_grupo_de_cada_dado(float** vetor_dados, int len_vetor_dados[2], float** k_grupos, int k){
    int *grupo_selecionado = (int*) malloc(len_vetor_dados[0] * sizeof(int));

    for (int i = 0; i < len_vetor_dados[0]; i++){

        float* objeto = vetor_dados[i];
        float aux_distancia_cada_posicao[k]; // Isso aqui precisa ser inicializado como 0 todas as posições!!!!

        for (int j = 0; j < len_vetor_dados[1]; j++){

            for (int m = 0; m < k; m++){
                aux_distancia_cada_posicao[m] += (objeto[j] - k_grupos[j][m]) * (objeto[j] - k_grupos[j][m]);
            }

        }
        int aux1 = -1; float aux2 = 0.0; // AUX1 terá a o numero do cluster mais próximo
        for (int j = 0; j < k; k++){
            aux_distancia_cada_posicao[j] = sqrt(aux_distancia_cada_posicao[j]);

            if ((aux_distancia_cada_posicao[j] < aux2) || (aux1 == -1))
                aux2 = aux_distancia_cada_posicao[j];
                aux1 = j;
        }

        grupo_selecionado[i] = aux1;

    }

    return;
}

int main(){
    return 0;
}