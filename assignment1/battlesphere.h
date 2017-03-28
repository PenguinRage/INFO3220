#ifndef BATTLESPHERE_H
#define BATTLESPHERE_H

#include <QDialog>
#include <QPainter>
#include <QPixmap>
#include <QSound>
#include <QTimer>

#include <config.h>

namespace si {

    class BattleSphere : public QDialog
    {
        Q_OBJECT
        QPixmap defender;
        QPixmap bullet;
        QSound sound;
        QTimer* timer;
        Config* config;
        int dx = 0;
        int dy = 350;
        int ds = 3;
        int bx = -1000;
        int by = -1000;
        int bs = 10;
    public:
        BattleSphere(QWidget *parent = nullptr);
        ~BattleSphere();
        int getNumber(string key);
        bool validateInt(const string input);
    protected:
        void paintEvent(QPaintEvent *event);
    public slots:
        void nextFrame();
    };

} // end namespace si

#endif // BATTLESPHERE_H
