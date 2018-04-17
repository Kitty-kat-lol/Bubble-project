#ifndef SCORES_H
#define SCORES_H

#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QLabel>

#include <QFile>
#include <QTextStream>
#include <QTextedit>
#include <iostream>
struct stru_scores
{
	QString name;
	qreal score;
};

class Scores :public QWidget
{
	Q_OBJECT
public:
	Scores();
	~Scores();

	stru_scores *the_scores;

	QTextEdit *textbox = new QTextEdit;
	QPushButton *reinit;
	QPushButton *save;
	QPushButton *act;
	
	public slots:
	
	void add_scores(stru_scores act);
	void gets_scores();
	void w_scores();
	void reinit_scores();

};

#endif