# 1. Program name
NAME = Abstract

# 2. Compiler and Compilation Flags
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

# 3. Object directory
OBJ_DIR = temp

# 4. Source and Object files
SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

# 5. Header Dependencies
HEADERS = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp

# 6. Default Target Rule
all: $(NAME)

# 7. Linking Rule
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# 8. Compilation Rule (creates temp dir if it doesn't exist)
$(OBJ_DIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 9. Clean Rules
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

# 10. Rebuild Rule
re: fclean all

# 11. Phony Targets
.PHONY: all clean fclean re