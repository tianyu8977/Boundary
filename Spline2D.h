#ifndef SPLINE2D_H
#define SPLINE2D_H

#include<cassert>
#include<vector>
#include<cmath>
#include"Curve2D_Base.h"

namespace knoblauch {

 class Spline2D : public Curve2D_Base {
 protected:

   std::vector<Vector2D> knot;

 public:

   Spline2D(const std::vector<Vector2D>& positions) {
     knot = positions;

   }

   int number_of_knots() const {return knot.size();}

   Vector2D get_position_at_s(float_type s) {
     Vector2D node_current;
     float_type length = 0.0;
     float_type l_current = 0.0;
     float_type d = 0.0;
     float_type l_pre = 0.0;
     float_type l_judge = 0.0;

     for(int k=0; k<number_of_knots()-1; k++)
       {
	 length = length+(knot[k+1]-knot[k]).norm();
       }
     l_judge = s*length;
     for(int j=0; j<number_of_knots()-1; j++)
       {
	 l_current = l_current+((knot[j+1]-knot[j]).norm());
	 l_pre = l_current-((knot[j+1]-knot[j]).norm());
	 if(l_judge <= l_current && l_judge >= l_pre) {
	   d = l_judge-l_pre;
	   node_current.y() = knot[j].y()+(knot[j+1].y()-knot[j].y())*d/((knot[j+1]-knot[j]).norm());
	   node_current.x() = knot[j].x()+(knot[j+1].x()-knot[j].x())*d/((knot[j+1]-knot[j]).norm());
	 }
       }
     return node_current;
   }

   float_type get_s_at_position(Vector2D point) {
     float_type length = 0.0;
     std::vector<float_type> line_judge(number_of_knots());     
     int number = 0;
     for(int i=0; i<number_of_knots(); i++) {
       line_judge[i] = (point-knot[i]).norm();
     }
     for(int i=0; i<number_of_knots()-1; i++) {
       if(line_judge[number]>line_judge[i+1]) {
	 number = i+1;
       }
     }

     for(int k=0; k<number_of_knots()-1; k++)
     {
       length = length+(knot[k+1]-knot[k]).norm();
     }

     float_type a1=0.0;
     float_type b1=0.0;
     float_type a2=0.0;
     float_type b2=0.0;
     float_type s1=0.0;
     float_type s2=0.0;
     float_type s =0.0;
     float_type l1=0.0;
     float_type l2=0.0;
     float_type l_current=0.0;
     float_type v1=0.0;
     float_type v2=0.0;

     if(number==0) {
       a2=(point-knot[number]).norm();
       b2=(point-knot[number+1]).norm();
       l2=(knot[number+1]-knot[number]).norm();
       s2=((a2*a2-b2*b2)/l2+l2)/(2*l2);
       if(s2<0) {
	 s=0;
       }
       else {
	 s=(s2*(knot[number+1]-knot[number]).norm())/length;
       }
     }  // for if

     else if(number==number_of_knots()-1) {
       a1=(point-knot[number-1]).norm();
       b1=(point-knot[number]).norm();
       l1=(knot[number]-knot[number-1]).norm();
       s1=((a1*a1-b1*b1)/l1+l1)/(2*l1);
       if(s1>1) {
	 s=1.0;
       }
       else {
	 s=(length-l1*(1-s1))/length;
       }
     } // for if

     else {
       for(int j=0; j<number; j++) {
	 l_current = l_current+(knot[j+1]-knot[j]).norm();
       }
       a1=(point-knot[number-1]).norm();
       b1=(point-knot[number]).norm();
       l1=(knot[number]-knot[number-1]).norm();
       s1=((a1*a1-b1*b1)/l1+l1)/(2*l1);
       a2=(point-knot[number]).norm();
       b2=(point-knot[number+1]).norm();
       l2=(knot[number+1]-knot[number]).norm();
       s2=((a2*a2-b2*b2)/l2+l2)/(2*l2);
       if(s1>=1.0 && s2<=0.0) {
	 s=l_current/length;
       }
       if(s1<1.0 && s2<=0.0) {
	 s=(l_current-l1*(1-s1))/length;
       }
       if(s1>=1.0 && s2>0.0) {
	 s=(l_current+l2*s2)/length;
       }
       if(s1<1.0 && s2>0.0) {
	 v1=a1*a1-l1*s1*l1*s1;
	 v2=a2*a2-l2*s2*l2*s2;
	 if(v1<=v2) {
	   s=(l_current-l1*(1-s1))/length;
	 }
	 else {
	   s=(l_current+l2*s2)/length;
	 }
       }
     }
     return s;
   }

 };
}

#endif
