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

void AndroidManagement::createEnrollmentToken(const QObject *receiver, const QString &enterpriseId, const QJsonObject &enrollmentToken, std::function<void (const GoogleCloudReply &)> code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &credential) {
        if (credential.error) {
            code(credential);
            return;
        }

        QUrl url = m_service;
        url.setPath(QLatin1String("/v1/enterprises/") + enterpriseId + QLatin1String("/enrollmentTokens"));

        QNetworkRequest req = defaultRequest(url);
        req.setHeader(QNetworkRequest::ContentTypeHeader, QByteArrayLiteral("application/json"));
        qDebug() << "list devices" << url << enterpriseId;
        QNetworkReply *reply = m_nam->post(req, QJsonDocument(enrollmentToken).toJson(QJsonDocument::Compact));
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            const QByteArray data = reply->readAll();
            GoogleCloudReply gcr;
            qDebug() << "enrollmentTokens" << reply->error() << data;
            if (!reply->error()) {
                QJsonParseError error;
                QJsonDocument doc = QJsonDocument::fromJson(data, &error);
                if (!error.error) {
                    gcr.data = doc.object();
                    qDebug() << "got token" << doc.object();
                } else {
                    qWarning() << "Failed to parse google token file" << data << error.errorString();
                }
            } else {
                qWarning() << "get token failed" << reply->error();
            }

            code(gcr);
        });
    });
}

void AndroidManagement::deleteEnrollmentToken(const QObject *receiver, const QString &enterpriseId, const QString &enrollmentTokenId, std::function<void (const GoogleCloudReply &)> code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &credential) {
        if (credential.error) {
            code(credential);
            return;
        }

        QUrl url = m_service;
        url.setPath(QLatin1String("/v1/enterprises/") + enterpriseId + QLatin1String("/enrollmentTokens/") + enrollmentTokenId);

        qDebug() << "delete enrollmentToken" << url << enterpriseId << enrollmentTokenId;
        QNetworkReply *reply = m_nam->deleteResource(defaultRequest(url));
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            const QByteArray data = reply->readAll();
            qDebug() << "delete enrollmentTokens" << reply->error() << data;
            if (!reply->error()) {
                QJsonParseError error;
                QJsonDocument doc = QJsonDocument::fromJson(data, &error);
                if (!error.error) {
                    qDebug() << "got delete enrollmentTokens" << doc.object();
                } else {
                    qWarning() << "Failed to parse delete enrollmentTokens" << data << error.errorString();
                }
            } else {
                qWarning() << "delete enrollmentTokens failed" << reply->error();
            }

            code(credential);
        });
    });
}

void AndroidManagement::getDevice(const QObject *receiver, const QString &fullDeviceId, std::function<void (const GoogleCloudReply &)> code)
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
            GoogleCloudReply deviceReply;
            const QByteArray data = reply->readAll();
            qDebug() << "get device" << reply->error() << data;
            if (!reply->error()) {
                QJsonParseError error;
                const QJsonDocument doc = QJsonDocument::fromJson(data, &error);
                if (!error.error) {
                    deviceReply.data = doc.object();
                    qDebug() << "got device" << doc.object();
                } else {
                    deviceReply.error = true;
                    qWarning() << "Failed to parse google token file" << data << error.errorString();
                }
            } else {
                deviceReply.error = true;
                qWarning() << "get token failed" << reply->error();
            }

            code(deviceReply);
        });
    });
}

void AndroidManagement::getDevices(const QObject *receiver, const QString &enterpriseId, std::function<void (const GoogleCloudReply &)> code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &credential) {
        if (credential.error) {
            code(credential);
            return;
        }

        QUrl url = m_service;
        url.setPath(QLatin1String("/v1/enterprises/") + enterpriseId + QLatin1String("/devices"));

        qDebug() << "list devices" << url << enterpriseId;
        QNetworkReply *reply = m_nam->get(defaultRequest(url));
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            GoogleCloudReply deviceReply;
            const QByteArray data = reply->readAll();
            qDebug() << "list devices" << reply->error();
            if (!reply->error()) {
                QJsonParseError error;
                const QJsonDocument doc = QJsonDocument::fromJson(data, &error);
                if (!error.error) {
                    deviceReply.data = doc.object();
                    qDebug() << "got devices" << doc.object();
                } else {
                    deviceReply.error = true;
                    qWarning() << "Failed to parse google token file" << data << error.errorString();
                }
            } else {
                deviceReply.error = true;
                qWarning() << "get token failed" << reply->error();
            }

            code(deviceReply);
        });
    });
}

void AndroidManagement::patchDevice(const QObject *receiver, const QString &enterpriseId, const QString &deviceId, const QString &updateMask, const QJsonObject &device, std::function<void (const GoogleCloudReply &)> code)
{
    patchDevice(receiver, QLatin1String("enterprises/") + enterpriseId + QLatin1String("/devices/") + deviceId,
                updateMask,
                device,
                code);
}

