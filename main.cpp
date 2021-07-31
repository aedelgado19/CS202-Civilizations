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

void gameplay(int civ, int round, Agriculture & a, Military & m, Industry & i, char* an, char* mn, char* in);
void agriculture(int c, Agriculture & a);
void military(int c, Military & m);
void industry(int c, Industry & i);
void rules();
void trading(Civilization & civ);
void data_structure(DLL & dll);

int main(){
  DLL dll;
  char yn;
  char ds;
  int choice;
  Agriculture a;
  Military m;
  Industry i;
  char an[50]; //agr name
  char mn[50]; //mil name
  char in[50]; //ind name
  
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
  cout << "Please choose a civilization to start with:" << endl;
  cout << "1 - agriculture" << endl;
  cout << "2 - military" << endl;
  cout << "3 - industry" << endl;
  cout << "> ";
  cin >> choice;
  cin.get();
  if(choice != 1 && choice != 2 && choice != 3){
    cout << "That was not one of the choices. Quitting program" << endl;
    return 0;
  }
  cout << " " << endl;
  cout << "Time to name all the civilizations. " << endl;
  cout << "Enter the name for your agricultural society: " << endl;
  cout << "> ";
  cin.get(an, 50);
  cin.get();
  cout << "Enter the name for your military society: " << endl;
  cout << "> ";
  cin.get(mn, 50);
  cin.get();
  cout << "Enter the name for your industrial society: " << endl;
  cout << "> ";
  cin.get(in, 50);
  cin.get();
  cout << "========================================" << endl;
  cout << " " << endl;
  cout << "The default game has 3 civilizations. " << endl;
  cout << "for DS testing, would you like to alter this? (y/n)" << endl;
  cout  << "> ";
  cin >> ds;
  cin.get();
  if(ds == 'y'){
    data_structure(dll);
  }
  gameplay(choice, 0, a, m, i, an, mn, in);
  return 0;
}

void data_structure(DLL & dll){
  int choice;
  int type;
  char name[50];
  
  cout << "Choose an option: " << endl;
  cout << "1 - insert a new civilization" << endl;
  cout << "2 - remove a civilization" << endl;
  cout << "3 - display all civilizations" << endl;
  cout << "4 - remove all civilizations (also ends game)" << endl;
  cout << " " << endl;
  cout << "> ";
  cin >> choice;
  cin.get();

  if(choice == 1){
    cout << "What kind of civilization would you like to add? " << endl;
    cout << "1 - agriculture" << endl;
    cout << "2 - military" << endl;
    cout << "3 - industry" << endl;
    cout << "> ";
    cin >> type;
    cin.get();
    cout << "What would you like to call this civilization? " << endl;
    cout << "> ";
    cin.get(name, 50);
    cin.get();

    if(type == 1){
      Agriculture * agr;
      dll.insert(agr, choice);
    } else if(type == 2){
      Military * mil;
      dll.insert(mil, choice);
    } else if(type == 3){
      Industry * ind;
      dll.insert(ind, choice);
    }
  } else if(choice == 2){
    char n[50];
    cout << "What is the name of the civilization you'd like to remove? " << endl;
    cout << "> ";
    cin.get(n, 50);
    cin.get();
    dll.remove(n);
  } else if(choice == 3){
    dll.display();
  } else if(choice == 4) {
    dll.remove_all();
    exit(1);
  } else {
    cout << "That was not one of the choices. " << endl;
  }
}

