//
// Created by 吴宗刚 on 2018/6/27.
//

#ifndef PROJ_ANDROID_PERSON_H
#define PROJ_ANDROID_PERSON_H


#include <string>

#include "json.hpp"

using json = nlohmann::json;

namespace ns {
    class Person {

    public:
        const std::string &getName() const;

        void setName(const std::string &name);

        const std::string &getSex() const;

        void setSex(const std::string &sex);

        int getAge() const;

        void setAge(int age);

    private:
        std::string name;
        std::string sex;
        int age;
    };

    void to_json(json &j, const Person &p);

    void from_json(const json &j, Person &p);
}


#endif //PROJ_ANDROID_PERSON_H
