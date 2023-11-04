#include "Card.hpp"

// Big Five and Constructor
/**
    @post: Destroy the Card object
**/
Card::~Card(){
    ???????????????????
}

/**
 @post: Construct a new Card object
 @param: const reference to a CardType object
**/
Card::Card(const Card& rhs){
    cardType_ = rhs.cardType_;
    instrucion_ = rhs.instruction_;
    bitmap_ = rhs.bitmap_;
    drawn_ = rhs.drawn_;
}

/**
 @param const reference to a Card object
 @return this Card object
**/
Card& Card::operator=(const Card& rhs){
    cardType_ = rhs.cardType_;
    instrucion_ = rhs.instruction_;
    bitmap_ = rhs.bitmap_;
    drawn_ = rhs.drawn_;
    return *this;
}

/**
 @param: rvalue reference to a Card object
**/
