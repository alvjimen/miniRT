# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 17:19:14 by alvjimen          #+#    #+#              #
#    Updated: 2023/06/22 18:44:01 by alvjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS				:=	--no-print-directory
## ANSI
CSI						:=	\033[
FOREGROUND				:=	3
BACKGROUND				:=	4
BLINK					:=	5
UNBLINK					:=	25
FOREGROUND_BRIGHT		:=	9
BACKGROUND_BRIGHT		:=	10
FORE/BACKGROUND_SET		:=	8
						#red_number 0-255;green_number 0-255; blue_number 0-255;
RGB						:=	;2;#255;0;0
3-4BITS					:=	:5:#nm
BLACK					:=	0
RED						:=	1
GREEN					:=	2
YELLOW					:=	3
BLUE					:=	4
MAGENTA					:=	5
LIGHT_BLUE				:=	6
END						:=	m
#END ANSI
SHELL					:=	/bin/sh
LIB-PREFIX				:=	lib
#RULES NAME BEGING
NAME					:=	$(LIB-PREFIX)ft.a
CMN-NAME				:=	$(LIB-PREFIX)cmn.a
STR-NAME				:=	$(LIB-PREFIX)str.a
MEM-NAME				:=	$(LIB-PREFIX)mem.a
NUM-NAME				:=	$(LIB-PREFIX)num.a
OUT-NAME				:=	$(LIB-PREFIX)out.a
LST-NAME				:=	$(LIB-PREFIX)lst.a
DCT-NAME				:=	$(LIB-PREFIX)dct.a
ERR-NAME				:=	$(LIB-PREFIX)err.a
GNL-NAME				:=	$(LIB-PREFIX)gnl.a
PRT-NAME				:=	$(LIB-PREFIX)prt.a
DBG-NAME				:=	$(LIB-PREFIX)dbg.a
LKS-NAME				:=	$(LIB-PREFIX)lks.a
SAR-NAME				:=	$(LIB-PREFIX)sar.a
# ALL RULES NAME FOR 
NAMES					:=	$(NAME) $(CMN-NAME) $(STR-NAME) $(MEM-NAME) $(NUM-NAME) $(OUT-NAME) $(LST-NAME)\
							$(DCT-NAME) $(ERR-NAME) $(GNL-NAME) $(PRT-NAME) $(DBG-NAME) $(LKS-NAME)
SRCS-DIR				:=	./src/
CMN-DIR					:=	cmn/
STR-DIR					:=	str/
MEM-DIR					:=	mem/
NUM-DIR					:=	num/
OUT-DIR					:=	out/
LST-DIR					:=	lst/
DCT-DIR					:=	dct/
ERR-DIR					:=	err/
GNL-DIR					:=	gnl/
PRT-DIR					:=	prt/
DBG-DIR					:=	dbg/
LKS-DIR					:=	lks/
SAR-DIR					:=	sar/

INC-DIR					:=	./include/
BUILD-DIR				:=	./.build/

CMN-SRC					:=	ft_calloc\
							ft_swap\
							ft_free\

CMN-SRC					:=	$(CMN-SRC:%=$(CMN-DIR)%)

STR-SRC					:=	ft_strlen\
							ft_isalpha\
							ft_isdigit\
							ft_isalnum\
							ft_isascii\
							ft_isprint\
							ft_is_plus_or_minus\
							ft_is_space\
							ft_strlcpy\
							ft_strlcat\
							ft_tolower\
							ft_toupper\
							ft_strchr\
							ft_strrchr\
							ft_strncmp\
							ft_strnstr\
							ft_strdup\
							ft_substr\
							ft_strjoin\
							ft_strtrim\
							ft_split\
							ft_strmapi\
							ft_striteri\
							ft_is_str_uniq\
							ft_is_str_uniq_exclude_rule\

STR-SRC					:=	$(STR-SRC:%=$(STR-DIR)%)

MEM-SRC					:=	ft_memset\
							ft_bzero\
							ft_memcpy\
							ft_memmove\
							ft_memchr\
							ft_memcmp\

MEM-SRC					:=	$(MEM-SRC:%=$(MEM-DIR)%)

OUT-SRC					:=	ft_putchar_fd\
							ft_putstr_fd\
							ft_putendl_fd\
							ft_putnbr_fd\
							ft_putnbr_base_unsigned_fd\
							ft_putnbr_base_fd\
							ft_put_pointer_fd\

OUT-SRC					:=	$(OUT-SRC:%=$(OUT-DIR)%)

LST-SRC					:=	ft_lstnew_bonus\
							ft_lstadd_front_bonus\
							ft_lstsize_bonus\
							ft_lstlast_bonus\
							ft_lstadd_back_bonus\
							ft_lstdelone_bonus\
							ft_lstclear_bonus\
							ft_lstiter_bonus\
							ft_lstmap_bonus\
							ft_lstnodeiteri\
							ft_lst_get_last_content\
							ft_search_list\
							ft_split_list\

LST-SRC					:=	$(LST-SRC:%=$(LST-DIR)%)

DCT-SRC					:=	ft_dict_new\
							ft_dict_search\
							ft_free_t_dict\

DCT-SRC					:=	$(DCT-SRC:%=$(DCT-DIR)%)
# Needed funs ft_calloc ft_memcmp
NUM-SRC					:=	ft_atoi\
							ft_atof\
							ft_itoa\
							ft_utoa\
							ft_putnbr_base\
							ft_putnbr_base_unsigned\
							ft_ptoa\
							ft_btoa\

NUM-SRC					:=	$(NUM-SRC:%=$(NUM-DIR)%)

GNL-SRC					:=	get_next_line_bonus\
							get_next_line_utils_bonus\

GNL-SRC					:=	$(GNL-SRC:%=$(GNL-DIR)%)

PRT-SRC				:=	ft_accuracy_bonus\
						ft_add_to_str_flags_bonus\
						ft_atoi_pf\
						ft_conversion_len_bonus\
						ft_conversions_bonus\
						ft_fill_flags_bonus\
						ft_fill_flags_zero_bonus\
						ft_fix_flags_bonus\
						ft_fix_flags_digit_bonus\
						ft_fix_flags_hex_bonus\
						ft_fix_flags_pointer_bonus\
						ft_fix_flags_unsigned_bonus\
						ft_flags_is_conversion_bonus\
						ft_flags_is_digit_bonus\
						ft_flags_is_str_bonus\
						ft_free_struct_bonus\
						ft_handle_flags_bonus\
						ft_is_flag_bonus\
						ft_pf_len\
						ft_printf_bonus\
						ft_putchar_pf_bonus\
						ft_putdigit_bonus\
						ft_puthex_pf_bonus\
						ft_putpointer_pf_bonus\
						ft_putstr_pf_bonus\
						ft_putuint_pf_bonus\
						ft_strlen_null_bonus\
						ft_width_bonus\
						putnbr_base_bonus\
						putnbr_base_unsigned_bonus\
						ft_memjoin_free_pf_bonus\

PRT-SRC					:=	$(PRT-SRC:%=$(PRT-DIR)%)
ERR-SRC					:=	ft_errors\
							ft_errors_2\

ERR-SRC					:=	$(ERR-SRC:%=$(ERR-DIR)%)

DBG-SRC				=	ft_title\
						ft_fill_cell\
						ft_headers\
						ft_draw_border\
						ft_draw_all_fields\
						ft_content\
						ft_max\
						ft_draw_all_contents\
						ft_data\
						ft_foot\

DBG-SRC					:=	$(DBG-SRC:%=$(DBG-DIR)%)

LKS-SRC					:=	mem
LKS-SRC					:=	$(LKS-SRC:%=$(LKS-DIR)%)

SAR-SRC					:=	ft_sarradd\
							ft_sarrcmp\
							ft_sarrfree\
							ft_sarrcpy\
							ft_sarrprint\
							ft_sarrrep\
							ft_sarrrmi\
							ft_sarrsize\
							ft_sarrsort\

SAR-SRC					:=	$(SAR-SRC:%=$(SAR-DIR)%)

SRC						+=	$(CMN-SRC) $(STR-SRC) $(MEM-SRC) $(NUM-SRC) $(OUT-SRC) $(LST-SRC) $(DCT-SRC)\
							$(ERR-SRC) $(GNL-SRC) $(PRT-SRC) $(DBG-SRC) $(LKS-SRC) $(SAR-SRC)

BUILD					:=	$(addsuffix .o, $(addprefix $(BUILD-DIR), $(SRC)))
CMN-BUILD				:=	$(addsuffix .o, $(addprefix $(BUILD-DIR), $(CMN-SRC)))
STR-BUILD				:=	$(addsuffix .o, $(addprefix $(BUILD-DIR), $(STR-SRC)))
MEM-BUILD				:=	$(addsuffix .o, $(addprefix $(BUILD-DIR), $(MEM-SRC)))
NUM-BUILD				:=	$(addsuffix .o, $(addprefix $(BUILD-DIR), $(NUM-SRC)))
OUT-BUILD				:=	$(addsuffix .o, $(addprefix $(BUILD-DIR), $(OUT-SRC)))
LST-BUILD				:=	$(addsuffix .o, $(addprefix $(BUILD-DIR), $(LST-SRC)))
DCT-BUILD				:=	$(addsuffix .o, $(addprefix $(BUILD-DIR), $(DCT-SRC)))
ERR-BUILD				:=	$(addsuffix .o, $(addprefix $(BUILD-DIR), $(ERR-SRC)))
GNL-BUILD				:=	$(addsuffix .o, $(addprefix $(BUILD-DIR), $(GNL-SRC)))
PRT-BUILD				:=	$(addsuffix .o, $(addprefix $(BUILD-DIR), $(PRT-SRC)))
DBG-BUILD				:=	$(addsuffix .o, $(addprefix $(BUILD-DIR), $(DBG-SRC)))
LKS-BUILD				:=	$(addsuffix .o, $(addprefix $(BUILD-DIR), $(LKS-SRC)))
SAR-BUILD				:=	$(addsuffix .o, $(addprefix $(BUILD-DIR), $(SAR-SRC)))

# Filling depencies
STR-BUILD				+=	$(CMN-BUILD)
DBG-BUILD				+=	$(STR-BUILD) $(OUT-BUILD)
PRT-BUILD				+=	$(CMN-BUILD) $(MEM-BUILD) $(STR-BUILD) $(NUM-BUILD)
GNL-BUILD				+=	$(CMN-BUILD) $(MEM-BUILD) $(STR-BUILD)
DCT-BUILD				+=	$(CMN-BUILD) $(MEM-BUILD)
NUM-BUILD				+=	$(STR-BUILD)
OUT-BUILD				+=	$(STR-BUILD)

# For forward make take on consideration de headers file
DEPS					:=	$(BUILD:.o=.d)
# FLAGS
AR						:=	ar
ARFLAGS					:=	-rcs
RM						:=	rm -rf
CC						:=	gcc
CFLAGS					:=	-Wall -Werror -Wextra #--std=c89 -pedantic -g3 #-fsanitize=undefined -fsanitize=address #-O2
PPFLAGS					:=	-MMD -MP $(INCLUDE)
INCLUDE					:=	-I $(INC-DIR)
# For create direcotory and print
DIR_DUP					=	mkdir -p $(@D)
END-RULE				=	@echo "$(CSI)$(BLINK)$(END)🎉🎊$(CSI)$(UNBLINK)$(END)$(CSI)$(FOREGROUND)$(GREEN)$(END) $@ $(CSI)$(END)$(CSI)$(BLINK)$(END)🎊$(CSI)$(UNBLINK)$(END)"
# RULES
all:
	@$(MAKE) $(NAME)

$(CMN-NAME):$(CMN-BUILD)
	@$(AR) $(ARFLAGS) $@ $^
	@$(END-RULE)

cmn:
	@$(MAKE) $(CMN-NAME)

$(STR-NAME):$(STR-BUILD)
	@$(AR) $(ARFLAGS) $@ $^
	@$(END-RULE)

str:
	@$(MAKE) $(STR-NAME)

$(MEM-NAME):$(MEM-BUILD)
	@$(AR) $(ARFLAGS) $@ $^
	@$(END-RULE)

mem:
	@$(MAKE) $(MEM-NAME)

$(NUM-NAME):$(NUM-BUILD)
	@$(AR) $(ARFLAGS) $@ $^
	@$(END-RULE)

num:
	@$(MAKE) $(NUM-NAME)

$(OUT-NAME):$(OUT-BUILD)
	@$(AR) $(ARFLAGS) $@ $^
	@$(END-RULE)

out:
	@$(MAKE) $(OUT-NAME)

$(LST-NAME):$(LST-BUILD)
	@$(AR) $(ARFLAGS) $@ $^
	@$(END-RULE)

lst:
	@$(MAKE) $(LST-NAME)

$(DCT-NAME):$(DCT-BUILD)
	@$(AR) $(ARFLAGS) $@ $^
	@$(END-RULE)

dct:
	@$(MAKE) $(DCT-NAME)

$(ERR-NAME):$(ERR-BUILD)
	@$(AR) $(ARFLAGS) $@ $^
	@$(END-RULE)

err:
	@$(MAKE) $(ERR-NAME)

$(GNL-NAME):$(GNL-BUILD)
	@$(AR) $(ARFLAGS) $@ $^
	@$(END-RULE)

gnl:
	@$(MAKE) $(GNL-NAME)

$(PRT-NAME):$(PRT-BUILD)
	@$(AR) $(ARFLAGS) $@ $^
	@$(END-RULE)

prt:
	@$(MAKE) $(PRT-NAME)

$(DBG-NAME):$(DBG-BUILD)
	@$(AR) $(ARFLAGS) $@ $^
	@$(END-RULE)

dbg:
	@$(MAKE) $(DBG-NAME)

$(LKS-NAME):$(LKS-BUILD)
	@$(AR) $(ARFLAGS) $@ $^
	@$(END-RULE)

lks:
	@$(MAKE) $(LKS-NAME)

$(SAR-NAME):$(SAR-BUILD)
	@$(AR) $(ARFLAGS) $@ $^
	@$(END-RULE)

sar:
	@$(MAKE) $(SAR-NAME)

$(NAME):	$(BUILD)
	@$(AR) $(ARFLAGS) $@ $(BUILD)
	@$(END-RULE)

$(BUILD-DIR)%.o:	$(SRCS-DIR)%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

-include $(DEPS)

clean:
	@$(RM) $(BUILD-DIR)

fclean:
	@$(MAKE) clean
	@$(RM) $(NAMES)

re:
	@$(MAKE) fclean
	@$(MAKE) all

info-%:
	@$(MAKE) --dry-run --always-make $* | grep -v "info"

print-%:
	@$(info '$*'='$($*)')

.PHONY: all clean fclean re info-% print-%
