#include <iostream>
#include <string>

// A pure virtual function is a function that must be overridden in a derived class and need not be defined.
// Pure virtual function (interfaces) implementation

class PrintName{
public:
    // Pure virtual function that must have subclass where it will execute
    // and, it's declared like below
    virtual std::string getClassName() = 0;
};
//Inherits from PrintName that allows us to get the value
class Entity : public PrintName{
public:
  virtual std::string getClass(){
        return "Entity";
    }
    std::string getClassName() override {
        return "Entity";
    }
};
// Attribute class inherits from Entity
class Attribute : public Entity{
private:
    std::string attrName;
public:
    // Constructor and Object initialization
   Attribute(const std::string& name)
        :attrName(name){};

    std::string getClass() override{
        return attrName;
    }
    // If we don't add and inherit from PrintName we may not able to get the answer, correctly
    std::string getClassName() override {
        return "Attribute";
    }
};
// Printable class doesn't care which function is in class, it needs to have PrintName public function
// To make it we should inherit from PrintName like below
class Example : public PrintName{
    std::string getClassName() override {
        return "Example";
    }
};
// Printing classes
void PrintGetClass(Entity* obj){
    std::cout << obj->getClass() << std::endl;
}
void PrintClassName(PrintName* name){
    std::cout << name->getClassName() << std::endl;
}
int main(){
    
    Entity *e = new Entity();
    Attribute* a = new Attribute("Attribute");
    Example* ex = new Example();
    
    // Both will print the result
    PrintGetClass(a);
    PrintGetClass(e);

    PrintClassName(e);
    PrintClassName(a);
    PrintClassName(ex);
}