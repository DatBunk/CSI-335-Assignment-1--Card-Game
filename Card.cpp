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
    if(bitmap_ != nullptr){
        delete[] bitmap_; //delete the bitmap
    }
}

/**
 @post: Construct a new Card object
 @param: const reference to a CardType object
**/
Card::Card(const Card& rhs){
    cardType_ = rhs.cardType_; //set the card type
    instruction_ = rhs.instruction_; //set the instruction
    bitmap_ = rhs.bitmap_; //set the bitmap
    drawn_ = rhs.drawn_; //set the drawn status
}

/**
 @param: rvalue reference to a Card object
**/
Card::Card(Card&& rhs){
    cardType_ = rhs.cardType_; //set the card type
    instruction_ = rhs.instruction_; //set the instruction
    bitmap_ = rhs.bitmap_; //set the bitmap
    drawn_ = rhs.drawn_; //set the drawn status
    rhs.cardType_ = CardType::POINT_CARD; //set the card type to point card
    rhs.instruction_ = ""; //set the instruction to empty
    rhs.bitmap_ = nullptr; //set the bitmap to null
    rhs.drawn_ = false; //set the drawn status to false
}

/**
 @param const reference to a Card object
 @return this Card object
**/
Card& Card::operator=(const Card& rhs){
    cardType_ = rhs.cardType_; //set the card type
    instruction_ = rhs.instruction_; //set the instruction
    bitmap_ = rhs.bitmap_; //set the bitmap
    drawn_ = rhs.drawn_; //set the drawn status

    return *this; //return this object
}

/**
 @param rvalue reference to a Card object
 @return this Card object
**/
Card& Card::operator=(Card&& rhs){
    cardType_ = rhs.cardType_; //set the card type
    instruction_ = rhs.instruction_; //set the instruction
    bitmap_ = rhs.bitmap_; //set the bitmap
    drawn_ = rhs.drawn_; //set the drawn status
    rhs.cardType_ = CardType::POINT_CARD; //set the card type to point card
    rhs.instruction_ = ""; //set the instruction to empty
    rhs.bitmap_ = nullptr; //set the bitmap to null
    rhs.drawn_ = false; //set the drawn status to false

    return *this; //return this object
}

/**
@post: Construct a new Card object  
**/
Card::Card(){
    cardType_ = CardType::POINT_CARD; //set the card type to point card
    instruction_ = ""; //set the instruction to empty
    bitmap_ = nullptr; //set the bitmap to null
    drawn_ = false; //set the drawn status to false
}

/**
* @return the string representation of the card type
*/
std::string Card::getType() const{
    if(cardType_ == CardType::POINT_CARD){
        return "POINT_CARD"; //return the string representation of the point card type
    }
    else{
        return "ACTION_CARD"; //return the string representation of the action card type
    }
}

/**
* @post: set the card type 
**/
void Card::setType(const CardType& type){
    cardType_ = type; //set the card type
}

/**
* @return the string representation of the card instruction
**/
const std::string& Card::getInstruction() const{
    return instruction_; //return the instruction
}

/**
 * @post: set the card instruction
 * @param const reference to a string object
 * */
void Card::setInstruction(const std::string& instruction){
    instruction_ = instruction; //set the instruction
}

/**
* @return the image data
*/
const int* Card::getImageData() const{
    return bitmap_; //return the image data
}

/**
 * @post: Set the image data
 * @param pointer to an array of integers
*/
void Card::setImageData(int* data){
    bitmap_ = data; //set the image data
}

/**
 * @return the drawn status of the card
 * */
bool Card::getDrawn() const{
    return drawn_; //return the drawn status
}

/**
 * @post: set the drawn status of the card
 * @param: const reference to a boolean
 * */
void Card::setDrawn(const bool& drawn){
    drawn_ = drawn; //set the drawn status
}

