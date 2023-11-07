#include "Player.hpp"
#include "Deck.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"
#include "Card.hpp"
#include "Hand.hpp"
#include <iostream>


int main() {
    // Create two players
    Player player1;
    Player player2;
    std::cout<<"Got to here"<<std::endl;
    // Set opponents
    player1.setOpponent(&player2);
    player2.setOpponent(&player1);
    std::cout<<" Got to here 2"<<std::endl;
    // Create decks for action and point cards
    Deck<ActionCard> actionDeck;
    Deck<PointCard> pointDeck;
    std::cout<<" Got to here 3"<<std::endl;

    // Fill the decks with cards (example, you will need to implement this according to your Card classes)
    for (int i = 0; i < 10; ++i) {
        actionDeck.AddCard(ActionCard(/* parameters for ActionCard constructor */));
        pointDeck.AddCard(PointCard(/* parameters for PointCard constructor */));
    }
    std::cout<<" Got to here 4"<<std::endl;
    // Assign the decks to the players
    player1.setActionDeck(&actionDeck);
    player1.setPointDeck(&pointDeck);
    std::cout<<" Got to here 5"<<std::endl;
    player2.setActionDeck(&actionDeck);
    player2.setPointDeck(&pointDeck);
    std::cout<<" Got to here 6"<<std::endl;
    // Shuffle the decks
    actionDeck.Shuffle();
    pointDeck.Shuffle();
    for(int i = 0; i < actionDeck.getSize(); i++){
        std::cout << actionDeck.getDeck()[i].getDrawn()<< ":" << i+1 << ", ";
    }
    std::cout << std::endl;
    std::cout<<" Got to here 7"<<std::endl;
    // Players draw point cards
    player1.drawPointCard();
    std::cout<<" Got to here 7.5"<<std::endl;
    player2.drawPointCard();
    std::cout<<" Got to here 8"<<std::endl;
    // Players draw action cards and play them
    ActionCard actionCard1 = player1.getActionDeck()->Draw();
    ActionCard actionCard2 = player2.getActionDeck()->Draw();
    std::cout<<" Got to here 9"<<std::endl;
    // Players play point cards
    player1.playPointCard();
    player2.playPointCard();
    std::cout<<" Got to here 10"<<std::endl;
    // Output scores
    std::cout << "Player 1 score: " << player1.getScore() << std::endl;
    std::cout << "Player 2 score: " << player2.getScore() << std::endl;
    std::cout<<" Got to here 11"<<std::endl;
    // Check and print hands and opponents

    std::cout << "Player 1's opponent is Player 2: " << (player1.getOpponent() == &player2) << std::endl;
    std::cout << "Player 2's opponent is Player 1: " << (player2.getOpponent() == &player1) << std::endl;
    std::cout<<" Got to here 12"<<std::endl;

    return 0;
}