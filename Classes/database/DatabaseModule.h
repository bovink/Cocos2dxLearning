//
// Created by 吴宗刚 on 2018/12/29.
//

#ifndef PROJ_ANDROID_DATABASEMODULE_H
#define PROJ_ANDROID_DATABASEMODULE_H


#include "cocos2d.h"
#include "sqlite3.h"

USING_NS_CC;
using namespace std;

class DatabaseModule {

public:

    void openDatabase(sqlite3 **ppDb);

    void createTable(sqlite3 *pDb, string sql);

    void insertData(sqlite3 *pDb, string sql);

    void queryData(sqlite3 *pDb, string sql);

    void queryData2(sqlite3 *pDb);

    void deleteData(sqlite3 *pDb, string sql);

    void modifyData(sqlite3 *pDb, string sql);
};


#endif //PROJ_ANDROID_DATABASEMODULE_H
