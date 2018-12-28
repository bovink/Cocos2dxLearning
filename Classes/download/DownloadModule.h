//
// Created by 吴宗刚 on 2018/12/27.
//

#ifndef PROJ_ANDROID_DOWNLOADMODULE_H
#define PROJ_ANDROID_DOWNLOADMODULE_H

#include <string>
#include "network/CCDownloader.h"
#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

class DownloadUtils;

class DownloadInfo;

// 下载服务
class DownloadService {

public:

    static DownloadService *getInstance();

    static DownloadService *getInstance(network::DownloaderHints hints);

    void startDownloadTask(DownloadInfo downloadInfo);

private:

    DownloadService();

    DownloadService(network::DownloaderHints hints);

    static DownloadService *downloadService = nullptr;

    unique_ptr<network::Downloader> downloader;
};


// 下载帮助类
class DownloadUtils {

public:

    static DownloadUtils *getInstance();

    void createPathIfNotExist(const string &dirPath);

private:

    DownloadUtils();

    static DownloadUtils *downloadUtils = nullptr;

};

// 下载信息
class DownloadInfo {

public:

    const string &getStoragePath() const;

    void setStoragePath(const string &storagePath);

    const string &getDownloadPath() const;

    void setDownloadPath(const string &downloadPath);

    const string &getMD5() const;

    void setMD5(const string &MD5);

    const string &getResourceVersion() const;

    void setResourceVersion(const string &resourceVersion);

    const string &getResourceID() const;

    void setResourceID(const string &resourceID);

    const string &getDes() const;

    void setDes(const string &des);

private:

    string storagePath;
    string downloadPath;
    string MD5;
    string resourceVersion;
    string resourceID;
    string des;
};


#endif //PROJ_ANDROID_DOWNLOADMODULE_H
