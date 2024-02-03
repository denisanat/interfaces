
#include "dtablabolas.h"
#include <QDebug>
#include <QTimer>

DTablaBolas::DTablaBolas(QVector<Bola*> bPasadas, 
		QWidget *parent): QDialog(parent){
		setupUi(this);


	modelo =new ModeloTabla();
	
	modelo->bolas = bPasadas;

	vista->setModel(modelo);

	QTimer *temporizador = new QTimer();
	temporizador->setInterval(1000);
	temporizador->setSingleShot(false);
	temporizador->start();
	
	connect(temporizador,SIGNAL(timeout()),
				this,SLOT(slotTemporizador()));
	
}

void DTablaBolas::slotTemporizador() {
	
	modelo->actualiza();
}

void DTablaBolas::slotEjemplo(){

}


Qt::ItemFlags ModeloTabla::flags(const QModelIndex &index) const {

	return Qt::ItemIsEditable | QAbstractTableModel::flags(index);

}




QVariant	ModeloTabla::data(const QModelIndex &index,
								 int role ) const {

			int fila = index.row();
			int columna = index.column();
			
			if (role	== Qt::BackgroundColorRole)
				return QVariant( bolas.at(fila)->color);				
			
			if (role != Qt::DisplayRole)
				return QVariant();
						
		  float valor;
		  
			switch ( columna ) {
				case 0:
						valor = bolas.at(fila)->posX;
						break;
				case 1:
						valor = bolas.at(fila)->posY;
						break;
				case 2:
						valor = bolas.at(fila)->velX;
						break;
				case 3:
						valor = bolas.at(fila)->velY;
						break;
	
			}
								
			return QVariant( QString::number(valor));
}
	
int	ModeloTabla::rowCount(const QModelIndex &parent ) const {

	return bolas.size();


}

int	ModeloTabla::columnCount(	const QModelIndex &parent ) const {

	return 4;

}
	


void ModeloTabla::actualiza() {

	emit layoutChanged();

}


QVariant ModeloTabla :: headerData(int section, Qt::Orientation orientation, int role ) const {

	QStringList lista = {"PosX","PosY", "VelX","VelY"};


if (role != Qt::DisplayRole )  return QVariant();

	QString cadena ;


	if (orientation == Qt::Horizontal) {
		return QVariant(lista.at(section));
	}
	if (orientation == Qt::Vertical) {
		cadena = QString("Bola ") + QString::number(section);
		return QVariant(cadena);
	}

}

bool ModeloTabla::setData(	const QModelIndex  & indice,
					const QVariant & value,
					int role  )  {
			
			if (role != Qt::EditRole) 
				return false;
				
			Bola * laBola = bolas.at(indice.row());	
					
			bool resultado = false;		
			float valor = value.toString().toFloat( &resultado);
			
			if ( ! resultado) return false;
			
			switch ( indice.column()){
			case 0:
				laBola->posX = valor; break;
			case 1:
				laBola->posY = valor ; break;
			case 2:
				laBola->velX = valor;	break;
			case 3:
				laBola->velY = valor;	break;
	};

	QModelIndex ini = index(0,0);
	QModelIndex fin = index(bolas.size()- 1 ,3);
	emit dataChanged(ini,fin);
				
			return true;		
		}




