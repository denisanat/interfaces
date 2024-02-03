#ifndef _BOLA_H_
#define _BOLA_H_

#include <QPainter>
#include <QColor>
#include <QImage>

/* para ahorrar ficheros, hacemos aquí la clase Choque*/

class Choque {
public:
	float x,y;
	int iOtraBola;// pq no se eliminan ni insertan bolas
};


class Bola {
public:
	Bola();
	
	float posX,posY;
	float velY,velX;
	float anchuraJuego,alturaJuego;
	
	QVector <int> choques;
	QVector <Choque> posicionesChoques;
	int id;
	
	QImage imagen;
	bool esImagen;
	
	bool especial;
	int vidas;
	QString nombre;
	
		static const int diametro=50;
	
	void anyadirChoque(int iOtra);
	
	QColor color;
	float distancia(Bola* otra);
	void mover(int,int);
	void pintar(QPainter &);
	bool choca(Bola *);
	void establecerImagen();
	void establecerImagen(QString ruta);
};

#endif






