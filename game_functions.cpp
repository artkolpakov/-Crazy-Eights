#include "card.h"
#include "deck.h"
#include "player.h"
#include "game.h"

#include <iostream>
#include <string>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

Game::Game() {
string str1 = "you";
string str2 = "AI";
players[0] = Player(str1);
players[1] = Player(str2);
cout << "Welcome to the 'Crazy Eights' card game!" << endl;
cards.shuffle_deck();
Card card;
deal_cards();
topcard = get_the_top_card();
do{
print_status();
if(turn == 1){
  print_hand();
}
cout << endl;

one_round();

get_deck_cards();
 
cout << "---------------------------------------" << endl;
}
while(check_for_win()== 0);
get_winner();
}

void Game::print_status(){
int a = players[0].get_hand().get_n_cards();
cout << "Number of cards in your hands: " << a << endl;

int b = players[1].get_hand().get_n_cards();
cout << "Number of cards in AI player hands: " << b << endl;

cout << "Top card is: " << topcard.get_string_rank() << ", " << topcard.get_string_suit() << endl;
}

void Game::get_deck_cards(){
  cout << "Number of cards left in deck: "<< 52 - cards.get_n_cards() << endl;
}

void Game::deal_cards(){
  for (int i = 0; i < 7; i++) {
  cards.deal_card(players[0].get_hand());
}
cout << "7 cards dealt to the player "<< endl;

for (int i = 0; i < 7; i++) {
  cards.deal_card(players[1].get_hand());
}
cout << "7 cards dealt to the AI player "<< endl;
}

void Game::print_hand(){
  cout << endl;
  cout << "Your hand: " << endl;
  players[0].get_hand().print_hand();
  players[0].extra_credit(topcard);
  cout << endl;
}

Card Game::get_current_card(){
  Card* cards_array = cards.get_cards_array();
  counter++; /* 15 0-13, + 14 */
  return cards_array[counter];
}

Card Game::get_the_top_card(){
Card* cards_array = cards.get_cards_array();

return cards_array[(cards.get_n_cards() + 1)];
}

bool Game::check_for_win(){
  bool flag = false;
  if ((cards.get_n_cards() == 51) && (players[0].get_hand().get_n_cards() != 0)&& ((players[1].get_hand().get_n_cards() != 0)) ){
    flag = true;
  }
  if (players[0].get_hand().get_n_cards() == 0){
    flag = true;
  }
  if (players[1].get_hand().get_n_cards() == 0){
  flag = true;
  }
  return flag;
}

void Game::get_winner(){
  if (players[0].get_hand().get_n_cards() == 0){
    cout << "Congratulations, "<<players[0].get_name() << " win !" << endl;
  }
  if (players[1].get_hand().get_n_cards() == 0){
    cout << "Unfortunately you lost, " <<players[1].get_name()<< " won." << endl;
  }
  if ((cards.get_n_cards() == 51) && (players[0].get_hand().get_n_cards() != 0) && (players[1].get_hand().get_n_cards() != 0)){
    if(players[0].get_hand().get_n_cards() < players[1].get_hand().get_n_cards()){
      cout << "Since there are no cards left in the deck, and you have fewer cards than the AI ​​player, you won! " << endl;
    }
    if(players[0].get_hand().get_n_cards() > players[1].get_hand().get_n_cards()){
      cout << "Since there are no cards left in the deck, and you have more cards than the AI ​​player, you have lost!" << endl;
    }
  }
}

int Game::switch_turn(int turn){
  if (turn == 0){
    turn = 1;
  }
  else{
    turn = 0;
  }
  return turn;
}

void Game::one_round(){

  if (turn == 1){
  user_move();
  turn = switch_turn(turn);
  }
  else{
  AI_move();
  turn = switch_turn(turn);
    }
}


void Game::user_move(){
  int choice;
    if (players[0].get_hand().is_valid_suit(topcard.get_string_suit())==1 || players[0].get_hand().is_valid_rank(topcard.get_string_rank())==1){

    choice = players[0].get_choice(topcard);
    make_choice(choice);

    }
    else {
      do {
        if (cards.get_n_cards() == 51){
          break;
          }  
      cards.deal_card(players[0].get_hand()); /* take 1 card */
      cout << "Since you didn't have a card to play, you were dealt one more card. " << endl;
      }
      while (players[0].get_hand().is_valid_suit(topcard.get_string_suit()) !=1 && players[0].get_hand().is_valid_rank(topcard.get_string_rank()) !=1);
    print_hand();
    choice = players[0].get_choice(topcard);
    make_choice(choice);
    }
  }

void Game::AI_move(){
  int choice;
    if (players[1].get_hand().is_valid_suit(topcard.get_string_suit())==1 || players[1].get_hand().is_valid_rank(topcard.get_string_rank())==1) {

    choice = players[1].get_AI_choice(topcard);
    AI_make_choice(choice);

    }
    else {
        do {
      if (cards.get_n_cards() == 51){
      break;
      }
      cards.deal_card(players[1].get_hand()); /* take 1 card */
      cout << "Since AI player didn't have a card to play, he was dealt one more card. " << endl;
        }
      while (players[1].get_hand().is_valid_suit(topcard.get_string_suit()) !=1 && players[1].get_hand().is_valid_rank(topcard.get_string_rank()) !=1);
    choice = players[1].get_AI_choice(topcard);
    AI_make_choice(choice);
    }
 }

void Game::make_choice(int choice){
  int suit;
  if(players[0].get_hand().check_for8(choice) == 1){
    suit = players[0].get_suit_if8_1();
    this->topcard = players[0].get_hand().remove_cards(choice);
    this->topcard.set_suit(suit);
  }
    else{
      this->topcard = players[0].get_hand().remove_cards(choice);
      }
}

void Game::AI_make_choice(int choice){
  int suit;
  if(players[1].get_hand().check_for8(choice) == 1){
    suit = players[1].get_suit_if8_2();
    this->topcard = players[1].get_hand().remove_cards(choice);
    cout <<"AI played an 8 and now he picked a new random suit. " << endl;
    this->topcard.set_suit(suit);
    cout << "AI player played with " << this->topcard.get_string_rank() << " of " << this->topcard.get_string_suit() << endl;
  }
    else{
      this->topcard = players[1].get_hand().remove_cards(choice);
    cout << "AI player played with " << this->topcard.get_string_rank() << " of " << this->topcard.get_string_suit() << endl;
  }
}
