#include "card.h"
#include "deck.h"
#include "hand.h"

#include <iostream>
#include <string>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int Deck::get_n_cards(){
  return n_cards;
}

Card* Deck::get_cards_array(){
  return cards;
}

void Deck::set_n_cards(int n_cards1){
  n_cards = n_cards1;
}

Deck::Deck() {
   int rank[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
   int suit[] = {0, 1, 2, 3};
   int k = 0;
   for (int i = 0; i < 13; i++) {
       for (int j = 0; j < 4; j++) {
           cards[k] = Card(rank[i], suit[j]);
           k++;
       }
   }
   n_cards = 0;
}

Deck::~Deck() {
}

void Deck::print_deck(){
  for (int i = 0; i < n_cards; i++) {
    cards[i].print_suit();
  }
}

void Deck::shuffle_deck(){
  srand(time(NULL));
  for (int i=0; i< 52; i++){
       int j = i + (rand() % (52 - i));
       Card card = cards[i];
       cards[i] = cards[j];
       cards[j] = card;
   }
}

void Deck::deal_card(Hand& hand){
  if (n_cards < 51){
    hand.add_cards(cards[n_cards++]);
  }
}