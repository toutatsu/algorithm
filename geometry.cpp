#include<iostream>
#include<vector>
#include<cmath>//for sqrt
#include<iomanip>
using namespace std;

//CGL_1_(A~A) verified
//ARC 042 B Verified
namespace geo{
    const double EPS=1e-10;

#define equals(a,b) (fabs((a)-(b))<EPS)

    class Point{
        public:
        double x,y;
        Point()=default;
        Point(double a,double b):x(a),y(b){};
        Point& operator+=(const Point p){x+=p.x;y+=p.y;return *this;};
        Point operator+(const Point p) {return Point(*this)+=p;}
        Point& operator-=(const Point p){x-=p.x;y-=p.y;return *this;};
        Point operator-(const Point p) {return Point(*this)-=p;}
        // Point operator+(Point &p){return Point(x+p.x,y+p.y);}
        // Point operator-(Point &p){return Point(x-p.x,y-p.y);}
        Point& operator*=(const double k){x*=k;y*=k;return *this;};
        Point operator*(const double k) {return Point(*this)*=k;}

        bool operator<(const Point &p)const{return x!=p.x?x<p.x:y<p.y;}
        bool operator==(const Point &p)const{return fabs(x-p.x)<EPS&&fabs(y-p.y)<EPS;}
    };
    typedef Point Vector;
    istream& operator>>(istream &is, Point &p) {return is>>p.x>>p.y;}
    ostream& operator<<(ostream &os, Point &p) {return os<<setprecision(15)<<p.x<<" "<<p.y;}

    double norm(Point p){return p.x*p.x+p.y*p.y;}
    double abs(Point p){return sqrt(norm(p));}

    double dot(Point a,Point b){return a.x*b.x+a.y*b.y;}
    double cross(Point a,Point b){return a.x*b.y+a.y*b.x;}

    class Segment{
        public:
        Point p1,p2;
        Segment(Point a,Point b):p1(a),p2(b){};
        double length(){return abs(p1-p2);};
    };

    Point project(Segment line,Point p){
        Vector base=line.p2-line.p1;
        return line.p1+base*(dot(p-line.p1,base)/norm(base));
    }

    class Circle{
        Point center;
        double radius;
        Circle(Point c=Point(),double r=0.0):center(c),radius(r){};
    };

    class Polygon{
        vector<Point>polygon;
    };
}
int N;
int main(){
    using namespace geo;
    Point takahashi;
    cin>>takahashi>>N;
    int V[N][2];
    for(int i=0;i<N;i++)cin>>V[i][0]>>V[i][1];
    double ans=1e9;
    for(int i=1;i<=N;i++){
        Segment s(Point(V[(i-1)%N][0],V[i-1][1]),Point(V[i%N][0],V[i%N][1]));
        ans=min(ans,abs(takahashi-project(s,takahashi)));
    }
    cout<<setprecision(10)<<ans<<endl;
    return 0;
}
