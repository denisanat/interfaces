
#include "dtablachoques.h"
#include <QDebug>
#include <QTimer>
#include <QFont>

DTablaChoques::DTablaChoques(QVector<Bola*> bPasadas, 
		QWidget *parent): QDialog(parent){
		setupUi(this);

	modelo =new ModeloChoques();
	
	modelo->bolas = bPasadas;

	QFont fuente = vistaChoques->font();
	fuente = QFont(fuente.family(),fuente.pointSize()*2);
	vistaChoques->setFont(fuente);
	vistaChoques->setModel(modelo);

	QTimer *temporizador = new QTimer();
	temporizador->setInterval(1000);
	temporizador->setSingleShot(false);
	temporizador->start();
	
	connect(temporizador,SIGNAL(timeout()),
				this,SLOT(slotTemporizador()));
}
void DTablaChoques::slotTemporizador() {
	
	modelo->actualiza();
}


void DTablaChoques::slotEjemplo(){

}


ModeloChoques::ModeloChoques() : QAbstractTableModel(){
		maxChoques = 0;
}

Qt::ItemFlags ModeloChoques::flags(const QModelIndex &index) const {

	return Qt::ItemIsEditable | QAbstractTableModel::flags(index);

}




QVariant	ModeloChoques::data(const QModelIndex &index,
								 int role ) const {

			int fila = index.row();
			int columna = index.column();
			
			int valor = bolas.at(fila)->choques.at(columna);
			
			if (role	== Qt::BackgroundColorRole &&
					  maxChoques !=0)
				return QVariant(
					 QColor( 255,
					 	255 - ( valor*255)/maxChoques,
					 	255 - ( valor*255)/maxChoques));				
			
			if (role != Qt::DisplayRole)
				return QVariant();
		
			
			return QVariant( QString::number(valor));
}
	
int	ModeloChoques::rowCount(const QModelIndex &parent ) const {

	return bolas.size();


}

int	ModeloChoques::columnCount(	const QModelIndex &parent ) const {

	return bolas.size();

}
	


void ModeloChoques::actualiza() {
	for (int i=0; i< bolas.size();i++)
		for (int j=i+1; j< bolas.size();j++)
			if (bolas.at(i)->choques.at(j) > 	maxChoques)
					maxChoques= bolas.at(i)->choques.at(j);

	QVector<int> rolesChanged;
	rolesChanged.append(Qt::BackgroundColorRole);
	rolesChanged.append(Qt::DisplayRole);
	emit dataChanged(
		index(0,0),
		index(bolas.size(),bolas.size()),
		rolesChanged);
	


}


QVariant ModeloChoques :: headerData(int section, Qt::Orientation orientation, int role ) const {


if (role != Qt::DisplayRole )  return QVariant();

	return QVariant(section);
	

}

bool ModeloChoques::setData(	const QModelIndex  & indice,
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
