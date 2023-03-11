
/*
Trabalho desenvolvido e apresentado ao Centro Federal de Educação Tecnológica de Minas Gerais(CEFET-MG)
Integrantes do trabalho:

* Vitor Mendes de Oliveira Abreu
* William Duarte de Andrade
* Lucas Lima Lopes
* Julia Bretas de Souza Ribeiro
* Ramon Luiz Souza Bhering Cruz
* Diogo Augusto Alves Fagundes

O intuito deste trabalho é simular um gerenciamento de um catálago de filmes. 
Neste trabalho, onde o usúario interage diretamente
com o programa e insere, edita, remove e imprime os filmes no catálogo, o programa 
processa os dados e realiza a operação desejada pelo usuário.
Foi utilizado vetores, apontadores e structs dentre outras operações que foram apresentadas durante as aulas de PC1.

*/

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct {			//Criando a estrutura principal do programa que será a base de dados a ser gerenciada, aqui ficará todo o catálogo so usuário

    int identificador;

    char nome[50];

    char genero[30];

    int anoLancamento;

    char nomeDiretor[30];


}Filme;


int main(){			//Funcao main é a parte rincipal do programa, ela chama todos os métodos necessários para o desenvolvimento e gerenciamento do catálogo de filmes

    Filme vetorFilmes[150];

    setlocale(LC_ALL ,"Portuguese");        //Definindo configuirações
    setlocale(LC_CTYPE,"pt_BR.UTF-8");

    int contaFilmes = 0, verificador = 1, contador1 = 1, opcoes;        //Criando variaveis

    int selecaoMenu, i;

    while(contador1 == 1){

        printf("Bem vindo ao menu principal!\n");
        printf("Selecione uma das opções do desejadas do menu para realizar uma ação\n");      //Mostrando menu proncipal
        printf("\nDigite [1] para adicionar um filme ");
        printf("\nDigite [2] para editar um filme ");
        printf("\nDigite [3] para remover um filme ");
        printf("\nDigite [4] para imprimir um filme \n\n");
        printf("Insira sua opção: ");

        scanf("%d",&selecaoMenu);

        printf("\n");                                                       //Apenas para tornar o menu do programa mais elegante

        if(selecaoMenu <1 || selecaoMenu > 4){

            while(selecaoMenu <1 || selecaoMenu > 4){

                printf("\nDesculpe, opção não encontrada! Favor inserir novamente um valor válido: \n");        //Validando entradas
                scanf("%d", &selecaoMenu);

            }

        }

         switch (selecaoMenu){                  //Selecionando opções, aqui o usuário irá gerenciar o catálogo e escolher a ação

            case  1:

            while(verificador == 1){

                adicionaFilme(vetorFilmes,&contaFilmes);        //Chamando funcao de adicionar filme

                printf("\nDeseja adicionar mais um filme? Digite [1] para 'sim' / Digite [0] para 'não': ");
                scanf("%d", &verificador);

                if(verificador == 0){

                    printf("\nFilme adicionado!\n");

                }
            }

            verificador = 1;

                break;

            case  2:

                while(verificador == 1){

                    printf("\nDeseja pesquisar um filme por índice ou por nome?\n\n");

                    printf("\n[0] para pesquisar por índice");
                    printf("\n[1] para pesquisar por nome\n\n");
                    scanf("%d", &opcoes);

                    while(opcoes !=0 && opcoes !=1){

                        printf("Opção não encontrada, favor inserir um número válido novamente!\n\n");
                        scanf("%d", &opcoes);

                    }

                    editaFilme (vetorFilmes,&contaFilmes, opcoes);          //Chamando funcao de editar filme

                    printf("\n\nDeseja editar mais algum filme? [1] sim / [0] não: ");
                    scanf("%d", &verificador);

                }

                verificador = 1;

                break;

            case  3:

                while(verificador == 1){

                removeFilme (vetorFilmes,&contaFilmes);                 //Chamando funcao de remover filme

                printf("\nDeseja remover mais um filme? [1] sim / [0] não: ");
                scanf("%d", &verificador);

                i = 0;

                if(verificador == 0){

                    printf("\nAlterações efetuadas com sucesso!\n");
                    break;

                }


            }

            verificador = 1;



                break;

            case  4:


                while(verificador == 1){

                    printf("\nDeseja imprimir apenas um filme ou todo catálogo?\n\n");

                    printf("\n[0] para catálogo");
                    printf("\n[1] para um filme em específico\n\n");
                    scanf("%d", &opcoes);

                    while(opcoes !=0 && opcoes !=1){

                        printf("Opção não encontrada, favor inserir um número válido novamente!\n\n");
                        scanf("%d", &opcoes);

                    }


                    imprimeFilmes (vetorFilmes,&contaFilmes, opcoes);           //Chamando funcao que imprime os filmes cadastrados

                    printf("\n\nDeseja imprimir o catálogo novamente [1] sim / [0] não: ");
                    scanf("%d", &verificador);

                }

                verificador = 1;

    }

    printf("\nDeseja continuar o uso do menu: [1] sim / [0] não: ");		//apos a operação já realizada
    scanf("%d", &contador1);

    printf("\n");

    if (contador1 !=0 && contador1 !=1){

        while(contador1 !=0 && contador1 !=1 ){

            printf("Desculpe, operação não encontrada,favor inserir o valor novamente\n");		//validando dados
            printf("Deseja continuar o uso do menu: [1] sim / [0] não: ");
            scanf("%d", &contador1);

        }
    }

}

    printf("Fim do programa!");		//aqui o programa se encerra

return 0;
}


