#include <bits/stdc++.h>
using namespace std;
int permutation(int n) {
  int result = 1;
  while (n > 0) {
    result *= n;
    n--;
  }
  return result;
}
int main() {
  
  // Program: Password Wordlist Generator
  // Description: Generates a wordlist of passwords based on the given
  // characters Author: Shadow Wolf
  // Date of version: 8th April,2024 
  // version: 1.3

cout<<"***************************\nWelcome to the Password Generator\n";
  int length = 0, i = 0;
  char alphabets[100] = "";
  cout << "Enter the alphabets you want: ";
  cin.getline(alphabets, 100);
  int size = strlen(alphabets);
  srand(time(0));
  cout << "Enter the length of each password: ";
  cin >> length;
  int total_combinations = permutation(size) * length;
  cout << "Total possible passwords with the given inputs: "
       << total_combinations << endl;
  char choice;
  cout << "Do you want to generate passwords? (y/n): ";
  cin >> choice;
  auto start = chrono::high_resolution_clock::now();
  if (choice == 'y' || choice == 'Y') {
    ofstream outfile("passwords.txt");
    vector<string> generatedPasswords;
    while (i < total_combinations) {
      string generatedPassword = "";
      for (int j = 0; j < length; j++) {
        char randomChar = alphabets[rand() % size];
        generatedPassword += randomChar;
        system("cls");
      }
      if (find(generatedPasswords.begin(), generatedPasswords.end(),
               generatedPassword) == generatedPasswords.end()) {
        generatedPasswords.push_back(generatedPassword);
        cout << generatedPassword << "\n";
        outfile << generatedPassword << "\n";
         system("cls");
      }
      i++;
    }
    outfile.close();
    cout << "Passwords are saved to passwords.txt\n";
  } else {
    cout << "Operation Aborted. No passwords generated.";
  }
  auto stop = chrono::high_resolution_clock::now();
  auto duration_seconds = chrono::duration_cast<chrono::seconds>(stop - start);
  auto duration_minutes = chrono::duration_cast<chrono::minutes>(stop - start);
  cout << "Code execution time: " << duration_seconds.count() << " seconds"
       << endl;
  cout << "Code execution time: " << duration_minutes.count() << " minutes" << endl;
  cout<<"****************************\n";
  system("Pause");
  return 0;
}
