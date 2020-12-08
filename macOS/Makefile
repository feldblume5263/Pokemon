NAME			= POKEMON

CC				= g++


FILES			= main \
				map \
				player \
				pokemon \
				skill \
				Battle \
				Database \
				mac_utils


SRC_DIR 		= ./src/

SRCS			= $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES)))

OBJ_DIR 		= ./objs/
OBJS 			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

CMAKE_CURRENT_BINARY_DIR = /usr/local/Cellar/cpprestsdk/2.10.16/lib/cmake/cpprestsdk
CMAKE_INSTALL_LIBDIR = ./
CPPREST_EXPORT_DIR = .

INC				= -I./include/
FLAGS			= -std=c++14 -stdlib=libc++ -lcpprest -lssl -lcrypto -lboost_system -lboost_thread-mt -lboost_chrono-mt -L/usr/local/opt/openssl/lib -I/usr/local/opt/openssl/include
RM				= rm -f

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp
				@mkdir -p $(OBJ_DIR)
				$(CC) $(FLAGS) $(INC) -c -o $@ $<

$(NAME):		$(OBJS)
				$(CC) $(FLAGS) $(OBJS) -o $(NAME)



all : $(NAME)

clean :
		$(RM) $(OBJS)
		$(RM) $(NAME)

 fclean : clean

 re : fclean all

 .PHONY: all clean fclean re .c.o
