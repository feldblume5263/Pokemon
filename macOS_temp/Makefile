# cmake_minimum_required(VERSION 3.9)
# project(main)

# find_package(cpprestsdk REQUIRED)

# add_executable(main main.cpp)
# target_link_libraries(main PRIVATE cpprestsdk::cpprest)

NAME			= POKEMON.a

CC				= g++
AR				= ar
ARFLAGS			= rcs


FILES			= main \
				map \
				player \
				pokemon \
				skill \
				Battle \
				Database \


SRC_DIR 		= ./src/

SRCS			= $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES)))

OBJ_DIR 		= ./objs/
OBJS 			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

CMAKE_CURRENT_BINARY_DIR = /usr/local/Cellar/cpprestsdk/2.10.16/lib/cmake/cpprestsdk
CMAKE_INSTALL_LIBDIR = ./
CPPREST_EXPORT_DIR = .

INC				= -I./include/
FLAGS			= -std=c++14 -stdlib=libc++ -lcpprest -lssl -lcrypto -lboost_system -lboost_thread-mt -lboost_chrono-mt -L/usr/local/opt/openssl/lib -L/usr/local/Cellar/cpprestsdk/2.10.16/lib/ -I/usr/local/Cellar/cpprestsdk/2.10.16/include/cpprest/details/  -I/usr/local/opt/openssl/include
RM				= rm -f

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp
				@mkdir -p $(OBJ_DIR)
				$(CC) $(FLAGS) $(INC) -c -o $@ $<

$(NAME):		$(OBJS)
				$(AR) $(ARFLAGS) $@ $(OBJS)



all : $(NAME)

clean :
		$(RM) $(OBJS)
		$(RM) $(NAME)

 fclean : clean

 re : fclean all

 .PHONY: all clean fclean re .c.o
