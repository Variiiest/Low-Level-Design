
//Evolve with simple factory to avoid previous issues

#include <iostream>
#include <memory>
#include<bits/stdc++.h>
using namespace std;
class IToy { // Interface
public:
    virtual void introduce()= 0; //pure virtual function
    virtual ~IToy() = default;
};


// Products
class ToyDog : public IToy {
    public:
    void introduce() override {
        cout << "I am ToyDog" << std::endl;
    }
};

class ToyRobot : public IToy {
    public:
    void introduce() override {
        cout << "I am ToyRobot" << std::endl;
    }
};


//Factory
class ToyFactory {
    public:
    static unique_ptr<IToy> createToy(const string& type) {
         if (type == "ToyDog") {
             return make_unique<ToyDog>();
         }
         if (type == "ToyRobot") {
             return make_unique<ToyRobot>();
         }
         return nullptr;
     }
};

int main() {
    const unique_ptr<IToy> toy = ToyFactory::createToy("ToyDog");
    toy->introduce();
    return 0;
}



/*

if else will grow endlessly you have thousand type of toys in factory
and it break the open/closed principle
So here comes the next factory improvement from GoF(Gang of four)
 */

