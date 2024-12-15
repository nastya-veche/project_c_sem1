#include "backend.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <random>
#include <string>
#include <utility>
#include <vector>
using namespace std;

void Player::data_changed(string _name, int diff, int number, int mode)
{
  if (mode == 1 and number == 0)
  {
    name = "Computer";
    is_computer = true;
  }
  else
    name = _name;

  int count_of_our_chips = 6;
  int count_of_another_chips = 0;

  int i;

  if (diff == 1)
  {
    count_of_our_chips = 3 * number;
    count_of_another_chips = 3 - count_of_our_chips;
  }
  else if (diff == 2)
  {
    count_of_our_chips = 6 * number;
    count_of_another_chips = 6 - count_of_our_chips;
  }
  else
  {
    count_of_our_chips = 3;
    count_of_another_chips = 3;
  }

  vector<int> pack;
  int randomNum;
  auto it = find(pack.begin(), pack.end(), randomNum);

  while (pack.size() < count_of_our_chips)
  {
    randomNum = rand() % 6;
    it = find(pack.begin(), pack.end(), randomNum);
    if (it == pack.end())
      pack.push_back(randomNum);
  }

  while (pack.size() < count_of_our_chips + count_of_another_chips)
  {
    randomNum = 6 + rand() % 6;
    it = find(pack.begin(), pack.end(), randomNum);
    if (it == pack.end())
      pack.push_back(randomNum);
  }
  pack_of_chips = pack;
  size_of_pack = pack.size();
  various = diff;
}

