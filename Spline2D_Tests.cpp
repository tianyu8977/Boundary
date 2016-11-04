#include"gtest/gtest.h"

#include"Spline2D.h"

namespace knoblauch {

  TEST(Spline2D, ImportNodesLValue) {

  float_type tolerance = 1.0e-10;
  std::vector<Vector2D> knot(5);
  float_type length = 0.0;
  float_type d_current = 0.0;

  knot[0].x() = 1.2;
  knot[0].y() = 1.0;
  knot[1].x() = 2.0;
  knot[1].y() = 2.0;
  knot[2].x() = 3.5;
  knot[2].y() = 2.5;
  knot[3].x() = 5.0;
  knot[3].y() = 2.8;
  knot[4].x() = 6.2;
  knot[4].y() = 3.0;

  Spline2D spline(knot);

  int n = spline.number_of_knots();

 Vector2D expected_value1;
 for(int i=0; i<n-1; i++)
   {
 	  length = length+(knot[i+1]-knot[i]).norm();
   }
 d_current = length*0.5-(knot[1]-knot[0]).norm();
 expected_value1.x() = knot[1].x()+(knot[2].x()-knot[1].x())*d_current/((knot[2]-knot[1]).norm());
 expected_value1.y() = knot[1].y()+(knot[2].y()-knot[1].y())*d_current/((knot[2]-knot[1]).norm());
 Vector2D actual_value1 = spline.get_position_at_s(0.5);

 Vector2D expected_value2;
 d_current = length*0.8-(knot[1]-knot[0]).norm()-(knot[2]-knot[1]).norm()-(knot[3]-knot[2]).norm();
 expected_value2.x() = knot[3].x()+(knot[4].x()-knot[3].x())*d_current/((knot[4]-knot[3]).norm());
 expected_value2.y() = knot[3].y()+(knot[4].y()-knot[3].y())*d_current/((knot[4]-knot[3]).norm());
 Vector2D actual_value2 = spline.get_position_at_s(0.8);

 ASSERT_NEAR(expected_value1.x(), actual_value1.x(), tolerance);
 ASSERT_NEAR(expected_value1.y(), actual_value1.y(), tolerance);
 ASSERT_NEAR(expected_value2.x(), actual_value2.x(), tolerance);
 ASSERT_NEAR(expected_value2.y(), actual_value2.y(), tolerance);
  
}


TEST(Spline2D, ReValue) {

  float_type tolerance = 1.0e-10;

  std::vector<Vector2D> knot(7);
  float_type length = 0.0;
  float_type d_current = 0.0;

  knot[0].x() = 2.0;
  knot[0].y() = 0.8;
  knot[1].x() = 2.0;
  knot[1].y() = 2.0;
  knot[2].x() = 3.0;
  knot[2].y() = 1.8;
  knot[3].x() = 4.0;
  knot[3].y() = 1.5;
  knot[4].x() = 5.2;
  knot[4].y() = 1.1;
  knot[5].x() = 3.2;
  knot[5].y() = 0.6;
  knot[6].x() = 2.0;
  knot[6].y() = 0.8;

  Spline2D spline(knot);

  int n = spline.number_of_knots();

  Vector2D expected_value1;
  for(int i=0; i<n-1; i++)
    {
	  length = length+(knot[i+1]-knot[i]).norm();
    };
  d_current = length*0.5-(knot[1]-knot[0]).norm()-(knot[2]-knot[1]).norm()-(knot[3]-knot[2]).norm();
  expected_value1.x() = knot[3].x()+(knot[4].x()-knot[3].x())*d_current/((knot[4]-knot[3]).norm());
  expected_value1.y() = knot[3].y()+(knot[4].y()-knot[3].y())*d_current/((knot[4]-knot[3]).norm());
  Vector2D actual_value1 =spline.get_position_at_s(0.5);

  Vector2D expected_value2;
  d_current = length*0.8-(knot[1]-knot[0]).norm()-(knot[2]-knot[1]).norm()-(knot[3]-knot[2]).norm()-(knot[4]-knot[3]).norm();
  expected_value2.x() = knot[4].x()+(knot[5].x()-knot[4].x())*d_current/((knot[5]-knot[4]).norm());
  expected_value2.y() = knot[4].y()+(knot[5].y()-knot[4].y())*d_current/((knot[5]-knot[4]).norm());
  Vector2D actual_value2 =spline.get_position_at_s(0.8);

  ASSERT_NEAR(expected_value1.x(), actual_value1.x(), tolerance);
  ASSERT_NEAR(expected_value1.y(), actual_value1.y(), tolerance);
  ASSERT_NEAR(expected_value2.x(), actual_value2.x(), tolerance);
  ASSERT_NEAR(expected_value2.y(), actual_value2.y(), tolerance);

}

}
