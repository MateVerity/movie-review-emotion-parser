#include "head.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> Comentarios;                //Vetor que armazena os comentários do arquivo de entrada.
    std::vector<LetraIndice> Indice(26);                 //Vetor que armazena a tabela alfabética, cada qual contendo os comentários com os scores da sua letra especifica.
    int OpcaoMenu;                                       //Detecta a opção desejada no menu.

    InicializaIndice(Indice);                            //Inicializa o vetor com nulos e zeros
    LeArquivo(Comentarios);                              //Armazena as informações do arquivo de entrada no vetor

    InserePalavra(Indice, Comentarios);


    for(;;){
    std::cout << "\nDigite a opcao desejada : " << "\n1. Classificar comentario (classificador versao simples)" << "\n2. Classificar comentario (classificador versao melhorada)" << "\n3. Buscar comentario por palavra e polaridade" <<"\n4. k-Palavras de maior ocorrencia\n";
    std::cin >> OpcaoMenu;
    fflush(stdin);

    switch(OpcaoMenu)
    {

    case 1 :
    {


        std::string Comentario;
        std::cout << "\nDigite um comentario por favor : ";
        std::getline(std::cin, Comentario);
        fflush(stdin);
        std::cout << "\nO comentario digitado foi : " << Comentario;

        CalculaScoreSIMPLES(Comentario, Indice);
        break;
    }

    case 2 :
    {
        std::string Comentario;
        std::cout << "\nDigite um comentario por favor : ";
        std::getline(std::cin, Comentario);
        fflush(stdin);
        std::cout << "\nO comentario digitado foi : " << Comentario;

        CalculaScore(Comentario, Indice);
        break;

    }

    case 3 :
        {

        std::string Palavra;
        int l;
        std::cout << "\nDigite uma palavra por favor : ";
        std::getline(std::cin, Palavra);
        std::cout << "\nDigite 0 para todas polaridades, 1 para so positivas e 2 para so negativas";
        fflush(stdin);
        std::cin >> l;
        BuscaComentario(Comentarios, Palavra, l);
        break;
        }
    case 4 :
        {
        int k;
        std::cout << "\nDigite o tamanho do ranking K desejado : ";
        std::cin >> k;
        kPalavras(Indice, k);
        break;
        }



    }}







}
