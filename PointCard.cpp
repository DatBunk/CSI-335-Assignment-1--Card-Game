/*
Ildefonso Marrero
Last Modified: 11/4/2023
*/
#include "PointCard.hpp"

/**
 * @post: Construct a new Point Card object
*/
PointCard::PointCard(){
    CardType point_tmp = POINT_CARD;
    setType(point_tmp);
}

/**
    * @return true if the card is playable, false otherwise
    * For a card to be playable, it has to be drawn and the instruction has to be a valid number
*/
bool PointCard::isPlayable(){
    bool can_play = false;
    if(getDrawn() == true){
        if(getInstruction() != ""){
            can_play = true;
        }
        
    }

    return can_play;
}

/**
    * @post: Print the Point Card in the following format:
    * Type: [CardType]
    * Points: [Instruction]
    * Card: 
    * [ImageData]
    * 
    * Note: For [ImageData]: If there is no image data, print "No image data" instead
*/
void PointCard::Print() const{
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Points: " << getInstruction() << std::endl;
    std::cout << "Card: " << std::endl;
    if(getImageData() == nullptr){
        std::cout << "No image data" << std::endl;
    }else{
        for(int i = 0; i < 5; i++){
            std::cout << getImageData()[i] << " ";
        }
        std::cout << std::endl;
    }
    
}