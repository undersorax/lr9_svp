#include <QString>
#include <QtTest>
#include <../objects/objects.h>

class TestTest : public QObject
{
    Q_OBJECT

public:
    TestTest();

private Q_SLOTS:
    void testCase1();
    void testCase2();
    void testCase3();
};

TestTest::TestTest()
{
}

void TestTest::testCase1()
{
    Bicycle bicycle;

    QVERIFY(bicycle.drive(1000));
    QCOMPARE(1000, bicycle.getMilage());
    QVERIFY(bicycle.drive(100000));
    QCOMPARE(101000, bicycle.getMilage());
    QVERIFY(bicycle.drive(10));
    QCOMPARE(101010, bicycle.getMilage());

}

void TestTest::testCase2()
{
    Suv suv;

    QVERIFY(!suv.drive(100));
    QCOMPARE(suv.getFuelLevel(), 0.0);
    QCOMPARE(suv.getMilage(), 0);
    suv.refuel();
    QVERIFY(suv.drive(100));
    QCOMPARE(suv.getMilage(), 100);
    QCOMPARE(suv.getFuelLevel(), 60.0);
    QVERIFY(suv.drive(400));
    QCOMPARE(suv.getFuelLevel(), 20.0);
    QCOMPARE(suv.getMilage(), 500);
    QVERIFY(!suv.drive(1000));

}

void TestTest::testCase3()
{
    Route route;
    Suv* vehicle = new Suv;

    route.addPoint({39.0, 80.0 , "Point1"});
    route.addPoint({0.0, 0.0, "Point2"});  //+89
    route.addPoint({65.0, 72.0, "Point3"}); //+97
    vehicle->refuel();

    route.run(vehicle);

    QCOMPARE(vehicle->getMilage(), 186);
}

QTEST_APPLESS_MAIN(TestTest)

#include "tst_testtest.moc"
