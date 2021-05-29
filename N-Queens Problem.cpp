// This code is written by Satish Kumar Prajapati
// N-Queens problem
#include<bits/stdc++.h>
using namespace std;

// Print the 2D vector matrix
void print (vector <vector <bool> > &a ){
  for (int i = 0 ; i < a.size() ; i ++){
    for (int j = 0 ; j < a.size() ; j ++){
      cout << a[i][j] << " " ;
    }
    cout << endl ;
  }
  cout << endl ;
}

// Check if a square is attacked by a queen
bool attacked (vector <vector <bool> > &a , int x , int y ){
    // Rows check
    for (int i = 0 ; i < a.size() ; i ++){
    
      if (a[i][y] == 1){
        return true ;
      }
    }
    // Columns check
    for (int i = 0 ; i < a.size () ; i ++){    
      if (a[x][i] == 1){
        return true ;
      }
    }
    // Right Diagonal Check
    for (int i = 0 ; i < a.size () ; i ++){
      for (int j = 0 ; j < a.size () ; j ++){
        if ((x - y) == (i - j) && a[i][j] == 1){
          return true ;
        }
      }
    }
    // Left downward Diagonal Check
      for (int ii = x , jj = y; ii < a.size() && jj >= 0 ; ii++ , jj--){
        if (a[ii][jj]) {
          return true ;
        }
      }
    // Left upward diagonal check 
      for (int ii = x , jj = y; jj < a.size() && ii >= 0 ; ii-- , jj++){
        if (a[ii][jj]) {
          return true ;
        }
      }
    return false ;
    }
    


// Place n - number of queens if Possible , else return false
bool place_queens(vector < vector <bool> > &a , int n){
  if (n == 0){
    return true ;
  }
  else {
    for (int i = 0 ; i < a.size() ; i ++){
      for (int j = 0 ; j < a.size() ; j ++){
        // If attacked then skip the square
        if (attacked (a , i , j )){
          continue ;
        }
        // if not attacked then place the queen here
        else {
          a[i][j] = 1 ;
          if (place_queens(a , n-1) == true) {
            return true;
          }
          else {
            a[i][j] = 0 ;
          }
        }
      }
    }
  }
  return false ;
}

// Main Code Here 



int main()

{
  ios::sync_with_stdio (false) ;
  cout << "Enter the board size : " ;
  int n ; cin >> n ;
  
  // Vector of n - rows
  vector <vector <bool> > a (n) ;
  
  // Vector of n - columns
  for (int i = 0 ; i < n ; i ++){
    a[i] = vector <bool> (n) ;
  }
  
  
  
  if (place_queens(a , n)){
    print (a ) ;
  }
  else {
    cout << "Not possible" ;
  }
  // Time complexity is approx O(N!) 
}
