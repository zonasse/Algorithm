//
// Created by 钟奇龙 on 2019-05-18.
//
#include <iostream>
using namespace std;
/*
 * 定义点
 */
class Point{
public:
    double x;
    double y;
    Point(double x1,double y1):x(x1),y(y1){

    }
};
/*
 * 定义二维向量
 */
class Vec{
public:
    double x;
    double y;
    Vec(Point *from,Point *to){
        this->x = from->x - to->x;
        this->y = from->y - to->y;
    }
};
/*
 * 计算两个二维向量的叉积
 */
double get2DCrossedMulti(Vec *vec1, Vec *vec2){
    return vec1->x * vec2->y - vec1->y * vec2->x;
}
/*
 * 判断e是否在abcd矩形内部
 */
bool isInside(Point *a, Point *b, Point *c, Point *d, Point *e){
    Vec *AB = new Vec(a,b);
    Vec *AE = new Vec(a,e);
    Vec *CD = new Vec(c,d);
    Vec *CE = new Vec(c,e);
    Vec *AD = new Vec(a,d);
    Vec *CB = new Vec(c,b);
    return get2DCrossedMulti(AB,AE)*get2DCrossedMulti(CD,CE) >=0 &&
    get2DCrossedMulti(AD,AE) * get2DCrossedMulti(CB,CE) >= 0;
}

int main(){
//    Point *a = new Point(0,0);
//    Point *b = new Point(1,0);
//    Point *c = new Point(1,2);
//    Point *d = new Point(0,2);
//    Point *e = new Point(0.5,0.5);
    Point *a = new Point(1,0);
    Point *b = new Point(0,1);
    Point *c = new Point(-1,0);
    Point *d = new Point(-1,-1);
    Point *e = new Point(0.5,0.49);
    cout<<isInside(a,b,c,d,e)<<endl;
    return 0;
}
