#include<iostream>
#include"pokerhand.h"

using namespace std;

PokerHand::PokerHand() {
	hand_rank = Rank();
}

void PokerHand::setPokerHand(Card in_hand[], int size) {
	if (size == 5) {
		for (int i = 0; i < FIVE; i++) {
			cards[i].suit = in_hand[i].suit;
			cards[i].point = in_hand[i].point;
		}
		sort();
		if (isStraightFlush()){}
			else if (isFourOfAKind()){}
				else if (isFullHouse()){}
					else if (isFlush()){}
						else if (isStraight()){}
							else if (isThreeOfAKind()){}
								else if (isPair()){}
									else if (isHighCard()){}
										else{hand_rank.kind=Rank::NoRank;}
	}
	else
		cout << "Invalid number of cards!";
}

int PokerHand::compareHand(const PokerHand &otherHand) {
	if (otherHand.hand_rank.kind > hand_rank.kind) {
		return -1;
	}
	else if (otherHand.hand_rank.kind < hand_rank.kind) {
		return 1;
	}
	else {
		if (otherHand.hand_rank.point > hand_rank.point) {
			return -1;
		}
		else if (otherHand.hand_rank.point < hand_rank.point) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

void PokerHand::print() {
	cout << "Five Cards: " << endl;
	for (int i = 0; i < FIVE; i++) {
		cards[i].print();
	}
	cout << "Its rank is: ";
	hand_rank.print();
}

Rank PokerHand::getRank() const {
	return hand_rank;
}

bool PokerHand::isStraightFlush() {
	if (isAllOneSuit() && isSequence()) {
		hand_rank = Rank(Rank::StraightFlush, cards[0].point);
		return true;
	}
	else {
		return false;
	}
}

bool PokerHand::isFourOfAKind() {
	if (cards[0].point == cards[3].point){
		hand_rank = Rank(Rank::FourOfAKind, cards[0].point);
		return true;
	}
	else if (cards[1].point == cards[4].point){
		hand_rank = Rank(Rank::FourOfAKind, cards[1].point);
		return true;
	}
	else{
		return false;
	}
}

bool PokerHand::isFullHouse() { // List two different kinds
	sort();
        if(((cards[0].point == cards[1].point && cards[1].point == cards[2].point) && (cards[3].point == cards[4].point) && cards[0].point != cards[3].point) ||
       (((cards[0].point == cards[1].point) && (cards[2].point == cards[3].point && cards[3].point == cards[4].point)) && (cards[0].point != cards[2].point))){
        hand_rank.kind = Rank :: FullHouse;
        hand_rank.point = cards[2].point;
	return true;
}
	else{
		return false;
}
}

bool PokerHand::isFlush() {
	if (isAllOneSuit() && !isSequence()) {
		hand_rank = Rank(Rank::Flush, cards[0].point);
		return true;
	}
	else {
		return false;
	}
}

bool PokerHand::isStraight() {
	if (!isFlush() && isSequence()) { // So it would not be All one suit
		hand_rank = Rank(Rank::Straight, cards[0].point);
		return true;
	}
	else {
		return false;
	}
}

bool PokerHand::isThreeOfAKind() { // List three different kinds
	sort();
	if (cards[0].point != cards[1].point && cards[2].point == cards[4].point) {
		hand_rank = Rank(Rank::ThreeOfAKind, cards[2].point);
		return true;
	}
	else if (cards[0].point != cards[4].point && cards[1].point == cards[3].point) {
		hand_rank = Rank(Rank::ThreeOfAKind, cards[1].point);
		return true;
	}
	else if (cards[0].point == cards[2].point && cards[3].point != cards[4].point) {
		hand_rank = Rank(Rank::ThreeOfAKind, cards[0].point);
		return true;
	}
	else {
		return false;
	}
}

bool PokerHand::isPair() { // could disappear one or two pairs in 5 cards
	if (cards[0].point == cards[1].point && cards[2].point != cards[3].point && cards[2].point != cards[4].point){
		hand_rank = Rank(Rank::Pair, cards[0].point);
		return true;
	}
	else if (cards[0].point != cards[3].point && cards[1].point == cards[2].point && cards[0].point != cards[4].point){
		hand_rank = Rank(Rank::Pair, cards[1].point);
		return true;
	}
	else if (cards[0].point != cards[1].point && cards[0].point != cards[4].point && cards[2].point == cards[3].point){
		hand_rank = Rank(Rank::Pair, cards[2].point);
		return true;
	}
	else if (cards[0].point != cards[1].point && cards[0].point != cards[3].point && cards[3].point == cards[4].point){
		hand_rank = Rank(Rank::Pair, cards[3].point);
		return true;
	}
	else{
		return false;
	}
}

bool PokerHand::isHighCard() { // The only one left
	hand_rank = Rank(Rank::HighCard, cards[0].point);
	return true;
}

void PokerHand::sort() { //Make the order decreasing
	for (int i = 0; i < FIVE; i++) {
		for (int j = 0; j < FIVE-i-1; j++) {
			if (cards[j].point < cards[j+1].point) {
				Card temp;
				temp = cards[j];
				cards[j] = cards[j+1];
				cards[j+1] = temp;
			}
		}
	}
}

bool PokerHand::isAllOneSuit() {
	for (int i = 0; i < FIVE-1; i++) {
		if (cards[i].suit != cards[i + 1].suit) { //Check all of suits
			return false;
		}
	}
	return true;
}

bool PokerHand::isSequence() {
	for (int i = 0; i < FIVE-1; i++) {
		if (cards[i].point != cards[i + 1].point + 1) { //Check all of points
			return false;
		}
	}
	return true;
}
