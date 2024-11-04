run:
	g++ \
		-fdiagnostics-color=always \
		-g \
		-Wall \
		-Weffc++ \
		-Wextra \
		-Wconversion \
		-Wsign-conversion \
		-pedantic-errors \
		-std=c++23 \
		-Werror \
		-Wshadow=global \
		./**.cpp ./blackjack/**.cpp \
		-o ./main

	clear && ./main

