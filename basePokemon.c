#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int numero, geracao, total, lendario, hp, ataque, defesa, ataqueEspecial, defesaEspecial, velocidade, taxaCaptura, preEvolucao, posEvolucao;
    char nome[31], cor[15], tipo1[15], tipo2[15];
    float altura, peso;
}Pokemon;

typedef struct{
    int pokemochila;
}Mochila;

typedef struct{
    int pokenumero;
}Colecao;

typedef enum{NOVOJOGO=1, CARREGARJOGO, SAIR}Opcoes;

typedef enum{GERACAO=1, TIPO}Filtro;

typedef enum{INSERIRPOKEMON=1, VISUALIZAR, ALTERAREQUIPE, VOLTARMOCHILA}MenuMochila;

typedef enum{INSERIR=1, LISTAR, PESQUISAR, ALTERAR, EXCLUIR, VOLTARCOLECAO}MenuColecao;

typedef enum{INSERIRPOKEDEX=1, LISTARPOKEDEX, PESQUISARPOKEDEX, ALTERARPOKEDEX, EXCLUIRPOKEDEX, VOLTARPOKEDEX}MenuPokedex;

//typedef enum{HP=1, ATAQUE, DEFESA, ATAQUEESPECIAL, DEFESAESPECIAL, VELOCIDADE, NOME, LENDARIO, SAIR}alterarPokemon;

//Recebe e armazena nomes
void jogNome(char pokenumero[], int size){

    setbuf(stdin, NULL);
    fgets(pokenumero, size, stdin);
    pokenumero[strcspn(pokenumero, "\n")] = '\0';
    setbuf(stdin, NULL);

    return;

}//jogNome

//Cadastra novo pokemon
void cadastrarPokemon(Pokemon pokedex[], int tamanho){

    //nome
    printf("Insira o nome do Pokémon desejado para inserção: ");
    jogNome(pokedex[tamanho - 1].nome, 15);

    //número
    printf("Insira o número desse pokémon:");
    scanf("%d", &pokedex[tamanho - 1].numero);

    while (pokedex[tamanho - 1].numero <= tamanho - 2){
        printf("Valor inválido. Insira um novo valor: ");
        scanf("%d", &pokedex[tamanho - 1].numero);
        printf("\n");
    }//while

    //geração
    printf("Insira a geração desse Pokémon: ");
    scanf("%d", &pokedex[tamanho - 1].geracao);

    while (pokedex[tamanho - 1].geracao <= 0){
        printf("Valor inválido. Insira um novo valor: ");
        scanf("%d", &pokedex[tamanho - 1].geracao);
        printf("\n");
    }//while

    //cor
    printf("Insira a cor desse Pokémon: ");
    jogNome(pokedex[tamanho - 1].cor, 11);
    printf("\n");

    //tipo 1
    printf("Insira o tipo primário desse Pokémon: ");
    jogNome(pokedex[tamanho - 1].tipo1, 11);

    //tipo 2
    printf("Insira o tipo secundário desse Pokémon, se não houver, pressione "
           "Enter"
           ": ");
    jogNome(pokedex[tamanho - 1].tipo2, 11);
    printf("\n");

    if (strcmp(pokedex[tamanho - 1].tipo2, "\n") == 0){
        strcpy(pokedex[tamanho - 1].tipo2, "NULL");
    }//if

    //valor total
    printf("Insira o valor total desse Pokémon: ");
    scanf("%d", &pokedex[tamanho - 1].total);

    while (pokedex[tamanho - 1].total <= 0){
        printf("Valor inválido. Insira um valor adequado: ");
        scanf("%d", &pokedex[tamanho - 1].total);
        printf("\n");
    }//while

    //HP
    printf("Insira o HP total desse Pokémon: ");
    scanf("%d", &pokedex[tamanho - 1].hp);

    while (pokedex[tamanho - 1].hp <= 0){
        printf("HP inválido. Insira um valor adequado: ");
        scanf("%d", &pokedex[tamanho - 1].hp);
        printf("\n");
    }//while

    //Ataque e defesa
    printf("Insira seu ataque e defesa respectivamente: ");
    printf("\nAtaque: ");
    scanf("%d", &pokedex[tamanho - 1].ataque);

    while (pokedex[tamanho - 1].ataque <= 0){
        printf("Ataque inválido. Insira um valor adequado: ");
        scanf("%d", &pokedex[tamanho - 1].ataque);
    }//while

    printf("Defesa: ");
    scanf("%d", &pokedex[tamanho - 1].defesa);

    while (pokedex[tamanho - 1].defesa <= 0){
        printf("Defesa inválida. Insira um valor adequado: ");
        scanf("%d", &pokedex[tamanho - 1].defesa);
        printf("\n");
    }//while

    printf("Insira seu ataque e defesa especial respectivamente: ");
    printf("\nAtaque Esp.: ");
    scanf("%d", &pokedex[tamanho - 1].ataqueEspecial);

    while (pokedex[tamanho - 1].ataqueEspecial <= 0){
        printf("Ataque Esp. inválido. Insira um valor adequado: ");
        scanf("%d", &pokedex[tamanho - 1].ataqueEspecial);
    }//while

    printf("Defesa Esp.: ");
    scanf("%d", &pokedex[tamanho - 1].defesaEspecial);

    while (pokedex[tamanho - 1].defesaEspecial <= 0){
        printf("Defesa Esp. inválida. Insira um valor adequado: ");
        scanf("%d", &pokedex[tamanho - 1].defesaEspecial);
        printf("\n");
    }//while

    printf("Por fim, insira sua velocidade: ");
    scanf("%d", &pokedex[tamanho - 1].velocidade);

    while (pokedex[tamanho - 1].velocidade <= 0){
        printf("Velocidade inválida. Insira um valor adequado: ");
        scanf("%d", &pokedex[tamanho - 1].velocidade);
        printf("\n");
    }//while

    // lendário
    printf("Esse Pokémon é lendário? Para "
           "Sim"
           ", insira 1, e para "
           "Não"
           ", insira 0: ");
    scanf("%d", &pokedex[tamanho - 1].lendario);
    printf("\n");

    while (pokedex[tamanho - 1].lendario != 0 && pokedex[tamanho - 1].lendario != 1){
        printf("Insira um valor igual a 0 ou 1.");
        scanf("%d", &pokedex[tamanho - 1].lendario);
        printf("\n");
    }//while

    // altura e peso
    printf("Insira a altura e peso do Pokémon respectivamente: ");
    printf("\nAltura: ");
    scanf("%f", &pokedex[tamanho - 1].altura);

    while (pokedex[tamanho - 1].altura <= 0.0){
        printf("Altura inválida. Insira um valor adequado: ");
        scanf("%f", &pokedex[tamanho - 1].altura);
        printf("\n");
    }//while

    printf("Peso: ");
    scanf("%f", &pokedex[tamanho - 1].peso);

    while (pokedex[tamanho - 1].peso <= 0.0){
        printf("Peso inválido. Insira um valor adequado: ");
        scanf("%f", &pokedex[tamanho - 1].peso);
        printf("\n");
    }//while

    printf("Insira a taxa de captura desse Pokémon: ");
    scanf("%d", &pokedex[tamanho - 1].taxaCaptura);
    printf("\n");

    while (pokedex[tamanho - 1].taxaCaptura <= 0){
        printf("Taxa de captura inválida. Insira um valor adequado: ");
        scanf("%d", &pokedex[tamanho - 1].taxaCaptura);
        printf("\n");
    }//while
}//cadastrarPokemon

