#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "deck.h"
#include "card.h"

#include <iostream>
#include <string>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Game {
  private:
    Deck cards;
    Player players[2];
    int counter = 15; 
    Card topcard;
    int turn = 1;    
  public:

/******************************************************
** Function: Game() constructor
** Description: constructor for a Game class, has all of the
* functions that are needed to play a game so that when a 
* game class in main is created, the whole program runs
** Parameters: -
** Pre-Conditions: player, game, deck, hand and card classes 
* must exist
** Post-Conditions: the game is being played until a winner is
* determined or there are no card in the deck left, when 
* the winner is determined program prints a winning message 
******************************************************/ 
  Game();

/******************************************************
** Function: get_hand
** Description: we need this function in order to a hand 
* class and its functions
** Parameters: -
** Pre-Conditions: hand class must exist
** Post-Conditions: returns all info about hand and gives
* us an access to all of the hand functions
******************************************************/ 
  Hand& get_hand();

/******************************************************
** Function: print_status
** Description: prints status of the game: the cards
* held by AI and the human player, number of cards left 
* in the deck, the card on the top of the pile) at the start of each turn (keeping the 
* computer player's cards hidden).
** Parameters: -
** Pre-Conditions: hand class must exist
** Post-Conditions: returns all info about hand and gives
* us an access to all of the hand functions
******************************************************/ 
  void print_status();

/******************************************************
** Function: get_current_card
** Description: gets current card in the deck (cards array)
** Parameters: -
** Pre-Conditions: player, game, deck, hand and card classes 
* must exist 
** Post-Conditions: returns current card 
******************************************************/   
  Card get_current_card();

/******************************************************
** Function: get_the_top_card
** Description: gets the topcard after 14 cards are dealt
** Parameters: -
** Pre-Conditions: player, game, deck, hand and card classes 
* must exist 
** Post-Conditions: returns initial topcard 
******************************************************/ 
  Card get_the_top_card();

/******************************************************
** Function: get_deck_cards
** Description: prints the number of cards left in deck by 
* subtracting from 52 the number of cards (it starts form 0)
** Parameters: -
** Pre-Conditions: player, game, deck, hand and card classes 
* must exist 
** Post-Conditions: prints the number of cards left in deck
******************************************************/ 
  void get_deck_cards();

/******************************************************
** Function: print_hand
** Description: prints all of the cards that are located 
* in the current hand of a user
** Parameters: -
** Pre-Conditions: player, game, deck, hand and card classes 
* must exist 
** Post-Conditions: prints the current hand of a user
******************************************************/ 
  void print_hand();

/******************************************************
** Function: deal_cards
** Description: deals 7 cards to the user, deals 7 cards to 
* the AI player
** Parameters: -
** Pre-Conditions: player, game, deck, hand and card classes 
* must exist 
** Post-Conditions: AI player and user hands are now filled 
* with 7 random cards which are taken from the deck
******************************************************/
  void deal_cards();

/******************************************************
** Function: get_winner
** Description: checks if user/AI hand has no cards left or
* if there is such situation when there are no card left in the 
* deck and both user and AI still have cards in their hands, 
* announces the winner according to the cases described above
** Parameters: -
** Pre-Conditions: player, game, deck, hand and card classes 
* must exist 
** Post-Conditions: If neither player has zero cards at the end 
* of the game, the player with the least amount of cards in 
* their hand wins. The first player to get rid of their cards 
* is a winner. Corresponding winning messages are printed
******************************************************/ 
  void get_winner();

/******************************************************
** Function: switch_turn
** Description: changes the turn 
** Parameters: integer turn 
** Pre-Conditions: game class must exist 
** Post-Conditions: if the turn was 1 it became 0 if it 
* was 0 it became 1, at the end int turn is returned 
******************************************************/  
  int switch_turn(int);

/******************************************************
** Function: one_round
** Description: if turn is equal to 1 it calls user_move 
* function and then switches the turn, if turn is equal 
* to 0 it calls AI_move function and then switches the turn
** Parameters: -
** Pre-Conditions: player, game, deck, hand and card classes 
* must exist 
** Post-Conditions: AI/user made their move 1 time, turn 
* is switched 
******************************************************/ 
  void one_round();

/******************************************************
** Function: user_move
** Description: user plays a card from their hand that is 
* the same suit or same rank as the top card on the pile, 
* which becomes the new top of the pile. If a player does 
* not have any cards of the required rank or suit, they
* draw from the top of the deck and add cards to their hand 
* until they draw a card that can be played on the pile, 
* or until the deck runs out of cards.
** Parameters: -
** Pre-Conditions: player, game, deck, hand and card classes 
* must exist 
** Post-Conditions: if function is called user makes 
* their move 1 time 
******************************************************/ 
  void user_move();

/******************************************************
** Function: AI_move
** Description: AI player plays a card from their hand that 
* is the same suit or same rank as the top card on the pile, 
* which becomes the new top of the pile. If a player does 
* not have any cards of the required rank or suit, they
* draw from the top of the deck and add cards to their hand 
* until they draw a card that can be played on the pile, 
* or until the deck runs out of cards.
** Parameters: -
** Pre-Conditions: player, game, deck, hand and card classes 
* must exist 
** Post-Conditions: if function is called AI player makes 
* their move 1 time 
******************************************************/   
  void AI_move();

/******************************************************
** Function: check_for_win
** Description: checks if user/AI hand has no cards left or
* if there is such situation when there are no cards left in
* the deck 
** Parameters: -
** Pre-Conditions: player, game, deck, hand and card classes 
* must exist 
** Post-Conditions: returns true if deck or one of the hands 
* is empty, false otherwise 
******************************************************/   
  bool check_for_win();

/******************************************************
** Function: check_for8
** Description: checks if user/AI decided to play a card with 
* a rank of 8 
** Parameters: integer of a played rank
** Pre-Conditions: hand, card and deck classes must exist
** Post-Conditions: it is now checked if any played decided 
* to play an 8 
******************************************************/   
  void check_for8(int);

/******************************************************
** Function: make_choice
** Description: If a user does not have any cards of the
* required rank or suit, they draw from the top of the deck
* and add cards to their hand until they draw a card that
* can be played on the pile, or until the deck runs out of
* cards. If user chooses to play an 8, they choose a suit 
* for next player to play
** Parameters: integer choice
** Pre-Conditions: player, game, deck, hand and card classes 
* must exist 
** Post-Conditions: user takes/removes one card from 
* their hand
******************************************************/   
  void make_choice(int);

/******************************************************
** Function: AI_make_choice
** Description: If a AI player does not have any cards of the
* required rank or suit, hw draws from the top of the deck
* and adds cards to his hand until he draws a card that
* can be played on the pile, or until the deck runs out of
* cards. If AI player chooses to play an 8, a choice of a suit 
* for next player to play is randomly generated
** Parameters: integer choice
** Pre-Conditions: player, game, deck, hand and card classes 
* must exist 
** Post-Conditions: AI player takes/removes one card from 
* their hand
******************************************************/ 
  void AI_make_choice(int);
  
};

#endif