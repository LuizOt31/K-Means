import pandas as pd
import numpy as np

def selecao_grupo_de_cada_dado(df, k_grupos, k):
    distancias = []
    grupo_cada_dado = []

    for i in range(df.shape[0]):

        for j in range(k):
            distancias.append((np.linalg.norm(df.iloc[i] - k_grupos[j]), j))

        distancias.sort(key=lambda x: x[0])

        grupo_cada_dado.append(distancias[0][1])

        distancias = []

    return grupo_cada_dado


def calcula_centroide(df, grupo_cada_dado, k):
    k_grupos_novo = [[0] * df.shape[1]] * k
    aux_total_objetos_cada_grupo = [0] * k

    for i in range(df.shape[0]):
        aux_total_objetos_cada_grupo[grupo_cada_dado[i]] += 1

        objeto = df.iloc[i]
        for j in range(df.shape[1]):
            k_grupos_novo[grupo_cada_dado[i]][j] += objeto.iloc[j]

    for i in range(k):
        for j in range(df.shape[1]):
            k_grupos_novo[i][j] = k_grupos_novo[i][j] / aux_total_objetos_cada_grupo[i]

    return k_grupos_novo  


def k_means(df, k_grupos):
    k = len(k_grupos)
    k_grupo_novo = []
    grupo_cada_dado = []

    grupo_cada_dado = selecao_grupo_de_cada_dado(df, k_grupos, k)
    k_grupo_novo = calcula_centroide(df, grupo_cada_dado, k)

    return k_grupo_novo


def main():
    df = pd.DataFrame({
    'x': [1, 2, 2, 15, 11, 12],
    'y': [1, 1, 3, 14, 12, 14]   
    })

    k_g = [[4, 4], [13, 13]]

    print(k_means(df, k_g))

main()