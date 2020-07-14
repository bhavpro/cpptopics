#include <iostream>

using namespace std;

auto test1 = []() {
    cout << "hey\n";
};

auto test2 = [](void (*tf1)()) {
    for (int i = 0; i < 10; i++)
    {
        tf1(); // execute 10 times
    }
};

auto test3 = [](string name, void (*test4)(string name)) {
    for (int i = 0; i < 5; i++)
    {
        test4(name);
    }
};

auto test4 = [](string name) {
    cout << name << "\n";
};

auto test5 = []() {
    string a = "#5";
    return a;
};

auto test6 = []() -> string {
    string c = "helo";
    return c;
};

int main()
{

    // test2(test1);
    // test3("bhavya", test4);
    // cout << test5();
    // cout << test6();
    int a = 3;
    int b = 4;
    int c = 2;
    auto it1 = [a, b]() mutable {
        cout << a << b++;
    };
    // it1();
    // cout << a << b;

    auto it2 = [&a, &b]() {
        cout << a++ << ++b;
    };
    // it2();
    // cout << a << b;

    auto it3 = [x = a, a]() mutable {
        x++;
        cout << x << a;
    };

    //it3();
    //cout << a;

    auto it4 = [&x = a, a]() mutable {
        x++;
        a++;
        cout << x << a;
    };

    //it4();
    // cout << a;
    return 0;
}