#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QVector>
#include <QAction>
#include <QMenu>

#include "bola.h"
#include "dtablabolas.h"
#include "dcontrolbolas.h"
#include "dposicionbolas.h"
#include "dtablachoques.h"
#include "panelposicioneschoques.h"

class MainWindow : public QMainWindow{
Q_OBJECT

public:
	MainWindow(QWidget *parent =NULL);

	QAction *actionDTablaBolas;	
	QAction *actionDControlBolas;
	QAction *actionDPosicionBolas;
	QAction *actionDTablaChoques;
	
	QAction *actionTemp;

	QVector<QAction * > accionesBolas;
	
	void paintEvent(QPaintEvent * evento);
void keyPressEvent(QKeyEvent * evento) ;
	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent * event);
	
	
	Bola * bolaJugador;
	
	QVector<Bola*> bolas;
	
	DTablaBolas * dTablaBolas;
	DControlBolas * dControlBolas;
	DPosicionBolas * dPosicionBolas;
	DTablaChoques * dTablaChoques;
	


	static const int NUMBOLAS=10;
	void crearBolas();
	void crearActions();
	void crearMenus();	
	
	
	
	
public slots:	
	void slotDTablaBolas();
	void slotDControlBolas();
	void slotDPosicionBolas();
	void slotDTablaChoques();
	void slotTemp();
	void slotBolas();
	void slotTemporizador();

};



#endif
