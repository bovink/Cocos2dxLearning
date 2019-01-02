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

    static DatabaseModule *getInstance();

    void openDatabase(sqlite3 **ppDb, string databaseName);

    void createTable(sqlite3 *pDb, string sql);

    bool checkTableExist(sqlite3 *pDb, string name);

    void insertData(sqlite3 *pDb, string sql);

    void queryData(sqlite3 *pDb, string sql);

    void queryData2(sqlite3 *pDb, string sql, char ***table, int *r, int *c);

    void deleteData(sqlite3 *pDb, string sql);

    void modifyData(sqlite3 *pDb, string sql);

private:

    DatabaseModule();

    static DatabaseModule *databaseModule;
};


#endif //PROJ_ANDROID_DATABASEMODULE_H
