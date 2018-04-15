#include "Options.h"


Options::Options()
{
	QVBoxLayout *general_layout = new QVBoxLayout;

	QGridLayout *top_part = new QGridLayout;
	QGridLayout *bottom_part = new QGridLayout;

	QVBoxLayout *column1 = new QVBoxLayout;
	QVBoxLayout *column2 = new QVBoxLayout;

	QLabel *Titre = new QLabel("OPTIONS");

	QCheckBox *Debug_FPGA = new QCheckBox("Debug FPGA");
	QCheckBox *Debug_CMD = new QCheckBox("Debug CMD");
	QCheckBox *Fille = new QCheckBox("Fille");
	

	QWidget *Vies = new QWidget;
	QHBoxLayout *Nb_vies = new QHBoxLayout;
	une_vie = new QRadioButton("1 vie (Multiplicateur x3)");
	une_vie->setChecked(true);
	deux_vies = new QRadioButton("2 vies (Multiplicateur x2)");
	trois_vies = new QRadioButton("3 vies (Multiplicateur x1)");
	Nb_vies->addWidget(une_vie);
	Nb_vies->addWidget(deux_vies);
	Nb_vies->addWidget(trois_vies);
	Vies->setLayout(Nb_vies);

	QLabel *Titre_vitesse = new QLabel("Vitesse de la bulle");
	Vitesse = new QSlider(Qt::Horizontal);
	Vitesse->setMaximumWidth(200);
	Vitesse->setSliderPosition(30);
	QLabel *Titre_Chances = new QLabel("Chances de power-ups");
	QSlider *Chances = new QSlider(Qt::Horizontal);
	Chances->setMaximumWidth(200);
	Chances->setSliderPosition(15);

	column1->addWidget(Debug_CMD);
	column1->addWidget(Debug_FPGA);
	column1->addWidget(Fille);
	//column1->addWidget(Titre_Nb_vies);
	column1->addWidget(Vies);

	column2->addWidget(Titre_vitesse);
	column2->addWidget(Vitesse);
	column2->addWidget(Titre_Chances);
	column2->addWidget(Chances);


	//top_part->addLayout(column1, 1, 1);
	//top_part->addLayout(column2, 1, 2);

	top_part->addWidget(Debug_CMD, 2, 1);
	top_part->addWidget(Debug_FPGA, 3, 1);
	top_part->addWidget(Fille, 4, 1);
	top_part->addWidget(une_vie, 5, 1);
	top_part->addWidget(deux_vies, 6, 1);
	top_part->addWidget(trois_vies, 7, 1);
	top_part->addWidget(Titre_vitesse, 2, 2);
	top_part->addWidget(Vitesse, 3, 2);
	top_part->addWidget(Titre_Chances, 4, 2);
	top_part->addWidget(Chances, 5, 2);

	retour = new QPushButton("Quitter");
	events = new LogOut;
	bottom_part->addWidget(events);
	bottom_part->addWidget(retour);

	general_layout->addLayout(top_part);
	general_layout->addLayout(bottom_part);
	setLayout(general_layout);

	QObject::connect(Vitesse, SIGNAL(valueChanged(int)), events, SLOT(Print_Vitesse(int)));
	QObject::connect(Chances, SIGNAL(valueChanged(int)), events, SLOT(Print_Chances(int)));
	QObject::connect(Debug_CMD, SIGNAL(stateChanged(int)), events, SLOT(Print_Debug_CMD(int)));
	QObject::connect(Fille, SIGNAL(stateChanged(int)), events, SLOT(Print_Debug_Fille(int)));
	QObject::connect(Debug_FPGA, SIGNAL(stateChanged(int)), events, SLOT(Print_Debug_FPGA(int)));
	QObject::connect(une_vie, SIGNAL(clicked(bool)), events, SLOT(Print_une_vie()));
	QObject::connect(deux_vies, SIGNAL(clicked(bool)), events, SLOT(Print_deux_vies()));
	QObject::connect(trois_vies, SIGNAL(clicked(bool)), events, SLOT(Print_trois_vies()));

	QObject::connect(retour, SIGNAL(clicked()), qApp, SLOT(quit()));
}

Options::~Options()
{
}


LogOut::LogOut()
{
	setReadOnly(true);
	setMaximumHeight(100);
	append("Affichages des changements d'options");
}

LogOut::~LogOut()
{

}

void LogOut::Print_Chances(int chances)
{
	QString info_chances;
	info_chances += "Les chances sont de: ";
	info_chances += QString::number(chances);
	info_chances += "%\n";

	setPlainText(info_chances);
}

void LogOut::Print_Debug_CMD(int state)
{
	if (state == 0)
	{
		setPlainText("Debug CMD inactif");
	}
	else if (state == 2)
	{
		setPlainText("Debug CMD actif");
	}
}

void LogOut::Print_Debug_FPGA(int state)
{
	if (state == 0)
	{
		setPlainText("Debug FPGA inactif");
	}
	else if (state == 2)
	{
		setPlainText("Debug FPGA actif");
	}
}

void LogOut::Print_Debug_Fille(int state)
{
	if (state == 0)
	{
		setPlainText("La joueuse est maintenant un joueur");
	}
	else if (state == 2)
	{
		setPlainText("Le joueur est maintenant une joueuse");
	}
}

void LogOut::Print_une_vie()
{
	setPlainText("Le joueur a 1 vie et un mulitplicateur de score de 3");
}

void LogOut::Print_deux_vies()
{
	setPlainText("Le joueur a 2 vie et un mulitplicateur de score de 2");
}

void LogOut::Print_trois_vies()
{
	setPlainText("Le joueur a 3 vie et un mulitplicateur de score de 1");
}

void LogOut::Print_Vitesse(int vitesse)
{
	QString info_vitesse;
	info_vitesse += "La vitesse est de: ";
	info_vitesse += QString::number(vitesse);
	info_vitesse += "\n";

	setPlainText(info_vitesse);
}