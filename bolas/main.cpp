#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
     QApplication app(argc, argv);
     
  	 MainWindow	* juego = new MainWindow();
  	 
  	 juego->show();
     
     return app.exec();
}
