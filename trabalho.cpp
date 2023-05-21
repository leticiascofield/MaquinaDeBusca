#include <iostream>
#include <string>
#include <map>
#include <vector>

class MaquinaDeBusca{
    public:

    //Criar uma maquina de busca com documentos
    MaquinaDeBusca(std::vector <std::string> documentos){
        this->documentos = documentos;

        for (int i=0; i < documentos.size(); i++){
            documentos[i] = normalizarTexto(documentos[i]);
        }
    }

    std::vector <std::string> pesquisar(std::string textoPesquisado){
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
    // fazer igual VPL04
    std::vector <std::string> separarPalavras(std::string textoNormalizado){
        std::vector <std::string> palavrasPesquisadas;
        //código
        return palavrasPesquisadas;
    }


    //Para procurar as palavras pesquisadas nos documentos
    // Vector - palavra[i] que aparece nos documentos
    // Map - documento[j] e quantidade de vezes que tem palavra[i] (quantidade>0)
    //usar find()
    std::vector<std::map <std::string, int>> procurarPalavra(std::vector<std::string> palavrasPesquisadas, std::vector <std::string> documentos){
        std::vector<std::map <std::string, int>> documentosComPalavra; 
        //código
        for (int i = 0; i < palavrasPesquisas.size(); i++){
            for (int j = 0; j < documentos.size(); j++)
                if (documentos.find(palavrasPesquisas)){

                }
        }

        return documentosComPalavra;
    }

    //ver se tem todas as palavras em um docs -> fazer uma função (de map) para contar quantas vezes um string 
    //(ex: d1.txt) aparece no vetor, se a quantidade for igual o tamanho do vetor, esse docs tem todas as palavras

    //somar os ints desse docs (que é um map), o que for maior aparece primeiro
    //if dois sejam iguais, aparecer o com nome menor


    //Ainda tem que fazer funções do subsistema de recuperação e no main colocar os arquivos dos documentos no vector<string>
    private:

    std::vector <std::string> documentos;

};