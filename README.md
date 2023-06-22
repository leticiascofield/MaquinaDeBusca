# PDS2_Trabalho_Pratico

MAQUINA DE BUSCA
Este é um projeto de implementação de uma máquina de busca simples em C++. A máquina de busca utiliza um índice invertido para realizar pesquisas em uma coleção de documentos.

ESTRUTURA DE PASTAS
O projeto está organizado nas seguintes pastas:

    build: Pasta onde os arquivos objeto gerados durante a compilação serão inseridos.
        place_holder_para_o_git_não_deletar_a_pasta

    documentos: Pasta onde os documentos a serem indexados devem ser inseridos.
        place_holder_para_o_git_não_deletar_a_pasta

    include: Contém os arquivos de cabeçalho.
        MaquinaDeBusca.hpp: Arquivo de cabeçalho da classe MaquinaDeBusca.

    src: Contém os arquivos de código-fonte.
        main.cpp: Arquivo de código-fonte contendo a função main.
        MaquinaDeBusca.cpp: Arquivo de código-fonte contendo a implementação da classe MaquinaDeBusca.

    Makefile: Arquivo de compilação utilizado para compilar e executar o projeto.

As pastas build e documentos estão com um place holder, porque o Git deleta pastas vazias.

FUNCIONALIDADES
A classe MaquinaDeBusca possui as seguintes funcionalidades:

    MaquinaDeBusca(): Construtor padrão que cria uma máquina de busca vazia.
    MaquinaDeBusca(vector<string> documentos): Construtor que cria uma máquina de busca e indexa os documentos fornecidos.
    vector<string> obterCaminhoArquivos(const string& caminhoArquivo): Obtém os caminhos dos arquivos contidos na pasta documentos.
    string normalizarTexto(string texto): Normaliza um texto removendo caracteres especiais e convertendo letras maiúsculas para minúsculas.
    vector<string> separarPalavras(string textoNormalizado): Separa o texto em palavras.
    map<string, map<string, int>> criarIndiceInvertido(const vector<string>& documentos): Cria o índice invertido com base nos documentos fornecidos.
    vector<string> ordenarDocumentos(const vector<string>& palavrasPesquisadas): Ordena os documentos de acordo com a relevância das palavras pesquisadas.
    vector<string> pesquisar(string textoPesquisado): Realiza uma pesquisa com base no texto fornecido, retornando os documentos encontrados em ordem de relevância.

COMPILAÇÃO E EXECUÇÃO
Certifique-se de ter o compilador g++ instalado em seu sistema. Para compilar e executar o projeto, siga os passos abaixo:

    1. Coloque seus documentos na pasta "documentos" do projeto.
    2. Abra um terminal na pasta raiz do projeto.
    3. Execute o comando make para compilar o projeto.
    4. Após a compilação bem-sucedida, execute o comando make run para executar o programa.

LIMPEZA
Para limpar os arquivos gerados durante a compilação, execute o comando make clean.
