#ifndef MAQUINADEBUSCA_HPP
#define MAQUINADEBUSCA_HPP

#include <string>
#include <vector>
#include <map>

class MaquinaDeBusca{
    public:
    //Criar uma maquina de busca com documentos
    MaquinaDeBusca(std::vector <std::string> documentos);

    //Para normalizar um texto (textoPesquisado e documentos)
    std::string normalizarTexto(std::string texto);
       
    //Para separar o texto pesquisado
    std::vector <std::string> separarPalavras(std::string textoNormalizado);

    //Para organizar o texto pesquisado
    std::vector <std::string> pesquisar(std::string textoPesquisado);

    //Função que faz o índice invertido
    std::map<std::string, std::map<std::string, int>> criarIndiceInvertido(const std::vector<std::string>& documentos);

    //A função que retorna a prioridade dos documentos
    std::vector<std::string> procurarPalavras(const std::vector<std::string>& palavrasPesquisadas, const std::map<std::string, std::map<std::string, int>>& indiceInvertido);

    private:
    std::vector <std::string> documentos;
    
};

#endif