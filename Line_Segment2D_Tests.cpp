#include"gtest/gtest.h"

#include"Line_Segment2D.h"

namespace knoblauch {

TEST(Line_Segment2D, Value_mid) {

  Vector2D begin;
  Vector2D end;

  begin.x() = 1.2;
  begin.y() = 1.2;
  end.x() = 2.9;
  end.y() = 3.1;

  Line_Segment2D(begin , end);

  Vector2D expected_value;
  expected_value.x() = 0.5*(begin.x()+end.x());
  expected_value.y() = 0.5*(begin.y()+end.y());
  Vector2D actual_value =Line_Segment2D(begin, end).get_position_at_s(0.5);

  ASSERT_DOUBLE_EQ(expected_value.x(), actual_value.x());
  ASSERT_DOUBLE_EQ(expected_value.y(), actual_value.y());
  
}


TEST(Line_Segment2D, Value_begin) {

  Vector2D begin;
  Vector2D end;

  begin.x() = -2.6;
  begin.y() =  3.2;
  end.x() =  1.3;
  end.y() = -2.1;

  Line_Segment2D( begin, end);

  Vector2D expected_value;
  expected_value.x() = begin.x();
  expected_value.y() = begin.y();
  Vector2D actual_value = Line_Segment2D(begin, end).get_position_at_s(0.0);

  ASSERT_DOUBLE_EQ(expected_value.x(), actual_value.x());
  ASSERT_DOUBLE_EQ(expected_value.y(), actual_value.y());
  
}


TEST(Line_Segment2D, Value_end) {

  Vector2D begin;
  Vector2D end;

  begin.x() = -2.6;
  begin.y() =  3.2;
  end.x() =  1.3;
  end.y() = -2.1;

  Line_Segment2D( begin, end);

  Vector2D expected_value;
  expected_value.x() = end.x();
  expected_value.y() = end.y();
  Vector2D actual_value = Line_Segment2D(begin, end).get_position_at_s(1.0);

  ASSERT_DOUBLE_EQ(expected_value.x(), actual_value.x());
  ASSERT_DOUBLE_EQ(expected_value.y(), actual_value.y());
  
}


TEST(Line_Segment2D, Value_random) {

  Vector2D begin;
  Vector2D end;

  begin.x() =  3.1;
  begin.y() = -2.2;
  end.x() =  1.3;
  end.y() = -4.1;

  Line_Segment2D( begin, end);

  Vector2D expected_value;
  expected_value.x() = begin.x()+0.85*(end.x()-begin.x());
  expected_value.y() = begin.y()+0.85*(end.y()-begin.y());
  Vector2D actual_value = Line_Segment2D(begin, end).get_position_at_s(0.85);

  ASSERT_DOUBLE_EQ(expected_value.x(), actual_value.x());
  ASSERT_DOUBLE_EQ(expected_value.y(), actual_value.y());
  
}


}
