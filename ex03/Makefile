NAME		= bureaucrat
CXX			= clang++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic
SRCS_DIR	= ./
SRCS		= main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJS_DIR 	= objs/
OBJ			= $(SRCS:.cpp=.o)
OBJS		= $(addprefix $(OBJS_DIR), $(OBJ))
INCLUDES	= ./includes
RM			= rm -rf
CXXFLAGS	+= -I $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.cpp
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS_DIR) *_shrubbery

fclean : clean
	$(RM) $(NAME)

debug :
	$(CXX) $(CXXFLAGS) -fsanitize=address -o $(NAME) $(SRCS)

test : $(NAME)
	@./$(NAME)

re : fclean all

.PHONY: all clean fclean re debug test