vector<pair<int, int>> Player::strike(vector<vector<int>> field)
{
  auto it = find(pack_of_chips.begin(), pack_of_chips.end(), 0);

  int pre_count;
  int pre_quantity;
  int required_quantity;
  int i, j, k, q;
  if (various == 3)
    required_quantity = 4;
  else
    required_quantity = 3;

  vector<pair<int, int>> delete_pack;

  int size_of_field = field.size();

  for (i = 0; i < size_of_field; ++i)  // horizontal
  {
    pre_count = field[i][0];
    pre_quantity = 0;

    for (j = 0; j < size_of_field; ++j)
    {
      if (field[i][j] == pre_count)
        ++pre_quantity;
      else
      {
        it = find(pack_of_chips.begin(), pack_of_chips.end(), pre_count);
        if (it != pack_of_chips.end() and pre_quantity >= required_quantity)
          for (k = pre_quantity; k > 0; --k)
          {
            delete_pack.push_back(
                pair<int, int>(i, j - pre_quantity + k - 1));
          }
        pre_quantity = 1;
        pre_count = field[i][j];
      }
    }

    it = find(pack_of_chips.begin(), pack_of_chips.end(), pre_count);
    if (it != pack_of_chips.end() and pre_quantity >= required_quantity)
    {
      for (k = pre_quantity; k > 0; --k)
        delete_pack.push_back(pair<int, int>(i, j - pre_quantity + k - 1));
    }
  }

  for (j = 0; j < size_of_field; ++j)  // vertical
  {

    pre_count = field[0][j];
    pre_quantity = 0;

    for (i = 0; i < size_of_field; ++i)
    {
      if (field[i][j] == pre_count)
        ++pre_quantity;
      else
      {
        it = find(pack_of_chips.begin(), pack_of_chips.end(), pre_count);
        if (it != pack_of_chips.end() and pre_quantity >= required_quantity)
        {
          for (k = pre_quantity; k > 0; --k)
            delete_pack.push_back(
                pair<int, int>(i - pre_quantity + k - 1, j));
        }
        pre_quantity = 1;
        pre_count = field[i][j];
      }
    }

    it = find(pack_of_chips.begin(), pack_of_chips.end(), pre_count);
    if (it != pack_of_chips.end() and pre_quantity >= required_quantity)
    {
      for (k = pre_quantity; k > 0; --k)
        delete_pack.push_back(pair<int, int>(i - pre_quantity + k - 1, j));
    }
  }

  if (various != 3)
  {

    for (q = 0; q < size_of_field; ++q)
    {

      pre_count = field[q][0];
      pre_quantity = 0;
      i = q;
      j = 0;

      while (i < size_of_field and j < size_of_field)
      {
        if (field[i][j] == pre_count)
          ++pre_quantity;
        else
        {
          it = find(pack_of_chips.begin(), pack_of_chips.end(), pre_count);
          if (it != pack_of_chips.end() and
              pre_quantity >= required_quantity)
            for (k = pre_quantity; k > 0; --k)
              delete_pack.push_back(pair<int, int>(
                  i - pre_quantity + k - 1, j - pre_quantity + k - 1));
          pre_quantity = 1;
          pre_count = field[i][j];
        }
        ++i;
        ++j;
      }

      it = find(pack_of_chips.begin(), pack_of_chips.end(), pre_count);
      if (it != pack_of_chips.end() and pre_quantity >= required_quantity)
        for (k = pre_quantity; k > 0; --k)
          delete_pack.push_back(pair<int, int>(i - pre_quantity + k - 1,
                                               j - pre_quantity + k - 1));
    }

    for (q = 0; q < size_of_field; ++q)
    {

      pre_count = field[0][q];
      pre_quantity = 0;
      i = 0;
      j = q;

      while (i < size_of_field and j < size_of_field)
      {
        if (field[i][j] == pre_count)
          ++pre_quantity;
        else
        {
          it = find(pack_of_chips.begin(), pack_of_chips.end(), pre_count);
          if (it != pack_of_chips.end() and
              pre_quantity >= required_quantity)
            for (k = pre_quantity; k > 0; --k)
              delete_pack.push_back(pair<int, int>(
                  i - pre_quantity + k - 1, j - pre_quantity + k - 1));
          pre_quantity = 1;
          pre_count = field[i][j];
        }
        ++i;
        ++j;
      }

      it = find(pack_of_chips.begin(), pack_of_chips.end(), pre_count);
      if (it != pack_of_chips.end() and pre_quantity >= required_quantity)
        for (k = pre_quantity; k > 0; --k)
          delete_pack.push_back(pair<int, int>(i - pre_quantity + k - 1,
                                               j - pre_quantity + k - 1));
    }

    for (q = 0; q < size_of_field; ++q)
    {

      pre_count = field[q][0];
      pre_quantity = 0;
      i = q;
      j = 0;

      while (i >= 0 and j < size_of_field)
      {
        if (field[i][j] == pre_count)
          ++pre_quantity;
        else
        {
          it = find(pack_of_chips.begin(), pack_of_chips.end(), pre_count);
          if (it != pack_of_chips.end() and
              pre_quantity >= required_quantity)
            for (k = pre_quantity; k > 0; --k)
              delete_pack.push_back(pair<int, int>(
                  i + pre_quantity - k + 1, j - pre_quantity + k - 1));
          pre_quantity = 1;
          pre_count = field[i][j];
        }
        --i;
        ++j;
      }

      it = find(pack_of_chips.begin(), pack_of_chips.end(), pre_count);
      if (it != pack_of_chips.end() and pre_quantity >= required_quantity)
        for (k = pre_quantity; k > 0; --k)
          delete_pack.push_back(pair<int, int>(i + pre_quantity - k + 1,
                                               j - pre_quantity + k - 1));
    }

    for (q = 0; q < size_of_field; ++q)
    {

      pre_count = field[size_of_field - 1][q];
      pre_quantity = 0;
      i = size_of_field - 1;
      j = q;

      while (i >= 0 and j < size_of_field)
      {
        if (field[i][j] == pre_count)
          ++pre_quantity;
        else
        {
          it = find(pack_of_chips.begin(), pack_of_chips.end(), pre_count);
          if (it != pack_of_chips.end() and
              pre_quantity >= required_quantity)
            for (k = pre_quantity; k > 0; --k)
              delete_pack.push_back(pair<int, int>(
                  i + pre_quantity - k + 1, j - pre_quantity + k - 1));
          pre_quantity = 1;
          pre_count = field[i][j];
        }
        --i;
        ++j;
      }

      it = find(pack_of_chips.begin(), pack_of_chips.end(), pre_count);
      if (it != pack_of_chips.end() and pre_quantity >= required_quantity)
        for (k = pre_quantity; k > 0; --k)
          delete_pack.push_back(pair<int, int>(i + pre_quantity - k + 1,
                                               j - pre_quantity + k - 1));
    }
  }
  balance = balance + delete_pack.size();
  return delete_pack;
}

