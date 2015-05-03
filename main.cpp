#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
		QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
		db.setDatabaseName("ihm.db");
		if (db.open())
			return a.exec();
		return -1;
}
