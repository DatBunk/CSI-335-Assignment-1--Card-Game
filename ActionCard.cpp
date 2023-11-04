#include "ActionCard.hpp"

/**
 @post: Construct a new Action Card object
**/
ActionCard::ActionCard(){

}

/**
    * @return true if the card is playable, false otherwise
    * For a card to be playable, it has to be drawn and the instruction has to be valid
    * Valid instructions:
    * DRAW x CARD(S) : assume x is a positive integer
    * PLAY x CARD(S) : assume x is a positive integer
    * REVERSE HAND : reverse the order of the cards in the hand
    * SWAP HAND WITH OPPONENT : swap the hand with the opponent
*/
virtual bool isPlayable() override{
    
}

/**
    * @post: Print the ActionCard in the following format:
    * Type: [CardType]
    * Instruction: [Instruction]
    * Card: 
    * [ImageData]
    * 
    * Note: For [ImageData]: If there is no image data, print "No image data" instead
*/
virtual void Print() const override{
    
}