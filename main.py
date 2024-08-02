import pandas as pd
import numpy as np
from sklearn.cluster import k_means

def cluster_de_cada_dado(df, k_grupos, k):
    distancias = []
    grupo_cada_dado = []

    for i in range(df.shape[0]):

        for j in range(k):
            distancias.append((np.linalg.norm(df.iloc[i] - k_grupos[j]), j)) # distância euclidiana de cada dado para cada grupo

        distancias.sort(key=lambda x: x[0])

        grupo_cada_dado.append(distancias[0][1])

        distancias = []
    return grupo_cada_dado

def calcula_centroide(df, grupo_cada_dado, k):
    k_grupos_novo = [[0] * df.shape[1] for _ in range(k)] # Vetor com as novas posições dos centróides 
    aux_total_objetos_cada_grupo = [0] * k # Vetor contendo o número de dados em cada cluster (indice do vetor == numero do grupo)

    for i in range(df.shape[0]):
        aux_total_objetos_cada_grupo[grupo_cada_dado[i]] += 1

        objeto = df.iloc[i]

        for j in range(df.shape[1]):
            k_grupos_novo[grupo_cada_dado[i]][j] += objeto.iloc[j]


    for i in range(k):
        for j in range(df.shape[1]):
            k_grupos_novo[i][j] = k_grupos_novo[i][j] / aux_total_objetos_cada_grupo[i]

    return k_grupos_novo  


def k_means(df, k_grupos, n_interation=10):
    """
    parâmetros:
        * df -> dataframe (escolho fazer esse codigo com o dataframe do pandas do que com um numpy array como o sklearn)
        * k_grupos -> array com a posição inicial dos grupos 
        * n_interation -> número de interações de cálculo dos centróides. Por default será 10

    Esse código não é tão complexo e há de ser melhorado conforme o tempo!
    """
    
    k = len(k_grupos)
    grupo_cada_dado = []

    for i in range(n_interation):
        grupo_cada_dado = cluster_de_cada_dado(df, k_grupos, k)
        k_grupos = calcula_centroide(df, grupo_cada_dado, k)


    return k_grupos


def main():
    df = pd.DataFrame({
    'x': [1, 10, 4, 10, 20, 10],
    'y': [2, 4, 6, 12, 14, 8]   
    })

    k_g = [[13, 13], [4, 4]]

    print(k_means(df, k_g, n_interation=5))


main()