void editaFilme(Filme vetorFilmes[],int *contaFilmes, int opcoes){       //Implementação da função que edita o filme desejado

    char nomeFilme[50];													//Declarando variaveis
    int VerificaCatalogo = 0;
    int i = 0, i2 = 0,j, j2 = 0, indice;

    printf("Escolha o filme que será editado:\n\n");

     for(j = 0;j < *contaFilmes; j++){									//mostrar os filmes já adicionados

        printf("\n\nFilme [%d] ", j+1);
        printf("\nNome: %s", vetorFilmes[j].nome);
        printf("\nGênero: %s", vetorFilmes[j].genero);
        printf("\nAno de lançamento: %d", vetorFilmes[j].anoLancamento);
        printf("\nNome do diretor: %s ", vetorFilmes[j].nomeDiretor);

        printf("\n\n");

    }


    if(opcoes == 0 && *contaFilmes > 0){

        fflush(stdin);					//Função que limpa os buffers de saída

        while(j2< 1){

            printf("Digite o índice do filme que deseja alterar: ");
            scanf("%d", &indice);

            if(indice < 1 || indice > *contaFilmes){

                printf("índice invalido, digite novamente!\n ");		//validando entrdada
                j2 = j2 -1;
            }

            j2 = j2+1;
        }

        j2 = 0;

        indice = indice -1; //Ja que no vetor começa no 0;

        fflush(stdin);

       while(i < 1){    //laço de repetição criado

            fflush(stdin);

            printf("\nDigite o novo nome do filme editado: ");
            scanf("%[^\n]", vetorFilmes[indice].nome);

            fflush(stdin);
            printf("\nDigite o novo genero do filme editado: ");
            scanf("%[^\n]", vetorFilmes[indice].genero);

            fflush(stdin);
            printf("\nDigite o novo ano de lançamento do filme editado: ");
            scanf("%d", &vetorFilmes[indice].anoLancamento);

            if(vetorFilmes[indice].anoLancamento < 1900 || vetorFilmes[indice].anoLancamento > 2021){		//validando entrdada

                printf("\nApenas filmes lançados entre 1900 e 2021 serão aceitos\n");
                printf("Por favor, edite o filme novamente!");
                continue;

            }

            else{

            fflush(stdin);

            printf("\nDigite o novo nome do diretor do filme editado: ");				//Recolhendo dados
            scanf("%[^\n]", vetorFilmes[indice].nomeDiretor);
            VerificaCatalogo = 1;

            }

            i = i +1;

       }

        i = 0;

    }
    else if(opcoes == 1 && *contaFilmes > 0){

        fflush(stdin);

        printf("Digite o nome do filme que deseja alterar: ");					//Recolhendo dados
        scanf("%[^\n]", nomeFilme);

        fflush(stdin);

        for(j = 0; j < *contaFilmes; j++){

            if((strcmp(nomeFilme,vetorFilmes[j].nome)) == 0 ){

                fflush(stdin);

                printf("\nDigite o novo nome do filme editado: ");
                scanf("%[^\n]", vetorFilmes[j].nome);

                fflush(stdin);

                printf("\nDigite o novo genero do filme editado: ");
                scanf("%[^\n]", vetorFilmes[j].genero);

                fflush(stdin);

                printf("\nDigite o novo ano de lançamento do filme editado: ");
                scanf("%d", &vetorFilmes[j].anoLancamento);

                if(vetorFilmes[j].anoLancamento < 1900 || vetorFilmes[j].anoLancamento > 2021){

                    printf("\nSomente são aceitos filmes no catálogo, lançados entre 1900 e 2021\n");		//validando entrada
                    printf("Por favor, edite o filme novamente!");

                    while(i2 < 1){

                        fflush(stdin);

                        printf("\nDigite o novo nome do filme editado: ");
                        scanf("%[^\n]", vetorFilmes[j].nome);

                        fflush(stdin);
                        printf("\nDigite o novo genero do filme editado: ");
                        scanf("%[^\n]", vetorFilmes[j].genero);

                        fflush(stdin);
                        printf("\nDigite o novo ano de lançamento do filme editado: ");
                        scanf("%d", &vetorFilmes[j].anoLancamento);

                        if(vetorFilmes[j].anoLancamento < 1900 || vetorFilmes[j].anoLancamento > 2021){

                            printf("\nSomente são aceitos filmes no catálogo, lançados entre 1900 e 2021\n");		//validando entrada
                            printf("Por favor, edite o filme novamente!");
                            printf("%d", i2);

                            i2 = i2-1;

                        }
                        else{

                            fflush(stdin);

                            printf("\nDigite o novo nome do diretor do filme editado: ");		//recolhendo dados
                            scanf("%[^\n]", vetorFilmes[indice].nomeDiretor);
                            VerificaCatalogo = 1;

                        }

                        i2 = i2 +1;

                   }

                    i2 = 0;

                }
                else{

                    fflush(stdin);

                    printf("\nDigite o novo nome do diretor do filme editado: ");		//recolhendo dados
                    scanf("%[^\n]", vetorFilmes[j].nomeDiretor);

                VerificaCatalogo = 1;

                }

            }

        }

    }

        if (VerificaCatalogo == 0){

            printf("Não existem filmes na base de dados com o nome inserido para serem editados!");		//validando dados

        }

        VerificaCatalogo = 0;

        i2 = 0;

    }