// Mostra pokemons da pokedex de acordo com o que é pedido
void mostrarTodos(Pokemon pokedex[], int tamanho){

    int opcao;
    int geracaoBusca;
    char buscaTipo[16];
    int achou = 0;

    do{
        printf("Filtros para listagem de Pokémon: ");
        printf("\n1 - Por geração.\n2 - Por tipo.\n");//ENUM de listagem e restrições
        printf("Insira o filtro desejado: ");
        scanf("%d", &opcao);
        printf("\n");
    } while (opcao != GERACAO || opcao != TIPO);
    

    switch (opcao){

        case GERACAO:

            printf("Insira qual geração deseja exibir: ");
            scanf("%d", &geracaoBusca);

            while (geracaoBusca <= 0){
                printf("Valor inválido. Insira um valor adequado: ");
                scanf("%d", &geracaoBusca);
                printf("\n");
            }//while

            for (int i = 0; i < tamanho; i++){

                if (pokedex[i].geracao == geracaoBusca){

                    printf("Número: %d.\n", pokedex[i].numero);
                    printf("Nome: %s.\n", pokedex[i].nome);
                    printf("Tipo 1: %s.\n", pokedex[i].tipo1);
                    printf("Tipo 2: %s.\n", pokedex[i].tipo2);
                    printf("Total: %d.\n", pokedex[i].total);
                    printf("Hp: %d.\n", pokedex[i].hp);
                    printf("Ataque: %d.\n", pokedex[i].ataque);
                    printf("Defesa: %d.\n", pokedex[i].defesa);
                    printf("Ataque especial: %d.\n", pokedex[i].ataqueEspecial);
                    printf("Defesa especial: %d.\n", pokedex[i].defesaEspecial);
                    printf("Velocidade: %d.\n", pokedex[i].velocidade);
                    printf("Geração: %d°.\n", pokedex[i].geracao);
                    printf("Lendário (0 = não e 1 = sim): %d.\n", pokedex[i].lendario);
                    printf("Cor: %s.\n", pokedex[i].cor);
                    printf("Altura (metros): %f.\n", pokedex[i].altura);
                    printf("Peso (kg): %f.\n", pokedex[i].peso);
                    printf("Taxa de captura: %d.\n", pokedex[i].taxaCaptura);
                    printf("\n");
                }//if

            }//for

            break;

        case TIPO:

            printf("Tipos de Pokémon: ");
            printf("\nAço\nAgua\nDragao\nEletrico\nFada\nFogo\nGelo\nFantasma\nInseto");
            printf("\nLutador\nNormal\nPedra\nPlanta\nPsiquico\nSombrio\nTerra\nVenenoso\nVoador\n");
            printf("\nInsira o tipo de Pokémon que deseja listar: ");
            jogNome(buscaTipo, 15);
            printf("\n");

            if (strcmp(buscaTipo, "Inseto") == 0){
                strcpy(buscaTipo, "Bug");
            }//if

            if (strcmp(buscaTipo, "Dragao") == 0){
                strcpy(buscaTipo, "Dragon");
            }//if

            if (strcmp(buscaTipo, "Eletrico") == 0){
                strcpy(buscaTipo, "Electric");
            }//if

            if (strcmp(buscaTipo, "Fogo") == 0){
                strcpy(buscaTipo, "Fire");
            }//if

            if (strcmp(buscaTipo, "Fantasma") == 0){
                strcpy(buscaTipo, "Ghost");
            }//if

            if (strcmp(buscaTipo, "Psiquico") == 0){
                strcpy(buscaTipo, "Psychic");
            }//if
            
            if (strcmp(buscaTipo, "Agua") == 0){
                strcpy(buscaTipo, "Water");
            }//if

            for (int i = 0; i < tamanho; i++){

                if (strcmp(pokedex[i].tipo1, buscaTipo) == 0 || strcmp(pokedex[i].tipo2, buscaTipo) == 0){

                    achou++;

                    printf("Número: %d.\n", pokedex[i].numero);
                    printf("Nome: %s.\n", pokedex[i].nome);
                    printf("Tipo 1: %s.\n", pokedex[i].tipo1);
                    printf("Tipo 2: %s.\n", pokedex[i].tipo2);
                    printf("Total: %d.\n", pokedex[i].total);
                    printf("Hp: %d.\n", pokedex[i].hp);
                    printf("Ataque: %d.\n", pokedex[i].ataque);
                    printf("Defesa: %d.\n", pokedex[i].defesa);
                    printf("Ataque especial: %d.\n", pokedex[i].ataqueEspecial);
                    printf("Defesa especial: %d.\n", pokedex[i].defesaEspecial);
                    printf("Velocidade: %d.\n", pokedex[i].velocidade);
                    printf("Geração: %d°.\n", pokedex[i].geracao);
                    printf("Lendário (0 = não e 1 = sim): %d.\n", pokedex[i].lendario);
                    printf("Cor: %s.\n", pokedex[i].cor);
                    printf("Altura (metros): %f.\n", pokedex[i].altura);
                    printf("Peso (kg): %f.\n", pokedex[i].peso);
                    printf("Taxa de captura: %d.\n", pokedex[i].taxaCaptura);
                    printf("\n");
                }//if

            }//for

            if (achou == 0){
                printf("Tipo não encontrado.\n");
                printf("\n");
            }//if

            break;
    }//switch

    return;

}//mostrarTodos

