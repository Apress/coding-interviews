// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdio.h>
#include <stack>
#include <cassert>

template <typename T> class StackWithMin
{
public:
    virtual ~StackWithMin(void) {}

    virtual T& top(void) = 0;
    virtual const T& top(void) const = 0;

    virtual void push(const T& value) = 0;
    virtual void pop(void) = 0;

    virtual const T& min(void) const = 0;

    virtual bool empty() const = 0;
    virtual size_t size() const = 0;
};


// ==================== Solution 1 ====================
template <typename T> class StackWithMin_Solution1 : public StackWithMin<T>
{
public:
    StackWithMin_Solution1(void) {}
    virtual ~StackWithMin_Solution1(void) {}

    T& top(void);
    const T& top(void) const;

    void push(const T& value);
    void pop(void);

    const T& min(void) const;

    bool empty() const;
    size_t size() const;

private:
    std::stack<T>   m_data;     // data stack, to store numbers
    std::stack<T>   m_min;      // auxiliary stack, to store minimal numbers
};

template <typename T> void StackWithMin_Solution1<T>::push(const T& value)
{
    m_data.push(value);

    if(m_min.size() == 0 || value < m_min.top())
        m_min.push(value);
    else
        m_min.push(m_min.top());
}

template <typename T> void StackWithMin_Solution1<T>::pop()
{
    assert(m_data.size() > 0 && m_min.size() > 0);

    m_data.pop();
    m_min.pop();
}

template <typename T> const T& StackWithMin_Solution1<T>::min() const
{
    assert(m_data.size() > 0 && m_min.size() > 0);

    return m_min.top();
}

template <typename T> T& StackWithMin_Solution1<T>::top()
{
    return m_data.top();
}

template <typename T> const T& StackWithMin_Solution1<T>::top() const
{
    return m_data.top();
}

template <typename T> bool StackWithMin_Solution1<T>::empty() const
{
    return m_data.empty();
}

template <typename T> size_t StackWithMin_Solution1<T>::size() const
{
    return m_data.size();
}

// ==================== Solution 2 ====================
template <typename T> class StackWithMin_Solution2 : public StackWithMin<T>
{
public:
    StackWithMin_Solution2(void) {}
    virtual ~StackWithMin_Solution2(void) {}

    T& top(void);
    const T& top(void) const;

    void push(const T& value);
    void pop(void);

    const T& min(void) const;

    bool empty() const;
    size_t size() const;

private:
    std::stack<T>   m_data;     // data stack, to store numbers
    T               m_min;      // minimal number
};

template <typename T> void StackWithMin_Solution2<T>::push(const T& value) 
{
    if(m_data.size() == 0) 
    {
        m_data.push(value);
        m_min = value;
    }
    else if(value >= m_min) 
    {
        m_data.push(value);
    }
    else 
    {
        m_data.push(2 * value - m_min);
        m_min = value;
    }
}

template <typename T> void StackWithMin_Solution2<T>::pop() 
{
    assert(m_data.size() > 0);

    if(m_data.top() < m_min)
        m_min = 2 * m_min - m_data.top();

    m_data.pop();
}

template <typename T> const T& StackWithMin_Solution2<T>::min() const 
{
    assert(m_data.size() > 0);

    return m_min;
}

template <typename T> T& StackWithMin_Solution2<T>::top() 
{
    T top = m_data.top();
    if(top < m_min)
        top = m_min;

    return top;
}

template <typename T> const T& StackWithMin_Solution2<T>::top() const
{
    T top = m_data.top();
    if(top < m_min)
        top = m_min;

    return top;
}

template <typename T> bool StackWithMin_Solution2<T>::empty() const
{
    return m_data.empty();
}

template <typename T> size_t StackWithMin_Solution2<T>::size() const
{
    return m_data.size();
}

// ==================== Test Code ====================
void Test(char* testName, const StackWithMin<int>& stack, int expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(stack.min() == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void test_Solution1()
{
    printf("===== Test for Solution1 begins: =====\n");
    
    StackWithMin_Solution1<int> stack;

    stack.push(3);
    Test("Test1", stack, 3);

    stack.push(4);
    Test("Test2", stack, 3);

    stack.push(2);
    Test("Test3", stack, 2);

    stack.push(3);
    Test("Test4", stack, 2);

    stack.pop();
    Test("Test5", stack, 2);

    stack.pop();
    Test("Test6", stack, 3);

    stack.pop();
    Test("Test7", stack, 3);

    stack.push(0);
    Test("Test8", stack, 0);
}

void test_Solution2()
{
    printf("===== Test for Solution2 begins: =====\n");
    
    StackWithMin_Solution2<int> stack;

    stack.push(3);
    Test("Test1", stack, 3);

    stack.push(4);
    Test("Test2", stack, 3);

    stack.push(2);
    Test("Test3", stack, 2);

    stack.push(3);
    Test("Test4", stack, 2);

    stack.pop();
    Test("Test5", stack, 2);

    stack.pop();
    Test("Test6", stack, 3);

    stack.pop();
    Test("Test7", stack, 3);

    stack.push(0);
    Test("Test8", stack, 0);
}

int main(int argc, char* argv[])
{
    test_Solution1();
    test_Solution2();
}