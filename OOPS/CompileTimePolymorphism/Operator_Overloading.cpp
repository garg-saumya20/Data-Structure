// #include <iostream>
// using namespace std;

// class complex
// {
// private:
//     int a, b;

// public:
//     void setValues(int x, int y)
//     {
//         this->a = x;
//         this->b = y;
//     }
//     complex add(complex o)
//     {
//         complex temp;
//         temp.a =this-> a + o.a;
//         temp.b = this->b + o.b;
//         return temp;
//     }
//     void show_data()
//     {
//         cout << a << " " << b;
//     }
// };

// int main()
// {
//     complex o1, o2, o3;
//     o1.setValues(3, 4);
//     o2.setValues(5, 7);
//     o3 = o1.add(o2);
//     o3.show_data();
// }


//Opeartor overloading for binary operator

// #include <iostream>
// using namespace std;

// class complex
// {
// private:
//     int a, b;

// public:
//     void setValues(int x, int y)
//     {
//         this->a = x;
//         this->b = y;
//     }
//     complex operator+(complex o)
//     {
//         complex temp;
//         temp.a = this->a + o.a;
//         temp.b = this->b + o.b;
//         return temp;
//     }
//     void show_data()
//     {
//         cout << a << " " << b;
//     }
// };

// int main()
// {
//     complex o1, o2, o3;
//     o1.setValues(3, 4);
//     o2.setValues(5, 7);
//     o3 = o1.operator+(o2);
//     // OR
//     //  o3=o1+o2;
//     o3.show_data();
// }

//Operator overloading for unary operator

#include <iostream>
using namespace std;

class complex
{
private:
    int a, b;

public:
    void setValues(int x, int y)
    {
        this->a = x;
        this->b = y;
    }
    complex operator-()
    {
        complex temp;
        temp.a = -a;
        temp.b = -b;
        return temp;
    }
    void show_data()
    {
        cout << a << " " << b;
    }
};

int main()
{
    complex o1, o2;
    o1.setValues(3, 4);
    o2=-o1;

    //OR
    //o2=o1.operator-();
    o2.show_data();
}