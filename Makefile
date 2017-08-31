EXE 	= test
CC		= nasm
LINKER	= ld
LIB		= -lSystem
SRCS 	= ./src/testasm.asm
SRDIR	= ./src/
SRC		= $(addprefix $(SRCDIR), $(SRCS))
OBJ		= $(SRC:.asm=.o)
FORMAT	= macho64
ARCH	= -macosx_version_min 10.8
OS		:= $(shell uname)

ifeq ($(OS), Darwin)
	FORMAT := macho64
else
	FORMAT := elf
	ARCH :=
endif

all: $(EXE) $(LINKER)

$(EXE):
	$(CC) -f $(FORMAT) $(SRC)

$(LINKER):
	$(LINKER) $(OBJ) $(ARCH) $(LIB) -o $(EXE)

clean:
	rm -f $(OBJ) *.out

fclean: clean
	rm -f $(EXE)

re: fclean all
