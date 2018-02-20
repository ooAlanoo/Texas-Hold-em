/* File: card.h
 * Course: CS216-00x
 * Project: Lab 7
 * Purpose: the implementation of member functions for the Card class.
 *
 */

#include "card.h"


// Default constructor marks card as invalid
Card::Card() 
{
    point = 0;
    suit = Invalid;
}

// Alternate constructor
Card::Card(cSuits s, cPoints p) 
{
    point = p;
    suit = s;
}

// compare with another Card object passed in as parameter: other
// if the object your are working on has higher point than other, return 1;
// if the object your are working on has lower point than other, return -1;
// otherwise, return 0
int Card::compareTo(Card other)
{
    if (this->point < other.point) { return -1;}
    else if (this->point > other.point) { return 1;}
    else if (this->point == other.point) { return 0;}
}

// Display a description of the Card object to standard output
// The output should look like:
//   
void Card::print() 
{
    const char *suitCase = NULL;
    switch(suit){
	case Spade: suitCase = SPADE; break;
	case Club: suitCase = CLUB; break;
	case Diamond: suitCase = DIAMOND; break;
	case Heart: suitCase = HEART; break;
	case Invalid: suitCase = NULL; break;
    }
    char pointCase = ' ';
    if (point == 11) {pointCase = 'J'; cout << suitCase << " " << pointCase << suitCase << endl;}
    else if (point == 12) {pointCase = 'Q'; cout << suitCase << " " << pointCase << suitCase << endl;}
    else if (point == 13) {pointCase = 'K'; cout << suitCase << " " << pointCase << suitCase << endl;}
    else if (point == 14) {pointCase = 'A'; cout << suitCase << " " << pointCase << suitCase << endl;}
    else { cout << suitCase << " " << point << suitCase << endl;}
}