void AndroidManagement::patchDevice(const QObject *receiver, const QString &fullDeviceId, const QString &updateMask, const QJsonObject &device, std::function<void (const GoogleCloudReply &)> code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &accessToken) {
        QUrl url = m_service;
        url.setPath(QLatin1String("/v1/") + fullDeviceId);

        if (!updateMask.isEmpty()) {
            QUrlQuery query;
            query.addQueryItem(QStringLiteral("updateMask"), updateMask);
            url.setQuery(query);
        }

        QNetworkRequest req = defaultRequest(url);
        req.setHeader(QNetworkRequest::ContentTypeHeader, QByteArrayLiteral("application/json"));
        qDebug() << "patch device" << url << fullDeviceId;
        QNetworkReply *reply = m_nam->sendCustomRequest(req, QByteArrayLiteral("PATCH"), QJsonDocument(device).toJson(QJsonDocument::Compact));
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            const QByteArray data = reply->readAll();
            GoogleCloudReply gcr;
            qDebug() << "patch device reply" << reply->error() << data;
            if (!reply->error()) {
                QJsonParseError error;
                QJsonDocument doc = QJsonDocument::fromJson(data, &error);
                if (!error.error) {
                    gcr.data = doc.object();
                    qDebug() << "got patch device" << doc.object();
                } else {
                    qWarning() << "Failed to parse google token file" << data << error.errorString();
                }
            } else {
                qWarning() << "patch device failed" << reply->error();
            }

            code(accessToken);
        });
    });
}

void AndroidManagement::issueCommandDevice(const QObject *receiver, const QString &enterpriseId, const QString &deviceId, const QJsonObject &command, std::function<void (const GoogleCloudReply &)> code)
{
    issueCommandDevice(receiver,
                       QLatin1String("enterprises/") + enterpriseId + QLatin1String("/devices/") + deviceId,
                       command,
                       code);
}

void AndroidManagement::issueCommandDevice(const QObject *receiver, const QString &fullDeviceId, const QJsonObject &command, std::function<void (const GoogleCloudReply &)> code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &accessToken) {
        QUrl url = m_service;
        url.setPath(QLatin1String("/v1/") + fullDeviceId + QLatin1String(":issueCommand"));

        QNetworkRequest req = defaultRequest(url);
        req.setHeader(QNetworkRequest::ContentTypeHeader, QByteArrayLiteral("application/json"));
        qDebug() << "issueCommand device" << url << fullDeviceId;
        QNetworkReply *reply = m_nam->post(req, QJsonDocument(command).toJson(QJsonDocument::Compact));
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            const QByteArray data = reply->readAll();
            qDebug() << "issueCommand device reply" << reply->error() << data;
            if (!reply->error()) {
                QJsonParseError error;
                QJsonDocument doc = QJsonDocument::fromJson(data, &error);
                if (!error.error) {
//                    m_token = doc.object();
                    qDebug() << "got issueCommand device" << doc.object();
                } else {
                    qWarning() << "Failed to issueCommand device" << data << error.errorString();
                }
            } else {
                qWarning() << "issueCommand device failed" << reply->error();
            }

            code(accessToken);
        });
    });
}

void AndroidManagement::deleteDevice(const QObject *receiver, const QString &enterpriseId, const QString &deviceId, std::function<void (const GoogleCloudReply &)> code)
{
    deleteDevice(receiver, QLatin1String("enterprises/") + enterpriseId + QLatin1String("/devices/") + deviceId, code);
}

void AndroidManagement::deleteDevice(const QObject *receiver, const QString &fullDeviceId, std::function<void (const GoogleCloudReply &)> code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &accessToken) {
        QUrl url = m_service;
        url.setPath(QLatin1String("/v1/") + fullDeviceId);

        qDebug() << "delete deviceId" << url << fullDeviceId;
        QNetworkReply *reply = m_nam->deleteResource(defaultRequest(url));
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            const QByteArray data = reply->readAll();
            GoogleCloudReply gcr;
            qDebug() << "delete deviceId" << reply->error() << data;
            if (!reply->error()) {
                QJsonParseError error;
                QJsonDocument doc = QJsonDocument::fromJson(data, &error);
                if (!error.error) {
                    gcr.data = doc.object();
                    qDebug() << "got delete deviceId" << gcr.data;
                } else {
                    qWarning() << "Failed to parse delete deviceId" << data << error.errorString();
                }
            } else {
                qWarning() << "delete deviceId failed" << reply->error();
            }

            code(gcr);
        });
    });
}

