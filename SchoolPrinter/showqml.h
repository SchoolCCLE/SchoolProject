#ifndef SHOWQML_H
#define SHOWQML_H

#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQuickItem>
#include <QSize>
#include <QObject>


class ShowQml : public QQuickView
{
    Q_OBJECT
public:
    explicit ShowQml();
    QQmlContext* getContext();
    QQmlEngine* getEngine() const;
    QQuickItem* getRootItem() const;
    void setQml(QString qmlFile);
signals:

public slots:
    void accessGranted(bool);
private:
    QQmlContext* context_;
    QQmlEngine* engine_;
    QQuickItem* rootItem_;
    QSize screenSize_;
};

#endif // SHOWQML_H
