//
// Created by student on 2/3/20.
//
#include "Game.h"
#include <boost/test/unit_test.hpp>



BOOST_AUTO_TEST_SUITE(GameTest)

    Game G;

    BOOST_AUTO_TEST_CASE(RunningState) {
        G.initate(450,340,false,1);
        BOOST_CHECK_EQUAL(G.running(),true);
    }
BOOST_AUTO_TEST_SUITE_END()
