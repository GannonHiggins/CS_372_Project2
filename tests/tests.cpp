#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../header/basic_shapes.hpp"
#include "../header/shape.hpp"
#include "../header/primatives.hpp"
#include "../header/shape_container.hpp"
#include <fstream>
#include <sstream>

TEST_CASE("draw a circle"){
    std::ostringstream output;

    SECTION("draw a Circle at 0,0."){

      Circle circle({0, 0}, 120);
      circle.draw(output);

      REQUIRE(output.str() == "gsave\nnewpath\n0 0 120 0 360 arc \nstroke\ngrestore\n");
    }

    // Reset output stringstream 
    std::ostringstream().swap(output);
  
    SECTION("draw a circle at 4,5 different position."){

      Circle circle1({4.0, 5.0}, 120);
      circle1.draw(output);

      REQUIRE(output.str() == "gsave\nnewpath\n4 5 120 0 360 arc \nstroke\ngrestore\n");
    }
}

TEST_CASE("Draw a polygon.") {
    std::ostringstream output;

    Poly poly({50, 50}, 5, 200);
    poly.draw(output);

    REQUIRE(output.str() =="50 50 translate\n/S 5 def\n/H "
    "153.884 def\nnewpath\nH 0 moveto\n1 1 S 1 sub\n"
    "{\n /i exch def\n 360 S div i mul cos H mul\n 360 S div i mul sin H mul lineto\n} for\n"
    "closepath\nstroke\nshowpage");
}

TEST_CASE("draw a Square."){

    std::ostringstream output;

    Square square({100, 100}, 120);
    square.draw(output);

    REQUIRE(output.str() == "100 100 translate\n/S 4 def\n/H "
    "60 def\nnewpath\nH 0 moveto\n1 1 S 1 sub\n"
    "{\n /i exch def\n 360 S div i mul cos H mul\n 360 S div i mul sin H mul lineto\n} for\n"
    "closepath\nstroke\nshowpage");
}

TEST_CASE("draw a Triangle."){
    std::ostringstream output;
    Triangle triangle({0, 0}, 120);
    triangle.draw(output);

    REQUIRE(output.str() == "0 0 translate\n/S 3 def\n/H "
    "51.9615 def\nnewpath\nH 0 moveto\n1 1 S 1 sub\n"
    "{\n /i exch def\n 360 S div i mul cos H mul\n 360 S div i mul sin H mul lineto\n} for\n"
    "closepath\nstroke\nshowpage");

}

TEST_CASE("draw a rectangle."){
  std::ostringstream output;
  Rect rect({10,10},50,100);
  rect.draw(output);

  std::ostringstream out1;
  Rect rect1({10,10}, 50,100);
  Move(rect1, false,50);
  rect.draw(out1);
  REQUIRE(output.str() == "10 10 moveto\ngsave\nnewpath\n-25 -50 50 100 rectstroke \nstroke\ngrestore\n");
  REQUIRE(out1.str() == "60 10 moveto\ngsave\nnewpath\n-25 -50 50 100 rectstroke \nstroke\ngrestore\n");
}
