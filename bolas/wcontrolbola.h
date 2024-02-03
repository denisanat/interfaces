
#ifndef WCONTROLBOLA_H
#define WCONTROLBOLA_H
#include "ui_wcontrolbola.h"

#include <QVector>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include "bola.h"

class WControlBola : public QWidget, public Ui::WControlBola {
Q_OBJECT

public:
	WControlBola(Bola * , QWidget *parent = NULL);

	QVector<QPushButton * > botonesParar;
	
	Bola * miBola;
	
public slots:
	void slotParar();
	void slotCambiarNombre(const QString &);
	void slotEjemplo();
	void slotBotonParar();

};

#endif 
