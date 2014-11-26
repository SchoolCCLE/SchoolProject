#ifndef CARTRIDGESCONTROLLER_H
#define CARTRIDGESCONTROLLER_H
#include <printerengine.h>

class CartridgesController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<QObject*> cartridges READ cartridges WRITE setCartridges NOTIFY cartridgesChanged)
public:
    explicit CartridgesController(PrinterEngine::PrinterType printerType, QObject *parent = 0);

    QList<QObject*> cartridges() const
    {
        return m_cartridges;
    }
public slots:
    void setCartridges(QList<QObject*> arg)
    {
        if (m_cartridges == arg)
            return;

        m_cartridges = arg;
        emit cartridgesChanged(arg);
    }
    void setNumCartridges(int n_numCartridges)
    {
        this->n_numCartridges = n_numCartridges;
    }

signals:
    void cartridgesChanged(QList<QObject*> arg);
private:
    QList<QObject*> m_cartridges;
    int n_numCartridges;
};

#endif // CARTRIDGESCONTROLLER_H
