//
// Created by Elias Aggergaard Larsen on 25/12-2025.
//

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QUrl>
#include <QString>
#include "LiFMQt/LiFMQt.hpp"

void LiFMQt::launch()
{
  int argc = 1;
  char* argv[] = {const_cast<char*>("LiFM")};
  QGuiApplication app(argc, argv);
  Q_INIT_RESOURCE(resources);

  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/Views/main.qml")));

  app.exec();
}
