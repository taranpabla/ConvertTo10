#include <iostream>
using namespace std;

//Find the length/size of the char array aka a string
int sizeOfArray(char charArray[]) {
  int index = 0; // Init value for index
  int size = 0; // Init vlaue of size
  //While loops runs through the whole array
  while (charArray[index] != 0) {
    size++; // Increase size by 1
    index++; // Increase index by 1 to keep the loop going
  }
  return size;
}

//Translates the digits into their ASCII decimel values
int translate(char digit){
  // Uppercase the letters in case the user inputed lower case letters
  if(digit >= 'a' &&  digit <= 'z')
      digit -= ('a' - 'A');

  // Convert char to int value that are 0-9
  if(digit >= '0' && digit <= '9'){
    digit -= '0';
  }
  else{//Handles digits that are A-Z
    digit = digit - 'A' + 10;
  }
  return digit;
}

int ConvertTo10(char input[], int base){
  //Get the length/size of the string using trhe sizeOfString fucntion
  int len = sizeOfArray(input)-1;

  int result = 0; // Set Inital Value of the final result
  int digitValue = 1;

  for(int i = len; i >= 0; --i) // Runs through the input array
  {
    char digit = input[i]; // Grab the first digit of the input
    char trans = translate(digit); // Translate the digits
    result += trans * digitValue; // Get the base 10 value of this digit
    digitValue *= base; // Sets up the next exponent. This allows me to avoid using exponent.
  }
  return result;
}

int main(){
  char input[256]; // Create a char array for the input
  int base; // Create a int value for base
  //Get values from the user
  cout<<"Enter the integer to convert: ";
  cin>>input;
  cout<<"Enter the base: ";
  cin>>base;
  int finalAns = ConvertTo10(input, base);//Exceute the convert fucntion
  //Print the answer to the user.
  cout<< input << " in base(" << base << ") is " << finalAns << " in base(10)"<< endl;
}
