CC		= nasm
EXE		= testasm
COMP	= gcc
LIB 	= libfts.a
INC		= include
LIBFLAG	= -lSystem
OBJDIR	= obj/
FORMAT	= macho64
ARCH	= -macosx_version_min 10.8
OS	:= $(shell uname)

######### object files ############
ft_puts = obj/ft_puts.o
ft_strlen = obj/ft_strlen.o

###################################
#         check for os            #
###################################
ifeq ($(OS), Darwin)
	FORMAT := macho64
else
	FORMAT := elf64
	ARCH :=
endif

all: $(ft_puts) $(ft_strlen) $(LIB) $(EXE)

$(EXE): main.c	
	$(COMP) $^ $(LIB) -I $(INC) -o $(EXE)

$(ft_puts): src/ft_puts.s
	$(CC) -f $(FORMAT) src/ft_puts.s -o ft_puts.o
	mv -f *.o $(OBJDIR)

$(ft_strlen): src/ft_strlen.s
	$(CC) -f $(FORMAT) src/ft_strlen.s -o ft_strlen.o
	mv -f *.o $(OBJDIR)

$(LIB):
	ar rc $(LIB) $(OBJDIR)*.o
	ranlib $(LIB)

clean:
	rm -f $(OBJDIR)*.o *.out *.o

fclean: clean
	rm -f $(LIB)

re: fclean all
