#include "card.h"
#include "hand.h"
#include "player.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

Player::Player(string name1) {
  hand = Hand();
  name = name1;
};

Player::Player(){
}

Hand& Player::get_hand() {
return hand;
}

string Player::get_name() {
return name;
}

int Player::get_choice(Card top_card){
  int x;
  int j;
  cout << "Which card would you like to play? (Choose an integer corresponding to your card): ";
  cin >> x;
  
  if ((hand.check_suit(top_card.get_string_suit(), x-1) == 0) && (hand.check_rank(top_card.get_string_rank(), x-1) == 0)) {
    do{
      cout << "This card can not be played !" << endl;
      cout << "Please use a card, which has the same suit or rank with the current topcard: " << endl;
      cin >> j;
      x = j;
    }
    while ((hand.check_suit(top_card.get_string_suit(), x-1) == 0) && (hand.check_rank(top_card.get_string_rank(), x-1) == 0));
  }
  
  return x;
}

int Player::get_AI_choice(Card top_card){
  int x = 100;

  for (int i = 0; i < hand.get_n_cards(); i++){
  if (hand.check_suit(top_card.get_string_suit(), i) || hand.check_rank(top_card.get_string_rank(), i)){
    x = i;
    x++;
    break;
    }
  }
  return x;
}

void Player::extra_credit(Card top_card){
  int x;

cout << "Hint, here are the cards that can be played: " << endl;
  for (int i = 0; i < hand.get_n_cards(); i++){
  if (hand.check_suit(top_card.get_string_suit(), i) || hand.check_rank(top_card.get_string_rank(), i)){
    x = i;
    x++;

    cout << x << ")  ";
      
    }
  }
}


int Player::get_suit_if8_1(){
  int x;
  cout << "Please choose a suit you want for next player to play. Enter (1) for Diamonds, (2) for Clubs, (3) for Hearts, (4) for Spades: " << endl;
  cin >> x;
  x--;
  return x;
}

int Player::get_suit_if8_2(){
  int x = (rand() % 4); /* numbers 0 to 3 */
  return x;
}

void Player::add_card(Card &card1) {
  hand.add_cards(card1);
}
