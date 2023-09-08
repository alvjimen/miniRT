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

SRC					=	main.c\
						hooks.c\
						draw.c\
						angle.c\
						element.c\
						init_figures.c\
						sphere.c\
						vec3d.c\
						vec3d_math_vec3d.c\
						vec3d_math_double.c\
						ray.c\
						ppm.c\
						camera.c\
						hit.c\
						world.c\
						antialiasing.c\
						random_number.c\
						number.c\
						color.c\
						parse.c\
						ft_is_space.c\
						ft_isdigit.c\
						ft_atof.c\
						ft_run.c\
						parse_utils.c\
						plane.c\
						cylinder.c\
						cone.c\
						rotations.c\
						light.c\
						texture_coordinates.c\
						matrix.c\
						light_utils.c\
						light_fun_ptr.c\
						parse_utils_v2.c\
						init_figures_utils.c\
						light_fun_ptr_utils.c\
						cone_utils.c\
						cylinder_utils.c\
						texture_coordinates_figures.c\
						texture_coordinates_utils.c\
						parse_utils_v3.c\
						#diffuse_materials.c\
						perspective.c\
						normalize.c\
						projection.c\
						vector4d.c\

OBJ		=	$(SRC:.c=.o)
RM		=	rm -rf
UNAME	:=	$(shell uname)
LIB		:=	lib/libft.a

ifeq ($(UNAME), Linux)
	LFLAGS			:=	-Lmlx_linux -lmlx_Linux -L/usr/lib -lbsd -lXext -lX11 -lm -lz
	INFLAGS			:=	-Imlx_linux -I/usr/include -I./lib/include
else
	LFLAGS			:=	-lmlx -framework OpenGL -framework Appkit -lm
	INFLAGS			:=	-I./lib/include
endif
END-RULE				=	@echo "$(CSI)$(BLINK)$(END)🎉🎊$(CSI)$(UNBLINK)$(END)\
	$(CSI)$(FOREGROUND)$(GREEN)$(END) $@ $(CSI)$(END)$(CSI)$(BLINK)$(END)🎊\
	$(CSI)$(UNBLINK)$(END)"

CFLAGS			=	-Wall -Werror -Wextra $(INFLAGS) -g3 -fsanitize=address
all:	$(NAME)

$(NAME):	$(OBJ) $(LIB)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS) $(LIB)
	$(END-RULE)

$(LIB):
	$(MAKE) -C lib
clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)

