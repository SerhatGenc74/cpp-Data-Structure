#include "header.h"
template <class T> // Template tanımladık
class Vector
{
private:
    T *data;      // Dizinin kendisi Diziler bir pointer olduğu için pointer olarak tanımladık
    int capacity; // Dizinin kapasitesi
    int size;     // Dizinin içindeki eleman sayısı yani indileri
public:
    // Kurucu fonksiyon
    Vector() : capacity(0), size(0), data(nullptr)
    {
        // diziyi oluştur
        data = new T[capacity];
    }
    // Kapasiteyi döndüren fonksiyon
    int getCapacity() const
    {
        return capacity;
    }
    // Dizinin Eleman sayısını döndüren fonksiyon
    int getSize() const
    {
        return size;
    }
    // Dizinin Sonuna Eleman Ekleme Fonksiyonu
    void push_back(const T &element)
    {
        // Eğer dizinin kapasitesi dolmuşsa kapasiteyi arttır
        data[size++] = element;
    }
    // Dizinin Sonundaki Elemanı Silen Fonksiyon
    void pop_back()
    {
        // Eğer dizinin içinde eleman varsa dizinin sonundaki elemanı sil
        if (size > 0)
        {
            //(size-1) dizinin son elemanına eşittir
            data[size - 1] = 0;
            size--;
        }
    }
    bool isEmpty() const
    {
        return (getSize() == 0);
    }
    T Front() const
    {
        return data[0];
    }
    T Back() const
    (
        return data[size-1];
    )
};

int main(int argc, char const *argv[])
{
    Vector<int> v;
    cout<< v.isEmpty() << endl;
    cout << v.getCapacity() << endl;
    cout << v.getSize() << endl;
    v.push_back(5);
    cout<< v.isEmpty() << endl;
    cout << v.getCapacity() << endl;
    cout << v.getSize() << endl;
    v.push_back(10);
    cout<< v.isEmpty() << endl;
    cout << v.getCapacity() << endl;
    cout << v.getSize() << endl;
    v.pop_back();
    v.pop_back();
    cout<< v.isEmpty() << endl;
    cout << v.getSize() << endl;

    return 0;
}
