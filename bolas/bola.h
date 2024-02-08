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
		
		float posX, posY;
		float velY, velX;
		static const int diametro = 50;
		QColor color;
		int vidas;
		QString nombre;
		
		QVector <int> choques;
		QVector <Choque> posicionesChoques;
		int id;
		
		QImage imagen;
		bool esImagen;
		
		bool especial;
		
		float anchuraJuego,alturaJuego;
		
		void anyadirChoque(int iOtra);
		
		float distancia(Bola* otra);
		void mover(int,int);
		void pintar(QPainter &);
		bool choca(Bola *);
		void establecerImagen();
		void establecerImagen(QString ruta);
};

#endif






