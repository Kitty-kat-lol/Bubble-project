#include "Jeu.h"




Bubble_Trouble::Bubble_Trouble() 
{
	int rayon_bulle = 70;
	this->setWindowState(Qt::WindowFullScreen);
	Frame = new QGraphicsScene(geometry().x(), geometry().y(), 1900, 1070);
	
	QBrush centre_rouge(Qt::red);	
	QPen contour_bleu(Qt::blue);
	contour_bleu.setWidth(5);

	//Bulle = new QGraphicsEllipseItem(width()/2,height()/2-1, 40, 40);
	
	Bulle = Frame->addEllipse(width() / 2, height() / 2 - 1, 2 * rayon_bulle, 2 * rayon_bulle, contour_bleu, centre_rouge);
	

	
	Plan.horizontal_min = -((1900+2 * rayon_bulle) / 2.0);
	Plan.horizontal_min *= 0.5;
	Plan.horizontal_max = ((1900 + 2 * rayon_bulle) / 2.0);
	Plan.horizontal_max *= 0.5;
	Plan.vertical_min = ((1070+rayon_bulle) / 2);
	Plan.vertical_max = -((1070 + rayon_bulle) / 2);

	/*Note:
	Le top est négatif et on a un plan cartésien centré dans la fenêtre pour les positions
	*/

	Bulle->setPos(-1940/2, -1090/2);
	
	
	
	
		
	
	setScene(Frame);
	setRenderHints(QPainter::Antialiasing);

	std::cout << "Max x: " << Plan.horizontal_max << std::endl;
	std::cout << "Max y: " << Plan.vertical_max  << std::endl << std::endl;

	//Bulle->setPos()
	std::cout << "Bulle x: " << Bulle->scenePos().x() << std::endl;
	std::cout << "Bulle y: " << Bulle->scenePos().y() << std::endl;
	
}


Bubble_Trouble::~Bubble_Trouble()
{
	
}

void Bubble_Trouble::move_bubble()
{
	qreal mouvement_x = 5;
	qreal mouvement_y = -5;
	QPointF coordonne_bulle = Bulle->scenePos();

	//Commence le timer et le step time
	qreal time = 0;
	qreal step = 1; // step en secondes

	//Nécessaire pour l'actualisation de la position de la bulle
	
	
	
	for(int i=0;i<=10;i++)
	{
		
		if (Bulle->pos().x() >= 0.5*sceneRect().width() || Bulle->pos().x() <= -0.5*sceneRect().width()) {
			mouvement_x = -mouvement_x;
		}
		if (Bulle->pos().y() >= 0.5*sceneRect().height() || Bulle->pos().y() <= -0.5*sceneRect().height()) {
			mouvement_y = -mouvement_y;
		}
		Bulle->moveBy(mouvement_x, mouvement_y);
		

		std::cout << "Pos x: " << coordonne_bulle.rx() << std::endl;
		std::cout << "Pos y: " << coordonne_bulle.ry() << std::endl << std::endl;
		//std::sleep
	}

	temps->start();
	temps->setLoopCount(0);

}

QGraphicsScene* Bubble_Trouble::get_Frame()
{
	return Frame;
}

QGraphicsEllipseItem* Bubble_Trouble::get_Bulle()
{
	return Bulle;
}

QTimeLine* Bubble_Trouble::get_temps()
{
	return temps;
}

QGraphicsItemAnimation* Bubble_Trouble::get_Trajectoire_Bulle()
{
	return Trajectoire_Bulle;
}
