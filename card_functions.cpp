#include <iostream>
#include <string>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

#include "card.h"

Card::Card(){
  suit = 0;
  rank = 0;
}

Card::Card(int rank1, int suit1){
  rank = rank1;
  suit = suit1;
}

Card::~Card() {
}

int Card::get_rank(){
  return rank;
}

int Card::get_suit(){
  return suit;
}

void Card::set_rank(int rank1){
  rank = rank1;
}

void Card::set_suit(int suit1){
  suit = suit1;
}

string Card::get_string_rank(){
  if (rank == 0){ return "Ace";}
  if (rank == 1){ return "2";}
  if (rank == 2){ return "3";}
  if (rank == 3){ return "4";}
  if (rank == 4){ return "5";}
  if (rank == 5){ return "6";}
  if (rank == 6){ return "7";}
  if (rank == 7){ return "8";}
  if (rank == 8){ return "9";}
  if (rank == 9){ return "10";}
  if (rank == 10){ return "Jack";}
  if (rank == 11){ return "Queen";}
  if (rank == 12){ return "King";}
}

string Card::get_string_suit(){
  if (suit == 0){ return "Diamonds";}
  if (suit == 1){ return "Clubs";}
  if (suit == 2){ return "Hearts";}
  if (suit == 3){ return "Spades";}
}

void Card::print_suit(){
    cout << "Suit of a card " << get_string_rank() << " is "<< get_string_suit() <<  endl;
}