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

    void startDownloadTask(const DownloadInfo &downloadInfo);

private:

    DownloadService();

    DownloadService(network::DownloaderHints hints);

    void init();

private:

    static DownloadService *downloadService;

    unique_ptr<network::Downloader> downloader;
};


// 下载帮助类
class DownloadUtils {

public:

    static DownloadUtils *getInstance();

    void createPathIfNotExist(const string &dirPath);

private:

    DownloadUtils();

    static DownloadUtils *downloadUtils;

};

// 下载信息
class DownloadInfo {

public:

    DownloadInfo(const string &storagePath, const string &downloadPath, const string &MD5,
                 int resourceVersion, int resourceID, const string &des, const string &fileName);

    const string &getStoragePath() const;

    void setStoragePath(const string &storagePath);

    const string &getDownloadPath() const;

    void setDownloadPath(const string &downloadPath);

    const string &getMD5() const;

    void setMD5(const string &MD5);

    int getResourceVersion() const;

    void setResourceVersion(int resourceVersion);

    int getResourceID() const;

    void setResourceID(int resourceID);

    const string &getDes() const;

    void setDes(const string &des);

    const string &getFileName() const;

    void setFileName(const string &fileName);

    int getDownloadState() const;

    void setDownloadState(int downloadState);

private:

    string storagePath;
    string downloadPath;
    string MD5;
    int resourceVersion;
    int resourceID;
    string des;
    string fileName;
    int downloadState = -1;// 默认为未下载-1 未知状态为-2 下载中为0 暂停下载为1 下载完毕为2
};


#endif //PROJ_ANDROID_DOWNLOADMODULE_H
