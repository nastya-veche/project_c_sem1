#include <iostream>
#include <string>
#include <utility>

#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>

#include "backend.h"
#include "frontend.h"
using namespace std;

#include <typeinfo>

Chip::Chip(Graph_lib::Point xy, int w, int h, const std::string& label,
           Graph_lib::Callback cb)
    : Graph_lib::Button{xy, w, h, "", cb}
{
  coords = pair<int, int>(3, 3);
}

Play_window::Play_window(Graph_lib::Point xy, int width, int height,
                         int _diff, string name1, string name2, int _mode,
                         int& _res1, int& _res2)
    : Graph_lib::Window{xy, width, height, "Play_window"},
      random{{space_w - 190, 80}, 50, 50, "Rand", cb_random_clicked},
      Current_field{{static_cast<int>(width * 1.0 / 8.0),
                     static_cast<int>(height / 5.0)},
                    70},
      commit{{500, window_h - 60}, 75, 50, "Commit", cb_commit_clicked},
      push_back{{600, window_h - 60}, 75, 50, "Back", cb_pushback_clicked},
      Buffer_1{{space_w - 300, static_cast<int>(height / 2.0)}, 300, 100},
      Buffer_2{
          {space_w - 300, static_cast<int>(height * 2.25 / 3.0)}, 300, 100},
      turn_play({space_w - 100, static_cast<int>(height * 2.0 / 5.0) - 50},
                100, 30, "Player's Move: "),
      balance_of_player1({static_cast<int>(width * 1.0 / 6.0),
                          static_cast<int>(height / 2.0) - 30},
                         200, 30, ""),
      balance_of_player2({static_cast<int>(width * 1.0 / 6.0),
                          static_cast<int>(height * 2.25 / 3.0) - 30},
                         200, 30, ""),
      new_chip{{static_cast<int>(width * 1.0 / 8.0),
                static_cast<int>(height / 5.0)},
               30},
      exit_end{{910, 10}, 75, 50, "Exit", cb_exit_end_button_clicked}

{
  attach(exit_end);

  res1 = &_res1;
  res2 = &_res2;

  vector<int> lc_f;
  for (int i = 0; i < _diff + 3; ++i)
    lc_f.push_back(-1);
  for (int j = 0; j < _diff + 3; ++j)
    FIELD.push_back(lc_f);

  new_chip.set_style(
      Graph_lib::Line_style(Graph_lib::Line_style::solid, 4));

  diff = _diff;
  mode = _mode;
  player1.data_changed(name1, diff, 1, mode);
  player2.data_changed(name2, diff, 0, mode);

  attach(random);
  attach(commit);
  attach(push_back);
  size_range(width, height, width, height);

  Current_field.set_style(
      Graph_lib::Line_style(Graph_lib::Line_style::solid, 4));
  Current_field.set_color(Graph_lib::Color::red);
  attach(Current_field);

  Buffer_1.set_style(
      Graph_lib::Line_style(Graph_lib::Line_style::solid, 4));
  Buffer_1.set_color(Graph_lib::Color::yellow);
  attach(Buffer_1);

  Buffer_2.set_style(
      Graph_lib::Line_style(Graph_lib::Line_style::solid, 4));
  Buffer_2.set_color(Graph_lib::Color::yellow);
  attach(Buffer_2);

  attach(turn_play);
  if (turn_count == 0)
    turn_play.put(player1.name);
  else
    turn_play.put(player2.name);

  attach(balance_of_player1);
  balance_of_player1.put(player1.name +
                         "'s balance: " + to_string(player1.balance));
  attach(balance_of_player2);
  balance_of_player2.put(player2.name +
                         "'s balance: " + to_string(player2.balance));

  for (int i = 0; i < player1.pack_of_chips.size(); ++i)
  {
    iso_chips.push_back(new Graph_lib::Circle{
        Graph_lib::Point{space_w - 300 + i * 45 + 30, height / 2 + 50},
        20});
    iso_chips[iso_chips.size() - 1].set_color(
        color[player1.pack_of_chips[i]]);
    iso_chips[iso_chips.size() - 1].set_style(
        Graph_lib::Line_style(Graph_lib::Line_style::solid, 4));
    attach(iso_chips[iso_chips.size() - 1]);
  }
  for (int i = 0; i < player2.pack_of_chips.size(); ++i)
  {
    iso_chips.push_back(
        new Graph_lib::Circle{Graph_lib::Point{space_w - 300 + i * 45 + 30,
                                               height * 2.25 / 3.0 + 50},
                              20});
    iso_chips[iso_chips.size() - 1].set_color(
        color[player2.pack_of_chips[i]]);
    iso_chips[iso_chips.size() - 1].set_style(
        Graph_lib::Line_style(Graph_lib::Line_style::solid, 4));
    attach(iso_chips[iso_chips.size() - 1]);
  }
  draw_field();
  next_walk();
}

