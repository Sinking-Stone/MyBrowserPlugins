#ifndef SINGLETON_H
#define SINGLETON_H

template<typename T>
class Singleton
{
public:
    static T& GetInstance(){
        static T m_instance;
        return m_instance;
    }
protected:
    Singleton()=default;
    ~Singleton()=default;

    Singleton(const Singleton&)=default;
    Singleton& operator=(const Singleton&)=default;
};

#endif // SINGLETON_H
