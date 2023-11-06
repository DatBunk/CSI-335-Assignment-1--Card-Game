/*
Ildefonso Marrero
Last Modified: 11/4/2023
*/
#include "Card.hpp"

// Big Five and Constructor
/**
    @post: Destroy the Card object
**/
Card::~Card(){
    delete bitmap_;
}

/**
 @post: Construct a new Card object
 @param: const reference to a CardType object
**/
Card::Card(const Card& rhs){
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    bitmap_ = rhs.bitmap_;
    drawn_ = rhs.drawn_;
}

/**
 @param: rvalue reference to a Card object
**/
Card::Card(Card&& rhs){
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    bitmap_ = rhs.bitmap_;
    drawn_ = rhs.drawn_;
    rhs.cardType_ = CardType::POINT_CARD;
    rhs.instruction_ = "";
    rhs.bitmap_ = nullptr;
    rhs.drawn_ = false;
}

/**
 @param const reference to a Card object
 @return this Card object
**/
Card& Card::operator=(const Card& rhs){
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    bitmap_ = rhs.bitmap_;
    drawn_ = rhs.drawn_;

    return *this;
}

/**
 @param rvalue reference to a Card object
 @return this Card object
**/
Card& Card::operator=(Card&& rhs){
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    bitmap_ = rhs.bitmap_;
    drawn_ = rhs.drawn_;
    rhs.cardType_ = CardType::POINT_CARD;
    rhs.instruction_ = "";
    rhs.bitmap_ = nullptr;
    rhs.drawn_ = false;

    return *this;
}

/**
@post: Construct a new Card object  
**/
Card::Card(){
    cardType_ = CardType::POINT_CARD;
    instruction_ = "";
    bitmap_ = nullptr;
    drawn_ = false;
}

/**
* @return the string representation of the card type
*/
std::string Card::getType() const{
    if(cardType_ == CardType::POINT_CARD){
        return "POINT_CARD";
    }
    else{
        return "ACTION_CARD";
    }
}

/**
* @post: set the card type 
**/
void Card::setType(const CardType& type){
    cardType_ = type;
}

/**
* @return the string representation of the card instruction
**/
const std::string& Card::getInstruction() const{
    return instruction_;
}

/**
 * @post: set the card instruction
 * @param const reference to a string object
 * */
void Card::setInstruction(const std::string& instruction){
    instruction_ = instruction;
}

/**
* @return the image data
*/
const int* Card::getImageData() const{
    return bitmap_;
}

/**
 * @post: Set the image data
 * @param pointer to an array of integers
*/
void Card::setImageData(int* data){
    bitmap_ = data;
}

/**
 * @return the drawn status of the card
 * */
bool Card::getDrawn() const{
    return drawn_;
}

/**
 * @post: set the drawn status of the card
 * @param: const reference to a boolean
 * */
void Card::setDrawn(const bool& drawn){
    drawn_ = drawn;
}