void Play_window::next_walk()
{
  bool close_if = true;
  for (int i = 0; i < diff + 3; ++i)
  {
    for (int j = 0; j < diff + 3; ++j)
    {
      if (FIELD[i][j] == -1)
        close_if = false;
    }
  }
  if (not close_if)
  {
    if (turn_count == 0)
      turn_play.put(player1.name);
    else
      turn_play.put(player2.name);

    balance_of_player1.put(player1.name +
                           "'s balance: " + to_string(player1.balance));
    balance_of_player2.put(player2.name +
                           "'s balance: " + to_string(player2.balance));

    if (turn_count == 0)
      type_new_chip =
          player1.pack_of_chips[rand() % player1.pack_of_chips.size()];
    else
      type_new_chip =
          player2.pack_of_chips[rand() % player2.pack_of_chips.size()];
    new_color = color[type_new_chip];
    new_chip.set_color(new_color);
    attach(new_chip);
    Fl::redraw();
    if (mode == 1 and turn_count == 1)
    {
      new_coords = player2.calculate_the_move(FIELD, type_new_chip);
      attach(iso_field[new_coords.first * (diff + 3) + new_coords.second]);
      iso_field[new_coords.first * (diff + 3) + new_coords.second]
          .set_color(new_color);

      chip_on_field = false;
      FIELD[new_coords.first][new_coords.second] = type_new_chip;
      vector<pair<int, int>> delete_pack;
      if (turn_count == 0)
        delete_pack = player1.strike(FIELD);
      else
        delete_pack = player2.strike(FIELD);

      for (unsigned i{0}; i < delete_pack.size(); ++i)
      {
        detach(iso_field[delete_pack[i].first * (diff + 3) +
                         delete_pack[i].second]);
        FIELD[delete_pack[i].first][delete_pack[i].second] = -1;
      }
      turn_count = (turn_count + 1) % 2;
      Fl::redraw();

      next_walk();
    }
  }
  else
    close_win();
}

void Play_window::wait_for_interruption()
{
  Fl::run();
  Fl::redraw();
}

void Play_window::cb_commit_clicked(Graph_lib::Address,
                                    Graph_lib::Address pw)
{
  auto& ref = Graph_lib::reference_to<Graph_lib::Button>(pw).window();
  Graph_lib::reference_to<Play_window>(&ref).commit_bt();
}

void Play_window::commit_bt()
{
  if (chip_on_field == true and not(mode == 1 and turn_count == 1))
  {
    chip_on_field = false;
    FIELD[new_coords.first][new_coords.second] = type_new_chip;
    vector<pair<int, int>> delete_pack;
    if (turn_count == 0)
      delete_pack = player1.strike(FIELD);
    else
      delete_pack = player2.strike(FIELD);
    for (unsigned i{0}; i < delete_pack.size(); ++i)
    {
      detach(iso_field[delete_pack[i].first * (diff + 3) +
                       delete_pack[i].second]);
      FIELD[delete_pack[i].first][delete_pack[i].second] = -1;
    }
    turn_count = (turn_count + 1) % 2;
    Fl::redraw();
    next_walk();
  }
}

void Play_window::cb_random_clicked(Graph_lib::Address,
                                    Graph_lib::Address pw)
{
  auto& ref = Graph_lib::reference_to<Graph_lib::Button>(pw).window();
  Graph_lib::reference_to<Play_window>(&ref).random_bt();
}

