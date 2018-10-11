NAME = ft_retro

CXX = @clang++

CFLAGS = -Wall -Wextra -Werror -lncurses

SRC = main.cpp \
	  KeyboardEvent.cpp \
	  AScrObj.cpp \
	  Bullet.cpp \
	  Weapon.cpp \
	  Character.cpp \
	  Enemy.cpp \
	  Game.cpp \
	  Spawner.cpp \
	  gameHelper.cpp \
	  LaserShark.cpp \
	  MegaWeapon.cpp \
	  Boss.cpp \

OBJS = $(SRC:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

.PHONY: clean fclean all re

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

all: $(NAME)

re: fclean all