void PesquisarPoke(Pokemon pokedex[], int tamanho){

    int achou;
    char busca[16];

    printf("Insira o nome do Pokémon que deseja buscar na Pokédex: ");
    jogNome(busca, 15);

    for (int i = 1; i < tamanho; i++){

        if (strcmp(busca, pokedex[i].nome) == 0){

            printf("Número: %d.\n", pokedex[i].numero);
            printf("Nome: %s.\n", pokedex[i].nome);
            printf("Tipo 1: %s.\n", pokedex[i].tipo1);
            printf("Tipo 2: %s.\n", pokedex[i].tipo2);
            printf("Total: %d.\n", pokedex[i].total);
            printf("Hp: %d.\n", pokedex[i].hp);
            printf("Ataque: %d.\n", pokedex[i].ataque);
            printf("Defesa: %d.\n", pokedex[i].defesa);
            printf("Ataque especial: %d.\n", pokedex[i].ataqueEspecial);
            printf("Defesa especial: %d.\n", pokedex[i].defesaEspecial);
            printf("Velocidade: %d.\n", pokedex[i].velocidade);
            printf("Geração: %d°.\n", pokedex[i].geracao);
            printf("Lendário (0 = não e 1 = sim): %d.\n", pokedex[i].lendario);
            printf("Cor: %s.\n", pokedex[i].cor);
            printf("Altura (metros): %.2f.\n", pokedex[i].altura);
            printf("Peso (kg): %.2f.\n", pokedex[i].peso);
            printf("Taxa de captura: %d.\n", pokedex[i].taxaCaptura);
            printf("\n");

            achou++;
        }//if

    }//for

    if (achou == 0){
        printf("Pokémon não encontrado.\n");
        printf("\n");
    }//if

}//PesquisarPoke

void alteraPoke(Pokemon pokedex[], int tamanho){

    int indice;
    int achou;

    printf("Digite o número do Pokémon que deseja alterar: ");
    scanf("%d", &indice);
    printf("\n");

    while (indice <= 0){
        printf("Valor inválido. Insira um valor válido.\n");
        scanf("%d", &indice);
    }//while

    for (int i = 1; i < tamanho; i++){

        if (indice == pokedex[i].numero){

            achou++;

            printf("Qual o novo nome desse Pokémon? ");
            jogNome(pokedex[i].nome, 15);

            printf("Insira o novo número desse Pokémon ");
            printf("(Obs: precisa ser diferente dos demais contidos na Pokédex): ");
            scanf("%d", &pokedex[i].numero);

            while (pokedex[i].numero <= (tamanho - 1)){
                printf("Valor inválido. Insira um novo valor: ");
                scanf("%d", &pokedex[i].numero);
                printf("\n");
            }//while

            printf("Insira a nova geração desse Pokémon: ");
            scanf("%d", &pokedex[i].geracao);

            while (pokedex[i].geracao <= 0){
                printf("Valor inválido. Insira um novo valor: ");
                scanf("%d", &pokedex[i].geracao);
                printf("\n");
            }//while

            printf("Insira a nova cor desse Pokémon: ");
            jogNome(pokedex[i].cor, 11);
            printf("\n");

            printf("Insira o novo tipo primário desse Pokémon: ");
            jogNome(pokedex[i].tipo1, 11);

            printf("Insira o novo tipo secundário desse Pokémon, se não houver, pressione "
                   "Enter"
                   ": ");
            jogNome(pokedex[i].tipo2, 11);
            printf("\n");

            if (strcmp(pokedex[i].tipo2, "\n") == 0){
                strcpy(pokedex[i].tipo2, "NULL");
            }//if

            printf("Insira o novo valor total desse Pokémon: ");
            scanf("%d", &pokedex[i].total);

            while (pokedex[i].total <= 0){
                printf("Valor inválido. Insira um valor adequado: ");
                scanf("%d", &pokedex[i].total);
                printf("\n");
            }//while

            printf("Insira o novo HP total desse Pokémon: ");
            scanf("%d", &pokedex[i].hp);

            while (pokedex[i].hp <= 0){
                printf("HP inválido. Insira um valor adequado: ");
                scanf("%d", &pokedex[i].hp);
                printf("\n");
            }//while

            printf("Insira seu novo ataque e defesa respectivamente: ");
            printf("\nAtaque: ");
            scanf("%d", &pokedex[i].ataque);

            while (pokedex[i].ataque <= 0){
                printf("Ataque inválido. Insira um valor adequado: ");
                scanf("%d", &pokedex[i].ataque);
            }//while

            printf("Defesa: ");
            scanf("%d", &pokedex[i].defesa);

            while (pokedex[i].defesa <= 0){
                printf("Defesa inválida. Insira um valor adequado: ");
                scanf("%d", &pokedex[i].defesa);
                printf("\n");
            }//while

            printf("Insira seu novo ataque e defesa especial respectivamente: ");
            printf("\nAtaque Esp.: ");
            scanf("%d", &pokedex[i].ataqueEspecial);

            while (pokedex[i].ataqueEspecial <= 0){
                printf("Ataque Esp. inválido. Insira um valor adequado: ");
                scanf("%d", &pokedex[i].ataqueEspecial);
            }//while

            printf("Defesa Esp.: ");
            scanf("%d", &pokedex[i].defesaEspecial);

            while (pokedex[i].defesaEspecial <= 0){
                printf("Defesa Esp. inválida. Insira um valor adequado: ");
                scanf("%d", &pokedex[i].defesaEspecial);
                printf("\n");
            }//while

            printf("Por fim, insira sua nova velocidade: ");
            scanf("%d", &pokedex[i].velocidade);

            while (pokedex[i].velocidade <= 0){
                printf("Velocidade inválida. Insira um valor adequado: ");
                scanf("%d", &pokedex[i].velocidade);
                printf("\n");
            }//while

            printf("Esse Pokémon é lendário? Para "
                   "Sim"
                   ", insira 1, e para "
                   "Não"
                   ", insira 0: ");
            scanf("%d", &pokedex[i].lendario);
            printf("\n");

            while (pokedex[i].lendario != 0 && pokedex[i].lendario != 1){
                printf("Insira um valor igual a 0 ou 1.");
                scanf("%d", &pokedex[i].lendario);
                printf("\n");
            }//while

            printf("Insira a nova altura e peso do Pokémon respectivamente: ");
            printf("\nAltura: ");
            scanf("%f", &pokedex[i].altura);

            while (pokedex[i].altura <= 0.0){
                printf("Altura inválida. Insira um valor adequado: ");
                scanf("%f", &pokedex[i].altura);
            }//while

            printf("Peso: ");
            scanf("%f", &pokedex[i].peso);

            while (pokedex[i].peso <= 0.0){
                printf("Peso inválido. Insira um valor adequado: ");
                scanf("%f", &pokedex[i].peso);
                printf("\n");
            }//while

            printf("Insira a nova taxa de captura desse Pokémon: ");
            scanf("%d", &pokedex[i].taxaCaptura);
            printf("\n");

            while (pokedex[i].taxaCaptura <= 0){
                printf("Valor inválido. Insira um valor adequado: ");
                scanf("%d", &pokedex[i].taxaCaptura);
                printf("\n");
            }//while

        }//if

    }//for

    if (achou == 0){
        printf("Pokémon não encontrado.\n");
        printf("\n");
    }//if

    return;

}//alteraPoke