void Play_window::random_bt()
{
  if (chip_on_field == false and not(mode == 1 and turn_count == 1))
  {
    auto old_type_new_chip{type_new_chip};
    srand(time(0));
    if (turn_count == 0 and player1.balance >= diff)
    {
      player1.balance = player1.balance - diff;
      while (old_type_new_chip == type_new_chip)
      {
        type_new_chip =
            player1.pack_of_chips[rand() % player1.pack_of_chips.size()];
      }
      balance_of_player1.put(player1.name +
                             "'s balance: " + to_string(player1.balance));
    }
    else if (turn_count == 1 and player2.balance >= diff)
    {
      player2.balance = player2.balance - diff;
      while (old_type_new_chip == type_new_chip)
      {
        type_new_chip =
            player1.pack_of_chips[rand() % player1.pack_of_chips.size()];
      }
      balance_of_player2.put(player2.name +
                             "'s balance: " + to_string(player2.balance));
    }
    new_color = color[type_new_chip];
    new_chip.set_color(new_color);
    Fl::redraw();
  }
}

void Play_window::cb_pushback_clicked(Graph_lib::Address,
                                      Graph_lib::Address pw)
{
  auto& ref = Graph_lib::reference_to<Graph_lib::Button>(pw).window();
  Graph_lib::reference_to<Play_window>(&ref).pushback_bt();
}

void Play_window::pushback_bt()
{
  if (chip_on_field == true and not(mode == 1 and turn_count == 1))
  {
    chip_on_field = false;
    detach(iso_field[new_coords.first * (diff + 3) + new_coords.second]);
    attach(new_chip);
    Fl::redraw();
  }
}

void Play_window::cb_field_button_clicked(Graph_lib::Address,
                                          Graph_lib::Address pw)
{
  auto& btn = Graph_lib::reference_to<Chip>(pw);
  dynamic_cast<Play_window&>(btn.window()).put_chip(btn);
}

void Play_window::put_chip(Chip& chip)
{
  if (chip_on_field == false and not(mode == 1 and turn_count == 1) and
      FIELD[chip.coords.first][chip.coords.second] == -1)
  {
    attach(iso_field[chip.coords.first * (diff + 3) + chip.coords.second]);
    iso_field[chip.coords.first * (diff + 3) + chip.coords.second]
        .set_color(new_color);
    chip_on_field = true;
    new_coords.first = chip.coords.first;
    new_coords.second = chip.coords.second;
    detach(new_chip);
    Fl::redraw();
  }
}

void Play_window::cb_exit_end_button_clicked(Graph_lib::Address,
                                             Graph_lib::Address pw)
{
  auto& ref = Graph_lib::reference_to<Graph_lib::Button>(pw).window();
  Graph_lib::reference_to<Play_window>(&ref).close_win();
}

void Play_window::close_win()
{
  *res1 = player1.balance;
  *res2 = player2.balance;
  hide();
}

void Play_window::set_field(int amount)
{
  int n{std::min(amount, (field_size / min_button_size))};
  std::cout << n << std::endl;
  int cell_size;
  if (((field_size - field_space) / n) < min_button_size)
    cell_size = min_button_size;
  else
  {
    cell_size = (field_size - field_space) / n;
  };
  int y{(window_h - field_size) / 2 + field_space / 2};
  int x{space_w + static_cast<int>(field_space * 1.5)};
  for (unsigned i{1}; i <= (n * n); ++i)
  {
    field.push_back(new Chip{Graph_lib::Point{x, y}, cell_size, cell_size,
                             " ", cb_field_button_clicked});
    field[i - 1].coords.first = (i - 1) / n;
    field[i - 1].coords.second = (i - 1) % n;
    iso_field.push_back(new Graph_lib::Circle{
        Graph_lib::Point{x + cell_size / 2, y + cell_size / 2},
        cell_size / 4});
    iso_field[i - 1].set_style(
        Graph_lib::Line_style(Graph_lib::Line_style::solid, 4));
    if (i % n == 0)
    {
      x = (space_w + static_cast<int>(field_space * 1.5));
      y += cell_size;
    }
    else
    {
      x += cell_size;
    }
  }
}

