#include <iostream>
#include <map>

using namespace std;

void print_board_state(map<int, char> state) {
  cout << state[1] << " | " << state[2] << " | " << state[3] << endl;
  cout << "-   -   -" << endl;
  cout << state[4] << " | " << state[5] << " | " << state[6] << endl;
  cout << "-   -   -" << endl;
  cout << state[7] << " | " << state[8] << " | " << state[9] << endl;
}

bool check_win_vertical(map<int, char> state) {
  // Check first column
  if (state[1] != '.' && state[1] == state[4] && state[4] == state[7]) {
    return true;
  }
  // Check second column
  if (state[2] != '.' && state[2] == state[5] && state[5] == state[8]) {
    return true;
  }
  // Check third column
  if (state[3] != '.' && state[3] == state[6] && state[6] == state[9]) {
    return true;
  }
  return false;
}
bool check_win_horizontal(map<int, char> state) {
  // Check first row
  if (state[1] != '.' && state[1] == state[2] && state[2] == state[3]) {
    return true;
  }
  // Check second row
  if (state[4] != '.' && state[4] == state[5] && state[5] == state[6]) {
    return true;
  }
  // Check third row
  if (state[7] != '.' && state[7] == state[8] && state[8] == state[9]) {
    return true;
  }
  return false;
}
bool check_win_diagonal(map<int, char> state) {
  // Check main diagonal (top-left to bottom-right)
  if (state[1] != '.' && state[1] == state[5] && state[5] == state[9]) {
    return true;
  }
  // Check anti-diagonal (top-right to bottom-left)
  if (state[3] != '.' && state[3] == state[5] && state[5] == state[7]) {
    return true;
  }
  return false;
}

int main() {
  map<int, char> state;
  for (int i = 1; i < 10; i++) {
    state.insert(make_pair(i, '.'));
  }
  cout << "Tic Tac Toe" << endl;

  print_board_state(state);
  int player = 1;
  int choice;
  while (true) {
    cout << "Player " << player << " enter a number: ";
    cin >> choice;
    state[choice] = player == 1 ? 'X' : 'O';
    print_board_state(state);
    if (check_win_vertical(state) || check_win_horizontal(state) ||
        check_win_diagonal(state)) {
      cout << "Player " << player << " wins!" << endl;
      break;
    }
    player = player == 1 ? 2 : 1;
  }

  print_board_state(state);
  return 0;
}
