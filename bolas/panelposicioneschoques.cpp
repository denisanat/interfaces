#include "panelposicioneschoques.h"
#include <QBrush>

PanelPosicionesChoques::PanelPosicionesChoques(
			Bola * bPasada,
			int  ind,
			QWidget *){
	
	miBola = bPasada;
	
	indFiltro = ind;
	
	resize(400,400);	
}



void PanelPosicionesChoques::paintEvent(QPaintEvent * event){
	
	QPainter pintor(this);
	QBrush brush(miBola->color,Qt::Dense4Pattern);

	QString texto = QString::number(indFiltro);
	texto = texto + QString("  ") + miBola->nombre;
	pintor.drawText(10,10,texto);
	
	for ( int i=0; i<miBola->posicionesChoques.size();i++){
		int iOtra = miBola->posicionesChoques.at(i).iOtraBola;
		if  ( indFiltro != iOtra 
			 && indFiltro != -1  )// -1 => all collisions   
				 continue;
		float xp = miBola->posicionesChoques.at(i).x;
		float yp = miBola->posicionesChoques.at(i).y;
		xp = xp * width() / miBola->anchuraJuego;
		yp = yp * height() / miBola->alturaJuego;
		pintor.drawPoint( xp,yp);
		pintor.drawEllipse( xp-4,yp-4,8,8);
		
	}
		
	float posicionX = miBola->posX * width() / miBola->anchuraJuego;
	float posicionY = miBola->posY * height() / miBola->alturaJuego;
			
	pintor.fillRect( posicionX-3,0,6,height(),brush);
	pintor.fillRect( 0,posicionY-3,width(),6,brush);

}


	
	
	
	
	
	