void Play_window::draw_field()
{
  set_field(diff + 3);
  for (unsigned i{0}; i < field.size(); ++i)
  {
    attach(field[i]);
  }
}

void Main_window::change_to_play()
{
  detach(set_gamemode1);
  detach(set_gamemode2);
  detach(set_difficulty1);
  detach(set_difficulty2);
  detach(set_difficulty3);
  detach(gamemode);
  detach(difficulty);
  detach(run);
  attach(name_setter);
  attach(next);
}

Main_window::Main_window(Graph_lib::Point xy, int width, int height,
                         int& _mode, int& _diff, int& _action,
                         string& _name1, string& _name2, int pres1,
                         int pres2)
    : Graph_lib::Window{xy, width, height, "Main_window"},
      run{{static_cast<int>(width / 3.0) - 50,
           static_cast<int>(5 / 7.0 * height)},
          static_cast<int>(width / 3.0 + 100),
          static_cast<int>(1 / 7.0 * height),
          "Start game",
          cb_run_clicked},
      set_gamemode1{{static_cast<int>(width / 12), 250},
                    static_cast<int>(0.4 * width),
                    70,
                    "Singleplayer",
                    cb_set1_clicked},
      set_gamemode2{{static_cast<int>((11 / 12.0 - 0.4) * width), 250},
                    static_cast<int>(0.4 * width),
                    70,
                    "Multiplayer",
                    cb_set2_clicked},
      set_difficulty1{{static_cast<int>(width / 12.0), 120},
                      120,
                      70,
                      "easy",
                      cb_diff1_clicked},
      set_difficulty2{{static_cast<int>(width * 3 / 12.0), 120},
                      120,
                      70,
                      "normal",
                      cb_diff2_clicked},
      set_difficulty3{{static_cast<int>(width * 5 / 12.0), 120},
                      120,
                      70,
                      "hard",
                      cb_diff3_clicked},
      next{{static_cast<int>(width * 2.0 / 3.0),
            static_cast<int>(height / 2.0)},
           100,
           75,
           "Enter",
           cb_name_setter},
      difficulty{{static_cast<int>(width * 3.0 / 12.0), 60},
                 150,
                 40,
                 "Chosen difficulty: "},
      gamemode{{static_cast<int>(width * 3.0 / 12.0), 200},
               150,
               40,
               "Chosen gamemode: "},
      name_setter{{static_cast<int>(width * 1.0 / 3.0),
                   static_cast<int>(height * 0.75 / 2.0)},
                  static_cast<int>(width / 3.0),
                  75,
                  "Enter a name for player: "},
      Player1_name{{static_cast<int>(width * 1.0 / 6.0),
                    static_cast<int>(height / 2.0) - 10},
                   ""},
      res1{{static_cast<int>(600), static_cast<int>(80)}, ""},
      res2{{static_cast<int>(600), static_cast<int>(80 + 40)}, ""},
      res3{{static_cast<int>(600), static_cast<int>(80 + 80)}, ""},
      exit_end{{910, 10}, 75, 50, "Exit", cb_exit_end_button_clicked}

{
  attach(exit_end);
  mode = &_mode;
  diff = &_diff;
  action = &_action;
  name1 = &_name1;
  name2 = &_name2;
  attach(set_gamemode1);
  attach(set_gamemode2);
  attach(set_difficulty1);
  attach(set_difficulty2);
  attach(set_difficulty3);
  attach(gamemode);
  gamemode.put("Choose gamemode!");
  attach(difficulty);
  difficulty.put("Choose difficulty!");
  attach(run);
  size_range(width, height, width, height);
  if (pres1 != -1)
  {
    res1.set_color(Graph_lib::Color::red);
    res1.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 4));
    res1.set_font_size(30);
    res1.set_label("Result:");
    attach(res1);
    res2.set_color(Graph_lib::Color::red);
    res2.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 4));
    res2.set_font_size(25);
    res2.set_label(*name1 + ": " + to_string(pres1) + " vs " + *name2 +
                   ": " + to_string(pres2));
    attach(res2);
    res3.set_color(Graph_lib::Color::red);
    res3.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 4));
    res3.set_font_size(25);
    if (pres1 > pres2)
      res3.set_label("win " + *name1);
    else if (pres1 < pres2)
      res3.set_label("win " + *name2);
    else
      res3.set_label("win " + *name1 + " and " + *name2);
    attach(res3);
  }
}

