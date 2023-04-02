
/*
Trabalho desenvolvido e apresentado ao Centro Federal de Educa��o Tecnol�gica de Minas Gerais(CEFET-MG)

* Vitor Mendes de Oliveira Abreu

O intuito deste trabalho é simular um gerenciamento de um cat�lago de filmes. 
Neste trabalho, onde o us�ario interage diretamente
com o programa e insere, edita, remove e imprime os filmes no cat�logo, o programa 
processa os dados e realiza a opera��o desejada pelo usu�rio.
Foi utilizado vetores, apontadores e structs dentre outras opera��es que foram apresentadas durante as aulas de PC1.

*/

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct {			//Criando a estrutura principal do programa que ser� a base de dados a ser gerenciada, aqui ficar� todo o cat�logo so usu�rio

    int identificador;

    char nome[50];

    char genero[30];

    int anoLancamento;

    char nomeDiretor[30];


}Filme;


int main(){			//Funcao main � a parte rincipal do programa, ela chama todos os m�todos necess�rios para o desenvolvimento e gerenciamento do cat�logo de filmes

    Filme vetorFilmes[150];

    setlocale(LC_ALL ,"Portuguese");        //Definindo configuira��es
    setlocale(LC_CTYPE,"pt_BR.UTF-8");

    int contaFilmes = 0, verificador = 1, contador1 = 1, opcoes;        //Criando variaveis

    int selecaoMenu, i;

    while(contador1 == 1){

        printf("Bem vindo ao menu principal!\n");
        printf("Selecione uma das op��es do desejadas do menu para realizar uma a��o\n");      //Mostrando menu proncipal
        printf("\nDigite [1] para adicionar um filme ");
        printf("\nDigite [2] para editar um filme ");
        printf("\nDigite [3] para remover um filme ");
        printf("\nDigite [4] para imprimir um filme \n\n");
        printf("Insira sua op��o: ");

        scanf("%d",&selecaoMenu);

        printf("\n");                                                       //Apenas para tornar o menu do programa mais elegante

        if(selecaoMenu <1 || selecaoMenu > 4){

            while(selecaoMenu <1 || selecaoMenu > 4){

                printf("\nDesculpe, op��o n�o encontrada! Favor inserir novamente um valor v�lido: \n");        //Validando entradas
                scanf("%d", &selecaoMenu);

            }

        }

         switch (selecaoMenu){                  //Selecionando op��es, aqui o usu�rio ir� gerenciar o cat�logo e escolher a a��o

            case  1:

            while(verificador == 1){

                adicionaFilme(vetorFilmes,&contaFilmes);        //Chamando funcao de adicionar filme

                printf("\nDeseja adicionar mais um filme? Digite [1] para 'sim' / Digite [0] para 'n�o': ");
                scanf("%d", &verificador);

                if(verificador == 0){

                    printf("\nFilme adicionado!\n");

                }
            }

            verificador = 1;

                break;

            case  2:

                while(verificador == 1){

                    printf("\nDeseja pesquisar um filme por �ndice ou por nome?\n\n");

                    printf("\n[0] para pesquisar por �ndice");
                    printf("\n[1] para pesquisar por nome\n\n");
                    scanf("%d", &opcoes);

                    while(opcoes !=0 && opcoes !=1){

                        printf("Op��o n�o encontrada, favor inserir um n�mero v�lido novamente!\n\n");
                        scanf("%d", &opcoes);

                    }

                    editaFilme (vetorFilmes,&contaFilmes, opcoes);          //Chamando funcao de editar filme

                    printf("\n\nDeseja editar mais algum filme? [1] sim / [0] n�o: ");
                    scanf("%d", &verificador);

                }

                verificador = 1;

                break;

            case  3:

                while(verificador == 1){

                removeFilme (vetorFilmes,&contaFilmes);                 //Chamando funcao de remover filme

                printf("\nDeseja remover mais um filme? [1] sim / [0] n�o: ");
                scanf("%d", &verificador);

                i = 0;

                if(verificador == 0){

                    printf("\nAltera��es efetuadas com sucesso!\n");
                    break;

                }


            }

            verificador = 1;



                break;

            case  4:


                while(verificador == 1){

                    printf("\nDeseja imprimir apenas um filme ou todo cat�logo?\n\n");

                    printf("\n[0] para cat�logo");
                    printf("\n[1] para um filme em espec�fico\n\n");
                    scanf("%d", &opcoes);

                    while(opcoes !=0 && opcoes !=1){

                        printf("Op��o n�o encontrada, favor inserir um n�mero v�lido novamente!\n\n");
                        scanf("%d", &opcoes);

                    }


                    imprimeFilmes (vetorFilmes,&contaFilmes, opcoes);           //Chamando funcao que imprime os filmes cadastrados

                    printf("\n\nDeseja imprimir o cat�logo novamente [1] sim / [0] n�o: ");
                    scanf("%d", &verificador);

                }

                verificador = 1;

    }

    printf("\nDeseja continuar o uso do menu: [1] sim / [0] n�o: ");		//apos a opera��o j� realizada
    scanf("%d", &contador1);

    printf("\n");

    if (contador1 !=0 && contador1 !=1){

        while(contador1 !=0 && contador1 !=1 ){

            printf("Desculpe, opera��o n�o encontrada,favor inserir o valor novamente\n");		//validando dados
            printf("Deseja continuar o uso do menu: [1] sim / [0] n�o: ");
            scanf("%d", &contador1);

        }
    }

}

    printf("Fim do programa!");		//aqui o programa se encerra

return 0;
}


