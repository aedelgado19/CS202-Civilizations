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
Civilization::Civilization(int f, int m, int s) : food(f), money(m), military(s), m_food(500), m_military(100), name(nullptr){
  srand(time(NULL));
  name = new char[50];
}

//destructor
Civilization::~Civilization(){
  delete [] name;
}

//copy constructor
Civilization::Civilization(const Civilization & source){
  name = new char[strlen(source.name) + 1];
  strcmp(name, source.name);
}

//show all civ details
void Civilization::display(char* n, int civ){
  std::cout << " " << std::endl;
  std::cout << "----------------------" << std::endl;
  std::cout << "Civilization Type: ";
  if(civ == 1){
    std::cout << "Agriculture" << std::endl;
  } else if(civ == 2){
    std::cout << "Military" << std::endl;
  } else {
    std::cout << "Industry" << std::endl;
  }
  if(n) std::cout << "NAME: " << n << std::endl;
  std::cout << " " << std::endl;
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
//bool is whether or not to display the money
bool Civilization::display_inventory(bool m){
  std::cout << " " << std::endl;
  std::cout << "----------------------" << std::endl;
  std::cout << "You have: " << std::endl;
  std::cout << "   " << food << " meat" << std::endl;
  std::cout << "   " << military << " soldiers" << std::endl;
  if(m == true) std::cout << "   " << money << " dollars" << std::endl;
  if(food == 0 && military == 0){
    return false;
  }
  return true;
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

//set up required action for each turn
void Civilization::required_action(int type){
  if(type == 1){
    required_action_done = false;
  } else {
    required_action_done = true;
  }
}

//compare if required action done or not
bool Civilization::compare_action(){
  if(required_action_done == true){
    std::cout << " " << std::endl;
    std::cout << "Required action done for this turn!" << std::endl;
    return true;
  }
  return false;
}

char* Civilization::ret_name(){
  return name;
}

//if they failed to do the required action, penalize
void Civilization::failed_to_do_action(int civ){ //civ: 1 = agr, 2 = mil, 3 = ind
  if(civ == 1){ //agriculture
    std::cout << "You failed to do your required action!" << std::endl;
    std::cout << "10 of your plants died. -10 food. " << std::endl;
    food -= 10;
  } else if(civ == 2){ //military
    military -= 10;
    std::cout << "You failed to do your required action! 10 of your soldiers" << std::endl;
    std::cout << "went hungry and left the military" << std::endl;
  } else { //industry
    money -= 10;
    std::cout << "You failed to do your required action!" << std::endl;
    std::cout << "Your buyers weren't pleased, and one of them stopped" << std::endl;
    std::cout << "doing business with you. -10 dollars." << std::endl;
  }
}

// ***************** AGRICULTURE CLASS *********************

//constructor (food, money, soldiers)
Agriculture::Agriculture() : Civilization(200, 100, 20), amount_of_plots(2){
  
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
      std::cout << "You gained  " << (4 * amount) << " dollars!" << std::endl;
    }
  } else if (to_sell == "soldiers"){
    bool valid = compare_military(amount);
    if(valid == false){
      std::cout << "That is more soldiers than you have." << std::endl;
    } else {
      military -= amount;
      money += (10 * amount);
      m_military += amount;
      std::cout << "You gained  " << (4 * amount) << " dollars!" << std::endl;
    }
  } else {
    std::cout << "That was not a valid item to sell" << std::endl;
  }
}

//display
void Agriculture::display(char* n){
  std::cout << " " << std::endl;
  std::cout << "Amount of plots: " << amount_of_plots << std::endl;
  Civilization::display(n, 1);
}

//trade with another civ. for lost and gained, 1 = food, 2 = soldiers
void Agriculture::trade(int lost, int al, int gained, int ag){
  if(lost == 1){ //food
    food -= al;
    if(gained == 1){ //food
      food += ag;
    } else {
      military += ag;
    }
  } else if(lost == 2){ //soldiers
    military -= al;
    if(gained == 1){
      food += ag;
    } else {
      military += ag;
    }
  } else {
    std::cout << "That was not a valid option." << std::endl;
  }
}

//calculate point totals
int Agriculture::calculate(){
  int f = food * 10; //10 points per food
  int d = money * 20; //20 points per dollar
  int m = military * 15; //15 per soldier
  int a  = amount_of_plots * 20; // 20 per plot
  std::cout << "     FOOD: " << food << " meat    => plus " << f << " points! " << std::endl;
  std::cout << "     MONEY: " << money << " dollars    => plus " << d << " points!" << std::endl;
  std::cout << "     MILITARY: " << military <<" soldiers     => plus " << m << " points!" << std::endl;
  std::cout << "     PLOTS: " << amount_of_plots << " plots     => plus " << a << " points! " << std::endl;
  std::cout << "       TOTAL = " << (f + d + m + a) << " points!" << std::endl;
  return (f + d + m + a);
}

