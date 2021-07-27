//
// Created by student on 2/3/20.
//
#include"Gameboard.h"
#include <boost/test/unit_test.hpp>



BOOST_AUTO_TEST_SUITE(GameboardTest)

Gameboard G;

    BOOST_AUTO_TEST_CASE(InitialLevel) {
        BOOST_CHECK_EQUAL(G.getLevel(),1);
        G.CheckLevel();
        BOOST_CHECK_EQUAL(G.getLevel(),2);
    }
    BOOST_AUTO_TEST_CASE(FirstTileCheck) {
        BOOST_CHECK_EQUAL(G.GetMazeTile(0,0),1);
    }


    BOOST_AUTO_TEST_CASE(CrashControlNocontrol) {
        BOOST_CHECK_EQUAL(G.CrashControl(0,0),false);
    }

    BOOST_AUTO_TEST_CASE(CrashandIsEatingTest) {
        BOOST_CHECK_EQUAL(G.CrashControl(320,224),true);
        BOOST_CHECK_EQUAL(G.isEating(320,320),false);
    }

BOOST_AUTO_TEST_SUITE_END()
