 #include"Character.h"
#include "Kobieta.h"
#include "Julek.h"
#include <boost/test/unit_test.hpp>



 BOOST_AUTO_TEST_SUITE(CharacterTest)

 Kobieta K(32,32,5);
Julek J(56,78,8);

 BOOST_AUTO_TEST_CASE(KobietaInitializingLivesChecking) {
         BOOST_CHECK_EQUAL(K.getLives(),5);
 }
 BOOST_AUTO_TEST_CASE(KobietaInitializingStartPosition) {
         BOOST_CHECK_EQUAL(K.getDX(),32);
         BOOST_CHECK_EQUAL(K.getDY(),32);
 }


 BOOST_AUTO_TEST_CASE(JulekInitilizingStartPositions) {
         BOOST_CHECK_EQUAL(J.getDX(),56);
         BOOST_CHECK_EQUAL(J.getDY(),78);
 }

     BOOST_AUTO_TEST_CASE(JulekNumberOfLivesAtStart) {
         BOOST_CHECK_EQUAL(J.getLives(),3);
     }

 BOOST_AUTO_TEST_SUITE_END()

