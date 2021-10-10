#ifndef DECK_H
#define DECK_H

#include "card.h"
#include "hand.h"

#include <iostream>
#include <string>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Deck {
private:
   Card cards[52];
   int n_cards;
public:

/******************************************************
** Function: get_n_cards
** Description: we need this function in order to gain access 
* to the private member of a Card class: int n_cards, which 
* is a number of cards remaining in the deck.
** Parameters: -
** Pre-Conditions: deck class must exist
** Post-Conditions: returns the int value of private member 
* variables of a class
******************************************************/
  int get_n_cards();

/******************************************************
** Function: set_n_cards
** Description: this function allows us to assign values
* to the private class member variable: int n_cards, which 
* is a number of cards remaining in the deck.
** Parameters: n_cards1 - value that we assign
** Pre-Conditions: deck class must exist
** Post-Conditions: now we can directly assign values to private member variable n_cards of class Deck
******************************************************/  
  void set_n_cards(int);

/******************************************************
** Function: get_cards_array
** Description: we need this function in order to gain access 
* to the private member of a Card class: cards array 
** Parameters: -
** Pre-Conditions: deck class must exist
** Post-Conditions: returns an array of a class Deck
******************************************************/ 
  Card* get_cards_array();

/******************************************************
** Function: Deck() constructor
** Description: constructor for a Deck class, initializes 
* the whole deck with card values - rank and suit values, 
* sets a number of cards remaining in the deck to 0 
** Parameters: -
** Pre-Conditions: deck and card classes must exist
** Post-Conditions: deck is filled with cards, 
******************************************************/ 
  Deck();

/******************************************************
** Function: print_deck
** Description: this function prints the whole deck array, 
* which is filled with cards 
* suit
** Parameters: -
** Pre-Conditions: deck class must exist
** Post-Conditions: all components of deck are printed 
******************************************************/   
  void print_deck();

/******************************************************
** Function: shuffle_deck
** Description: shuffles a deck, mixes the cards in it
** Parameters: -
** Pre-Conditions: deck and card classes must exist
** Post-Conditions: deck array is now filled randomly
******************************************************/ 
  void shuffle_deck();

/******************************************************
** Function: Deck() destructor
** Description: does nothing
** Parameters: -
** Pre-Conditions: deck class must exist
** Post-Conditions: -
******************************************************/  
  ~Deck();

/******************************************************
** Function: deal_card
** Description: checks if deck still has cards left in it,
* if so, deals one card to the hand 
** Parameters: -
** Pre-Conditions: deck and hand classes must exist
** Post-Conditions: one card is dealt to the hand
******************************************************/   
  void deal_card(Hand&);
};

#endif