using namespace std;

#include <iostream>


class Person{
    public:
        Person(string name, string animal, string other);
        string getName();
        string getAnimal();
        string getOther();
    private:
        string name;
        string animal;
        string other;
};

Person::Person (string name, string animal, string other){
    this->name = name;
    this->animal = animal;
    this->other = other;
};

string Person::getAnimal(){
    return this->animal;
};

string Person::getName(){
    return this->name;
};

string Person::getOther(){
    return this->other;
};

Person* parse(string element){
    //return nullptr;
    int begin = 0;
    int end = 0;

    end = element.find("|");
    string name = element.substr(begin, end - begin);
    begin = end + 1;

    end = element.find("|", begin);    
    string animal = element.substr(begin, end - begin);
    begin = end + 1;

    end = element.size();
    string other = element.substr(begin, end - begin);

    Person* result = new Person(name, animal, other);
    return result;
}

int main()
{
    string raw_data[3] = {"scott|tiger|mushroom","john|dog|pepper", "meggan|cat|pineapple" };
    Person* data[3];

    for(int i = 0; i<3; ++i){
        Person* tmp = parse(raw_data[i]);
        data[i] = tmp;
    }

    for(int i = 0; i<3; ++i){
        cout << "Name: " << data[i]->getName();
        cout << " Animal: " << data[i]->getAnimal();
        cout << " Other: " << data[i]->getOther() << endl;
    }

}
