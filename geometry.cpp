#include<iostream>
#include<vector>
#include<cmath>//for sqrt
#include<iomanip>
#include<cassert>
#include<algorithm>
#include<cstdio>
using namespace std;

namespace geo{

    const double EPS=1e-10;
#define equals(a,b) (fabs((a)-(b))<EPS)

    class Point{
        public:
        double x,y;
        Point()=default;
        Point(double a,double b):x(a),y(b){};
        // Point& operator+=(const Point p){x+=p.x;y+=p.y;return *this;};
        // Point  operator+ (const Point p){return Point(*this)+=p;}
        // Point& operator-=(const Point p){x-=p.x;y-=p.y;return *this;};
        // Point  operator- (const Point p){return Point(*this)-=p;}
        // // Point operator+(Point &p){return Point(x+p.x,y+p.y);}
        // // Point operator-(Point &p){return Point(x-p.x,y-p.y);}
        // Point& operator*=(const double k){x*=k;y*=k;return *this;};
        // Point  operator* (const double k){return Point(*this)*=k;}

        Point operator + (Point p) {return Point(x+p.x,y+p.y);}
        Point operator - (Point p) {return Point(x-p.x,y-p.y);}
        Point operator * (double a){return Point(x*a,y*a);}
        Point operator / (double a){return Point(x/a,y/a);}

        double norm(){return x*x+y*y;}
        double abs(){return sqrt(norm());}

        bool operator < (const Point &p)const{return x!=p.x?x<p.x:y<p.y;}
        bool operator ==(const Point &p)const{return fabs(x-p.x)<EPS&&fabs(y-p.y)<EPS;}
    };
    istream& operator>>(istream &is, Point &p) {return is>>p.x>>p.y;}
    ostream& operator<<(ostream &os, Point &p) {return os<<setprecision(15)<<p.x<<" "<<p.y;}
    typedef Point Vector;

    Vector polar(double arg,double radius){return Point(cos(radius)*arg,sin(radius)*arg);}

    double norm(Vector v){return v.norm();}
    double abs(Vector v){return v.abs();}
    double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
    double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
    double arg(Vector v){return atan2(v.y,v.x);}

    class Segment{
        public:
        Point p1,p2;
        Segment()=default;
        Segment(Point a,Point b):p1(a),p2(b){};
    };
    istream& operator>>(istream &is, Segment &s) {return is>>s.p1>>s.p2;}
    ostream& operator<<(ostream &os, Segment &s) {return os<<setprecision(15)<<s.p1<<" "<<s.p2;}
    typedef Segment Line;

    bool isOrthogonal(Vector a,Vector b){return equals(dot(a,b),0.0);}
    bool isOrthogonal(Point a1,Point a2,Point b1,Point b2){return isOrthogonal(a1-a2,b1-b2);}
    bool isOrthogonal(Segment s1,Segment s2){return isOrthogonal(s1.p1-s1.p2,s2.p1-s2.p2);}

    bool isParallel(Vector a,Vector b){return equals(cross(a,b),0.0);}
    bool isParallel(Point a1,Point a2,Point b1,Point b2){return isParallel(a1-a2,b1-b2);}
    bool isParallel(Segment s1,Segment s2){return isParallel(s1.p1-s1.p2,s2.p1-s2.p2);}

    Point project(Segment line,Point p){
        Vector base=line.p2-line.p1;
        return line.p1+base*(dot(p-line.p1,base)/norm(base));
    }

    Point reflect(Segment line,Point p){
        return p+(project(line,p)-p)*2.0;
    }
    
    double getDistance(Point a,Point b){
        return abs(a-b);
    }

