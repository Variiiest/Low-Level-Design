//
// Created by varis on 06-01-2026.
// In this , how we are writing now

#include <iostream>
#include <string>

using namespace std;

class Dog{
public:
   void introduce(){
       cout<<"I am Dog"<<endl;
   }
};

class Robot{
public:
   void introduce(){
      cout<<"I am Robot"<<endl;
   }
};


int main(){
   if(const string choice ="dog"; choice == "dog"){
      const auto dog= new Dog();
      dog->introduce();
      delete dog;
    } else if( choice == "robot") {
       const auto robot = new Robot();
       robot->introduce();
       delete robot;
    }
}

/*
Tight coupling - if rename the class Dog to Pitbul our main function will break
If I have to create 10 types of toys and in other files I have to write the same if else again and again
Main function can manage specific types and can manage the memory manually


*/