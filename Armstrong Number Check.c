# include <stdio.h>

int power (int n , int k){
	// n raised to the power k function
	int result = 1 ;
	while (k!=0){
		result = result * n ;
		k = k - 1 ;
	}
	return result ;
}

int no_of_digits(int n){
	int count = 0 ;
	while (n != 0){
		n = n/ 10 ;
		count = count + 1 ;
	}
	return count ;
}

int main (){
	printf("Enter a number : ") ;
	int n ;
	scanf("%d" , &n) ;
	int digits = no_of_digits(n) ;
	printf("\nThe number of Digits are : %d \n" , digits) ;
	
	int result = 0 , temp_n = n ;
	
	for (int i = 0 ; i <= digits ; ++i){
		int temp = temp_n % 10 ;
		result = result + power (temp , digits) ;
		temp_n = temp_n / 10;
	}
	
	printf("%d is " , n) ;
	printf((result == n?"an Armstrong number":"Not an Armstrong Number")) ;
    
}
