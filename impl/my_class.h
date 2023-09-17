class MyClass_Impl;

class MyClass
{
public:
    MyClass();
    ~MyClass();

    void DoSomething();

private:
    MyClass_Impl *m_pImpl;
};