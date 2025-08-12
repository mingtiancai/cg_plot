#ifndef FACE3D_H
#define FACE3D_H

#include "Point3d.h"

class Face3d
{
public:
    // Constructors
    Face3d() : num_(0) {}
    // Constructor with indices
    Face3d(int num, int index0, int index1, int index2, int index3 = -1)
        : num_(num)
    {
        index_[0] = index0;
        index_[1] = index1;
        index_[2] = index2;
        index_[3] = index3; 
    }

    Face3d(const Face3d &other) : num_(other.num_)
    {
        for (int i = 0; i < 4; ++i)
        {
            index_[i] = other.index_[i];
        }
    }

    Face3d &operator=(const Face3d &other)
    {
        if (this != &other)
        {
            num_ = other.num_;
            for (int i = 0; i < 4; ++i)
            {
                index_[i] = other.index_[i];
            }
        }
        return *this;
    }

    ~Face3d() {} // Destructor

    int GetNum() const { return num_; }
    int GetIndex(int i) const
    {
        if (i < 0 || i >= 4)
        {
            throw std::out_of_range("Index out of range");
        }    
        else
        {
            return index_[i];
        }
    }

private:
    int num_;
    int index_[4];
};

#endif