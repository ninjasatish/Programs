# include <bits/stdc++.h>
# include <conio.h>
# define vi vector <int>
# define vvi vector < vi >

using namespace std ;

void shuffle (vvi &v){
	for (int i = 0 ; i < 3 ; i ++){
		for (int j = 0 ; j < 3 ; j ++){
			v.at(i).at(j) = (rand () % 20) + 10 ;
		}
	}
}

void print_matrix (vvi &v){
	for (int i = -1 ; i <= 3 ; i ++){
		cout << "\t\t" ;
		for (int j = -1 ; j <= 4 ; j ++){
			if (i == -1 || i == 3){
				cout << "- " ;
			}
			else if (j == -1 || j == 3){
				cout << "| " ;
			}
			if (i > -1 && j > -1 && i < 3 && j < 3)
				cout << v.at(i).at(j) << " " ;
		}
		cout << "\n" ;
	}
	cout << "\n" ;
}

int score (vvi &a , int bid){
	for (int i = 0; i < 3 ; i ++){
		for (int j = 0 ; j < 3 ; j ++){
			if (a.at(i).at(0) == a.at(i).at(1) && a.at(i).at(1) == a.at(i).at(2) ){
				cout << "Triple Combo ...\n" ;
				return 5*bid ;
			}
			if (a.at(0).at(0) == a.at(1).at(1) && a.at(1).at(1) == a.at(2).at(2) ){
				cout << "\t Triple Combo ...\n" ;
				return 5*bid ;
			}
			if (a.at(0).at(0) == a.at(1).at(1) && a.at(1).at(1) == a.at(2).at(2) ){
				cout << "\t Triple Combo ...\n" ;
				return 5*bid ;
			}
			if (a.at(0).at(2) == a.at(1).at(1) && a.at(1).at(1) == a.at(2).at(0)){
				cout << "\t Triple Combo ...\n" ;
				return 5*bid ;
			}
			if (j+1 < 3 && a.at(i).at(j) == a.at(i).at(j+1)){
				cout << "\tDouble Combo ...\n" ;
				return 2*bid ;
			}
			if (i+1 < 3 && a.at(i).at(j) == a.at(i+1).at(j)){
				cout << "\tDouble Combo ...\n" ;
				return 2*bid ;
			}
			if (a.at(0).at(0) == a.at(1).at(1) ){
				cout << "\tDouble Combo ...\n" ;
				return 2*bid ;
			}
			if (a.at(1).at(1) == a.at(2).at(2)){
				cout << "\tDouble Combo ...\n" ;
				return 2*bid ;
			}
			if (a.at(2).at(0) == a.at(1).at(1) || a.at(1).at(1) == a.at(0).at(2)){
				cout << "\tDouble Combo ...\n" ;
				return 2*bid ;
			}
		}
	}
}

// Main Code Here 

int main()

{
	
	// Variables and Input
	srand ( time (0) ) ;
	vvi matrix (3) ;
	for (int i = 0 ; i < 3 ; i++){
		matrix[i] = vi (3) ;
	}	
	int balance , bid   ;
	string name ;
	
	// code
	
	cout << "\t<<<\tWelcome to the Cassino\t>>>\n\n" ;
	cout << "\tEnter Your Name :  " ;
	cin >> name ;
	balance = 50 ;
	
	start: 
	system ("CLS") ;
	if (balance < 1){
		cout << "\n\tOut of balance ..." ;
		exit(0) ;
	}
	cout << "\t<<<\t\tWelcome to the Cassino  - " << name << "\t>>>\n\n" ;
	cout << "\tRules :: \n\n" ;
	cout << "\t1. Enter the bid amount" << "\n\t2. For two consecutive same numbers you get 2x the bid\n" ;
	cout << "\t3. For three consecutive same numbers you get 5x the bid\n" ;
	cout << "\t4. The numbers are choosen randomly between 10-30\n" ;
	cout << "\t5. You lose when you are out of balance\n\n" ;
	
	
	cout << "\tYour available balance is  : $ " << balance ;
	cout << "\n\n  Enter bid amount : " ; cin >> bid ;
	if (bid > balance){
		cout << "\n\tBid cannot be greater than you balance ..." ;
		
	}
	balance -= bid ;
	int temp_bal = balance ;
	
	shuffle:
	system ("CLS") ;
	shuffle(matrix) ;
	cout << "\n" ;
	print_matrix (matrix) ;
	
	balance += score (matrix , bid) ;
	
	
	cout << "\n\tYour Earning  : $ " << balance  - temp_bal ; 
	cout << "\n\n\tDo you want to continue playing .. (y / n) : " ;
	char a = getch() ;
	if (a == 'y' || a == 'Y'){
		goto start ;
	}
	else {
		exit (0) ;
	}
	goto start ;
}
