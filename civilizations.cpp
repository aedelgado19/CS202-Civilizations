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
Civilization::Civilization() : name(nullptr), food(0), money(0), military(0), m_food(500), m_military(100){
  
}

//destructor
Civilization::~Civilization(){
  delete [] name;
}

//copy constructor
Civilization::Civilization(const Civilization & source){
  name = new char[strlen(source.name) + 1];
  strcpy(name, source.name);
}

//show all civ details
void Civilization::display(){
  std::cout << " " << std::endl;
  std::cout << "----------------------" << std::endl;
  std::cout << "Civilization name: " << name << std::endl;
  std::cout << "   Food: " << food << " meat" << std::endl;
  std::cout << "   Money: " << money << " dollars" << std::endl;
  std::cout << "   Military: " << military << " soldiers" << std::endl;
  std::cout << " " << std::endl;
}

//display items on market
void Civilization::display_market(){
  std::cout << "   " << m_food << " meat" << std::endl;
  std::cout << "   " << m_military << " soldiers" << std::endl;
}

//displays inventory (true if there is stuff, false if empty inventory)
bool Civilization::display_inventory(){
  std::cout << " " << std::endl;
  std::cout << "----------------------" << std::endl;
  std::cout << "You have: " << std::endl;
  std::cout << "   " << food << " meat" << std::endl;
  std::cout << "   " << military << " soldiers" << std::endl;
  std::cout << "   " << money << " dollars" << std::endl;
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

//checks if the civ has enough money to buy something
//for item, 1 = food, 2 = soldier
//a soldier is $10 and food is $4
//return false for do not have enough money, true for can afford
bool Civilization::check_money(int item, int amount){
  if(item == 1){ //food
    int i = amount * 4;
    if(money < i){
      return false;
    }
  } else { // soldier
    int j = amount * 10;
    if(money < j){
      return false;
    }
  }
  return true;
}
// ***************** AGRICULTURE CLASS *********************

//constructor
Agriculture::Agriculture() : Civilization(), amount_of_plots(0){

}

//buy from market
void Agriculture::buy(const std::string & to_buy, int amount){
  if(to_buy == "meat"){
    bool valid = check_money(1, amount);
    if(valid == false){
      std::cout << "You do not have enough money :(" << std::endl;
    } else {
      m_food -= amount;
      food += amount;
    }
  }
  else if(to_buy == "soldiers"){
    bool valid = check_money(2, amount);
    if(valid == false){
      std::cout << "You do not have enough money :(" << std::endl;
    } else {
      m_military -= amount;
      military += amount;
    }
  }
  else {
    std::cout << "That was not a valid option to purchase" << std::endl;
  }
}

//sell to market
void Agriculture::sell(const std::string & to_sell, int amount){
  if(to_sell == "meat"){
    bool valid = compare_food(amount);
    if(valid == false){
      std::cout << "That is more meat than you have. "<< std::endl;
    } else {
      food -= amount;
      money += (4 * amount);
      m_food += amount;
    }
  } else if (to_sell == "soldiers"){
    bool valid = compare_military(amount);
    if(valid == false){
      std::cout << "That is more soldiers than you have." << std::endl;
    } else {
      military -= amount;
      money += (10 * amount);
      m_military += amount;
    }
  } else {
    std::cout << "That was not a valid item to sell" << std::endl;
  }
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
  if(to_buy == "meat"){
    bool valid = check_money(1, amount);
    if(valid == false){
      std::cout << "You do not have enough money :(" << std::endl;
    } else {
      m_food -= amount;
      food += amount;
    }
  }
  else if(to_buy == "soldiers"){
    bool valid = check_money(2, amount);
    if(valid == false){
      std::cout << "You do not have enough money :(" << std::endl;
    } else {
      m_military -= amount;
      military += amount;
    }
  }
  else {
    std::cout << "That was not a valid option to purchase" << std::endl;
  }
}

//sell to market
void Military::sell(const std::string & to_sell, int amount){
  if(to_sell == "meat"){
    bool valid = compare_food(amount);
    if(valid == false){
      std::cout << "That is more meat than you have. "<< std::endl;
    } else {
      food -= amount;
      money += (4 * amount);
      m_food += amount;
    }
  } else if (to_sell == "soldiers"){
    bool valid = compare_military(amount);
    if(valid == false){
      std::cout << "That is more soldiers than you have." << std::endl;
    } else {
      military -= amount;
      money += (10 * amount);
      m_military += amount;
    }
  } else {
    std::cout << "That was not a valid item to sell" << std::endl;
  }
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
  if(to_buy == "meat"){
    bool valid = check_money(1, amount);
    if(valid == false){
      std::cout << "You do not have enough money :(" << std::endl;
    } else {
      m_food -= amount;
      food += amount;
    }
  }
  else if(to_buy == "soldiers"){
    bool valid = check_money(2, amount);
    if(valid == false){
      std::cout << "You do not have enough money :(" << std::endl;
    } else {
      m_military -= amount;
      military += amount;
    }
  }
  else {
    std::cout << "That was not a valid option to purchase" << std::endl;
  }
}

//sell to market
void Industry::sell(const std::string & to_sell, int amount){
  if(to_sell == "meat"){
    bool valid = compare_food(amount);
    if(valid == false){
      std::cout << "That is more meat than you have. "<< std::endl;
    } else {
      food -= amount;
      money += (4 * amount);
      m_food += amount;
    }
  } else if (to_sell == "soldiers"){
    bool valid = compare_military(amount);
    if(valid == false){
      std::cout << "That is more soldiers than you have." << std::endl;
    } else {
      military -= amount;
      money += (10 * amount);
      m_military += amount;
    }
  } else {
    std::cout << "That was not a valid item to sell" << std::endl;
  }
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
