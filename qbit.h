#ifndef QBIT_H
#define QBIT_H

#define DIAGONAL_POLARIZATION true
#define STRAIGHT_POLARIZATION false

class QBit
{
public:
    QBit(bool type, bool value) : type(type), value(value) {};
    bool getValue(bool valType);

private:
    bool type;
    bool value;

};

#endif // QBIT_H
