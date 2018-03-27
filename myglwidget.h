#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H
#include <GL/glu.h>
#include <QGLWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QTimer>
#include "brique.h"
#include "palet.h"
#include "boule.h"
#include "mur.h"
#include "jeu.h"
#include <QApplication>
#include <QDesktopWidget>


// Classe dediee a l'affichage d'une scene OpenGL
class MyGLWidget : public QGLWidget
{
    Q_OBJECT

public:

    // Constructeur
    MyGLWidget(QWidget * parent = nullptr);

    void SetJeu(Jeu* JeuPtr);

protected:

    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

private:
    // Timer d'animation
    float m_TimeElapsed { 0.0f };
    QTimer m_AnimationTimer;

    Jeu *Jeu_;
};

#endif // MYGLWIDGET_H
