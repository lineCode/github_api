
#include <QCoreApplication>
#include <QDebug>
#include <QNetworkAccessManager>

#include <github_api/github_api.hpp>
#include <github_api/request.hpp>


int main(int argc, char** argv)
{
    QCoreApplication qapp(argc, argv);
    QNetworkAccessManager manager;

    GitHubApi github(manager);
    std::unique_ptr<GitHub::IConnection> connection = github.connect();
    GitHub::Request request(connection.get());

    const QJsonDocument info = request.getUserInfo("Kicer86");
    const QByteArray raw = info.toJson();

    qInfo() << raw;

    return 0;
}
