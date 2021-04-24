// This code is written by Satish Kumar Prajapati
// C ++ Programm 

# include <bits/stdc++.h>
using namespace std ;

//Encryptor

string encrypt (string text , int shift){
  string result = "";
  int val ;
  for (int i = 0 ; i < text.length()  ; i++){
        val = int (text[i]) ;
        if(text[i] == ' '){
            result += ' ';
        }
        else if(isupper(text[i])){
            result += char (((val - 65 + shift) % 26)+65) ;
        } 
        else{
           result += char (((val - 97 + shift) % 26)+97) ;
        }
  }
  return result ;
}


//Decryptor

string decrypt(string text , int shift){
  string result = "";
  int val ;
  for (int i = 0 ; i < text.length()  ; i++){
        
        if(text[i] == ' '){
            result += ' ';
        }
        else if(isupper(text[i])){
          val = (int (text[i]) - 65) - shift;
          if(val < 0) result += val + 26 + 65 ;
          else result += char(val + 65) ;
        }
         else if(islower(text[i])){
          val = (int (text[i]) - 97) - shift;
          if(val < 0) result += val + 26 + 97 ;
          else result += char(val + 97) ;
        }
  }
  return result ;

} 

//Possible decryptions
   
void crack (string text){
  cout << "Possible decryptions : "<<endl;
  for (int i = 0 ; i < 26 ; i ++){
    cout <<"\t" << decrypt (text , i) << endl ;
  }
}



//Write main code here

int main ()
{
  ios_base::sync_with_stdio (false) ;
  clrscr () ;
  string text ; 
  int shift , option ;
  cout << "Caesar Cipher Encryptor ::\n" << endl ;
  
    cout << "Text : " ; 
    getline (cin , text) ;
    cout <<"\nShift key : " ; 
    cin >> shift ;
    shift = shift % 26 ;
    cout << "encrypted : " << encrypt (text , shift) << endl;
    cout << "\ndecrypted : "<<decrypt (text , shift) ;
    cout << "\n\n" ;
    crack (text) ;
  
  
}
