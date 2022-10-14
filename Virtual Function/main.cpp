#include <iostream>
#include <string>

//Inherits from PrintName that allows us to get the value
class Entity {
public:
  virtual std::string getClass(){
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
};

void PrintGetClass(Entity* obj){
    std::cout << obj->getClass() << std::endl;
};
int main(){
    
    Entity *e = new Entity();
    Attribute* a = new Attribute("Attribute");
    // Both will print the result
    PrintGetClass(a);
    PrintGetClass(e);

}