void excluiPoke(Pokemon pokedex[], int tamanho){

    int indice;
    int achou = 0;

    printf("Insira o número do Pokémon que deseja excluir: ");
    scanf("%d", &indice);

    for (int i = 0; i < tamanho; i++){
        if (indice == pokedex[i].numero){

            achou++;

            pokedex[indice].nome[0] = '\0';
            pokedex[indice].tipo1[0] = '\0';
            pokedex[indice].tipo2[0] = '\0';
            pokedex[indice].total = 0;
            pokedex[indice].hp = 0;
            pokedex[indice].ataque = 0;
            pokedex[indice].defesa = 0;
            pokedex[indice].ataqueEspecial = 0;
            pokedex[indice].defesaEspecial = 0;
            pokedex[indice].velocidade = 0;
            pokedex[indice].geracao = 0;
            pokedex[indice].lendario = 0;
            pokedex[indice].cor[0] = '\0';
            pokedex[indice].altura = 0.0;
            pokedex[indice].peso = 0.0;
            pokedex[indice].taxaCaptura = 0;
        }//if

    }//for

    if (achou != 0){
        printf("Pokémon excluído com sucesso!\n");
        printf("\n");
    }else{
        printf("Pokémon não encontrado.\n");
    }//else

    return;

}//excluirPoke

void adicionarPoke(Mochila meuTime[], int tamanho){

    if (meuTime[1].pokemochila != 0){
        printf("Time já preenchido.\n");
        printf("\n");

        return;
    }//if

    for (int i = 1; i < 7; i++){
        printf("Insira o número do %d° Pokémon do time: ", i);
        scanf("%d", &meuTime[i].pokemochila);

        while (meuTime[i].pokemochila == meuTime[i - 1].pokemochila){
            printf("Pokémon já adicionado ao time. Insira outro: ");
            scanf("%d", &meuTime[i].pokemochila);
            printf("\n");
        }//while
        while (meuTime[i].pokemochila <= 0 || meuTime[i].pokemochila > tamanho){
            printf("Pokémon inválido. Insira um número válido: ");
            scanf("%d", &meuTime[i].pokemochila);
            printf("\n");
        }//while

    }//for

    printf("\n");

    return;
    
}//adicionarPoke

void mostrarMochila(Mochila meuTime[], Pokemon pokedex[]){

    if (meuTime[1].pokemochila == 0){
        printf("Time ainda não preenchido.\n");
        printf("\n");
    }else{
        for (int i = 1; i < 7; i++){
            printf("%d° Pokémon: %s.\n", i, pokedex[meuTime[i].pokemochila].nome);
        }//for

        printf("\n");
    }//else

}//mostrarMochila

