//
// Created by 吴宗刚 on 2018/12/27.
//

#include "DownloadModule.h"

const string &DownloadInfo::getStoragePath() const {
    return storagePath;
}

void DownloadInfo::setStoragePath(const string &storagePath) {
    DownloadInfo::storagePath = storagePath;
}

const string &DownloadInfo::getDownloadPath() const {
    return downloadPath;
}

void DownloadInfo::setDownloadPath(const string &downloadPath) {
    DownloadInfo::downloadPath = downloadPath;
}

const string &DownloadInfo::getMD5() const {
    return MD5;
}

void DownloadInfo::setMD5(const string &MD5) {
    DownloadInfo::MD5 = MD5;
}

const string &DownloadInfo::getResourceVersion() const {
    return resourceVersion;
}

void DownloadInfo::setResourceVersion(const string &resourceVersion) {
    DownloadInfo::resourceVersion = resourceVersion;
}

const string &DownloadInfo::getResourceID() const {
    return resourceID;
}

void DownloadInfo::setResourceID(const string &resourceID) {
    DownloadInfo::resourceID = resourceID;
}

const string &DownloadInfo::getDes() const {
    return des;
}

void DownloadInfo::setDes(const string &des) {
    DownloadInfo::des = des;
}