void adicionaFilme(Filme vetorFilmes[], int *contaFilmes){       //Implementação da função que adiciona o filme desejado

    printf("\nAtente-se ao limite de 150 filmes simultâneos!\n");
    printf("Atualmente existem %d filmes no catálogo\n",*contaFilmes);

        fflush(stdin);          //Função que limpa os buffers de saída
        printf("\nDigite o nome do filme: ");
        scanf("%[^\n]", vetorFilmes[*contaFilmes].nome);

        fflush(stdin);
        printf("Digite o gênero do filme: ");
        scanf("%[^\n]", vetorFilmes[*contaFilmes].genero);

        fflush(stdin);
        printf("Digite o ano de lançamento do filme: ");
        scanf("%d", &vetorFilmes[*contaFilmes].anoLancamento);

        if(vetorFilmes[*contaFilmes].anoLancamento < 1900 || vetorFilmes[*contaFilmes].anoLancamento > 2021){

            printf("\nAoenas filmes lançados entre 1900 e 2021 são aceitos");			//validando dados
            *contaFilmes = *contaFilmes - 1;
        }

        else{

        fflush(stdin);
        printf("Digite o nome do diretor do filme: ");
        scanf("%[^\n]", vetorFilmes[*contaFilmes].nomeDiretor);
        }


        *contaFilmes = *contaFilmes + 1;

    }