//harvest crops
void Agriculture::harvest(){
  int n = 0;
  
  for(int i = 0; i < amount_of_plots; i++){
    n = rand() % 10;
    if(n > 5){ //if even
      std::cout << "You successfully harvested plot #" << (i+1) <<"!" << std::endl;
      std::cout << " + 20 food" << std::endl;
      food += 20;
    } else {
      std::cout << "Plot #" << (i+1) << " wasn't ready to harvest." << std::endl;
    }
  }
}

//water your crops
void Agriculture::water_crops(){
  std::cout << " " << std::endl;
  std::cout << "Yay! The plants are looking very happy now." << std::endl;
}

//plant another plot of crops
void Agriculture::plant_plots(){
  char yn;
  std::cout << "Planting a new plot costs $10. Would you like to proceed (y/n)?" << std::endl;
  std::cin >> yn;
  std::cin.get();
  if (yn == 'y'){
    if(money >= 10){
      amount_of_plots += 1;
      money -= 10;
      std::cout << "Success! Number of plots now: " << amount_of_plots << std::endl;
    } else {
      std::cout << "You do not have enough money" << std::endl;
    }
  }
}

// ***************** MILITARY CLASS *********************

//constructor (food, money, soldiers)
Military::Military() : Civilization(100, 100, 100){
  successful_wars = 0;
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
      std::cout << "You gained  " << (4 * amount) << " dollars!" << std::endl;
    }
  } else if (to_sell == "soldiers"){
    bool valid = compare_military(amount);
    if(valid == false){
      std::cout << "That is more soldiers than you have." << std::endl;
    } else {
      military -= amount;
      money += (10 * amount);
      m_military += amount;
      std::cout << "You gained  " << (4 * amount) << " dollars!" << std::endl;
    }
  } else {
    std::cout << "That was not a valid item to sell" << std::endl;
  }
}

//trade with another civ
void Military::trade(int lost, int al, int gained, int ag){
  if(lost == 1){ //food
    food -= al;
    if(gained == 1){ //food
      food += ag;
    } else {
      military += ag;
    }
  } else if(lost == 2){ //soldiers
    military -= al;
    if(gained == 1){
      food += ag;
    } else {
      military += ag;
    }
  } else {
    std::cout << "That was not a valid option." << std::endl;
  }
}

//calculate point totals
int Military::calculate(){
  int f = food * 10; //10 points per food
  int d = money * 20; //20 points per dollar
  int m = military * 15; //15 per soldier
  int a  = successful_wars * 20; // 20 per war
  std::cout << "     FOOD: " << food << " meat    => plus " << f << " points! " << std::endl;
  std::cout << "     MONEY: " << money << " dollars    => plus " << d << " points!" << std::endl;
  std::cout << "     MILITARY: " << military <<" soldiers     => plus " << m << " points!" << std::endl;
  std::cout << "     SUCCESSFUL WARS: " << successful_wars << " wars     => plus " << a << " points! " << std::endl;
  std::cout << "       TOTAL = " << (f + d + m + a) << " points!" << std::endl;
  return (f + d + m + a);
}

//gain more soldiers
void Military::train_troops(){
  std::cout << "Training was successful. You gained 15 soldiers." << std::endl;
  military += 15;
}

//required every turn
void Military::feed_troops(){
  std::cout << " " << std::endl;
  std::cout << "Required action done! "<< std::endl;
}

//potentially gain more resources but you can lose soldiers
void Military::wage_war(){
  int success = rand() % 10;
  if(success > 5){
    std::cout << "You won the war!!! + 20 meat and + 40 dollars." << std::endl;
    food += 20;
    money += 40;
    successful_wars += 1;
    return;
  }
  std::cout << "Their army was too powerful. You lost 25 soldiers. "<< std::endl;
  military -= 25;
}

//display
void Military::display(char* n){
  std::cout << "wars won: " << successful_wars << std::endl;
  std::cout << " " << std::endl;
  Civilization::display(n, 2);
}

// ***************** INDUSTRY CLASS *********************

//constructor (food, money, soldiers)
Industry::Industry() : Civilization(50, 200, 50){
  amount_of_products = 2;
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
      std::cout << "You gained  " << (4 * amount) << " dollars!" << std::endl;
    }
  } else if (to_sell == "soldiers"){
    bool valid = compare_military(amount);
    if(valid == false){
      std::cout << "That is more soldiers than you have." << std::endl;
    } else {
      military -= amount;
      money += (10 * amount);
      m_military += amount;
      std::cout << "You gained  " << (4 * amount) << " dollars!" << std::endl;
    }
  } else {
    std::cout << "That was not a valid item to sell" << std::endl;
  }
}

