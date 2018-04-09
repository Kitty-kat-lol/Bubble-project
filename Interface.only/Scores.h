#ifndef SCORES_H
#define SCORES_H

struct stru_scores
{
	QString name;
	int score;
};


class Scores :public QWidget
{
	Q_OBJECT
public:
	Scores();
	~Scores();
	
	QPushButton *reinit;
	QPushButton *save;
	QPushButton *act;
	
	stru_scores the_scores[100];


//public slots:

};

#endif