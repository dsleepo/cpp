#include <iostream>
#include <cassert>

class ArrayInt 
{
private:
    int m_length;
    int *m_data;

public:
    ArrayInt(): m_length(0), m_data(nullptr)
    {
    }

    ArrayInt(int length): m_length(length)
    {
        assert(m_length >= 0);

        if (length > 0) 
        {
            m_data = new int[m_length];
        }
        else
        {
            m_data = nullptr;
        }
    }

    ~ArrayInt() 
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    void reallocate(int newLength)
    {
        erase();
        
        if (newLength <= 0)
        {
            return;
        }

        m_data = new int[newLength];
        m_length = newLength;
    }

    void resize(int newLength)
    {
        if (newLength == m_length) 
        {
            return;
        }

        if (newLength == 0) 
        {
            erase();
            return;
        }

        int *data = new int[newLength];

        int last = m_length > newLength ? newLength : m_length;
        for (int i = 0; i < last; ++i)
        {
            data[i] = m_data[i];
        }

        delete[] m_data;

        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        assert(index >= 0 && index <= m_length);

        int *data = new int[m_length + 1];

        for (int before = 0; before < index; ++before) 
        {
            data[before] = m_data[before];
        }

        data[index] = value;

        for (int after = index; after < m_length; ++after)
        {
            data[after+1] = m_data[after];
        }

        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void remove(int index)
    {
        assert(index >= 0 && index < m_length);

        if (m_length == 1)
        {
            erase();
            return;
        }

        int *data = new int[m_length - 1];

        for (int before = 0; before < index; ++before) 
        {
            data[before] = m_data[before];
        }

        for (int after = index + 1; after < m_length; ++after)
        {
            data[after - 1] = m_data[after];
        }

        delete[] m_data;
        m_data = data;
        --m_length;
    }

    void insertAtBeginning(int value) { insertBefore(value, 0); }

    void insertAtEnd(int value) { insertBefore(value, m_length); }

    int getLength() { return m_length; }
};

int main()
{
    ArrayInt array(10);
 
    for (int i=0; i<10; i++)
    {
        array[i] = i+1;
    }
 
    array.resize(7);
 
    array.insertBefore(15, 4);
 
    array.remove(5);
 
    array.insertAtEnd(35);
    array.insertAtBeginning(50);
 
    for (int j=0; j<array.getLength(); j++)
    {
        std::cout << array[j] << " ";
    }
 
    return 0;
}
