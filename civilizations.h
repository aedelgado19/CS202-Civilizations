/* Author: Allison Delgado
   Class: CS 202 Summer 2021
   civilizations.h contains the prototypes of the functions
   for the three civilization types: agricultural, military, and industrial.
   This file also contains the Civilization class
   which the three civilizations inherit, and the DLL class that the
   three civilizations are stored in.

   Last updated: July 19, 2021
*/
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <stdlib.h>
#include <vector>

// ************** BASE CLASS: CIVILIZATION *******************

class Civilization {
public:
  Civilization(); //constructor
  ~Civilization();
  Civilization(const Civilization & source);
  void read(); //fill in fields for the civilization
  void display(); //display details of the civilization
  virtual void buy(std::string to_buy, int amount) = 0; //buy goods from market
  virtual void sell(std::string to_sell, int amount) = 0; //sell goods to market in exchange for money
  virtual void trade(std::string civilization, std::string item) = 0; //civilization is the other civilization you wish to trade with, item is what to trade
  void display_market();
protected:
  char* name;
  int population;

 private:
  void set_up_market(); //fills market with items
  std::vector<std::string> items;
};

// ************** CIVILIZATION: AGRICULTURE  ******************

class Agriculture : public Civilization {
public:
  Agriculture();
  ~Agriculture();
  void buy(std::string to_buy, int amount);
  void sell(std::string to_sell, int amount);
  void trade(std::string civilization, std::string item);
  
  //specifically agriculture functions:
  bool harvest(); //harvest crops. The bool determines success based on crop status
  int check_on_crops(); //randomly generates 0 or 1 to see if the crops are ready to harvest
  void plant_plots(); //plant more another plot of crops (requires money, but you can have multiple instances of crops growing at the same time).
  
 private:
  int crop_status; // 0 = not ready to harvest, 1 = ready to harvest
  int money; //how much money you have
  std::vector<std::string> to_sell; //vector of items you can sell (once you harvest a crop, it is added here as a potential item to sell/trade)
  std::vector<std::string> inventory;
};

// ************** CIVILIZATION: MILITARY  ******************

class Military : public Civilization {
public:
  Military();
  ~Military();
  void buy(std::string to_buy, int amount);
  void sell(std::string to_sell, int amount);
  void trade(std::string civilization, std::string item);

  //specifically military functions:
  void train_troops(); //gain more soldiers
  void feed_troops(); //you must feed troops every round or you lose soldiers
private:
  int troops; //amount of soldiers
  int money; //amount of money you have
  std::vector<std::string> inventory; //holds any items you bought or traded for
};

// ************** CIVILIZATION: INDUSTRY  ******************

class Industry : public Civilization {
public:
  Industry();
  ~Industry();
  void buy(std::string to_buy, int amount);
  void sell(std::string to_sell, int amount);
  void trade(std::string civilization, std::string item);

  //specifically industry functions
  void produce_new_product(); //create a new product you can produce
  void check_status(); //check on production of products
private:
  int money;
  std::vector<std::string> products; //you can sell or trade these
  std::vector<std::string> inventory; //holds whatever you buy
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
  void remove(const Civilization *& civ); //remove from DLL
  void display();
  void remove_all(); //clear from DLL
private:
  void insert(Node * current, Node *& to_add); //recursive insert
  void remove(Node * current, Node *& to_remove); //recursive remove
  void display(Node * current); //recursive display
  void remove_all(Node *& current); //recursive remove all
  Node ** head;
};
