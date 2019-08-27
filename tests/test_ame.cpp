#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
#include "doctest.h"
#include "testutils.h"
#include <math.h>
#include <vector>
#include "../ame16.h"

TEST_CASE("ame"){
        CHECK(ame16::get_mass(12,6)==approx(12.0).R(1e-5));
        CHECK(ame16::get_mass(11,6)==approx(11.011432591,1e-6));
        CHECK(ame16::get_mass(153,63)==approx(152.922,1e-3));
        CHECK(ame16::get_mass(153,12)==0.0);

        CHECK(ame16::get_nuclear_mass(12,6)==approx(11.99671).epsilon(1e-4));
        CHECK(ame16::get_nuclear_mass(11,6)==approx(11.00814).epsilon(1e-4));
        CHECK(ame16::get_nuclear_mass(1,1)==approx(1.00728).R(1e-5));
        CHECK(ame16::get_nuclear_mass(10,1)==0.0);

        CHECK(ame16::Sn(12,6)==approx(18.721,1e-2));
        CHECK(ame16::Sp(12,6)==approx(15.957,1e-2));
        CHECK(ame16::S(12,6,0,1)== approx(18.721,1e-2));
        CHECK(ame16::S(12,6,1,0)==approx(15.957,1e-2));

        CHECK(ame16::Sn(12,6,2)==approx(31.841,1e-2));
        CHECK(ame16::Sp(12,6,2)==approx(27.185,1e-2));
        CHECK(ame16::S(12,6,0,2)==approx(31.841,1e-2));
        CHECK(ame16::S(12,6,2,0)==approx(27.185,1e-2));

        CHECK(ame16::Sn(11,6,2)== approx(34.404,1e-2));
        CHECK(ame16::Sp(11,6,2)== approx(15.277,1e-2));

        CHECK(ame16::Sn(15,6)==approx(1.218,1e-2));
        CHECK(ame16::Sp(15,6)==approx(21.080,1e-2));
        CHECK(ame16::Sn(15,6,2)==approx(9.395,1e-2));
        CHECK(ame16::Sp(15,6,2)==approx(38.364,1e-2));

        CHECK(ame16::Sn(9,6)==approx(14.225,1e-2));
        CHECK(ame16::Sp(9,6)==approx(1.300,1e-2));
        CHECK(ame16::Sn(9,6,2)==approx(0.0,1e-5));
        CHECK(ame16::Sp(9,6,2)==approx(1.436,1e-2));
        CHECK(ame16::S(9,6,0,1)==approx(14.225,1e-2));
        CHECK(ame16::S(9,6,1,0)==approx(1.300,1e-2));
        CHECK(ame16::S(9,6,0,2)==approx(0.0,1e-5));
        CHECK(ame16::S(9,6,2,0)==approx(1.436,1e-2));

        CHECK(ame16::Sn(8,6)== 0.0);
        CHECK(ame16::Sp(8,6)==approx(-0.099,1e-1));
        CHECK(ame16::Sn(8,6,2)== 0.0);
        CHECK(ame16::Sp(8,6,2)==approx(-2.111,1e-2));

        CHECK(ame16::Sn(7,6)== 0.0);
        CHECK(ame16::Sp(7,6)== 0.0);
        CHECK(ame16::Sn(7,6,2)== 0.0);
        CHECK(ame16::Sp(7,6,2)== 0.0);
        CHECK(ame16::S(7,6,2,0)== 0.0);

        CHECK(ame16::Sa(11,6)== approx(7.544,1e-2));
        CHECK(ame16::Sa(10,6)== approx(5.101,1e-2));
        CHECK(ame16::S(10,6,2,2)== approx(5.101,1e-2));
        CHECK(ame16::S(11,6,2,2)== approx(7.544,1e-2));

        CHECK(ame16::BA(1,1)== 0.0);
        CHECK(ame16::BA(2,1)== approx(1.112,1e-2));
        CHECK(ame16::BA(10,6)== approx(6.032,1e-2));
        CHECK(ame16::BA(9,6)== approx(4.337,1e-2));
        CHECK(ame16::BA(8,6)== approx(3.101,1e-2));
        CHECK(ame16::BA(7,6)== 0.0);
    }
