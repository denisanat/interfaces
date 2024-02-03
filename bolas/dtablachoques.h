
#ifndef DTABLACHOQUES_H
#define DTABLACHOQUES_H
#include "ui_dtablachoques.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include <QAbstractTableModel>
#include <QModelIndex>
#include <QColor>

#include "bola.h"

class ModeloChoques;

class DTablaChoques : public QDialog, public Ui::DTablaChoques {
Q_OBJECT

public:
	DTablaChoques(QVector<Bola*> bPasadas, QWidget *parent = NULL);
	
		ModeloChoques * modelo ;


public slots:
	void slotEjemplo();
	void slotTemporizador();


};


class ModeloChoques : public QAbstractTableModel {
public:
		ModeloChoques();
		int maxChoques;
		QVector<Bola*>  bolas;

   Qt::ItemFlags flags(const QModelIndex &index) const ;

	QVariant	data(const QModelIndex &index,
								 int role = Qt::DisplayRole) const ;
	
	int	rowCount(const QModelIndex &parent = QModelIndex()) const ;
	int	columnCount(const QModelIndex &parent = QModelIndex()) const ;
	
	void actualiza();
	
	QVariant headerData(int section, 
						Qt::Orientation orientation,
						int role = Qt::DisplayRole) const;
						
	bool setData(	const QModelIndex &,
					const QVariant &,
					int role = Qt::EditRole )  ;					
						
};



#endif 
