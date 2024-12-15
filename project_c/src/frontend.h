#pragma once
#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>
#include <array>
#include <map>
#include <random>
#include <string>
#include <utility>

#include "backend.h"
using namespace std;

constexpr int field_space{50};  // размер для "бортика" - место справа,
                                // сверху и снизу от границ окна
constexpr int min_button_size{50};  // минимальный размер для кнопки/ поля
constexpr int field_size{
    500};  // размер квадратного поля, в котором расположатся фишки
constexpr int window_w{1000};  // ширина окон
constexpr int window_h{600};   // высота окон
constexpr int space_w{400};  // место на игровом экране, оставленное под
                             // интерфейс - остальное под поле

struct Chip : public Graph_lib::Button
{
  Chip(Graph_lib::Point xy, int w, int h, const std::string& label,
       Graph_lib::Callback cb);
  pair<int, int> coords;
};

class Play_window : public Graph_lib::Window
{
public:
  int diff, mode;
  int turn_count = rand() % 2;
  bool chip_on_field = false;
  int type_new_chip;
  int *res1, *res2;
  std::pair<int, int> new_coords;
  Player player1 = Player();
  Player player2 = Player();

  std::vector<vector<int>> FIELD;

  std::array<Graph_lib::Color, 12> color{
      Graph_lib::Color::red,          Graph_lib::Color::green,
      Graph_lib::Color::blue,         Graph_lib::Color::yellow,
      Graph_lib::Color::magenta,      Graph_lib::Color::cyan,
      Graph_lib::Color::dark_red,     Graph_lib::Color::dark_green,
      Graph_lib::Color::dark_yellow,  Graph_lib::Color::dark_blue,
      Graph_lib::Color::dark_magenta, Graph_lib::Color::dark_cyan};

  Graph_lib::Vector_ref<Graph_lib::Circle> iso_field;

  Graph_lib::Vector_ref<Graph_lib::Circle> iso_chips;

  Graph_lib::Circle Current_field;

  Graph_lib::Button random;

  Graph_lib::Button commit;

  Graph_lib::Button push_back;

  Graph_lib::Button exit_end;

  Graph_lib::Rectangle Buffer_1;
  Graph_lib::Rectangle Buffer_2;
  Graph_lib::Out_box turn_play;
  Graph_lib::Out_box balance_of_player1;
  Graph_lib::Out_box balance_of_player2;

  Graph_lib::Circle new_chip;
  Graph_lib::Color new_color = Graph_lib::Color::red;

  Graph_lib::Vector_ref<Chip> field;

  Play_window(Graph_lib::Point xy, int width, int height, int _diff,
              string _name1, string _name2, int _mode, int& res1,
              int& res2);

  void next_walk ();

  void wait_for_interruption ();

  static void cb_random_clicked (Graph_lib::Address, Graph_lib::Address pw);
  void random_bt ();

  static void cb_commit_clicked (Graph_lib::Address, Graph_lib::Address pw);
  void commit_bt ();

  static void cb_pushback_clicked (Graph_lib::Address,
                                   Graph_lib::Address pw);
  void pushback_bt ();

  static void cb_field_button_clicked (Graph_lib::Address,
                                       Graph_lib::Address pw);
  void put_chip (Chip& chip);

  static void cb_exit_end_button_clicked (Graph_lib::Address,
                                          Graph_lib::Address pw);
  void close_win ();

  void set_field (int n);
  void draw_field ();
};

class Main_window : public Graph_lib::Window
{
public:
  int* diff;
  int* mode;
  int* action;
  string *name1, *name2;

  Graph_lib::Button run;            // starts game
  Graph_lib::Button set_gamemode1;  // button to set singleplayer
  Graph_lib::Button set_gamemode2;
  Graph_lib::Button set_difficulty1;
  Graph_lib::Button set_difficulty2;
  Graph_lib::Button set_difficulty3;
  Graph_lib::Button next;  // enters the name
  Graph_lib::Out_box difficulty;
  Graph_lib::Out_box gamemode;

  Graph_lib::In_box name_setter;

  Graph_lib::Text Player1_name;

  Graph_lib::Text res1;
  Graph_lib::Text res2;
  Graph_lib::Text res3;

  Graph_lib::Button exit_end;

  Main_window(Graph_lib::Point xy, int width, int height, int& mode,
              int& diff, int& action, string& name1, string& name2,
              int res1, int res2);

  void wait_for_interruption ();
  void waiting ();

  static void cb_run_clicked (Graph_lib::Address, Graph_lib::Address pw);
  void run_bt ();

  static void cb_set1_clicked (Graph_lib::Address, Graph_lib::Address pw);
  void set_1_bt ();

  static void cb_set2_clicked (Graph_lib::Address, Graph_lib::Address pw);
  void set_2_bt ();

  static void cb_diff1_clicked (Graph_lib::Address, Graph_lib::Address pw);
  void set_diff_1_bt ();

  static void cb_diff2_clicked (Graph_lib::Address, Graph_lib::Address pw);
  void set_diff_2_bt ();

  static void cb_diff3_clicked (Graph_lib::Address, Graph_lib::Address pw);
  void set_diff_3_bt ();

  static void cb_name_setter (Graph_lib::Address, Graph_lib::Address pw);

  static void cb_exit_end_button_clicked (Graph_lib::Address,
                                          Graph_lib::Address pw);
  void close_win ();

  void set_name ();
  void change_to_play ();
};
