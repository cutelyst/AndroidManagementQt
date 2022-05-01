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
    using ReplyCb = std::function<void(const GoogleCloudReply &)>;
    explicit AndroidManagement(QObject *parent = nullptr);

    /*!
     * \brief Lists EMM-managed enterprises. Only BASIC fields are returned.
     */
    void getEnterprises(const QObject *receiver, ReplyCb code);

    void createEnterprise(const QObject *receiver, const QUrlQuery &query, const QJsonObject &enterprise, ReplyCb code);

    void getEnterprise(const QObject *receiver, const QString &name, ReplyCb code);

    void patchEnterprise(const QObject *receiver, const QString &name, const QString &updateMask,  const QJsonObject &enterprise, ReplyCb code);
    inline void patchEnterprise(const QObject *receiver, const QString &name, const QJsonObject &enterprise, ReplyCb code);

    void deleteEnterprise(const QObject *receiver, const QString &name, ReplyCb code);

    void createEnrollmentToken(const QObject *receiver, const QString &enterpriseId, const QJsonObject &enrollmentToken, ReplyCb code);

    void deleteEnrollmentToken(const QObject *receiver, const QString &enrollmentTokenId, ReplyCb code);
    void deleteEnrollmentToken(const QObject *receiver, const QString &enterpriseId, const QString &enrollmentTokenId, ReplyCb code);

    void getDevice(const QObject *receiver, const QString &fullDeviceId, ReplyCb code);

    void getDevices(const QObject *receiver, const QString &enterpriseId, ReplyCb code);

    void patchDevice(const QObject *receiver, const QString &enterpriseId, const QString &deviceId, const QString &updateMask, const QJsonObject &device, ReplyCb code);

    void patchDevice(const QObject *receiver, const QString &fullDeviceId, const QString &updateMask, const QJsonObject &device, ReplyCb code);

    void issueCommandDevice(const QObject *receiver, const QString &enterpriseId, const QString &deviceId, const QJsonObject &command, ReplyCb code);

    void issueCommandDevice(const QObject *receiver, const QString &fullDeviceId, const QJsonObject &command, ReplyCb code);

    void deleteDevice(const QObject *receiver, const QString &enterpriseId, const QString &deviceId, ReplyCb code);

    void deleteDevice(const QObject *receiver, const QString &fullDeviceId, ReplyCb code);

    void getPolicies(const QObject *receiver, const QString &enterpriseId, ReplyCb code);

    void getPolicy(const QObject *receiver, const QString &enterpriseId, const QString &policyId, ReplyCb code);

    void patchPolicy(const QObject *receiver, const QString &enterpriseId, const QString &policyId, const QString &updateMask, const QJsonObject &policy, ReplyCb code);
    void patchPolicy(const QObject *receiver, const QString &policyName, const QString &updateMask, const QJsonObject &policy, ReplyCb code);

    void deletePolicy(const QObject *receiver, const QString &enterpriseId, const QString &policyId, ReplyCb code);

    void deletePolicy(const QObject *receiver, const QString &fullPolicyId, ReplyCb code);

private:
    void requestFinished(QNetworkReply *reply, ReplyCb code);

    QUrl m_service;
};

inline void AndroidManagement::patchEnterprise(const QObject *receiver, const QString &name, const QJsonObject &enterprise, ReplyCb code)
{
    patchEnterprise(receiver, name, {}, enterprise, code);
}

}

#endif // ANDROIDMANAGEMENT_H
