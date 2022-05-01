/*
 * SPDX-FileCopyrightText: (C) 2022 Daniel Nicoletti <dantti12@gmail.com>
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */
#include "androidmanagement.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QUrlQuery>
#include <QNetworkReply>
#include <QFile>

#include <QLoggingCategory>

using namespace AndroidManagementQt;

AndroidManagement::AndroidManagement(QObject *parent) : GoogleCloudOAuth2(parent)
  , m_service(QStringLiteral("https://androidmanagement.googleapis.com"))
{
    setScopes({
                  QStringLiteral("https://www.googleapis.com/auth/androidmanagement"),
              });
}

void AndroidManagement::getEnterprises(const QObject *receiver, ReplyCb code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &credential) {
        if (credential.error) {
            code(credential);
            return;
        }

        QUrl url = m_service;
        url.setPath(QLatin1String("/v1/enterprises"));

        url.setQuery(QUrlQuery{
                         {QStringLiteral("projectId"), accountCredential()[u"project_id"].toString()},
                     });

        QNetworkRequest req = defaultRequest(url);
        qDebug() << "list Enterprises" << url;
        QNetworkReply *reply = m_nam->get(req);
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            requestFinished(reply, code);
        });
    });
}

void AndroidManagement::createEnterprise(const QObject *receiver, const QUrlQuery &query, const QJsonObject &enterprise, ReplyCb code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &credential) {
        if (credential.error) {
            code(credential);
            return;
        }

        QUrl url = m_service;
        url.setPath(QLatin1String("/v1/enterprises"));

        QUrlQuery _query = query;
        _query.addQueryItem(QStringLiteral("projectId"), accountCredential()[u"project_id"].toString());
        url.setQuery(_query);

        QNetworkRequest req = defaultRequest(url);
        req.setHeader(QNetworkRequest::ContentTypeHeader, QByteArrayLiteral("application/json"));
        qDebug() << "create enterprise" << url;
        QNetworkReply *reply = m_nam->post(req, QJsonDocument(enterprise).toJson(QJsonDocument::Compact));
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            requestFinished(reply, code);
        });
    });
}

void AndroidManagement::getEnterprise(const QObject *receiver, const QString &name, ReplyCb code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &credential) {
        if (credential.error) {
            code(credential);
            return;
        }

        QUrl url = m_service;
        if (name.startsWith(u"enterprises/")) {
            url.setPath(QLatin1String("/v1/") + name);
        } else {
            url.setPath(QLatin1String("/v1/enterprises/") + name);
        }

        QNetworkRequest req = defaultRequest(url);
        qDebug() << "delete enterprise" << url;
        QNetworkReply *reply = m_nam->get(req);
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            requestFinished(reply, code);
        });
    });
}

void AndroidManagement::patchEnterprise(const QObject *receiver, const QString &name, const QString &updateMask, const QJsonObject &enterprise, ReplyCb code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &accessToken) {
        QUrl url = m_service;
        if (name.startsWith(u"enterprises/")) {
            url.setPath(QLatin1String("/v1/") + name);
        } else {
            url.setPath(QLatin1String("/v1/enterprises/") + name);
        }

        if (!updateMask.isEmpty()) {
            url.setQuery(QUrlQuery{
                             {QStringLiteral("updateMask"), updateMask},
                         });
        }

        QNetworkRequest req = defaultRequest(url);
        req.setHeader(QNetworkRequest::ContentTypeHeader, QByteArrayLiteral("application/json"));
        qDebug() << "patch enterprise" << url << name;
        QNetworkReply *reply = m_nam->sendCustomRequest(req, QByteArrayLiteral("PATCH"), QJsonDocument(enterprise).toJson(QJsonDocument::Compact));
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            requestFinished(reply, code);
        });
    });
}

void AndroidManagement::deleteEnterprise(const QObject *receiver, const QString &enterprise, ReplyCb code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &credential) {
        if (credential.error) {
            code(credential);
            return;
        }

        QUrl url = m_service;
        if (enterprise.startsWith(u"enterprises/")) {
            url.setPath(QLatin1String("/v1/") + enterprise);
        } else {
            url.setPath(QLatin1String("/v1/enterprises/") + enterprise);
        }

        QNetworkRequest req = defaultRequest(url);
        qDebug() << "delete enterprise" << url;
        QNetworkReply *reply = m_nam->deleteResource(req);
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            requestFinished(reply, code);
        });
    });
}

void AndroidManagement::createEnrollmentToken(const QObject *receiver, const QString &enterpriseId, const QJsonObject &enrollmentToken, ReplyCb code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &credential) {
        if (credential.error) {
            code(credential);
            return;
        }

        QUrl url = m_service;
        if (enterpriseId.startsWith(u"enterprises/")) {
            url.setPath(QLatin1String("/v1/") + enterpriseId + QLatin1String("/enrollmentTokens"));
        } else {
            url.setPath(QLatin1String("/v1/enterprises/") + enterpriseId + QLatin1String("/enrollmentTokens"));
        }

        QNetworkRequest req = defaultRequest(url);
        req.setHeader(QNetworkRequest::ContentTypeHeader, QByteArrayLiteral("application/json"));
        qDebug() << "list devices" << url << enterpriseId;
        QNetworkReply *reply = m_nam->post(req, QJsonDocument(enrollmentToken).toJson(QJsonDocument::Compact));
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            requestFinished(reply, code);
        });
    });
}

