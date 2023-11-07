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
    
}

/** 
@post: Destroy the Hand object
**/
Hand::~Hand(){
    
}

/**
 * Copy Constructor
 * @param: other Hand object
*/
Hand::Hand(const Hand& other){
    cards_ = other.cards_; //copy the cards
}

/**
 * Copy Assignment Operator
 * @param: other Hand object
 * @return this Hand 
*/
Hand& Hand::operator=(const Hand& other){
    cards_ = other.cards_; //copy the cards
    return *this; //return this object
}

/**
 * Move Constructor
 * @param: other Hand object
*/
Hand::Hand(Hand&& other){
    cards_ = std::move(other.cards_); //move the cards
}

/**
 * Move assignment operator
 * @param: other Hand object
 * @return this Hand
*/
Hand& Hand::operator=(Hand&& other){
    cards_ = std::move(other.cards_); //move the cards
    return *this; //return this object
}

/**
 * @return Hand
*/
const std::deque<PointCard>& Hand::getCards() const{
    return cards_; //return the cards
}

/**
 * @post: Add a card to the hand
 * @param PointCard object
*/
void Hand::addCard(PointCard&& card){
    cards_.push_back(card); //add the card to the back of the deque
}

/**
 * @return true if hand is empty, false otherwise
*/
bool Hand::isEmpty() const{
    return cards_.empty(); //return if the deque is empty
}

/**
 * @post: Reverse the hand
*/
void Hand::Reverse(){
    std::reverse(cards_.begin(), cards_.end()); //reverse the deque
}

/**
* @post: Play the card at the front of the hand, removing it from the hand
* Throws an exception if the hand is empty or the card is not playable
* If the card is not playable, the card is removed from the hand
* @return the points earned from playing the card
*/
int Hand::PlayCard(){
    if(isEmpty() == true){
        throw -1; //throw an exception
    }else{
        std::string str_points = cards_.front().getInstruction(); //get the instruction
        if(str_points == ""){
            return 0;
        }
        int tmp_points = stoi(str_points); //convert the instruction to an int
        cards_.pop_front(); //remove the card from the front of the deque
        return tmp_points; //return the points
        /*
        bool is_digit = false; //initialize the bool to false
        if(std::isdigit(str_points[0]) == true){
            is_digit = true; //set the bool to true
        }
        if(is_digit == true){
            int tmp_points = stoi(str_points); //convert the instruction to an int
            cards_.pop_front(); //remove the card from the front of the deque
            return tmp_points; //return the points
        }else{
            throw -1; //throw an exception
        }*/
    }
    
}