void Main_window::wait_for_interruption()
{
  Fl::run();
  Fl::redraw();
}

void Main_window::cb_run_clicked(Graph_lib::Address, Graph_lib::Address pw)
{
  auto& ref = Graph_lib::reference_to<Graph_lib::Button>(pw).window();
  Graph_lib::reference_to<Main_window>(&ref).run_bt();
}

void Main_window::run_bt()
{
  detach(res1);
  detach(res2);
  detach(res3);
  detach(exit_end);
  *name1 = "";
  *name2 = "";
  if (1 <= *mode and *mode <= 2 and 1 <= *diff and *diff <= 3)
    change_to_play();
}

void Main_window::cb_set1_clicked(Graph_lib::Address, Graph_lib::Address pw)
{
  auto& ref = Graph_lib::reference_to<Graph_lib::Button>(pw).window();
  Graph_lib::reference_to<Main_window>(&ref).set_1_bt();
}

void Main_window::set_1_bt()
{
  *mode = 1;
  gamemode.put("singleplayer");
}

void Main_window::cb_set2_clicked(Graph_lib::Address, Graph_lib::Address pw)
{
  auto& ref = Graph_lib::reference_to<Graph_lib::Button>(pw).window();
  Graph_lib::reference_to<Main_window>(&ref).set_2_bt();
}

void Main_window::set_2_bt()
{
  *mode = 2;
  gamemode.put("multiplayer");
}

void Main_window::cb_diff1_clicked(Graph_lib::Address,
                                   Graph_lib::Address pw)
{
  auto& ref = Graph_lib::reference_to<Graph_lib::Button>(pw).window();
  Graph_lib::reference_to<Main_window>(&ref).set_diff_1_bt();
}

void Main_window::set_diff_1_bt()
{
  *diff = 1;
  difficulty.put("easy");
}

void Main_window::cb_diff2_clicked(Graph_lib::Address,
                                   Graph_lib::Address pw)
{
  auto& ref = Graph_lib::reference_to<Graph_lib::Button>(pw).window();
  Graph_lib::reference_to<Main_window>(&ref).set_diff_2_bt();
}

void Main_window::set_diff_2_bt()
{
  *diff = 2;
  difficulty.put("normal");
}

void Main_window::cb_diff3_clicked(Graph_lib::Address,
                                   Graph_lib::Address pw)
{
  auto& ref = Graph_lib::reference_to<Graph_lib::Button>(pw).window();
  Graph_lib::reference_to<Main_window>(&ref).set_diff_3_bt();
}

void Main_window::set_diff_3_bt()
{
  *diff = 3;
  difficulty.put("hard");
}

void Main_window::cb_name_setter(Graph_lib::Address, Graph_lib::Address pw)
{
  auto& ref = Graph_lib::reference_to<Graph_lib::Button>(pw).window();
  Graph_lib::reference_to<Main_window>(&ref).set_name();
}

void Main_window::cb_exit_end_button_clicked(Graph_lib::Address,
                                             Graph_lib::Address pw)
{
  auto& ref = Graph_lib::reference_to<Graph_lib::Button>(pw).window();
  Graph_lib::reference_to<Main_window>(&ref).close_win();
}

void Main_window::close_win()
{
  *action = -1;
  hide();
}

void Main_window::set_name()
{
  if (*mode == 2)
  {
    if (*name1 == "")
    {

      *name1 = (name_setter.get_string()).substr(0, 17);
      if (*name1 != "")
      {
        Player1_name.set_label("Player 1: " + *name1);
        attach(Player1_name);
        redraw();
      }
    }
    else
    {
      *name2 = (name_setter.get_string()).substr(0, 17);
      if (*name2 != "")
        waiting();
    }
  }
  else
  {
    *name1 = (name_setter.get_string()).substr(0, 17);
    if (*name1 != "")
    {
      *name2 = "computer";
      waiting();
    }
  }
}

void Main_window::waiting() { hide(); }
