#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>

void exercicio1();
void exercicio2();
void exercicio3();


void exercicio1()
{
	GraphViewer *gv = new GraphViewer(600, 600, true);
	gv->setBackground("background.jpeg");
	gv->createWindow(600, 600);

	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");	int idNo = 0;	gv->addNode(idNo);
	idNo++;
	gv->addNode(idNo);
	gv->addEdge(0, 0, 1, EdgeType::UNDIRECTED);

	//gv->addEdge(0, 0, 1, EdgeType::DIRECTED);

	gv->removeNode(idNo);
	gv->addNode(2);
	gv->addEdge(0, 0, 2, EdgeType::DIRECTED);
	gv->setVertexLabel(0, "ANDRE GOMES");

	gv->setVertexLabel(2, "MUNDIAL");
	gv->setEdgeLabel(0, "VAI GANHAR");
	gv->setVertexColor(2, "green");	gv->setEdgeColor(0, "yellow");
	gv->rearrange();

}

void exercicio2()
{
	GraphViewer *gv = new GraphViewer(600, 600, false);
	gv->createWindow(600, 600);

	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");

	gv->addNode(0, 300, 50);
	gv->addNode(1, 318, 58);
	gv->addNode(2, 325, 75);
	gv->addNode(3, 318, 93);
	gv->addNode(4, 300, 100);
	gv->addNode(5, 282, 93);
	gv->addNode(6, 275, 75);
	gv->addNode(7, 282, 58);
	gv->addNode(8, 150, 200);
	gv->addNode(9, 300, 200);
	gv->addNode(10, 450, 200);
	gv->addNode(11, 300, 400);
	gv->addNode(12, 200, 550);
	gv->addNode(13, 400, 550);



	gv->addEdge(0, 0, 1, EdgeType::UNDIRECTED);
	gv->addEdge(1, 1, 2, EdgeType::UNDIRECTED);
	gv->addEdge(2, 2, 3, EdgeType::UNDIRECTED);
	gv->addEdge(3, 3, 4, EdgeType::UNDIRECTED);
	gv->addEdge(4, 4, 5, EdgeType::UNDIRECTED);
	gv->addEdge(5, 5, 6, EdgeType::UNDIRECTED);
	gv->addEdge(6, 6, 7, EdgeType::UNDIRECTED);
	gv->addEdge(7, 7, 0, EdgeType::UNDIRECTED);
	gv->addEdge(8, 4, 9, EdgeType::UNDIRECTED);
	gv->addEdge(9, 9, 8, EdgeType::UNDIRECTED);
	gv->addEdge(10, 9, 10, EdgeType::UNDIRECTED);
	gv->addEdge(11, 9, 11, EdgeType::UNDIRECTED);
	gv->addEdge(12, 11, 12, EdgeType::UNDIRECTED);
	gv->addEdge(13, 11, 13, EdgeType::UNDIRECTED);

	int idNo = 12;

	//200 250
	//350 400

	int x1 = 200;
	int x2 = 400;

	while (idNo < 100)
	{
		Sleep(100);
		x1 += 10;
		x2 -= 10;
		if (x1 > 250)
			x1 = 200;
		if (x2 < 350)
			x2 = 400;
		gv->removeNode(idNo);
		gv->removeNode(idNo + 1);
		idNo += 2;

		gv->addNode(idNo, x1, 550);
		gv->addNode(idNo+1, x2, 550);

		gv->addEdge(idNo, 11, idNo, EdgeType::UNDIRECTED);
		gv->addEdge(idNo+1, 11, idNo+1, EdgeType::UNDIRECTED);
		gv->rearrange();
	}

}

void exercicio3()
{

}


int main() {
	//exercicio1();
	exercicio2();
	//exercicio3();
	getchar();
	return 0;
}
