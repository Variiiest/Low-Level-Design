//
// Created by varis on 06-01-2026.
//


#include <iostream>
#include <memory>
#include <bits/ostream.tcc>
using namespace  std;
//Product Interface
class IToy {
    public:
    virtual ~IToy() = default;
    virtual void introduce() = 0;
};

//Concrete Products
class ToyDog : public IToy {
    public:
    void introduce() override {
        cout << "I am ToyDog" << endl;
    }
};

class ToyRobot : public IToy {
    public:
    void introduce() override {
        cout << "I am ToyRobot" << endl;
    }
};

//Now I can define main point of contact (The creator)

class ToyCreator {
    public:
      virtual ~ToyCreator() = default;

    // Core method to manufacture that toy
      virtual unique_ptr<IToy> createToy() const = 0;

    // Now comes operation logic
      void deliver() const {
          cout << "I am ToyCreator" << endl;
          unique_ptr<IToy> toy = createToy();
          cout << "System: Delivering... ";
          toy->introduce();
      }
};

//concrete creators
class DogCreator : public ToyCreator {
    public:
      unique_ptr<IToy> createToy() const override {
          return make_unique<ToyDog>();
      }
};

class RobotCreator : public ToyCreator {
    public:
    unique_ptr<IToy> createToy() const override {
        return make_unique<ToyRobot>();
    }
};


int main() {
    unique_ptr<ToyCreator> dogCreator = make_unique<DogCreator>();
    dogCreator->deliver();
}

/*
Simple factory - waiter , remember everything chef added in the menu
GoF factory - food court ( Provide space) and specialized chef can install the cart for their product


Now there is one question ? You want special type of ability that is not
common like robot can fly also
*/
