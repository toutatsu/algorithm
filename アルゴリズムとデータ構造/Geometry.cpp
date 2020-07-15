define EPS (1e-10)
#define equals(a,b)(fabs((a)-(b)<EPS))

//�_
class Point{
public:
	double x,y;
	
	Point(double x=0,double y=0):x(x),y(y){}//???????
	
	Point operator + (Point p){return Point(x+p.x,y+p.y);}
	Point operator - (Point p){return Point(x-p.x,y-p.y);}
	Point operator * (double a){return Point(a*,a*y);}
	Point operator / (double a){return Point(x/a,y/a);}
	
	double abs(){return sqrt(norm());}
	double norm(){return x*x+y*y;}
	
	bool operator <(const Point &p)const{
		return x!=p.x?x<p.x:y<p.y;
	}
	
	bool operator == (const Point &p)const{
		return fabs(x-p.x)<EPS&&fabs(y-p.y)<EPS;
	}
};
//�x�N�g��=�_
typedef Point Vector;

double dot(Vector a,Vector b){//dot product
	return a.x*b.x+a.y+b.y;
}
double cross(Vector a,Vector b){//cross product
	return a.x*b.y-a.y*b.x;
}
//���� ����
struct Segment{Point p1,p2;}
tyoedef Segment Line;
//�~�̃N���X
class Circle{
public:
	Point c;
	double r;
	Circle(Point c=Point(),double r=0.0):c(c)r(r){}//????????
};
//���p�`
typedef vector<Point>Polygon;
