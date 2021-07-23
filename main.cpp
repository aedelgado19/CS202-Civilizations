/* Author: Allison Delgado
   Class: CS 202 Summer 2021
   This project is a Civilization game in which the user can 
   build and play as different civilization types: agricultural,
   military, and industrial. Each civilization type has different
   strengths and weaknesses, starting resources, and skills.
   Main.cpp acts as the client for gameplay. The rules of
   the game play are displayed when the client runs the game
   and selects "rules".
   
   last updated: July 22, 2021
 */

#include <iostream>
#include "civilizations.h"
#include <math.h>
using namespace std;

#define AGR 1 //agriculture
#define MIL 2 //military
#define IND 3 //industry

void gameplay(int civ, int round, char* name, Agriculture & a, Military & m, Industry & i);
void agriculture(int c, Agriculture & a);
void military(int c, Military & m);
void industry(int c, Industry & i);
void rules();
void trading(Civilization & civ);

int main(){
  char yn;
  int choice;
  char name[50];
  Agriculture a;
  Military m;
  Industry i;
  
  cout << "------------------------------------" << endl;
  cout << "  Welcome to Civilization " << endl;
  cout << "------------------------------------" << endl;
  cout << "Would you like to hear the rules of the game? (y/n)" << endl;
  cout << "> ";
  cin >> yn;
  cin.get();
  if(yn == 'y'){
    rules();
  }
  cout << "Let's get started." << endl;
  cout << "Please choose a civilization:" << endl;
  cout << "1 - agriculture" << endl;
  cout << "2 - military" << endl;
  cout << "3 - industry" << endl;
  cout << "> ";
  cin >> choice;
  cin.get();
  if(choice != 1 || choice != 2 || choice != 3){
    cout << "That was not one of the choices. Quitting program" << endl;
    return 0;
  }
  cout << "What would you like to name your civilization? " << endl;
  cout << "> ";
  cin.get(name, 50);
  cin.get();
  gameplay(choice, 0, name, a, m, i);
  return 0;
}

//print out the rules of the game
void rules(){
  char yn;
  
  cout << "In this game, you can choose one of three" << endl;
  cout << "civilizations to play as: agricultural, " << endl;
  cout << "military, or industrial. Each has their own " << endl;
  cout << "strengths and weaknesses. The computer will " << endl;
  cout << "play as the other two civilizations you did " << endl;
  cout << "not select. The game has 5 rounds. In each round, " << endl;
  cout << "you will have 2 actions to play, and one required " << endl;
  cout << "action that depends on your specific civilization. " << endl;
  cout << "If you do not do the required action, you may lose points." << endl;
  cout << "You gain points for having a lot of money, military, and food. The " << endl;
  cout << "civilization that has the most points at the " << endl;
  cout << "end of the 5 rounds wins. " << endl;
  cout << " " << endl;
  cout << "Would you like to hear about each civilization? (y/n)" << endl;
  cout << "> ";
  cin >> yn;
  cin.get();
  if(yn == 'y'){
    cout << " " << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << " " << endl;
    cout << "AGRICULTURAL: " << endl;
    cout << "   REQUIRED ACTION EACH TURN: water crops" << endl;
    cout << "   STRENGTHS: starts with higher food" << endl;
    cout << "   WEAKNESSES: starts with low money and low military" << endl;
    cout << "   tip: you can sell your crops for money so you can buy" << endl;
    cout << "   military protection. This might come in handy in case of a raid" << endl;
    cout << " " << endl;
    cout << "INDUSTRIAL: " << endl;
    cout << "   REQUIRED ACTION FOR EACH TURN: go to work (produce items)" << endl;
    cout << "   STRENGTHS: starts with higher money" << endl;
    cout << "   WEAKNESSES: has a low population and low military" << endl;
    cout << "   tip: you can choose to produce new products which means" << endl;
    cout << "   you can be making money in parallel from different products" << endl;
    cout << " " << endl;
    cout << "MILITARY: " << endl;
    cout << "   REQUIRED ACTION FOR EACH TURN: feed troops - or else you lose soldiers" << endl;
    cout << "   STRENGTHS: starts with a very high military" << endl;
    cout << "   WEAKNESSES: has low money and low food" << endl;
    cout << "   tip: choose the 'wage war' option to potentially " << endl;
    cout << "   gain more resources but at the cost of soldiers" << endl;
    cout << " " << endl;
    cout << "--------------------------------------------------------" << endl;
  } 
}

//basic gameplay
void gameplay(int civ, int round, char* name, Agriculture & a, Military & m, Industry & i){
  int choice;
  
  if(round != 0){
    //TODO: display status (inside civilization) ***************************
  }
  cout << "Pick three actions to do (don't forget about your required one!" << endl;
  cout << "1 - buy goods from the market" << endl;
  cout << "2 - sell items" << endl;
  cout << "3 - trade" << endl;

  //civilization specific:
  if(civ == AGR){
    cout << "4 - harvest crops" << endl;
    cout << "5 - plant more plots" << endl;
    cout << "6 - REQUIRED: water crops" << endl;
    cin >> choice;
    cin.get();
    agriculture(choice, a);
  }
  else if(civ == MIL){
    cout << "4 - train more troops" << endl;
    cout << "5 - wage war" << endl;
    cout << "6 - REQUIRED: feed troops" << endl;
    cin >> choice;
    cin.get();
    military(choice, m);
  }
  else {
    cout << "4 - produce a new product" << endl;
    cout << "5 - check status of products" << endl;
    cout << "6 - REQUIRED: go to work" << endl;
    cin >> choice;
    cin.get();
    industry(choice, i);
  }
}

