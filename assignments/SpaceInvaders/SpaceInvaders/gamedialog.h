#pragma once


#include "config.h"
#include "menu.h"
#include "ship.h"
#include "swarm.h"
#include "swarminfo.h"
#include "inputstrategy.h"
#include <QDialog>
#include <QSoundEffect>
#include <QMouseEvent>
#include <QWidget>
#include <vector>
#include <sstream>
#include <QPainter>

namespace game {
class GameDialog : public QDialog {
    Q_OBJECT

public:
    GameDialog(QWidget* parent = nullptr);
    void generateAliens(const QList<SwarmInfo>& swarms);
    virtual ~GameDialog();

protected:
    QTimer* timer;
    void paintEvent(QPaintEvent* event);
    void paintLevel(QPainter& painter);
    void paintBullets(QPainter& painter);
    void updateBullets();
    void paintSwarm(QPainter& painter, AlienBase*& root);
    void checkSwarmCollisions(AlienBase*& root);
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void new_level(int);


    // ship and swarms
    Ship* ship;
    std::vector<Bullet*> bullets;
    AlienBase* swarms;  // swarms is the ROOT node of the composite
    QSoundEffect shipFiringSound;
    int next_instruct;

    // keys
    void keyPressEvent(QKeyEvent* event);

    // about the canvas
    int frames;
    const int WIDTH = 800;
    const int HEIGHT = 600;
    int level = 1;
    int SCALEDWIDTH;
    int SCALEDHEIGHT;
    int multiplier = 1;

    // collision...
    int get_collided_swarm(Bullet*& b, AlienBase*& root);
    int get_collided(Bullet*& b, AlienBase*& root);
    void addBullets(const QList<Bullet*>& list);
    int getClosest();

    // pausing & menu
    bool paused;
    bool ship_alive = true;
    void pauseStart();
    Menu* menu;

    // keyboard & mouse
    Input * remote;


    // score
    int gameScore;  // this run's score.
public slots:
    void nextFrame();
    // menus
    void showScore();
    void toggleKeyboard();
    void toggleMouse();
    void setFastSpeed();
    void setSlowSpeed();
    void exit();
    void reset();
};
}
