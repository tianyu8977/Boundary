#ifndef CURVE2D_H
#define CURVE2D_H

#include<cassert>
#include<vector>
#include<cmath>
#include"../../Lin_Alg/Basic_Linear_Algebra.h"


namespace knoblauch {

class Curve2D_Base {
 public:

   virtual Vector2D get_position_at_s(float_type s) = 0;
   virtual float_type get_s_at_position(Vector2D point) = 0;

 };
}

#endif
