#ifndef PLAY_H
#define PLAY_H

#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <Qmessagebox>
#include <QFile>
#include <QTextStream>

struct stru_play
{
	QString name;
	QString score;
};

class Play :public QWidget
{
	Q_OBJECT
public:
	Play();
	~Play();

	QPushButton *Start;
	QPushButton *Quit;

	public slots:

	void Quit_play();
	void Start_play();

};

#endif