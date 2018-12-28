//
// Created by 吴宗刚 on 2018/12/27.
//

#include "DownloadModule.h"

DownloadService* DownloadService::downloadService = nullptr;
DownloadUtils* DownloadUtils::downloadUtils = nullptr;

DownloadService::DownloadService() {

    network::DownloaderHints hints;
    hints.countOfMaxProcessingTasks = 5;
    hints.tempFileNameSuffix = "temp";
    hints.timeoutInSeconds = 10;

    downloader.reset(new network::Downloader(hints));
}

DownloadService::DownloadService(network::DownloaderHints hints) {

    downloader.reset(new network::Downloader(hints));
}

DownloadService *DownloadService::getInstance() {
    if (downloadService == nullptr) {
        downloadService = new DownloadService();
        downloadService->init();
    }
    return downloadService;
}

DownloadService *DownloadService::getInstance(network::DownloaderHints hints) {
    if (downloadService == nullptr) {
        downloadService = new DownloadService(hints);
        downloadService->init();
    }
    return downloadService;
}

void DownloadService::init() {

    downloader->onTaskProgress = [this](const network::DownloadTask &task,
                                        int64_t bytesReceived,
                                        int64_t totalBytesReceived,
                                        int64_t totalBytesExpected) {
        float percent = float(totalBytesReceived * 100) / totalBytesExpected;
        __CCLOGWITHFUNCTION("taskName:%s,%.1f%%[total %d KB]", task.identifier.c_str(), percent,
                            int(totalBytesExpected / 1024));
    };

    downloader->onDataTaskSuccess = [this](const cocos2d::network::DownloadTask &task,
                                           std::vector<unsigned char> &data) {

    };

    downloader->onFileTaskSuccess = [this](const cocos2d::network::DownloadTask &task) {

        __CCLOGWITHFUNCTION("Task:%s Download Finish", task.identifier.c_str());
    };
    downloader->onDataTaskSuccess = [this](const cocos2d::network::DownloadTask &task,
                                           std::vector<unsigned char> &data) {

    };
}

void DownloadService::startDownloadTask(const DownloadInfo &downloadInfo) {

    downloader->createDownloadFileTask(downloadInfo.getDownloadPath(),
                                       downloadInfo.getStoragePath(), downloadInfo.getFileName());
}

////////////////////////////////////////下载工具类////////////////////////////////////////

DownloadUtils::DownloadUtils() {

}

DownloadUtils *DownloadUtils::getInstance() {
    if (downloadUtils == nullptr) {
        downloadUtils = new DownloadUtils();
    }
    return downloadUtils;
}

void DownloadUtils::createPathIfNotExist(const string &dirPath) {
    bool isPathExist = FileUtils::getInstance()->isDirectoryExist(dirPath);
    if (!isPathExist) {
        FileUtils::getInstance()->createDirectory(dirPath);
    }
}

////////////////////////////////////////下载信息类////////////////////////////////////////

DownloadInfo::DownloadInfo(const string &storagePath, const string &downloadPath, const string &MD5,
                           int resourceVersion, int resourceID, const string &des,
                           const string &fileName) : storagePath(storagePath),
                                                     downloadPath(downloadPath), MD5(MD5),
                                                     resourceVersion(resourceVersion),
                                                     resourceID(resourceID), des(des),
                                                     fileName(fileName) {}

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

int DownloadInfo::getResourceVersion() const {
    return resourceVersion;
}

void DownloadInfo::setResourceVersion(int resourceVersion) {
    DownloadInfo::resourceVersion = resourceVersion;
}

int DownloadInfo::getResourceID() const {
    return resourceID;
}

void DownloadInfo::setResourceID(int resourceID) {
    DownloadInfo::resourceID = resourceID;
}

const string &DownloadInfo::getDes() const {
    return des;
}

void DownloadInfo::setDes(const string &des) {
    DownloadInfo::des = des;
}

const string &DownloadInfo::getFileName() const {
    return fileName;
}

void DownloadInfo::setFileName(const string &fileName) {
    DownloadInfo::fileName = fileName;
}
