#ifndef OPTIONS_H
#define OPTIONS_H

#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QSlider>
#include <QTextEdit>
#include <QSpinBox>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QApplication>

class LogOut : public QTextEdit
{
	Q_OBJECT
public:
	LogOut();
	~LogOut();

	public slots:

	void Print_Vitesse(int vitesse);
	void Print_Chances(int chances);
	void Print_Debug_CMD(int state);
	void Print_Debug_FPGA(int state);
	void Print_Debug_Fille(int state);
	void Print_une_vie();
	void Print_deux_vies();
	void Print_trois_vies();

};




class Options :public QWidget
{
	Q_OBJECT
public:
	Options();
	~Options();

	QRadioButton *une_vie;
	QRadioButton *deux_vies;
	QRadioButton *trois_vies;

	QSlider *Vitesse;
	QSlider *Chances;

	QPushButton *retour;
	LogOut *events;

};



#endif // !ACCEUIL_H