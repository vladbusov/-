#include <iostream>

class CPoint {
public:
    CPoint() = default;
    CPoint(int x, int y): _x(x), _y(y) {}

    CPoint(const CPoint& other);
    CPoint(CPoint&& other){ *this = std::move(other); }

    CPoint& operator=( const CPoint& other);

    void setX(int x);
    void setY(int y);
    void setXY(int x, int y);

    int getX() const { return _x; }
    int getY() const { return _y; }
private:
    int _x;
    int _y;
};

CPoint::CPoint(const CPoint& other){
    _x = other.getX();
    _y = other.getY();
}

CPoint& CPoint::operator=( const CPoint& other){
    if (this == &other) {
        return *this;
    }
    _x = other.getX();
    _y = other.getY();

    return *this;
}

void CPoint::setX(int x){
    _x = x;
}

void CPoint::setY(int y){
    _y = y;
}

void CPoint::setXY(int x, int y){
    _x = x;
    _y = y;
}

int pointCmp( CPoint a, CPoint b){
    if (a.getX() > b.getX()){
        return 1;
    } else if (a.getX() < b.getX()){
        return -1;
    }

    if (a.getY() > b.getY()){
        return 1;
    } else if (a.getY() < b.getY()){
        return -1;
    }
    return 0;
}

class CFirPntLessSec {
public:
    bool operator()(CPoint a, CPoint b){
        if (pointCmp(a , b) < 0)
            return 1;
        return 0;
    }
};

template <typename Compare>
void BSort( CPoint * arr, int size, Compare cmp )
{
    const int n = size;
    for( int i = 0; i < n - 1; ++i ) {
        for( int j = 1; j < n - i; ++j ) {
            if( cmp( arr[j], arr[j - 1] ) ) {
                std::swap( arr[j], arr[j - 1] );
            }
        }
    }
}

int main()
{
    int size;
    std::cin >> size;

    CFirPntLessSec comparator;
    CPoint * arr = new CPoint[size];
    for (int i = 0 ; i < size; i++){
        int x, y;
        std::cin >> x >> y;
        arr[i].setXY(x , y);
    }
    BSort(arr, size, comparator);
    for (int i = 0 ; i < size; i++){
        std::cout << arr[i].getX() << " " << arr[i].getY() << std::endl;
    }
    return 0;
}