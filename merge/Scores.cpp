#include "Scores.h"




//Scores
Scores::Scores()
{
	the_scores = new stru_scores[100];

	the_scores[0].name = "BOB";
	the_scores[0].score = 500000;
	the_scores[1].name = "JAQUE123";
	the_scores[1].score = 235000;
	the_scores[2].name = "Claudette";
	the_scores[2].score = 243000;
	the_scores[3].name = "PAPA";
	the_scores[3].score = 100100;
	the_scores[4].name = "GERARD-LOL-0P";
	the_scores[4].score = 500;

	QVBoxLayout *list = new QVBoxLayout;
	QHBoxLayout *top = new QHBoxLayout;
	
	reinit = new QPushButton("Reinitialiser les Scores");
	save = new QPushButton("Sauvgarder les Scores");
	act = new QPushButton("Actualiser les Scores");

	top->addWidget(reinit);
	top->addWidget(save);
	top->addWidget(act);

	QLabel *title = new QLabel("Top Scores");

	QGridLayout *box = new QGridLayout;
	QLabel *first = new QLabel("First");
	QLabel *second = new QLabel("Second");
	QLabel *third = new QLabel("Third");
	QLabel *fourth = new QLabel("Fourth");
	QLabel *fifth = new QLabel("Fift");

	QLabel *first_n = new QLabel(the_scores[0].name);
	QLabel *second_n = new QLabel(the_scores[1].name);
	QLabel *third_n = new QLabel(the_scores[2].name);
	QLabel *fourth_n = new QLabel(the_scores[3].name);
	QLabel *fifth_n = new QLabel(the_scores[4].name);

	QLabel *first_s = new QLabel(QString::number(the_scores[0].score));
	QLabel *second_s = new QLabel(QString::number(the_scores[1].score));
	QLabel *third_s = new QLabel(QString::number(the_scores[2].score));
	QLabel *fourth_s = new QLabel(QString::number(the_scores[3].score));
	QLabel *fifth_s = new QLabel(QString::number(the_scores[4].score));

	box->addWidget(title, 0, 0);

	box->addWidget(first, 1, 1);
	box->addWidget(second, 2, 1);
	box->addWidget(third, 3, 1);
	box->addWidget(fourth, 4, 1);
	box->addWidget(fifth, 5, 1);

	box->addWidget(first_n, 1, 2);
	box->addWidget(second_n, 2, 2);
	box->addWidget(third_n, 3, 2);
	box->addWidget(fourth_n, 4, 2);
	box->addWidget(fifth_n, 5, 2);

	box->addWidget(first_s, 1, 3);
	box->addWidget(second_s, 2, 3);
	box->addWidget(third_s, 3, 3);
	box->addWidget(fourth_s, 4, 3);
	box->addWidget(fifth_s, 5, 3);

	list->addLayout(top);
	list->addLayout(box);

	setLayout(list);
	
	//connect
	QObject::connect(reinit, SIGNAL(clicked()), this, SLOT(reinit_scores()));
	QObject::connect(save, SIGNAL(clicked()), this, SLOT(w_scores()));
	QObject::connect(act, SIGNAL(clicked()), this, SLOT(gets_scores()));

}

Scores::~Scores()
{
	
}

void Scores::add_scores(stru_scores act)
{
	int i = 0;
	while (the_scores[i].name != "")
	{
		int a = the_scores[i].score;
		int b = act.score;

		if (a <= b)
		{
			the_scores[i].name = act.name;
			the_scores[i].score = act.score;
			return;
		}
		i = i + 1;
	}
	the_scores[i].name = act.name;
	the_scores[i].score = act.score;
	return;
}

void Scores::gets_scores()
{
	QFile file("scores.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;

	QTextStream in(&file);
	int i = 0;
	while (!in.atEnd() && i != 99) {
		QString line = in.readLine();
		QStringList list = line.split(' ', QString::SkipEmptyParts);
		the_scores[i].name = list[0];
		the_scores[i].score = list[1].toInt();
		i = i + 1;

	}

}

void Scores::w_scores()
{
	QFile file("scores.txt");
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return;

	QTextStream out(&file);
	int i = 0;
	while (the_scores[i].name != "")
	{
		out << the_scores[i].name << " " << the_scores[i].score << "\n";
		std::cout << the_scores[i].name.toStdString() << " " << the_scores[i].score << "\n";
		i = i + 1;
	}
	return;
}

void Scores::reinit_scores()
{
	the_scores[0].name = "BOB";
	the_scores[0].score = 500000;
	the_scores[1].name = "JAQUE123";
	the_scores[1].score = 235000;
	the_scores[2].name = "Claudette";
	the_scores[2].score = 243000;
	the_scores[3].name = "PAPA";
	the_scores[3].score = 100100;
	the_scores[4].name = "GERARD-LOL-0P";
	the_scores[4].score = 500;
	int i = 5;
	while (the_scores[i].name != "" && i != 99)
	{
		the_scores[i].name = "";
		the_scores[i].score = 0;
		i = i + 1;
	}
	return;
}
