#include <QString>
#include <QtTest>

#include "../Core/game.h"

//Маловато тестов!
//По идее, каждая функциональность каждого класса должна быть хорошенько протестирована.
//И не только функциональность, но и даже вспомогательные методы (которые не совсем очевидны)
class CoreTest : public QObject
{
    Q_OBJECT

public:
    CoreTest();

private Q_SLOTS:
    void testCell();
    void testShip();
    void testField();
    void testGame();

};

CoreTest::CoreTest()
{
}

void CoreTest::testCell()
{
    Cell* cellFirst=new Cell();
    Cell* cellSecond=new Cell(5,7);
    cellFirst->setX(3);
    cellFirst->setY(4);
    cellFirst->setStatus(whole);
    QVERIFY(cellFirst->getX()==3);
    QVERIFY(cellFirst->getY()==4);
    QVERIFY(cellFirst->getStatus()==0);
    QVERIFY(cellSecond->getX()==5);
    QVERIFY(cellSecond->getY()==7);
    delete cellFirst;
    delete cellSecond;

}

void CoreTest::testShip()
{
    Ship* ship=new Ship();
    Field* field=new Field();
    ship->createShip(*field,2,4,3,horizontal);
    QVERIFY(ship->getShipCells()[1].getX()==3);
    QVERIFY(ship->getShipCells()[1].getY()==4);
    QVERIFY(ship->getShipCells()[1].getStatus()==0);
    ship->getShipCells()[0].setStatus(whole);
    ship->getShipCells()[1].setStatus(stricken);
    ship->getShipCells()[2].setStatus(whole);
    ship->setShipStatus(2,4);
    QVERIFY(ship->getShipStatus()==1);
    delete ship;

}

void CoreTest::testField()
{
    Field* field=new Field();
    field->placeShip(2,4,3,horizontal);
    QVERIFY(field->getFieldCells()[1][5].getX()==5);
    QVERIFY(field->getFieldCells()[1][5].getStatus()==2);
    QVERIFY(field->getFieldCells()[4][3].getStatus()==0);
    QVERIFY(field->getFieldShips()[0].getShipStatus()==0);
    QVERIFY(field->getFieldShips()[0].getShipCells()[1].getX()==3);
    QVERIFY(field->isDeck(3,4)==true);
    QVERIFY(field->shot(2,3)==false);
    QVERIFY(field->allShipsDestroyed()==false);
    delete field;
}

void CoreTest::testGame()
{
    Game* game=new Game();
    game->getPlayerField()->placeShip(1,2,3,vertical);
    game->getComputerField()->placeShip(2,2,2,horizontal);
    QVERIFY(game->getComputerField()->shot(2,2)==true);
    QVERIFY(game->getComputerField()->getFieldCells()[2][2].getStatus()==1);
    QVERIFY(game->getComputerField()->getFieldShips()[0].getShipStatus()==1);
    QVERIFY(game->getComputerField()->shot(3,2)==true);
    QVERIFY(game->getComputerField()->getFieldShips()[0].getShipStatus()==2);
    QVERIFY(game->getComputerField()->getnumberSetShips()==1);
    QVERIFY(game->getComputerField()->getFieldShips()[0].getShipStatus()==2);
    QVERIFY(game->getComputerField()->allShipsDestroyed()==true);
    QVERIFY(game->getComputerField()->allShipsLocate()==false);
    delete game;
}





QTEST_APPLESS_MAIN(CoreTest)

#include "tst_coretest.moc"
