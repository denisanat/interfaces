#include "mainwindow.h"
#include <math.h>
#include <QPainter>
#include <QColor>
#include <QTimer>
#include <QMenuBar>
#include <QFile>
#include <QTextStream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QDate>
#include <QMimeData>

#include <QMessageBox>


MainWindow::MainWindow(QWidget * parent ) : QMainWindow(parent){

		resize(800,600);
		
		dTablaBolas = NULL;
		dControlBolas = NULL;
		dPosicionBolas = NULL;
		dTablaChoques = NULL;
		
		QTimer *temporizador = new QTimer();
			temporizador->setInterval(40);
			temporizador->setSingleShot(false);
			temporizador->start();
		
		crearBolas();
		
		crearActions();
		crearMenus();
		setAcceptDrops(true);
		
		connect(temporizador,SIGNAL(timeout()),
					this,SLOT(slotTemporizador()));	
}

void MainWindow::crearActions(){					

		actionDTablaBolas = new QAction( "Tabla Bolas" );
			connect(actionDTablaBolas,SIGNAL( triggered() ),
					this, SLOT( slotDTablaBolas() ));
				
		actionDControlBolas = new QAction("Control Bolas");
			connect(actionDControlBolas,SIGNAL(triggered()),
					this, SLOT(slotDControlBolas()));		

		actionDPosicionBolas = new QAction("Posicion Bolas");
			connect(actionDPosicionBolas,SIGNAL(triggered()),
					this, SLOT(slotDPosicionBolas()));		

		actionDTablaChoques = new QAction("Choques");
			connect(actionDTablaChoques,SIGNAL(triggered()),
					this, SLOT(slotDTablaChoques()));		
		
		actionTemp = new QAction("TEMPORAL");
			connect(actionTemp,SIGNAL(triggered()),
					this, SLOT(slotTemp()));		

		for (int i=0; i<bolas.size();i++) {
			QAction * nueva = new QAction(bolas.at(i)->nombre);
				connect(nueva,SIGNAL(triggered()),
						this,SLOT(slotBolas()));
						
			nueva->setData(QVariant(i));
			accionesBolas.append(nueva);	
		}

}


void MainWindow::crearMenus() {

		QMenu * menuDialogos = menuBar()->addMenu("Info");
		menuDialogos->addAction(actionDTablaBolas);
			menuDialogos->addAction(actionDControlBolas);
		menuDialogos->addAction(actionDPosicionBolas);
		menuDialogos->addAction(actionDTablaChoques);
		menuDialogos->addAction(actionTemp);
		
		QMenu * menuBolas = menuBar()->addMenu("Bolas");
		for ( int i = 0 ; i < accionesBolas.size() ; i++ )
			menuBolas->addAction(accionesBolas.at(i));
}


void MainWindow::crearBolas(){

		QStringList nombres = { "heejin", "hyunjin", "haseul", "yeojin", "vivi", "gowon", "hyejoo" };

		for ( int i = 0 ; i < NUMBOLAS ; i++ ) {
	   		Bola * nueva = new Bola();
	   		nueva -> id = i;
			nueva -> choques.resize( NUMBOLAS );
	   	 	nueva -> posX = random() % width();
	   	 	nueva -> posY = random() % height();
	   	 	nueva -> velX = (float) ( rand() % 100 ) / 50 -1;
	   	 	nueva -> velY = (float) ( rand() % 100 ) / 50 -1;
	   	 
	   	 	nueva->nombre = nombres.at( i % nombres.size());
		   	nueva->velX = nueva->velX *3;
		   	nueva->velY = nueva->velY *3;
		   	
		   	if ( i % 2 == 0 ) 
		   	 	nueva -> establecerImagen();

	   		bolas.append(nueva);    
		}
		
		bolaJugador = new Bola();
		bolaJugador -> especial = true;
		bolaJugador -> velX = bolaJugador -> velY = 0;
		bolaJugador -> posX = bolaJugador -> posY = 400;
		bolaJugador -> color = QColor( 0, 0, 0 );
    
}


void MainWindow::paintEvent( QPaintEvent * ){
	
		QPainter pintor( this );
		
		for ( int i = 0 ; i < bolas.size() ; i++ )
			bolas[i] -> pintar( pintor );
	   	 
	 	bolaJugador -> pintar( pintor );
}


