/*
Ildefonso Marrero
Last Modified: 11/4/2023
*/
#include "Player.hpp"

/**
 @post: Construct a new Player object
**/
Player::Player(){
    score_ = 0; //score initialized at 0
    opponent_ = nullptr; //opponent initialized to nullptr
    actiondeck_ = nullptr; //action deck initialized to nullptr
    pointdeck_ = nullptr; //point deck initialized to nullptr
}

/**
 @post: Destroy the Player object
**/
Player::~Player(){
    delete actiondeck_; //delete the action deck
    delete pointdeck_; //delete the point deck
    delete opponent_; //delete the opponent
}

/**
 @return the player's hand
**/
const Hand& Player::getHand() const{
    return hand_; //return the hand
}

/**
 @post: Set the player's hand
 @param const reference to a hand object
**/
void Player::setHand(const Hand& hand){
    hand_ = hand; //set the hand to the given hand, copy constructor
}

/**
 @return the Player's current score
**/
int Player::getScore() const{
    return score_; //return the score
}

/**
 @post: Set the player's score
 @param: score
**/
void Player::setScore(const int& score){
    score_ = score; //set the score to the given score
}

/**
 @post: Play a given action card
 @param: an Actioncard object
 Begin the function by reporting the instruction of the card:
 PLAYING ACTION CARD: [instruction]
**/
void Player::play(ActionCard&& card){
    std::istringstream instruction(card.getInstruction()); //create an istringstream object
    std::string act; //create a temporary string
    instruction >> act; //get the first word of the instruction

    std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << std::endl; //print the instruction
    if(card.getInstruction() == "REVERSE HAND"){ //if the instruction is reverse hand
        hand_.Reverse(); //reverse the hand
    }else if(card.getInstruction() == "SWAP HAND WITH OPPONENT"){ //if the instruction is swap hand with opponent
        Hand temp_hand = hand_; //create a temporary hand
        hand_ = opponent_->getHand(); //set the hand to the opponent's hand
        opponent_->setHand(temp_hand); //set the opponent's hand to the temporary hand
    }else if(card.getInstruction() == "DRAW"){
        int num_cards;
        instruction >> num_cards; //get the number of cards to draw
        for(int i = 0; i < num_cards; i++){
            drawPointCard(); //draw the number of cards
        }
    }else if(card.getInstruction() == "PLAY"){
        int num_cards;
        instruction >> num_cards; //get the number of cards to draw
        for(int i = 0; i < num_cards; i++){
            playPointCard(); //draw the number of cards
        }
    }
}

/**
 @post: Draw a point card and place it in the player's hand
**/
void Player::drawPointCard(){
    if(pointdeck_){
        hand_.addCard(pointdeck_->Draw()); //add a card to the hand
    }
}

/**
 @post: Play a point card from the player's hand and update the player's score
**/
void Player::playPointCard(){
    if(hand_.isEmpty() == false){
        score_ += hand_.PlayCard(); //play a point card and update the score
    }
}

/**
 @post: Set the opponent of the player
 @param a pointer to a Player opponent
**/
void Player::setOpponent(Player* opponent){
    opponent_ = opponent; //set the opponent to the given opponent
}

/**
 @return: a pointer to the player's opponent
**/
Player* Player::getOpponent(){
    return opponent_; //return the opponent
}

/**
@post: set the action deck of the player
@param: A pointer to a deck holding Action cards 
**/
void Player::setActionDeck(Deck<ActionCard>* actiondeck){
    actiondeck_ = actiondeck; //set the action deck to the given action deck
}

/**
@return: a pointer to the player's action deck
**/
Deck<ActionCard>* Player::getActionDeck(){
    return actiondeck_; //return the action deck
}

/**
 @post: Set the point deck of the player
 @param: A pointer to a deck holding Point cards
**/
void Player::setPointDeck(Deck<PointCard>* pointdeck){
    pointdeck_ = pointdeck; //set the point deck to the given point deck
}

/**
 @return: a pointer to the player's point deck
**/
Deck<PointCard>* Player::getPointDeck(){
    return pointdeck_; //return the point deck
}

