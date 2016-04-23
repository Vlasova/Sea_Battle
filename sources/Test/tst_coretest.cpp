#include <QString>
#include <QtTest>

#include "../Core/game.h"


class CoreTest : public QObject
{
    Q_OBJECT

public:
    CoreTest();

private Q_SLOTS:
    void testCell();
    void testShip();
    void testField();

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
    ship->setShipStatus();
    QVERIFY(ship->getShipStatus()==1);
    delete ship;

}

void CoreTest::testField()
{
    Field* field=new Field();
    field->placeShip(2,4,3,horizontal);
    QVERIFY(field->getFieldCells()[1][5].getStatus()==2);
    QVERIFY(field->getFieldCells()[3][4].getStatus()==0);
    QVERIFY(field->getFieldShips()[0].getShipStatus()==0);
    QVERIFY(field->getFieldShips()[0].getShipCells()[1].getX()==3);
    QVERIFY(field->isDeck(3,4)==true);
    QVERIFY(field->shot(2,3)==false);
    QVERIFY(field->allShipsDestroyed()==false);
    delete field;
}



QTEST_APPLESS_MAIN(CoreTest)

#include "tst_coretest.moc"
