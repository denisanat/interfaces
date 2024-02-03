#include "bola.h"
#include <math.h>
#include <QBrush>
#include <QDebug>

Bola::Bola() {
	posX = posY = 300;
	velX = 0.3;
	velY = -1;
	especial = false;
	
	vidas = 10;
	
	color = QColor(rand()%256,rand()%256,rand()%256);
	esImagen = false;
}

void Bola::anyadirChoque(int ind){
	Choque choque;
	choque.iOtraBola = ind;
	choque.x = posX;
	choque.y = posY;
	
	posicionesChoques.append(choque);


}

void Bola::mover(int anchura, int altura){
	anchuraJuego = anchura;
	alturaJuego = altura;
  posX = posX + velX ;
	posY= posY + velY ;
		
	if (posX > anchura - diametro) 
		velX = -fabs(velX);
	
	if (posX < 0) 
		velX = fabs(velX);
		
	if (posY > altura- diametro) {
		velY = - fabs(velY);
		}
	
	if (posY < 0) 
		velY = fabs(velY);
}

void Bola::pintar(QPainter &pintor){

	if (especial)
	pintor.drawEllipse(posX - 3 , posY - 3, diametro + 6, diametro + 6);

	pintor.setBrush(QColor(0,0,0));
	QString texto = QString("vidas: ") + QString::number(vidas);
	pintor.drawText(posX,posY-10,texto);
	
	pintor.drawText(posX,posY+diametro+12 ,nombre);

	if (!esImagen ) {
		pintor.setBrush(color);
		pintor.drawEllipse(this->posX,posY,diametro,diametro);
	}
	
	if (esImagen) {
		pintor.drawImage(posX,posY,imagen);
	
	}	
}


void Bola::establecerImagen(){
	imagen = QImage("imagenes/carita1.png");
	if (imagen.isNull() ) 
		qDebug() << "Panico: La imagen no sirve " ;
	imagen = imagen.scaled(diametro,diametro);
	esImagen = true;
}

void Bola::establecerImagen(QString ruta){
	imagen = QImage(ruta);
	if (imagen.isNull() ) 
		qDebug() << "Panico: La imagen no sirve " ;
	imagen = imagen.scaled(diametro,diametro);
	esImagen = true;
}



float Bola::distancia(Bola* otra) {
	float dist = sqrtf( powf(posX - otra->posX,2 ) +
											powf(posY - otra->posY,2 ));

	return dist;

}

bool Bola::choca(Bola *otra) {
		bool hayChoque = false ;
		if ( distancia(otra) > diametro )
				return false;
	 
	 Bola * arriba, *abajo;
	 Bola * izq, *der;
	 
	 /* Posicion horizontal */
	 if (posX < otra->posX) {
	 		izq = this;
	 		der = otra;
	 } else {
	 		der = this;
	 		izq = otra;
	 }
	 
	 if (izq->velX > der->velX) {
	 		float aux = der->velX;
	 		der->velX = izq->velX;
	 		izq->velX = aux;
	 		hayChoque = true;
	 }
	 	
	 	/* posicion Y */
	 	 if (posY < otra->posY) {
	 		arriba = this;
	 		abajo = otra;
	 } else {
	 		abajo = this;
	 		arriba = otra;
	 }
	 
	 if (arriba->velY > abajo->velY) {
	 		float aux = arriba->velY;
	 		arriba->velY = abajo->velY;
	 		abajo->velY = aux;
	 		hayChoque = true;
	 }
	 	

		return hayChoque;
}






