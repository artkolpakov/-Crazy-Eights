#ifndef CARD_H
#define CARD_H 

#include <iostream>
#include <string>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Card{
  private:
  int suit;
  int rank;

  public:
/******************************************************
** Function: get_rank
** Description: we need this function in order to gain access 
* to the private member of a Card class: int rank
** Parameters: -
** Pre-Conditions: card class must exist
** Post-Conditions: returns the int value of private member 
* variables of a class
******************************************************/
  int get_rank();

/******************************************************
** Function: get_suit
** Description: we need this function in order to gain access 
* to the private member of a Card class: int suit
** Parameters: -
** Pre-Conditions: card class must exist
** Post-Conditions: returns the int value of private member 
* variables of a class
******************************************************/
  int get_suit();

/******************************************************
** Function: set_rank
** Description: this function allows us to assign values
* to the private class member variable: int rank
** Parameters: rank1 - value that we assign
** Pre-Conditions: card class must exist
** Post-Conditions: now we can directly assign values to private member variable rank of class Card
******************************************************/  
  void set_rank(int);

/******************************************************
** Function: set_suit
** Description: this function allows us to assign values
* to the private class member variable: int suit
** Parameters: suit1 - value that we assign
** Pre-Conditions: card class must exist
** Post-Conditions: now we can directly assign values to private member variable suit of class Card
******************************************************/   
  void set_suit(int);

/******************************************************
** Function: print_suit
** Description: this function prints string rank and string 
* suit
** Parameters: -
** Pre-Conditions: card class must exist
** Post-Conditions: info received from get_string_rank and 
* get_string_suit functions is being printed if function 
* is called
******************************************************/  
  void print_suit();

/******************************************************
** Function: Card() constructor
** Description: constructor for a Card class, initializes 
* rank and suit values with 0 when a Card class is created
** Parameters: -
** Pre-Conditions: card class must exist
** Post-Conditions: sets rank and suit to 0
******************************************************/   
  Card();

/******************************************************
** Function: Card() constructor
** Description: constructor for a Card class, initializes 
* rank and suit values with given as a parameter values 
** Parameters: -
** Pre-Conditions: card class must exist
** Post-Conditions: sets rank and suit to parameters -
* given values
******************************************************/   
  Card(int, int);

/******************************************************
** Function: Card() destructor
** Description: does nothing
** Parameters: -
** Pre-Conditions: card class must exist
** Post-Conditions: -
******************************************************/
  ~Card();

/******************************************************
** Function: get_string_rank
** Description: takes an int value of a rank and translates 
* it into a string 
** Parameters: -
** Pre-Conditions: card class must exist
** Post-Conditions: returns a string value of a rank, 
* corresponding to the int value of a rank
******************************************************/  
  string get_string_rank();

/******************************************************
** Function: get_string_suit
** Description: takes an int value of a suit and translates 
* it into a string 
** Parameters: -
** Pre-Conditions: card class must exist
** Post-Conditions: returns a string value of a suit, 
* corresponding to the int value of a suit
******************************************************/  
  string get_string_suit();
};

#endif