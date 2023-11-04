/*
Ildefonso Marrero
Last Modified: 11/4/2023
*/
#include "Hand.hpp"

// Big Five and constructor
/**
 @post: Construct a new Hand object
**/
Hand::Hand(){
    cards_ = std::deque<PointCard>();
}

/** 
@post: Destroy the Hand object
**/
Hand::~Hand(){
    cards_.clear();
    delete &cards_;
}

/**
 * Copy Constructor
 * @param: other Hand object
*/
Hand::Hand(const Hand& other){
    cards_ = other.cards_;
}

/**
 * Copy Assignment Operator
 * @param: other Hand object
 * @return this Hand 
*/
Hand& Hand::operator=(const Hand& other){
    cards_ = other.cards_;
    return *this;
}

/**
 * Move Constructor
 * @param: other Hand object
*/
Hand::Hand(Hand&& other){
    cards_ = other.cards_;
    other.cards_.clear();
}

/**
 * Move assignment operator
 * @param: other Hand object
 * @return this Hand
*/
Hand& Hand::operator=(Hand&& other){
    cards_ = other.cards_;
    other.cards_.clear();
    return *this;
}

/**
 * @return Hand
*/
const std::deque<PointCard>& Hand::getCards() const{
    return cards_;
}

/**
 * @post: Add a card to the hand
 * @param PointCard object
*/
void Hand::addCard(PointCard&& card){
    cards_.push_back(card);
}

/**
 * @return true if hand is empty, false otherwise
*/
bool Hand::isEmpty() const{
    return cards_.empty();
}

/**
 * @post: Reverse the hand
*/
void Hand::Reverse(){
    std::reverse(cards_.begin(), cards_.end());
}

/**
* @post: Play the card at the front of the hand, removing it from the hand
* Throws an exception if the hand is empty or the card is not playable
* If the card is not playable, the card is removed from the hand
* @return the points earned from playing the card
*/
int Hand::PlayCard(){
    if(cards_.empty()){
        throw std::runtime_error("Hand is empty");
    }
    else{
        int points = cards_.front().getPoints();
        cards_.pop_front();
        return points;
    }
}