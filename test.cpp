#include "Player.hpp"
#include "Deck.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"
#include "Card.hpp"
#include "Hand.hpp"

int main(){
    /*HAND TESTING*/
    Hand hand;

    PointCard p_card1;
    PointCard p_card2;
    PointCard p_card3;

    Deck<PointCard> point_deck;
    point_deck.AddCard(p_card1);
    point_deck.AddCard(p_card2);
    point_deck.AddCard(p_card3);

    hand.addCard(point_deck.Draw());
    hand.addCard(point_deck.Draw());
    hand.addCard(point_deck.Draw());


    


    /* DECK TESTING
    Deck<ActionCard> action_deck;
    ActionCard card1;
    card1.setInstruction("REVERSE HAND");
    card1.setType(CardType::ACTION_CARD);
    
    deck.AddCard(card1);


    ActionCard test_card = action_deck.Draw();
    test_card.Print();

    /* DECK IS EMPTY TEST
    std::cout << "Is empty: ";
    if(action_deck.IsEmpty()){
        std::cout << "true" << std::endl;
    }
    else{
        std::cout << "false" << std::endl;
    }
    */

    return 0;
}