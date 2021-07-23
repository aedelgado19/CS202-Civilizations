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
void Civilization::display_market(){

}

//displays inventory (true if there is stuff, false if empty inventory)
bool Civilization::display_inventory(){
  
}

//displays random civilization names
void Civilization::random_civs(){
  std::vector<std::string> v;
  srand(time(NULL));
  
  v.push_back("The Mayans");
  v.push_back("The Huns");
  v.push_back("The Aztecs");
  v.push_back("The Goths");
  v.push_back("The Franks");
  v.push_back("The Japanese");
  v.push_back("The Norsemen");
  v.push_back("The Romans");
  v.push_back("The Byzantines");
  v.push_back("The French");
  for(int i = 0; i < 3; i++){
    int n = rand() % 9;
    std::cout << (i + 1) << ") " << v.at(n) << std::endl;
  }
}

//print out a random inventory amounts (used in trading)
void Civilization::random_inventory(int & food, int & soldiers){
  srand(time(NULL));
  int f = rand() % 20;
  int s = rand() % 10;
  food = f;
  soldiers = s;
}

//compares food passed in to civ's food
bool Civilization::compare_food(int i){
  if(i > food){
    return false;
  }
  return true;
}

//compares military passed in to civ's military
bool Civilization::compare_military(int i){
  if(i > military){
    return false;
  }
  return true;
}

// ***************** AGRICULTURE CLASS *********************

//constructor
Agriculture::Agriculture() : Civilization(){

}

//buy from market
void Agriculture::buy(const std::string & to_buy, int amount){
  //call function to check that they have enough money. if not enough print
}

//sell to market
void Agriculture::sell(const std::string & to_sell, int amount){
  //check if valid
}

//trade with another civ
void Agriculture::trade(int lost, int al, int gained, int ag){

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
void Military::buy(const std::string & to_buy, int amount){

}

//sell to market
void Military::sell(const std::string & to_sell, int amount){

}

//trade with another civ
void Military::trade(int lost, int al, int gained, int ag){

}

//gain more soldiers
void Military::train_troops(){

}

//required every turn
void Military::feed_troops(){

}

//potentially gain more resources but you can lose soldiers
void Military::wage_war(){

}

// ***************** INDUSTRY CLASS *********************

Industry::Industry() : Civilization(){

}

//buy from market
void Industry::buy(const std::string & to_buy, int amount){

}

//sell to market
void Industry::sell(const std::string & to_sell, int amount){

}

//trade with another civ
void Industry::trade(int lost, int al, int gained, int ag){

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
