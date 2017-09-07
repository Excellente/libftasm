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
	@$(COMP) $^ $(LIB) -I $(INC) -o $(EXE)
	@echo "\033[92mMake Done!\033[0m"

$(ft_puts): src/ft_puts.s
	@echo "\033[92mputs object\033[0m"
	@$(CC) -f $(FORMAT) -I$(INC) src/ft_puts.s -o ft_puts.o
	@mv -f *.o $(OBJDIR)

$(ft_strlen): src/ft_strlen.s
	@echo "\033[92mstrlen object\033[0m"
	@$(CC) -f $(FORMAT) src/ft_strlen.s -o ft_strlen.o
	@mv -f *.o $(OBJDIR)

$(LIB):
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
