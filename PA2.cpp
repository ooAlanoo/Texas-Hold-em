#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include"card.h"
#include"deck.h"
#include"SortedLinkedList.h"
#include"pokerhand.h"
#include"rank.h"

using namespace std;

const int SEVEN = 7;
const int FIVE = 5;
const int TWO = 2;

PokerHand best_FIVE_out_of_SEVEN(const vector<Card>& cards); 

int main(){
	char control = 'A'; // play or not
    vector <Card> player_hand(SEVEN);
    vector <Card> comp_hand(SEVEN);
    vector <Card> table_cards(FIVE);
    Deck Game;
    do{
        Game.createDeck();//create a deck
        Game.shuffleDeck();//sort it
        cout << "The cards in your hand are: " << endl;
        for (int i = 0; i < TWO ; i ++){ // player's cards
            player_hand[i] = Game.deal_a_card();
            player_hand[i].print();
        }
        cout << endl;
        cout << "The FIVE cards from the deck to share are: " <<  endl
             << "***********************" << endl;
        for (int k = 0; k < FIVE ; k++){ // deck cards
            table_cards[k] = Game.deal_a_card();
            table_cards[k].print();
        }

        cout << endl;
        cout << "***********************" << endl;
        cout << "The cards in computer's hand are: " << endl;
        for (int j = 0; j < TWO; j++){ // computer's cards
            comp_hand[j] = Game.deal_a_card();
            comp_hand[j].print();
        }
        cout << endl;

        player_hand[2] = table_cards[0];
        player_hand[3] = table_cards[1];
        player_hand[4] = table_cards[2];
        player_hand[5] = table_cards[3];
        player_hand[6] = table_cards[4];

        comp_hand[2] = table_cards[0];
        comp_hand[3] = table_cards[1];
        comp_hand[4] = table_cards[2];
        comp_hand[5] = table_cards[3];
        comp_hand[6] = table_cards[4];

        PokerHand hand[2];

        cout << "Player 1: You" << endl;
        hand[0] = best_FIVE_out_of_SEVEN(player_hand);

        cout << "Player 2: Computer" << endl;
        hand[1] = best_FIVE_out_of_SEVEN(comp_hand);

        if (hand[0].compareHand(hand[1]) < 0) {
            cout << "Sorry, the computer wins the game... " << endl;
        }
        else if (hand[0].compareHand(hand[1]) > 0){
            cout << "Congratulations, you win the game..." << endl;
        }
        else {
            cout <<"It's a Tie game..." << endl;
        }

        cout << "Do you want to play again? (Enter Q or q to quit)";
        cin >> control;
        cin.ignore(256,'\n');           
        }while (control !='Q' && control != 'q');
	cout << "Thanks for using this program!" << endl;
	return 0;
}


PokerHand best_FIVE_out_of_SEVEN(const vector<Card>& cards)
{    

    PokerHand bestH;
    PokerHand cardsH;

    // check if the parameter is valid
    if (cards.size() != SEVEN)
    {
        cout << "Invalid Cards, we need SEVEN cards!" << endl;
        return cardsH; // return a PokerHand object by default constructor
    }

    // Consider all possible ways of dropping two cards
    // from all seven cards 
    // i is the index of the first card dropped
    // and j is the index of the second card dropped.
    // There are 21 different ways to pick 5 cards out of 7
    for (int i=0; i < SEVEN; i++) 
    {
        for (int j=i+1; j < SEVEN; j++) 
        {
            Card pick[FIVE];
            int index = 0;

            // Iterate over all seven cards and assign them to the pick[] array
            // exclude cards with index numbers of #i and #j.
            for (int k=0 ; k < SEVEN ; k++) 
            {
                if (k == i || k == j) 
                    continue;
                pick[index] = cards[k];
                index++;
            }
            
            // create a PokerHand with pick[]
            cardsH.setPokerHand(pick, FIVE);

            // Check to see if current pick is better than
            // the best you have seen so far
            if (bestH.compareHand(cardsH) < 0)
            {
                bestH = cardsH ;
            }
        }
    }

    // Now bestH holds the best poker hand among all 21 poker hands
    cout << "*** Best five-card hand ***" << endl;
    bestH.print();
    cout << endl << endl;
    return bestH;
}
