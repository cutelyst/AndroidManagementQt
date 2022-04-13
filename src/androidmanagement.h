/*
 * SPDX-FileCopyrightText: (C) 2022 Daniel Nicoletti <dantti12@gmail.com>
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */
#ifndef ANDROIDMANAGEMENT_H
#define ANDROIDMANAGEMENT_H

#include <QObject>

#include <QJsonObject>

#include <androidmanagementexports.h>
#include <androidmanagementpolicy.h>
#include <googlecloudoauth2.h>

namespace AndroidManagementQt {

class ANDROID_MANAGEMENT_QT_EXPORT AndroidManagement : public GoogleCloudOAuth2
{
    Q_OBJECT
public:
    explicit AndroidManagement(QObject *parent = nullptr);

    void createEnrollmentToken(const QObject *receiver, const QString &enterpriseId, const QJsonObject &enrollmentToken, std::function<void(const GoogleCloudReply &)> code);

    void deleteEnrollmentToken(const QObject *receiver, const QString &enterpriseId, const QString &enrollmentTokenId, std::function<void(const GoogleCloudReply &)> code);

    void getDevice(const QObject *receiver, const QString &fullDeviceId, std::function<void(const GoogleCloudReply &)> code);

    void getDevices(const QObject *receiver, const QString &enterpriseId, std::function<void(const GoogleCloudReply &)> code);

    void patchDevice(const QObject *receiver, const QString &enterpriseId, const QString &deviceId, const QString &updateMask, const QJsonObject &device, std::function<void(const GoogleCloudReply &)> code);

    void patchDevice(const QObject *receiver, const QString &fullDeviceId, const QString &updateMask, const QJsonObject &device, std::function<void(const GoogleCloudReply &)> code);

    void issueCommandDevice(const QObject *receiver, const QString &enterpriseId, const QString &deviceId, const QJsonObject &command, std::function<void(const GoogleCloudReply &)> code);

    void issueCommandDevice(const QObject *receiver, const QString &fullDeviceId, const QJsonObject &command, std::function<void(const GoogleCloudReply &)> code);

    void deleteDevice(const QObject *receiver, const QString &enterpriseId, const QString &deviceId, std::function<void(const GoogleCloudReply &)> code);

    void deleteDevice(const QObject *receiver, const QString &fullDeviceId, std::function<void(const GoogleCloudReply &)> code);

    void getPolicies(const QObject *receiver, const QString &enterpriseId, std::function<void(const GoogleCloudReply &, const std::vector<AndroidManagementPolicy> &policies)> code);

    void getPolicy(const QObject *receiver, const QString &enterpriseId, const QString &policyId, std::function<void(const GoogleCloudReply &, const AndroidManagementPolicy &policy)> code);

    void patchPolicy(const QObject *receiver, const QString &enterpriseId, const QString &policyId, const QString &updateMask, const QJsonObject &policy, std::function<void(const GoogleCloudReply &)> code);

    void deletePolicy(const QObject *receiver, const QString &enterpriseId, const QString &policyId, std::function<void(const GoogleCloudReply &)> code);

    void deletePolicy(const QObject *receiver, const QString &fullPolicyId, std::function<void(const GoogleCloudReply &)> code);

private:
    QUrl m_service;
};

}

#endif // ANDROIDMANAGEMENT_H
