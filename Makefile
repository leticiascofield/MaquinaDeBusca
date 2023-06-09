# Nome do executável
TARGET = programa

# Compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -std=c++11 -Wall

# Diretório dos arquivos de origem
SRCDIR = src

# Lista de arquivos fonte
SOURCES = $(SRCDIR)/MaquinadeBusca.cpp \
          $(SRCDIR)/Main.cpp

# Lista de arquivos objeto
OBJECTS = $(SOURCES:.cpp=.o)

# Regra padrão de compilação
all: $(TARGET)

# Regra de ligação
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regra de compilação dos arquivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar arquivos objeto e executável
clean:
	rm -f $(OBJECTS) $(TARGET)
