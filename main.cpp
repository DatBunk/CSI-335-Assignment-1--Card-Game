#include "Player.hpp"
#include "Deck.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"
#include "Card.hpp"
#include "Hand.hpp"

int main(){
    Deck<ActionCard> deck;
    ActionCard card1;
    card1.setInstruction("REVERSE HAND");
    card1.setType(CardType::ACTION_CARD);
    
    deck.AddCard(card1);


    ActionCard test_card = deck.Draw();
    test_card.Print();

    /* DECK IS EMPTY TEST*/
    std::cout << "Is empty: ";
    if(deck.IsEmpty()){
        std::cout << "true" << std::endl;
    }
    else{
        std::cout << "false" << std::endl;
    }
    

    return 0;
}