void AndroidManagement::deleteEnrollmentToken(const QObject *receiver, const QString &enrollmentTokenId, ReplyCb code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &credential) {
        if (credential.error) {
            code(credential);
            return;
        }

        QUrl url = m_service;
        url.setPath(QLatin1String("/v1/") + enrollmentTokenId);

        qDebug() << "delete enrollmentToken" << url << enrollmentTokenId;
        QNetworkReply *reply = m_nam->deleteResource(defaultRequest(url));
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            requestFinished(reply, code);
        });
    });
}

void AndroidManagement::deleteEnrollmentToken(const QObject *receiver, const QString &enterpriseId, const QString &enrollmentTokenId, ReplyCb code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &credential) {
        if (credential.error) {
            code(credential);
            return;
        }

        QUrl url = m_service;
        if (enterpriseId.startsWith(u"enterprises/")) {
            url.setPath(QLatin1String("/v1/") + enterpriseId + QLatin1String("/enrollmentTokens/") + enrollmentTokenId);
        } else {
            url.setPath(QLatin1String("/v1/enterprises/") + enterpriseId + QLatin1String("/enrollmentTokens/") + enrollmentTokenId);
        }

        qDebug() << "delete enrollmentToken" << url << enterpriseId << enrollmentTokenId;
        QNetworkReply *reply = m_nam->deleteResource(defaultRequest(url));
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            requestFinished(reply, code);
        });
    });
}

void AndroidManagement::getDevice(const QObject *receiver, const QString &fullDeviceId, ReplyCb code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &credential) {
        if (credential.error) {
            code(credential);
            return;
        }

        QUrl url = m_service;
        url.setPath(QLatin1String("/v1/") + fullDeviceId);

        qDebug() << "get device" << url << fullDeviceId;
        QNetworkReply *reply = m_nam->get(defaultRequest(url));
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            requestFinished(reply, code);
        });
    });
}

void AndroidManagement::getDevices(const QObject *receiver, const QString &enterpriseId, ReplyCb code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &credential) {
        if (credential.error) {
            code(credential);
            return;
        }

        QUrl url = m_service;
        if (enterpriseId.startsWith(u"enterprises/")) {
            url.setPath(QLatin1String("/v1/") + enterpriseId + QLatin1String("/devices"));
        } else {
            url.setPath(QLatin1String("/v1/enterprises/") + enterpriseId + QLatin1String("/devices"));
        }

        qDebug() << "list devices" << url << enterpriseId;
        QNetworkReply *reply = m_nam->get(defaultRequest(url));
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            requestFinished(reply, code);
        });
    });
}

void AndroidManagement::patchDevice(const QObject *receiver, const QString &enterpriseId, const QString &deviceId, const QString &updateMask, const QJsonObject &device, ReplyCb code)
{
    patchDevice(receiver, QLatin1String("enterprises/") + enterpriseId + QLatin1String("/devices/") + deviceId,
                updateMask,
                device,
                code);
}

void AndroidManagement::patchDevice(const QObject *receiver, const QString &fullDeviceId, const QString &updateMask, const QJsonObject &device, ReplyCb code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &accessToken) {
        QUrl url = m_service;
        url.setPath(QLatin1String("/v1/") + fullDeviceId);

        if (!updateMask.isEmpty()) {
            url.setQuery(QUrlQuery{
                             {QStringLiteral("updateMask"), updateMask},
                         });
        }

        QNetworkRequest req = defaultRequest(url);
        req.setHeader(QNetworkRequest::ContentTypeHeader, QByteArrayLiteral("application/json"));
        qDebug() << "patch device" << url << fullDeviceId;
        QNetworkReply *reply = m_nam->sendCustomRequest(req, QByteArrayLiteral("PATCH"), QJsonDocument(device).toJson(QJsonDocument::Compact));
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            requestFinished(reply, code);
        });
    });
}

void AndroidManagement::issueCommandDevice(const QObject *receiver, const QString &enterpriseId, const QString &deviceId, const QJsonObject &command, ReplyCb code)
{
    issueCommandDevice(receiver,
                       QLatin1String("enterprises/") + enterpriseId + QLatin1String("/devices/") + deviceId,
                       command,
                       code);
}

void AndroidManagement::issueCommandDevice(const QObject *receiver, const QString &fullDeviceId, const QJsonObject &command, ReplyCb code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &accessToken) {
        QUrl url = m_service;
        url.setPath(QLatin1String("/v1/") + fullDeviceId + QLatin1String(":issueCommand"));

        QNetworkRequest req = defaultRequest(url);
        req.setHeader(QNetworkRequest::ContentTypeHeader, QByteArrayLiteral("application/json"));
        qDebug() << "issueCommand device" << url << fullDeviceId;
        QNetworkReply *reply = m_nam->post(req, QJsonDocument(command).toJson(QJsonDocument::Compact));
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            requestFinished(reply, code);
        });
    });
}

