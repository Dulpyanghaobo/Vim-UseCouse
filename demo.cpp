//
//  main.cpp
//  C++Demo121701
//
//  Created by yhb on 2020/12/17.
//
// C++可以使用struct、class定义类
// struct与class区别
//1.struct默认权限public,class默认权限private
//2.C++规范 g_:全局变量 m_:成员变量 s_:静态变量 c_:常量
//3.成员变量不能共用，不能共用内存
//4.函数可以共用
//5.this存储函数调用者的地址,this指向了函数调用者:原理->左边为指针,.左边为对象
//
#include <iostream>
using namespace std;
using namespace std;
class Person {
public:
//    成员变量
    int age;
//    成员函数
    void run() {
        cout << "Person::run()"<<endl;
    }
};
struct Car {
    int m_price;
    int m_scale;
    void run() {
        cout << "Car::run()"<<m_scale <<endl;
    }
};
struct User {
    string name;
    int age;
    int height;
    char gender;
    void display() {
//        cout << name << age << height << endl;
        cout << "User::run()- "<<this->age << endl;
    }
};
int main(int argc, const char * argv[]) {
//  Java/JS
//    Person p = new Person();
//创建一个对象
//    Person p;
//    p.age = 10;
//    printf("%d\n",p.age);
////引用p创建新对象
//    Person *person = &p;
//    person->age = 20;
//    person->run();
//    printf("%d\n",p.age);
//
//    Car car1;
//    car1.m_price = 10;
//    car1.m_scale = 20;
//    car1.run();
//    Car car2;
//    car2.m_price = 10;
//    car2.m_scale = 20;
//    car2.run();
    User user;
    user.display();
    user.name = "1";
    user.age = 2;
    user.height = 3;
    user.gender = 'm';
    user.display();
    cout << "user.name==" << &user.name << "\n" << "user.age==" << &user.age << "\n" << "user.height==" << &user.height << "\n" << "user.gender==" << (void *)&(user.gender) << endl;
    User *u = &user;
    u->age = 3;
    u->height = 3;
    u->gender = 'r';
    cout << "user.age==" << &u->age << "\n" << "user.height==" << &u->height << "\n" << "user.gender==" << (void *)&(u->gender) << endl;
    
    User *p = (User *)&user.age;
    p->age = 20;
    p->height = 30;
    cout << "user.age==" << &p->age << "\n" << "user.height==" << &p->height << "\n" << "user.gender==" << (void *)&(p->gender) << endl;
    return 0;
}

