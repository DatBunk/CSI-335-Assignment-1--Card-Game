/*
Ildefonso Marrero
Last Modified: 11/7/2023
*/
#include "Deck.hpp"

/**
 * @post: Construct a new Deck object
*/
template <typename CardType>
Deck<CardType>::Deck(){
    
}

/**
 * @post: Destroy the Deck object
 */
template <typename CardType>
Deck<CardType>::~Deck(){
    
}

/**
 * @post: Add a Card to the Deck
 * @param: const reference to CardType card
*/
template <typename CardType>
void Deck<CardType>::AddCard(const CardType& card){
    cards_.push_back(card); //add the card to the back of the vector
}

/**
 * @post: Draw a card from the deck
 * @pre: the deck is not empty
 * @return the right hand value of type CardType 
*/
template <typename CardType>
CardType Deck<CardType>::Draw(){
    CardType card = cards_.back(); //get the card at the back of the vector
    cards_.pop_back(); //remove the card from the back of the vector
    return card; //return the card
}

/**
 * @return if the deck is empty 
*/
template <typename CardType>
bool Deck<CardType>::IsEmpty() const{
    return cards_.empty(); //return if the vector is empty
}

/**
 * @post: Shuffle the deck 
 * Create a random number generator using std::mt19937 with seed 2028358904, 
 * then call std::shuffle on the vector of cards, and with the random number generator as the third argument.  
 * https://en.cppreference.com/w/cpp/algorithm/random_shuffle
 * https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine
*/
template <typename CardType>
void Deck<CardType>::Shuffle(){
    std::mt19937 rng(2028358904); //create the random number generator
    std::shuffle(cards_.begin(), cards_.end(), rng); //shuffle the vector
}

/**
 * @return the size of the deck 
*/
template <typename CardType>
int Deck<CardType>::getSize() const{
    return cards_.size(); //return the size of the vector
}

/**
 * @return the vector of cards in the deck 
*/
template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const{
    return cards_; //return the vector of cards
}