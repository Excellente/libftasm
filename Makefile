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
ft_puts		= obj/ft_puts.o
ft_bzero	= obj/ft_bzero.o
ft_strcat	= obj/ft_strcat.o
ft_strlen	= obj/ft_strlen.o
ft_isalpha	= obj/ft_isalpha.o
ft_isdigit	= obj/ft_isdigit.o
ft_isalnum	= obj/ft_isalnum.o
ft_isascii	= obj/ft_isascii.o
ft_isprint	= obj/ft_isprint.o
ft_isupper	= obj/ft_isupper.o
ft_islower	= obj/ft_islower.o
ft_tolower	= obj/ft_tolower.o
ft_toupper	= obj/ft_toupper.o

DEP			= $(ft_isalpha) $(ft_isdigit) \
			  $(ft_isalnum) $(ft_isascii) \
			  $(ft_isprint) $(ft_isupper) \
			  $(ft_bzero) $(ft_puts) \
			  $(ft_toupper) $(ft_strlen) \
			  $(ft_islower) $(ft_tolower) \
			  $(ft_strcat)

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

$(ft_strcat): src/ft_strcat.s
	@echo "\033[92mstrcat\033[0m"
	@$(CC) -f $(FORMAT) src/ft_strcat.s -o ft_strcat.o
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

$(ft_isprint): src/ft_isprint.s
	@echo "\033[92misprint\033[0m"
	@$(CC) -f $(FORMAT) src/ft_isprint.s -o ft_isprint.o
	@mv -f *.o $(OBJDIR)

$(ft_isupper): src/ft_isupper.s
	@echo "\033[92misupper\033[0m"
	@$(CC) -f $(FORMAT) src/ft_isupper.s -o ft_isupper.o
	@mv -f *.o $(OBJDIR)

$(ft_islower): src/ft_islower.s
	@echo "\033[92mislower\033[0m"
	@$(CC) -f $(FORMAT) src/ft_islower.s -o ft_islower.o
	@mv -f *.o $(OBJDIR)

$(ft_toupper): src/ft_toupper.s
	@echo "\033[92mtoupper\033[0m"
	@$(CC) -f $(FORMAT) src/ft_toupper.s -o ft_toupper.o
	@mv -f *.o $(OBJDIR)

$(ft_tolower): src/ft_tolower.s
	@echo "\033[92mtolower\033[0m"
	@$(CC) -f $(FORMAT) src/ft_tolower.s -o ft_tolower.o
	@mv -f *.o $(OBJDIR)

$(LIB): $(DEP)
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
