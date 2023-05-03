MAKEFLAGS			+=	--no-print-directory
CSI					:=	\033[
SEPARATOR			:=	;
FOREGROUND			:=	3
BACKGROUND			:=	4
BLINK				:=	5
UNBLINK				:=	25
FOREGROUND_BRIGHT	:=	9
BACKGROUND_BRIGHT	:=	10
FORE/BACKGROUND_SET	:=	8
						#red_number 0-255;green_number 0-255; blue_number 0-255;
RGB					:=	;2;#255;0;0
3-4BITS				:=	:5:#
BLACK				:=	0
RED					:=	1
GREEN				:=	2
YELLOW				:=	3
BLUE				:=	4
MAGENTA				:=	5
LIGHT_BLUE			:=	6
END					:=	m

# UTENSILS
SHELL				:=	/bin/sh
NAME				:=	graphics
DIR_DUP				=	mkdir -p $(@D)
CC					:=	gcc

SRC					=	main.c

OBJ		=	$(SRC:.c=.o)
RM		=	rm -rf
UNAME	:=	$(shell uname)
ifeq ($(UNAME), Linux)
	LFLAGS			:=	-Lmlx_linux -lmlx_Linux -L/usr/lib -lbsd -lXext -lX11 -lm -lz
	INFLAGS			:=	-Imlx_linux -I/usr/include
else
	LFLAGS			:=	-lmlx -framework OpenGL -framework Appkit -lm
endif
END-RULE				=	@echo "$(CSI)$(BLINK)$(END)🎉🎊$(CSI)$(UNBLINK)$(END)\
	$(CSI)$(FOREGROUND)$(GREEN)$(END) $@ $(CSI)$(END)$(CSI)$(BLINK)$(END)🎊\
	$(CSI)$(UNBLINK)$(END)"

CFLAGS			=	-Wall -Werror -Wextra $(INFLAGS) -g3
all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LFLAGS)
	$(END-RULE)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)

