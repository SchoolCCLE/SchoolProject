#include "showqml.h"
#include <QQmlComponent>
#include <QScreen>

ShowQml::ShowQml()
{
    screenSize_ = screen()->availableSize();
    engine_ = new QQmlEngine();
    context_ = new QQmlContext(engine_);
    QQuickView(engine_,NULL);
}

QQmlContext* ShowQml::getContext()
{
    return context_;
}

QQmlEngine *ShowQml::getEngine() const
{
    return engine_;
}

QQuickItem *ShowQml::getRootItem() const
{
    return rootItem_;
}

void ShowQml::setQml(QString qmlFile)
{
    QQmlComponent* component = new QQmlComponent(engine_,QUrl(QStringLiteral("qrc:/%1").arg(qmlFile)));
    rootItem_ = qobject_cast<QQuickItem*>(component->create(context_));
    rootItem_->setParentItem(this->contentItem());
    resize(rootItem_->width(),rootItem_->height());
    setX(screenSize_.width()/2 - width()/2);
    setY(screenSize_.height()/2 - height()/2);
}

void ShowQml::accessGranted(bool access)
{
    if(access)
    {
        setQml("HomeScreen.qml");
    }
}
