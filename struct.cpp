#include <iostream>
#include <string>
#include <vector>

struct Mahasiswa
{
   std::string nama;
   int usia;
   std::string alamat;
   int nrp;
};

//menampilkan mahasiswa
void menampilkanDataMhs(const std::vector<Mahasiswa>& data) {
    if (data.empty())
    {
        std::cout << "Tidak ada data." << std::endl;
        return;
    }

    std::cout << "Data yang tersimpan:" << std::endl;
    for (const Mahasiswa& d : data) 
    {
        std::cout << "Nama: " << d.nama << ", Usia: " << d.usia << ", Alamat: " << d.alamat << ", Nrp: " << d.nrp <<std::endl;
    }
}

int main()
{
    std::vector<Mahasiswa> data;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Tampilkan data\n";
        std::cout << "2. Tambah data baru\n";
        std::cout << "3. Hapus data\n";
        std::cout << "4. Ubah data\n";
        std::cout << "5. Keluar\n";
        std::cout << "Nomor pilihan anda: ";

        int nomor;
        std::cin >> nomor;
        std::cin.ignore();

        switch (nomor) {
            case 1:
                menampilkanDataMhs(data);
                break;
            
            case 2:
                {
                    Mahasiswa dataBaru;
                    std::cout << "Masukkan Nama: ";
                    std::getline(std::cin, dataBaru.nama);
                    std::cout << "Masukkan Usia: ";
                    std::cin >> dataBaru.usia;
                    std::cin.ignore();
                    std::cout << "Masukkan Alamat: ";
                    std::getline(std::cin, dataBaru.alamat);
                    std::cout << "Masukkan Nrp: ";
                    std::cin >> dataBaru.nrp;
                data.push_back(dataBaru);
                std::cout << "Data telah ditambahkan.\n";
                }
                break;
            
            case 3:
                {
                    if (data.empty()) {
                        std::cout << "Data kosong, tidak ada yang bisa dihapus.\n";
                    } else {
                        int indeks;
                        std::cout << "Masukkan indeks data yang akan dihapus: ";
                        std::cin >> indeks;

                        if (indeks >= 0 && indeks < data.size()) {
                            data.erase(data.begin() + indeks);
                            std::cout << "Data telah dihapus.\n";
                        } else {
                            std::cout << "Indeks tidak valid.\n";
                        }
                    }
                }
                break;

            case 4:
            {
                if (data.empty()) {
                        std::cout << "Data kosong, tidak ada yang bisa diubah.\n";
                    } else {
                        int indeks;
                        std::cout << "Masukkan indeks data yang akan diubah: ";
                        std::cin >> indeks;

                        if (indeks >= 0 && indeks < data.size()) {
                            Mahasiswa& dataBaru = data[indeks];
                            std::cout << "Masukkan Nama: ";
                            std::cin.ignore();
                            std::getline(std::cin, dataBaru.nama);
                            std::cout << "Masukkan Usia: ";
                            std::cin >> dataBaru.usia;
                            std::cin.ignore();
                            std::cout << "Masukkan Alamat: ";
                            std::getline(std::cin, dataBaru.alamat);
                            std::cout << "Masukkan Nrp: ";
                            std::cin >> dataBaru.nrp;
                            std::cout << "Data telah diubah.\n"; 
                        } else {
                            std::cout << "Indeks tidak valid.\n";
                        }   
                    }
                }
                break;

            case  5:
                std::cout << "Program selesai.\n";
                return 0;
            
            default:
                std::cout << "Pilihan tidak valid.\n";         
                }
        }
    return 0;
}
