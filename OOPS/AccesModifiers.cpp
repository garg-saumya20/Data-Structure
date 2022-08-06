#include <iostream>
using namespace std;

class Human
{

private:
    int age;

public:
    int height;
    int weight;

    int getAge()
    {
        this->age;
    }
    void setWeight(w)
    {
        this->weight = w;
    }
};

class Male : public Human
{
public:
    string color;
    void sleep()
    {
        cout << "Male is sleeping" << endl;
    }
    
};

int main()
{
    Male m;
    

}
