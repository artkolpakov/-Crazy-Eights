#include <iostream>
#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "hand.h"

class Player {
  private:
    Hand hand;
    string name;
  public:

/******************************************************
** Function: Player() constructor
** Description: constructor for a Player class, initializes 
* hand with hand constructor and name with a given to it
* string as a parameter, works as a setter
** Parameters: string name, which sets the name of a player 
** Pre-Conditions: player class must exist, this constructor 
* has to be called in order to work
** Post-Conditions: hand and name of a particular 
* player are initialized
******************************************************/ 
    Player(string);

/******************************************************
** Function: Player() constructor
** Description: constructor for a Player class, initializes 
* a player class, does not have to be called in order to work
** Parameters: -
** Post-Conditions: hand and name of a particular 
* player are initialized
******************************************************/   
    Player();

/******************************************************
** Function: get_hand
** Description: we need this function in order to gain access 
* to the Hand class and its functions
** Parameters: -
** Pre-Conditions: hand and player classes must exist
** Post-Conditions: returns the reference to a hand class
******************************************************/
    Hand& get_hand();

/******************************************************
** Function: get_name
** Description: we need this function in order to gain access 
* to the private member of a Player class: string name, 
* which is a name of a player
** Parameters: -
** Pre-Conditions: player class must exist
** Post-Conditions: returns the string value of private member 
* variable of a class player 
******************************************************/    
    string get_name();

/******************************************************
** Function: set_name
** Description: this function allows us to assign values
* to the private class member variable: string name
** Parameters: name1 - string value that we assign
** Pre-Conditions: player class must exist
** Post-Conditions: now we can directly assign values to 
* private member variable string name of class player
******************************************************/
    void set_name(string);

/******************************************************
** Function: get_choice
** Description: this function gets a choice of a card 
* user wants to play, checks if this card can be played and
* if so, returns an integer corresponding to the card 
* a user decided to play 
** Parameters: cards array 
** Pre-Conditions: all included classes (card, deck, hand, 
* game) must exist 
** Post-Conditions: integer corresponding to the card the 
* user wanted to play is returned 
******************************************************/
    int get_choice(Card);

/******************************************************
** Function: get_choice
** Description: this function gets a choice of a card 
* AI user wants to play, by checking if there is a card
* in the AI players hand that can be played and if so,
* returns an integer corresponding to the first matched card 
* that can be played by AI
** Parameters: cards array 
** Pre-Conditions: all included classes (card, deck, hand, 
* game) must exist 
** Post-Conditions: integer corresponding to the card the 
* AI player plays
******************************************************/
    int get_AI_choice(Card);

/******************************************************
** Function: get_suit_if8_1
** Description: this function gets a choice of a suit 
* from a user if they played an "8" card, then this choice
* is returned as a decremented integer corresponding to 
* the chosen suit
** Parameters: -
** Pre-Conditions: function must be called
** Post-Conditions: integer corresponding to the the chosen
* suit is returned 
******************************************************/  
    int get_suit_if8_1();

/******************************************************
** Function: get_suit_if8_2
** Description: this function gets a choice of a suit 
* from AI player if he played an "8" card, the choice 
* of a suit, is a randomly generated integer
** Parameters: -
** Pre-Conditions: function must be called
** Post-Conditions: integer corresponding to the the randomly 
* chosen suit is returned 
******************************************************/
    int get_suit_if8_2();

/******************************************************
** Function: add_card
** Description: this function draws one card 
* from the deck to the particular hand
** Parameters: cards array (deck)
** Pre-Conditions: Card and player classes must exist
** Post-Conditions: one card is added to the hand of a 
* player 
******************************************************/    
    void add_card(Card&);

/******************************************************
** Function: add_card
** Description: this function checks all cards in 
* the hand of a user, when it finds a valid card, that 
* can be played (by comparing it to the rank and the suit 
* of a topcard) it prints its number so that the player 
* knows that this card can be played  
** Parameters: card topcard
** Pre-Conditions: Card and player classes must exist
** Post-Conditions: all 'hint cards'(cards that can be 
* played) are printed to the screen
******************************************************/
    void extra_credit(Card);
    };

#endif