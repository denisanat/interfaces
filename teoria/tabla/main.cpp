#include <QApplication>
#include "tablaidol.h"

int main(int argc, char *argv[])
{
     QApplication app(argc, argv);
     
  	 TablaIdol * tabla = new TablaIdol();
  	 
  	 tabla -> show();
     
     return app.exec();
}
