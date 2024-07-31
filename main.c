#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int vetor_teste[10][2];

int* selecao_grupo_de_cada_dado(double** vetor_dados, int len_vetor_dados[2], double** k_grupos, int k){
    int *grupo_selecionado = (int*) malloc(len_vetor_dados[0] * sizeof(int));

    for (int i = 0; i < len_vetor_dados[0]; i++){

        double* objeto = vetor_dados[i];
        double aux_distancia_cada_posicao[k]; // Isso aqui precisa ser inicializado como 0 todas as posições!!!!

        for (int faça_isso_rapido_por_favor; faça_isso_rapido_por_favor < k; faça_isso_rapido_por_favor++){
            aux_distancia_cada_posicao[faça_isso_rapido_por_favor] = 0.0;
        }

        for (int j = 0; j < len_vetor_dados[1]; j++){

            for (int m = 0; m < k; m++){
                aux_distancia_cada_posicao[m] += (objeto[j] - k_grupos[j][m]) * (objeto[j] - k_grupos[j][m]);
            }

        }
        int aux1 = -1; double aux2 = 0.0; // AUX1 terá a o numero do cluster mais próximo
        for (int j = 0; j < k; j++){
            aux_distancia_cada_posicao[j] = sqrt(aux_distancia_cada_posicao[j]);

            if ((aux_distancia_cada_posicao[j] < aux2) || (aux1 == -1))
                aux2 = aux_distancia_cada_posicao[j];
                aux1 = j;
        }

        grupo_selecionado[i] = aux1;

    }

    return grupo_selecionado;
}

void calcula_centroide(double** dados, int len_dados[2], int* vetor_grupos, double** k_grupos, int k){

    int* vetor_soma_novo_centroide = (int*) malloc(len_dados[1] * sizeof(int));
    int num_dados_do_grupo = 0;

    for(int i = 0; i < len_dados[1]; i++)
        vetor_soma_novo_centroide[i] = 0;

    for (int i = 0; i < k; i ++){ // Loop por todos os grupos para redefinir suas posições

        for (int j = 0; j < len_dados[0]; j ++){ // Loop por todos os dados para achar quais são do grupo i

            if (vetor_grupos[j] == i){ // Se objeto == grupo i, calcule os calculos

                num_dados_do_grupo ++;

                for(int m = 0; m < len_dados[1]; m ++)
                    vetor_soma_novo_centroide[m] += dados[j][m];
            }
        }

        for (int j = 0; j < len_dados[1]; j++)
            k_grupos[i][j] = vetor_soma_novo_centroide[j] / num_dados_do_grupo; // Calculando o novo centroide do grupo i (calculando cada dimensão)
    }

    free(vetor_soma_novo_centroide);

    return;
}

void k_means(double** dados, int rows_columns_data[2], double** k_grupos, int k){
    int rows_columns_data[2]; // primeiro valor é o numero de linhas, o segundo é o de colunas
    int* grupos;

    for (int i = 0; i < 10; i ++){
        grupos = selecao_grupo_de_cada_dado(dados, rows_columns_data, k_grupos, k);
        calcula_centroide(dados, rows_columns_data, grupos, k_grupos, k);
    }
    return;
}








int main(){
    return 0;
}