#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <vector>
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ESTRUTURAS
struct PalavraTabelada //Basicamente uma lista de palavras contendo score, ocorrencias e a palavra em si
{
    int Ocorrencias;
    float Score;
    std:: string Palavra;

};
typedef struct PalavraTabelada PalavraTabelada;

struct LetraIndice    //Tabela contendo as letras do alfabeto, e cada uma tem uma lista correspondente de palavras
{
    char letra;
    std::list<PalavraTabelada> Palavras;
};
typedef struct LetraIndice LetraIndice;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ESTRUTURAS DE DADOS

void InicializaIndice(std::vector<LetraIndice> &ListaIndice); //onde ListaIndice deve ser o vetor alfab�tico
void InserePalavra(std::vector<LetraIndice> &Indice, std::vector<std::string> Comentarios); //Indice � o vetor alfab�tico, Comentarios o vetor de coment�rios armazenado


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ARQUIVO
int LeArquivo (std::vector<std::string> &Comentarios); //Comentarios � o vetor onde ser� armazenado os  coment�rios do arquivo
void BuscaComentario (std::vector<std::string> Comentario, std::string word, int polaridade); // word � a palavra que ser� buscada e polaridade 0 se for neutro, 1 se for positivo ou 2 se for negativo


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//COMENT�RIOS E SCORES

void CalculaScoreSIMPLES(std::string Comentario, std::vector<LetraIndice> Indice); //Sem tratamento
void CalculaScore(std::string Comentario, std::vector<LetraIndice> Indice); //Sem stopwords

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//MENU
void kPalavras (std::vector<LetraIndice> Indice, int j); //Busca as k-palavras de maior ocorrencia, onde j � o ranking desejado, por ex j = 10 dar� as top-10 palavras.


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DEBUG
void PrintaVetor(std::vector<std::string> Comentarios);
void ImprimeListasAlfabeticas(std::vector<LetraIndice> Indice);



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
