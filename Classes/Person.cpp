//
// Created by 吴宗刚 on 2018/6/27.
//

#include "Person.h"

const std::string &ns::Person::getName() const {
    return name;
}

void ns::Person::setName(const std::string &name) {
    Person::name = name;
}

const std::string &ns::Person::getSex() const {
    return sex;
}

void ns::Person::setSex(const std::string &sex) {
    Person::sex = sex;
}

int ns::Person::getAge() const {
    return age;
}

void ns::Person::setAge(int age) {
    Person::age = age;
}

void ns::from_json(const json &j, Person &p) {

    p.setName(j.at("name").get<std::string>());
    p.setSex(j.at("sex").get<std::string>());
    p.setAge(j.at("age").get<int>());
}

void ns::to_json(json &j, const Person &p) {

    j = json {{"name", p.getName()},
              {"sex",  p.getSex()},
              {"age",  p.getAge()}};
}
