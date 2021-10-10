/******************************************************
** Program: crazyeights.cpp
** Author: Artem Kolpakov
** Date: 04/26/2021
** Description: This is a program that allows user to play a
* game of Crazy Eights against AI. The program first creates
* a deck of 52 cards (the numbers 2 through 10, 11
* corresponding to "Jack", 12 corresponding to "Queen",
* 13 corresponding to "King", and 1 corresponding to "Ace"),
* which have 4 suit types, then randomly shuffles the cards
* and assigns 7 random cards to the player and the computer.
* The top card of the remaining deck is be placed face-up, 
* the remaining cards are placed face-down, and then the game 
* begins. The player to go first has to play a card of the
* same suit or the same number as the top card on the discard
* pile, if a player is unable to play a card of the same suit
* or number, he/she will draw from the top of the stock deck
* and add cards to their hand until a play is possible, or
* until the stock is exhausted. The next player must play
* either a card of the specified suit or an eight. 
* This behavior of the alternating moves of the players
* continues until one of the players has no cards left or
* until the pile of cards runs out and no one can play a
* card. If there is such a situation that the stockpile is
* over and each of the players still has cards in their hands
* and none of them can play, then the player with the least
* number of cards in his/her hands wins. After each move
* (round), my program displays new cards of the user,
* including those that were issued from the stockpile,
* computer player's cards always stay hidden.
** Input: choice from the player and the AI ​​which cards to play,
* choice of the suit from the player and the AI ​​if they played 
* with an eight: on the human player's turn, program prompts the user
* for a card to play. If they cannot play any card, program lets them
* know that they will have to draw a card. When they enter a card, 
* program either puts the card on top of the pile or have them draw 
* a card from the deck if they can't play. If the user chooses to play
* an 8, program prompts the user to declare a suit for the next player.
** Output: program prints the current status of the game (e.g. the cards
* held by AI and the human player, number of cards left in the deck, the 
* card of on the top of the pile) at the start of each turn (keeping the 
* computer player's cards hidden). Once the game is over, program announces
* the winner and ask the user if they want to play again.
******************************************************/

#include "card.h"
#include "deck.h"
#include "hand.h"
#include "game.h"

#include <iostream>
#include <string>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

/******************************************************
** Function: main
** Description: this function creates a Game class
** Parameters: -
** Pre-Conditions: all included classes (card, deck, hand, 
* game) must exist 
** Post-Conditions: when the Game class is created, its 
* constructor is automatically called which launches whole 
* program
******************************************************/

int main(){

Game game1;

return 0;
}
