#include "card.h"
#include "hand.h"
#include "deck.h"

#include <iostream>
#include <string>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int Hand::get_n_cards() {
return this->n_cards;
}

Card* Hand::get_cards(){
  return this->cards;
}

Card Hand::get_n_card(int i){
  return this->cards[i];
}

Hand::Hand() {
cards = NULL;
n_cards = 0;
}

void Hand::set_n_cards(int n_cards1) {
n_cards = n_cards1;
}

Hand::Hand(const Hand& old_hand){
/*  cout << "Invoked the copy constructor!" << endl; */
  this->n_cards = old_hand.n_cards;
  this->cards = new Card[n_cards];
  for(int i = 0; i< n_cards; i++){
  this->cards[i] = old_hand.cards[i];
  }
}

Hand& Hand::operator=(const Hand& old_hand) {
/*  cout << "Invoked the overloaded assignment operator" << endl; */
  if(this != &old_hand){

  if (this-> cards != NULL){
    delete[] this->cards;
    cards = NULL;
  }

  this->n_cards = old_hand.n_cards;

  this->cards = new Card[n_cards];
  for(int i = 0; i< n_cards; i++){
    this->cards[i] = old_hand.cards[i];
  }
}
  return *this;
}

Hand::~Hand(){
/*  cout << "Invoked freeing the memory" << endl; */
  delete [] cards;
}

void Hand::add_cards(Card card){
  
  Card *cards1 = new Card[n_cards + 1];
  for(int i=0; i< n_cards; i++){
    cards1[i] = cards[i];
  }
  cards1[n_cards] = card;
  
  n_cards++;

  delete [] cards;
  
  cards = cards1;

}

Card Hand::remove_cards(int choice){
  Card *cards1 = new Card[n_cards - 1];
  Card saved; 
    int counter1 = 0;
    int counter2 = 0;
    choice--;
  for(int i=0; i < n_cards; i++){
    if(i == choice) {
      saved = cards[counter2];
      counter2++;
      continue;
      }
      else{
        cards1[counter1] = cards[counter2];
        counter1++;
        counter2++;
      }
  }
  n_cards--;
  delete [] cards;
  cards = new Card[n_cards];
  for (int i = 0; i<n_cards; i++){
    cards[i] = cards1[i];
  }
  delete [] cards1; 
  return saved; 
}

void Hand::print_hand(){
  for (int i= 0; i< n_cards; i++){
    cout << i+1 <<") " << cards[i].get_string_rank() << " of " << cards[i].get_string_suit() << endl;
  }
}

bool Hand::is_valid_suit(string suit){
  bool flag = false;
  for (int i = 0; i < n_cards; i++){
    if (cards[i].get_string_suit() == suit){
        flag = true;
        return flag;         
        }
  }
  return flag;
}
bool Hand::check_suit(string suit, int i){
  if (this->cards[i].get_string_suit() == suit){
    return true;
  }
  if (this->cards[i].get_string_rank() == "8"){
  return true;
  }
  return false; 
}

bool Hand::check_rank(string rank, int i){
  if (this->cards[i].get_string_rank() == rank){
    return true;
  }
  return false; 
}

bool Hand::is_valid_rank(string rank){
  bool flag = false;
  for (int i = 0; i < n_cards; i++){
    if (cards[i].get_string_rank() == rank)
    {
        flag = true;   
        return flag;      
        }
  }
  for (int i = 0; i < n_cards; i++){
    if (cards[i].get_string_rank() == "8"){
  /* 8 can be played any time */    
        flag = true;   
        return flag;      
        }
  }

  return flag;
}

bool Hand::check_for8(int choice){
choice--;
bool flag = false;
if (cards[choice].get_string_rank() == "8"){
    flag = true;
  }
  return flag;
}
