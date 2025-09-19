#include <iostream>
#include <map>

using namespace std;

void print_board_state(map<int, char> state)
{
  cout << state[1] << " | " << state[2] << " | " << state[3] << endl;
  cout << "-   -   -" << endl;
  cout << state[4] << " | " << state[5] << " | " << state[6] << endl;
  cout << "-   -   -" << endl;
  cout << state[7] << " | " << state[8] << " | " << state[9] << endl;
}

int main()
{
  map<int, char> state = {{1, '.'}, {2, '.'}};
  for (int i = 1; i < 10; i++)
  {
    state.insert{{i, '.'}};
  }

  print_board_state(state);
  return 0;
}
