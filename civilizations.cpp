/* Author: Allison Delgado
   Class: CS 202 Summer 2021
   The civilizations.cpp file contains the member functions
   of the following classes: Civilization, Industry,
   Agriculture, Military, Node, and DLL. This project is
   a Civilization game in which the user can                    
   build and play as different civilization types. You can
   test it out in main.

   Last updated: July 20, 2021
 */
#include "civilizations.h"

// ***************** CIVILIZATION CLASS *********************

//constructor
Civilization::Civilization(){
  
}

//destructor
Civilization::~Civilization(){
  
}

//copy constructor
Civilization::Civilization(const Civilization & source){

}

//fill in civilization details
void Civilization::read(){

}

//show all civ details
void Civilization::display(){

}

//display items on market
void display_market(){

}

// ***************** AGRICULTURE CLASS *********************

//constructor
Agriculture::Agriculture() : Civilization(){

}

//buy from market
void Agriculture::buy(std::string to_buy, int amount){

}

//sell to market
void Agriculture::sell(std::string to_sell, int amount){

}

//trade with another civ
void Agriculture::trade(std::string civilization, std::string item){

}

//harvest crops. returns true for success, false for failure
bool Agriculture::harvest(){

}

//water your crops
void Agriculture::water_crops(){

}

//plant another plot of crops
void Agriculture::plant_plots(){

}

// ***************** MILITARY CLASS *********************

Military::Military() : Civilization(){

}

//buy from market
void Military::buy(std::string to_buy, int amount){

}

//sell to market
void Military::sell(std::string to_sell, int amount){

}

//trade with another civ
void Military::trade(std::string civilization, std::string item){

}

//gain more soldiers
void Military::train_troops(){

}

//required every turn
void Military::feed_troops(){

}

//potentially gain more soldiers
void Military::boost_morale(){

}

// ***************** INDUSTRY CLASS *********************

Industry::Industry() : Civilization(){

}

//buy from market
void Industry::buy(std::string to_buy, int amount){

}

//sell to market
void Industry::sell(std::string to_sell, int amount){

}

//trade with another civ
void Industry::trade(std::string civilization, std::string item){

}

//create a new product that you can produce
void Industry::produce_new_product(){

}

//check on current products
void Industry::check_status(){

}

//required every turn
void Industry::work(){

}

// ***************** NODE CLASS *********************

//constructor
Node::Node(){

}

//copy constructor
Node::Node(const Civilization & source){

}

//go to the next node
Node *& Node::go_next(){

}

//set next
void Node::set_next(Node*& next){

}

//set previous
void Node::set_prev(Node *& prev){

}

// ***************** DLL CLASS *********************

//constructor
DLL::DLL(){

}

//destructor
DLL::~DLL(){

}

//copy constructor
DLL::DLL(const DLL & source){

}

//insert to DLL
void DLL::insert(const Civilization *& civ){

}

//recursive insert
void DLL::insert(Node * current, Node *& to_add){

}

//remove from DLL
void DLL::remove(char* name){

}

//recursive remove
void DLL::remove(Node * current, char* to_remove){

}

//display DLL
void DLL::display(){

}

//recursive display
void DLL::display(Node * current){

}

//remove all nodes from DLL
void DLL::remove_all(){

}

//recursive remove all
void DLL::remove_all(Node *& current){
  
}
