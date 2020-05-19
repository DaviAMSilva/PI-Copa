CC       = gcc
NOME     = Copa

ARGS     = -I $(IDIR) -Wall

IDIR     = include
ODIR     = build
SDIR     = source
BDIR     = bin

_OBJ     = teams.o functions.o jogos.o main.o
OBJS     = $(patsubst %,$(ODIR)/%,$(_OBJ))


.PHONY: clean all


all: $(NOME)


# Compila cada arquivo
$(ODIR)/%.o: $(SDIR)/%.c | $(ODIR) $(BDIR)
	$(CC) -c -o $@ $< $(ARGS)


# Faz a linkagem de todo o programa
$(NOME): $(OBJS)
	$(CC) -o $(BDIR)/$@ $^ $(ARGS) $(ARGS)


# Roda o programa normalmente (a e b podem ser usados como os argumentos)
run: $(NOME)
	./$(BDIR)/$^ $(a) $(b)


# Roda o programa com os arquivos padrões
test: $(NOME)
	"./$(BDIR)/$^" "extra/Times.txt" "extra/Resultado.txt"


# Cria os diretórios bin e build
$(ODIR) $(BDIR):
ifeq ($(OS), Windows_NT)
	if not exist $@ mkdir $@
else
	mkdir -p $@
endif


# Limpar arquivos .o
clean: | $(ODIR) $(BDIR)
ifeq ($(OS), Windows_NT)
	del $(ODIR)\*.o
else
	rm -f $(ODIR)/*.o
endif