//trade with another civ
void Industry::trade(int lost, int al, int gained, int ag){
  if(lost == 1){ //food
    food -= al;
    if(gained == 1){ //food
      food += ag;
    } else {
      military += ag;
    }
  } else if(lost == 2){ //soldiers
    military -= al;
    if(gained == 1){
      food += ag;
    } else {
      military += ag;
    }
  } else {
    std::cout << "That was not a valid option." << std::endl;
  }
}

//calculate point totals
int Industry::calculate(){
  int f = food * 10; //10 points per food
  int d = money * 20; //20 points per dollar
  int m = military * 15; //15 per soldier
  int a  = amount_of_products * 20; // 20 per product
  std::cout << "     FOOD: " << food << " meat    => plus " << f << " points! " << std::endl;
  std::cout << "     MONEY: " << money << " dollars    => plus " << d << " points!" << std::endl;
  std::cout << "     MILITARY: " << military <<" soldiers     => plus " << m << " points!" << std::endl;
  std::cout << "     DIFFERENT PRODUCTS PRODUCED: " << amount_of_products << " products     => plus " << a << " points! " << std::endl;
  std::cout << "       TOTAL = " << (f + d + m + a) << " points!" << std::endl;
  return (f + d + m + a);
}

//create a new product that you can produce
void Industry::produce_new_product(){
  std::string item;
  std::cout << "What product would you like to produce?" << std::endl;
  std::getline(std::cin, item);
  std::cout << "Sounds good. Your production line now produces " << item << std::endl;
  std::cout << "You now produce " << amount_of_products << " total products. " << std::endl;
  std::cout << "This will be added to your score in the end!" << std::endl;
}

//required every turn
void Industry::work(){
  std::cout << "You went to work today. Good job! You completed your required action." << std::endl;
  
}

// ***************** NODE CLASS *********************

//constructor
Node::Node(){
  next = nullptr;
  prev = nullptr;
  type = 0;
}

//constructor with args
Node::Node(Civilization * c, int t){
  next = nullptr;
  prev = nullptr;
  type = t;
  civ = c;
}

//copy constructor
Node::Node(const Civilization & source){
  next = nullptr;
  prev = nullptr;
}

//go to the next node
Node *& Node::go_next(){
  return next;
}

//go to previous node
Node *& Node::go_prev(){
  return prev;
}

//set next
void Node::set_next(Node* n){
  next = n;
}

//set previous
void Node::set_prev(Node * p){
  prev = p;
}

//call civilization display
void Node::display(){
  civ->display(nullptr, type);
}

//return the name of the civilization
char* Node::name(){
  return civ->ret_name();
}
// ***************** DLL CLASS *********************

//constructor
DLL::DLL(){
  head = nullptr;
}

//destructor
DLL::~DLL(){
  destruct(head);
  head = nullptr;
}

//recursively deallocate all nodes
void DLL::destruct(Node *& cur){
  if(!cur) return;
  if(cur->go_next()){
    if(cur->go_prev()) cur->set_prev(nullptr);
    Node* hold = cur->go_next();
    cur->set_next(nullptr);
    delete cur;
    destruct(hold);
  }
  //final node
  cur->set_prev(nullptr);
  delete cur;
}

//copy constructor
DLL::DLL(const DLL & source){
  cp(head, source.head);
}

//recursive copy
void DLL::cp(Node *& cur, Node * source){
  if(source->go_next() == nullptr){
    cur = new Node(*source);
    cur->set_next(nullptr);
    cur->set_prev(source->go_prev());
  } else {
    cur = new Node(*source);
    cur->set_prev(source->go_prev());
    cp(cur->go_next(), source->go_next());
  }
}

//insert to DLL
void DLL::insert(Civilization * c, int t){
  Node * new_node = new Node(c, t);
  insert(head, new_node);
}

//recursive insert
void DLL::insert(Node * current, Node *& to_add){
  if(!current) return;
  if(current->go_next()){
    insert(current->go_next(), to_add);
  }
  //otherwise insert the new node here
  current->set_next(to_add);
  to_add->set_prev(current);
  to_add->set_next(nullptr);
}

//remove from DLL
void DLL::remove(char* name){
  if(!name) return;
  remove(head, name);
}

//recursive remove
void DLL::remove(Node * current, char* to_remove){
  if(!current) return;
  if(strcmp(current->name(), to_remove) == 0){
    current->go_prev()->set_next(current->go_next()); //set prev's next to cur's next
    current->go_next()->set_prev(current->go_prev());
    delete current;
    return;
  }
  remove(current->go_next(), to_remove);
}

//display DLL
void DLL::display(){
  display(head);
}

//recursive display
void DLL::display(Node * current){
  if(!current) return;
  current->display();
  display(current->go_next());
}

//remove all nodes from DLL
void DLL::remove_all(){
  destruct(head);
  head = nullptr;
}