void MainWindow::slotTemporizador() {
	
		for ( int i = 0 ; i < bolas.size() ; i++ )
	   		bolas[i] -> mover( width(), height() );	
	   	 
		bolaJugador -> mover( width(), height() );
	  	 
	 	for (int i=0; i< bolas.size();i++)  	 
	 		for (int j=0; j< bolas.size();j++) 
	 			if ( (i != j ) && bolas.at(i)->choca(bolas.at(j) )) {
	 				bolas.at(i)->vidas--;
	 				bolas.at(j)->vidas--;
	 				bolas.at(i)->choques[j]++;
	 				bolas.at(j)->choques[i]++; 
	 				bolas.at(i)->anyadirChoque(j);
	 				bolas.at(j)->anyadirChoque(i); 								
	 				
	 		}
	 	
		for ( int i = 0 ; i < bolas.size() ; i++ )  	 	
			if ( bolaJugador -> choca( bolas.at(i) ) )
				bolaJugador -> vidas--;

		update();
}


void MainWindow::keyPressEvent( QKeyEvent * evento ) {

		int teclaPulsada = evento->key();
		
		switch (teclaPulsada) {
			case Qt::Key_Up:
					bolaJugador->velY -= 0.1  ;
					break;
			case Qt::Key_Down:
					bolaJugador->velY += 0.1  ;
					break;
			case Qt::Key_Left:
					bolaJugador->velX -= 0.1  ;
					break;
			case Qt::Key_Right:
					bolaJugador->velX += 0.1  ;
					break;														
		};

}


void MainWindow::dragEnterEvent( QDragEnterEvent *event ) {
		event -> acceptProposedAction();
}


void MainWindow::dropEvent( QDropEvent * event ) {

		if ( ! event -> mimeData() -> hasText() ) {
			QMessageBox::information(
						this,
						"dropEvent",
						"no tiene texto",
						QMessageBox::Ok );
						
			return;		
		}
			
		qDebug() << event -> mimeData() -> text();
		
		QString rutaArchivo;
		rutaArchivo = event -> mimeData() -> urls().first().path();
		
	 	Bola * nueva = new Bola();
		   	nueva -> posX = event -> pos().x();
		   	nueva -> posY = event -> pos().y();
		   	nueva -> velX = (float) ( rand() % 100 ) / 50 -1;
		   	nueva -> velY = (float) ( rand() % 100 ) / 50 -1;
	   	 
		   	nueva -> nombre = QString( "Bolita" );
		   	nueva -> velX = nueva -> velX * 3;
		   	nueva -> velY = nueva -> velY * 3;
			nueva -> establecerImagen( rutaArchivo );

		bolas.append( nueva );	
}


void MainWindow::slotDTablaBolas() {

		if ( dTablaBolas == NULL )
			dTablaBolas = new DTablaBolas(bolas);

		dTablaBolas->show();
}


void MainWindow::slotDControlBolas() {

		if ( dControlBolas == NULL )
			dControlBolas = new DControlBolas(bolas);

		dControlBolas->show();

}


void MainWindow::slotDPosicionBolas() {

		if ( dPosicionBolas == NULL )
			dPosicionBolas = new DPosicionBolas(bolas);

		dPosicionBolas->show();
}


void MainWindow::slotDTablaChoques() {

		if ( dTablaChoques == NULL )
			dTablaChoques = new DTablaChoques(bolas);

		dTablaChoques->show();
}


void MainWindow::slotTemp() {

		PanelPosicionesChoques * p = new PanelPosicionesChoques( bolas.at(0), -1 ); // -1 to disable ball filtering
		
		p -> show();
	
}


void MainWindow::slotBolas(){

		QObject * culpable = sender();
		QAction * accCulpable;
		accCulpable = qobject_cast<QAction *> (culpable);
	  
		int i = accCulpable->data().toInt();
	  
		PanelPosicionesChoques *p;
	  	Bola *bola = bolas.at(i);
	  	p = new 	PanelPosicionesChoques(bola,-1 ); // -1 to disable ball filtering
		
		p->show();
	
}