    double getDistanceLP(Line l,Point p){
        return std::abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));
    }

    double getDistance(Segment s,Point p){
        if(dot(s.p2-s.p1,p-s.p1)<0.0)return abs(p-s.p1);
        if(dot(s.p1-s.p2,p-s.p2)<0.0)return abs(p-s.p2);
        return getDistanceLP(s,p);
    }

    static const int COUNTER_CLOCKWISE=1;
    static const int CLOCKWISE=-1;
    static const int ONLINE_BACK=2;
    static const int ONLINE_FRONT=-2;
    static const int ON_SEGMENT=0;

    int ccw(Point p0,Point p1,Point p2){
        Vector a=p1-p0,b=p2-p0;
        if(cross(a,b)>EPS)   return COUNTER_CLOCKWISE;
        if(cross(a,b)<-EPS)  return CLOCKWISE;
        if(dot(a,b)<-EPS)    return ONLINE_BACK;
        if(a.norm()<b.norm())return ONLINE_FRONT;
        return ON_SEGMENT;
    }

    bool intersect(Point p1,Point p2,Point p3,Point p4){
        return (ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0&&ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0);
    }
    bool intersect(Segment s1,Segment s2){return intersect(s1.p1,s1.p2,s2.p1,s2.p2);}

    Point getCrossPoint(Segment s1,Segment s2){
        double d1=getDistanceLP(s2,s1.p1),d2=getDistanceLP(s2,s1.p2);
        return s1.p1+(s1.p2-s1.p1)*(d1/(d1+d2));
    }

    double getDistance(Segment s1,Segment s2){
        if(intersect(s1,s2))return 0.0;
        return min(
            min(getDistance(s1,s2.p1),getDistance(s1,s2.p2)),
            min(getDistance(s2,s1.p1),getDistance(s2,s1.p2))
        );
    }

    class Circle{
        public:
        Point center;
        double radius;
        Circle(Point c=Point(),double r=0.0):center(c),radius(r){};
    };
    istream& operator>>(istream &is, Circle &c) {return is>>c.center>>c.radius;}

    bool intersect(Circle c,Line l){return getDistanceLP(l,c.center)<=c.radius;}
    bool intersect(Circle c1,Circle c2){return abs(c2.center-c1.center)<=c1.radius+c2.radius;}

    pair<Point,Point>getCrossPoints(Circle c,Line l){
        assert(intersect(c,l));
        Vector pr=project(l,c.center);
        Vector e=(l.p2-l.p1)/abs(l.p2-l.p1);
        double base=sqrt(c.radius*c.radius-norm(pr-c.center));
        return make_pair(pr+e*base,pr-e*base);
    }
    pair<Point,Point>getCrossPoints(Circle c1,Circle c2){
        assert(intersect(c1,c2));
        double d=abs(c1.center-c2.center);
        double a=acos((c1.radius*c1.radius+d*d-c2.radius*c2.radius)/(2*c1.radius*d));
        double t=arg(c2.center-c1.center);
        return make_pair(c1.center+polar(c1.radius,t+a),c1.center+polar(c1.radius,t-a));
    }

    typedef vector<Point> Polygon;

    double area(Polygon p){//?
        double res=0.0;
        for(int i=0;i<(int)p.size();i++){
            res+=cross(p[i],p[(i+1)%p.size()])/2.0;
        }
        return std::abs(res);
    }

    int contains(Polygon g,Point p){//?
        static const int IN=2,ON=1,OUT=0;
        int n=g.size();
        bool x=false;
        for(int i=0;i<n;i++){
            Point a=g[i]-p,b=g[(i+1)%n]-p;
            if(std::abs(cross(a,b))<EPS&&dot(a,b)<EPS)return ON;
            if(a.y>b.y){Point tmp=b;b=a;a=tmp;}
            if(a.y<EPS&&EPS<b.y&&cross(a,b)>EPS)x=!x;
        }
        return (x?IN:OUT);
    }

    Polygon andrewScan(Polygon s){//?
        Polygon u,l;
        if(s.size()<3)return s;
        sort(s.begin(),s.end());
        u.push_back(s[0]);
        u.push_back(s[1]);

        l.push_back(s[s.size()-1]);
        l.push_back(s[s.size()-2]);

        for(int i=2;i<s.size();i++){
            for(int n=u.size();n>=2&&ccw(u[n-2],u[n-1],s[i])==COUNTER_CLOCKWISE/*!=CLOCKWISE*/;n--)u.pop_back();
            u.push_back(s[i]);
        }
        
        for(int i=s.size()-3;i>=0;i--){
            for(int n=l.size();n>=2&&ccw(l[n-2],l[n-1],s[i])==COUNTER_CLOCKWISE/*!=CLOCKWISE*/;n--)l.pop_back();
            l.push_back(s[i]);
        }

        reverse(l.begin(),l.end());
        for(int i=u.size()-2;i>=1;i--)l.push_back(u[i]);
        return l;
    }
}
int main(){
    using namespace geo;
    int n;cin>>n;
    Polygon p(n);
    for(int i=0;i<n;i++)cin>>p[i];
    printf("%.1lf\n",area(p));
    return 0;
}
