#include"gtest/gtest.h"

#include"Circular_Arc2D.h"

namespace knoblauch {

TEST(Circular_Arc2D, Value) {

  float_type tolerance = 1.0e-10;

  float_type pi = constants::PI;
  Vector2D origin;
  Vector2D begin;

  origin.x() = 0.0;
  origin.y() = 0.0;
  begin.x() = 3.0;
  begin.y() = 0.0;

  Circular_Arc2D(origin, begin, pi);

  Vector2D expected_begin;
  Vector2D expected_mid;
  Vector2D expected_random;
  Vector2D expected_end;

  expected_begin.x() = 3.0;
  expected_begin.y() = 0.0;
  expected_mid.x() = 0.0;
  expected_mid.y() = 3.0;
  expected_random.x() = 3.0*cos(pi/4);
  expected_random.y() = 3.0*sin(pi/4);
  expected_end.x() = -3.0;
  expected_end.y() = 0.0;
  Vector2D actual_begin = Circular_Arc2D(origin, begin, pi).get_position_at_s(0.0);
  Vector2D actual_mid = Circular_Arc2D(origin, begin, pi).get_position_at_s(0.5);
  Vector2D actual_random = Circular_Arc2D(origin, begin, pi).get_position_at_s(0.25);
  Vector2D actual_end = Circular_Arc2D(origin, begin, pi).get_position_at_s(1.0);

  ASSERT_NEAR(expected_begin.x(), actual_begin.x(), tolerance);
  ASSERT_NEAR(expected_begin.y(), actual_begin.y(), tolerance);
  ASSERT_NEAR(expected_mid.x(), actual_mid.x(), tolerance);
  ASSERT_NEAR(expected_mid.y(), actual_mid.y(), tolerance);
  ASSERT_NEAR(expected_random.x(), actual_random.x(), tolerance);
  ASSERT_NEAR(expected_random.y(), actual_random.y(), tolerance);
  ASSERT_NEAR(expected_end.x(), actual_end.x(), tolerance);
  ASSERT_NEAR(expected_end.y(), actual_end.y(), tolerance);

}


TEST(Circular_Arc2D, ReValue) {

  float_type tolerance = 1.0e-10;

  float_type pi = constants::PI;
  Vector2D origin;
  Vector2D begin;

  origin.x() =  4.0;
  origin.y() = -3.0;
  begin.x() =  8.0;
  begin.y() = -6.0;

  Circular_Arc2D(origin, begin, -pi);

  Vector2D expected_begin;
  Vector2D expected_mid;
  Vector2D expected_random;
  Vector2D expected_end;

  expected_begin.x() =  8.0;
  expected_begin.y() = -6.0;
  expected_mid.x() =  1.0;
  expected_mid.y() = -7.0;
  float_type theta = atan(0.75);
  expected_random.x() =  4.0+5.0*cos(-theta-pi*0.3);
  expected_random.y() = -3.0-5.0*sin(theta+pi*0.3);
  expected_end.x() = 0.0;
  expected_end.y() = 0.0;
  Vector2D actual_begin = Circular_Arc2D(origin, begin, -pi).get_position_at_s(0.0);
  Vector2D actual_mid = Circular_Arc2D(origin, begin, -pi).get_position_at_s(0.5);
  Vector2D actual_random = Circular_Arc2D(origin, begin, -pi).get_position_at_s(0.3);
  Vector2D actual_end = Circular_Arc2D(origin, begin, -pi).get_position_at_s(1.0);

  ASSERT_NEAR(expected_begin.x(), actual_begin.x(), tolerance);
  ASSERT_NEAR(expected_begin.y(), actual_begin.y(), tolerance);
  ASSERT_NEAR(expected_mid.x(), actual_mid.x(), tolerance);
  ASSERT_NEAR(expected_mid.y(), actual_mid.y(), tolerance);
  ASSERT_NEAR(expected_random.x(), actual_random.x(), tolerance);
  ASSERT_NEAR(expected_random.y(), actual_random.y(), tolerance);
  ASSERT_NEAR(expected_end.x(), actual_end.x(), tolerance);
  ASSERT_NEAR(expected_end.y(), actual_end.y(), tolerance);

}
}
