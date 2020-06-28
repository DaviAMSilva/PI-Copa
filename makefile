CC      = gcc
NOME    = Copa
TARGET  = $(BDIR)\$(NOME).exe

ARGS    = -I $(IDIR) -Wall

IDIR    = include
ODIR    = build
SDIR    = source
BDIR    = bin

SOURCES = $(wildcard $(SDIR)/*.c)
OBJECTS = $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SOURCES))


.PHONY: clean all


all: $(TARGET)


# Compila cada arquivo
$(ODIR)/%.o: $(SDIR)/%.c | $(ODIR)
	$(CC) -c -o $@ $< $(ARGS)


# Faz a linkagem de todo o programa
$(TARGET): $(OBJECTS) | $(BDIR)
	$(CC) $^ -o $@ $(ARGS)


# Roda o programa normalmente (a e b podem ser usados como os argumentos)
run: $(TARGET)
	$^ $(a) $(b)


# Roda o programa com os arquivos padrões
test: $(TARGET)
	"$^" "extra/Times.txt" "extra/Resultado.txt"


# Cria os diretórios bin e build
$(ODIR) $(BDIR):
	if not exist $@ mkdir $@


# Limpar arquivos
clean: | $(ODIR) $(BDIR)
	if exist $(ODIR)\*.o del $(ODIR)\*.o
	if exist $(TARGET) del $(TARGET)