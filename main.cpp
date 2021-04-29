#include <iostream>
#include<bits/stdc++.h>
using namespace std;

typedef struct text{
  char word[100];
  text *ori, *old;
}
Line;
Line *one;
Line *two;
text*top, *bot;
int num;
void createcurrent(){
  text*a;
  a = new text;
  one= a;
  top= one;
  bot= one;
  num= -1;
}
void line(){
  text*a;
  a= new text;
  a-> ori= NULL;
  a-> old= one;
  one->ori= a;
  bot= a;
  one= a;
  num= 0;
}
void line2(){
  text*a;
  a= new text;
  a -> ori= NULL;
  if (top == NULL){    
    top= a;
    bot= a;
  }
  else{
    text*b= bot;
    b->ori= a;
    a-> old= b;
  }
  bot= a;
  one= a;
}
int main(){
  cout<< "Text Editor: ";
  char string[30];
  cin.getline (string,30);
  ifstream instream;
  instream.open(string); 
  char get;
  one= two;
  createcurrent();
  while(instream.get(&get,sizeof(get))){
    if (get == '\n')
    line();
    else{
      num++;
      one->word[num]= get;
    }
  }
  instream.close();
}