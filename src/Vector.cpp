#include "header.h"

template <class T> // Template tanımladık
class Vector
{
public:
    // Kurucu fonksiyon
    Vector() : m_capacity(0), m_size(0),m_data(nullptr)
    {
        // diziyi oluştur
        data = new T[m_capacity];
    }

    ~Vector() // Yıkıcı fonksiyon
    {
        // Dinamik olarak ayrılmış belleği serbest bırak
        delete[] data;
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
        if (m_size  == m_capacity) // Eğer dizinin kapasitesi dolmuşsa
        {
            extendingArray(); // Eğer dizinin kapasitesi dolmuşsa extendingArray fonksiyonunu çağır
            m_data[size+1] = element; // Yeni elemanı dizinin sonuna ekle
        }
        else
        {
            data[size] = element; // Eğer dizinin kapasitesi dolmamışsa elemanı dizinin sonuna ekle
            size++; // Eleman sayısını bir arttır
        }
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
        else
        {
            cout << "Dizi zaten boş!" << endl; // Eğer dizinin içinde eleman yoksa uyarı ver
        }
    }

    // Dizinin Boş Olup Olmadığını Kontrol Eden Fonksiyon
    bool isEmpty() const
    {
        return (getSize() == 0);
    }

    // Dizinin İlk Elemanını Döndüren Fonksiyon
    T Front() const
    {
        return data[0];
    }

    // Dizinin Son Elemanını Döndüren Fonksiyon
    T Back() const
    {
        return data[size - 1];
    }
    
    //Diziyi genişleten fonksiyon
    T extendingArray()
    {
        T* newdata = new T[m_capacity*2]; // Yeni geçici bir dizi oluşturduk
        for (int i = 0; i < m_size; i++)
        {
            newdata[i] = m_data[i]; 
        }
        delete[] m_data; // Eski diziyi serbest bıraktık
        m_data = newdata; // Yeni diziyi eski dizinin yerine koyduk
        m_capacity *= 2 ; // Kapasiteyi 5 arttırdık
        
        return *m_data; // Yeni diziyi döndürdük
    }
    
    
    friend std::ostream &operator<<(std::ostream &os, const Vector<T> &vec)
    {
        os << "|";
        for (int i = 0; i < vec.getCapacity(); ++i)
            os << setw(3) << i << setw(1) << "|";
        os << endl << "|";
        for (int i = 0; i < vec.getCapacity(); ++i)
            os << setw(3) << "---" << setw(1) << "|";
        os << endl<< "|";
        for (int i = 0; i < vec.getSize(); ++i)
        {
            os << setw(3) << "***" << setw(1) << "|";
        }
        for (int i = vec.getSize(); i < vec.getCapacity(); ++i)
        {
            os << setw(3) << "bos" << setw(1) << "|";
        }
        os << endl << endl;

        return os;
    }

private:
    T *m_data;      // Dizinin kendisi Diziler bir pointer olduğu için pointer olarak tanımladık
    int m_capacity; // Dizinin kapasitesi
    int m_size;     // Dizinin içindeki eleman sayısı yani indileri
};

int main(int argc, char const *argv[])
{
    Vector<int> vec; // Vector sınıfından bir nesne oluşturduk
    cout << vec;

    return 0;
}
