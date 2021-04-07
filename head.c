    #include <iostream>
#include "head.h"
#include <list>
#include <string>

int LeArquivo (std::string NomeArquivo, std::string Comentarios[])
{
    using namespace std;
    string line;
    int i = 0;

    ifstream myFile("movieReviews.txt", ios::out);

    if(myFile.is_open() == true)
    {
        while ( getline(myFile, line))
        {
            Comentarios[i] = line + '\n';
            i++;
        }
        myFile.close();
        return 1;
    }
    else
        perror("Erro ao abrir arquivo!");

    return 0;
}
