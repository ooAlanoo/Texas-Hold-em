OBJECTS1 = card.o deck.o rank.o SortedLinkedList.o pokerhand.o PA2.o

OBJECTS2 = card.o deck.o rank.o SortedLinkedList.o pokerhand.o testPA2.o # make difference between CS216PA2 and testPA2

HEADERS = card.h deck.h rank.h SortedLinkedList.h pokerhand.h

CS216PA2: $(OBJECTS1)
	g++ -o CS216PA2 card.cpp deck.cpp rank.cpp SortedLinkedList.cpp pokerhand.cpp PA2.cpp
testPA2: $(OBJECTS2)
	g++ -o testPA2 card.cpp deck.cpp rank.cpp SortedLinkedList.cpp pokerhand.cpp testPA2.cpp
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@
clean:
	rm -i *.o PA2 # clean the mess


