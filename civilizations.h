/* Author: Allison Delgado
   Class: CS 202 Summer 2021
   civilizations.h contains the prototypes of the functions
   for the three civilization types: agricultural, military, and industrial.
   This file also contains the Civilization class
   which the three civilizations inherit, and the DLL class that the
   three civilizations are stored in.

   Last updated: July 22, 2021
*/
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <math.h>

// ************** BASE CLASS: CIVILIZATION *******************

class Civilization {
public:
  Civilization(int f, int m, int s); //constructor (food, money, soldiers)
  virtual ~Civilization();
  Civilization(const Civilization & source);
  void read(); //fill in fields for the civilization
  void display(); //display details of the civilization
  virtual void buy(const std::string & to_buy, int amount) = 0; //buy goods from market
  virtual void sell(const std::string & to_sell, int amount) = 0; //sell goods to market in exchange for money
  virtual void trade(int lost, int al, int gained, int ag) = 0; //lost is what you gave, al is how much you lost, gained is what you gained and ag is how much of that item you gained
  bool check_money(int item, int amount);
  void display_market(); //displays items you can buy
  bool display_inventory();
  void random_civs(); //prints out random civilization names
  void random_inventory(int & food, int & soldiers); //print out a random inventory amounts (used in trading)
  bool compare_food(int i); //compares food passed in to civ's food 
  bool compare_military(int i); //compares military passed in to civ's military
  bool compare_action();
  void required_action();
  void failed_to_do_action(int civ);
protected:
  char* name;
  int food;
  int money; //how much money you have
  int military; // how much protection your civilization has
  int m_food; //market food
  int m_military; //market soldiers
  bool required_action_done;
};

// ************** CIVILIZATION: AGRICULTURE  ******************

class Agriculture : public Civilization {
public:
  Agriculture();
  void buy(const std::string & to_buy, int amount);
  void sell(const std::string & to_sell, int amount);
  void trade(int lost, int al, int gained, int ag);
  //specifically agriculture functions:
  void harvest(); //harvest crops.
  void water_crops(); //required every turn
  void plant_plots(); //plant more another plot of crops (requires money, but you can have multiple instances of crops growing at the same time).
  
 private:
  int amount_of_plots;
  std::vector<std::string> to_sell; //vector of items you can sell (once you harvest a crop, it is added here as a potential item to sell/trade)
};

// ************** CIVILIZATION: MILITARY  ******************

class Military : public Civilization {
public:
  Military();
  void buy(const std::string & to_buy, int amount);
  void sell(const std::string & to_sell, int amount);
  void trade(int lost, int al, int gained, int ag);
 
  //specifically military functions:
  void train_troops(); //gain more soldiers
  void feed_troops(); //you must feed troops every round or you lose soldiers
  void wage_war(); //potentially gain resources but RNG how many soldiers you lose
private:
  int troops; //amount of soldiers
};

// ************** CIVILIZATION: INDUSTRY  ******************

class Industry : public Civilization {
public:
  Industry();
  void buy(const std::string & to_buy, int amount);
  void sell(const std::string & to_sell, int amount);
  void trade(int lost, int al, int gained, int ag);
 
  //specifically industry functions
  void produce_new_product(); //create a new product you can produce
  void check_status(); //check on production of products
  void work(); //required every turn. Produces exisitng products
private:
  std::vector<std::string> products; //you can sell or trade these
};


// ************** DATA STRUCTURE: DLL ******************
class Node {
  Node();
  Node(const Civilization & source);
  Node *& go_next(); //go to the next node
  void set_next(Node *& next);
  void set_prev(Node *& prev);
private:
  Node * next;
  Node * prev;
  Civilization * civ;
};

class DLL {
public:
  DLL();
  ~DLL();
  DLL(const DLL & source); // copy constructor
  void insert(const Civilization *& civ); //insert to DLL
  void remove(char* name); //remove from DLL
  void display();
  void remove_all(); //clear from DLL
private:
  void insert(Node * current, Node *& to_add); //recursive insert
  void remove(Node * current, char* to_remove); //recursive remove
  void display(Node * current); //recursive display
  void remove_all(Node *& current); //recursive remove all
  Node ** head;
};
