# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 17:37:36 by hojsong           #+#    #+#              #
#    Updated: 2023/01/05 12:35:08 by hojsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SRCS_S = srcs/server.c srcs/util.c
SRCS_C = srcs/client.c srcs/util.c

SERVER_BO = server_bonus
CLIENT_BO = client_bonus

SRCS_S_BO = bonus/server_bonus.c bonus/util_bonus.c\
			bonus/util2_bonus.c
SRCS_C_BO = bonus/client_bonus.c bonus/util_bonus.c\
			bonus/util2_bonus.c

OBJS_S_BO = $(SRCS_S:.c=.o)
OBJS_C_BO = $(SRCS_C:.c=.o)

OBJS_S_BO = $(SRCS_S:.c=.o)
OBJS_C_BO = $(SRCS_C:.c=.o)

HEAD  = head/
CC = cc
CFLAG = -Wall -Wextra -Werror 

ifdef BONUS
	SERVER_CUR = $(SERVER_BO)
	CLIENT_CUR = $(CLIENT_BO)
	SRCS_S_CUR = $(SRCS_S_BO)
	SRCS_C_CUR = $(SRCS_C_BO)
	OBJS_S_CUR = $(OBJS_S_BO)
	OBJS_C_CUR = $(OBJS_C_BO)	
else
	SERVER_CUR = $(SERVER)
	CLIENT_CUR = $(CLIENT)
	SRCS_S_CUR = $(SRCS_S)
	SRCS_C_CUR = $(SRCS_C)
	OBJS_S_CUR = $(OBJS_S)
	OBJS_C_CUR = $(OBJS_C)

endif
all : $(SERVER_CUR) $(CLIENT_CUR)

.c.o :
	$(CC) $(CFLAG) -I $(HEAD) -c $< -o $@

$(SERVER_CUR) : $(SRCS_S_CUR)
	$(CC) $(CFLAG) -o $(SERVER_CUR) $(SRCS_S_CUR)
$(CLIENT_CUR) : $(SRCS_C_CUR)
	$(CC) $(CFLAG) -o $(CLIENT_CUR) $(SRCS_C_CUR)

clean :
	rm -rf $(OBJS_S) $(OBJS_C) $(OBJS_S_BO) $(OBJS_C_BO)

fclean : clean
	rm -rf $(SERVER) $(CLIENT) $(SERVER_BO) $(CLIENT_BO)
	
re : fclean all

bonus :
	make BONUS=1 $(SERVER_BO) $(CLIENT_BO)

.PHONY : all re clean fclean bonus
