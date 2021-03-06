
/*
 bplist00�_WebMainResource�
^WebResourceURL_WebResourceFrameName_WebResourceData_WebResourceMIMEType_WebResourceTextEncodingName_Qhttp://www.cse.scu.edu/~atkinson/teaching/sp20/171/protected/2/resources/Queens.hPO+<html><head></head><body><pre style="word-wrap: break-word; white-space: pre-wrap;">

*/

# ifndef QUEENS_H
# define QUEENS_H
#include <cstdlib>
//# include &lt;cstdlib&gt;


// An abstract chess piece that cannot be instantiated.

class Piece {
protected:
    int _row, _column;

public:
    int row() const {
	return _row;
    }

    int column() const {
	return _column;
    }

    void place(int row, int column) {
	_row = row;
	_column = column;
    }

    virtual bool menaces(const Piece *p) const = 0;
};

//Can move two spaces up and to the right
class Knight : virtual public Piece {
public:
    virtual bool menaces(const Piece *p) const{
        int rows = abs(_row - p->row());
        int cols = abs(_column - p->column());
        return (rows == 2 && cols ==1) || (rows == 1 && cols ==2);
    }
};

//Can move any number of spaces horizontally or verticaly
class Rook: virtual public Piece{
public:
    virtual bool menaces(const Piece *p) const{
        int rows = abs(_row - p->row());
        int cols = abs(_column - p->column());
        return rows == 0 || cols == 0;
    }
};

//Can move any number of spaces diagonally
class Bishop : virtual public Piece {
public:
    virtual bool menaces(const Piece *p) const{
        int rows = abs(_row - p->row());
        int cols = abs(_column - p->column());
        return rows == cols;
    }
};

//Can move like a Bishop or a Rook
class Queen : virtual public Rook, virtual public Bishop{
public:
    virtual bool menaces(const Piece *p) const{
        return Rook::menaces(p) || Bishop::menaces(p);
    }
};

//Can move like a Queen or a Knight
class Amazon: virtual public Knight, virtual public Queen {
public:
    virtual bool menaces(const Piece *p) const {
        return Knight::menaces(p) || Queen::menaces(p);
    }
};




# endif /* QUEENS_H */
/*
</pre></body></html>Xtext/x-cUUTF-8    ( 7 N ` v � � �!             
              '
*/
