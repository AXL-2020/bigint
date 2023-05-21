/*Aidan Latessa
Project 1 Milestone 2
CS23001*/

#include "bigint.hpp"

bigint::bigint() { // sets all values in the array to 0
    defaultFlag = true;
    for (auto i = 0; i <= CAPACITY; i++)
        myInt[i] = 0;
}

bigint::bigint(int param) : bigint() { // default constructor
    if (param > 2147483647)
	return;
    defaultFlag = false;

    for (auto i = 0; i < 10; i++) { // 2147483647 is 10 spaces
        myInt[i] = param % 10;
        param /= 10;
    }
}

bigint::bigint(const char param[]) : bigint() { // converts characters to bigint
    defaultFlag = false;
    int charSize = 0;

    while (param[charSize] != 0) //gets size of char parameter
        charSize++;

    int myIntIndex = 0;
    for (auto i = charSize - 1; i >= 0; i--) {

        int charToInt = param[i] - '0'; // converts char to int 

        myInt[myIntIndex] = charToInt; 
        myIntIndex++;
    }
}

/*bigint& bigint::operator=(bigint paramBigint) {
    defaultFlag = paramBigint.defaultFlag;
    
    for (int i = 0; i < CAPACITY; i++) {
        myInt[i] = paramBigint.myInt[i];
    }
    return *this;
}*/

void bigint::debugPrint(std::ostream& stream) const { 
    for (auto i = CAPACITY; i >= 0; i--)
        stream << myInt[i] << "|";
}

int bigint::getStartIndex() { // sets index bounds to avoid leading 0's
    if (defaultFlag)
        return 0;

    for (auto i = CAPACITY; i > 0; i--) {
        if (myInt[i] != 0)
            return i;
    }
    return 0;
}

std::ostream& operator<<(std::ostream& stream, bigint& myBigInt) {
    int myStartIndex = myBigInt.getStartIndex();
    for (auto i = myStartIndex; i >= 0; i--) {
        if (myStartIndex < 80) {
            stream << myBigInt.myInt[i];
        }
        else {
            if (i % 80 == 0)
                stream << myBigInt.myInt[i] << std::endl;
            else
                stream << myBigInt.myInt[i];
        }
    }
    return stream;
}

bool bigint::operator==(const bigint& comparedInt) const { // compares two bigints

    for (int i = 0; i < CAPACITY; i++) {
        if (myInt[i] != comparedInt.myInt[i])
            return false;
    }
    return true;
}

bool bigint::operator==(int comparedInt) const { // compares bigint to an int
    bigint paramInt(comparedInt);

    return *this == paramInt;
}

bigint bigint::operator+(const bigint& paramBigint) const {
    bigint result;

    result.defaultFlag = false;

    for (auto i = 0; i < CAPACITY; ++i) {
        int indexResult = myInt[i] + paramBigint.myInt[i];
        if (indexResult + result.myInt[i] > 10) {
            result.myInt[i + 1] += indexResult / 10;
            result.myInt[i] += indexResult % 10;
        }
        else if (indexResult + result.myInt[i] == 10) { 
            result.myInt[i] = 0;
            result.myInt[i + 1] = 1;
        }
        else result.myInt[i] += indexResult;
    }
    return result;
}

int bigint::operator[](const int index) const {
    //if (index < 0 || index > CAPACITY)
        //return 0;
    return myInt[index];
}

/*bigint bigint::timesDigit(int intToMultiply) const {
    if (intToMultiply < 0 || intToMultiply > 9)
        return 0;
    
    bigint result;
    for (auto i = 0; i < intToMultiply; i++)
        result = result + *this;

    return result;
}

bigint bigint::times10(int intToMultiply) const {
    bigint result;
    for (auto i = CAPACITY - intToMultiply; i >= 0; i--) {
        result.myInt[i + intToMultiply] = myInt[i];
    }
    return result;
}

bigint& bigint::operator*(const bigint& paramBigInt) {

    bigint product;
    bigint temp;
    for (int i = 0; i < CAPACITY; i++) {
        temp = timesDigit(paramBigInt[i]);
        product = product + temp.times10(i);
    }
    *this = product;
    return *this;
}

*/
