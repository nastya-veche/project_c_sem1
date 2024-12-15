#ifndef BACKEND_H
#define BACKEND_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Player
{
public:
  vector<int> pack_of_chips;
  string name;
  int size_of_pack;
  int various;
  int balance = 0;
  bool is_computer = false;

  void data_changed (string namep, int diff, int number, int mode);
  vector<pair<int, int>> strike (vector<vector<int>> field);
  pair<int, int> calculate_the_move (vector<vector<int>> field, int type);
};

#endif