EXE 	= test
CC		= nasm
LINKER	= ld
LIB		= -lSystem
SRCS 	= ./src/testasm.s
SRDIR	= ./src/
SRC		= $(addprefix $(SRCDIR), $(SRCS))
OBJ		= $(SRC:.s=.o)
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
	$(LINKER) $(ARCH) $(OBJ) $(LIB) -o $(EXE)

clean:
	rm -f $(OBJ) *.out

fclean: clean
	rm -f $(EXE)

re: fclean all
