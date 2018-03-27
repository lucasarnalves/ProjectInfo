#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "jeu.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    // Fonction de gestion d'interactions clavier
    void keyPressEvent(QKeyEvent * event);
private:
    Ui::MainWindow *ui;
    float Pospalet_;
    Jeu Jeu_;
    // Timer d'animation
    float m_TimeElapsed { 0.0f };
    QTimer m_AnimationTimer;
};

#endif // MAINWINDOW_H
