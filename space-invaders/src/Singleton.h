//
// Created by isi on 1/12/2023.
//

#ifndef SPACE_INVADERS_SINGLETON_H
#define SPACE_INVADERS_SINGLETON_H

template <typename T>
class Singleton
{
protected:
    // Protected constructor to prevent instantiation
    Singleton() {}
    // Protected copy constructor to prevent copy
    Singleton(const Singleton &);
    // Protected assignment operator to prevent assignment
    Singleton & operator=(const Singleton &);

public:
    // Returns a reference to the singleton instance
    static T &getInstance()
    {
        static T instance;
        return instance;
    }
};
#endif //SPACE_INVADERS_SINGLETON_H
