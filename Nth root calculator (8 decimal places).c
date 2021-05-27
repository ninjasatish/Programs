#include <stdio.h>

double pow (double n , int r){
  if (r == 0){
    return 1;
  }
  else{
    double res = 1;
    while (r > 0){
      if (r%2 == 1){
        res *= n ;
      }
      n *= n ;
      r = r / 2 ;
    }
    return res ;
  }
  return 0;
}


double nth_root(double n , int r){
  double start = 1 , end = n;
  double mid = (start + end)/2.0;
  while (end - start > -1e6){
    mid = (start+end)/2.0;
    if (mid == start || mid == end)
      break;
    if (pow(mid , r) == n){
      return mid ;
    }
    else if (pow(mid , r ) >n){
      end = mid;
    }
    else if (pow(mid , r) < n){
      start = mid ;
    }
  }
  return mid;
}

// Time complexity is O (log K * log (N*1e6))


int main (){
    double n ; int r;
    
    printf("Enter a number : ");
    scanf("%lf" ,&n );
    printf("\nWhich root to find? : ");
    scanf("%d", &r) ;
    printf("\n%dth root of %lf is : ",r,n);
    printf("%.8lf",nth_root(n , r));
    
}
