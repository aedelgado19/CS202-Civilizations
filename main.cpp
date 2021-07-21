/* Author: Allison Delgado
   Class: CS 202 Summer 2021
   This project is a Civilization game in which the user can 
   build and play as different civilization types: agricultural,
   military, and industrial. Each civilization type has different
   strengths and weaknesses, starting resources, and skills.
   Main.cpp acts as the client for gameplay. The rules of
   the game play are displayed when the client runs the game
   and selects "rules".
   
   last updated: July 20, 2021
 */

#include <iostream>
#include "civilizations.h"
using namespace std;

#define AGR 1 //agriculture
#define MIL 2 //military
#define IND 3 //industry

void AI(int civ);
void gameplay(int civ, int round, char* name, Agriculture & a, Military & m, Industry & i);
void agriculture(int c, Agriculture & a);
void military(int c, Military & m);
void industry(int c, Industry & i);
void rules();

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
    cout << "   tip: choose the 'boost morale' option to increase " << endl;
    cout << "   military points" << endl;  
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
    cout << "5 - boost morale" << endl;
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
    
  }
  else if(c == 2){

  }
  else if(c == 3){

  }
  else if(c == 4){

  }
  else if(c == 5){

  }
  else if(c == 6){

  }
  else {
    cout << "That was not one of the choices. Quitting program." << endl;
    exit(1);
  }
}

//military functions
void military(int c, Military & m){
  if(c == 1){

  }
  else if(c == 2){

  }
  else if(c == 3){

  }
  else if(c == 4){

  }
  else if(c == 5){

  }
  else if(c == 6){

  }
  else {
    cout << "That was not one of the choices. Quitting program." << endl;
    exit(1);
  }

}

//industry functions
void industry(int c, Industry & i){
  if(c == 1){

  }
  else if(c == 2){

  }
  else if(c == 3){

  }
  else if(c == 4){

  }
  else if(c == 5){

  }
  else if(c == 6){

  }
  else {
    cout << "That was not one of the choices. Quitting program." << endl;
    exit(1);
  }
}