pair<int, int> Player::calculate_the_move(vector<vector<int>> field,
                                          int type)
{
  vector<pair<int, int>> delete_pack;
  pair<int, int> coord;
  pair<int, int> new_coord;
  coord.first = -1;
  bool anti_player;
  int max_s = 0;
  if (is_computer)
  {

    for (int i = 0; i < field.size(); ++i)
    {
      for (int j = 0; j < field.size(); ++j)
      {
        if (field[i][j] == -1)
        {
          field[i][j] = type;
          delete_pack = strike(field);
          if (delete_pack.size() > max_s)
          {
            max_s = delete_pack.size();
            coord.first = i;
            coord.second = j;
          }
          field[i][j] = -1;
        }
      }
    }

    if (max_s == 0)
    {
      max_s = 100;
      int required_quantity;
      if (various == 3)
        required_quantity = 4;
      else
        required_quantity = 3;
      bool exist_of_cell;
      int min_moves;

      for (int i = 0; i < field.size();
           ++i)  // where free cells in horizontal
      {
        for (int j = 0; j < field.size() - required_quantity + 1; ++j)
        {
          exist_of_cell = true;
          min_moves = 0;
          anti_player = true;
          for (int k = 0; k < required_quantity; ++k)
          {
            if (field[i][j + k] != -1 and field[i][j + k] != type)
              exist_of_cell = false;
            else if (field[i][j + k] == -1)
            {
              ++min_moves;
              new_coord.second = j + k;
            }
            if (field[i][j + k] != -1 and field[i][j + k] != field[i][j])
              anti_player = false;
          }
          if (anti_player and min_moves == 1)
          {
            coord.first = i;
            coord.second = new_coord.second;
            return coord;
          }
          else if (exist_of_cell and min_moves < max_s)
          {
            coord.first = i;
            coord.second = new_coord.second;
            max_s = min_moves;
          }
        }
      }

      for (int j = 0; j < field.size();
           ++j)  // where free cells in vertical
      {
        for (int i = 0; i < field.size() - required_quantity + 1; ++i)
        {
          exist_of_cell = true;
          min_moves = 0;
          anti_player = true;
          for (int k = 0; k < required_quantity; ++k)
          {
            if (field[i + k][j] != -1 and field[i + k][j] != type)
              exist_of_cell = false;
            else if (field[i + k][j] == -1)
            {
              ++min_moves;
              new_coord.first = i + k;
            }
            if (field[i + k][j] != -1 and field[i + k][j] != field[i][j])
              anti_player = false;
          }
          if (anti_player and min_moves == 1)
          {
            coord.first = new_coord.first;
            coord.second = j;
            return coord;
          }
          else if (exist_of_cell and min_moves < max_s)
          {
            coord.first = new_coord.first;
            coord.second = j;
            max_s = min_moves;
          }
        }
      }

      if (various != 3)  // where free cells in diagonal
      {
        int q, i, j;
        int size_of_field = field.size();
        for (q = 0; q < size_of_field; ++q)
        {
          i = q;
          j = 0;
          while (i < size_of_field - required_quantity + 1 and
                 j < size_of_field - required_quantity + 1)
          {
            exist_of_cell = true;
            min_moves = 0;
            anti_player = true;
            for (int k = 0; k < required_quantity; ++k)
            {
              if (field[i + k][j + k] != -1 and field[i + k][j + k] != type)
                exist_of_cell = false;
              else if (field[i + k][j + k] == -1)
              {
                ++min_moves;
                new_coord.first = i + k;
                new_coord.second = j + k;
              }
              if (field[i + k][j + k] != -1 and
                  field[i + k][j + k] != field[i][j])
                anti_player = false;
            }
            if (anti_player and min_moves == 1)
            {
              coord.first = new_coord.first;
              coord.second = new_coord.second;
              return coord;
            }
            else if (exist_of_cell and min_moves < max_s)
            {
              coord.first = new_coord.first;
              coord.second = new_coord.second;
              max_s = min_moves;
            }

            ++i;
            ++j;
          }
        }

        for (q = 0; q < size_of_field; ++q)
        {
          i = 0;
          j = q;

          while (i < size_of_field - required_quantity + 1 and
                 j < size_of_field - required_quantity + 1)
          {
            exist_of_cell = true;
            min_moves = 0;
            anti_player = true;
            for (int k = 0; k < required_quantity; ++k)
            {
              if (field[i + k][j + k] != -1 and field[i + k][j + k] != type)
                exist_of_cell = false;
              else if (field[i + k][j + k] == -1)
              {
                ++min_moves;
                new_coord.first = i + k;
                new_coord.second = j + k;
              }
              if (field[i + k][j + k] != -1 and
                  field[i + k][j + k] != field[i][j])
                anti_player = false;
            }
            if (anti_player and min_moves == 1)
            {
              coord.first = new_coord.first;
              coord.second = new_coord.second;
              return coord;
            }
            else if (exist_of_cell and min_moves < max_s)
            {
              coord.first = new_coord.first;
              coord.second = new_coord.second;
              max_s = min_moves;
            }

            ++i;
            ++j;
          }
        }

        for (q = 0; q < size_of_field; ++q)
        {
          i = q;
          j = 0;

          while (i >= required_quantity - 1 and
                 j < size_of_field - required_quantity + 1)
          {
            exist_of_cell = true;
            min_moves = 0;
            anti_player = true;
            for (int k = 0; k < required_quantity; ++k)
            {
              if (field[i - k][j + k] != -1 and field[i - k][j + k] != type)
                exist_of_cell = false;
              else if (field[i - k][j + k] == -1)
              {
                ++min_moves;
                new_coord.first = i - k;
                new_coord.second = j + k;
              }
              if (field[i - k][j + k] != -1 and
                  field[i - k][j + k] != field[i][j])
                anti_player = false;
            }
            if (anti_player and min_moves == 1)
            {
              coord.first = new_coord.first;
              coord.second = new_coord.second;
              return coord;
            }
            else if (exist_of_cell and min_moves < max_s)
            {
              coord.first = new_coord.first;
              coord.second = new_coord.second;
              max_s = min_moves;
            }

            --i;
            ++j;
          }
        }

        for (q = 0; q < size_of_field; ++q)
        {
          i = size_of_field - 1;
          j = q;

          while (i >= required_quantity - 1 and
                 j < size_of_field - required_quantity + 1)
          {
            exist_of_cell = true;
            min_moves = 0;
            anti_player = true;
            for (int k = 0; k < required_quantity; ++k)
            {
              if (field[i - k][j + k] != -1 and field[i - k][j + k] != type)
                exist_of_cell = false;
              else if (field[i - k][j + k] == -1)
              {
                ++min_moves;
                new_coord.first = i - k;
                new_coord.second = j + k;
              }
              if (field[i - k][j + k] != -1 and
                  field[i - k][j + k] != field[i][j])
                anti_player = false;
            }
            if (anti_player and min_moves == 1)
            {
              coord.first = new_coord.first;
              coord.second = new_coord.second;
              return coord;
            }
            else if (exist_of_cell and min_moves < max_s)
            {
              coord.first = new_coord.first;
              coord.second = new_coord.second;
              max_s = min_moves;
            }

            --i;
            ++j;
          }
        }
      }
    }

    if (coord.first == -1)
    {
      for (int i = 0; i < field.size(); ++i)
      {
        for (int j = 0; j < field.size(); ++j)
        {
          if (field[i][j] == -1)
            return pair<int, int>(i, j);
        }
      }
    }
  }
  return coord;
}