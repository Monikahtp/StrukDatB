#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa
{
    string nama;
    string nrp;
    int umur;
    bool jenis_kelamin;
    Mahasiswa* next; 
};

// Fungsi untuk menambahkan data mahasiswa ke linked list
Mahasiswa* tambahMahasiswa(Mahasiswa* head, string nama, string nrp, int umur, bool jenis_kelamin)
{
    Mahasiswa* newNode = new Mahasiswa;
    newNode->nama = nama;
    newNode->nrp = nrp;
    newNode->umur = umur;
    newNode->jenis_kelamin = jenis_kelamin;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        return newNode;
    }
    else
    {
        Mahasiswa* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
        return head;
    }
}

// Fungsi untuk menampilkan data mahasiswa dari linked list
void tampilkanMahasiswa(Mahasiswa* head)
{
    if (head == nullptr)
    {
        cout << "Linked list kosong." << endl;
        return;
    }

    Mahasiswa* current = head;
    int index = 1;

    while (current != nullptr)
    {
        cout << "Data ke-" << index << ":" << endl;
        cout << "Nama: " << current->nama << endl;
        cout << "NRP: " << current->nrp << endl;
        cout << "Umur: " << current->umur << endl;
        cout << "Jenis Kelamin: " << (current->jenis_kelamin ? "Laki-laki" : "Perempuan") << endl;
        current = current->next;
        index++;
    }
}

int main()
{
    Mahasiswa* head = nullptr;
    int jumlah_data = 0;

    while (true)
    {
        int input_user;

        cout << "\nMenu: " << endl;
        cout << "1. Menambah Data" << endl;
        cout << "2. Menampilkan Data" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu (1/2/3): ";
        cin >> input_user;

        if (input_user == 1)
        {
            if (jumlah_data < 10)
            {
                string nama, nrp;
                int umur;
                bool jenis_kelamin;

                cout << "Masukkan data mahasiswa ke-" << jumlah_data + 1 << ":" << endl;
                cout << "Nama: ";
                cin >> nama;
                cout << "NRP: ";
                cin >> nrp;
                cout << "Umur: ";
                cin >> umur;
                cout << "Jenis Kelamin (0: Perempuan, 1: Laki-laki): ";
                cin >> jenis_kelamin;

                head = tambahMahasiswa(head, nama, nrp, umur, jenis_kelamin);
                jumlah_data++;
            }
            else
            {
                cout << "Maaf, Anda sudah mencapai batas maksimum (10 data mahasiswa)." << endl;
            }
        }
        else if (input_user == 2)
        {
            cout << "\nData Mahasiswa:" << endl;
            tampilkanMahasiswa(head);
        }
        else if (input_user == 3)
        {
            break; // Keluar dari program
        }
        else
        {
            cout << "Menu tidak valid. Silakan masukkan pilihan yang valid." << endl;
        }
    }

    // Bebaskan memori setelah selesai menggunakan linked list
    while (head != nullptr)
    {
        Mahasiswa* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

