#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

class MaquinaDeBusca{
    public:
//vetor da classe documentos
    //Criar uma maquina de busca com documentos
    MaquinaDeBusca(std::vector <std::string> documentos){
        this->documentos = documentos;

        for (int i=0; i < documentos.size(); i++){
            documentos[i] = normalizarTexto(documentos[i]);
        }
    }

    std::vector <std::string> pesquisar(std::string textoPesquisado){ //fazer iteração
        std::string pesquisaNormalizada = normalizarTexto(textoPesquisado);
        std::vector <std::string> palavrasPesquisadas = separarPalavras(pesquisaNormalizada);
        std::vector<std::map <std::string, int>> documentosComPalavra = procurarPalavra(palavrasPesquisadas, documentos);
        //Ainda falta resolver prioridade de documentos e retornar
        return 0;
    }

    //Para normalizar um texto (textoPesquisado e documentos)
    std::string normalizarTexto(std::string texto){ //verificar função normalize()
        std::string textoNormalizado;
        //código
        return textoNormalizado;
    }

    //Para separar o texto pesquisado
    std::vector <std::string> separarPalavras(std::string textoNormalizado){ //igual VPL04
        std::vector <std::string> palavrasPesquisadas;
        //código
        return palavrasPesquisadas;
    }


    //Para procurar as palavras pesquisadas nos documentos
    // Vector - palavra[i] que aparece nos documentos
    // Map - documento[j] e quantidade de vezes que tem palavra[i] (<0)
    std::vector<std::map <std::string, int>> procurarPalavra(std::vector<std::string> palavrasPesquisadas, std::vector <std::string> documentos){ //usar find()
        std::vector<std::map <std::string, int>> documentosComPalavra;
        //código
        return documentosComPalavra;
    }

    //Ainda tem que fazer funções do subsistema de recuperação e no main colocar os arquivos dos documentos no vector<string>

    private:

    std::vector <std::string> documentos;

};