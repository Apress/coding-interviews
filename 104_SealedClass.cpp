// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdio.h>

// ==================== Solution 1 ====================
class SealedClass1
{
public:
    static SealedClass1* GetInstance() 
    {
        return new SealedClass1();
    }
 
    static void DeleteInstance( SealedClass1* pInstance)
    {
        delete pInstance;
    }
 
private:
    SealedClass1() {}
    ~SealedClass1() {}
};

// It will cause compiling errors when we try to
// define new classes deriving from SealedClass
/*
class Try1 : public SealedClass1
{
public:
    Try1() {}
    ~Try1() {}
};
*/

// ==================== Solution 2 ====================
// NOTE: It only works in Visual Studio, but does not
// work in G++
template <typename T> class MakeSealed
{
    friend T;
 
private:
    MakeSealed() {}
    ~MakeSealed() {}
};
 
class SealedClass2 : virtual public MakeSealed<SealedClass2>
{
public:
    SealedClass2() {}
    ~SealedClass2() {}
};

// It will cause compiling errors when we try to
// define new classes deriving from SealedClass
/*
class Try2 : public SealedClass2
{
public:
    Try2() {}
    ~Try2() {}
};
*/

int main(int argc, char* argv[])
{
    return 0;
}