void alteraMochila(Mochila meuTime[], Pokemon pokedex[], int tamanho){

    int alterar;

    if (meuTime[1].pokemochila == 0){
        printf("Time ainda não preenchido.\n");
        printf("\n");

        return;
    }else{

        printf("Time atual:\n");

        for (int i = 1; i < 7; i++){
            printf("[%d]: %s.\n", i, pokedex[meuTime[i].pokemochila].nome);
        }//for

        printf("\n");

    }//else

    printf("Qual deles deseja alterar? ");
    scanf("%d", &alterar);
    printf("\n");

    while (alterar < 1 || alterar > 6){

        printf("Valor inválido. Insira novamente: ");
        scanf("%d", &alterar);
        printf("\n");
    }//while

    printf("Qual o número do Pokémon que deseja colocar no lugar de %s? ", pokedex[meuTime[alterar].pokemochila].nome);
    scanf("%d", &meuTime[alterar].pokemochila);
    printf("\n");

    while (meuTime[alterar].pokemochila <= 0 || meuTime[alterar].pokemochila > tamanho){
        printf("Pokémon inválido. Insira um número válido: ");
        scanf("%d", &meuTime[alterar].pokemochila);
        printf("\n");
    }//while

    printf("Pokémon alterado com sucesso.\n");
    printf("\n");

    return;

}//alteraMochila

void addColecao(Colecao minhaColecao[], int tamanho, int tamanhoColecao){

    int novoNumero;

    printf("Insira o número do Pokémon que deseja adicionar na coleção: ");

    scanf("%d", &novoNumero);

    while (novoNumero <= 0 || novoNumero > tamanho - 1){
        printf("Pokémon inválido. Insira um valor válido: ");
        scanf("%d", &novoNumero);
    }//while

    int numero_existente = 0;
    for (int i = 0; i < tamanhoColecao; i++){
        if (minhaColecao[i].pokenumero == novoNumero){
            numero_existente = 1;
            break;
        }//if
    }//for

    if (numero_existente){
        printf("Esse Pokémon já está na coleção.\n");
    }else{
        for (int i = 0; i < tamanhoColecao; i++){
            if (minhaColecao[i].pokenumero == 0){
                minhaColecao[i].pokenumero = novoNumero;
                printf("Pokémon adicionado à coleção com sucesso!\n");
                break;
            }//if
        }//for
    }//else

    return;

}

void mostrarColecao(Colecao minhaColecao[], Pokemon pokedex[], int tamanhoColecao){

    int preenchido = 0;

    for (int i = 1; i < tamanhoColecao; i++){
        if (minhaColecao[i].pokenumero != 0){
            preenchido++;
        }//if
    }//for

    if (preenchido == 0){
        printf("Coleção vazia.\n");
        printf("\n");

        return;
    }else{

        printf("Seus Pokémon listados são:\n");

        for (int i = 1; i < tamanhoColecao; i++){
            if (minhaColecao[i].pokenumero != 0){
                printf("Posição [%d]: %d, %s.\n", i, minhaColecao[i].pokenumero, pokedex[minhaColecao[i].pokenumero].nome);
            }//if
        }//for

        printf("\n");

    }//else

    return;

}//mostrarColecao

void buscaColecao(Colecao minhaColecao[], Pokemon pokedex[], int tamanhoColecao){

    char busca_colecao[16];
    int achou = 0;

    printf("Insira o nome do Pokémon que deseja procurar na lista: ");
    jogNome(busca_colecao, 15);

    for (int i = 1; i < tamanhoColecao; i++){

        if (strcmp(busca_colecao, pokedex[minhaColecao[i].pokenumero].nome) == 0){

            printf("Número: %d.\n", pokedex[minhaColecao[i].pokenumero].numero);
            printf("Nome: %s.\n", pokedex[minhaColecao[i].pokenumero].nome);
            printf("Tipo 1: %s.\n", pokedex[minhaColecao[i].pokenumero].tipo1);
            printf("Tipo 2: %s.\n", pokedex[minhaColecao[i].pokenumero].tipo2);
            printf("Total: %d.\n", pokedex[minhaColecao[i].pokenumero].total);
            printf("Hp: %d.\n", pokedex[minhaColecao[i].pokenumero].hp);
            printf("Ataque: %d.\n", pokedex[minhaColecao[i].pokenumero].ataque);
            printf("Defesa: %d.\n", pokedex[minhaColecao[i].pokenumero].defesa);
            printf("Ataque especial: %d.\n", pokedex[minhaColecao[i].pokenumero].ataqueEspecial);
            printf("Defesa especial: %d.\n", pokedex[minhaColecao[i].pokenumero].defesaEspecial);
            printf("Velocidade: %d.\n", pokedex[minhaColecao[i].pokenumero].velocidade);
            printf("Geração: %d°.\n", pokedex[minhaColecao[i].pokenumero].geracao);
            printf("Lendário (0 = não e 1 = sim): %d.\n", pokedex[minhaColecao[i].pokenumero].lendario);
            printf("Cor: %s.\n", pokedex[minhaColecao[i].pokenumero].cor);
            printf("Altura (metros): %.2f.\n", pokedex[minhaColecao[i].pokenumero].altura);
            printf("Peso (kg): %.2f.\n", pokedex[minhaColecao[i].pokenumero].peso);
            printf("Taxa de captura: %d.\n", pokedex[minhaColecao[i].pokenumero].taxaCaptura);
            printf("\n");

            achou++;

        }//if

    }//for

    if (achou == 0){
        printf("Pokémon indisponível na coleção.\n");
        printf("\n");
    }//if

    return;

}//buscaColecao

void alteraColecao(Colecao minhaColecao[], int tamanho, int tamanhoColecao){

    int busca;
    int novoNumero;
    int achou = 0;
    int preenchido = 0;

    for (int i = 1; i < tamanhoColecao; i++){
        if (minhaColecao[i].pokenumero != 0){
            preenchido++;
        }//if
    }//for

    if (preenchido == 0){
        printf("Coleção vazia.\n");
        printf("\n");

        return;
    }else{

        printf("Insira o número do Pokémon da coleção que deseja alterar: ");
        scanf("%d", &busca);

        for (int i = 1; i < tamanhoColecao; i++){

            if (minhaColecao[i].pokenumero == busca){

                printf("Insira o número do novo Pokémon: ");
                scanf("%d", &novoNumero);

                while (novoNumero <= 0 || novoNumero > tamanho - 1){
                    printf("Pokémon inválido. Insira um valor entre 1 e %d: ", tamanho - 1);
                    scanf("%d", &novoNumero);
                }//while

                achou++;

                minhaColecao[i].pokenumero = novoNumero;
                printf("Pokémon alterado com sucesso.\n");
                printf("\n");

                break;
            }//if

        }//for
        if (achou == 0){

            printf("Pokémon indisponível na coleção.\n");
        }//if

    }//else

    return;

}//alterarColecao

