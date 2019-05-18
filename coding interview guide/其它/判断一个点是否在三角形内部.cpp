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
 bool isPositive(double x){
    return x > 0;
}
/*
 * 判断d是否在三角形abc内部
 */
bool isInside(Point *a,Point *b,Point *c,Point *d){
    Vec *AB = new Vec(a,b);
    Vec *BC = new Vec(b,c);
    Vec *CA = new Vec(c,a);

    Vec *AD = new Vec(a,d);
    Vec *BD = new Vec(b,d);
    Vec *CD = new Vec(c,d);
    return isPositive(get2DCrossedMulti(AB,AD)) == isPositive(get2DCrossedMulti(BC,BD)) &&
            isPositive(get2DCrossedMulti(CA,CD)) == isPositive(get2DCrossedMulti(BC,BD));
}


int main(){

    Point *a = new Point(0,0);
    Point *b = new Point(1,0);
    Point *c = new Point(0.5,1);
    Point *d = new Point(0.5,-0.1);
    cout<<isInside(a,b,c,d)<<endl;
    return 0;
}