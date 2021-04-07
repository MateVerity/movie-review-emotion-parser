#include <iostream>
#include "head.h"
#include <list>
#include <string>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>

int LeArquivo (std::vector<std::string> &Comentarios)
{
    using namespace std;
    string line;
    int i = 0;

    ifstream myFile("movieReviews.txt", ios::out);

    if(myFile.is_open() == true)
    {
        while ( getline(myFile, line))
        {
            Comentarios.push_back(line + '\n');
            i++;
        }
        myFile.close();
        return 1;
    }
    else
        perror("Erro ao abrir arquivo!");
    return 0;
}
void PrintaVetor(std::vector<std::string> Comentarios)
{
    for (std::vector<std::string>::const_iterator i = Comentarios.begin(); i != Comentarios.end(); ++i)
        std::cout << *i << ' ';
}
void InicializaIndice(std::vector<LetraIndice> &ListaIndice)
{
    LetraIndice novo;
    char alfabeto[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int k = 0;

    for(k = 0; k < 26; k++)
    {
        novo.letra = alfabeto[k];
        ListaIndice[k] = novo;
    }
}
void InserePalavra(std::vector<LetraIndice> &Indice, std::vector<std::string> Comentarios)
{



    for(unsigned int p = 0; p != Comentarios.size(); p++)
    {
        int   k = 0;

        std::string buf;
        std::stringstream ss(Comentarios[p]);
        std::vector<std::string> tokens;
        while(ss >> buf)
        {
            if(buf[0] == ',' || buf[0] == '.' || buf[0] == '\'')
                continue;
            tokens.push_back(buf);
            std::transform(tokens[k].begin(), tokens[k].end(), tokens[k].begin(), ::tolower);
            char score = tokens[0][0];
            int realscore = score - '0';
            PalavraTabelada NovaPalavra;
            NovaPalavra.Ocorrencias = 1;
            NovaPalavra.Palavra = tokens[k];
            NovaPalavra.Score = realscore;
            int flag = 0;

            for(std::vector<LetraIndice>::iterator it = Indice.begin(); it != Indice.end(); ++it)
            {
                if(it->letra == tokens[k][0])
                {
                    if(it->Palavras.empty() == true)
                    {
                        it->Palavras.push_back(NovaPalavra);
                        break;
                    }
                    else
                    {
                        for(std::list<PalavraTabelada>::iterator it2 = it->Palavras.begin(); it2 != it->Palavras.end(); ++it2)
                        {
                            if(it2->Palavra == tokens[k])
                            {
                                it2->Ocorrencias++;
                                it2->Score = ((it2->Score+realscore)/2);
                                flag = 1;
                                break;
                            }
                        }
                        if(flag == 0)
                        {
                            it->Palavras.push_back(NovaPalavra);
                            break;
                        }
                        else
                            break;
                    }
                }
            }
            k++;
        }
    }
}

void ImprimeListasAlfabeticas(std::vector<LetraIndice> Indice)
{
    for(std::vector<LetraIndice>::iterator it = Indice.begin(); it != Indice.end(); ++it)
    {
        for(std::list<PalavraTabelada>::iterator itz = it->Palavras.begin(); itz != it->Palavras.end(); ++itz)
        {
            std::cout << " " << itz->Palavra << " " << itz->Score << " " << itz->Ocorrencias << '\n';

        }
        getchar();
    }
}

void CalculaScoreSIMPLES(std::string Comentario, std::vector<LetraIndice> Indice)
{
    int k = 0;
    float score = 0;
    std::string buf;
    std::stringstream ss(Comentario);
    std::vector<std::string> tokens;
    while(ss >> buf)
    {
        tokens.push_back(buf);
        std::transform(tokens[k].begin(), tokens[k].end(), tokens[k].begin(), ::tolower);

        for(std::vector<LetraIndice>::iterator it = Indice.begin(); it != Indice.end(); ++it)
        {
            if(it->letra == tokens[k][0])
            {
                for(std::list<PalavraTabelada>::iterator it2 = it->Palavras.begin(); it2 != it->Palavras.end(); ++it2)
                {
                    if(it2->Palavra == tokens[k])
                    {
                        score = score + it2->Score;
                        break;

                    }
                }
            }
        }
        k++;
    }

    score = score/k;

     if(score < 1)
        std::cout << " \nComentario com emocao Ruim" << "  " << score;
    if(score >= 1 && score < 2)
        std::cout << " \nComentario com emocao Um Pouco Ruim" << "  " << score;
    if(score >= 2 && score < 3)
        std::cout << " \nComentario com emocao Neutra" << "  " << score;
    if(score >= 3 && score < 3.5)
        std::cout << " \nComentario com emocao Um Pouco Positiva" << "  " << score;
    if(score >= 3.5)
        std::cout << "\nComentario com emocao Positiva" << "  " << score;
}

void CalculaScore(std::string Comentario, std::vector<LetraIndice> Indice)
{
    int k = 0;
    float score = 0;
    int z = 0;
    std::string buf;
    std::stringstream ss(Comentario);
    std::vector<std::string> tokens;
    while(ss >> buf)
    {
        tokens.push_back(buf);
        std::transform(tokens[k].begin(), tokens[k].end(), tokens[k].begin(), ::tolower);



        for(std::vector<LetraIndice>::iterator it = Indice.begin(); it != Indice.end(); ++it)
        {
            if(it->letra == tokens[k][0])
            {
                for(std::list<PalavraTabelada>::iterator it2 = it->Palavras.begin(); it2 != it->Palavras.end(); ++it2)
                {
                    if(it2->Palavra == tokens[k])
                    {
                        if(it2->Ocorrencias >= 450)
                            continue;

                        else
                        {

                            score = score + it2->Score;
                            z++;
                            break;
                        }

                    }
                }
            }
        }









        k++;
    }

    score = score/z;

    if(score < 1)
        std::cout << " \nComentario com emocao Ruim" << "  " << score;
    if(score >= 1 && score < 2)
        std::cout << " \nComentario com emocao Um Pouco Ruim" << "  " << score;
    if(score >= 2 && score < 3)
        std::cout << " \nComentario com emocao Neutra" << "  " << score;
    if(score >= 3 && score < 3.5)
        std::cout << " \nComentario com emocao Um Pouco Positiva" << "  " << score;
    if(score >= 3.5)
        std::cout << "\nComentario com emocao Positiva" << "  " << score;

}

void BuscaComentario (std::vector<std::string> Comentario, std::string word, int polaridade)
{
    for(unsigned int p = 0; p != Comentario.size(); p++)
    {
        int   k = 0;
        int l = polaridade;

        std::string buf;
        std::stringstream ss(Comentario[p]);
        std::vector<std::string> tokens;
        while(ss >> buf)
        {
            if(buf[0] == ',' || buf[0] == '.' || buf[0] == '\'')
                continue;
            tokens.push_back(buf);
            std::transform(tokens[k].begin(), tokens[k].end(), tokens[k].begin(), ::tolower);


            if(tokens[k] == word && l == 1)
            {
                if(Comentario[p][0] == '3' || Comentario[p][0] == '4')
                {
                    std::cout << "\n\tPolaridade Positiva" << '\n' << "Sentimento #" << Comentario[p][0] << " Palavra #" << k << " " << "Comentario #" << p << ": " << '\n' << Comentario[p];
                    k++;
                    continue;
                }
            }

            if(tokens[k] == word && l == 2)
            {
                if(Comentario[p][0] == '2' || Comentario[p][0] == '1' || Comentario[p][0] == '0')
                {
                    std::cout << "\n\tPolaridade Negativa" << '\n' << "Sentimento #" << Comentario[p][0] << " Palavra #" << k << " " << "Comentario #" << p << ": " << '\n' << Comentario[p];
                    k++;
                    continue;
                }
            }


            if(tokens[k] == word && l == 0)
            {
                std::cout << '\n' << "Sentimento #" << Comentario[p][0] << " Palavra #" << k << " " << "Comentario #" << p << ": " << '\n' << Comentario[p];
                k++;
            }
            else
            {
                k++;
                continue;
            }
        }
    }
}

bool compareByLength(const PalavraTabelada &a, const PalavraTabelada &b)
    {
        return b.Ocorrencias < a.Ocorrencias;
    }

void kPalavras (std::vector<LetraIndice> Indice, int j)
{
    std::vector<PalavraTabelada> Ranking;
    PalavraTabelada novo;
    int k = 0;
    int d;

    for(std::vector<LetraIndice>::iterator it = Indice.begin(); it != Indice.end(); ++it)
    {
        for(std::list<PalavraTabelada>::iterator it2 = it->Palavras.begin(); it2 != it->Palavras.end(); ++it2)
        {
            if(Ranking.empty() == true)
            {
                novo.Ocorrencias = it2->Ocorrencias;
                novo.Palavra = it2->Palavra;
                novo.Score = it2->Score;
                Ranking.push_back(novo);
                k++;
            }

            else if(k < j)
            {
                novo.Ocorrencias = it2->Ocorrencias;
                novo.Palavra = it2->Palavra;
                novo.Score = it2->Score;
                Ranking.push_back(novo);
                k++;
            }

            else if(k >= j)
            {
                for(d = 0; d < j; d++)
                {
                    if(Ranking[d].Ocorrencias < it2->Ocorrencias && Ranking[d].Palavra != it2->Palavra)
                    {
                        novo.Ocorrencias = it2->Ocorrencias;
                        novo.Palavra = it2->Palavra;
                        novo.Score = it2->Score;
                        Ranking[d] = novo;
                        k++;
                        break;
                    }
                }
            }
        }
    }

    std::sort(Ranking.begin(), Ranking.end(), compareByLength);

    for(int ad = 0; ad < j; ad++)
        std::cout << '\n' << Ranking[ad].Palavra << "---" << Ranking[ad].Ocorrencias;
}







