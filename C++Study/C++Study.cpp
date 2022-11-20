#include <iostream>
#include <list>
using namespace std;
class Object
{
public:
    int age;
    float height;
    Object( float _height, int _age)
    {
        age = _age;
        height = _height;
        Obj_method();
    }

    void Obj_method()
    {
        cout << "Obj의 메소드"<< endl;
    }
    float getData()
    {
        return (height * age);
    }

};

class Animal : public Object
{
public:
    Animal(float height, int age) : Object(height,age)
    {
        Animal_method();
    }
    void Animal_method()
    {
        cout << "Animal의 메소드" << endl;
    }
};

class Person:public Object
{
public:
    Person(float height, int age) : Object(height, age)
    {
        Person_method();
    }

    void Person_method()
    {
        cout << "Person의 메소드" << endl;
    }
};

struct Data
{
    float data_value;
};
void setData(Data data, Object obj)
{
    data.data_value = obj.getData();
}

void ShowList(list<Data> datalist)
{
    for (int i = 0; i < datalist.size(); i++)
    {
        Data var_data = datalist.front();
        cout << var_data.data_value << endl;
    }
}
int main()
{
    list<Data> dataList = list<Data>();

    Person man(170.5f, 24);
    Data manData;
    dataList.push_back(manData);
    setData(manData, man);
    cout << man.getData() << '\n' << endl;
    

    Animal dog(30.0f, 4);
    Data dogData;
    dataList.push_back(dogData);
    setData(dogData,dog);
    cout << dog.getData() << '\n' << endl;


    Object obj_man = man; //man 업캐스팅 
    obj_man.Obj_method();
    cout << obj_man.getData() << '\n' << endl;

    Object obj_animal = dog; // dog 업캐스팅
    obj_animal.Obj_method();
    cout << obj_animal.getData() << '\n' << endl;


    cout << "데이터 리스트에 저장된 값은 : " << '\n' << endl;

    cout <<  dataList.front().data_value << '\n' << endl;

    //ShowList(dataList);

    return 0;
}


