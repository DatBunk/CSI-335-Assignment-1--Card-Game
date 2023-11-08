/*
Ildefonso Marrero
Last Modified: 11/7/2023
*/
#include "PointCard.hpp"

/**
 * @post: Construct a new Point Card object
*/
PointCard::PointCard(){
    CardType point_tmp = POINT_CARD; //set the card type to point card
    setType(point_tmp); //set the type
}

/**
    * @return true if the card is playable, false otherwise
    * For a card to be playable, it has to be drawn and the instruction has to be a valid number
*/
bool PointCard::isPlayable(){
    bool can_play = false; //initialize the bool to false
    if(getDrawn() == true){
        if(getInstruction() != ""){
            can_play = true; //set the bool to true
        }
        
    }

    return can_play; //return the bool
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
        for(int i = 0; i < 80; i++){
            std::cout << getImageData()[i] << " ";
        }
        std::cout << std::endl;
    }
    
}