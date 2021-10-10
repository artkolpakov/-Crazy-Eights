CC = g++ -std=c++11 -g
exe_file = crazy8
$(exe_file): card_functions.o deck_functions.o hand_functions.o player_functions.o game_functions.o driver.o
	$(CC) card_functions.o deck_functions.o hand_functions.o player_functions.o game_functions.o driver.o -o $(exe_file)
card_functions.o: card_functions.cpp
	$(CC) -c card_functions.cpp
deck_functions.o: deck_functions.cpp
	$(CC) -c deck_functions.cpp
hand_functions.o: hand_functions.cpp
	$(CC) -c hand_functions.cpp
player_functions.o: player_functions.cpp
	$(CC) -c player_functions.cpp
game_functions.o: game_functions.cpp
	$(CC) -c game_functions.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)
