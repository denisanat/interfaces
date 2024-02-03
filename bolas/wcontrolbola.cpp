
#include "wcontrolbola.h"
#include <QDebug>

WControlBola::WControlBola(Bola * bPasada, QWidget *parent): QWidget(parent),miBola(bPasada) {
		setupUi(this);

	miBola = bPasada;
	
	QHBoxLayout *layoutBotones = new QHBoxLayout();
		for (int i=0;i<miBola->choques.size();i++){
			QPushButton *nB= new QPushButton(QString::number(i));
			layoutBotones->addWidget(nB);
			botonesParar.append(nB);
			connect(nB,SIGNAL(clicked()),
							this,SLOT(slotBotonParar()));
		}
			
		fBotonesChoques->setLayout(layoutBotones);
	connect(bParar, SIGNAL(clicked()),
			this, SLOT(slotParar()));
		
	leNombre->setFocus();
	leNombre->setText(bPasada->nombre);
	connect(leNombre,SIGNAL(textChanged(const QString &)),
				this,SLOT(slotCambiarNombre(const QString &)));
}

void WControlBola::slotParar(){

	miBola->velX = miBola->velY = 0;

}


void WControlBola::slotEjemplo(){

	

}

void WControlBola::slotBotonParar(){
	QPushButton * bCulpable =
		 qobject_cast<QPushButton*>(sender());
		 
	for (int i=0;i< botonesParar.size(); i++)
		if (botonesParar.at(i) == bCulpable )
			miBola->choques[i] = 0 ;
	
}

void WControlBola::slotCambiarNombre(const QString &cad){
	miBola->nombre = cad;

}


