#include <iostream>
#ifndef HAND_H
#define HAND_H

#include "card.h"
#include <string>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Hand {
  private:
    Card* cards;
    int n_cards;  /* Number of cards in the hand. */
  public:

/******************************************************
** Function: get_n_cards
** Description: we need this function in order to gain access 
* to the private member of a Hand class: int n_cards, which 
* is a number of cards remaining in the hand.
** Parameters: -
** Pre-Conditions: hand class must exist
** Post-Conditions: returns the int value of private member 
* variable of a class hand 
******************************************************/
    int get_n_cards();

/******************************************************
** Function: get_cards
** Description: we need this function in order to gain access 
* to the private member of a Card class: cards array 
** Parameters: -
** Pre-Conditions: deck, hand and card classes must exist
** Post-Conditions: returns an array of a class Deck
******************************************************/ 
    Card* get_cards();

/******************************************************
** Function: Hand() constructor
** Description: constructor for a Card class, initializes 
* n_cards and cards array values with 0 and NULL when a Hand 
* class is created
** Parameters: -
** Pre-Conditions: deck, hand and card classes must exist
** Post-Conditions: sets n_cards and cards array to 0
******************************************************/ 
    Hand();

/******************************************************
** Function: set_n_cards
** Description: this function allows us to assign values
* to the private class member variable: int n_cards, which 
* is a number of cards remaining in the hand.
** Parameters: n_cards1 - value that we assign
** Pre-Conditions: hand class must exist
** Post-Conditions: now we can directly assign values to 
* private member variable n_cards of class Hand
******************************************************/
    void set_n_cards(int);

/******************************************************
** Function: get_n_cards
** Description: we need this function in order to gain access 
* to the private member of a Hand class: int n_cards, which 
* is a particular element of a cards array (1 card)
** Parameters: integer i from a loop in player class 
** Pre-Conditions: hand, card and deck classes must exist
** Post-Conditions: returns a single element of a cards array 
* (1 card)
*****************************************************/
    Card get_n_card(int i);

/******************************************************
** Function: hand copy constructor 
** Description: makes a 'deep' copy of an old hand when we 
* create a new class hand and instantly set it equal to 
* the old hand class
** Parameters: old hand 
** Pre-Conditions: hand, card and deck classes must exist
** Post-Conditions: a deep copy is made
*****************************************************/
    Hand(const Hand&);

/******************************************************
** Function: hand overloaded assignment operator
** Description: makes a 'deep' copy of an old hand when we 
* create a new class hand and at some point set it equal to 
* the old hand class
** Parameters: old hand
** Pre-Conditions: hand, card and deck classes must exist
** Post-Conditions: a deep copy is made
*****************************************************/
    Hand& operator= (const Hand&);

/******************************************************
** Function: hand destuctor
** Description: deallocates the dynamically allocated memory 
* when the program ends
** Parameters: -
** Pre-Conditions: hand class must exist
** Post-Conditions: the memory is freed, dynamically 
* allocated array cards is now deleted
*****************************************************/
    ~Hand();

/******************************************************
** Function: add_cards
** Description: dynamically allocates a new array of cards
* and adds a needed card to the hand
** Parameters: cards array of calss Card
** Pre-Conditions: hand, card and deck classes must exist
** Post-Conditions: the card is added to the hand
*****************************************************/
    void add_cards(Card);

/******************************************************
** Function: add_cards
** Description: dynamically allocates a new array of cards
* and removes a needed card from the hand
** Parameters: integer choice (which card to remove)
** Pre-Conditions: hand, card and deck classes must exist
** Post-Conditions: the card is removed from the hand, this 
* card is now also saved and returned as a next top card 
*****************************************************/
    Card remove_cards(int);

/******************************************************
** Function: print_hand
** Description: this function prints the cards that are 
* located in the hand of the player/AI
** Parameters: -
** Pre-Conditions: hand, card and deck classes must exist
** Post-Conditions: all cards of a hand are printed 
******************************************************/ 
    void print_hand();

/******************************************************
** Function: is_valid_rank
** Description: checks if there is a card in a hand 
* that can be played, by comparing it to the rank 
* of the topcard, which is passed to the function
** Parameters: string rank of a topcard 
** Pre-Conditions: hand, card and deck classes must exist
** Post-Conditions: returns true if there is at least 
* one card that can be played (8 can always be played)
******************************************************/ 
    bool is_valid_rank(string);

/******************************************************
** Function: check_suit
** Description: checks if such suit of a chosen card 
* of a hand can be played or not by comparing it to 
* the passed topcard
** Parameters: string suit of a topcard to play card and
* integer i corresponding to the desired to play 
* card number in the print menu 
** Pre-Conditions: hand, card and deck classes must exist
** Post-Conditions: returns true if a given suit 
* of a card of a hand can be played, false otherwise 
******************************************************/  
    bool check_suit(string, int);

/******************************************************
** Function: is_valid_suit
** Description: checks if there is a card in a hand 
* that can be played, by comparing it to the suit 
* of the topcard, which is passed to the function
** Parameters: string suit of a topcard 
** Pre-Conditions: hand, card and deck classes must exist
** Post-Conditions: returns true if there is at least 
* one card that can be played (8 can always be played)
******************************************************/ 
    bool is_valid_suit(string);

/******************************************************
** Function: check_rank
** Description: checks if such rank of a chosen card 
* of a hand can be played or not by comparing it to 
* the passed topcard
** Parameters: string rank of a topcard to play card and
* integer i corresponding to the desired to play 
* card number in the print menu 
** Pre-Conditions: hand, card and deck classes must exist
** Post-Conditions: returns true if a given rank 
* of a card of a hand can be played, false otherwise 
******************************************************/ 
    bool check_rank(string suit, int i);

/******************************************************
** Function: check_for8
** Description: checks if such rank of a card of a hand 
* is "8" or not
** Parameters: integer of a played rank
** Pre-Conditions: hand, card and deck classes must exist
** Post-Conditions: returns true if a given integer rank 
* of a card is an "8", false otherwise 
******************************************************/ 
    bool check_for8(int);

};

#endif
