/*
Ildefonso Marrero
Last Modified: 11/4/2023
*

#include "Player.hpp"

/**
 @post: Construct a new Player object
**
Player::Player(){
    score_ = 0;
}

/**
 @post: Destroy the Player object
**
Player::~Player(){
    delete actiondeck_;
    delete pointdeck_;
    delete opponent_;
}

/**
 @return the player's hand
**
const Hand& Player::getHand() const{
    return hand_;
}

/**
 @post: Set the player's hand
 @param const reference to a hand object
**
void Player::setHand(const Hand& hand){
    hand_ = hand;
}

/**
 @return the Player's current score
**
int Player::getScore() const{
    return score_;
}

/**
 @post: Set the player's score
 @param: score
**
void Player::setScore(const int& score){
    score_ = score;
}

/**
 @post: Play a given action card
 @param: an Actioncard object
 Begin the function by reporting the instruction of the card:
 PLAYING ACTION CARD: [instruction]
**
void Player::play(ActionCard&& card){
    std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << std::endl;
    hand_.PlayCard();
}

/**
 @post: Draw a point card and place it in the player's hand
**
void Player::drawPointCard(){
    pointdeck_->Draw();
}

/**
 @post: Play a point card from the player's hand and update the player's score
**
void Player::playPointCard(){
    score_ += hand_.PlayCard();
}

/**
 @post: Set the opponent of the player
 @param a pointer to a Player opponent
**
void Player::setOpponent(Player* opponent){
    opponent_ = opponent;
}

/**
 @return: a pointer to the player's opponent
**
Player* Player::getOpponent(){
    return opponent_;
}

/**
@post: set the action deck of the player
@param: A pointer to a deck holding Action cards 
**
void Player::setActionDeck(Deck<ActionCard>* actiondeck){
    actiondeck_ = actiondeck;
}

/**
@return: a pointer to the player's action deck
**
Deck<ActionCard>* Player::getActionDeck(){
    return actiondeck_;
}

/**
 @post: Set the point deck of the player
 @param: A pointer to a deck holding Point cards
**
void Player::setPointDeck(Deck<PointCard>* pointdeck){
    pointdeck_ = pointdeck;
}

/**
 @return: a pointer to the player's point deck
**
Deck<PointCard>* Player::getPointDeck(){
    return pointdeck_;
}

