#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../header/basic_shapes.hpp"
#include "../header/shape.hpp"
#include <fstream>
#include <sstream>

TEST_CASE("draw a circle"){
    std::ostringstream output;

    Circle circle(120);

    circle.draw(output);
    SECTION("draw a Circle."){
    REQUIRE(output.str() == "gsave\nnewpath\n0 0 120 0 360 arc \nstroke\ngrestore\n");
  }

  std::ostringstream out;
  std::ostringstream out1;
  std::ostringstream out2;
  Circle circle1(4.0,5.0,120), circle2(10.0,10.0,120), circle3(5.0,4.0,120);
  circle1.draw(out);
  circle2.draw(out1);
  circle3.draw(out2);
  SECTION("draw a circle at a different position."){
    REQUIRE(out.str() == "gsave\nnewpath\n4 5 120 0 360 arc \nstroke\ngrestore\n");
    REQUIRE(out1.str() == "gsave\nnewpath\n10 10 120 0 360 arc \nstroke\ngrestore\n");
    REQUIRE(out2.str() == "gsave\nnewpath\n5 4 120 0 360 arc \nstroke\ngrestore\n");
  }
}

TEST_CASE("Draw a polygon.") {
  std::ostringstream output;

  Poly poly(5, 200);

  poly.draw(output);

 REQUIRE(output.str() ==
          "gsave\nnewpath\n/S 5 def /H 153.884 \ndef /A 360 S div "
          "def A cos H mul H sub A sin H mul 0 sub atan rotate -90 rotate H 0 "
          "moveto S{ A cos H mul A sin H mul lineto /A A 360 S div add def } "
          "repeat\nclosepath\nstroke\ngrestore\n");
}

TEST_CASE("draw a Square."){

std::ostringstream output;

Square Square(200);
Square.draw(output);

REQUIRE(output.str() == "gsave\nnewpath\n/S 4 def /H 100 \ndef /A 360 S div "
          "def A cos H mul H sub A sin H mul 0 sub atan rotate -90 rotate H 0 "
          "moveto S{ A cos H mul A sin H mul lineto /A A 360 S div add def } "
          "repeat\nclosepath\nstroke\ngrestore\n");
}

TEST_CASE("draw a Triangle."){
std::ostringstream output;
Triangle Triangle(120);
Triangle.draw(output);

REQUIRE(output.str() == "gsave\nnewpath\n/S 3 def /H 51.9615 \ndef /A 360 S div "
          "def A cos H mul H sub A sin H mul 0 sub atan rotate -90 rotate H 0 "
          "moveto S{ A cos H mul A sin H mul lineto /A A 360 S div add def } "
          "repeat\nclosepath\nstroke\ngrestore\n");

}