void editaFilme(Filme vetorFilmes[],int *contaFilmes, int opcoes){       //Implementa��o da fun��o que edita o filme desejado

    char nomeFilme[50];													//Declarando variaveis
    int VerificaCatalogo = 0;
    int i = 0, i2 = 0,j, j2 = 0, indice;

    printf("Escolha o filme que ser� editado:\n\n");

     for(j = 0;j < *contaFilmes; j++){									//mostrar os filmes j� adicionados

        printf("\n\nFilme [%d] ", j+1);
        printf("\nNome: %s", vetorFilmes[j].nome);
        printf("\nG�nero: %s", vetorFilmes[j].genero);
        printf("\nAno de lan�amento: %d", vetorFilmes[j].anoLancamento);
        printf("\nNome do diretor: %s ", vetorFilmes[j].nomeDiretor);

        printf("\n\n");

    }


    if(opcoes == 0 && *contaFilmes > 0){

        fflush(stdin);					//Fun��o que limpa os buffers de sa�da

        while(j2< 1){

            printf("Digite o �ndice do filme que deseja alterar: ");
            scanf("%d", &indice);

            if(indice < 1 || indice > *contaFilmes){

                printf("�ndice invalido, digite novamente!\n ");		//validando entrdada
                j2 = j2 -1;
            }

            j2 = j2+1;
        }

        j2 = 0;

        indice = indice -1; //Ja que no vetor come�a no 0;

        fflush(stdin);

       while(i < 1){    //la�o de repeti��o criado

            fflush(stdin);

            printf("\nDigite o novo nome do filme editado: ");
            scanf("%[^\n]", vetorFilmes[indice].nome);

            fflush(stdin);
            printf("\nDigite o novo genero do filme editado: ");
            scanf("%[^\n]", vetorFilmes[indice].genero);

            fflush(stdin);
            printf("\nDigite o novo ano de lan�amento do filme editado: ");
            scanf("%d", &vetorFilmes[indice].anoLancamento);

            if(vetorFilmes[indice].anoLancamento < 1900 || vetorFilmes[indice].anoLancamento > 2021){		//validando entrdada

                printf("\nApenas filmes lan�ados entre 1900 e 2021 ser�o aceitos\n");
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

                printf("\nDigite o novo ano de lan�amento do filme editado: ");
                scanf("%d", &vetorFilmes[j].anoLancamento);

                if(vetorFilmes[j].anoLancamento < 1900 || vetorFilmes[j].anoLancamento > 2021){

                    printf("\nSomente s�o aceitos filmes no cat�logo, lan�ados entre 1900 e 2021\n");		//validando entrada
                    printf("Por favor, edite o filme novamente!");

                    while(i2 < 1){

                        fflush(stdin);

                        printf("\nDigite o novo nome do filme editado: ");
                        scanf("%[^\n]", vetorFilmes[j].nome);

                        fflush(stdin);
                        printf("\nDigite o novo genero do filme editado: ");
                        scanf("%[^\n]", vetorFilmes[j].genero);

                        fflush(stdin);
                        printf("\nDigite o novo ano de lan�amento do filme editado: ");
                        scanf("%d", &vetorFilmes[j].anoLancamento);

                        if(vetorFilmes[j].anoLancamento < 1900 || vetorFilmes[j].anoLancamento > 2021){

                            printf("\nSomente s�o aceitos filmes no cat�logo, lan�ados entre 1900 e 2021\n");		//validando entrada
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

            printf("N�o existem filmes na base de dados com o nome inserido para serem editados!");		//validando dados

        }

        VerificaCatalogo = 0;

        i2 = 0;

    }
void adicionaFilme(Filme vetorFilmes[], int *contaFilmes){       //Implementa��o da fun��o que adiciona o filme desejado

    printf("\nAtente-se ao limite de 150 filmes simult�neos!\n");
    printf("Atualmente existem %d filmes no cat�logo\n",*contaFilmes);

        fflush(stdin);          //Fun��o que limpa os buffers de sa�da
        printf("\nDigite o nome do filme: ");
        scanf("%[^\n]", vetorFilmes[*contaFilmes].nome);

        fflush(stdin);
        printf("Digite o g�nero do filme: ");
        scanf("%[^\n]", vetorFilmes[*contaFilmes].genero);

        fflush(stdin);
        printf("Digite o ano de lan�amento do filme: ");
        scanf("%d", &vetorFilmes[*contaFilmes].anoLancamento);

        if(vetorFilmes[*contaFilmes].anoLancamento < 1900 || vetorFilmes[*contaFilmes].anoLancamento > 2021){

            printf("\nAoenas filmes lan�ados entre 1900 e 2021 s�o aceitos");			//validando dados
            *contaFilmes = *contaFilmes - 1;
        }

        else{

        fflush(stdin);
        printf("Digite o nome do diretor do filme: ");
        scanf("%[^\n]", vetorFilmes[*contaFilmes].nomeDiretor);
        }


        *contaFilmes = *contaFilmes + 1;

    }

void imprimeFilmes(Filme vetorFilmes[],int *contaFilmes, int opcoes){					//Implementa��o da fun��o que imprime os filme desejados

    int VerificaCatalogo = 0;
    char nomeFilme[50];				//iniciando variaveis
    int i = 0;

    if(opcoes == 0 && *contaFilmes > 0 ){

            for( i =0 ; i < *contaFilmes; i++){

                printf("\n\nFilme [%d] ", i+1);
                printf("\nNome: %s", vetorFilmes[i].nome);
                printf("\nG�nero: %s", vetorFilmes[i].genero);
                printf("\nAno de lan�amento: %d", vetorFilmes[i].anoLancamento);
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
                printf("\nG�nero: %s", vetorFilmes[i].genero);
                printf("\nAno de lan�amento: %d", vetorFilmes[i].anoLancamento);
                printf("\nNome do diretor: %s ", vetorFilmes[i].nomeDiretor);

                VerificaCatalogo = 1;
            }

        }

        if (VerificaCatalogo == 0){			//validando dados

            printf("N�o existem filmes na base de dados com o nome digitado para serem catalogados!");

        }

        VerificaCatalogo = 0;


    }
    if(*contaFilmes == 0){

        printf("N�o existe este filme no cat�logo! ");

    }

}

void removeFilme(Filme vetorFilmes[],int *contaFilmes){						//Implementa��o da fun��o que remove o filme desejado

    int numFilme;

    if(*contaFilmes > 0){

        for(int i =0 ; i< *contaFilmes; i++){

                printf("\n\nFilme [%d] ", i+1);
                printf("\nNome: %s", vetorFilmes[i].nome);
                printf("\nG�nero: %s", vetorFilmes[i].genero);
                printf("\nAno de lan�amento: %d", vetorFilmes[i].anoLancamento);
                printf("\nNome do diretor: %s ", vetorFilmes[i].nomeDiretor);

                printf("\n\n");

            }

        printf("\nDigite o n�mero do filme que queira remover:  ");
        scanf("%d", &numFilme);

        if (numFilme > *contaFilmes || numFilme <= 0){

            while(numFilme > *contaFilmes || numFilme <= 0){

           printf("\nN�o foi encontrado o filme no cat�logo, digite outro n�mero novamente:");
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

         printf("\nN�o h� filme para sere removido");
    }




}



