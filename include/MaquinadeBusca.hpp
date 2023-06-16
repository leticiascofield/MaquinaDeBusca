#ifndef MAQUINADEBUSCA_HPP
#define MAQUINADEBUSCA_HPP

#include <string>
#include <vector>
#include <map>

using std::string;  
using std::vector;
using std::map;

class MaquinaDeBusca{
    public:
    //Criar uma maquina de busca com os documentos
    MaquinaDeBusca(vector <string> documentos);

    //Normalizar um texto (sendo textoPesquisado ou documentos)
    string normalizarTexto(string texto);
       
    //Separar o texto pesquisado em um vetor com as palavras
    vector <string> separarPalavras(string textoNormalizado);

    //Criar o índice invertido
    map<string, map<string, int>> criarIndiceInvertido(const vector<string>& documentos);

    //Ordenar os documentos (documentos com todas as palavras e ordem de frequência)
    vector<string> ordenarDocumentos(const vector<string>& palavrasPesquisadas);

    //Engloba as outras funções
    vector <string> pesquisar(string textoPesquisado);

    private:
    vector <string> documentos;
    map<string, map<string, int>> indiceInvertido;

};

#endif