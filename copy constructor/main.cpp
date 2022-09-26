#include <iostream>
#include <string>

// Copy constructor is a special constructor for creating a new object as a copy of an existing object. 
// Copy constructors are the standard way of copying objects in C++, as opposed to cloning, and have C++-specific nuances.
// The first argument of such a constructor is a reference to an object of the same type as is being constructed (const or non-const),
// which might be followed by parameters of any type

class String{
    private:
        char* myBuffer;
        unsigned int mySize;
    public:
        String(const char* string){
            mySize = strlen(string);
            // That will replace null termination char 
            myBuffer = new char[mySize + 1]; // Try to use without adding + 1 and will see the difference
            // Copy the value of this pointer into actual buffer by interating over
            memcpy(myBuffer, string, mySize);
            myBuffer[mySize] = 0;
        }

        String(const String& other)
            :mySize(other.mySize)
        {
            myBuffer = new char[mySize + 1];
            memcpy(myBuffer, other.myBuffer, mySize + 1);
        }

        // Object destructor 
        ~String(){
            delete[] myBuffer;
        }

        char& operator[](unsigned int index){
            return myBuffer[index];
        }

        //That lets us access the private member of class   
        friend std::ostream& operator << (std:: ostream& stream, const String& string );
};

std::ostream& operator << (std::ostream& stream, const String& string){
    stream << string.myBuffer;
    return stream;
}

void PrintString(const String& string){
    String copy = string;
    std::cout << string << std::endl;
}

int main(){
    String firstString= "Hello";
    String secondString  = firstString;
    secondString[2] = 'o';

    PrintString(firstString);
    PrintString(secondString);
    
    return 0;

}