//print out the rules of the game
void rules(){
  char yn;
  
  cout << "In this game, you can play as three civilizations: agricultural, " << endl;
  cout << "military, or industrial. Each has their own " << endl;
  cout << "strengths and weaknesses. The game has 5 rounds. In each round, " << endl;
  cout << "you will have 2 actions to play, and one required " << endl;
  cout << "action that depends on your specific civilization. " << endl;
  cout << "If you do not do the required action, you may lose points." << endl;
  cout << "You gain points for having a lot of money, military, and food. The " << endl;
  cout << "civilization that has the most points at the " << endl;
  cout << "end of the 5 rounds wins. " << endl;
  cout << " " << endl;
  cout << "PRICES ON THE MARKET: " << endl;
  cout << "   $10 per soldier" << endl;
  cout << "   $4 per meat" << endl;
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
    cout << "   you can gain bonus points in the end" << endl;
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
void gameplay(int civ, int round, Agriculture & a, Military & m, Industry & i, char* an, char* mn, char* in){
  int choice;

  for(int turn = 0; turn < 3; turn++){
    if(civ == AGR) a.display(an);
    if(civ == MIL) m.display(mn);
    if(civ == IND) i.display(in);

    cout << "Pick three actions to do (don't forget about your required one!)" << endl;
    cout << "1 - buy goods from the market" << endl;
    cout << "2 - sell items" << endl;
    cout << "3 - trade" << endl;

    //civilization specific:
    if(civ == AGR){
      a.required_action(1);
      cout << "4 - harvest crops" << endl;
      cout << "5 - plant more plots" << endl;
      cout << "6 - REQUIRED: water crops" << endl;
      cin >> choice;
      cin.get();
      agriculture(choice, a);
      if(turn == 3 && (a.compare_action() == false)){
	a.failed_to_do_action(1);
      }
    }
    else if(civ == MIL){
      m.required_action(1);
      cout << "4 - train more troops" << endl;
      cout << "5 - wage war" << endl;
      cout << "6 - REQUIRED: feed troops" << endl;
      cin >> choice;
      cin.get();
      military(choice, m);
      if(turn == 3 && (m.compare_action() == false)){
	m.failed_to_do_action(2);
      }
    }
    else {
      i.required_action(1);
      cout << "4 - produce a new product" << endl;
      cout << "5 - REQUIRED: go to work" << endl;
      cin >> choice;
      cin.get();
      industry(choice, i);
      if(turn == 3 && (i.compare_action() == false)){
	i.failed_to_do_action(3);
      }
    }
  }
  if(round < 5){
    int new_civ = (civ + 1) % 3;
    cout << "=======================================" << endl;
    cout << "             next turn! " << endl;
    cout << "=======================================" << endl;
    gameplay(new_civ, round + 1, a, m, i, an, mn, in);
  } else {
    cout << "Awesome work! Game over. Here are the point totals: " << endl;
    cout << "  Agricultural Society points: " << endl;
    int ap = a.calculate();
    cout << "  Military Society points: " << endl;
    int mp = m.calculate();
    cout << "  Industrial Society points: " << endl;
    int ip = i.calculate();
    if(ap > mp && ap > ip){ //agricultural win
      cout << " " << endl;
      cout << "WINNER: AGRICULTURAL SOCIETY!" << endl;
    }
    else if(mp > ap && mp > ip){ //military win
      cout << " " << endl;
      cout << "WINNER: MILITARY SOCIETY!" << endl;
    }
    else {
      cout << " " << endl;
      cout << "WINNER: INDUSTRIAL SOCIETY!" << endl;
    }
  }
}

//Agriculture functions
void agriculture(int c, Agriculture & a){
  if(c == 1){
    string purchase;
    int amount;
    cout << "-------------------" << endl;
    cout << "   MARKET ITEMS: " << endl;
    cout << "-------------------" << endl;
    a.display_market();
    cout << "-------------------" << endl;
    cout << "   MARKET PRICES: " << endl;
    cout << "-------------------" << endl;
    cout << "   1 soldier = $10" << endl;
    cout << "   1 meat = $4" << endl;
    cout << " " << endl;
    cout << "What would you like to buy? " << endl;
    cout << "> ";
    getline(cin, purchase);
    cout << "How much " << purchase << " would you like to buy?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    a.buy(purchase, amount);
    a.display_inventory(true);
  }
  else if(c == 2){
    string sell;
    int amount;
    bool valid = a.display_inventory(false);
    if(valid == false){
      cout << "You don't have anything to sell!" << endl;
    } else {
      cout << "What would you like to sell?" << endl;
      cout << "> ";
      getline(cin, sell);
      cout << "How much " << sell << " would you like to sell?" << endl;
      cin >> amount;
      cin.get();
      a.sell(sell, amount);
      a.display_inventory(true);
    }
  }
  else if(c == 3){
    trading(a);
    cout << " " << endl;
  }
  else if(c == 4){
    a.harvest();
    cout << " " << endl;
  }
  else if(c == 5){
    a.plant_plots();
    cout << " " << endl;
  }
  else if(c == 6){
    a.water_crops();
    a.required_action(2);
    cout << " " << endl;
  }
  else {
    cout << "That was not one of the choices. Quitting program." << endl;
    cout << " " << endl;
    exit(1);
  }
}

//military functions
void military(int c, Military & m){
  if(c == 1){
    string purchase;
    int amount;

    cout << "-------------------" << endl;
    cout << "   MARKET ITEMS: " << endl;
    cout << "-------------------" << endl;
    m.display_market();
    cout << "-------------------" << endl;
    cout << "   MARKET PRICES: " << endl;
    cout << "-------------------" << endl;
    cout << "   1 soldier = $10" << endl;
    cout << "   1 meat = $4" << endl;
    cout << " " << endl;
    cout << "What would you like to buy? " << endl;
    cout << "> ";
    getline(cin, purchase);
    cout << "How much " << purchase << " would you like to buy?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    m.buy(purchase, amount);
    m.display_inventory(true);
  }
  else if(c == 2){
    string sell;
    int amount;
    bool valid = m.display_inventory(false);
    if(valid == false){
      cout << "You don't have anything to sell!" << endl;
    } else {
      cout << "What would you like to sell?" << endl;
      cout << "> ";
      getline(cin, sell);
      cout << "How much " << sell << " would you like to sell?" << endl;
      cin >> amount;
      cin.get();
      m.sell(sell, amount);
      m.display_inventory(true);
      cout << " " << endl;
    }
  }
  else if(c == 3){
    trading(m);
    cout << " " << endl;
  }
  else if(c == 4){
    m.train_troops();
    cout << " " << endl;
  }
  else if(c == 5){
    m.wage_war();
    cout << " " << endl;
  }
  else if(c == 6){
    m.feed_troops();
    m.required_action(2);
    cout << " " << endl;
  }
  else {
    cout << "That was not one of the choices. Quitting program." << endl;
    cout << " " << endl;
    exit(1);
  }
}

//industry functions
void industry(int c, Industry & i){
  if(c == 1){
    string purchase;
    int amount;

    cout << "-------------------" << endl;
    cout << "   MARKET ITEMS: " << endl;
    cout << "-------------------" << endl;
    i.display_market();
    cout << "-------------------" << endl;
    cout << "   MARKET PRICES: " << endl;
    cout << "-------------------" << endl;
    cout << "   1 soldier = $10" << endl;
    cout << "   1 meat = $4" << endl;
    cout << " " << endl;
    cout << "What would you like to buy? " << endl;
    cout << "> ";
    getline(cin, purchase);
    cout << "How much " << purchase << " would you like to buy?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    i.buy(purchase, amount);
    i.display_inventory(true);
  }
  else if(c == 2){
    string sell;
    int amount;
    bool valid = i.display_inventory(false);
    if(valid == false){
      cout << "You don't have anything to sell!" << endl;
    } else {
      cout << "What would you like to sell?" << endl;
      cout << "> ";
      getline(cin, sell);
      cout << "How much " << sell << " would you like to sell?" << endl;
      cin >> amount;
      cin.get();
      i.sell(sell, amount);
      i.display_inventory(true);
    }

  }
  else if(c == 3){
    trading(i);
    cout << " " << endl;
  }
  else if(c == 4){
    i.produce_new_product();
    cout << " " << endl;
  }
  else if(c == 5){
    i.work();
    i.required_action(2);
    cout << " " << endl;
  }
  else {
    cout << "That was not one of the choices. Quitting program." << endl;
    cout << " " << endl;
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
  civ.display_inventory(false);
  cout << " " << endl;
  cout << "----------------------" << endl;
  cout << "Items you could trade for: "<< endl;
  civ.random_inventory(food, soldiers);
  cout << "   " << food << " food" << endl;
  cout << "   " << soldiers << " soldiers" << endl;
  cout << "----------------------" << endl;
  cout << " " << endl;
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
