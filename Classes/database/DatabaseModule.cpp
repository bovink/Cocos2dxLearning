//
// Created by 吴宗刚 on 2018/12/29.
//

#include "DatabaseModule.h"

void DatabaseModule::openDatabase(sqlite3 **ppDb) {

    string dbPath = FileUtils::getInstance()->getWritablePath() + "mydatabase.db";

    int result = sqlite3_open(dbPath.c_str(), ppDb);

    if (result == SQLITE_OK)
        __CCLOGWITHFUNCTION("open database successful!");
    else
        __CCLOGWITHFUNCTION("open database failed!");

}

void DatabaseModule::createTable(sqlite3 *pDb, string sql) {

    // 创建表的sql语句：create table
//    string sql = "create table student(ID integer primary key autoincrement, name text, sex text)";

    // 执行sql语句：sqlite3_exec
    int ret = sqlite3_exec(pDb, sql.c_str(), nullptr, nullptr, nullptr);

    if (ret != SQLITE_OK) {
        __CCLOGWITHFUNCTION("create table failed");
    }
}

void DatabaseModule::insertData(sqlite3 *pDb, string sql) {

    // (1 , 'student1' , 'male')
//    string sql = "insert into student values(1, 'student1', 'male')";

    int ret = sqlite3_exec(pDb, sql.c_str(), nullptr, nullptr, nullptr);

    if (ret != SQLITE_OK) {
        __CCLOGWITHFUNCTION("insert data failed!");
    }

}

// 回调函数
int callback(void *para, int col_num, char **col_value, char **col_name) {
    CCLOG("%s : 总共有 %d 个字段", (char *) para, col_num);

    for (int i = 0; i < col_num; i++) {
        CCLOG("%s = %s", col_name[i], col_value[i]);
    }

    CCLOG("------------------------------"); // 分隔符

    return 0;
}

void DatabaseModule::queryData(sqlite3 *pDb, string sql) {

    // 查询语句
//    string sql = "select * from student";

    int ret = sqlite3_exec(pDb, sql.c_str(), &callback, (void *) "para", nullptr);

    if (ret != SQLITE_OK) {
        CCLOG("query data failed!");
    }
}

void DatabaseModule::queryData2(sqlite3 *pDb, string sql, char **table, int *r, int *c) {

//    char **table; // 查询结果
//    int r, c;     // 行数、列数

//    string sql = "select * from student";
    sqlite3_get_table(pDb, sql.c_str(), &table, r, c, nullptr);

//    CCLOG("行数 is %d , 列数 is %d", r, c);
//
//    // 第0行（0 ~ c-1），为字段名
//    // 第1行（c ~ 2*c-1），第一条记录
//    // ......
//    for (int i = 0; i <= r; i++) {
//        for (int j = 0; j < c; j++) {
//            CCLOG("%s", table[i * c + j]);
//        }
//        CCLOG("------------------------------");
//    }

    // 必须释放查询表
    sqlite3_free_table(table);
}

void DatabaseModule::deleteData(sqlite3 *pDb, string sql) {

    // 删除第一条记录
//    string sql = "delete from student where ID = 1";

    int ret = sqlite3_exec(pDb, sql.c_str(), nullptr, nullptr, nullptr);

    if (ret != SQLITE_OK) {
        CCLOG("delete data failed!");
    }
}

void DatabaseModule::modifyData(sqlite3 *pDb, string sql) {


    // 修改第三条记录的 name 字段
//    string sql = "update student set name = 'hello' where ID = 3";

    int ret = sqlite3_exec(pDb, sql.c_str(), nullptr, nullptr, nullptr);

    if (ret != SQLITE_OK) {
        CCLOG("update data failed!");
    }
}