void AndroidManagement::getPolicies(const QObject *receiver, const QString &enterpriseId, std::function<void (const GoogleCloudReply &, const std::vector<AndroidManagementPolicy> &)> code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &accessToken) {
        QUrl url = m_service;
        url.setPath(QLatin1String("/v1/enterprises/") + enterpriseId + QLatin1String("/policies"));

        qDebug() << "list policies" << url << enterpriseId;
        QNetworkReply *reply = m_nam->get(defaultRequest(url));
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            const QByteArray data = reply->readAll();
            std::vector<AndroidManagementPolicy> policies;

            qDebug() << "list policies" << reply->error();
            if (!reply->error()) {
                QJsonParseError error;
                QJsonDocument doc = QJsonDocument::fromJson(data, &error);
                if (!error.error) {
                    const QJsonArray array = doc.object()[QStringLiteral("policies")].toArray();
                    qDebug() << "got policies" << array;
                    for (const QJsonValue &p : array) {
                        policies.push_back(p.toObject());
                    }
                } else {
                    qWarning() << "Failed to parse policies" << data << error.errorString();
                }
            } else {
                qWarning() << "get policies failed" << reply->error();
            }

            code(accessToken, policies);
        });
    });
}

void AndroidManagement::getPolicy(const QObject *receiver, const QString &enterpriseId, const QString &policyId, std::function<void (const GoogleCloudReply &, const AndroidManagementPolicy &)> code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &accessToken) {
        QUrl url = m_service;
        url.setPath(QLatin1String("/v1/enterprises/") + enterpriseId + QLatin1String("/policies/") + policyId);

        QNetworkRequest req = defaultRequest(url);
        qDebug() << "list devices" << url << enterpriseId;
        QNetworkReply *reply = m_nam->get(req);
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            QJsonObject obj;
            const QByteArray data = reply->readAll();
            qDebug() << "get policy" << reply->error() << data;
            if (!reply->error()) {
                QJsonParseError error;
                QJsonDocument doc = QJsonDocument::fromJson(data, &error);
                if (!error.error) {
                    obj = doc.object();
                    qDebug() << "got policy" << doc.object();
                } else {
                    qWarning() << "Failed to parse google token file" << data << error.errorString();
                }
            } else {
                qWarning() << "get policy failed" << reply->error();
            }

            code(accessToken, obj);
        });
    });
}

void AndroidManagement::patchPolicy(const QObject *receiver, const QString &enterpriseId, const QString &policyId, const QString &updateMask, const QJsonObject &policy, std::function<void (const GoogleCloudReply &)> code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &accessToken) {
        QUrl url = m_service;
        url.setPath(QLatin1String("/v1/enterprises/") + enterpriseId + QLatin1String("/policies/") + policyId);

        if (!updateMask.isEmpty()) {
            QUrlQuery query;
            query.addQueryItem(QStringLiteral("updateMask"), updateMask);
            url.setQuery(query);
        }

        QNetworkRequest req = defaultRequest(url);
        req.setHeader(QNetworkRequest::ContentTypeHeader, QByteArrayLiteral("application/json"));
        qDebug() << "patch policy" << url << enterpriseId;
        QNetworkReply *reply = m_nam->sendCustomRequest(req, QByteArrayLiteral("PATCH"), QJsonDocument(policy).toJson(QJsonDocument::Compact));
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            const QByteArray data = reply->readAll();
            GoogleCloudReply gcr;
            qDebug() << "patch policy reply" << reply->error() << data;
            if (!reply->error()) {
                QJsonParseError error;
                QJsonDocument doc = QJsonDocument::fromJson(data, &error);
                if (!error.error) {
                    gcr.data = doc.object();
                    qDebug() << "got patch policy" << doc.object();
                } else {
                    qWarning() << "Failed to parse google token file" << data << error.errorString();
                }
            } else {
                qWarning() << "patch policy failed" << reply->error();
            }

            code(gcr);
        });
    });
}

void AndroidManagement::deletePolicy(const QObject *receiver, const QString &enterpriseId, const QString &policyId, std::function<void (const GoogleCloudReply &)> code)
{
    deletePolicy(receiver, QLatin1String("enterprises/") + enterpriseId + QLatin1String("/policies/") + policyId, code);
}

void AndroidManagement::deletePolicy(const QObject *receiver, const QString &fullPolicyId, std::function<void (const GoogleCloudReply &)> code)
{
    getAccessToken(receiver, [=] (const GoogleCloudReply &accessToken) {
        QUrl url = m_service;
        url.setPath(QLatin1String("/v1/") + fullPolicyId);

        qDebug() << "delete policyId" << url << fullPolicyId;
        QNetworkReply *reply = m_nam->deleteResource(defaultRequest(url));
        connect(reply, &QNetworkReply::finished, receiver, [=] {
            const QByteArray data = reply->readAll();
            GoogleCloudReply gcr;
            qDebug() << "delete policyId" << reply->error() << data;
            if (!reply->error()) {
                QJsonParseError error;
                QJsonDocument doc = QJsonDocument::fromJson(data, &error);
                if (!error.error) {
                    gcr.data = doc.object();
                    qDebug() << "got delete policyId" << gcr.data;
                } else {
                    qWarning() << "Failed to parse delete policyId" << data << error.errorString();
                }
            } else {
                qWarning() << "delete policyId failed" << reply->error();
            }

            code(gcr);
        });
    });
}
