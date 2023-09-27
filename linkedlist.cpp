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

// Fungsi untuk menghapus data mahasiswa dari linked list berdasarkan NRP
Mahasiswa* hapusMahasiswa(Mahasiswa* head, string nrp)
{
    if (head == nullptr)
    {
        cout << "Linked list kosong." << endl;
        return head;
    }

    if (head->nrp == nrp)
    {
        Mahasiswa* temp = head;
        head = head->next;
        delete temp;
        cout << "Data mahasiswa dengan NRP " << nrp << " berhasil dihapus." << endl;
        return head;
    }

    Mahasiswa* current = head;
    while (current->next != nullptr)
    {
        if (current->next->nrp == nrp)
        {
            Mahasiswa* temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout << "Data mahasiswa dengan NRP " << nrp << " berhasil dihapus." << endl;
            return head;
        }
        current = current->next;
    }

    cout << "Data mahasiswa dengan NRP " << nrp << " tidak ditemukan." << endl;
    return head;
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
        cout << "3. Hapus Data Mahasiswa" << endl;
        cout << "4. Keluar" << endl; // Ubah opsi menu ini
        cout << "Pilih menu (1/2/3/4): ";
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
            if (jumlah_data > 0)
            {
                string nrp;
                cout << "Masukkan NRP mahasiswa yang ingin dihapus: ";
                cin >> nrp;

                head = hapusMahasiswa(head, nrp);
                jumlah_data--;
            }
            else
            {
                cout << "Tidak ada data mahasiswa untuk dihapus." << endl;
            }
        }
        else if (input_user == 4)
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

