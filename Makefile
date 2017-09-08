CC		= nasm
EXE		= testasm
COMP	= gcc
LIB 	= libfts.a
INC		= include
LIBFLAG	= -lSystem
OBJDIR	= obj/
SRCDIR	= src/
FORMAT	= macho64
ARCH	= -macosx_version_min 10.8
OS		:= $(shell uname)

######### object files ############
ft_puts = obj/ft_puts.o
ft_bzero = obj/ft_bzero.o
ft_strlen = obj/ft_strlen.o
ft_isalpha = obj/ft_isalpha.o
ft_isdigit = obj/ft_isdigit.o
ft_isalnum = obj/ft_isalnum.o
ft_isascii = obj/ft_isascii.o

###################################
#         check for os            #
###################################
ifeq ($(OS), Darwin)
	FORMAT := macho64
else
	FORMAT := elf64
	ARCH :=
endif

all: $(EXE)

$(EXE): $(LIB) main.c	
	@$(COMP) $^ $(LIB) -I $(INC) -o $(EXE)
	@echo "\033[92mMake Done!\033[0m"

$(ft_puts): src/ft_puts.s
	@echo "\033[92mputs\033[0m"
	@$(CC) -f $(FORMAT) -I$(INC) src/ft_puts.s -o ft_puts.o
	@mv -f *.o $(OBJDIR)

$(ft_bzero): src/ft_bzero.s
	@echo "\033[92mbzero\033[0m"
	@$(CC) -f $(FORMAT) -I$(INC) src/ft_bzero.s -o ft_bzero.o
	@mv -f *.o $(OBJDIR)

$(ft_strlen): src/ft_strlen.s
	@echo "\033[92mstrlen\033[0m"
	@$(CC) -f $(FORMAT) src/ft_strlen.s -o ft_strlen.o
	@mv -f *.o $(OBJDIR)

$(ft_isalpha): src/ft_isalpha.s
	@echo "\033[92misalpha\033[0m"
	@$(CC) -f $(FORMAT) src/ft_isalpha.s -o ft_isalpha.o
	@mv -f *.o $(OBJDIR)

$(ft_isdigit): src/ft_isdigit.s
	@echo "\033[92misdigit\033[0m"
	@$(CC) -f $(FORMAT) src/ft_isdigit.s -o ft_isdigit.o
	@mv -f *.o $(OBJDIR)

$(ft_isalnum): src/ft_isalnum.s
	@echo "\033[92misalnum\033[0m"
	@$(CC) -f $(FORMAT) src/ft_isalnum.s -o ft_isalnum.o
	@mv -f *.o $(OBJDIR)

$(ft_isascii): src/ft_isascii.s
	@echo "\033[92misascii\033[0m"
	@$(CC) -f $(FORMAT) src/ft_isascii.s -o ft_isascii.o
	@mv -f *.o $(OBJDIR)

$(LIB): $(ft_puts) $(ft_bzero) $(ft_strlen) $(ft_isalpha) $(ft_isdigit) $(ft_isalnum) $(ft_isascii)
	@echo "\033[92mBuilding Library\033[0m"
	@ar rc $(LIB) $(OBJDIR)*.o
	@ranlib $(LIB)
	@echo "\033[92mLibrary Built\033[0m"

push:
	@make fclean
	@echo "\033[92mCommitting to git\033[0m"
	@git add .; git commit -m "automated push"; git push
	
	@echo "\033[92mCopying to vog repo\033[0m"
	@cp -rf src obj include Makefile main.c ../emsimang
	@cd ../emsimang
	
	@echo "\033[92mPushing to vog repo\033[0m"
	@git add .; git commit -m "automated push"; git push origin master
	@cd ../libftasm
	
	@echo "\033[92mDONE!\033[0m"

clean:
	@echo "\033[92mCleaning\033[0m"
	@rm -f $(SRCDIR)*.o $(OBJDIR)*.o *.out *.o

fclean: clean
	@rm -f $(LIB) $(EXE)
	@echo "\033[92mClean\033[0m"

re: fclean all

.PHONY: clean fclean push
