#include "rank.h"
#include<iostream>

using namespace std;

Rank::Rank() {
	point = 0;
	kind = Rank::NoRank;
}

Rank::Rank(hRanks r, rPoints p) {
	point = p;
	kind = r;
}

void Rank::print() { // Every kind has a output
	char pointCase = ' ';
	if (point == 11) {
		pointCase = 'J';
		if (kind == Rank::HighCard) { cout << "HighCard( " << pointCase << ")" << endl; }
		if (kind == Rank::Pair) { cout << "Pair( " << pointCase << ")" << endl; }
		if (kind == Rank::ThreeOfAKind) { cout << "ThreeOfAKind( " << pointCase << ")" << endl; }
		if (kind == Rank::Straight) { cout << "Straight( " << pointCase << ")" << endl; }
		if (kind == Rank::Flush) { cout << "Flush( " << pointCase << ")" << endl; }
		if (kind == Rank::FullHouse) { cout << "FullHouse( " << pointCase << ")" << endl; }
		if (kind == Rank::FourOfAKind) { cout << "FourOfAKind( " << pointCase << ")" << endl; }
		if (kind == Rank::StraightFlush) { cout << "StraightFlush( " << pointCase << ")" << endl; }
	}
	else if (point == 12) {
		pointCase = 'Q';
		if (kind == Rank::HighCard) { cout << "HighCard( " << pointCase << ")" << endl; }
		if (kind == Rank::Pair) { cout << "Pair( " << pointCase << ")" << endl; }
		if (kind == Rank::ThreeOfAKind) { cout << "ThreeOfAKind( " << pointCase << ")" << endl; }
		if (kind == Rank::Straight) { cout << "Straight( " << pointCase << ")" << endl; }
		if (kind == Rank::Flush) { cout << "Flush( " << pointCase << ")" << endl; }
		if (kind == Rank::FullHouse) { cout << "FullHouse( " << pointCase << ")" << endl; }
		if (kind == Rank::FourOfAKind) { cout << "FourOfAKind( " << pointCase << ")" << endl; }
		if (kind == Rank::StraightFlush) { cout << "StraightFlush( " << pointCase << ")" << endl; }
	}
	else if (point == 13) {
		pointCase = 'K';
		if (kind == Rank::HighCard) { cout << "HighCard( " << pointCase << ")" << endl; }
		if (kind == Rank::Pair) { cout << "Pair( " << pointCase << ")" << endl; }
		if (kind == Rank::ThreeOfAKind) { cout << "ThreeOfAKind( " << pointCase << ")" << endl; }
		if (kind == Rank::Straight) { cout << "Straight( " << pointCase << ")" << endl; }
		if (kind == Rank::Flush) { cout << "Flush( " << pointCase << ")" << endl; }
		if (kind == Rank::FullHouse) { cout << "FullHouse( " << pointCase << ")" << endl; }
		if (kind == Rank::FourOfAKind) { cout << "FourOfAKind( " << pointCase << ")" << endl; }
		if (kind == Rank::StraightFlush) { cout << "StraightFlush( " << pointCase << ")" << endl; }
	}
	else if (point == 14) {
		pointCase = 'A';
		if (kind == Rank::HighCard) { cout << "HighCard( " << pointCase << ")" << endl; }
		if (kind == Rank::Pair) { cout << "Pair( " << pointCase << ")" << endl; }
		if (kind == Rank::ThreeOfAKind) { cout << "ThreeOfAKind( " << pointCase << ")" << endl; }
		if (kind == Rank::Straight) { cout << "Straight( " << pointCase << ")" << endl; }
		if (kind == Rank::Flush) { cout << "Flush( " << pointCase << ")" << endl; }
		if (kind == Rank::FullHouse) { cout << "FullHouse( " << pointCase << ")" << endl; }
		if (kind == Rank::FourOfAKind) { cout << "FourOfAKind( " << pointCase << ")" << endl; }
		if (kind == Rank::StraightFlush) { cout << "StraightFlush( " << pointCase << ")" << endl; }
	}
	else {
		if (kind == Rank::HighCard) { cout << "HighCard( " << point << ")" << endl; }
		if (kind == Rank::Pair) { cout << "Pair( " << point << ")" << endl; }
		if (kind == Rank::ThreeOfAKind) { cout << "ThreeOfAKind( " << point << ")" << endl; }
		if (kind == Rank::Straight) { cout << "Straight( " << point << ")" << endl; }
		if (kind == Rank::Flush) { cout << "Flush( " << point << ")" << endl; }
		if (kind == Rank::FullHouse) { cout << "FullHouse( " << point << ")" << endl; }
		if (kind == Rank::FourOfAKind) { cout << "FourOfAKind( " << point << ")" << endl; }
		if (kind == Rank::StraightFlush) { cout << "StraightFlush( " << point << ")" << endl; }
	}
}