void imprimeFilmes(Filme vetorFilmes[],int *contaFilmes, int opcoes){					//Implementação da função que imprime os filme desejados

    int VerificaCatalogo = 0;
    char nomeFilme[50];				//iniciando variaveis
    int i = 0;

    if(opcoes == 0 && *contaFilmes > 0 ){

            for( i =0 ; i < *contaFilmes; i++){

                printf("\n\nFilme [%d] ", i+1);
                printf("\nNome: %s", vetorFilmes[i].nome);
                printf("\nGênero: %s", vetorFilmes[i].genero);
                printf("\nAno de lançamento: %d", vetorFilmes[i].anoLancamento);
                printf("\nNome do diretor: %s ", vetorFilmes[i].nomeDiretor);

                printf("\n\n");

            }

    }
     else if (opcoes == 1 && *contaFilmes > 0 ){

        fflush(stdin);
        printf("\nEscreva o nome do filme que deseja ");
        scanf("%[^\n]", nomeFilme);


        for( i = 0; i < *contaFilmes; i++ ){


            if((strcmp(nomeFilme,vetorFilmes[i].nome)) == 0 ){		//exibindo dados

                printf("\n\nFilme [%d] ", i+1);
                printf("\nNome: %s", vetorFilmes[i].nome);
                printf("\nGênero: %s", vetorFilmes[i].genero);
                printf("\nAno de lançamento: %d", vetorFilmes[i].anoLancamento);
                printf("\nNome do diretor: %s ", vetorFilmes[i].nomeDiretor);

                VerificaCatalogo = 1;
            }

        }

        if (VerificaCatalogo == 0){			//validando dados

            printf("Não existem filmes na base de dados com o nome digitado para serem catalogados!");

        }

        VerificaCatalogo = 0;


    }
    if(*contaFilmes == 0){

        printf("Não existe este filme no catálogo! ");

    }

}

void removeFilme(Filme vetorFilmes[],int *contaFilmes){						//Implementação da função que remove o filme desejado

    int numFilme;

    if(*contaFilmes > 0){

        for(int i =0 ; i< *contaFilmes; i++){

                printf("\n\nFilme [%d] ", i+1);
                printf("\nNome: %s", vetorFilmes[i].nome);
                printf("\nGênero: %s", vetorFilmes[i].genero);
                printf("\nAno de lançamento: %d", vetorFilmes[i].anoLancamento);
                printf("\nNome do diretor: %s ", vetorFilmes[i].nomeDiretor);

                printf("\n\n");

            }

        printf("\nDigite o número do filme que queira remover:  ");
        scanf("%d", &numFilme);

        if (numFilme > *contaFilmes || numFilme <= 0){

            while(numFilme > *contaFilmes || numFilme <= 0){

           printf("\nNão foi encontrado o filme no catálogo, digite outro número novamente:");
           scanf("%d", &numFilme);

            }

    }

        for( int i = numFilme-1; i < 150; i++){			//limitado a 150 filmes

           strcpy(vetorFilmes[i].nome , vetorFilmes[i+1].nome);
           strcpy(vetorFilmes[i].genero,vetorFilmes[i+1].genero);		//A funcao strcpy() copia a string apontada para o destino
           vetorFilmes[i].anoLancamento = vetorFilmes[i+1].anoLancamento;
           strcpy(vetorFilmes[i].nomeDiretor,vetorFilmes[i+1].nomeDiretor);


        }


    *contaFilmes = *contaFilmes - 1;

    }


    else{

         printf("\nNâo há filme para sere removido");
    }




}