//Agriculture functions
void agriculture(int c, Agriculture & a){
  if(c == 1){
    string purchase;
    int amount;
    a.display_market();
    cout << "What would you like to buy? " << endl;
    cout << "> ";
    getline(cin, purchase);
    cout << "How much of " << purchase << " would you like to buy?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    a.buy(purchase, amount);
  }
  else if(c == 2){
    string sell;
    int amount;
    bool valid = a.display_inventory();
    if(valid == false){
      cout << "You don't have anything to sell!" << endl;
    } else {
      cout << "What would you like to sell?" << endl;
      cout << "> ";
      getline(cin, sell);
      cout << "How much would of " << sell << " would you like to sell?" << endl;
      cin >> amount;
      cin.get();
      a.sell(sell, amount);
    }
  }
  else if(c == 3){
    trading(a);
  }
  else if(c == 4){
    a.harvest();
  }
  else if(c == 5){
    a.water_crops();
  }
  else if(c == 6){
    a.plant_plots();
  }
  else {
    cout << "That was not one of the choices. Quitting program." << endl;
    exit(1);
  }
}

//military functions
void military(int c, Military & m){
  if(c == 1){
    string purchase;
    int amount;
    m.display_market();
    cout << "What would you like to buy? " << endl;
    cout << "> ";
    getline(cin, purchase);
    cout << "How much of " << purchase << " would you like to buy?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    m.buy(purchase, amount);
  }
  else if(c == 2){
    string sell;
    int amount;
    bool valid = m.display_inventory();
    if(valid == false){
      cout << "You don't have anything to sell!" << endl;
    } else {
      cout << "What would you like to sell?" << endl;
      cout << "> ";
      getline(cin, sell);
      cout << "How much would of " << sell << " would you like to sell?" << endl;
      cin >> amount;
      cin.get();
      m.sell(sell, amount);
    }
  }
  else if(c == 3){
    trading(m);
  }
  else if(c == 4){
    m.train_troops();
  }
  else if(c == 5){
    m.wage_war();
  }
  else if(c == 6){
    m.feed_troops();
  }
  else {
    cout << "That was not one of the choices. Quitting program." << endl;
    exit(1);
  }

}

//industry functions
void industry(int c, Industry & i){
  if(c == 1){
    string purchase;
    int amount;
    i.display_market();
    cout << "What would you like to buy? " << endl;
    cout << "> ";
    getline(cin, purchase);
    cout << "How much of " << purchase << " would you like to buy?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    i.buy(purchase, amount);
  }
  else if(c == 2){
    string sell;
    int amount;
    bool valid = i.display_inventory();
    if(valid == false){
      cout << "You don't have anything to sell!" << endl;
    } else {
      cout << "What would you like to sell?" << endl;
      cout << "> ";
      getline(cin, sell);
      cout << "How much would of " << sell << " would you like to sell?" << endl;
      cin >> amount;
      cin.get();
      i.sell(sell, amount);
    }

  }
  else if(c == 3){
    trading(i);
  }
  else if(c == 4){
    i.produce_new_product();
  }
  else if(c == 5){
    i.check_status();
  }
  else if(c == 6){
    i.work();
  }
  else {
    cout << "That was not one of the choices. Quitting program." << endl;
    exit(1);
  }
}


void trading(Civilization & civ){
  srand(time(NULL));
  int c;
  int food;
  int soldiers;
  int gained;
  int lost;
  int ag; // amount gained
  int al; // amount lost
    
  cout << "Possible civilizations to trade with: "<< endl;
  civ.random_civs();
  cout << "Who would you like to trade with? (1 - 3)" << endl;
  cout << "> ";
  cin >> c;
  cin.get();
  cout << "Items you own: " << endl;
  civ.display_inventory();
  cout << "Items you could trade for: "<< endl;
  civ.random_inventory(food, soldiers);
  cout << food << " food" << endl;
  cout << soldiers << " soldiers" << endl;
  cout << "Which item would you like? (1 - food, 2 - soldiers)" << endl;
  cout << "> ";
  cin >> gained;
  cin.get();
  cout << "How much?" << endl;
  cin >> ag;
  cin.get();
  if(gained == 1 && ag > food){
    cout << "Invalid trade. You selected more items than they own." << endl;
  }
  else if(gained == 2 && ag > soldiers){
    cout << "Invalid trade. You selected more items than you have." << endl;
  }
  else {
    cout << "What would you like to trade (of your own inventory)?" << endl;
    cout << "(1 - food, 2 - soldiers)" << endl;
    cout << "> ";
    cin >> lost;
    cin.get();
    cout << "How many? " << endl;
    cin >> al;
    cin.get();
    if(lost == 1 && (civ.compare_food(al) == false)){
      cout << "Invalid trade. You selected more items than you have." << endl;
    }
    else if(lost == 2 && (civ.compare_military(al) == false)){
      cout << "Invalid trade. You selected more items than you have." << endl;
    }
    else {
      //rng if successful or not
      int success = rand() % 10;
      if(success % 2 == 0){
	civ.trade(lost, al, gained, ag);
      }
    }
  }
}
