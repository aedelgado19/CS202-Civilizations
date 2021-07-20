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

//base class
class Civilization {
public:
  Civilization(); //constructor
  void read(); //fill in fields for the civilization
  void display(); //display details of the civilization
  virtual void buy(std::string to_buy, int amount); //buy goods from market
  virtual void sell(std::string to_sell, int amount); //sell goods to market in exchange for money
  virtual void trade(std::string civilization, std::string item); //civilization is the other civilization you wish to trade with, item is what to trade
  void display_market();
protected:
  std::string name;
  int population;

 private:
  void set_up_market(); //fills market with items
  std::vector<std::string> items;
};

class Agriculture : public Civilization {
public:
  Agriculture();
  ~Agriculture();
  Agriculture(const Agriculture & source); //copy constructor
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