void excluiColecao(Colecao minhaColecao[], int tamanhoColecao){

    int busca;
    int achou = 0;
    int preenchido = 0;

    for (int i = 1; i < tamanhoColecao; i++){
        if (minhaColecao[i].pokenumero != 0){
            preenchido++;
        }//if
    }//for

    if (preenchido == 0){
        printf("Coleção vazia.\n");
        printf("\n");

        return;
    }else{

        printf("Insira o número do Pokémon da coleção que deseja excluir: ");
        scanf("%d", &busca);

        for (int i = 1; i < tamanhoColecao; i++){

            if (minhaColecao[i].pokenumero == busca){
                minhaColecao[i].pokenumero = 0;
                achou++;

                printf("Pokémon excluído com sucesso.\n");
                printf("\n");
            }//if
        }//for

        if (achou == 0){
            printf("Pokémon indisponível na coleção.\n");
        }//if

    }//else

    return;

}//excluirColecao

void salvarJogador(FILE *arqjogador, Pokemon *pokedex, Colecao *minhaColecao, Mochila meuTime[], int tamanho, int tamanhoColecao, char nickname[]){

    fclose(arqjogador);

    arqjogador = fopen(nickname, "wb");

    if (arqjogador == NULL){
        printf("Erro na abertura do arquivo do jogador.\n");
        exit(1);
    }//if

    fprintf(arqjogador, "numero ,nome           ,tipo1      ,tipo2      ,total ,hp  ,ataque ,defesa ,ataque_especial ,defesa_especial ,velocidade ,geracao ,lendario ,cor        ,altura_m ,peso_kg ,taxa_captura");

    for (int i = 1; i < tamanho; i++){
        fprintf(arqjogador, "\n%7d,%15s,%11s,%11s,%6d,%4d,%7d,%7d,%16d,%16d,%11d,%8d,%9d,%11s, %7.2f , %6.2f ,%12d",
                pokedex[i].numero, pokedex[i].nome, pokedex[i].tipo1, pokedex[i].tipo2,
                pokedex[i].total, pokedex[i].hp, pokedex[i].ataque, pokedex[i].defesa,
                pokedex[i].ataqueEspecial, pokedex[i].defesaEspecial, pokedex[i].velocidade, pokedex[i].geracao,
                pokedex[i].lendario, pokedex[i].cor, pokedex[i].altura, pokedex[i].peso,
                pokedex[i].taxaCaptura);
    }//for

    fprintf(arqjogador, "\n;");

    fprintf(arqjogador, "\n%d,%d,%d,%d,%d,%d",
            meuTime[1].pokemochila, meuTime[2].pokemochila, meuTime[3].pokemochila,
            meuTime[4].pokemochila, meuTime[5].pokemochila, meuTime[6].pokemochila);

    for (int i = 1; i < tamanhoColecao; i++){
        fprintf(arqjogador, "\n%d", minhaColecao[i].pokenumero);
    }//for

    fprintf(arqjogador, "\n;");
}//salvaJogador

void exportaPokedex(Pokemon *pokedex, Colecao *minhaColecao, Mochila meuTime[], int tamanho, int tamanhoColecao){

    FILE *novo_csv;
    char nome_csv[21];
    int exportaPokedex;

    printf("Deseja exportar uma cópia do arquivo no formato .csv?\n");
    printf("1 - Sim.\n2 - Não.\n");
    printf("Insira sua opção: ");
    scanf("%d", &exportaPokedex);

    while (exportaPokedex < 1 || exportaPokedex > 2){
        printf("Opção inválida. Insira 1 ou 2.\n");
    }//while

    if (exportaPokedex == 1){

        printf("Insira o nome desejado para o arquivo: ");
        jogNome(nome_csv, 20);
        strcat(nome_csv, ".csv");
        novo_csv = fopen(nome_csv, "w");
        printf("\n");

        fprintf(novo_csv, "numero ,nome           ,tipo1      ,tipo2      ,total ,hp  ,ataque ,defesa ,ataque_especial ,defesa_especial ,velocidade ,geracao ,lendario ,cor        ,altura_m ,peso_kg ,taxa_captura");
        for (int i = 1; i < tamanho; i++){
            fprintf(novo_csv, "\n%7d,%15s,%11s,%11s,%6d,%4d,%7d,%7d,%16d,%16d,%11d,%8d,%9d,%11s, %7.2f , %6.2f ,%12d",
                    pokedex[i].numero, pokedex[i].nome, pokedex[i].tipo1, pokedex[i].tipo2,
                    pokedex[i].total, pokedex[i].hp, pokedex[i].ataque, pokedex[i].defesa,
                    pokedex[i].ataqueEspecial, pokedex[i].defesaEspecial, pokedex[i].velocidade, pokedex[i].geracao,
                    pokedex[i].lendario, pokedex[i].cor, pokedex[i].altura, pokedex[i].peso,
                    pokedex[i].taxaCaptura);
        }//for
        fprintf(novo_csv, "\n");
        fprintf(novo_csv, "\nMeu time:");

        for (int i = 1; i < 7; i++){
            fprintf(novo_csv, "\n[%d]: %d, %s.", i, meuTime[i].pokemochila, pokedex[meuTime[i].pokemochila].nome);
        }//for

        fprintf(novo_csv, "\n");

        fprintf(novo_csv, "\nMinha coleção: ");
        for (int i = 1; i < tamanhoColecao; i++){
            fprintf(novo_csv, "\n[%d]: %d, %s.", i, minhaColecao[i].pokenumero, pokedex[minhaColecao[i].pokenumero].nome);
        }//for

        fclose(novo_csv);
        free(pokedex);
        free(minhaColecao);

        printf("Arquivo criado com sucesso!\n");
        printf("\n");

        fclose(novo_csv);
    }else{

        free(pokedex);
        free(minhaColecao);
    }//else

    return;

}//exportaPokedex