void AndroidManagement::deleteDevice(const QObject *receiver, const QString &enterpriseId, const QString &deviceId, ReplyCb code)
{
    deleteDevice(receiver, QLatin1String("enterprises/") + enterpriseId + QLatin1String("/devices/") + deviceId, code);
}

void AndroidManagement::deleteDevice(const QObject *receiver, const QString &fullDeviceId, ReplyCb code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &accessToken) {
        QUrl url = m_service;
        url.setPath(QLatin1String("/v1/") + fullDeviceId);

        qDebug() << "delete deviceId" << url << fullDeviceId;
        QNetworkReply *reply = m_nam->deleteResource(defaultRequest(url));
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            requestFinished(reply, code);
        });
    });
}

void AndroidManagement::getPolicies(const QObject *receiver, const QString &enterpriseId, ReplyCb code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &accessToken) {
        QUrl url = m_service;
        if (enterpriseId.startsWith(u"enterprises/")) {
            url.setPath(QLatin1String("/v1/") + enterpriseId + QLatin1String("/policies"));
        } else {
            url.setPath(QLatin1String("/v1/enterprises/") + enterpriseId + QLatin1String("/policies"));
        }

        qDebug() << "list policies" << url << enterpriseId;
        QNetworkReply *reply = m_nam->get(defaultRequest(url));
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            requestFinished(reply, code);
        });
    });
}

void AndroidManagement::getPolicy(const QObject *receiver, const QString &enterpriseId, const QString &policyId, ReplyCb code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &accessToken) {
        QUrl url = m_service;
        url.setPath(QLatin1String("/v1/enterprises/") + enterpriseId + QLatin1String("/policies/") + policyId);

        QNetworkRequest req = defaultRequest(url);
        qDebug() << "list devices" << url << enterpriseId;
        QNetworkReply *reply = m_nam->get(req);
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            requestFinished(reply, code);
        });
    });
}

void AndroidManagement::patchPolicy(const QObject *receiver, const QString &enterpriseId, const QString &policyId, const QString &updateMask, const QJsonObject &policy, ReplyCb code)
{
    QString policyName;
    if (enterpriseId.startsWith(u"enterprises/")) {
        policyName = enterpriseId + QLatin1String("/policies/") + policyId;
    } else {
        policyName = QLatin1String("enterprises/") + QLatin1String("/policies/") + policyId;
    }
    patchPolicy(receiver, policyName, updateMask, policy, code);
}

void AndroidManagement::patchPolicy(const QObject *receiver, const QString &policyName, const QString &updateMask, const QJsonObject &policy, ReplyCb code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &accessToken) {
        QUrl url = m_service;
        url.setPath(QLatin1String("/v1/") + policyName);

        if (!updateMask.isEmpty()) {
            url.setQuery(QUrlQuery{
                             {QStringLiteral("updateMask"), updateMask},
                         });
        }

        QNetworkRequest req = defaultRequest(url);
        req.setHeader(QNetworkRequest::ContentTypeHeader, QByteArrayLiteral("application/json"));
        qDebug() << "patch policy" << url << updateMask;
        QNetworkReply *reply = m_nam->sendCustomRequest(req, QByteArrayLiteral("PATCH"), QJsonDocument(policy).toJson(QJsonDocument::Compact));
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            requestFinished(reply, code);
        });
    });
}

void AndroidManagement::deletePolicy(const QObject *receiver, const QString &enterpriseId, const QString &policyId, ReplyCb code)
{
    QString policyName;
    if (enterpriseId.startsWith(u"enterprises/")) {
        policyName = enterpriseId + QLatin1String("/policies/") + policyId;
    } else {
        policyName = QLatin1String("enterprises/") + QLatin1String("/policies/") + policyId;
    }
    deletePolicy(receiver, policyName, code);
}

void AndroidManagement::deletePolicy(const QObject *receiver, const QString &fullPolicyId, ReplyCb code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &accessToken) {
        QUrl url = m_service;
        url.setPath(QLatin1String("/v1/") + fullPolicyId);

        qDebug() << "delete policyId" << url << fullPolicyId;
        QNetworkReply *reply = m_nam->deleteResource(defaultRequest(url));
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            requestFinished(reply, code);
        });
    });
}

void AndroidManagement::requestFinished(QNetworkReply *reply, ReplyCb code)
{
    reply->deleteLater();

    const QByteArray data = reply->readAll();
    GoogleCloudReply gcr;

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(data, &error);
    if (!error.error) {
        gcr.data = doc.object();
        gcr.error = reply->error();
        qDebug() << "AM got data" << reply->error() << gcr.data;
    } else {
        qWarning() << "AM Failed to parse data" << data << error.errorString();
        gcr.error = true;
    }

    code(gcr);
}

#include "moc_androidmanagement.cpp"
