# K-Means

Este projeto visa construir o algoritmo K-Médias em linguagem C por dois motivos:
1. Entender melhor o funcionamento do algoritmo, quebrando a cabeça para fazê-lo do zero
2. Conseguir melhorar meus códigos em python
3. Se divertir :) pretendo no futuro criar um repositório só com algoritmos de Machine Learning

Por enquanto terá dois códigos, um em C e outro em Python (os dois azendo o mesmo algoritmo) 
*PS: por enquanto só em Python está funcionando

As próximas seções abordarão brevemente o que é o K_means, o cósigo em C e o código em Python, respectivamente

## Mas o que é o K-Means?

K-Means é um algoritmo muito importante em ML na área de aprendizado não-supervisionado. Ele tem como objetivo criar Clusters, ou como foi traduzido para o português "grupos", através de dados não rotulados.

Para isso, ele criará K grupos (sim, o K do nome é uma variável), onde você inicialmente coloca as posições iniciais de onde quer começar os grupos, e caso um objeto esteja mais perto de um grupo X, ele será "classificado" com esse grupo. O cálculo de distância pode ser feito de várias maneiras, mas neste projeto usamos distância Euclidiana.

Há muito mais à se falar sobre ele, mas deixarei para o leitor que não conhecer sobre e se interesse, pesquise mais sobre ele. Vai por mim, ele é de simples entendimento e muito legal :)



# MAIN.C

**void selecao_grupo_de_cada_dado(float vetor_dados, int len_vetor_dados[2], float k_posicoes, int k)**

Essa função pegará os dados de treinamento e as posições de cada grupo e para cada objeto determinará qual grupo ele faz parte
A seleção é de qual ele o dado deve pertencer é feito com distancia euclidiana. A menor distância para um grupo será esse o grupo

    Parâmetros:
        * vetor_dados = matriz com os dados
        * len_vetor_dados[2] = tem dois dados, [0] é o número de objetos do dataset, [1] número de atributos
        * k_grupos = matriz com K objetos (os k grupos) e len_vetor_dados[1] número de atributos
        * K = número de grupos

A função principalmente intera entre 3 loops, um dentro do anterior. 
1º loop: interá para cada objeto
    2º loop: interá sobre os atributos do objeto
        3º loop: interá sobre os atributos de cada objeto do parametro k_grupos

O vetor de floats aux_distancia_cada_posicao de tamanho K é essencial na função, ele é um auxiliar que em cada posição dele será feita um cálculo de distância euclidiana. Por exemplo, a posição 0 deste vetor está fazendo o cálculo de distância entre o objeto em questão e o k_grupos[0]. Desta maneira ao final dos dois últimos loops teremos todos os cálculos de distância e escolheremos o com menor número. Quando se acha o menor, seu índice é pego e jogado para o vetor grupo_selecionado[len_vetor_dados[0]] (lembre-se, pegamos o índice pq ele já nos diz qual é o grupo).

O vetor grupo_selecionado terá tamanho len_vetor_dados[0], e representará de qual grupo cada objeto pertencerá. Ou seja, a posição 0 do array representará o grupo do vetor_dados[0].

# MAIN.PY

Por enquanto o único testado se está realmente funcionando. Porém é necessário fazer ressalvas. Ele foi testado com um dataset muito pequeno, então carece de testes maiores. Além do mais é muito simples, por isso vou deixar aqui algumas sugestões para o eu do futuro melhorar:

* Mudar o algoritmo de um funções jogadas para uma classe específica chamada K_means
* Trocar o conjunto de dados aceito, em vez de dataframe, um np.array
* Verificações de valores nulos e parametros errados
* Só está funcionando para datasets com valores inteiros ou de ponto flutuantes. Pode se colocar outros tipos de dados para funcionar
* Em um futuro distante mudar o algoritmo para k_means++

