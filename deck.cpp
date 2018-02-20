/* File: deck.cpp
 * Course: CS216-00x
 * Project: Lab 8 (as part of Project 2)
 * Purpose: the implementation of member functions for the Deck class.
 *
 */

#include <cstdlib>
#include <ctime>
#include "deck.h"
        
// create a standard 52-card deck
void Deck::createDeck()
{
    for (Card::cPoints i = CARD_START; i <= POINT_RANKS;i++){
        deck.push_back(Card(Card::Spade,i));
        deck.push_back(Card(Card::Club,i));
        deck.push_back(Card(Card::Heart,i));
        deck.push_back(Card(Card::Diamond,i));
    }
}

// shuffle the cards in 52-card deck
void Deck::shuffleDeck()
{
    srand(time(NULL));
    for(int i=deck.size()-1;i>0;i--){
        int r = rand()% (i+1);
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

// return a card from the tail of the deck
Card Deck::deal_a_card()
{
    if (!deck.empty()){
        Card card = deck.back();
        deck.pop_back();
        return card;
    }
    else
        return Card(Card::Invalid,0);
}
