#ifndef PANELPOSICIONESCHOQUES_H
#define PANELPOSICIONESCHOQUES_H

#include <QVector>
#include <QWidget>
#include <QHBoxLayout>
#include <QPaintEvent>
#include "bola.h"

class PanelPosicionesChoques : public QWidget {
Q_OBJECT

public:
	PanelPosicionesChoques(Bola * bPasada,
												 int ind,
												 QWidget * parent =NULL);

	Bola * miBola;
	int indFiltro;
	
	void paintEvent(QPaintEvent * event);
	
};




#endif



