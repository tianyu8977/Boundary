#ifndef LINE_SEGMENT2D_H
#define LINE_SEGMENT2D_H

#include<cassert>
#include<vector>
#include<cmath>
#include"Curve2D_Base.h"

namespace knoblauch {

 class Line_Segment2D : public Curve2D_Base {
 protected:
   
   Vector2D node_begin;
   Vector2D node_end;

 public:
   Vector2D get_position_at_s(float_type s) {
     return node_begin + s*(node_end-node_begin);
   }

   float_type get_s_at_position(Vector2D point) {
     float_type l = (node_begin-node_end).norm();
     float_type a = (point-node_begin).norm();
     float_type b = (point-node_end).norm();
     float_type s = ((a*a-b*b)/l+l)/(2*l);
     if(s<0) {
       s=0.0;
     }
     if(s>1) {
       s=1.0;
     }
     return s;
   }

 Line_Segment2D(const Vector2D& begin, const Vector2D &end) :
   node_begin(begin),
   node_end(end) {}

 };
}


#endif
