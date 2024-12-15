#include <iostream>
#include <string>
#include <utility>

#include "backend.h"
#include "frontend.h"

using namespace std;

int main ()
{
  int mode, diff, action = 1;
  string name1, name2;
  int res1 = -1, res2 = -1;
  while (action == 1)
  {
    Main_window main_win(Graph_lib::Point{500, 250}, 1000, 600, mode, diff,
                         action, name1, name2, res1, res2);
    main_win.wait_for_interruption();

    if (action == 1)
    {
      Play_window play_win(Graph_lib::Point{500, 250}, 1000, 600, diff,
                           name1, name2, mode, res1, res2);
      play_win.wait_for_interruption();
    }
  }
  cout << "Goodbye!";
  exit(0);
}