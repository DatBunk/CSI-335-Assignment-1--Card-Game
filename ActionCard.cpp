/*
Ildefonso Marrero
Last Modified: 11/4/2023
*/
#include "ActionCard.hpp"

/**
 @post: Construct a new Action Card object
**/
ActionCard::ActionCard(){
    CardType action_tmp = ACTION_CARD;
    setType(action_tmp);
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
bool ActionCard::isPlayable(){
    bool can_play = false;
    if(getDrawn() == true){
        if(getInstruction() != ""){
            can_play = true;
        }
        
    }

    return can_play;
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
void ActionCard::Print() const{
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Instruction: " << getInstruction() << std::endl;
    std::cout << "Card: " << std::endl;
    if(getImageData() == nullptr){
        std::cout << "No image data" << std::endl;
    }else{
        for(int i = 0; i < 80; i++){
            std::cout << getImageData()[i] << " ";
        }
        std::cout << std::endl;
    }
    
}