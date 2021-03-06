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
    cellFirst->setStatus(cellStatus::whole);
    QVERIFY(cellFirst->getX()==3);
    QVERIFY(cellFirst->getY()==4);
    QVERIFY(cellFirst->getStatus()==cellStatus::whole);
    QVERIFY(cellSecond->getX()==5);
    QVERIFY(cellSecond->getY()==7);
    delete cellFirst;
    delete cellSecond;

}

void CoreTest::testShip()
{
    Ship* ship=new Ship();
    Ship(2,4,3,shipLocation::horizontal);
    QVERIFY(ship->getShipCells()[1].getX()==3);
    QVERIFY(ship->getShipCells()[1].getY()==4);
    QVERIFY(ship->getShipCells()[1].getStatus()==cellStatus::whole);
    ship->getShipCells()[0].setStatus(cellStatus::whole);
    ship->getShipCells()[1].setStatus(cellStatus::stricken);
    ship->getShipCells()[2].setStatus(cellStatus::whole);
    ship->setShipStatus(2,4);
    QVERIFY(ship->getShipStatus()==shipStatus::stricken);
    delete ship;

}

void CoreTest::testField()
{
    Field* field=new Field();
    field->placeShip(2,4,3,shipLocation::horizontal);
    QVERIFY(field->getFieldCells()[1][5].getX()==5);
    QVERIFY(field->getFieldCells()[1][5].getStatus()==cellStatus::blank);
    QVERIFY(field->getFieldCells()[4][3].getStatus()==cellStatus::whole);
    QVERIFY(field->getFieldShips()[0].getShipStatus()==shipStatus::whole);
    QVERIFY(field->getFieldShips()[0].getShipCells()[1].getX()==3);
    QVERIFY(field->isDeck(3,4)==true);
    QVERIFY(field->shot(2,3)==false);
    delete field;
}

void CoreTest::testGame()
{
    GameAPI* game=new GameAPI();
    game->placeUserShip(1,2,3,shipLocation::vertical);
    game->getComputerField()->placeShip(2,2,2,shipLocation::horizontal);
    QVERIFY(game->getComputerField()->shot(2,2)==true);
    QVERIFY(game->getComputerField()->getFieldCells()[2][2].getStatus()==cellStatus::stricken);
    QVERIFY(game->getComputerField()->getFieldShips()[0].getShipStatus()==shipStatus::stricken);
    QVERIFY(game->getComputerField()->shot(3,2)==true);
    QVERIFY(game->getComputerField()->getFieldShips()[0].getShipStatus()==shipStatus::destroyed);
    QVERIFY(game->getComputerField()->getnumberSetShips()==1);
    QVERIFY(game->getComputerField()->getFieldShips()[0].getShipStatus()==shipStatus::destroyed);
    QVERIFY(game->allShipsDestroyed(game->getComputerField())==true);
    QVERIFY(game->getComputerField()->allShipsLocate()==false);
    delete game;
}





QTEST_APPLESS_MAIN(CoreTest)

#include "tst_coretest.moc"