int main(){

    int mainMenu, menuJogo, menuPokemon, menuMochila, menuColecao;
    int tamanho = 722, tamanhoColecao = 800;
    char nickname[31];
    char c;

    //Esse cria o arquivo da pokedex e o do jogador
    FILE *arquivoPokedex = fopen("pokedex.csv", "r");
    FILE *arqjogador = fopen("jogador.csv", "w");
    
    Pokemon *pokedex = (Pokemon *)malloc(tamanho * sizeof(Pokemon));
    Colecao *minhaColecao = (Colecao *)malloc(tamanhoColecao * sizeof(Colecao)); // armazena os Pokémon na coleção

    Mochila meuTime[7];
    if (arquivoPokedex == NULL|| arqjogador == NULL || pokedex == NULL || minhaColecao == NULL){
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    }//if

    
    printf("\nSeja bem-vindo ao Projeto Pokemón!\n");
    while (mainMenu < NOVOJOGO || mainMenu > SAIR){
        printf("\n1 - Novo jogo");
        printf("\n2 - Carregar jogo");
        printf("\n3 - Sair\n");
        printf("Insira sua opção:");
        scanf("%d", &mainMenu);
        printf("\n");
        if (mainMenu < 1 || mainMenu > 3){
            printf("Opção inválida! Digite novamente\n");
        }//if
    }//while

    switch (mainMenu){
        case NOVOJOGO:
            for (int i = 0; i < 7; i++){
                meuTime[i].pokemochila = 0;
            }//for

            for (int i = 1; i < tamanhoColecao; i++){
                minhaColecao[i].pokenumero = 0;
            }//for

            arquivoPokedex = fopen("pokedex.csv", "r");

            if (arquivoPokedex == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }//if

            fseek(arquivoPokedex, 174, SEEK_SET);

            for (int i = 1; i < tamanho; i++){

                fscanf(arquivoPokedex, "%d ,%s ,%s ,%s ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%s ,%f ,%f ,%d",
                    &pokedex[i].numero, pokedex[i].nome, pokedex[i].tipo1, pokedex[i].tipo2,
                    &pokedex[i].total, &pokedex[i].hp, &pokedex[i].ataque, &pokedex[i].defesa,
                    &pokedex[i].ataqueEspecial, &pokedex[i].defesaEspecial, &pokedex[i].velocidade, &pokedex[i].geracao,
                    &pokedex[i].lendario, pokedex[i].cor, &pokedex[i].altura, &pokedex[i].peso,
                    &pokedex[i].taxaCaptura);
            }//for

            fclose(arquivoPokedex);

            printf("Insira seu nickname: ");
            jogNome(nickname, 30);
            strcat(nickname, ".dat");
            arqjogador = fopen(nickname, "wb");
            printf("\n");
            break;

        case CARREGARJOGO:

            printf("Insira seu nickname: ");
            jogNome(nickname, 30);
            strcat(nickname, ".dat");
            arqjogador = fopen(nickname, "rb");
            printf("\n Olá de novo %s! Gostaria de continuar sua jornada?\n", nickname);

            if (arqjogador == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }//if
            printf("\n");

            tamanho = 0;

            while ((c = fgetc(arqjogador)) != ';'){

                if (c == '\n'){
                    tamanho++;
                }//if

            }//while

            // realoca depois do calculo das linhas
            pokedex = realloc(pokedex, tamanho * sizeof(Pokemon));

            // Esse é pra primeira linha nao ser lida
            fseek(arqjogador, 184, SEEK_SET);

            for (int i = 1; i < tamanho; i++){

                fscanf(arqjogador, "%d ,%s ,%s ,%s ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%s ,%f ,%f ,%d",
                    &pokedex[i].numero, pokedex[i].nome, pokedex[i].tipo1, pokedex[i].tipo2,
                    &pokedex[i].total, &pokedex[i].hp, &pokedex[i].ataque, &pokedex[i].defesa,
                    &pokedex[i].ataqueEspecial, &pokedex[i].defesaEspecial, &pokedex[i].velocidade, &pokedex[i].geracao,
                    &pokedex[i].lendario, pokedex[i].cor, &pokedex[i].altura, &pokedex[i].peso,
                    &pokedex[i].taxaCaptura);
            
            }//for

            // esse é pro ; nao ser lido
            fseek(arqjogador, 2, SEEK_CUR);

            fscanf(arqjogador, "%d,%d,%d,%d,%d,%d", &meuTime[1].pokemochila, &meuTime[2].pokemochila, &meuTime[3].pokemochila, &meuTime[4].pokemochila, 
            &meuTime[5].pokemochila, &meuTime[6].pokemochila);

            int i = 1;
            tamanhoColecao = 0;

            while ((c = fgetc(arqjogador)) != ';'){
                if (c == '\n'){
                    tamanhoColecao++;
                }//if

                if (c >= '0' && c <= '9'){
                    ungetc(c, arqjogador);
                    fscanf(arqjogador, "%d", &minhaColecao[i].pokenumero);
                    i++;
                }//if

            }//while
            break;
    
        case SAIR:
            exit(1);
            break;
        
        default:
            printf("Opção inválida!\n");
            break;
    }//switch

Menu:
    printf("Menu principal:\n");
    printf("1 - Mochila.\n");
    printf("2 - Coleção.\n");
    printf("3 - Pokédex.\n");
    printf("4 - Sair.\n");
    printf("\nInsira sua opção:");
    scanf("%d", &menuJogo);
    printf("\n");

    while (menuJogo < 0 || menuJogo > 4){
        printf("Opção inválida. Digite novamente\n");
        printf("Menu principal:\n");
        printf("1 - Mochila.\n");
        printf("2 - Coleção.\n");
        printf("3 - Pokédex.\n");
        printf("4 - Sair.\n");
        printf("\nInsira sua opção:");
        scanf("%d", &menuJogo);
        printf("\n");
    }//while

    if (menuJogo == 1){

        do{
            printf("Mochila:\n");
            printf("1 - Inserir Pokémon no time\n");
            printf("2 - Visualizar time.\n");
            printf("3 - Alterar equipe.\n");
            printf("4 - Voltar.\n");
            printf("\n");
            printf("Insira sua opção:");
            scanf("%d", &menuMochila);
            printf("\n");

            while (menuMochila < INSERIRPOKEMON || menuMochila > VOLTARMOCHILA){
                printf("Opção inválida. Digite novamente\n");
                printf("Mochila:\n");
                printf("1 - Inserir Pokémon no time\n");
                printf("2 - Visualizar time.\n");
                printf("3 - Alterar equipe.\n");
                printf("4 - Voltar.\n");
                printf("\n");
                printf("Insira sua opção:");
                scanf("%d", &menuMochila);
                printf("\n");
            }//while

            switch (menuMochila){

                case INSERIRPOKEMON:

                    adicionarPoke(meuTime, tamanho);

                    break;
                case VISUALIZAR:

                    mostrarMochila(meuTime, pokedex);

                    break;

                case ALTERAREQUIPE:

                    printf("%d\n", meuTime[1].pokemochila);
                    alteraMochila(meuTime, pokedex, tamanho);

                    break;

                case VOLTARMOCHILA:

                    goto Menu;

                    break;

            }//switch

        } while (menuMochila != 4);

    }else if (menuJogo == 2){

        printf("Coleção:\n");
        printf("1 - Inserir Pokémon\n");
        printf("2 - Listar coleção\n");
        printf("3 - Pesquisar\n");
        printf("4 - Alterar\n");
        printf("5 - Excluir\n");
        printf("6 - Voltar\n");
        printf("\n");
        printf("Insira sua opção:");
        scanf("%d", &menuColecao);
        printf("\n");

        while (menuColecao < INSERIR || menuColecao > VOLTARCOLECAO){
            printf("Opção inválida. Digite novamente\n");
            printf("Coleção:\n");
            printf("1 - Inserir Pokémon\n");
            printf("2 - Listar coleção\n");
            printf("3 - Pesquisar\n");
            printf("4 - Alterar\n");
            printf("5 - Excluir\n");
            printf("6 - Voltar\n");
            printf("\n");
            printf("Insira sua opção:");
            scanf("%d", &menuColecao);
            printf("\n");
        }//while

        switch (menuColecao){
            case INSERIR:

                if (minhaColecao[tamanhoColecao - 1].pokenumero != 0){
                    minhaColecao = realloc(minhaColecao, (tamanhoColecao + 10) * sizeof(Colecao));

                    for (int i = tamanhoColecao; i < tamanhoColecao + 10; i++){
                        minhaColecao[i].pokenumero = 0;
                    }//for

                    tamanhoColecao += 10;
                }//if

                addColecao(minhaColecao, tamanho, tamanhoColecao);

                break;

            case LISTAR:

                mostrarColecao(minhaColecao, pokedex, tamanhoColecao);

                break;

            case PESQUISAR:

                buscaColecao(minhaColecao, pokedex, tamanhoColecao);

                break;

            case ALTERAR:

                alteraColecao(minhaColecao, tamanho, tamanhoColecao);

                break;

            case EXCLUIR:

                excluiColecao(minhaColecao, tamanhoColecao);

                break;

            case VOLTARCOLECAO:

                goto Menu;

                break;
        }//switch

    
    }else if (menuJogo == 3){

        do{
            printf("Pokédex:\n");
            printf("1 - Inserir\n");
            printf("2 - Listar\n");
            printf("3 - Pesquisar\n");
            printf("4 - Alterar\n");
            printf("5 - Excluir\n");
            printf("6 - Voltar\n");
            printf("\n");
            printf("Insira sua opção:");
            scanf("%d", &menuPokemon);
            printf("\n");

            while (menuPokemon < INSERIR || menuPokemon > VOLTARPOKEDEX){
                printf("Opção inválida. Digite novamente\n");
                printf("Pokédex:\n");
                printf("1 - Inserir\n");
                printf("2 - Listar\n");
                printf("3 - Pesquisar\n");
                printf("4 - Alterar\n");
                printf("5 - Excluir\n");
                printf("6 - Voltar\n");
                printf("\n");
                printf("Insira sua opção:");
                scanf("%d", &menuPokemon);
            }//while

            switch (menuPokemon){
                case INSERIR:

                    tamanho++;
                    pokedex = realloc(pokedex, tamanho * sizeof(Pokemon));

                    cadastrarPokemon(pokedex, tamanho);

                    break;

                case LISTAR:

                    mostrarTodos(pokedex, tamanho);

                    break;

                case PESQUISAR:

                    PesquisarPoke(pokedex, tamanho);

                    break;

                case ALTERAR:

                    alteraPoke(pokedex, tamanho);

                    break;

                case EXCLUIR:

                    excluiPoke(pokedex, tamanho);

                    break;

                case VOLTARPOKEDEX:

                    goto Menu;

                    break;
            }//switch

        } while (menuPokemon != 6);

    }else{

        if (arqjogador != NULL){

            salvarJogador(arqjogador, pokedex, minhaColecao, meuTime, tamanho, tamanhoColecao, nickname);
            fclose(arqjogador);

            exportaPokedex(pokedex, minhaColecao, meuTime, tamanho, tamanhoColecao);
            free(pokedex);
            free(minhaColecao);
        }//if

    }//else

    return 0;

}//main